#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<bits/stdc++.h>
#include <windows.h>
#include <glut.h>
#include "bitmap_image.hpp"
#define pi (2*acos(0.0))
#define EPSILON 0.000001
using namespace std;

double cameraHeight=0;
double cameraAngle;
int drawgrid;
int drawaxes;
double angle;
double radius,height,var,VIEW_ANGLE=80;
int w_w=500,w_h=500;
int image_width,recursion_level;

struct point
{
    double x,y,z;
} pos;

struct up
{
    double x,y,z;
} u;

struct look
{
    double x,y,z;
} l;

struct right
{
    double x,y,z;
} r;

void drawAxes()
{
    if(drawaxes==1)
    {
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
        {
            glColor3f(1, 0, 0);
            glVertex3f( 100,0,0);
            glVertex3f(-100,0,0);

            glColor3f(0, 1, 0);
            glVertex3f(0,-100,0);
            glVertex3f(0, 100,0);

            glColor3f(0, 0, 1);
            glVertex3f(0,0, 100);
            glVertex3f(0,0,-100);
        }
        glEnd();
    }
}


void drawGrid()
{
    int i;
    if(drawgrid==1)
    {
        glColor3f(0.6, 0.6, 0.6);	//grey
        glBegin(GL_LINES);
        {
            for(i=-8; i<=8; i++)
            {

                if(i==0)
                    continue;	//SKIP the MAIN axes

                //lines parallel to Y-axis
                glVertex3f(i*10, -90, 0);
                glVertex3f(i*10,  90, 0);

                //lines parallel to X-axis
                glVertex3f(-90, i*10, 0);
                glVertex3f( 90, i*10, 0);


            }
        }
        glEnd();
    }
}

void drawSquare(double a)
{
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    {
        glVertex3f( a, a,2);
        glVertex3f( a,-a,2);
        glVertex3f(-a,-a,2);
        glVertex3f(-a, a,2);
    }
    glEnd();
}

class vector3
{
public:
    double x,y,z;
};

vector <vector3> lights;

vector3 sub(vector3 a,vector3 b)
{
    vector3 ans;
    ans.x=a.x-b.x;
    ans.y=a.y-b.y;
    ans.z=a.z-b.z;
    return ans;
}

vector3 cross(vector3 a,vector3 b)
{
    vector3 ans;
    ans.x = a.y*b.z - a.z*b.y;
    ans.y = a.z*b.x - a.x*b.z;
    ans.z = a.x*b.y - a.y*b.x;
    return ans;
}

vector3 add(vector3 a,vector3 b)
{
    vector3 ans;
    ans.x=a.x+b.x;
    ans.y=a.y+b.y;
    ans.z=a.z+b.z;
    return ans;
}

double dist(vector3 a,vector3 b)
{
    double ans;
    ans=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
    return sqrt(ans);
}

vector3 mul(double a,vector3 b)
{
    vector3 ans;
    ans.x=a*b.x;
    ans.y=a*b.y;
    ans.z=a*b.z;
    return ans;
}

double dot(vector3 a,vector3 b)
{
    double ans=a.x*b.x+a.y*b.y+a.z*b.z;
    return ans;
}

vector3 normalize(vector3 a)
{
    double val=sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
    a.x/=val;
    a.y/=val;
    a.z/=val;
    return a;
}


class Ray
{
public:
    vector3 start;
    vector3 dir;

    Ray(vector3 s,vector3 d)
    {
        start=s;
        dir=d;
    }
};


class Object
{
public:
    vector3 r_point,a,b,c;
    double height, width, length;
    double Shine;
    double color[3];
    double co_efficients[4];


    Object()
    {

    }

    virtual void draw()
    {

    }

    void setColor(double c[])
    {
        for(int i=0; i<3; i++)
        {
            color[i]=c[i];
        }
    }

    void setShine(double s)
    {
        Shine=s;
    }

    void setCoEfficients(double co[])
    {
        for(int i=0; i<4; i++)
        {
            co_efficients[i]=co[i];
        }
    }

    virtual double intersect(Ray *r, double current_color[], int level)
    {
        return -1;
    }

    virtual double getIntersectingT(Ray *r)
    {
        return -1;
    }
};

vector<Object*>objects;

class Sphere : public Object
{
public:
    Sphere(vector3 Center,double Radius)
    {
        r_point=Center;
        length=Radius;
    }

    void draw()
    {
        glTranslatef(r_point.x,r_point.y,r_point.z);
        struct point points[100][100];
        int i,j;
        double h,r;
        //generate points
        int stacks=50,slices=50;
        for(i=0; i<=stacks; i++)
        {
            h=length*sin(((double)i/(double)stacks)*(pi/2));
            r=length*cos(((double)i/(double)stacks)*(pi/2));
            for(j=0; j<=slices; j++)
            {
                points[i][j].x=r*cos(((double)j/(double)slices)*2*pi);
                points[i][j].y=r*sin(((double)j/(double)slices)*2*pi);
                points[i][j].z=h;
            }
        }
        //draw quads using generated points
        for(i=0; i<stacks; i++)
        {
            //glColor3f((double)i/(double)stacks,(double)i/(double)stacks,(double)i/(double)stacks);
            for(j=0; j<slices; j++)
            {
                glBegin(GL_QUADS);
                {
                    //upper hemisphere
                    glVertex3f(points[i][j].x,points[i][j].y,points[i][j].z);
                    glVertex3f(points[i][j+1].x,points[i][j+1].y,points[i][j+1].z);
                    glVertex3f(points[i+1][j+1].x,points[i+1][j+1].y,points[i+1][j+1].z);
                    glVertex3f(points[i+1][j].x,points[i+1][j].y,points[i+1][j].z);
                    //lower hemisphere
                    glVertex3f(points[i][j].x,points[i][j].y,-points[i][j].z);
                    glVertex3f(points[i][j+1].x,points[i][j+1].y,-points[i][j+1].z);
                    glVertex3f(points[i+1][j+1].x,points[i+1][j+1].y,-points[i+1][j+1].z);
                    glVertex3f(points[i+1][j].x,points[i+1][j].y,-points[i+1][j].z);
                }
                glEnd();
            }
        }
        glTranslatef(-r_point.x,-r_point.y,-r_point.z);
    }

    double getIntersectingT(Ray *r)
    {
        double a=1;
        vector3 o_c=sub(r->start,r_point);
        double b=2*(r->dir.x*o_c.x + r->dir.y*o_c.y +r->dir.z*o_c.z);
        double c=o_c.x*o_c.x + o_c.y*o_c.y + o_c.z*o_c.z -length*length;

        //cout<<"b: "<<b<<" c: "<<c<<endl;
        double d=b*b-4*a*c;

        //cout<<"d: "<<d<<endl;
        if(d<0)return -1;
        else
        {
            d=sqrt(d);
            double t1=-(b+d)/(2*a);
            double t2=(-b+d)/(2*a);

            return min(t1,t2);
        }
    }

    double intersect(Ray *r, double current_color[], int level)
    {
        double t= getIntersectingT(r);
        if(t<=0)return -1;
        if(level==0)return t;

        vector3 intersectionPoint = add(r->start,mul(t,r->dir));
        //cout<<co_efficients[0]<<endl;
        for(int i=0; i<3; i++)
        {
            current_color[i]=color[i]*co_efficients[0];
        }

        vector3 normal=sub(intersectionPoint,r_point);
        normal=normalize(normal);
        double mid=dot(r->dir,normal);
        mid*=2;
        vector3 reflection= sub(r->dir,mul(mid,normal));
        reflection=normalize(reflection);

        for(int i=0; i<lights.size(); i++)
        {
            vector3 direction= sub(lights[i],intersectionPoint);
            direction=normalize(direction);
            vector3 start= add(intersectionPoint,direction);
            Ray *L=new Ray(start, direction);

            for(int j=0; j<objects.size(); j++)
            {
                //Object *temp=objects[j];
                double t1 =objects[j]->getIntersectingT(L);
                if(t1>0 && t1<dist(lights[i],start))continue;

                mid=dot(L->dir,normal);
                double lambert=max(mid,0.0);

                mid*=2;
                vector3 R=sub(mul(mid,normal),L->dir);
                R=normalize(R);

                vector3 pos1;
                pos1.x=pos.x;
                pos1.y=pos.y;
                pos1.z=pos.z;
                vector3 V=sub(pos1,intersectionPoint);
                V=normalize(V);
                //V=mul(-1,V);

                double phong=max(pow(dot(R,V),objects[j]->Shine),0.0);

                for(int k=0; k<3; k++)
                {
                    current_color[k]+=lambert*color[k]*co_efficients[1];
                    current_color[k]+=pow(phong,Shine)*color[k]*co_efficients[2];
                }

            }
        }

        double dummyColorAt[3]= {0,0,0};
        double  reflected_color[3]= {0,0,0};
        if(level<recursion_level)
        {
            vector3 start=add(intersectionPoint,reflection);
            Ray *reflectionRay=new Ray(start, reflection);

            int nearest=-1;
            double t_min=100000000;
            for(int k=0; k<objects.size(); k++)
            {
                //temp=objects[k];
                double t1 =objects[k]->intersect(reflectionRay, dummyColorAt, 0);
                //cout<<"t: "<<t<<" k: "<<k<<endl;
                if(t1<=0)continue;

                if(t1<t_min)
                {
                    t_min=t1;
                    nearest=k;
                }
            }

            //cout<<"n: "<<nearest<<endl;
            if(nearest!=-1)
            {
                //temp=objects[nearest];
                double t1 =objects[nearest]->intersect(reflectionRay, reflected_color,level+1);
                for(int k=0; k<3; k++)
                {
                    current_color[k]+=reflected_color[k]*co_efficients[3];
                }

            }
        }

        for(int k=0; k<3; k++)
        {
            if(current_color[k]>1)current_color[k]=1;
        }

        return t;


    }
};

class Floor : public Object
{
public:
    Floor(int f_w,int t_w)
    {
        r_point.x=-f_w*1.0/2,r_point.y=-f_w*1.0/2,r_point.z=0;
        length=t_w;
    }

    void draw()
    {
        int ct=0;
        for(int i=r_point.x; i<=-r_point.x; i+=length)
        {
            for(int j=r_point.y; j<=-r_point.y; j+=length)
            {
                if(ct%2==0)glColor3f(1,1,1);
                else glColor3f(0,0,0);

                glBegin(GL_QUADS);
                {
                    glVertex3f( i, j,0);
                    glVertex3f( i,j+length,0);
                    glVertex3f(i+length,j+length,0);
                    glVertex3f(i+length,j,0);
                }
                glEnd();
                ct++;
            }
        }
    }

    double getIntersectingT(Ray *r)
    {
        double t=-r->start.z/r->dir.z;
        if(t<0)return -1;
        else return t;
    }

    double intersect(Ray *r, double current_color[], int level)
    {
        double t= getIntersectingT(r);
        if(t<=0)return -1;
        if(level==0)return t;

        vector3 intersectionPoint = add(r->start,mul(t,r->dir));

        int row=floor((intersectionPoint.x-r_point.x)/length);
        int col=floor((intersectionPoint.y-r_point.y)/length);
        row%=2;
        col%=2;
        if(row==col)
        {
            for(int k=0; k<3; k++)
            {
                color[k]=1;
            }
        }
        else
        {
            for(int k=0; k<3; k++)
            {
                color[k]=0;
            }
        }

        for(int i=0; i<3; i++)
        {
            current_color[i]=color[i]*co_efficients[0];
        }

        vector3 normal;
        normal.x=0;
        normal.y=0;
        normal.z=1;
        //normal=normalize(normal);
        double mid=dot(r->dir,normal);
        mid*=2;
        vector3 reflection= sub(r->dir,mul(mid,normal));
        reflection=normalize(reflection);

        for(int i=0; i<lights.size(); i++)
        {
            vector3 direction= sub(lights[i],intersectionPoint);
            direction=normalize(direction);
            vector3 start= add(intersectionPoint,direction);
            Ray *L=new Ray(start, direction);

            mid=dot(L->dir,normal);
            double lambert=max(mid,0.0);

            mid*=2;
            vector3 R=sub(mul(mid,normal),L->dir);
            R=normalize(R);

            vector3 pos1;
            pos1.x=pos.x;
            pos1.y=pos.y;
            pos1.z=pos.z;
            vector3 V=sub(pos1,intersectionPoint);
            V=normalize(V);
            //V=mul(-1,V);

            double phong=max(pow(dot(R,V),Shine),0.0);

            for(int k=0; k<3; k++)
            {
                current_color[k]+=lambert*color[k]*co_efficients[1];
                current_color[k]+=pow(phong,Shine)*color[k]*co_efficients[2];
            }


        }

        double dummyColorAt[3]= {0,0,0};
        double  reflected_color[3]= {0,0,0};
        if(level<recursion_level)
        {
            vector3 start=add(intersectionPoint,reflection);
            Ray *reflectionRay=new Ray(start, reflection);

            int nearest=-1;
            double t_min=100000000;
            for(int k=0; k<objects.size(); k++)
            {
                //temp=objects[k];
                double t1 =objects[k]->intersect(reflectionRay, dummyColorAt, 0);
                //cout<<"t: "<<t<<" k: "<<k<<endl;
                if(t1<=0)continue;

                if(t1<t_min)
                {
                    t_min=t1;
                    nearest=k;
                }
            }

            //cout<<"n: "<<nearest<<endl;
            if(nearest!=-1)
            {
                //temp=objects[nearest];
                double t1 =objects[nearest]->intersect(reflectionRay, reflected_color,level+1);
                for(int k=0; k<3; k++)
                {
                    current_color[k]+=reflected_color[k]*co_efficients[3];
                }

            }
        }

        for(int k=0; k<3; k++)
        {
            if(current_color[k]>1)current_color[k]=1;
        }

        return t;


    }
};

class Triangle : public Object
{
public:
    Triangle(vector3 a1,vector3 b1,vector3 c1)
    {
        a=a1;
        b=b1;
        c=c1;
    }

    void draw()
    {
        glBegin(GL_TRIANGLES);
        {
            glVertex3f( a.x, a.y,a.z);
            glVertex3f( b.x,b.y,b.z);
            glVertex3f(c.x,c.y,c.z);
            //glVertex3f(-a, a,2);
        }
        glEnd();
    }

    double getIntersectingT(Ray *r)
    {
        vector3 e1, e2;  //Edge1, Edge2
        vector3 P, Q, T;
        float det, inv_det, u, v;
        float t;

        e1=sub(b,a);
        e2=sub(c,a);
        P=cross(r->dir,e2);
        det = dot(e1, P);
        if(det > -EPSILON && det < EPSILON) return -1;
        inv_det = 1.f / det;

        T=sub(r->start,a);
        u = dot(T, P) * inv_det;
        if(u < 0.f || u > 1.f) return -1;

        Q=cross(T,e1);
        v = dot(r->dir, Q) * inv_det;
        if(v < 0.f || u + v  > 1.f) return -1;

        t = dot(e2, Q) * inv_det;
        if(t > EPSILON)   //ray intersection
        {
            return t;
        }
        return -1;

    }

    double intersect(Ray *r, double current_color[], int level)
    {
        double t= getIntersectingT(r);
        if(t<=0)return -1;
        if(level==0)return t;

        vector3 intersectionPoint = add(r->start,mul(t,r->dir));
        //cout<<co_efficients[0]<<endl;
        for(int i=0; i<3; i++)
        {
            current_color[i]=color[i]*co_efficients[0];
        }

        vector3 b_a=sub(b,a);
        vector3 c_a=sub(c,a);
        vector3 normal=cross(b_a,c_a);
        normal=normalize(normal);

        double mid=dot(r->dir,normal);
        mid*=2;
        vector3 reflection= sub(r->dir,mul(mid,normal));
        reflection=normalize(reflection);

        for(int i=0; i<lights.size(); i++)
        {
            vector3 direction= sub(lights[i],intersectionPoint);
            direction=normalize(direction);
            vector3 start= add(intersectionPoint,direction);
            Ray *L=new Ray(start, direction);

            for(int j=0; j<objects.size(); j++)
            {
                //Object *temp=objects[j];
                double t1 =objects[j]->getIntersectingT(L);
                if(t1>0 && t1<dist(lights[i],start))continue;

                mid=dot(L->dir,normal);
                double lambert=max(mid,0.0);

                mid*=2;
                vector3 R=sub(mul(mid,normal),L->dir);
                R=normalize(R);

                vector3 pos1;
                pos1.x=pos.x;
                pos1.y=pos.y;
                pos1.z=pos.z;
                vector3 V=sub(pos1,intersectionPoint);
                V=normalize(V);
                //V=mul(-1,V);

                double phong=max(pow(dot(R,V),objects[j]->Shine),0.0);

                for(int k=0; k<3; k++)
                {
                    current_color[k]+=lambert*color[k]*co_efficients[1];
                    current_color[k]+=pow(phong,Shine)*color[k]*co_efficients[2];
                }

            }
        }

        double dummyColorAt[3]= {0,0,0};
        double  reflected_color[3]= {0,0,0};
        if(level<recursion_level)
        {
            vector3 start=add(intersectionPoint,reflection);
            Ray *reflectionRay=new Ray(start, reflection);

            int nearest=-1;
            double t_min=100000000;
            for(int k=0; k<objects.size(); k++)
            {
                //temp=objects[k];
                double t1 =objects[k]->intersect(reflectionRay, dummyColorAt, 0);
                //cout<<"t: "<<t<<" k: "<<k<<endl;
                if(t1<=0)continue;

                if(t1<t_min)
                {
                    t_min=t1;
                    nearest=k;
                }
            }

            //cout<<"n: "<<nearest<<endl;
            if(nearest!=-1)
            {
                //temp=objects[nearest];
                double t1 =objects[nearest]->intersect(reflectionRay, reflected_color,level+1);
                for(int k=0; k<3; k++)
                {
                    current_color[k]+=reflected_color[k]*co_efficients[3];
                }

            }
        }

        for(int k=0; k<3; k++)
        {
            if(current_color[k]>1)current_color[k]=1;
        }

        return t;


    }
};

class General : public Object
{
public:
    double A,B,C,D,E,F,G,H,I,J;
    General(vector3 aa,double l,double w,double hh,double a,double b,double c,double d,double e,double f,double g,double h,double i,double j)
    {
        r_point=aa;
        length=l;
        width=w;
        height=hh;
        A=a;
        B=b;
        C=c;
        D=d;
        E=e;
        F=f;
        G=g;
        H=h;
        I=i;
        J=j;
        //cout<<length<<" "<<width<<" "<<height<<" "<<A<<" "<<B<<" "<<C<< " "<<D<<" "<<E<<" "<<F<<" "<<G<<" "<<H<<" "<<I<<" "<<J<<endl;
    }

    double getIntersectingT(Ray *r)
    {
        double a=A*r->dir.x*r->dir.x + B*r->dir.y*r->dir.y + C*r->dir.z*r->dir.z + D*r->dir.x*r->dir.y + E*r->dir.y*r->dir.z + F*r->dir.z*r->dir.x;
        double b=2*A*r->start.x*r->dir.x + 2*B*r->start.y*r->dir.y + 2*C*r->start.z*r->dir.z + D*r->start.x*r->dir.y + D*r->start.y*r->dir.x + E*r->start.y*r->dir.z + E*r->start.z*r->dir.y + F*r->start.z*r->dir.x + F*r->start.x*r->dir.z + G*r->dir.x + H*r->dir.y + I*r->dir.z;
        double c=A*r->start.x*r->start.x + B*r->start.y*r->start.y + C*r->start.z*r->start.z + D*r->start.x*r->start.y + E*r->start.y*r->start.z + F*r->start.z*r->start.x + G*r->start.x + H*r->start.y + I*r->start.z + J;

        double d=b*b-4*a*c;
        //cout<<"a: "<<a<<" b: "<<b<<" c: "<<c<<" d: "<<d<<endl;
        if(d<0)return -1;
        else
        {
            //cout<<"a: "<<a<<" b: "<<b<<" c: "<<c<<" d: "<<d<<endl;
            d=sqrt(d);
            double t1=(-b+d)/(2*a);
            double t2=(-b-d)/(2*a);
            vector3 intersectionPoint;

            if(t1>0)
            {
                intersectionPoint = add(r->start,mul(t1,r->dir));
                if((length>0 && intersectionPoint.x>=r_point.x && intersectionPoint.x<=(r_point.x +length)) || (width>0 && intersectionPoint.y>=r_point.y && intersectionPoint.y<=(r_point.y +width)) || (height>0 && intersectionPoint.z>=r_point.z && intersectionPoint.z<=(r_point.z +height)))
                {
                    //cout<<"t1:"<<t1<<endl;
                    if(t2>0)
                    {
                        intersectionPoint = add(r->start,mul(t2,r->dir));
                        if((length>0 && intersectionPoint.x>=r_point.x && intersectionPoint.x<=(r_point.x +length)) || (width>0 && intersectionPoint.y>=r_point.y && intersectionPoint.y<=(r_point.y +width))|| (height>0 && intersectionPoint.z>=r_point.z && intersectionPoint.z<=(r_point.z +height)))
                        {
                            //cout<<"t1:"<<t1<<" t2:"<<t2<<endl;
                            return min(t1,t2);
                        }
                        else return t1;
                    }
                }

                else if(t2>0)
                {
                    intersectionPoint = add(r->start,mul(t2,r->dir));
                    if((length>0 && intersectionPoint.x>=r_point.x && intersectionPoint.x<=(r_point.x +length)) || (width>0 && intersectionPoint.y>=r_point.y && intersectionPoint.y<=(r_point.y +width))|| (height>0 && intersectionPoint.z>=r_point.z && intersectionPoint.z<=(r_point.z +height)))
                    {
                        //cout<<"t1:"<<t1<<" t2:"<<t2<<endl;
                        return t2;
                    }
                    else return -1;
                }
            }

            else
            {
                if(t2>0)
                {
                    intersectionPoint = add(r->start,mul(t2,r->dir));
                    if((length>0 && intersectionPoint.x>=r_point.x && intersectionPoint.x<=(r_point.x +length)) ||( width>0 && intersectionPoint.y>=r_point.y && intersectionPoint.y<=(r_point.y +width))||(height>0 && intersectionPoint.z>=r_point.z && intersectionPoint.z<=(r_point.z +height)))
                    {
                        return t2;
                    }
                }
            }

            return -1;
        }

    }

    double intersect(Ray *r, double current_color[], int level)
    {
        double t= getIntersectingT(r);

        if(t<=0)return -1;
        //cout<<t<<endl;
        if(level==0)return t;

        vector3 intersectionPoint = add(r->start,mul(t,r->dir));
        //cout<<co_efficients[0]<<endl;
        for(int i=0; i<3; i++)
        {
            current_color[i]=color[i]*co_efficients[0];
            //cout<<current_color[i]<<endl;
        }

        vector3 normal;
        normal.x=2*A*intersectionPoint.x + D*intersectionPoint.y + F*intersectionPoint.z +G;
        normal.y=2*B*intersectionPoint.y + D*intersectionPoint.x + E*intersectionPoint.z +H;
        normal.z=2*C*intersectionPoint.z + E*intersectionPoint.y + F*intersectionPoint.x +I;
        normal=normalize(normal);

        double mid=dot(r->dir,normal);
        mid*=2;
        vector3 reflection= sub(r->dir,mul(mid,normal));
        reflection=normalize(reflection);

        for(int i=0; i<lights.size(); i++)
        {
            vector3 direction= sub(lights[i],intersectionPoint);
            direction=normalize(direction);
            vector3 start= add(intersectionPoint,direction);
            Ray *L=new Ray(start, direction);

            for(int j=0; j<objects.size(); j++)
            {
                //Object *temp=objects[j];
                double t1 =objects[j]->getIntersectingT(L);
                if(t1>0 && t1<dist(lights[i],start))continue;

                mid=dot(L->dir,normal);
                double lambert=max(mid,0.0);

                mid*=2;
                vector3 R=sub(mul(mid,normal),L->dir);
                R=normalize(R);

                vector3 pos1;
                pos1.x=pos.x;
                pos1.y=pos.y;
                pos1.z=pos.z;
                vector3 V=sub(pos1,intersectionPoint);
                V=normalize(V);
                //V=mul(-1,V);

                double phong=max(pow(dot(R,V),objects[j]->Shine),0.0);

                for(int k=0; k<3; k++)
                {
                    current_color[k]+=lambert*color[k]*co_efficients[1];
                    current_color[k]+=pow(phong,Shine)*color[k]*co_efficients[2];
                }

            }
        }

        double dummyColorAt[3]= {0,0,0};
        double  reflected_color[3]= {0,0,0};
        if(level<recursion_level)
        {
            vector3 start=add(intersectionPoint,reflection);
            Ray *reflectionRay=new Ray(start, reflection);

            int nearest=-1;
            double t_min=100000000;
            for(int k=0; k<objects.size(); k++)
            {
                //temp=objects[k];
                double t1 =objects[k]->intersect(reflectionRay, dummyColorAt, 0);
                //cout<<"t: "<<t<<" k: "<<k<<endl;
                if(t1<=0)continue;

                if(t1<t_min)
                {
                    t_min=t1;
                    nearest=k;
                }
            }

            //cout<<"n: "<<nearest<<endl;
            if(nearest!=-1)
            {
                //temp=objects[nearest];
                double t1 =objects[nearest]->intersect(reflectionRay, reflected_color,level+1);
                for(int k=0; k<3; k++)
                {
                    current_color[k]+=reflected_color[k]*co_efficients[3];
                }

            }
        }

        for(int k=0; k<3; k++)
        {
            if(current_color[k]>1)current_color[k]=1;
        }

        return t;


    }
};


void capture()
{
    //cout<<"bal1"<<endl;
    bitmap_image image(image_width,image_width);
    for(int i=0; i<image_width; i++)
    {
        for(int j=0; j<image_width; j++)
        {
            image.set_pixel(i,j,0,0,0);
            //cout<<"color: "<<clor[i][j].c[0]<<" "<<clor[i][j].c[1]<<" "<<clor[i][j].c[2]<<endl;
        }
    }


    double plane_distance= (w_h/2*1.0)/tan(VIEW_ANGLE/2.0);

    vector3 topleft;
    topleft.x= pos.x - l.x*plane_distance - r.x*w_w/2.0 + u.x*w_h/2.0;
    topleft.y= pos.y - l.y*plane_distance-r.y*w_w/2.0+u.y*w_h/2.0;
    topleft.z= pos.z - l.z*plane_distance-r.z*w_w/2.0+u.z*w_h/2.0;

    double du=w_w*1.0/image_width;
    double dv=w_h*1.0/image_width;
    //cout<<"du: "<<du<<" "<<dv<<endl;

    Object *temp;
    double dummyColorAt[3]= {0,0,0};
    double ColorAt[3]= {0,0,0};
    //i=image_width/2-10; i<image_width/2+10;
    for(int i=0; i<image_width; i++)
    {
        for(int j=0; j<image_width; j++)
        {
            vector3 corner;
            corner.x=topleft.x+r.x*i*du-u.x*j*dv;
            corner.y=topleft.y+r.y*i*du-u.y*j*dv;
            corner.z=topleft.z+r.z*i*du-u.z*j*dv;
            //cout<<corner.x<<" "<<corner.y<<" "<<corner.z<<endl;

            vector3 dir;
            dir.x=corner.x-pos.x;
            dir.y=corner.y-pos.y;
            dir.z=corner.z-pos.z;

            //cout<<dir.x<<" "<<dir.y<<" "<<dir.z<<endl;
            double val=sqrt(dir.x*dir.x+dir.y*dir.y+dir.z*dir.z);
            dir.x/=val;
            dir.y/=val;
            dir.z/=val;


            vector3 pos1;
            pos1.x=pos.x;
            pos1.y=pos.y;
            pos1.z=pos.z;
            Ray* ray=new Ray(pos1,dir);

            int nearest=-1;
            double t_min=100000000;
            for(int k=0; k<objects.size(); k++)
            {
                temp=objects[k];
                double t =temp->intersect(ray, dummyColorAt, 0);
                //cout<<"t: "<<t<<" k: "<<k<<endl;
                if(t<=0)continue;

                if(t<t_min)
                {
                    t_min=t;
                    nearest=k;
                }
            }

            //cout<<"n: "<<nearest<<endl;
            if(nearest!=-1)
            {
                temp=objects[nearest];
                double t =temp->intersect(ray,ColorAt,1);
                image.set_pixel(i,j,ColorAt[0]*255.0,ColorAt[1]*255.0,ColorAt[2]*255.0);
            }

        }
    }
    cout<<"completed\n";
    image.save_image("output.bmp");
    //image.clear();
}


void loadTestData()
{
    ifstream cin("scene.txt");

    cin >> recursion_level ;
    cin >>image_width;
    int n_o_object,n_o_lights;
    cin >> n_o_object;
    //cout <<"a: "<<recursion_level<<" b: "<<image_width<<" c: "<<n_o_object<<endl;
    Object *temp;
    vector3 v;
    string name;
    double radius,c[3],co[4],s;

    for(int i=0;i<n_o_object;i++)
    {
        cin>>name;
        if(name=="sphere")
        {
            cin>>v.x;
            cin>>v.y;
            cin>>v.z;
            cin>>radius;
            for(int j=0;j<3;j++)
            {
                cin>>c[j];
            }
            for(int j=0;j<4;j++)
            {
                cin>>co[j];
            }
            cin>>s;
            temp=new Sphere(v, radius);
            temp->setColor(c);
            temp->setCoEfficients(co);
            temp->setShine(s);
            objects.push_back(temp);
        }

        else if(name == "triangle")
        {
            vector3 a1,b1,c1;
            cin>>a1.x;
            cin>>a1.y;
            cin>>a1.z;

            cin>>b1.x;
            cin>>b1.y;
            cin>>b1.z;

            cin>>c1.x;
            cin>>c1.y;
            cin>>c1.z;

            for(int j=0;j<3;j++)
            {
                cin>>c[j];
            }
            for(int j=0;j<4;j++)
            {
                cin>>co[j];
            }
            cin>>s;

            temp=new Triangle(a1,b1,c1);
            temp->setColor(c);
            temp->setCoEfficients(co);
            temp->setShine(s);
            objects.push_back(temp);
        }

        else if(name == "general")
        {
            double A,B,C,D,E,F,G,H,I,J,l,w,h;
            cin>>A;
            cin>>B;
            cin>>C;
            cin>>D;
            cin>>E;
            cin>>F;
            cin>>G;
            cin>>H;
            cin>>I;
            cin>>J;

            cin>>v.x;
            cin>>v.y;
            cin>>v.z;

            cin>>l;
            cin>>w;
            cin>>h;

            for(int j=0;j<3;j++)
            {
                cin>>c[j];
            }
            for(int j=0;j<4;j++)
            {
                cin>>co[j];
            }
            cin>>s;

            temp=new General(v,l,w,h,A,B,C,D,E,F,G,H,I,J);
            temp->setColor(c);
            temp->setCoEfficients(co);
            temp->setShine(s);
            objects.push_back(temp);
        }
    }

    cin>>n_o_lights;
    for(int i=0;i<n_o_lights;i++)
    {
        cin>>v.x;
        cin>>v.y;
        cin>>v.z;
        lights.push_back(v);
    }

    temp=new Floor(1000, 20);
    double co3[4]= {0.4,0.2,0.2,0.2};
    temp->setCoEfficients(co3);
    temp->setShine(1);
    objects.push_back(temp);

    /*v.x=0,v.y=0,v.z=10;
    temp=new Sphere(v, 10); // Center(0,0,10), Radius 10
    double c11[3]= {1,0,0};
    temp->setColor(c11);
    double co11[4]= {.4,.2,.2,.2};
    temp->setCoEfficients(co11);
    temp->setShine(1);
    objects.push_back(temp);

    //triangle
    vector3 a1;
    vector3 b1;
    vector3 cc1;
    a1.x=60,a1.y=-10,a1.z=10;
    b1.x=100,b1.y=-10,b1.z=20;
    cc1.x=80,cc1.y=-10,cc1.z=50;
    temp=new Triangle(a1,b1,cc1); // Center(0,0,10), Radius 10
    double c21[3]= {1,0,0};
    temp->setColor(c21);
    double co21[4]= {.4,.2,.2,.2};
    temp->setCoEfficients(co21);
    temp->setShine(1);
    objects.push_back(temp);*/


}

void keyboardListener(unsigned char key, int x,int y)
{
    switch(key)
    {

    case '0':
        capture();
        break;

    case '1':
        r.x = r.x*cos(angle) + l.x*sin(angle);
        r.y = r.y*cos(angle) + l.y*sin(angle);
        r.z = r.z*cos(angle) + l.z*sin(angle);

        l.x = u.y*r.z - u.z*r.y;
        l.y = u.z*r.x - u.x*r.z;
        l.z = u.x*r.y - u.y*r.x;
        break;

    case '2':
        r.x = r.x*cos(-angle) + l.x*sin(-angle);
        r.y = r.y*cos(-angle) + l.y*sin(-angle);
        r.z = r.z*cos(-angle) + l.z*sin(-angle);

        l.x = u.y*r.z - u.z*r.y;
        l.y = u.z*r.x - u.x*r.z;
        l.z = u.x*r.y - u.y*r.x;
        break;

    case '3':
        l.x = l.x*cos(angle) + u.x*sin(angle);
        l.y = l.y*cos(angle) + u.y*sin(angle);
        l.z = l.z*cos(angle) + u.z*sin(angle);

        u.x = r.y*l.z - r.z*l.y;
        u.y = r.z*l.x - r.x*l.z;
        u.z = r.x*l.y - r.y*l.x;
        break;

    case '4':
        l.x = l.x*cos(-angle) + u.x*sin(-angle);
        l.y = l.y*cos(-angle) + u.y*sin(-angle);
        l.z = l.z*cos(-angle) + u.z*sin(-angle);

        u.x = r.y*l.z - r.z*l.y;
        u.y = r.z*l.x - r.x*l.z;
        u.z = r.x*l.y - r.y*l.x;
        break;

    case '5':
        u.x = u.x*cos(angle) + r.x*sin(angle);
        u.y = u.y*cos(angle) + r.y*sin(angle);
        u.z = u.z*cos(angle) + r.z*sin(angle);

        r.x = l.y*u.z - l.z*u.y;
        r.y = l.z*u.x - l.x*u.z;
        r.z = l.x*u.y - l.y*u.x;
        break;

    case '6':
        u.x = u.x*cos(-angle) + r.x*sin(-angle);
        u.y = u.y*cos(-angle) + r.y*sin(-angle);
        u.z = u.z*cos(-angle) + r.z*sin(-angle);

        r.x = l.y*u.z - l.z*u.y;
        r.y = l.z*u.x - l.x*u.z;
        r.z = l.x*u.y - l.y*u.x;
        break;

    default:
        break;
    }
}


void specialKeyListener(int key, int x,int y)
{
    switch(key)
    {
    case GLUT_KEY_DOWN:		//down arrow key
        pos.x -= var*l.x;
        pos.y -= var*l.y;
        pos.z -= var*l.z;
        break;

    case GLUT_KEY_UP:		// up arrow key
        pos.x += var*l.x;
        pos.y += var*l.y;
        pos.z += var*l.z;
        break;

    case GLUT_KEY_RIGHT:
        pos.x += var*r.x;
        pos.y += var*r.y;
        pos.z += var*r.z;
        break;

    case GLUT_KEY_LEFT:
        pos.x -= var*r.x;
        pos.y -= var*r.y;
        pos.z -= var*r.z;
        break;

    case GLUT_KEY_PAGE_UP:
        pos.x += var*u.x;
        pos.y += var*u.y;
        pos.z += var*u.z;
        break;

    case GLUT_KEY_PAGE_DOWN:
        pos.x -= var*u.x;
        pos.y -= var*u.y;
        pos.z -= var*u.z;
        break;

    case GLUT_KEY_HOME:
        if(height>0)
        {
            radius +=1;
            height -=1;
        }
        break;
    case GLUT_KEY_END:
        if(radius>0)
        {
            radius -=1;
            height +=1;
        }
        break;

    default:
        break;
    }
}



void display()
{

    //clear the display
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,0);	//color black
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /********************
    / set-up camera here
    ********************/
    //load the correct matrix -- MODEL-VIEW matrix
    glMatrixMode(GL_MODELVIEW);

    //initialize the matrix
    glLoadIdentity();

    //now give three info
    //1. where is the camera (viewer)?
    //2. where is the camera looking?
    //3. Which direction is the camera's UP direction?

    //gluLookAt(100,100,100,	0,0,0,	0,0,1);
    gluLookAt(pos.x, pos.y, pos.z, pos.x + l.x, pos.y + l.y, pos.z + l.z, u.x, u.y,u.z);
    //gluLookAt(100+cameraHeight,100,0,	0,0,0,	0,0,1);


    //again select MODEL-VIEW
    glMatrixMode(GL_MODELVIEW);


    /****************************
    / Add your objects from here
    ****************************/
    //add objects

    drawAxes();
    drawGrid();
    Object *temp;
    vector3 v;
    for(int i=0; i<objects.size(); i++)
    {
        temp=objects[i];
        glColor3f(temp->color[0]*255,temp->color[1]*255,temp->color[2]*255);
        temp->draw();
    }

    glColor3f(1,0,0);
    for(int i=0; i<lights.size(); i++)
    {
        v=lights[i];
        glBegin(GL_POINTS);
        {
            glVertex3f(v.x,v.y,v.z);
        }
        glEnd();
    }

    //ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
    glutSwapBuffers();
}


void animate()
{
    //angle+=0.05;
    //codes for any changes in Models, Camera
    glutPostRedisplay();
}

void init()
{
    //codes for initialization
    drawgrid=0;
    drawaxes=1;
    cameraHeight=0.0;
    cameraAngle=1.0;
    angle=1.2*pi/180;
    var=3;

    pos.x=0;
    pos.y=-200;
    pos.z=10;

    u.x=0;
    u.y=0;
    u.z=1;

    l.x= 0;
    l.y =1;
    l.z =0;

    r.x =-1;
    r.y =0;
    r.z =0;

    radius=20;
    height=25;
    //clear the screen
    glClearColor(0,0,0,0);

    /************************
    / set-up projection here
    ************************/
    //load the PROJECTION matrix
    glMatrixMode(GL_PROJECTION);

    //initialize the matrix
    glLoadIdentity();

    //give PERSPECTIVE parameters
    gluPerspective(VIEW_ANGLE,	1,	1,	1000.0);
    //field of view in the Y (vertically)
    //aspect ratio that determines the field of view in the X direction (horizontally)
    //near distance
    //far distance
}



int main(int argc, char **argv)
{

    loadTestData();
    glutInit(&argc,argv);
    glutInitWindowSize(w_w, w_h);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

    glutCreateWindow("My OpenGL Program");

    init();

    glEnable(GL_DEPTH_TEST);	//enable Depth Testing

    glutDisplayFunc(display);	//display callback function
    glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

    glutKeyboardFunc(keyboardListener);
    glutSpecialFunc(specialKeyListener);
    //glutMouseFunc(mouseListener);

    glutMainLoop();		//The main loop of OpenGL

    return 0;
}
