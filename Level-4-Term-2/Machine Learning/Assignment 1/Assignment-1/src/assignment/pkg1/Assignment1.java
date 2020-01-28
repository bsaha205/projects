/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package assignment.pkg1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

 class node {
     String[][] records = new String[1000][15];
     int f_own;
     int f_child;
     node[] child= new node[12];
     int[] f=new int[12];
     int lebel;
     int len;
    
    
    node()
    {
        records=null;
        f_own=-1;
        f_child=-1;
        lebel=-1;
        len=-1;
        
    }
    
}


public class Assignment1 {

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
    
    public static void DT(node root)
    {
        //System.out.println(" baal");
        int yes=0;
        for(int i=0;i<root.len;i++)
        {
            if(root.records[i][8].equals("1")) yes++;
        }
        //System.out.println(" baal1");
        if(yes==root.len)
        {
            root.lebel=1;
            return;
        }
        //System.out.println(" baa3");
        if(yes==0)
        {
            root.lebel=0;
            return;
        }
        //System.out.println(" baa4");
        int ct=0;
        for(int i=0;i<8;i++)
        {
            if(root.f[i]==1)ct++;
        }
        if(ct==0)
        {
            int no=root.len-yes;
            if(yes>=no)
            {
                 root.lebel=1;
                 return;
            }
            else
            {
                 root.lebel=0;
                 return;
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
                node child=new node();
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
                    
                    DT(child);
                  
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
   public static double [][] result=new double[10][7];
    public static void test(node root,String[][] test,int len,int ind)
    {
       int tp=0,tn=0,fp=0,fn=0;
       //System.out.println("sad");
       node rt=root;
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
                if(root.lebel==1 && c==1 )tp++;
                else if(root.lebel==0 && c==0 )tn++;
                else if(root.lebel==1 && c==0 )fp++;
                else fn++;
                
           
          
        }
          System.out.println("tp: "+tp); 
          System.out.println("tn: "+tn); 
          System.out.println("fp: "+fp); 
          System.out.println("fn: "+fn); 
          double tpr=tp*1.0/(tp+fn);
          double tnr=tn*1.0/(tn+fp); 
          double ppv=tp*1.0/(tp+fp);
          double npv=tn*1.0/(tn+fn);
          double fpr=fp*1.0/(tn+fp);
          double fdr=fp*1.0/(fp+tp);
          double fnr=fn*1.0/(tp+fn);
          double f1=2*tp*1.0/(2*tp+fn+fp);
          double acc=(tp+tn)*1.0/len;
          System.out.println("tpr: "+tpr); 
          System.out.println("tnr: "+tnr);
          System.out.println("ppv: "+ppv); 
          System.out.println("npv: "+npv);
          System.out.println("fpr: "+fpr); 
          System.out.println("fdr: "+fdr);
          System.out.println("fnr: "+fnr); 
          System.out.println("f1: "+f1);
          System.out.println("acc: "+acc);
          System.out.println("--------------------------------------------");
          System.out.println("--------------------------------------------");
          
          result[0][ind]=tpr;
          result[1][ind]=tnr;
          result[2][ind]=ppv;
          result[3][ind]=npv;
          result[4][ind]=fpr;
          result[5][ind]=fdr;
          result[6][ind]=fnr;
          result[7][ind]=f1;
          result[8][ind]=acc;
              
    }
    
    public static void main(String[] args) {

        //double entro=entropy();
        //System.out.println("Entropy = "+entro);
        int f=8;
        int v=11;
        for(int k=0;k<5;k++)
        {
            
            System.out.println("k: "+k+"\n");
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

           node root=new node();
           root.records=data_m;
           root.f=fe;
           root.len=ind;
           //System.out.println(root.records.length);
           DT(root);

          // print(root);
           /*for(int i=0;i<4;i++)
            {
                System.out.println(root.f[i]);
                //System.out.println("Info Gain = "+info_gain(data_m,ind,i));
            }*/
           //System.out.println(ind_t);
            //System.out.println("aaa");
          // double [][] result=new double[10][7];
          test(root,test,ind_t,k);
        }
          double tpr_avg=0;
          for(int i=0;i<5;i++)
          {
              tpr_avg +=result[0][i];
          }
          tpr_avg=tpr_avg/5;
          
          double tnr_avg=0;
          for(int i=0;i<5;i++)
          {
              tnr_avg +=result[1][i];
          }
          tnr_avg=tnr_avg/5;
          
          double ppv_avg=0;
          for(int i=0;i<5;i++)
          {
              ppv_avg +=result[2][i];
          }
          ppv_avg=ppv_avg/5;
          
          
          double npv_avg=0;
          for(int i=0;i<5;i++)
          {
              npv_avg +=result[3][i];
          }
          npv_avg=npv_avg/5;
          
          
          double fpr_avg=0;
          for(int i=0;i<5;i++)
          {
              fpr_avg +=result[4][i];
          }
          fpr_avg=fpr_avg/5;
          
          
          double fdr_avg=0;
          for(int i=0;i<5;i++)
          {
              fdr_avg +=result[5][i];
          }
          fdr_avg=fdr_avg/5;
          
          
          double fnr_avg=0;
          for(int i=0;i<5;i++)
          {
              fnr_avg +=result[6][i];
          }
          fnr_avg=fnr_avg/5;
          
          
          double f1_avg=0;
          for(int i=0;i<5;i++)
          {
              f1_avg +=result[7][i];
          }
          f1_avg=f1_avg/5;
          
          
          double acc_avg=0;
          for(int i=0;i<5;i++)
          {
              acc_avg +=result[8][i];
          }
          acc_avg=acc_avg/5;
          
          
          System.out.println("tpr_avg: "+tpr_avg); 
          System.out.println("tnr_avg: "+tnr_avg);
          System.out.println("ppv_avg: "+ppv_avg); 
          System.out.println("npv_avg: "+npv_avg);
          System.out.println("fpr_avg: "+fpr_avg); 
          System.out.println("fdr_avg: "+fdr_avg);
          System.out.println("fnr_avg: "+fnr_avg); 
          System.out.println("f1_avg: "+f1_avg);
          System.out.println("acc_avg: "+acc_avg);
        
    }
}


