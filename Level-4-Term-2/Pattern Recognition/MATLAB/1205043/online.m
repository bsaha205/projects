load train.txt;
train_d=train(2:end,1:3);
prob_c1=.5;
prob_c2=.5;


at1_c1=zeros(1,25);
at2_c1=zeros(1,25);
a1=0;
a2=0;
for(i=1:25)
    if(train(i,3)==1)
        a1=a1+1;
        a2=a2+1;
        if(a1<26)
            at1_c1(a1)=train(i,1);
        end
        if(a2<26)
            at2_c1(a2)=train(i,2);
        end
    end
end

mean_at1_c1=mean(at1_c1);
mean_at2_c1=mean(at2_c1);
var_at1_c1=var(at1_c1);
var_at2_c1=var(at2_c1);

at1_c2=zeros(1,25);
at2_c2=zeros(1,25);
a1=0;
a2=0;
for(i=51:75)
    if(train(i,3)==2)
        a1=a1+1;
        a2=a2+1;
        if(a1<26)
            at1_c2(a1)=train(i,1);
        end
        if(a2<26)
            at2_c2(a2)=train(i,2);
        end
    end
end

mean_at1_c2=mean(at1_c2);
mean_at2_c2=mean(at2_c2);
var_at1_c2=var(at1_c2);
var_at2_c2=var(at2_c2);

X=[7.9464,9.0686];

X_at1_c1=normpdf(X(1),mean_at1_c1,sqrt(var_at1_c1))
X_at2_c1=normpdf(X(2),mean_at2_c1,sqrt(var_at2_c1))
X_at1_c2=normpdf(X(1),mean_at1_c2,sqrt(var_at1_c2))
X_at2_c2=normpdf(X(2),mean_at2_c2,sqrt(var_at2_c2))

p_c1=X_at1_c1*X_at2_c1*.5
p_c2=X_at1_c2*X_at2_c2*.5






