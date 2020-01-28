clc;

data=dlmread('output.txt');
[m,n,o]=size(data);
cluster=17;
for j=1:cluster

     count=0;
     val=j;

     for i=1:m
         if data(i,3)==val
             count=count+1;
         end
    
    
     end
     %disp(count);
     location=zeros(count,2);
     
      for i=1:m
         if data(i,3)==val
             location(i,1)=data(i,1);
             location(i,2)=data(i,2);
         end
    
    
      end
      
      %c=[.1 .1 .1];
      x1=rand();
      x2=rand();
      x3=rand();
      c=[x1 x2 x3];
     
      scatter(location(:,1),location(:,2),20,c,'filled');
      hold on;
      
end;
load noise.txt;
Noise=noise(1:end,1:end);
[Size a]=size(Noise);

for i=1:Size
       c=[1 0 0];
     
      scatter(Noise(:,1),Noise(:,2),20,c,'+');
      hold on;
end

hold off;
