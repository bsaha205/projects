clc;
%load tls.txt;

tls=dlmread('trainLinearlySeparable.txt');
testls=dlmread('testLinearlySeparable.txt');
d=tls(1,1);
n=tls(1,3);

w=zeros(1,d+1);
x=zeros(d+1,1);
p=.05;
y=1;
w0=0;

while(y>0)
    y=0;
    for(i=2:n)
        
        
        
        for(j=1:d)
            x(j,1)=tls(i,j);
        end;
        x(d+1,1)=1;
        mat=w*x;
                
        if(mat<=0 && tls(i,d+1)==1)
            y=y+1;
            %x=x*dx;
            x=x*p;
            w=w.';
            w=w+x;
            w=w.';
        end;
        
        if(mat>=0 && tls(i,d+1)==2)
            y=y+1;
            %x=x*dx;
            x=x*p;
            w=w.';
            w=w-x;
            w=w.';
        end;
       
    end;
    y;
     
    
end;

%load testls.txt;
sz=size(testls,1);
tp=0;
tn=0;
fp=0;
fn=0;
for(i=1:sz)
    for(j=1:d)
        x(j,1)=testls(i,j);
    end;
    x(d+1,1)=1;
    disp('Feature values');
    x=x.'
    x=x.';
    mat=w*x;
    Actual_class=testls(i,d+1)
    
    if(mat>0)
        predicted_class=1
    else  predicted_class=2
    end;
    
    if(Actual_class==1 && predicted_class==1)
        tp=tp+1;
    end;
    if(Actual_class==2 && predicted_class==1)
        fp=fp+1;
    end;
    if(Actual_class==1 && predicted_class==2)
        fn=fn+1;  
    end;
    if(Actual_class==2 && predicted_class==2)
        tn=tn+1;
    end;
end;
tp;

fp;
accuracy=(tp+tn)/(tp+fp+tn+fn)
precision=tp/(tp+fp)
recall=tp/(tp+fn)