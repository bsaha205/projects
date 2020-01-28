package pr_channel_eualization;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class Pr_channel_eualization {
    static double h[] = new double[100];
    static double var = .005;
    static int span;
    public static void get_span() throws FileNotFoundException, IOException {
        String FILENAME = "H:\\LEVEL-4-TERM-2\\2.LAB_PR\\CHANNEL_EQUALIZATION_OFFLINE\\h.txt";
        BufferedReader br = new BufferedReader(new FileReader(FILENAME));
        int i=0;
        String h1;
        while((h1 = br.readLine())!=null)
        {
            h[i] = Double.parseDouble(h1);
            i++;
            //System.out.println(h[i]);
        }
        span=i;
    }   

    public static double gaussian(double x, double m, double var) {
        double result = 0;
        double temp = 1 / (Math.sqrt(2 * Math.PI * var));
        result = Math.exp(-((x - m) * (x - m)) / (2 * var));
        result = temp * result;
        return result;
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        get_span();
        
        int s_z = (int) Math.pow(2, span);
        double prior[] = new double[s_z];
        double mean[] = new double[s_z];
        double tran[][] = new double[s_z][s_z];
        String FILENAME = "H:\\LEVEL-4-TERM-2\\2.LAB_PR\\CHANNEL_EQUALIZATION_OFFLINE\\train.txt";

        BufferedReader br = new BufferedReader(new FileReader(FILENAME));
        String bits = br.readLine();
        //System.out.println(bits.length());
        //System.out.println(s_z);
        for (int i = 0; i <= bits.length() - span; i++) {
            String bit = bits.substring(i, i + span);
            //System.out.println(bit);
            int ind = Integer.parseInt(bit, 2);
            //System.out.println(bit+" "+ind);
            prior[ind] += 1;
            double m = 0;
            for (int j = 0; j < span; j++) {
                if (bit.charAt(j) == '1') {
                    m += h[j];
                } else {
                    m -= h[j];
                }
            }
            //System.out.println(m);
            Random r = new Random();
            double xk = m + r.nextGaussian() * var;
            mean[ind] += xk;

            if ((i + span + 1) <= bits.length()) {
                bit = bits.substring(i + 1, i + span + 1);
                int ind2 = Integer.parseInt(bit, 2);
                tran[ind][ind2] += 1;
            }

        }
        for (int i = 0; i < s_z; i++) {
            //System.out.println(prior[i]);
            if (prior[i] != 0) {
                mean[i] /= prior[i];
            }
            prior[i] /= (bits.length() - span + 1);
            //System.out.println(prior[i]+" "+mean[i]);

        }

        for (int i = 0; i < s_z; i++) {
            double sum = 0;
            for (int j = 0; j < 8; j++) {
                sum += tran[i][j];
            }
            if (sum != 0) {
                for (int j = 0; j < 8; j++) {
                    tran[i][j] /= sum;
                }
            }
        }
        /*System.out.println("Transition");
        for(int i=0;i<s_z;i++)
        {          
            for(int j=0;j<s_z;j++)
            {
                System.out.println(tran[i][j]);
            }
            System.out.println();
        }*/

        FILENAME = "H:\\LEVEL-4-TERM-2\\2.LAB_PR\\CHANNEL_EQUALIZATION_OFFLINE\\test.txt";
        br = new BufferedReader(new FileReader(FILENAME));
        String test = br.readLine();
        System.out.println(test+" "+test.length());
        double cost[][] = new double[s_z][test.length() - span + 1];
        double back_prop[][] = new double[s_z][test.length() - span + 1];
        for (int i = 0; i <= 0; i++) {
            String bit = test.substring(i, i + span);
            //int ind=Integer.parseInt(bit,2);           
            double m = 0;
            for (int j = 0; j < span; j++) {
                if (bit.charAt(j) == '1') {
                    m += h[j];
                } else {
                    m -= h[j];
                }
            }
            //System.out.println(m);
            Random r = new Random();
            double xk = m + r.nextGaussian() * var;

            for (int j = 0; j < s_z; j++) {
                double p = prior[j];
                if (p != 0) {
                    p = Math.log(p);
                }
                double g = gaussian(xk, mean[j], var);
                if (g != 0) {
                    g = Math.log(g);
                }
                cost[j][i] = p + g;
                back_prop[j][i]=j;
                //System.out.println(cost[j][i]);
            }

        }

        for (int i = 1; i <= test.length() - span; i++) {
            //System.out.println(i+span);
            String bit = test.substring(i, i + span);
            //int ind = Integer.parseInt(bit, 2);
            double m = 0;
            for (int j = 0; j < span; j++) {
                if (bit.charAt(j) == '1') {
                    m += h[j];
                } else {
                    m -= h[j];
                }
            }
            //System.out.println(m);
            Random r = new Random();
            double xk = m + r.nextGaussian() * var;

            for (int j = 0; j < s_z; j++) {
                double mx = -1000000000;
                for (int k = 0; k < s_z; k++) {
                    double c = cost[k][i - 1];
                    double p = tran[k][j];
                    if (p != 0) {
                        p = Math.log(p);
                    }
                    double g = gaussian(xk, mean[j], var);
                    if (g != 0) {
                        g = Math.log(g);
                    }
                    double tot_c = c + p + g;
                    if (tot_c > mx) {
                        cost[j][i] = tot_c;
                        mx = tot_c;
                        back_prop[j][i]=k;
                    }

                    //System.out.println(cost[j][i]);
                }

            }
        }

        /*for (int j = 0; j < s_z; j++) {
            for (int i = 0; i <= test.length() - span; i++) {
                System.out.print(back_prop[j][i] + " ");
            }
            System.out.println();
        }*/
        
        
        int num[]=new int[test.length() - span+1];
        double mx= cost[0][test.length() - span];
        for(int j=1;j<s_z;j++)
        {
            if(cost[j][test.length() - span]>mx)
            {
                mx=cost[j][test.length() - span];
                num[test.length() - span]=j;
            }
        }
        //System.out.println(num[test.length() - span]);
        int last=num[test.length() - span];
        for(int i=test.length() - span-1;i>-1;i--)
        {
            num[i]=(int) back_prop[last][i+1];
            last=num[i];
        }
        
        String pre = Integer.toBinaryString(num[0]);
        String predict="";
        for(int i=0;i<span-pre.length();i++)
        {
            predict=predict+"0";
        }
        predict=predict+pre;
        for(int i=1;i<=test.length() - span;i++)
        {
            if(num[i]%2==0)predict=predict+"0";
            else predict=predict+"1";
            //System.out.println(p);
        }
        System.out.println(predict+" "+predict.length());
        
        int error=0;
        for(int i=0;i<test.length();i++)
        {
            if(test.charAt(i)!=predict.charAt(i))error++;
        }
        FILENAME = "H:\\LEVEL-4-TERM-2\\2.LAB_PR\\CHANNEL_EQUALIZATION_OFFLINE\\out.txt";
        BufferedWriter writer = new BufferedWriter(new FileWriter(FILENAME));
        writer.write(predict);
        writer.close( );
        
        double acc=(test.length()-error)*100/test.length();
        System.out.println("accuracy is "+acc+"%");
    }

}
