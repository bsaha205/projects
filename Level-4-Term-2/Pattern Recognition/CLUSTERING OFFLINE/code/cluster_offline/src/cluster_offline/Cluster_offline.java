package cluster_offline;
 
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;
import java.util.Scanner;

 
class location{
   double  x,y;
   
   location(){
       
   }
   
   location(double x1,double y1){
       x=x1;
       y=y1;
   }
    
 }

public class Cluster_offline { 
 
    public static ArrayList<Integer> regionQuery(int i, double eps,ArrayList<location> data) {
        ArrayList<Integer> neigh = new ArrayList<Integer>();
        int sz=data.size();
        for (int j = 0; j < sz; j++) {
            if (distance(data.get(i), data.get(j)) <= eps) {
                neigh.add(j);
            }
        }
        return neigh;
    }
    
    public static double distance(location a,location b){
        return Math.sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    }
    
    public static void main(String[] args) throws IOException {
        int minpts=18;
        ArrayList<location> data=new ArrayList<location>();
        ArrayList<Integer> noise=new ArrayList<Integer>();
        
        try (BufferedReader br = new BufferedReader(new FileReader("dataset.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] pos = line.split(" ");
                location loc=new location(Double.parseDouble(pos[0]),Double.parseDouble(pos[1]));
                data.add(loc);
            }
        }
        
        int data_sz=data.size();
        int[] visited=new int[data_sz];
        int[] dbscan_cluser=new int[data_sz];
        int n_o_cluster=0;
        double eps=.11;
        
        for(int i=0;i<data_sz;i++){
            if(visited[i]==1)
                continue;
            visited[i]=1;           
            
            ArrayList<Integer> neighborpts=regionQuery(i,eps,data);
           
            if(neighborpts.size()<minpts){
                noise.add(i);
            }else{
                n_o_cluster++;
                dbscan_cluser[i]=n_o_cluster;
                
                for(int j=0;j<neighborpts.size();j++){
                    int n=neighborpts.get(j);
                    if(visited[n]==0){
                        visited[n]=1;
                        ArrayList<Integer> new_neighborpts=regionQuery(n,eps,data);
                        
                        if(new_neighborpts.size()>=minpts){
                            for(int k=0;k<new_neighborpts.size();k++){
                                neighborpts.add(new_neighborpts.get(k));
                            }
                        }
                    }
                    if(dbscan_cluser[n]==0){
                        dbscan_cluser[n]=n_o_cluster;
                    }
                }
            }
                       
        }
        
        System.out.println("num_cluster: "+n_o_cluster+"    noise_size:"+noise.size());
        
        //k_means-algo
        int [] kmeans_cluser=new int[data_sz];
        ArrayList<location> cluster=new ArrayList<location>();
        
        for(int i=0;i<n_o_cluster;i++){
            Random r = new Random();
            double a = r.nextDouble();
            double b  = r.nextDouble();
            location loc=new location(a, b);
            cluster.add(loc);
        }
        
        int l_flag=1;
        int iter_no=0;
        while(l_flag==1){          
            iter_no++;
            int flag=0;
            for(int i=0;i<data.size();i++){
                double dist=10000000;
                int ind=0;
                for(int j=0;j<n_o_cluster;j++){
                    double dis=distance(data.get(i), cluster.get(j));
                    if(dis<dist){
                        dist=dis;
                        ind=j+1;
                    }
                }
                if(kmeans_cluser[i]!=ind){
                    flag=1;
                    kmeans_cluser[i]=ind;
                }
            }
            if(flag==0){
                l_flag=0;
            }
            
            for(int i=0;i<n_o_cluster;i++){
                int count=0;
                double x1=0,y1=0;
                for(int j=0;j<data.size();j++){
                    if(kmeans_cluser[j]==i+1){
                        x1+=data.get(j).x;
                        y1+=data.get(j).y;
                        count++;
                    }
                }
                cluster.get(i).x=x1/count;
                cluster.get(i).y=y1/count;
            }
            
        }
        System.out.println("iteration_no: "+iter_no);
        
        PrintWriter writer = null;
        try
        {
            writer = new PrintWriter("output.txt");
            for ( int i = 0 ; i < data.size() ; i++ )
            {
                writer.println(data.get(i).x+" "+data.get(i).y+" "+dbscan_cluser[i]+" "+kmeans_cluser[i]);
                writer.flush();
 
            }
            writer.close();
            writer = new PrintWriter("noise.txt");
            for ( int i = 0 ; i < noise.size() ; i++ )
            {
                writer.println(data.get(noise.get(i)).x+" "+data.get(noise.get(i)).y);
                writer.flush();
 
            }
 
 
 
        } catch (IOException e) {
            writer.close();
        }
 
        
        
    }
    
}
 