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

str = strcat('reference.jpg');
R = imread(char(str));

[M,N,dim]=size(R);
[I,J,dim1]=size(T);
%disp(dim);
B=R(1:M,1:N,1);

T=st1(1).frames;
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

  st2 = struct('cdata',zeros(video_h,video_w,3,'uint8'),...
    'colormap',[]);
     k1 = 1;
     st2(k1).cdata = T;    
 ct=0;       
for num=2:frame
    T=st1(num).frames;
    min=uint64(17194399);
    
    
    filter=fspecial('gaussian');
    R1=imfilter(R,filter,'replicate');
    T1=imfilter(T,filter,'replicate');
   
    R1=imresize(R1, 0.5);
    T1=imresize(T1, 0.5);
    
    R2=imfilter(R1,filter,'replicate');
    T2=imfilter(T1,filter,'replicate');
    
    R2=imresize(R2, 0.5);
    T2=imresize(T2, 0.5);
    
      p=2;
     a5=int16(a1/4);
     a6=int16(a2/4);
     
     
     B=R2(1:M/4,1:N/4,1);  
     a3=a5;
     a4=a6;
     
     while p>1
       k=log2(p);
       k=ceil(k);
       d=2^(k-1);
       %disp(k);
       %disp(d);
       x=zeros(9);
       y=zeros(9);
       x(1)=a5;
       y(1)=a6;
       x(2)=a5-d;
       y(2)=a6;
       x(3)=a5-d;
       y(3)=a6-d;
       x(4)=a5+d;
       y(4)=a6-d;
       x(5)=a5-d;
       y(5)=a6+d;
       x(6)=a5;
       y(6)=a6+d;
       x(7)=a5+d;
       y(7)=a6+d;
       x(8)=a5;
       y(8)=a6-d;      
       x(9)=a5+d;
       y(9)=a6;
      
        
       for pt=1:9
           m=x(pt);
           n=y(pt);  
           %m+M/4-1
           %n+N/4-1
            A=T2(m:m+M/4-1,n:n+N/4-1,1);
            ss= double((double(A)-double(B)).^2);
            sm=double(sum(ss(:)));
            if sm< min
                min=sm;
                a5=m;
                a6=n;

            end
                     
       end     
      if(min~=0)
           ct=ct+1;
               
       end
       p=p/2;
     end;
     
      B=R1(1:M/2,1:N/2,1);   
      p=2;
     
      %a5=int16(a1/2+2*(a5-a3));
      %a6=int16(a2/2+2*(a6-a4));
     a5=2*a5;
     a6=2*a6;
     a3=a5;
     a4=a6;
    
     min=uint64(17194399);
     while p>1
       k=log2(p);
       k=ceil(k);
       d=2^(k-1);
       %disp(k);
       %disp(d);
       x=zeros(9);
       y=zeros(9);
       x(1)=a5;
       y(1)=a6;
       x(2)=a5-d;
       y(2)=a6;
       x(3)=a5-d;
       y(3)=a6-d;
       x(4)=a5+d;
       y(4)=a6-d;
       x(5)=a5-d;
       y(5)=a6+d;
       x(6)=a5;
       y(6)=a6+d;
       x(7)=a5+d;
       y(7)=a6+d;
       x(8)=a5;
       y(8)=a6-d;      
       x(9)=a5+d;
       y(9)=a6;
      
     
       for pt=1:9
           m=x(pt);
           n=y(pt);  
          
            A=T1(m:m+M/2-1,n:n+N/2-1,1);
            ss= double((double(A)-double(B)).^2);
            sm=double(sum(ss(:)));
            if sm< min
                min=sm;
                a5=m;
                a6=n;

            end
                     
       end     
      
       p=p/2;
     end;
     
     B=R(1:M,1:N,1);   
     p=2;
    
     %a5=int16(a1+2*(a5-a3));
     %a6=int16(a2+2*(a6-a4));
     a5=2*a5;
     a6=2*a6;
    min=uint64(17194399);
     while p>1
       k=log2(p);
       k=ceil(k);
       d=2^(k-1);
       %disp(k);
       %disp(d);
       x=zeros(9);
       y=zeros(9);
       x(1)=a5;
       y(1)=a6;
       x(2)=a5-d;
       y(2)=a6;
       x(3)=a5-d;
       y(3)=a6-d;
       x(4)=a5+d;
       y(4)=a6-d;
       x(5)=a5-d;
       y(5)=a6+d;
       x(6)=a5;
       y(6)=a6+d;
       x(7)=a5+d;
       y(7)=a6+d;
       x(8)=a5;
       y(8)=a6-d;      
       x(9)=a5+d;
       y(9)=a6;
      
     
       for pt=1:9
           m=x(pt);
           n=y(pt);  
          
            A=T(m:m+M-1,n:n+N-1,1);
            ss= double((double(A)-double(B)).^2);
            sm=double(sum(ss(:)));
            if sm< min
                min=sm;
                a5=m;
                a6=n;

            end
                     
       end     
      
       p=p/2;
     end;
     
     a1=a5;
     a2=a6;
     %disp(p);
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
ct/(frame-1)

 my_vedio = VideoWriter('bishwa_hirarchical.MOV');
    open(my_vedio);
    writeVideo(my_vedio, st2);
    close(my_vedio);






