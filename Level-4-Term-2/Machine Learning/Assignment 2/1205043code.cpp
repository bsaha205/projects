#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

//int llc, flc;

int atrange=11;

class node
{
    public:
    int feature;
    int outcome[11];
    double cum_weight;
};

double calculate_h(double pos, double neg, double lc)
{
    double fp=0;
    double fn=0;
    if(pos!=0)fp=-((pos/lc)*log2(pos/lc));
    if(neg!=0)fn=-((neg/lc)*log2(neg/lc));
    double res=fp+fn;
    return res;
}

double scount=0;

double calculate_s(int **examples, int value, int feature, int lc, int feat)
{
    double pos=0;
    double neg=0;

    for(int i=0; i<lc; i++)
    {
        if(examples[i][feature]==value)
        {
            scount++;
            if(examples[i][feat]==0)neg++;
            else if (examples[i][feat]==1)pos++;
        }
    }

    double llc=lc;

    double hs = calculate_h(pos, neg, lc);

    //cout<<"hs is "<<hs<<endl;

    return hs;
}

double info_gain(int **examples, int feature, int lc, int feat)
{
    double s_att[11];
    double sum=0;
    for(int i=1; i<11; i++)
    {
        scount=0;
        double llc=lc;
        s_att[i]=calculate_s(examples, i, feature, lc, feat);
        sum += ((scount/llc)*s_att[i]);
    }
    return sum;

}

int DT(int **examples, int *labels, int *features, int lc, int feat, node *tree)
{

    double hif;

    double pos=0;
    double neg=0;

    for(int i=0; i<lc; i++)
    {
        if(examples[i][feat]==0)neg++;
        else if (examples[i][feat]==1)pos++;
    }

    double llc=lc;

    double hs = calculate_h(pos, neg, lc);


    //cout<<"pos is "<<pos<<" and neg is "<<neg<<" and h is "<<hs<<endl;

    double ig;
    double max=-1;
    int chosen_feat;

    for(int i=0; i<feat; i++)
    {
        if(features[i]==0)continue;
        hif=info_gain(examples, i, lc, feat);
        ig=hs-hif;
        //cout<<"for feature "<<i<<" information gain is: "<<ig<<endl;
        if(ig>max)
        {
            max=ig;
            chosen_feat=i;
        }
    }
    //cout<<"chosen feature is: "<<chosen_feat<<endl;
    tree->feature=chosen_feat;
    for(int l=1; l<atrange; l++)
    {
        int pcount=0;
        int ncount=0;
        for(int i=0; i<lc; i++)
        {
            if(examples[i][chosen_feat]==l&&examples[i][feat]==1)pcount++;
            else if(examples[i][chosen_feat]==l&&examples[i][feat]==0)ncount++;
        }
        if(ncount>pcount)
        {
            tree->outcome[l]=0;
            return 0;
        }
        else
        {
            tree->outcome[l]=1;
            return 1;
        }
    }

    //cout<<"Tree outcome: "<<tree->outcome<<endl;

}

void traverse(node *tree)
{
    //cout<<"feature "<<tree->feature<<" outcome "<<tree->outcome<<endl;
    //if(tree->outcome==1||tree->outcome==0)return;
    return;
}

double atpr=0;
double atnr=0;
double appv=0;
double anpv=0;
double afpr=0;
double afnr=0;
double afdr=0;
double af1=0;
double aacc=0;

double tpr=0;
double tnr=0;
double ppv=0;
double npv=0;
double fpr=0;
double fnr=0;
double fdr=0;
double f1=0;
double acc=0;

double cp=0;
double cn=0;
double tp=0;
double tn=0;
double fp=0;
double fn=0;

double avgb=0;
double avgd=0;

void checkData(int **data, int nlc, int feat, node *dStumps, int val_t)
{
    tp=0;
    tn=0;
    fp=0;
    fn=0;
    int result;
    srand( time(NULL) );
    for(int x=0; x<nlc; x++)
    {
        double r = (rand()/(RAND_MAX*1.0));
        int d=0;
        for(int j=0;j<val_t;j++)
        {
            if(dStumps[j].cum_weight>r)
            {
                d=j;
                break;
            }
        }
        //cout<<d<<endl;
        for(int l=1; l<atrange; l++)
        {
            if(data[x][dStumps[d].feature]==l)
            {
                result=dStumps[d].outcome[l];
                break;
            }
        }
        int rr=data[x][feat];
        if(rr==1&&result==1)tp++;
        if(rr==0&&result==0)tn++;
        if(rr==1&&result==0)fn++;
        if(rr==0&&result==1)fp++;
        //cout<<"result is "<<result<<" true result "<<rr<<endl;
    }
    /*for(int i=0; i<nlc; i++)
    {
        result=treeDecision(data[i],feat,tree,i);
        int rr=data[i][feat];
        if(rr==1&&result==1)tp++;
        if(rr==0&&result==0)tn++;
        if(rr==1&&result==0)fn++;
        if(rr==0&&result==1)fp++;
        //cout<<"result for "<<i+534<<" is: "<<result<<" and real result is: "<<data[i][feat]<<endl;
    }*/

    //cout<<"tp: "<<tp<<" tn: "<<tn<<" fp: "<<fp<<" fn: "<<fn<<endl;
    tpr=tp/(tp+fn);
    tnr=tn/(tn+fp);
    ppv=tp/(tp+fp);
    npv=tn/(tn+fn);
    fpr=fp/(fp+tn);
    fnr=fn/(tp+fn);
    fdr=fp/(tp+fp);
    f1=(2*tp)/((2*tp)+fp+fn);
    acc=(tp+tn)/(tp+fp+tn+fn);
    if(acc!=acc)acc=0;
    //if(acc!=acc)cout<<"tp: "<<tp<<" tn: "<<tn<<" fp: "<<fp<<" fn: "<<fn<<endl;
}

int treeDecision(int *data, int feat, node tree, int ch, int featval)
{
    for(int i=1; i<atrange; i++)
    {
        if(featval==i)
        {
            return tree.outcome[i];
        }
    }
    return 1;
}

double calculate_error(int **data, int nlc, int feat, node tree, double *weight)
{
    tp=0;
    tn=0;
    fp=0;
    fn=0;
    double error=0;
    int result;
    for(int i=0; i<nlc; i++)
    {
        result=treeDecision(data[i],feat,tree,i,tree.feature);
        int rr=data[i][feat];
        if(rr==1&&result==1)tp++;
        if(rr==0&&result==0)tn++;
        if(rr==1&&result==0)
        {
            error+=weight[i];
            //cout<<error<<" fn "<<weight[i]<<endl;
            fn++;
        }
        if(rr==0&&result==1)
        {
            error+=weight[i];
            //cout<<error<<" fp "<<weight[i]<<endl;
            fp++;
        }
        //cout<<"result for "<<i+534<<" is: "<<result<<" and real result is: "<<data[i][feat]<<endl;
    }

    //cout<<"tp: "<<tp<<" tn: "<<tn<<" fp: "<<fp<<" fn: "<<fn<<endl;
    tpr=tp/(tp+fn);
    tnr=tn/(tn+fp);
    ppv=tp/(tp+fp);
    npv=tn/(tn+fn);
    fpr=fp/(fp+tn);
    fnr=fn/(tp+fn);
    fdr=fp/(tp+fp);
    f1=(2*tp)/((2*tp)+fp+fn);
    acc=(tp+tn)/(tp+fp+tn+fn);
    return error;
}

void checksData(int **data, int nlc, int feat, node *dStumps, int val_t)
{
    tp=0;
    tn=0;
    fp=0;
    fn=0;
    int result;
    srand( time(NULL) );
    double value;
    for(int x=0; x<nlc; x++)
    {
        double total=0;
        for(int j=0;j<val_t;j++)
        {
            for(int l=1; l<atrange; l++)
            {
                if(data[x][dStumps[j].feature]==l)
                {
                    result=dStumps[j].outcome[l];
                    if(result==1)value=1;
                    else value=-1;
                    total+=(value*dStumps[j].cum_weight);
                    //cout<<total<<endl;
                    break;
                }
            }
        }
        //cout<<d<<endl;
        if(total<0)result=0;
        else result=1;
        int rr=data[x][feat];
        if(rr==1&&result==1)tp++;
        if(rr==0&&result==0)tn++;
        if(rr==1&&result==0)fn++;
        if(rr==0&&result==1)fp++;
        //cout<<"result is "<<result<<" true result "<<rr<<endl;
    }
    /*for(int i=0; i<nlc; i++)
    {
        result=treeDecision(data[i],feat,tree,i);
        int rr=data[i][feat];
        if(rr==1&&result==1)tp++;
        if(rr==0&&result==0)tn++;
        if(rr==1&&result==0)fn++;
        if(rr==0&&result==1)fp++;
        //cout<<"result for "<<i+534<<" is: "<<result<<" and real result is: "<<data[i][feat]<<endl;
    }*/

    //cout<<"tp: "<<tp<<" tn: "<<tn<<" fp: "<<fp<<" fn: "<<fn<<endl;
    tpr=tp/(tp+fn);
    tnr=tn/(tn+fp);
    ppv=tp/(tp+fp);
    npv=tn/(tn+fn);
    fpr=fp/(fp+tn);
    fnr=fn/(tp+fn);
    fdr=fp/(tp+fp);
    f1=(2*tp)/((2*tp)+fp+fn);
    acc=(tp+tn)/(tp+fp+tn+fn);
    if(acc!=acc)acc=0;
    //if(acc!=acc)cout<<"tp: "<<tp<<" tn: "<<tn<<" fp: "<<fp<<" fn: "<<fn<<endl;
}


void k_fold_cv(int kfold, int lc, int fc, int lcc, int val_t)
{
    string line;
    aacc=0;
    for(int i=0;i<kfold;i++)
    {
        //cout<<"for dataset "<<i+1<<endl;

        lc=(kfold-1)*(lcc/kfold);

        int nlc=lcc-lc;

        int in=i*(lcc/kfold);
        int fin=in+nlc;
        //cout<<"nlc is "<<nlc<<" in "<<in<<" fin "<<fin<<endl;
        double *weight=new double [lc];
        double *cume_weight=new double [lc];
        int **dataset= new int *[lc];
        int **data= new int *[nlc];
        for(int i=0;i<lc;i++)
        {
            dataset[i]=new int[fc];
            weight[i]=(1.0/lc);
            if(i==0)cume_weight[i]=1.0/lc;
            else cume_weight[i]=cume_weight[i-1]+weight[i];
        }
        //cout<<"cume weight "<<cume_weight[lc-1]<<endl;
        for(int i=0;i<nlc;i++)
        {
            data[i]=new int[fc];
        }

        ifstream ifile("Assignment1_data_set.csv");
        int c=-2;
        int k=0;
        while (getline(ifile, line))
        {
            c++;
            if(c==-1)continue;
            istringstream iss(line);

            vector<string> tokens;
            string token;
            while (getline(iss, token, ','))
            {
                tokens.push_back(token);
            }
            for (int i=0; i<tokens.size(); i++)
            {
                int Result;
                stringstream convert(tokens[i]);
                convert >> Result;
                if(c>=in&&c<fin)
                {
                    data[c-in][i]=Result;
                }
                else if(c<in)
                {
                    //cout<<k<<endl;
                    dataset[c][i]=Result;
                }
                else if(c>=fin)
                {
                    dataset[c-fin][i]=Result;
                }
            }
        }
        //cout<<"line no: "<<lc<<" and column no: "<<fc<<endl;

        node dStumps[val_t];
        for(int t=0; t<val_t; t++)
        {
            int **examples= new int *[lc];
            for(int i=0;i<lc;i++)
            {
                examples[i]=new int[fc];
            }

            //taking randomly generated number into examples
            srand( time(NULL) );
            for(int i=0; i<lc; i++)
            {
                double r = (rand()/(RAND_MAX*1.0));
                int d=0;
                for(int j=0;j<lc;j++)
                {
                    if(cume_weight[j]>r)
                    {
                        d=j;
                        break;
                    }
                }

                for(int j=0; j<fc; j++)
                {
                    examples[i][j]=dataset[d][j];
                }
            }

            node *dtree;
            int labels[2]={0,1};
            int features[fc-1];
            int feat = fc-1;
            for(int i=0; i<feat; i++)
            {
                features[i]=i;
            }
            dtree = new node;
            DT(examples, labels, features, lc, feat, dtree);

            dStumps[t].feature=dtree->feature;
            for(int l=1; l<atrange; l++)
            {
                dStumps[t].outcome[l]=dtree->outcome[l];
                //cout<<"feature "<<dStumps[t].feature<<" outcome "<<dStumps[t].outcome<<endl;
            }

            //checkData(data, nlc, feat, dStumps[t]);
            double e=calculate_error(dataset, lc, feat, dStumps[t],weight);
            //cout<<"error is "<<e<<endl;
            double alpha=.5*log((1-e)/e);
            if(e==0)alpha=4;
            if(e>.49)alpha=0;
            //cout<<"alpha is "<<alpha<<endl;
            dStumps[t].cum_weight=alpha;
            //if(t==0)dStumps[t].cum_weight=alpha;
            //else dStumps[t].cum_weight=dStumps[t-1].cum_weight+alpha;
            double tot=0;
            for(int i=0; i<lc; i++)
            {
                for(int l=1; l<atrange; l++)
                {
                    if(dStumps[t].feature==l && dStumps[t].outcome[l]==dataset[i][fc-1])
                    {
                        //cout<<weight[i]<<"  ";
                        weight[i]=weight[i]*exp(-alpha);
                        break;
                        //cout<<weight[i]<<endl;
                    }
                    else if(dStumps[t].feature==l && dStumps[t].outcome[l]!=dataset[i][fc-1])
                    {
                        //cout<<weight[i]<<"  ";
                        weight[i]=weight[i]*exp(alpha);
                        break;
                        //cout<<weight[i]<<endl;
                    }
                }
                tot+=weight[i];
            }
            //if(t==0)dStumps[t].cum_weight=alpha;
            //else dStumps[t].cum_weight=dStumps[t-1].cum_weight+alpha;
            for(int i=0;i<lc;i++)
            {
                weight[i]=weight[i]/tot;
                //cout<<weight[i]<<endl;
                if(i==0)cume_weight[i]=weight[i];
                else cume_weight[i]=cume_weight[i-1]+weight[i];
            }
            //cout<<"cume weight "<<cume_weight[lc-1]<<endl;

        }

        /*for(int x=0; x<val_t; x++)
        {
            dStumps[x].cum_weight=dStumps[x].cum_weight/dStumps[val_t-1].cum_weight;
            //cout<<dStumps[x].cum_weight<<endl;
        }*/

        checksData(data, nlc, fc-1, dStumps,val_t);

        /*cout<<"tpr is "<<tpr<<endl;
        cout<<"tnr is "<<tnr<<endl;
        cout<<"ppv is "<<ppv<<endl;
        cout<<"npv is "<<npv<<endl;
        cout<<"fpr is "<<fpr<<endl;
        cout<<"fnr is "<<fnr<<endl;
        cout<<"fdr is "<<fdr<<endl;
        cout<<"f1 is "<<f1<<endl<<endl;*/

        atpr+=tpr;
        atnr+=tnr;
        appv+=ppv;
        anpv+=npv;
        afpr+=fpr;
        afnr+=fnr;
        afdr+=fdr;
        af1+=f1;
        aacc+=acc;
        //cout<<"acc is "<<acc<<" and aac is "<<aacc<<endl;

    }
    atpr/=kfold;
    atnr/=kfold;
    appv/=kfold;
    anpv/=kfold;
    afpr/=kfold;
    afnr/=kfold;
    afdr/=kfold;
    af1/=kfold;
    aacc/=kfold;

    cout<<"average acc is "<<aacc<<endl;
    /*cout<<"average tpr is "<<atpr<<endl;
    cout<<"average tnr is "<<atnr<<endl;
    cout<<"average ppv is "<<appv<<endl;
    cout<<"average npv is "<<anpv<<endl;
    cout<<"average fpr is "<<afpr<<endl;
    cout<<"average fnr is "<<afnr<<endl;
    cout<<"average fdr is "<<afdr<<endl;
    cout<<"average f1 is "<<af1<<endl<<endl;*/
    cout<<endl;
}

void booster(int lc, int fc, int lcc)
{
    cout<<"5 fold cross validation"<<endl;
    k_fold_cv(5, lc, fc, lcc, 30);
    avgb+=aacc;
    cout<<"10 fold cross validation"<<endl;
    k_fold_cv(10, lc, fc, lcc, 30);
    avgb+=aacc;
    cout<<"20 fold cross validation"<<endl;
    k_fold_cv(20, lc, fc, lcc, 30);
    avgb+=aacc;
    cout<<"leave-one-out cross validation"<<endl;
    k_fold_cv(lc, lc, fc, lcc, 30);
    avgb+=aacc;
    avgb/=4;
}

void decision_stump(int lc, int fc, int lcc)
{
    cout<<"5 fold cross validation"<<endl;
    k_fold_cv(5, lc, fc, lcc, 1);
    avgd+=aacc;
    cout<<"10 fold cross validation"<<endl;
    k_fold_cv(10, lc, fc, lcc, 1);
    avgd+=aacc;
    cout<<"20 fold cross validation"<<endl;
    k_fold_cv(20, lc, fc, lcc, 1);
    avgd+=aacc;
    //cout<<"leave-one-out cross validation"<<endl;
    //k_fold_cv(lc, lc, fc, lcc, 1);
    //avgd+=aacc;
    avgd/=3;
}


int main()
{
    // in your case you'll have a file
    ifstream ifiles("Assignment1_data_set.csv");
    //stringstream ifile("User1, 21, 70\nUser2, 25,68");

    string line;
    int fc=0;
    int lc=0;
    while (getline(ifiles, line)) // read the current line
    {
        lc++;

        if(lc==1)
        {
            istringstream iss(line);

            vector<string> tokens;
            string token;
            while (getline(iss, token, ','))
            {
                fc++;
                tokens.push_back(token);
            }
        }
    }
    lc--;
    int lcc=lc;

    booster(lc,fc,lcc);

    decision_stump(lc,fc,lcc);

    cout<<"Average accuracy for booster: "<<avgb<<endl;
    cout<<"Average accuracy for decision stump: "<<avgd<<endl;

}
