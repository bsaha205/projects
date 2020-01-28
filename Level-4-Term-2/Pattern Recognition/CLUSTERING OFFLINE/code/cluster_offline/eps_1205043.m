clc;
load dataset.txt
data=dataset(:,:);
sz=size(data,1);
dist=zeros(sz,sz);

for(i=1:sz)
    for(j=1:sz)
        if(i~=j)
            dist(i,j)=sqrt((data(i,1)-data(j,1))*(data(i,1)-data(j,1))+(data(i,2)-data(j,2))*(data(i,2)-data(j,2)));

        end
    end
end

sort_dist=sort(dist,2);
MINPTS=3;

array=zeros(1,sz);
for(i=1:sz)
     array(1,i)=sort_dist(i,MINPTS+1);
end

sort_array=sort(array,2);

for i=1:sz
    scatter(i,sort_array(1,i));     
    hold on;
end
hold off;




