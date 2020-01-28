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

  st2 = struct('cdata',zeros(vidHeight,vidWidth,3,'uint8'),...
    'colormap',[]);
     k = 1;
     st2(k).cdata = T;    
     
for num=2:frame
T=st1(num).frames;
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
     k=k+1;
     st2(k).cdata = T; 
end


 my_vedio = VideoWriter('bishwa.MOV');
    open(my_vedio);
    writeVideo(my_vedio, st2);
    close(my_vedio);






