package javaapplication9;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

class word {

    String word;
    int doc;
    int topic;

    word(String w, int d, int t) {
        word = w;
        doc = d;
        topic = t;
    }
}

public class test {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        int k = 20;
        double alpha = 50 / k;
        double eta = .1;
        ArrayList<word> words = new ArrayList<word>();
        Set<String> set = new HashSet<String>();
        File folder = new File("H:\\LEVEL-4-TERM-2\\3.LAB_ML\\ASSIGNMENT-3\\Assignment 3\\20newsgroups");
        //File folder = new File("H:\\LEVEL-4-TERM-2\\3.LAB_ML\\ASSIGNMENT-3\\Assignment 3\\artificial");
        File[] listOfFiles = folder.listFiles();

        BufferedReader br = null;
        int d = 0;
        for (File file : listOfFiles) {

            if (file.isFile()) {
                //System.out.println(file.getName());
                d++;
                String sCurrentLine;
                br = new BufferedReader(new FileReader(folder + "\\" + file.getName()));
                while ((sCurrentLine = br.readLine()) != null) {
                    //System.out.println(sCurrentLine);
                    String res[] = sCurrentLine.split("\\s+");

                    for (String w : res) {
                        //System.out.println(w);

                        double rand = Math.random();
                        double div = 1.0 / k;
                        int topic = (int) ((rand / div)) + 1;
                        //System.out.println(rand);
                        //System.out.println(topic);
                        word nw = new word(w, d, topic);
                        words.add(nw);
                        set.add(w);

                    }
                }
            }
            //System.out.println();
        }
        //System.out.println("d : " + d);
        /* Iterator itr11 = words.iterator();
        while (itr11.hasNext()) {
            word w = (word) itr11.next();
            System.out.println("word: "+w.word+" "+w.doc+" "+w.topic);
        }*/
        int V = set.size();
        int[][] n1 = new int[d + 5][k + 5];
        int[][] n2 = new int[k + 5][V + 5];

        for (int i = 1; i <= d; i++) {
            for (int j = 1; j <= k; j++) {
                int ct = 0;
                Iterator itr = words.iterator();
                while (itr.hasNext()) {
                    word w = (word) itr.next();
                    if (w.doc == i && w.topic == j) {
                        ct++;
                    }
                }
                n1[i][j] = ct;
                //System.out.println(i+" "+j+" "+ct);
            }
        }

        for (int i = 1; i <= k; i++) {
            Iterator itr1 = set.iterator();
            int j = 1;
            while (itr1.hasNext()) {
                String w1 = (String) itr1.next();
                Iterator itr = words.iterator();
                int ct = 0;
                while (itr.hasNext()) {
                    word w = (word) itr.next();
                    if (w.topic == i && w.word.equals(w1)) {
                        ct++;
                    }
                }
                n2[i][j] = ct;
                //System.out.println(i+" "+j+" "+ct);
                j++;

            }
        }

        //double[] p = new double[k + 5];
        double[] cum = new double[k + 5];
        int loop = 1000;
        int s_w = words.size();
        int[][] n_f = new int[loop + 5][s_w + 5];
        int[] t_f = new int[s_w + 5];
        //System.out.println(set);

        for (int i = 1; i <= loop; i++) {
            //System.out.println();
            System.out.println("Loop: "+i);
            Iterator itr = words.iterator();
            int j = 0;
            while (itr.hasNext()) {
                j++;
                word w = (word) itr.next();
                int doc = w.doc;
                int topic = w.topic;
                n1[doc][topic]--;
                //System.out.println("n1["+doc+"]["+topic+"] :"+n1[doc][topic]);
                String w1 = w.word;
                Iterator itr1 = set.iterator();
                int v = 1;
                while (itr1.hasNext()) {
                    String w2 = (String) itr1.next();
                    if (w1.equals(w2)) {
                        break;
                    } else {
                        v++;
                    }
                }
                n2[topic][v]--;
                //System.out.println("n2["+topic+"]["+v+"] :"+n2[topic][v]);
                double n1_ = 0;
                for (int t = 1; t <= k; t++) {
                    n1_ += n1[doc][t];
                }

                ArrayList p = new ArrayList<Double>();
                ArrayList p1 = new ArrayList<Double>();
                ArrayList q = new ArrayList<Double>();

                for (int t = 1; t <= k; t++) {
                    double f = (alpha + n1[doc][t]) * 1.0 / (k * alpha + n1_);
                    double n2_ = 0;
                    for (int v1 = 1; v1 <= V; v1++) {
                        n2_ += n2[t][v1];
                    }
                    double s = (eta + n2[t][v]) * 1.0 / (set.size() * eta + n2_);
                    //System.out.println("f: " + f + " s: " + s);
                    p.add(f * s);
                }

                double tot = 0;
                Iterator itr_p = p.iterator();

                while (itr_p.hasNext()) {

                    double p_ = (double) itr_p.next();
                    tot += p_;
                }

                itr_p = p.iterator();
                while (itr_p.hasNext()) {

                    double p_ = (double) itr_p.next();
                    p1.add(p_ / tot);
                    //System.out.println("  p[n] : " + p_ / tot);
                }

                itr_p = p1.iterator();

                while (itr_p.hasNext()) {
                    q.add(itr_p.next());
                }

                Collections.sort(q);

                itr_p = q.iterator();
                //double p_=0;
                while (itr_p.hasNext()) {
                    double ax = (double) itr_p.next();
                    //System.out.println("  q[n] : " + ax);
                }
                /*itr_p = q.iterator();
                cum[1] = (double) itr_p.next();
                System.out.println("  cum[1] : " + cum[1]);
                for (int n = 2; n <= k; n++) {
                    cum[n] = cum[n - 1] + (double) itr_p.next();
                    System.out.println("  cum[2] : " + cum[n]);
                }*/
                //System.out.println();
                double rand = Math.random();

                itr_p = q.iterator();
                double p_ = 0;
                while (itr_p.hasNext()) {
                    double ax = (double) itr_p.next();
                    p_ = p_ + ax;
                    if (rand <= p_) {
                        w.topic = p1.indexOf(ax) + 1;
                        n_f[i][j] = p1.indexOf(ax) + 1;
                        //System.out.println("rand: " + rand + " n: " +n_f[i][j]+" ax: "+ax);
                        break;
                    }
                }

                /*for (int n = 1; n <= k; n++) {
                    if (rand <= cum[n]) {
                        w.topic = p1.indexOf(cum[n] - cum[n - 1])+1;
                        n_f[i][j] = p1.indexOf(cum[n] - cum[n - 1])+1;
                        System.out.println("rand: " + rand + " n: " + n_f[i][j] + " (cum[n]-cum[n-1]): " + (cum[n] - cum[n - 1]));
                        break;
                    }

                }*/
                n1[doc][w.topic]++;
                n2[w.topic][v]++;
                //System.out.print(w.topic + " ");

            }
        }

        //System.out.println();
        Iterator itr = words.iterator();
        int ind = 0;
        while (itr.hasNext()) {
            ind++;
            word w = (word) itr.next();
            
            int[] ct = new int[k + 5];
            for (int j = 1; j <= loop; j++) {
                int ind1=n_f[j][ind];
                ct[ind1]++;
            }
            
            int f_ind=0;
            int mx=-1;
            for (int j = 1; j <= k; j++) {
                if(ct[j]>mx)
                {
                    mx=ct[j];
                    f_ind=j;
                }
            }
            w.topic = f_ind;
            //System.out.print(" " + w.topic);
        }
        //System.out.println("ind :" + ind);

        for (int i = 1; i <= d; i++) {
            for (int j = 1; j <= k; j++) {
                int ct = 0;
                Iterator itr1 = words.iterator();
                while (itr1.hasNext()) {
                    word w = (word) itr1.next();
                    if (w.doc == i && w.topic == j) {
                        ct++;
                    }
                }
                n1[i][j] = ct;
                //System.out.println(i+" "+j+" "+ct);
            }
        }

        for (int i = 1; i <= k; i++) {
            Iterator itr1 = set.iterator();
            int j = 1;
            while (itr1.hasNext()) {
                String w1 = (String) itr1.next();
                Iterator itr2 = words.iterator();
                int ct = 0;
                while (itr2.hasNext()) {
                    word w = (word) itr2.next();
                    if (w.topic == i && w.word.equals(w1)) {
                        ct++;
                    }
                }
                n2[i][j] = ct;
                //System.out.println(i + " " + j + " " + ct);
                j++;

            }
        }

        double[][] theta = new double[d + 5][k + 5];
        double[][] beta = new double[k + 5][set.size() + 5];

        for (int i = 1; i <= d; i++) {
            double n1_ = 0;
            for (int t = 1; t <= k; t++) {
                n1_ += n1[i][t];
            }
            for (int t = 1; t <= k; t++) {
                theta[i][t] = (alpha + n1[i][t]) * 1.0 / (k * alpha + n1_);
            }

        }

        //System.out.println(set);
        //System.out.println("set_size "+V);
        FileWriter fw = new FileWriter("H:\\LEVEL-4-TERM-2\\3.LAB_ML\\ASSIGNMENT-3\\Assignment 3\\topicwords_1205043.csv");
        PrintWriter out = new PrintWriter(fw);
        for (int i = 1; i <= k; i++) {
            double n2_ = 0;
            for (int v = 1; v <= set.size(); v++) {
                n2_ += n2[i][v];
            }
            ArrayList p = new ArrayList<Double>();
            ArrayList p1 = new ArrayList<Double>();
            for (int v = 1; v <= set.size(); v++) {
                beta[i][v] = (eta + n2[i][v] * 1.0) / (set.size() * eta + n2_);
                p.add(beta[i][v]);
                p1.add(beta[i][v]);
                //System.out.println("beta :" + beta[i][v]);
            }
            Collections.sort(p1);
            //System.out.println();
            //System.out.println(p1);

            Iterator itr_p = p1.iterator();
            double a = 0;
            for (int l = 0; l < (V - 5); l++) {
                a = (double) itr_p.next();

            }
            int[] flag = new int[V + 10];
            for (int l = 0; l < 5; l++) {
                a = (double) itr_p.next();
                //System.out.println("itr_p.next() "+a);
                int pos = p.indexOf(a);
                while (flag[pos] != 0) {
                    pos++;
                }
                flag[pos] = 1;
                Iterator itr_s = set.iterator();
                int pos1 = 0;
                while (pos1 < pos) {
                    String w2 = (String) itr_s.next();
                    pos1++;
                }
                String w1 = (String) itr_s.next();
                System.out.print(w1 + "  ");
                out.print(w1 + "  ,");
            }
            out.println();
            out.println();
            System.out.println();
            //System.out.println();

        }
        //Flush the output to the file
        out.flush();

        //Close the Print Writer
        out.close();

        //Close the File Writer
        fw.close();

    }

}
