/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pr_assignment_neotrone;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import static java.lang.Math.abs;
import static java.lang.Math.exp;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 *
 * @author User
 */
class neurone {

    double in;
    double out;
    double del;

    neurone() {
        in = 0;
        out = 0;
        del = 0;
    }
}

class layer {

    int non;
    neurone[] node = new neurone[100];

    layer() {
        non = 0;
    }
}

public class Pr_assignment_neotrone {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String csvFile = "H:\\LEVEL-4-TERM-2\\2.LAB_PR\\NEUTRONE_OFFLINE\\evaluation\\trainNN.txt";
        String line = "";
        String cvsSplitBy = "\\s+";
        Set<String> set = new HashSet<String>();
        String[][] data_m = new String[1000][100];
        //String[][] test = new String[1000][15];
        int ct = 0, fe = 0, ind = 0;
        try (BufferedReader br = new BufferedReader(new FileReader(csvFile))) {
            while ((line = br.readLine()) != null) {
                ct++;
                String[] data = line.split(cvsSplitBy);
                for (int i = 0; i < data.length; i++) {
                    data_m[ind][i] = data[i];
                }
                fe = data.length - 1;
                set.add(data[fe]);
                ind++;
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("sample: " + ct + " fe: " + fe + " class " + set.size());

        csvFile = "H:\\LEVEL-4-TERM-2\\2.LAB_PR\\NEUTRONE_OFFLINE\\dataFilesForNeuralNetwork\\layer_configuration.txt";
        line = "";
        String[] data = new String[100];
        try (BufferedReader br = new BufferedReader(new FileReader(csvFile))) {
            while ((line = br.readLine()) != null) {
                data = line.split(cvsSplitBy);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

        int hl = data.length;
         System.out.println("hl= "+hl);
        layer[] l = new layer[100];
        l[0] = new layer();
        l[0].non = fe;
        for (int i = 1; i <= hl; i++) {
            l[i] = new layer();
            l[i].non = Integer.parseInt(data[i - 1]);
        }
        l[hl + 1] = new layer();
        l[hl + 1].non = set.size();
        /*for(int i=0;i<hl+2;i++)
        {
            System.out.println(l[i].non);
        }*/

        double w[][][] = new double[100][100][100];
        double delw[][][] = new double[100][100][100];
        int layerr = hl + 2;
        int c = 0;
        for (int i = 0; i < layerr - 1; i++) {
            for (int j = 0; j < l[i].non+1; j++) {
                for (int k = 0; k < l[i + 1].non+1; k++) {
                    double rand = Math.random();
                    //System.out.println(rand);
                    w[i][j][k] = rand;
                    //w[i+1][k][j]=rand;
                    c++;
                }
            }
        }
        //System.out.println(c);

        for (int i = 0; i < layerr - 1; i++) {
            for (int j = 0; j < l[i].non+1; j++) {
                for (int k = 0; k < l[i + 1].non+1; k++) {
                    //double rand = Math.random();
                    delw[i][j][k] = 0;
                }
            }
        }

        double a = .1;
        for (int loop = 0; loop < 5; loop++) {
            System.out.println("loop "+loop);
            for (int i = 0; i < ind; i++) {
                double mx=0;
                for(int j=0;j<fe;j++)
                {
                    double d=Double.parseDouble(data_m[i][j]);
                    if(d>mx)mx=d;
                }
                l[0].node[0] = new neurone();
                l[0].node[0].out=1;
                for (int j = 1; j < l[0].non+1; j++) {
                    l[0].node[j] = new neurone();
                    l[0].node[j].in = Double.parseDouble(data_m[i][j-1])/mx;
                    l[0].node[j].out = 1.0 / (1 + exp(-a * l[0].node[j].in));
                    //l[0].node[j].out =l[0].node[j].in;
                   // System.out.println(Double.parseDouble(data_m[i][j-1])/mx);
                    //System.out.println(l[0].node[j].out);
                    //System.out.println();
                }
                //System.out.println();
                for (int j = 1; j < layerr; j++) {
                    l[j].node[0] = new neurone();
                    l[j].node[0].out=1;
                    for (int k = 1; k < l[j].non+1; k++) {
                        l[j].node[k] = new neurone();
                        double in = 0;
                        for (int m = 0; m < l[j - 1].non+1; m++) {
                            in += l[j - 1].node[m].out * w[j - 1][m][k];
                            ///System.out.println(l[j - 1].node[m].out + " "+w[j - 1][m][k]);
                        }
                        //System.out.println("in");
                        l[j].node[k].in = in;
                        l[j].node[k].out = 1.0 / (1 + exp(-a * l[j].node[k].in));
                        if (j == layerr - 1) {
                            //System.out.println(l[j].node[k].in);
                            //System.out.println(l[j].node[k].out);
                            //System.out.println();
                        }

                    }
                }
                //System.out.println();
                //System.out.println();
                double actual = Double.parseDouble(data_m[i][fe]);
                double e = 0;
                for (int j = 1; j < l[layerr - 1].non+1; j++) {
                    double out = l[layerr - 1].node[j].out;
                    if(j!=actual)actual=0;
                    e = abs(out-actual);
                    l[layerr - 1].node[j].del = e * a * out * (1 - out);
                }

                for (int j = layerr - 2; j > -1; j--) {
                    for (int k = 1; k < l[j].non+1; k++) {
                        //l[j].node[k]=new neurone();
                        double er = 0;
                        for (int m = 1; m < l[j + 1].non+1; m++) {
                            er += l[j + 1].node[m].del * w[j][k][m];
                        }
                        double out = l[j].node[k].out;
                        l[j].node[k].del = er * a * out * (1 - out);
                        if (j == 0) {
                            //System.out.println(l[j].node[k].del);
                        }

                    }
                }
                //System.out.println();  
                for (int m = 1; m < layerr; m++) {
                    for (int j = 0; j < l[m].non+1; j++) {
                        for (int k = 0; k < l[m - 1].non+1; k++) {
                            delw[m - 1][k][j] += l[m].node[j].del * l[m - 1].node[k].out;
                            //System.out.println(delw[m-1][k][j]);
                        }
                    }
                }
                //System.out.println();
            }

            double u = .7/ct;
            for (int i = 0; i < layerr - 1; i++) {
                for (int j = 0; j < l[i].non+1; j++) {
                    for (int k = 0; k < l[i + 1].non+1; k++) {
                        delw[i][j][k] *= -u;
                        //System.out.println(delw[i][j][k]);
                    }
                }
            }

           for (int i = 0; i < layerr - 1; i++) {
                for (int j = 0; j < l[i].non+1; j++) {
                    for (int k = 0; k < l[i + 1].non+1; k++) {
                        //System.out.println(w[i][j][k]);
                        //w[i][j][k] += delw[i][j][k];
                        //System.out.println(w[i][j][k]);
                        //System.out.println();
                    }
                }
            }
        }
        
        csvFile = "H:\\LEVEL-4-TERM-2\\2.LAB_PR\\NEUTRONE_OFFLINE\\evaluation\\testNN.txt";
        line = "";
        String[][] data_test = new String[1000][100];
        ct = 0;
        ind = 0;
        try (BufferedReader br = new BufferedReader(new FileReader(csvFile))) {
            while ((line = br.readLine()) != null) {
                ct++;
                String[] data_t = line.split(cvsSplitBy);
                for (int i = 0; i < data_t.length; i++) {
                    data_test[ind][i] = data_t[i];
                }               
                ind++;
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
       
        int r8=0;
        for (int i = 0; i < ind; i++) {
            double mx = 0;
            for (int j = 0; j < fe; j++) {
                double d = Double.parseDouble(data_m[i][j]);
                if (d > mx) {
                    mx = d;
                }
            }
            for (int j = 1; j < l[0].non+1; j++) {
                l[0].node[j].in = Double.parseDouble(data_test[i][j-1])/mx;
                l[0].node[j].out = 1.0 / (1 + exp(-a * l[0].node[j].in));
               //l[0].node[j].out = l[0].node[j].in;
                //System.out.println(l[0].node[j].in);
                //System.out.println(l[0].node[j].out);
                //System.out.println();
            }
            //System.out.println();
            mx=0;
            int node=0;
            for (int j = 1; j < layerr; j++) {
                
                for (int k = 1; k < l[j].non+1; k++) {
                    //l[j].node[k] = new neurone();
                    double in = 0;
                    for (int m = 0; m < l[j - 1].non+1; m++) {
                        in += l[j - 1].node[m].out * w[j - 1][m][k];
                        //in += l[j - 1].node[m].out;
                    }
                    l[j].node[k].in = in ;
                    l[j].node[k].out = 1.0 / (1 + exp(-a * l[j].node[k].in));
                    if (j == layerr - 1) {
                        //System.out.println(l[j].node[k].in);
                        //System.out.println(l[j].node[k].out);
                        //System.out.println(l[j].non);
                        if(l[j].node[k].out>mx)
                        {
                            mx=l[j].node[k].out;
                            node=k+1;
                        }
                        
                    }

                }
            }
            if(node==Integer.parseInt( data_test[i][fe]))r8++;
            
            //System.out.println();
        }
        double acc=r8*1.0/ct;
        System.out.println("accuracy is "+acc*100+"%");
    }
}
