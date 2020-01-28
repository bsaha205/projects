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
disp(k);
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

     for m=240:I-M-1
         
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
     
     p=5;
     for num=2:frameCount-1
       X=s(num).cdata;
       min=uint64(17194399);
     
       s1=a1;
       s2=a2;
       a1=0;
       a2=0;
     
       for m=s1-p:s1+p
         
         for n=s2-p:s2+p
             sum=uint64(0);
             
                for i=m:M+m-1
        
                   for j=n:N+n-1
            
                       val=uint64(X(i,j)-Y(i-m+1,j-n+1));
                
                        val=val*val;
                        sum=sum+val;
                
            
            
                   end
    
                end
                 %disp(sum);
               if sum< min
               min=sum;
               a1=m;
               a2=n;
               end
             
             
             
         end
         %disp(min);
         
         
       end
     
     
      disp(min);
      disp(k);
     %disp(a1);
     %disp(a2);
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
     % figure;
     %disp(X);
     %imshow(X);
     %figure;
     k = k+1;
     ss(k).cdata = X;
     
     
     end 
     
     
     myVideo = VideoWriter('shaon.MOV');
     open(myVideo);
     writeVideo(myVideo, ss);
     close(myVideo);
    









