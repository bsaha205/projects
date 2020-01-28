#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <sstream>
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

class matrix
{
public:
    double rows[5][5];
    void set_value(double val[5][5]);
    void printt()
    {
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                cout<< rows[i][j]<<" ";
            }
            cout<<endl;
        }
    }

};

void matrix::set_value(double val[5][5])
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            rows[i][j]=val[i][j];
        }
    }
}

stack<int> push;
stack<matrix> m_stack;
ofstream myfileo("stage1.txt");
ofstream stage2("stage2.txt");
ofstream stage3("stage3.txt");

void print1(double point[4])
{
    matrix ob=m_stack.top();
    double np[4];
    for(int i=0; i<4; i++)
    {
        double val=0.0;
        for(int j=0; j<4; j++)
        {
            val+=ob.rows[i][j]*point[j];
        }
        np[i]=val;
    }

    for(int j=0; j<4; j++)
    {
        cout<<np[j]<<" ";
    }
    cout<<endl;

    for(int j=0; j<3; j++)
    {
        np[j]/=np[3];
    }

    for(int j=0; j<3; j++)
    {
        if(abs(np[j])<.000001)np[j]=0;
        myfileo<<np[j]<<" ";
    }
    myfileo<<endl;

}

void print2(double point[4])
{
    matrix ob=m_stack.top();
    double np[4];
    for(int i=0; i<4; i++)
    {
        double val=0.0;
        for(int j=0; j<4; j++)
        {
            val+=ob.rows[i][j]*point[j];
        }
        np[i]=val;
    }

    for(int j=0; j<4; j++)
    {
        cout<<np[j]<<" ";
    }
    cout<<endl;

    for(int j=0; j<3; j++)
    {
        np[j]/=np[3];
    }

    for(int j=0; j<3; j++)
    {
        if(abs(np[j])<.000001)np[j]=0;
        stage2<<np[j]<<" ";
    }
    stage2<<endl;

}

void print3(double point[4])
{
    matrix ob=m_stack.top();
    double np[4];
    for(int i=0; i<4; i++)
    {
        double val=0.0;
        for(int j=0; j<4; j++)
        {
            val+=ob.rows[i][j]*point[j];
        }
        np[i]=val;
    }

    for(int j=0; j<4; j++)
    {
        cout<<np[j]<<" ";
    }
    cout<<endl;

    for(int j=0; j<3; j++)
    {
        np[j]/=np[3];
    }

    for(int j=0; j<3; j++)
    {
        if(abs(np[j])<.000001)np[j]=0;
        stage3<<np[j]<<" ";
    }
    stage3<<endl;

}


void mat_mul(double mat[4][4])
{
    matrix ob=m_stack.top();
    matrix ob1;

    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            ob1.rows[i][j]=0;
            for(int k = 0; k < 4; ++k)
            {
                ob1.rows[i][j] += ob.rows[i][k] * mat[k][j];
            }
        }
    }

    m_stack.push(ob1);
    cout<<"trans"<<endl;
    ob1.printt();
    cout<<endl;
    //ob.printt();
}

int main()
{
    double rows[5][5];
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(i==j)rows[i][j]=1;
            else rows[i][j]=0;
        }
    }
    matrix ob;
    ob.set_value(rows);
    m_stack.push(ob);

    string line;
    ifstream myfile ("scene.txt");
    if (myfile.is_open())
    {
        while ( getline(myfile,line) )
        {
            //cout << line << '\n';

            if(line.compare("triangle")==0)
            {
                for(int i=0; i<3; i++)
                {
                    double point[4];
                    getline(myfile,line);
                    string delimiter = " ";

                    size_t pos = 0;
                    string token;
                    int j=0;
                    while ((pos = line.find(delimiter)) != string::npos)
                    {
                        token = line.substr(0, pos);
                        //cout << token << endl;
                        line.erase(0, pos + delimiter.length());
                        point[j]=atof(token.c_str());
                        j++;
                    }
                    //cout << line <<endl;
                    point[j]=atof(line.c_str());
                    point[j+1]=1.0;
                    print1(point);
                }
                myfileo << endl;
                cout<<endl;
            }

            else if(line.compare("translate")==0)
            {
                getline(myfile,line);
                double point[4];
                //cout << line << '\n';
                string delimiter = " ";

                size_t pos = 0;
                string token;
                int j=0;
                while ((pos = line.find(delimiter)) != string::npos)
                {
                    token = line.substr(0, pos);
                    //cout << token << endl;
                    line.erase(0, pos + delimiter.length());
                    point[j]=atof(token.c_str());
                    j++;
                }
                //cout << line <<endl;
                point[j]=atof(line.c_str());
                point[j+1]=1.0;

                /*for(int j=0; j<4; j++)
                {
                    cout<<point[j]<<" ";
                }
                cout<<endl;*/

                double mat[4][4];
                for(int i=0; i<4; i++)
                {
                    for(int j=0; j<4; j++)
                    {
                        if(i==j)mat[i][j]=1;
                        else if(j==3)mat[i][j]=point[i];
                        else mat[i][j]=0;
                    }
                }

                /*for(int i=0; i<4; i++)
                {
                    for(int j=0; j<4; j++)
                    {
                        cout<<mat[i][j]<<" ";
                    }
                    cout<<endl;
                }*/

                mat_mul(mat);
            }

            else if(line.compare("scale")==0)
            {
                getline(myfile,line);
                double point[4];
                string delimiter = " ";

                size_t pos = 0;
                string token;
                int j=0;
                while ((pos = line.find(delimiter)) != string::npos)
                {
                    token = line.substr(0, pos);
                    line.erase(0, pos + delimiter.length());
                    point[j]=atof(token.c_str());
                    j++;
                }
                point[j]=atof(line.c_str());
                point[j+1]=1.0;

                double mat[4][4];
                for(int i=0; i<4; i++)
                {
                    for(int j=0; j<4; j++)
                    {
                        if(i==j)mat[i][j]=point[i];
                        else mat[i][j]=0;
                    }
                }
                mat_mul(mat);
            }

            else if(line.compare("rotate")==0)
            {
                getline(myfile,line);
                double point[4];
                string delimiter = " ";

                size_t pos = 0;
                string token;
                int j=0;
                while ((pos = line.find(delimiter)) != string::npos)
                {
                    token = line.substr(0, pos);
                    line.erase(0, pos + delimiter.length());
                    point[j]=atof(token.c_str());
                    j++;
                }
                point[j]=atof(line.c_str());
                point[j+1]=1.0;

                double c[4][4];
                double pi=acos(-1);
                double theta=point[0]*pi/180;
                double val_c=sqrt(point[1]*point[1]+point[2]*point[2]+point[3]*point[3]);
                double ax=point[1]/val_c;
                double ay=point[2]/val_c;
                double az=point[3]/val_c;

                c[0][0]=cos(theta)+(1-cos(theta))*ax*ax;
                c[0][1]=(1-cos(theta))*ax*ay + az*sin(theta);
                c[0][2]=(1-cos(theta))*ax*az - ay*sin(theta);

                c[1][0]=(1-cos(theta))*ax*ay - az*sin(theta);
                c[1][1]=cos(theta)+(1-cos(theta))*ay*ay;
                c[1][2]=(1-cos(theta))*ay*az + ax*sin(theta);

                c[2][0]=(1-cos(theta))*az*ay + ay*sin(theta);
                c[2][1]=(1-cos(theta))*az*ay - ax*sin(theta);
                c[2][2]=cos(theta)+(1-cos(theta))*az*az;

                double mat[4][4];
                for(int i=0; i<4; i++)
                {
                    for(int j=0; j<4; j++)
                    {
                        if(j==3 || i==3)mat[i][j]=0;
                        else mat[i][j]=c[j][i];
                    }
                }
                mat[3][3]=1;
                mat_mul(mat);
            }

            else if(line.compare("push")==0)
            {
                int len=m_stack.size();
                push.push(len);
                cout<<"push value_push= "<<push.top()<<endl;
                cout<<"len_push= "<<m_stack.size()<<endl;
                m_stack.top().printt();
            }

            else if(line.compare("pop")==0)
            {
                int len=m_stack.size();
                if(push.size()>0)
                {
                    int be=push.top();
                    push.pop();
                    for(int i=len; i>be; i--)
                    {
                        m_stack.pop();
                    }
                    cout<<"len_pop= "<<m_stack.size()<<endl;
                    m_stack.top().printt();
                }
                if(push.size()>0)cout<<"push value_pop= "<<push.top()<<endl;
            }

            else if(line.compare("end")==0)break;
            //if(push.size()>0)cout<<"push value= "<<push.top()<<endl;
        }
        myfile.close();
    }
    else cout << "Unable to open file";


    ifstream scene1 ("scene.txt");
    if (scene1.is_open())
    {
        cout <<endl<<"In View"<<endl;

        int len=m_stack.size();
        for(int i=len; i>1; i--)
        {
            m_stack.pop();
        }

        double point[4][4];
        for(int i=0; i<3; i++)
        {
            getline(scene1,line);
            string delimiter = " ";

            size_t pos = 0;
            string token;
            int j=0;
            while ((pos = line.find(delimiter)) != string::npos)
            {
                token = line.substr(0, pos);
                //cout << token << endl;
                line.erase(0, pos + delimiter.length());
                point[i][j]=atof(token.c_str());
                j++;
            }
            //cout << line <<endl;
            point[i][j]=atof(line.c_str());
        }

        /*for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                cout<<point[i][j]<<" ";
            }
            cout<<endl;
        }
        */

    double l[4],r[4],u[4];
    for(int i=0; i<3; i++)
    {
        l[i]=point[1][i]-point[0][i];
    }
    double val=sqrt(l[0]*l[0]+l[1]*l[1]+l[2]*l[2]);
    for(int i=0; i<3; i++)
    {
        l[i]/=val;
    }

    r[0]=l[1]*point[2][2]-l[2]*point[2][1];
    r[1]=l[2]*point[2][0]-l[0]*point[2][2];
    r[2]=l[0]*point[2][1]-l[1]*point[2][0];
    val=sqrt(r[0]*r[0]+r[1]*r[1]+r[2]*r[2]);
    for(int i=0; i<3; i++)
    {
        r[i]/=val;
    }

    u[0]=r[1]*l[2]-r[2]*l[1];
    u[1]=r[2]*l[0]-r[0]*l[2];
    u[2]=r[0]*l[1]-r[1]*l[0];

    double mat[4][4];
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(j==3 || i==3)mat[i][j]=0;
            else if(i==0)mat[i][j]=r[j];
            else if(i==1)mat[i][j]=u[j];
            else if(i==2)mat[i][j]=-l[j];
        }
    }
    mat[3][3]=1;
    mat_mul(mat);

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(i==j)mat[i][j]=1;
            else if(j==3)mat[i][j]=-point[0][i];
            else mat[i][j]=0;
        }
    }
    mat_mul(mat);
    scene1.close();

    ifstream stage1 ("stage1.txt");
    if (stage1.is_open())
    {
        int k=0;
        while ( getline(stage1,line) )
        {
            k++;
            if(k%4!=0)
            {
                cout << "line: "<<line <<endl;
                double point[4];
                string delimiter = " ";

                size_t pos = 0;
                string token;
                int j=0;
                while ((pos = line.find(delimiter)) != string::npos)
                {
                    token = line.substr(0, pos);
                    //cout << token << endl;
                    line.erase(0, pos + delimiter.length());
                    point[j]=atof(token.c_str());
                    j++;
                }
                point[j]=atof(line.c_str());
                point[3]=1;
                cout<<"point\n";
                for(int j=0; j<4; j++)
                {
                    cout<<point[j]<<" ";
                }
                cout<<endl;

                print2(point);
                //stage2 << endl;
            }
            else
            {
                stage2 << endl;
            }

        }
    }
    stage1.close();
    }
    else cout << "Unable to open file";


    ifstream scene2 ("scene.txt");
    if (scene2.is_open())
    {
    cout <<endl<<"In Perspective"<<endl;

    int len=m_stack.size();
    for(int i=len; i>1; i--)
    {
        m_stack.pop();
    }

    double point[4];
    for(int i=0; i<3; i++)
    {
        getline(scene2,line);
    }

    getline(scene2,line);
    string delimiter = " ";

    size_t pos = 0;
    string token;
    int j=0;
    while ((pos = line.find(delimiter)) != string::npos)
    {
        token = line.substr(0, pos);
        //cout << token << endl;
        line.erase(0, pos + delimiter.length());
        point[j]=atof(token.c_str());
        j++;
    }
    //cout << line <<endl;
    point[j]=atof(line.c_str());
    /*for(int j=0; j<4; j++)
    {
        cout<<point[j]<<" ";
    }
    cout<<endl;
    */

    double pi=acos(-1);
    double fovy=point[0];
    double near=point[2];
    double far=point[3];
    double fovx=fovy*point[1];
    double t=near*tan(fovy*pi/360);
    double r=near*tan(fovx*pi/360);
    cout<<"r= "<<r<<endl;
    //matrix ob=m_stack.top();
    //ob.printt();

    double mat[4][4];
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(i==j && i==0)mat[i][j]=near/r;
            else if(i==j && i==1)mat[i][j]=near/t;
            else if(i==j && i==2)mat[i][j]=-(far+near)/(far-near);
            else if(i==3 && j==2)mat[i][j]=-1;
            else if(i==2 && j==3)mat[i][j]=-(2*far*near)/(far-near);
            else mat[i][j]=0;
        }
    }
    //mat[3][3]=1;
    mat_mul(mat);
    scene2.close();

    ifstream stage2 ("stage2.txt");
    if (stage2.is_open())
    {
        int k=0;
        while ( getline(stage2,line) )
        {
            k++;
            if(k%4!=0)
            {
                cout << "line: "<<line <<endl;
                double point[4];
                string delimiter = " ";

                size_t pos = 0;
                string token;
                int j=0;
                while ((pos = line.find(delimiter)) != string::npos)
                {
                    token = line.substr(0, pos);
                    //cout << token << endl;
                    line.erase(0, pos + delimiter.length());
                    point[j]=atof(token.c_str());
                    j++;
                }
                point[j]=atof(line.c_str());
                point[3]=1;
                cout<<"point\n";
                for(int j=0; j<4; j++)
                {
                    cout<<point[j]<<" ";
                }
                cout<<endl;

                print3(point);
                //stage2 << endl;
            }
            else
            {
                stage3 << endl;
            }

        }
    }
    stage2.close();

    }
    else cout << "Unable to open file";
    return 0;
}



