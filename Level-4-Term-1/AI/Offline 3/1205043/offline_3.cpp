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

int jobs,machines,time1[50][50],iter[11],make_span[11],iter_sim[11],make_span_sim[11];

int makespan(int* arr)
{
    int cost[50][50];
    for(int i=0; i<jobs; i++)
    {
        for(int j=0; j<machines; j++)
        {
            if(i==0 && j==0)
            {
                cost[arr[i]][j]=time1[arr[i]][j];
            }
            else if (j==0 && i>0)
            {
                cost[arr[i]][j]=cost[arr[i-1]][j]+time1[arr[i]][j];
            }
            else if(j>0 && i==0)
            {
                cost[arr[i]][j]=cost[arr[i]][j-1]+time1[arr[i]][j];
            }
            else
            {
                cost[arr[i]][j]=max(cost[arr[i-1]][j],cost[arr[i]][j-1])+time1[arr[i]][j];
            }
        }
    }
    return cost[arr[jobs-1]][machines-1];
}

void hillclimb(int* current,int ind)
{
    int neigh[50];
    int j,i;
    for( i=0; i<2000; i++)
    {
        for(j=0; j<500; j++)
        {
            for(int k=0; k<jobs; k++)
            {
                neigh[k]=current[k];
            }
            double x = (double)rand()/RAND_MAX;
            if(x<.5)
            {
                int pos1=rand()%jobs;
                int pos2=rand()%jobs;
                if(pos1>pos2)
                {
                    int temp=neigh[pos1];
                    for(int k=0; k<pos1-pos2; k++)
                    {
                        neigh[pos1-k]=neigh[pos1-1-k];
                    }
                    neigh[pos2]=temp;
                }
                else if(pos1<pos2)
                {
                    int temp=neigh[pos1];
                    for(int k=0; k<pos2-pos1; k++)
                    {
                        neigh[pos1+k]=neigh[pos1+1+k];
                    }
                    neigh[pos2]=temp;
                }
            }
            else
            {
                int pos1=rand()%jobs;
                int pos2=rand()%jobs;
                int temp=neigh[pos1];
                neigh[pos1]=neigh[pos2];
                neigh[pos2]=temp;
            }

            if(makespan(neigh)<makespan(current))
            {
                for(int k=0; k<jobs; k++)
                {
                    current[k]=neigh[k];

                }
                break;
            }

        }
        if(j==500)break;
    }

    iter[ind]=i;
    make_span[ind]=makespan(current);
    for(int k=0; k<jobs; k++)
    {
        cout<<current[k]<<" ";
    }
    cout<<endl;

}

void simulated(int* current,int ind)
{
    int neigh[50];
    int j,i;
    for( i=0; i<1000000; i++)
    {

        for(int k=0; k<jobs; k++)
        {
            neigh[k]=current[k];
        }
        double x = (double)rand()/RAND_MAX;
        if(x<.5)
        {
            int pos1=rand()%jobs;
            int pos2=rand()%jobs;
            if(pos1>pos2)
            {
                int temp=neigh[pos1];
                for(int k=0; k<pos1-pos2; k++)
                {
                    neigh[pos1-k]=neigh[pos1-1-k];
                }
                neigh[pos2]=temp;
            }
            else if(pos1<pos2)
            {
                int temp=neigh[pos1];
                for(int k=0; k<pos2-pos1; k++)
                {
                    neigh[pos1+k]=neigh[pos1+1+k];
                }
                neigh[pos2]=temp;
            }
        }
        else
        {
            int pos1=rand()%jobs;
            int pos2=rand()%jobs;
            int temp=neigh[pos1];
            neigh[pos1]=neigh[pos2];
            neigh[pos2]=temp;
        }
        double T=3000.0-.001*i;
        int dif=makespan(current)-makespan(neigh);
        if(dif>0)
        {
            for(int k=0; k<jobs; k++)
            {
                current[k]=neigh[k];

            }
        }
        else
        {
            x = (double)rand()/RAND_MAX;
            double prob=exp(dif*1.0/T);
            if(x<=prob)
            {
                for(int k=0; k<jobs; k++)
                {
                    current[k]=neigh[k];

                }
            }
        }
    }

    iter_sim[ind]=i;
    make_span_sim[ind]=makespan(current);
    for(int k=0; k<jobs; k++)
    {
        cout<<current[k]<<" ";
    }
    cout<<endl;

}


int main()
{

    scanf("%d%d",&jobs,&machines);
    for(int i=0; i<jobs; i++)
    {
        for(int j=0; j<machines; j++)
        {
            int a;
            si(a);
            scanf("%d",&time1[i][a]);
        }
    }
    int sol[50];
    for(int i=0; i<jobs; i++)
    {
        sol[i]=i;
    }

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<i+1; j++)
        {
            random_shuffle(sol,sol+jobs);
        }
        for(int k=0; k<jobs; k++)
        {
            cout<<sol[k]<<" ";
        }
        cout<<endl<<endl;
        hillclimb(sol,i);

    }
    int sum_hill=0;
    for(int i=0; i<10; i++)
    {
        sum_hill+=iter[i];
    }
    int avg_hill=sum_hill/10;

    int sum_mspan_hill=0;
    for(int i=0; i<10; i++)
    {
        sum_mspan_hill+=make_span[i];
    }
    int avg_mspan_hill=sum_mspan_hill/10;
    cout<<"Avg_iteration_hill = "<<avg_hill<<endl;
    cout<<"Avg_makespan_hill = "<<avg_mspan_hill<<endl;
    sort(make_span,make_span+10);
    cout<<"Minimum_makespan_hill = "<<make_span[0]<<endl;


    int sum_sim=0;
    for(int i=0; i<10; i++)
    {
        sum_sim+=iter_sim[i];
    }
    int avg_sim=sum_sim/10;

    int sum_mspan_sim=0;
    for(int i=0; i<10; i++)
    {
        sum_mspan_sim+=make_span_sim[i];
    }
    int avg_mspan_sim=sum_mspan_sim/10;
    cout<<"Avg_iteration_sim = "<<avg_sim<<endl;
    cout<<"Avg_makespan_sim = "<<avg_mspan_sim<<endl;
    sort(make_span_sim,make_span_sim+10);
    cout<<"Minimum_makespan_sim = "<<make_span_sim[0]<<endl;
    return 0;
}

/*
4 3
0 4 1 2 2 1
0 3 1 6 2 2
0 7 1 2 2 3
0 1 1 5 2 8
*/


