clc;
load loc.txt
data=loc(:,:);
sz=size(data,1);
sz2=size(data,2);
k=2;
u=zeros(k,sz2);
e=zeros(sz2,sz2,k);
t=zeros(k,1);

s=0;
for(i=1:k)
    t(i)=rand;
    s=s+t(i);
end

for(i=1:k)
    t(i)=t(i)/s;
end

for(i=1:k)
    pos=round(sz*rand);
    u(i,:)=data(pos,:);
end

c=cov(data);
for(i=1:k)
    e(:,:,i)=c;
end

init=0;
for(i=1:sz)
    init2=0;
    for(j=1:k)
        n=mvnpdf(data(i,:),u(j,:),e(:,:,j));
        init2=init2+t(j)*n;
    end
    init=init+log(init2);
end

pi=zeros(sz,k);
while 1
    for(i=1:sz)
        init2=0;
        for(j=1:k)
            n=mvnpdf(data(i,:),u(j,:),e(:,:,j));
            init2=init2+t(j)*n;
        end
        for(j=1:k)
            n=mvnpdf(data(i,:),u(j,:),e(:,:,j));
            pi(i,j)=t(j)*n/init2;
        end
    end
    
    for(j=1:k)
        pi_i=0;
        for(i=1:sz)
            pi_i=pi_i+pi(i,j);
        end
      
        c=pi(1,j)*transpose((data(1,:)-u(j,:)))*(data(1,:)-u(j,:));
        for(i=2:sz)
           c=c+pi(i,j)*transpose((data(i,:)-u(j,:)))*(data(i,:)-u(j,:));         
        end
        
        e(:,:,j)=c/pi_i;
        
        d=pi(1,j)*data(1,:);
        for(i=2:sz)
           d=d+pi(i,j)*data(i,:);         
        end
        
        u(j,:)=d/pi_i;
                
        t(j)=pi_i/sz;
    end
    
    init_l=0;
    for(i=1:sz)
        init2=0;
        for(j=1:k)
            n=mvnpdf(data(i,:),u(j,:),e(:,:,j));
            init2=init2+t(j)*n;
        end
        init_l=init_l+log(init2);
    end
   
    if(init-init_l==0)
       break;
    end
    i1=init-init_l
    init=init_l;
    
end

u
e
t
scatter(data(:,1),data(:,2));
