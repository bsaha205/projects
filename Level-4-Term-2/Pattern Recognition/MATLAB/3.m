clc;
load tlns.txt;
d=tlns(1,1);
n=tlns(1,3);

w=zeros(1,d+1);
x=zeros(d+1,1);
p=1;
y=1;
w0=0;
ws=zeros(1,d+1);
ys=n+10;
it=0;


while(y>0 && it<2000)
    y=0;
    for(i=2:n)
        
        if(tlns(i,d+1)==1)
            dx=-1;
        else
            dx=1;            
        end;
        
        for(j=1:d)
            x(j,1)=tlns(i,j);
        end;
        x(d+1,1)=1;
        mat=w*x;
                
        if(dx*mat>=0)
            y=y+1;
            x=x*dx;
            x=x*p;
            w=w.';
            w=w-x;
            w=w.';
        end;
       
    end;
    y;
    if(y<ys)
        ws=w;
        ws;
        ys=y;
    end;
    it=it+1;
    
end;

load testlns.txt;
sz=size(testlns,1);
tp=0;
tn=0;
fp=0;
fn=0;
for(i=1:sz)
    for(j=1:d)
        x(j,1)=testlns(i,j);
    end;
    x(d+1,1)=1;
    disp('Feature values');
    x=x.'
    x=x.';
    mat=w*x;
    Actual_class=testlns(i,d+1)
    
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
