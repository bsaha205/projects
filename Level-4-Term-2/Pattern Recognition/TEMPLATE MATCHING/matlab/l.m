clc;

video = VideoReader('input.MOV');
video_h = video.Height;
video_w = video.Width;
st1 = struct('frames',zeros(video_h,video_w,3,'uint8'),...
    'colormap',[]);
k = 0;
while hasFrame(video)
    k=k+1;
    st1(k).frames = readFrame(video);
   
end
disp(k);
frame=k;

T=st1(1).frames;
str = strcat('reference.jpg');
R = imread(char(str));

[M,N,dim]=size(R);
[I,J,dim1]=size(T);
%disp(dim);
B=R(1:M,1:N,1);


min=uint64(17194399);
     %for m=240:I-M+1
     for m=1:I-M-1    
       for n=1:J-N-1
               
        A=T(m:m+M-1,n:n+N-1,1);
        
        ss= double((double(A)-double(B)).^2);
        sm=double(sum(ss(:)));
        if sm< min
            min=sm;
            a1=m;
            a2=n;
            
        end
      end
    % disp(min);
     end
    
     disp('frame');
     %disp(min);
     disp(a1);
     disp(a2);
     
     %min_a1=241
     %min_a2=141
     for i=a1:a1+M-1
        T(i,a2,1)=255;
        T(i,a2,2)=0;
        T(i,a2,3)=0;
     end
     
     for i=a1:a1+M-1
        T(i,a2+N-1,1)=255;
        T(i,a2+N-1,2)=0;
        T(i,a2+N-1,3)=0;
     end
     
     for i=a2:a2+N-1
        T(a1,i,1)=255;
        T(a1,i,2)=0;
        T(a1,i,3)=0;
     end
     
     for i=a2:a2+N-1
        T(a1+M-1,i,1)=255;
        T(a1+M-1,i,2)=0;
        T(a1+M-1,i,3)=0;
     end
     %figure;
     %disp(X);
     %imshow(T);

  st2 = struct('cdata',zeros(vidHeight,vidWidth,3,'uint8'),...
    'colormap',[]);
     k1 = 1;
     st2(k1).cdata = T;    
   
 ct=0;    
for num=2:frame
    T=st1(num).frames;
    min=uint64(17194399);
    p=14;
    
     while p>1
       k=log2(p);
       k=ceil(k);
       d=2^(k-1);
       %disp(k);
       %disp(d);
       x=zeros(9);
       y=zeros(9);
       x(1)=a1;
       y(1)=a2;
       x(2)=a1-d;
       y(2)=a2;
       x(3)=a1-d;
       y(3)=a2-d;
       x(4)=a1+d;
       y(4)=a2-d;
       x(5)=a1-d;
       y(5)=a2+d;
       x(6)=a1;
       y(6)=a2+d;
       x(7)=a1+d;
       y(7)=a2+d;
       x(8)=a1;
       y(8)=a2-d;      
       x(9)=a1+d;
       y(9)=a2;
      
     
       for pt=1:9
           m=x(pt);
           n=y(pt);  
           
            A=T(m:m+M-1,n:n+N-1,1);
            ss= double((double(A)-double(B)).^2);
            sm=double(sum(ss(:)));
            if sm< min
                min=sm;
                a1=m;
                a2=n;

            end
            
                     
       end
       if(min~=0)
           ct=ct+1;
               
       end
      
       p=p/2;
     end;
     disp(p);
     disp('frame');
     %disp(min);
     disp(a1);
     disp(a2);
     
     %min_a1=241
     %min_a2=141
     for i=a1:a1+M-1
        T(i,a2,1)=255;
        T(i,a2,2)=0;
        T(i,a2,3)=0;
     end
     
     for i=a1:a1+M-1
        T(i,a2+N-1,1)=255;
        T(i,a2+N-1,2)=0;
        T(i,a2+N-1,3)=0;
     end
     
     for i=a2:a2+N-1
        T(a1,i,1)=255;
        T(a1,i,2)=0;
        T(a1,i,3)=0;
     end
     
     for i=a2:a2+N-1
        T(a1+M-1,i,1)=255;
        T(a1+M-1,i,2)=0;
        T(a1+M-1,i,3)=0;
     end
     
     k1=k1+1
     st2(k1).cdata = T; 
end
ct/(frame-1);

    my_vedio = VideoWriter('bishwa_log.MOV');
    open(my_vedio);
    writeVideo(my_vedio, st2);
    close(my_vedio);






