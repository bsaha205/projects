clc;
load dataset.txt
data=dataset(:,:);
sz=size(data,1);
%sz=4;
sz2=size(data,2);

dist=zeros(sz,sz);

for(i=1:sz)
    for(j=1:sz)
        if(i~=j)
            dist(i,j)=sqrt((data(i,1)-data(j,1))*(data(i,1)-data(j,1))+(data(i,2)-data(j,2))*(data(i,2)-data(j,2)));
            
        end
    end
    init=init+log(init2);
end

sort_dist=sort(dist,2);
MINPTS=3;

array=zeros(1,sz);
for(i=1:sz)
     array(1,i)=sort_dist(i,MINPTS+1);
end

sort_array=sort(array,2);
%{
for i=1:sz
    scatter(i,sort_array(1,i));     
    hold on;
end
hold off;
%}
eps=.08;
visited=zeros(1,sz);
noise=zeros(1,sz);
cluster=zeros(sz,sz);
n_o_cluster=0;

for i=1:sz
    if (visited(1,i)==0)
        visited(1,i)=1;
        neighbourpts=zeros(1,sz);
        neigh_size=0;
        for j=1:sz
            if dist(i,j)<=eps              
                neigh_size=neigh_size+1;
                neighbourpts(1,j)=1;                
            end          
        end
        
        if neigh_size<MINPTS
            noise(1,i)=1;
        else
            n_o_cluster=n_o_cluster+1;           
            cluster(n_o_cluster,i)=1;
            
            for k=1:neigh_size
                if visited(1,k)==0
                    visited(1,k)=1;               
                    n_size1=0;
                    neighbourpts1=zeros(1,sz);
                    for l=1:neigh_size
                        if dist(k,l)<=eps
                            n_size1=n_size1+1;
                            neighbourpts1(1,n_size1)=l;

                        end
                    
                    end
                end
                if n_size>=minpts
                    
                end
                end
            end
        end
    
    end
end
    





