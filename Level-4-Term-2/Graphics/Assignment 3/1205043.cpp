
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
int s_w,s_h;
double x_r_l,x_l_l,y_t_l,y_b_l,z_f_l,z_n_l;


void read_data()
{
    string line;
    ifstream myfile ("H:\\LEVEL-4-TERM-2\\1.LAB_G\\Assignment-3\\TestCases\\1\\config.txt");
    if (myfile.is_open())
    {
        for(int i=0;i<4;i++)
        {
            getline (myfile,line);
            //cout << line << '\n';
            if(i==0)
            {
                s_w=stoi(line[0]);
                s_h=atoi(line[1].c_str());
                cout << s_w<<" "<<s_h << '\n';
            }
        }
        myfile.close();
    }

    else cout << "Unable to open file";
}

int main()
{

    read_data();
    return 0;
}


