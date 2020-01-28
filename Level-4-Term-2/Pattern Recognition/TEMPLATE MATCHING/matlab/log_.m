clc;
vidObj = VideoReader('input.MOV');
vidHeight = vidObj.Height;
vidWidth = vidObj.Width;
s = struct('cdata',zeros(vidHeight,vidWidth,3,'uint8'),...
    'colormap',[]);
k = 1;
while hasFrame(vidObj)
    s(k).cdata = readFrame(vidObj);
    k = k+1;
end
%disp(k);
frameCount=k;

X=s(1).cdata;
%X=rgb2gray(X);
%imshow(X);

str = strcat('reference.jpg');
Y = imread(char(str));
%Y=rgb2gray(Y);
%figure;
%imshow(Y);

[M,N,dim]=size(Y);
[I,J,dim1]=size(X);
%disp(dim);
min=uint64(17194399);
a1=0;
a2=0;

     for m=240:242
         
      for n=1:J-N-1
     %m=2;
     %n=2;
        sum=uint64(0);

        for i=m:M+m-1
        
            for j=n:N+n-1
            
                val=uint64(X(i,j)-Y(i-m+1,j-n+1));
                
                val=val*val;
                sum=sum+val;
                %disp(val);
                %disp(X(i,j));
                %disp(Y(i-m+1,j-n+1));
            
            
            end
    
        end
        %disp(sum);
        if sum< min
            min=sum;
            a1=m;
            a2=n;
            
        end
      end
    % disp(min);
     end
    
     disp(min);
     disp(a1);
     disp(a2);
     for i=a1:a1+M-1
        X(i,a2,1)=255;
        X(i,a2,2)=0;
        X(i,a2,3)=0;
     end
     
     for i=a1:a1+M-1
        X(i,a2+N-1,1)=255;
        X(i,a2+N-1,2)=0;
        X(i,a2+N-1,3)=0;
     end
     
     for i=a2:a2+N-1
        X(a1,i,1)=255;
        X(a1,i,2)=0;
        X(a1,i,3)=0;
     end
     
     for i=a2:a2+N-1
        X(a1+M-1,i,1)=255;
        X(a1+M-1,i,2)=0;
        X(a1+M-1,i,3)=0;
     end
     %figure;
     %disp(X);
     imshow(X);
     
     ss = struct('cdata',zeros(vidHeight,vidWidth,3,'uint8'),...
    'colormap',[]);
     k = 1;
     ss(k).cdata = X;
     % figure;
     
     %imshow(X);
     %figure;
     X=s(2).cdata;
     
     p=2;
     min=uint64(17194399);
     value=p;
     
     while value>1
       k=log2(value);
       k=ceil(k);
       d=2^(k-1);
       %disp(k);
       disp(d);
       first=zeros(9);
       second=zeros(9);
       first(1)=a1;
       second(1)=a2;
       first(2)=a1-d;
       second(2)=a2-d;
       first(3)=a1-d;
       second(3)=a2;
       first(4)=a1-d;
       second(4)=a2+d;
       first(5)=a1;
       second(5)=a2-d;
       first(6)=a1;
       second(6)=a2+d;
       first(7)=a1+d;
       second(7)=a2-d;
       first(8)=a1+d;
       second(8)=a2;
       first(9)=a1+d;
       second(9)=a2+d;
     
       for z=1:9
           m=first(z);
           n=second(z);
           sum=uint64(0);

           for i=m:M+m-1
        
               for j=n:N+n-1
            
                   val=uint64(X(i,j)-Y(i-m+1,j-n+1));
                
                   val=val*val;
                   sum=sum+val;
                %disp(val);
                %disp(X(i,j));
                %disp(Y(i-m+1,j-n+1));
            
            
               end
    
           end
            %disp(sum);
           if sum< min
                min=sum;
               a1=m;
               a2=n;
            
           end
           
           
       end
       
       
       disp(min);
       value=value/2;
     end;
     disp(value);
     for i=a1:a1+M-1
        X(i,a2,1)=255;
        X(i,a2,2)=0;
        X(i,a2,3)=0;
     end
     
     for i=a1:a1+M-1
        X(i,a2+N-1,1)=255;
        X(i,a2+N-1,2)=0;
        X(i,a2+N-1,3)=0;
     end
     
     for i=a2:a2+N-1
        X(a1,i,1)=255;
        X(a1,i,2)=0;
        X(a1,i,3)=0;
     end
     
     for i=a2:a2+N-1
        X(a1+M-1,i,1)=255;
        X(a1+M-1,i,2)=0;
        X(a1+M-1,i,3)=0;
     end
     figure;
     %disp(X);
     imshow(X)
     
     
     









