load test.txt;
training=test(1:end,1:3);
result=test(1:end,4);
total_rec=size(result,1);
total_yes=0;
total_no=0;


for(i=1:total_rec)
    if(result(i)==1)
        total_yes=total_yes+1;
    end
     if(result(i)==0)
        total_no=total_no+1;
     end
end
prob_yes=total_yes/total_rec;
prob_no=total_no/total_rec;

income_yes=zeros(1,total_yes);
income_no=zeros(1,total_no);
total_yes=0;
total_no=0;
for(i=1:total_rec)
    if(result(i)==1)
        total_yes=total_yes+1;
        income_yes(total_yes)=training(i,3);
    end
     if(result(i)==0)
        total_no=total_no+1;
         income_no(total_no)=training(i,3);
     end
end
mean_sal_yes=mean(income_yes);
mean_sal_no=mean(income_no);
mean_var_yes=var(income_yes);
mean_var_no=var(income_no);

X=[0,2,120];
prob_feature=zeros(2,3);  % 0 ar 1 er jonno
sum_feature=zeros(2,3);
X_no=1;
X_yes=1;

for i=1:2
    for j=1:10
        if(training(j,i)==X(i))
            k=result(j)+1;
            sum_feature(k,i)=sum_feature(k,i)+1;
        end
    end
    prob_feature(1,i)=sum_feature(1,i)/total_no;
    X_no=X_no*prob_feature(1,i);
     prob_feature(2,i)=sum_feature(2,i)/total_yes;
     X_yes=X_yes*prob_feature(2,i);
end

X_income_yes=normpdf(X(3),mean_sal_yes,sqrt(mean_var_yes))
X_income_no=normpdf(X(3),mean_sal_no,sqrt(mean_var_no))

X_no=X_no*X_income_no
X_yes=X_yes*X_income_yes


clc;
load train.txt;
training=train(1:end,1:end);
[Size col]=size(training);
train_array=zeros(Size,Size);
input=5;
dist=zeros(Size,Size);
minpts=input;
for i=1:Size
    for j=1:Size
        temp=sqrt(((training(i,1)-training(j,1))*(training(i,1)-training(j,1)))+((training(i,2)-training(j,2))*(training(i,2)-training(j,2))));
        train_array(i,j)=temp;
        dist(i,j)=temp;
    end
    train_array(i,1:end)=sort(train_array(i,1:end));
end
temp_array=zeros(1,Size);
for i=1:Size
    temp_array(1,i)=train_array(i,input);
end
temp_array=sort(temp_array);
%for i=1:Size
%    scatter(i,temp_array(1,i));     
%    hold on;
%end
%hold off;

cluster=zeros(Size,Size);
num_of_cluster=0;
elements_of_cluster=zeros(1,Size);
visited=zeros(1,Size);
eps=.08;
noise=zeros(1,Size);
for i=1:Size
    if (visited(1,i)==0)
        visited(1,i)=1;
        neighbourpts=zeros(1,Size);
        n_size=0;
        for j=1:Size
            if dist(i,j)<=eps
                
                n_size=n_size+1;
                neighborpts(1,j)=1;
                
            end
            
        end
        if n_size<minpts
            noise(1,i)=1;
        else
            num_of_cluster=num_of_cluster+1;
            
            cluster(num_of_cluster,i)=1;
            for k=1:n_size
                if visited(1,k)==0
                    visited(1,k)=1;
                
                n_size1=0;
                neighbourpts1=zeros(1,Size);
                for l=1:n_size
                    if dist(k,l)<=eps
                        n_size1=n_size1+1;
                        neighbourpts1(1,n_size1)=l;
                        
                    end
                    
                end
                if n_size>=minpts
                    
                end
                end
            end
        end
    
    end
    
    
    
end
disp('ball');
num_of_cluster
    