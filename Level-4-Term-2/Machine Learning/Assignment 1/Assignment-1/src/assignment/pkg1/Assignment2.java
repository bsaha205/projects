/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package assignment.pkg1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

 class node1 {
     String[][] records = new String[1000][15];
     int f_own;
     int f_child;
     node1[] child= new node1[12];
     int[] f=new int[12];
     int lebel;
     int len;
     double alpha;
    
    
    node1()
    {
        records=null;
        f_own=-1;
        f_child=-1;
        lebel=-1;
        len=-1;
        alpha=0;
        
    }
    
}


public class Assignment2 {
   

    public static double entropy(String[][] data,int len)
    {
        //System.out.println("a");
        int yes=0,no=0,count=0;
        //int len=data.length;
        //System.out.println(len);
        for(int i=0;i<len;i++)
        {
            //System.out.println(data[i].charAt(4));
            if(data[i][8].equals("0")) no++;
            else yes++;
            count++;
            //System.out.println(data.charAt(i));
        }
        
        double p_y=yes*1.0/count;
        double p_n=no*1.0/count;
       // System.out.println(count + " len= "+len);
        if(len==0 || (p_y==0 || p_n==0))return 0;
        double entro= -p_y*Math.log(p_y)/Math.log(2.0)-p_n*Math.log(p_n)/Math.log(2.0);
        //System.out.println(entro);
        
        return entro;
        
    }
    
    public static double info_gain(String[][] data,int len,int f)
    {
        
        double h=entropy(data,len);
        //System.out.println("h: "+h);
         double[] h1 = new double[11];
         double[] count = new double[11];
        for(int i=1;i<11;i++)
        {
                //int len=data.length();
                String[][] new_d=new String[1000][15];
                int ct=0;
                int yes=0,no=0;
                int ind=0;
                for(int j=0;j<len;j++)
                {
                    //System.out.println(Character.getNumericValue(data[j].charAt(f)));
                    if(Integer.parseInt(data[j][f])==i) 
                    {
                        ct++;
                        new_d[ind]=data[j];
                        ind++;
                        
                    }
                    
                    //System.out.println(ind);
                }
                h1[i]=entropy(new_d,ind);
               // System.out.println("h["+i+"]= "+h1[i]);
                count[i]=ct;
        }
        double i_g=0;
        for(int i=0;i<11;i++)
        {
            i_g += h1[i]*count[i]/len;
        }
        i_g = h-i_g;
        return i_g;
    }
    
    public static void DT(node1 root,int depth)
    {
        //System.out.println(" baal");
        depth--;
        int yes=0;
        for(int i=0;i<root.len;i++)
        {
            if(root.records[i][8].equals("1")) yes++;
        }
        //System.out.println(" baal1");
        if(yes==root.len)
        {
            root.lebel=1;
            return ;
        }
        //System.out.println(" baa3");
        if(yes==0)
        {
            root.lebel=0;
            return ;
        }
        //System.out.println(" baa4");
        int ct=0;
        for(int i=0;i<8;i++)
        {
            if(root.f[i]==1)ct++;
        }
        if(ct==0 || depth<0)
        {
            int no=root.len-yes;
            if(yes>=no)
            {
                 root.lebel=1;
                 return ;
            }
            else
            {
                 root.lebel=0;
                 return ;
            }  
              
        }
       // System.out.println(" baa2");
        double max_ig=-1,ig=-1;
        //root.f_own=3;
        for(int i=0;i<8;i++)
        {   
            if(root.f[i]==1)
            {
                ig=info_gain(root.records,root.len,i);
            }
            if(ig>max_ig)
            {
                max_ig=ig;
                root.f_own=i;
            }
            //System.out.println("Info Gain = "+info_gain(data_m,ind,i));
        }
        
        for(int i=1;i<11;i++)
        {
                //int len=data.length();
                String[][] new_d=new String[1000][15];
                int ind=0;
                for(int j=0;j<root.len;j++)
                {
                    //System.out.println(Character.getNumericValue(data[j].charAt(f)));
                    if(Integer.parseInt(root.records[j][root.f_own])==i) 
                    {
                        new_d[ind]=root.records[j];
                        ind++;
                        
                    }
                }
                node1 child=new node1();
                child.records=new_d;
                child.len=ind;
                child.f=root.f;
                child.f[root.f_own]=0;
                root.child[i]=child;
                if(ind==0)
                {
                    ;
                }
                else
                {
                    /*for(int j=0;j<8;j++)
                    {
                        System.out.print(root.f[j]);
                        System.out.print(" ");
                    }
                    System.out.println();
                    System.out.println("f_own: "+root.f_own+" len: "+ind+" val: "+i);*/
                    
                    DT(child,depth);
                  
                }
                
        }
        
        
    }

    
    /*public static void print(node root)
    {
        System.out.println(root.f_own);
        for(int i=0;i<11;i++)
        {
            print(root.child[i]);
        }
        // System.out.println();       
    }*/
   public static double [][] result=new double[1000][10000];
    public static double test(node1 root,String[][] test,int len,double[] d,int ind)
    {
       double e=0;
       int ct=0;
       node1 rt=root;
        
        for(int i=0;i<len;i++)
        {
            root=rt;
            //System.out.println(root.lebel);
            while(root.lebel==-1)
            {
                //System.out.println(root.f_own);
                int c=Integer.parseInt(test[i][root.f_own]);
                //System.out.println(c); 
                //System.out.println("sad");
                
                root=root.child[c];
                //System.out.println(root.lebel);
                //System.out.println();
            }
            //System.out.println(root.lebel);
                int c =Integer.parseInt(test[i][8]);
                //int c=1;
                if((root.lebel==1 && c==0) || (root.lebel==0 && c==1) )
                {
                    e+=d[i];
                    ct++;
                }
                result[ind][i]=root.lebel;
                
                            
        }
        //System.out.println("ct= "+ct);
        root=rt;
        return e;
          
    }
    
    
    public static void main(String[] args) {
        
        int f=8;
        int v=11;
        for(int k=0;k<1;k++)
        {
            
            //System.out.println("k: "+k+"\n");
            String csvFile = "H:\\LEVEL-4-TERM-2\\3.LAB_ML\\Assignment1\\data.csv";
            String line = "";
            String cvsSplitBy = ",";
            String[][] data_m = new String[1000][15];
            String[][] test = new String[1000][15];
            int ind=0,ct=0,ind_t=0;
            try (BufferedReader br = new BufferedReader(new FileReader(csvFile))) {

                while ((line = br.readLine()) != null) {
                    String[] data = line.split(cvsSplitBy);
                    if(k==0)
                    {
                        if(ct>133)
                        {
                            
                            //String data_l="";
                            for(int i=0;i<f+1;i++)
                            {
                                data_m[ind][i]=data[i];
                                //System.out.println(data[i]);
                            }
                            //data_m[ind]=data_l;
                            ind++;
                        }
                        else if((ct>0 &&ct<65) || (ct>65 && ct<=133))
                        {
                             for(int i=0;i<f+1;i++)
                            {
                                test[ind_t][i]=data[i];
                                //System.out.println(data[i]);
                            }
                            //data_m[ind]=data_l;
                            
                            ind_t++;
                        }
                    }
                    
                    else if(k==1)
                    {
                        if((ct>0 && ct<134)|| ct>=268)
                        {
                            for(int i=0;i<f+1;i++)
                            {
                                data_m[ind][i]=data[i];
                                //System.out.println(data[i]);
                            }
                            //data_m[ind]=data_l;
                            ind++;
                        }
                        else if((ct>133 &&ct<246)|| (ct>246 && ct<251))
                        {
                             for(int i=0;i<f+1;i++)
                            {
                                test[ind_t][i]=data[i];
                                //System.out.println(data[i]);
                            }                          
                            ind_t++;
                        }
                    }
                    
                    else if(k==2)
                    {
                        if((ct>0 && ct<268)|| ct>=402)
                        {
                            for(int i=0;i<f+1;i++)
                            {
                                data_m[ind][i]=data[i];
                                //System.out.println(data[i]);
                            }
                            //data_m[ind]=data_l;
                            ind++;
                        }
                        else if((ct>267 &&ct<272) || (ct>275 && ct<298) || (ct>299 && ct<335) || (ct>335 && ct<402))
                        {
                             for(int i=0;i<f+1;i++)
                            {
                                test[ind_t][i]=data[i];
                                //System.out.println(data[i]);
                            }                          
                            ind_t++;
                        }
                    }
                     
                    else  if(k==3)
                    {
                        if((ct>0 && ct<402)|| ct>=536)
                        {
                            for(int i=0;i<f+1;i++)
                            {
                                data_m[ind][i]=data[i];
                                //System.out.println(data[i]);
                            }
                            //data_m[ind]=data_l;
                            ind++;
                        }
                        else if((ct>401 &&ct<466)|| (ct>467 &&ct<527) || (ct>527 &&ct<536) )
                        {
                             for(int i=0;i<f+1;i++)
                            {
                                test[ind_t][i]=data[i];
                                //System.out.println(data[i]);
                            }                          
                            ind_t++;
                        }
                    }
                    
                     else 
                    {
                        if((ct>0 && ct<536))
                        {
                            for(int i=0;i<f+1;i++)
                            {
                                data_m[ind][i]=data[i];
                                //System.out.println(data[i]);
                            }
                            //data_m[ind]=data_l;
                            ind++;
                        }
                        else if((ct>536 &&ct<598) || (ct>598 &&ct<670))
                        {
                             for(int i=0;i<f+1;i++)
                            {
                                test[ind_t][i]=data[i];
                                //System.out.println(data[i]);
                            }                          
                            ind_t++;
                        }
                    }
                    
                    
                    ct++;
                    //System.out.println(data_l);
                   //System.out.println("data-1= " + data[0] + " , data-2= " + data[1] + " , data-3= " + data[2] +" , data-4= " + data[3] +" , data-5= " + data[4]);
                }
               //System.out.println(data_m);
               //System.out.println(ind);

            } catch (IOException e) {
                e.printStackTrace();
            }
            //double entro=entropy(data_m,ind);
           //System.out.println("Entropy = "+entro);
           int[] fe=new int[10];
           for(int i=0;i<8;i++)
           {
               fe[i]=1;
           }

           node1 root=new node1();
           root.records=data_m;
           root.f=fe;
           root.len=ind;
           //System.out.println(root.records.length);
           int[] t = new int[]{5,10,20,30};
           //node1[][] tree = new node1[5][31];
           /*for(int l=0;l<ind;l++)
           {
                    for(int m=0;m<8;m++)
                    {
                        System.out.print(data_m[l][m]);
                    }
                    System.out.println();
           }*/
           double[] d=new double[1000];
           for(int l=0;l<ind;l++)
           {
               d[l]=1.0/ind;
           }
           
           double alpha=0;
           for(int l=0;l<1;l++)
           {
               node1[] tree=new node1[40];
               for(int m=0;m<40;m++)
               {
                   tree[m]=root;
               }
               
               class examp implements Comparable<examp>{
                   String[] record=new String[15];
                    double wt;
                   
                    examp()
                    {
                        wt=0;
                    }
                    
                   public double getwt() {
                       return wt;
                   }
                   
                  
                   public int compareTo(examp o) {
                       return new Double(wt).compareTo(o.wt);
                   }
               }
               
               List<examp> exm = new ArrayList<examp>();
               
               node1 nr=root;
               double h=0;
               String[][] data_mn = new String[1000][15];
               data_mn=data_m;
               //tree[0]=root;
               int round=2;
               int indx=0;
               //test=data_m;
               
               for(int m=0;m<round;m++)
               {
                   //System.out.println("a");
                   DT(nr,1);
                   //System.out.println("aa");
                   double e=test(nr,data_mn,ind,d,0);
                   System.out.println("e= "+e);
                   alpha=.5*Math.log((1-e)/e);
                   System.out.println("alpha= "+alpha);
                   
                   double sum=0;
                   for(int n=0;n<ind;n++)
                    {
                        node1 rt = nr;
                        //System.out.println(root.lebel);
                        while (rt.lebel == -1) {
                            //System.out.println(root.f_own);
                            int c = Integer.parseInt(data_mn[n][rt.f_own]);
                            //System.out.println(c); 
                            //System.out.println("sad");

                            rt = rt.child[c];
                            //System.out.println(root.lebel);
                            //System.out.println();
                        }
                        //System.out.println(root.lebel);
                        int c = Integer.parseInt(data_mn[n][8]);
                        d[n]=d[n]*Math.exp(-alpha*rt.lebel*c);
                        sum+=d[n];
                    }
                   System.out.println("sum= "+sum);
                   for (int n = 0; n < ind; n++) {
                       //System.out.println(d[n]);
                       d[n] = d[n] /sum;
                       //System.out.println(d[n]);
                       
                   }
                   for (int n = 0; n < ind; n++) {
                       examp exm1 = new examp();
                       exm1.record = data_mn[n];
                       exm1.wt = d[n];
                       exm.add(exm1);
                       //System.out.println("wt = " +exm[0].wt);
                   }
                  Collections.sort(exm);
                  /*for (int n = 0; n < ind; n++) {
                       System.out.println(exm.get(n).wt);
                       //System.out.println(d[n]);
                   }*/
                  double[] cum=new double[1000];
                  cum[0]=exm.get(0).wt;
                  for (int n = 1; n < ind; n++) {
                       cum[n]=cum[n-1]+exm.get(n).wt;
                       //System.out.println(cum[n]);
                   }
                  //System.out.println();
                  String[][] data_n = new String[1000][15];
                   for (int p = 0; p < ind; p++) {

                       double rand = Math.random();
                       for (int n = 0; n < ind; n++) {
                           if(rand<cum[n])
                           {
                               data_n[p]=data_mn[n];
                               break;
                           }
                       }
                   }
                   tree[indx]=nr;
                   tree[indx].alpha=alpha;
                   nr.records=data_n;
                   data_mn=data_n;
                   System.out.println();
                   //h+=alpha*
                   
                   indx++;
              }
               System.out.println("test");
               for(int m=0;m<round;m++ )
               {
                   double e=test(tree[m],test,ind_t,d,m);
               }
               
               int r8=0;
               for(int n=0;n<ind;n++)
               {
                   double predict=0;
                   int cla=0;
                   for(int p=0;p<round;p++)
                   {
                       predict+=result[p][n]*tree[p].alpha;
                   }
                   if(predict>0)cla=1;
                   if(cla==Integer.parseInt(data_m[n][8]))r8++;
                       
               }
               double acc=r8*1.0/ind;
               System.out.println("adaboost accuracy is "+acc*100+"%");
           }

          //test(root,test,ind_t,k);
        }
    }
}


