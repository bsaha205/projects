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
int sz_global,dev;

struct node
{
    int num[20],f_score,g_score;
    node(int a[],int b,int c)
    {

        for(int i=0; i<sz_global; i++)
        {
            num[i]=a[i];
        }
        g_score=b;
        f_score=c;
    }
    node()
    {
        for(int i=0; i<20; i++)
        {
            num[i]=0;
        }
        g_score=INF;
        f_score=INF;
    }
    node(int a[])
    {
        for(int i=0; i<sz_global; i++)
        {
            num[i]=a[i];
        }
        g_score=INF;
        f_score=INF;
    }
    bool operator < ( const node& p ) const
    {
        for(int i=0; i<sz_global; i++)
        {
            if(num[i]==p.num[i])continue;
            return num[i]>p.num[i];
        }

    }
};

vector<node>closed_set;
vector<node>open_set;
map<node,node>came_from;

int heuristic1(int *s,int *g)
{

    dev=3;

    if(sz_global>9)
    {
        dev=4;
    }
    int dist=0,rs[20],cs[20],rg[20],cg[20];
    for(int i=1; i<sz_global; i++)
    {
        int indx,r1,r2,c1,c2;
        for(int j=0; j<sz_global; j++)
        {
            if(s[j]==i)
            {
                indx=j+1;
                break;
            }
        }
        r1=(indx/dev);
        double r=(indx*1.0/dev);
        //cout<<"r= "<<r<<endl;
        if(r1<r)r1++;
        c1=(indx%dev);
        if(c1==0)c1=dev;
        rs[i]=r1;
        cs[i]=c1;

        for(int j=0; j<sz_global; j++)
        {
            if(g[j]==i)
            {
                indx=j+1;
                break;
            }
        }
        r2=(indx/dev);
        r=(indx*1.0/dev);
        if(r2<r)r2++;
        c2=(indx%dev);
        if(c2==0)c2=dev;
        rg[i]=r2;
        cg[i]=c2;
        //cout<<r1<<" "<<r2<<" "<<c1<<" "<<c2<<endl;
        dist+=(abs(r2-r1)+abs(c2-c1));
        //cout<<dist<<endl;
    }

    for(int i=0; i<dev; i++)
    {
        for(int j=0; j<dev-1; j++)
        {
            int a=s[i*dev+j];
            int r1=rs[a],c1=cs[a],r1_g=rg[a],c1_g=cg[a];
            if(r1==r1_g)
            {
                for(int k=j+1; k<dev; k++)
                {
                    int a=s[i*dev+k];
                    int r2=rs[a],c2=cs[a],r2_g=rg[a],c2_g=cg[a];
                    if(r2==r2_g && c2_g<c1_g)dist+=2;
                }
            }
        }
    }

    for(int i=0; i<dev; i++)
    {
        for(int j=0; j<dev-1; j++)
        {
            int a=s[i+dev*j];
            int r1=rs[a],c1=cs[a],r1_g=rg[a],c1_g=cg[a];
            if(c1==c1_g)
            {
                for(int k=j+1; k<dev; k++)
                {
                    int a=s[i+k*dev];
                    int r2=rs[a],c2=cs[a],r2_g=rg[a],c2_g=cg[a];
                    if(c2==c2_g && r2_g<r1_g)dist+=2;
                }
            }
        }
    }
    return dist;
}

int heuristic2(int *s,int *g)
{
    dev=3;

    if(sz_global>9)
    {
        dev=4;
    }
    int dist=0,rs[20],cs[20],rg[20],cg[20];
    for(int i=1; i<sz_global; i++)
    {
        int indx,r1,r2,c1,c2;
        for(int j=0; j<sz_global; j++)
        {
            if(s[j]==i)
            {
                indx=j+1;
                break;
            }
        }
        r1=(indx/dev);
        double r=(indx*1.0/dev);
        //cout<<"r= "<<r<<endl;
        if(r1<r)r1++;
        c1=(indx%dev);
        if(c1==0)c1=dev;
        rs[i]=r1;
        cs[i]=c1;

        for(int j=0; j<sz_global; j++)
        {
            if(g[j]==i)
            {
                indx=j+1;
                break;
            }
        }
        r2=(indx/dev);
        r=(indx*1.0/dev);
        if(r2<r)r2++;
        c2=(indx%dev);
        if(c2==0)c2=dev;
        rg[i]=r2;
        cg[i]=c2;
        //cout<<r1<<" "<<r2<<" "<<c1<<" "<<c2<<endl;
        dist+=((abs(r2-r1))*(abs(r2-r1))+abs(c2-c1));
        //cout<<dist<<endl;
    }
    /*int indx;
    for(int j=0; j<sz_global; j++)
    {
        if(s[j]==0)
        {
            indx=j+1;
            break;
        }
    }
    int r_space=(indx/dev);
    double r=(indx*1.0/dev);
    if(r_space<r)r_space++;
    int c_space=(indx%dev);
    if(c_space==0)c_space=dev;
    for(int i=1; i<sz_global; i++)
    {
        dist+=(abs(r_space-rs[i])+abs(c_space-cs[i]));
    }
    for(int i=1; i<sz_global; i++)
    {
        dist+=(abs(r_space-rg[i])+abs(c_space-cg[i]));
    }*/
    return dist;

}

int main()
{
    int s[20],g[20];
    si(sz_global);
    sz_global++;
    forl(i,sz_global)
    {
        si(s[i]);
    }
    forl(i,sz_global)
    {
        si(g[i]);
    }

    node start=node(s,0,heuristic1(s,g));
    open_set.push_back(start);
    node current=open_set[0];

    while(!open_set.empty())
    {
        current=open_set[0];
        int low=open_set[0].f_score,ind=0;
        for(int i=1; i<open_set.size(); i++)
        {
            if(open_set[i].f_score<=low)
            {
                low=open_set[i].f_score;
                current=open_set[i];
                ind=i;
            }
        }

        open_set.erase(open_set.begin() +ind);
        closed_set.push_back(current);
        int flag=1;
        for(int i=0; i<sz_global; i++)
        {
            if(current.num[i]!=g[i])
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"YESS!"<<endl;
            break;
        }
        else
        {
            for(int i=0; i<4; i++)
            {
                int neigh[20],indx;
                for(int j=0; j<sz_global; j++)
                {
                    neigh[j]=current.num[j];
                }
                for(int j=0; j<sz_global; j++)
                {
                    if(neigh[j]==0)
                    {
                        indx=j+1;
                        break;
                    }
                }
                int row=(indx/dev);
                double r=(indx*1.0/dev);
                //cout<<"r= "<<r<<endl;
                if(row<r)row++;
                int col=(indx%dev);
                if(col==0)col=dev;
                //cout<<row<<" "<<col<<endl;

                int f=0;
                if(i==0)
                {
                    if(row+1<=dev)
                    {
                        int temp=neigh[dev*(row-1)+col-1];
                        neigh[dev*(row-1)+col-1]=neigh[dev*row+col-1];
                        neigh[dev*row+col-1]=temp;
                        f=1;
                    }

                }
                else if(i==1)
                {
                    if(row-1>=1)
                    {
                        int temp=neigh[dev*(row-1)+col-1];
                        neigh[dev*(row-1)+col-1]=neigh[dev*(row-2)+col-1];
                        neigh[dev*(row-2)+col-1]=temp;
                        f=1;
                    }
                }
                else if(i==2)
                {
                    if(col-1>=1)
                    {
                        int temp=neigh[dev*(row-1)+col-1];
                        neigh[dev*(row-1)+col-1]=neigh[dev*(row-1)+col-2];
                        neigh[dev*(row-1)+col-2]=temp;
                        f=1;
                    }
                }
                else
                {
                    if(col+1<=dev)
                    {
                        int temp=neigh[dev*(row-1)+col-1];
                        neigh[dev*(row-1)+col-1]=neigh[dev*(row-1)+col];
                        neigh[dev*(row-1)+col]=temp;
                        f=1;
                    }
                }
                if(f==1)
                {
                    int flag;
                    for(int j=0; j<closed_set.size(); j++)
                    {
                        flag=1;
                        for(int k=0; k<sz_global; k++)
                        {
                            if(closed_set[j].num[k]!=neigh[k])
                            {
                                flag=0;
                                break;
                            }
                        }
                        if(flag==1)break;
                    }
                    if(flag==0)
                    {

                        int t_g_score=current.g_score+1;
                        node nei=node(neigh);

                        for(int j=0; j<open_set.size(); j++)   //openset_ check
                        {
                            flag=1;
                            for(int k=0; k<sz_global; k++)
                            {
                                if(open_set[j].num[k]!=neigh[k])
                                {
                                    flag=0;
                                    break;
                                }
                            }
                            if(flag==1)
                            {
                                nei=open_set[j];
                                break;
                            }
                        }

                        if(flag==0 || t_g_score<nei.g_score)
                        {
                            came_from[nei]=current;

                            nei.g_score=t_g_score;
                            nei.f_score=nei.g_score+heuristic1(neigh,g);
                            if(flag==0)
                            {
                                //cout<<endl<<i<<endl;
                                open_set.push_back(nei);
                            }
                        }
                    }
                }
            }
        }
    }
    node u=current;
    cout<<"Moves Required :"<<u.g_score<<endl;
    cout<<"Nodes explored :"<<closed_set.size()<<endl;
    cout<<"Steps :"<<endl;
    vector<node>out;

    while(u.g_score!=0)
    {
        out.push_back(u);
        u=came_from[u];
    }
    out.push_back(u);
    reverse(out.begin(),out.end());

    for(int i=0; i<(int)out.size(); i++)
    {
        for(int k=0; k<dev; k++)
        {
            for(int l=0; l<dev; l++)
            {
                cout<<out[i].num[k*dev+l]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }

   // cout<<endl<<heuristic2(s,g)<<endl;
    return 0;
}

//  8 7 2 4 6 3 1 8 0 5 1 2 3 4 5 6 7 8 0
//  8 1 2 0 5 3 4 7 8 6 1 2 3 4 5 6 7 8 0

