#include "bitmap_image.hpp"
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
int s_w,s_h,num_t;
double x_r_l,x_l_l,y_t_l,y_b_l,z_f_l,z_r_l;
double dx,dy,top_y,left_x;


class triangle
{
public:
    double point[4][4];
    double color[4];
    double l_i_p,r_i_p;

    double get_mx_y()
    {
        double y=max(point[0][1],point[1][1]);
        y=max(y,point[2][1]);
        y=min(y,y_t_l);
        return y;
    }

    double get_mn_y()
    {
        double y=min(point[0][1],point[1][1]);
        y=min(y,point[2][1]);
        y=max(y,y_b_l);
        return y;
    }

    void get_intersecting_point(double y)
    {
        double x1,x2,x_l=11111,x_r=-111111;
        for(int i=0; i<3; i++)
        {
            if(point[i][0]<x_l)x_l=point[i][0];
            if(point[i][0]>x_r)x_r=point[i][0];
        }
        //cout<<"x_l: "<<x_l<<" "<<x_r<<endl<<endl;
        int j=0;
        for(int i=0; i<3; i++)
        {
            double x1_=point[i][0];
            double y1_=point[i][1];
            double x2_=point[(i+1)%3][0];
            double y2_=point[(i+1)%3][1];
            double x_=(x1_-x2_);
            double y_=(y1_-y2_);
            double a=y_;
            double b=-x_;
            double c=x_*y1_-x1_*y_;

            double x=-(c+b*y)/a;
            if(x>=x_l && x<=x_r && j==0)
            {
                x1=x;
                j++;
            }
            else if(x>=x_l && x<=x_r && j==1)x2=x;
        }
        l_i_p=min(x1,x2);
        r_i_p=max(x1,x2);
        l_i_p=max(l_i_p,x_l_l);
        r_i_p=min(r_i_p,x_r_l);
    }

    double get_z_value(double x,double y)
    {
        double x1_,x2_,y1_,y2_,z1_,z2_;
        x1_=point[0][0]-point[1][0];
        x2_=point[2][0]-point[1][0];
        y1_=point[0][1]-point[1][1];
        y2_=point[2][1]-point[1][1];
        z1_=point[0][2]-point[1][2];
        z2_=point[2][2]-point[1][2];

        double a=y1_*z2_-z1_*y2_;
        double b=z1_*x2_-x1_*z2_;
        double c=x1_*y2_-y1_*x2_;
        double d=-(a*point[1][0]+b*point[1][1]+c*point[1][2]);

        double z=-(a*x+b*y+d)/c;
        return z;
    }


};
triangle tri[100];

void read_data()
{
    string line;
    ifstream myfile ("H:\\LEVEL-4-TERM-2\\1.LAB_G\\Assignment-3\\TestCases\\2\\config.txt");
    if (myfile.is_open())
    {
        string delimiter = " ";
        string token;
        for(int i=0; i<4; i++)
        {
            if(i==0)
            {
                getline(myfile,line);
                size_t pos = 0;

                int j=0;
                while ((pos = line.find(delimiter)) != string::npos)
                {
                    token = line.substr(0, pos);
                    //cout << token << endl;
                    line.erase(0, pos + delimiter.length());

                    s_w=atof(token.c_str());

                }
                s_h=atof(line.c_str());
            }

            else if(i==1)
            {
                getline(myfile,line);
                x_l_l=atof(line.c_str());
                x_r_l=-x_l_l;
            }

            else if(i==2)
            {
                getline(myfile,line);
                y_b_l=atof(line.c_str());
                y_t_l=-y_b_l;
            }

            if(i==3)
            {
                getline(myfile,line);
                size_t pos = 0;

                while ((pos = line.find(delimiter)) != string::npos)
                {
                    token = line.substr(0, pos);
                    //cout << token << endl;
                    line.erase(0, pos + delimiter.length());

                    z_f_l=atof(token.c_str());

                }
                z_r_l=atof(line.c_str());
            }
            //cout << line <<endl;

        }
        //cout << x_l_l<<" "<<y_t_l<<endl;
        myfile.close();
    }

    else cout << "Unable to open file";


    ifstream myfile1("H:\\LEVEL-4-TERM-2\\1.LAB_G\\Assignment-3\\TestCases\\2\\stage3.txt");
    if (myfile1.is_open())
    {
        //cout<<"k: "<<endl;
        string delimiter = " ";
        string token;
        num_t=0;
        int i=0;
        while(getline(myfile1,line))
        {
            size_t pos = 0;
            int j=0;
            while ((pos = line.find(delimiter)) != string::npos)
            {
                token = line.substr(0, pos);
                //cout << token << endl;
                line.erase(0, pos + delimiter.length());
                tri[num_t].point[i][j]=atof(token.c_str());
                j++;
            }
            //cout << line <<endl;
            tri[num_t].point[i][j]=atof(line.c_str());

            //cout << tri[k].point[i][0]<<" "<<tri[k].point[i][1]<<" "<<tri[k].point[i][2]<<endl;
            //cout << tri[k].point[1][0]<<" "<<tri[k].point[1][1]<<" "<<tri[k].point[1][2]<<endl;
            //cout << tri[k].point[2][0]<<" "<<tri[k].point[2][1]<<" "<<tri[k].point[2][2]<<endl<<endl;
            //cout<<"k: "<<k<<endl;

            i++;
            i=i%3;
            if(i==0)
            {
                for(int l=0; l<3; l++)
                {
                    tri[num_t].color[l]=rand() % 256;
                }
                /*for(int l=0; l<3; l++)
                {
                    cout<<tri[num_t].color[l]<<" ";
                }
                cout<<endl;*/
                num_t++;
                getline(myfile1,line);
            }

        }
        //cout << x_l_l<<" "<<y_t_l<<endl;
        myfile1.close();
    }

    else cout << "Unable to open file";
}

class color
{
public:
    int c[4];
};


void initialize_z_buffer_and_frame_buffer(double **z_buffer,color **clor)
{
    dx=abs(x_r_l-x_l_l)/s_w;
    dy=abs(y_t_l-y_b_l)/s_h;
    top_y=y_t_l-dy/2;
    left_x=x_l_l+dx/2;

    for (int i=0; i<s_h; i++)
        z_buffer[i] = (double *)malloc(s_w * sizeof(double));

    for (int i = 0; i <  s_h; i++)
    {
        for (int j = 0; j < s_w; j++)
        {
            z_buffer[i][j] = z_r_l-z_f_l;
        }
    }

    for (int i=0; i<s_h; i++)
        clor[i] = (color *)malloc(s_w * sizeof(color));

    for (int i = 0; i <  s_h; i++)
    {
        for (int j = 0; j < s_w; j++)
        {
            color clr;
            for(int l=0; l<3; l++)
            {
                clr.c[l]=0;
            }
            clor[i][j] = clr;
        }
    }


}

void apply_procedure(double **z_buffer,color **clor)
{
    freopen ("z_buffer.txt","w",stdout);
    for(int i=0; i<num_t; i++)
    {
        int t_s_l=ceil((top_y-tri[i].get_mx_y())/dy);
        int b_s_l=floor((top_y-tri[i].get_mn_y())/dy);
        //int b_s_l=b;
        //if(b>t_s_l)t_s_l++;

        //cout<<"t_s_l: "<<t_s_l<<" "<<b_s_l<<endl;
        for(int j=t_s_l; j<b_s_l; j++)
        {
            double y=top_y-j*dy;
            tri[i].get_intersecting_point(y);
            int l_s_l=round((tri[i].l_i_p-left_x)/dx);
            int r_s_l=round((tri[i].r_i_p-left_x)/dx);
            //int r_s_l=b1;
            //if(b1>r_s_l)r_s_l++;

            //cout<<"l_i_p: "<<tri[i].l_i_p<<" "<<tri[i].r_i_p<<endl;
            //cout<<"j: "<<j<<" "<<l_s_l<<" "<<r_s_l<<endl<<endl;
            for(int k=l_s_l; k<r_s_l; k++)
            {
                double x=left_x+k*dx;
                double z=tri[i].get_z_value(x,y);
                //cout<<"z: "<<x<<" "<<y<<" "<<z<<endl;
                if(z>=z_f_l && z<=z_r_l)
                {
                    if(z<z_buffer[j][k])
                    {
                        //cout<<"z: "<<z<<endl;
                        z_buffer[j][k]=z;
                        cout<<z<<"\t";
                        color clr;
                        for(int l=0; l<3; l++)
                        {
                            clr.c[l]=tri[i].color[l];
                            //cout<<"color: "<<clr.c[l]<<endl;
                        }
                        clor[j][k] = clr;

                    }
                }
            }
            cout<<endl;

        }
        //cout<<"end"<<endl;
    }
    fclose (stdout);
}

void save(color **clor)
{

    bitmap_image image(s_h,s_w);
    for(int i=0; i<s_h; i++)
    {
        for(int j=0; j<s_w; j++)
        {
            image.set_pixel(j,i,clor[i][j].c[0],clor[i][j].c[1],clor[i][j].c[2]);
            //cout<<"color: "<<clor[i][j].c[0]<<" "<<clor[i][j].c[1]<<" "<<clor[i][j].c[2]<<endl;
        }
    }

    image.save_image("output.bmp");
    image.clear();
    //cout<<"freed image"<<endl;

}

void free_memory(double **z_buffer,color **clor)
{
    for (int i=0; i<s_h; ++i)
    {
        free(z_buffer[i]);
    }
    free(z_buffer);
    //cout<<"freed z_buffer array"<<endl;

    for (int i=0; i<s_h; ++i)
    {
        free(clor[i]);
    }
    free(clor);
    //cout<<"freed color array"<<endl;

}




int main()
{

    read_data();
    double *z_buffer[s_h+10];
    color *clor[s_h+10];
    initialize_z_buffer_and_frame_buffer(z_buffer,clor);
    apply_procedure(z_buffer,clor);
    save(clor);
    free_memory(z_buffer,clor);
    return 0;
}


