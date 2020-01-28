#include<bits/stdc++.h>
#define forl(i,n) for(int i=0;i<(int)n;i++)
#define pb(x) push_back(int x)
#define lld long long int
#define pii pair<int,int>
#define mem(x,y) memset(x,y,sizeof(x))
#define INF 1<<28
#define si(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
#define sc(a) scanf("%ch",&a)
#define print(a) printf("%d\n",a)
using namespace std;

int express[1000][200];
int val,opt,len;
int ps=100;

int evaluate(int ind[])
{
    int sum,flag,temp[200];
    temp[0]=ind[0];
    int j=1;

    for(int i=1; i<len; i++)
    {
        if(ind[i]==13)
        {
            temp[j-1]*=ind[i+1];
            i++;
        }
        else
        {
            temp[j]=ind[i];
            j++;
        }
    }

    sum=temp[0];
    for(int i=1; i<j; i++)
    {
        if(i%2==1)flag=temp[i];
        else
        {
            if(flag==11)sum+=temp[i];
            else if(flag==12)sum-=temp[i];
            //else sum*=ind[i];
        }
    }
    return sum;
}

int fitness(int ind[])
{
    int eval=evaluate(ind);
    return -abs(val-eval);
}

void SWR(int* p)
{
    int pos=rand()%ps;
    int best[200];
    for(int i=0; i<len; i++)
    {
        best[i]=express[pos][i];
    }
    for(int j=1; j<3; j++)
    {
        pos=rand()%ps;
        int next[200];
        for(int i=0; i<len; i++)
        {
            next[i]=express[pos][i];
        }
        if(fitness(next)>fitness(best))
        {
            for(int i=0; i<len; i++)
            {
                best[i]=next[i];
            }
        }
    }
    for(int i=0; i<len; i++)
    {
        p[i]=best[i];
    }

}

void OPC(int* p1,int* p2)
{
    int c=rand()%len;
    for(int i=c; i<len; i++)
    {
        int temp=p1[i];
        p1[i]=p2[i];
        p2[i]=temp;
    }
}

void TPC(int* p1,int* p2)
{
    int c=rand()%len;
    int d=rand()%len;
    if(c>d)
    {
        int t=c;
        c=d;
        d=t;
    }
    for(int i=c; i<=d; i++)
    {
        int temp=p1[i];
        p1[i]=p2[i];
        p2[i]=temp;
    }
}

void mutate(int* p)
{

    double pb=1.0/len*1.0;
    double b=.1;
    for(int i=0; i<len; i++)
    {
        double ran=(rand()%101)*1.0/100,ran1;
        if(pb>=ran)
        {
            //cout<<pb<<" "<<ran<<endl;
            if(i%2==0)
            {
                do
                {
                    int n=rand()%2;
                    if(n==0)n=-1;
                    if((p[i]+n)>9 || (p[i]+n)<1)p[i]=p[i]-n;
                    else p[i]=p[i]+n;
                    ran1=(rand()%101)/100*1.0;
                }
                while(b<ran1);
            }
            else
            {
                int n=rand()%2;
                if(p[i]==11)
                {
                    if(n==0)p[i]=12;
                    else p[i]=13;
                }
                else if(p[i]==12)
                {
                    if(n==0)p[i]=13;
                    else p[i]=11;
                }
                else
                {
                    if(n==0)p[i]=11;
                    else p[i]=12;
                }
            }
        }
    }

}

int main()
{
    while(1)
    {
        si(opt);
        si(val);
        len=2*opt+1;
        for(int i=0; i<ps; i++)
        {
            for(int j=0; j<len; j++)
            {
                int a;
                if(j%2==0)a=rand()%9+1;
                else a=rand()%3+11;
                express[i][j]=a;
            }
        }

        int best[200],loop;

        for(loop=0; loop<10000; loop++)
        {
            for(int i=0; i<len; i++)
            {
                best[i]=express[0][i];
            }

            for(int i=1; i<ps; i++)
            {
                if(fitness(express[i])>fitness(best))
                {
                    for(int j=0; j<len; j++)
                    {
                        best[j]=express[i][j];
                    }
                }
            }
            if(evaluate(best)==val)break;

            int q[1000][200];
            for(int i=0,j=0; i<ps/2; i++,j++)
            {
                int p1[200],p2[200];
                SWR(p1);
                SWR(p2);

                mutate(p1);
                mutate(p2);

                for(int k=0; k<len; k++)
                {
                    q[j][k]=p1[k];
                }
                j++;
                for(int k=0; k<len; k++)
                {
                    q[j][k]=p2[k];
                }

            }
            for(int k=0; k<ps; k++)
            {
                for(int l=0; l<len; l++)
                {
                    express[k][l]=q[k][l];
                }
            }
        }

        cout<<"best fitness: "<<fitness(best)<<endl;
        cout<<"loop count: "<<loop<<endl;
        cout<<"best expression: "<<endl;
        for(int j=0; j<len; j++)
        {
            if(j%2==1)
            {
                if(best[j]==11)cout<<'+';
                else if(best[j]==12)cout<<'-';
                else if(best[j]==13)cout<<'*';
            }
            else cout<<best[j];
        }
        cout<<endl<<endl;
    }
    return 0;
}


