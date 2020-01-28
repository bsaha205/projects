#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<bits/stdc++.h>
#include <windows.h>
#include <glut.h>

#define pi (2*acos(0.0))
using namespace std;
double cameraHeight;
double cameraAngle;
int drawgrid;
int drawaxes;
double angle,radius,translate,angle1,tx,ty;
int segments;

struct point
{
    double x,y,z;
};

struct point points[100];
struct point points2[100];


void drawAxes()
{
    if(drawaxes==1)
    {
        glBegin(GL_LINES);
        {
            glColor3f(1, 0, 0);
            glVertex3f( 200,0,0);
            glVertex3f(-200,0,0);

            glColor3f(0, 1, 0);
            glVertex3f(0,-200,0);
            glVertex3f(0, 200,0);

            glColor3f(0, 0, 1);
            glVertex3f(0,0, 200);
            glVertex3f(0,0,-200);
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



void drawCircle(double radius,int segments)
{

    int i;
    glColor3f(0.7,0.7,0.7);
    //generate points
    /*if(flag==1)
    {
        i=i+segments;
    }*/
    for(i=0; i<=segments; i++)
    {
        points[i].x=radius*cos(((double)i/(double)segments)*2*pi);
        points[i].z=radius*sin(((double)i/(double)segments)*2*pi);
    }
    //draw segments using generated points
    for(i=0; i<segments; i++)
    {
        glBegin(GL_LINES);
        {
            glVertex3f(points[i].x,0,points[i].z);
            glVertex3f(points[i+1].x,0,points[i+1].z);
        }
        glEnd();
    }
}



void keyboardListener(unsigned char key, int x,int y)
{
    switch(key)
    {
        case 'w':
            //angle1=0;
            angle += 5;
            //translate += 5*radius/360;
            tx += 25*radius*cos(angle1*pi/180)/360;
            ty +=25*radius*sin(angle1*pi/180)/360;
            break;

        case 's':
            //angle1=0;
            angle -= 5;
            tx -= 25*radius*cos(angle1*pi/180)/360;
            ty -=25*radius*sin(angle1*pi/180)/360;
            break;

        case 'a':
            //angle=0;
            angle1 +=5;
            //translate -= 5*radius/360;
            break;

         case 'd':
             //angle=0;
            angle1 -=5;
            //translate -= 5*radius/360;
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
        cameraHeight -= 3.0;
        break;
    case GLUT_KEY_UP:		// up arrow key
        cameraHeight += 3.0;
        break;

    case GLUT_KEY_RIGHT:
        cameraAngle += 0.03;
        break;
    case GLUT_KEY_LEFT:
        cameraAngle -= 0.03;
        break;

    case GLUT_KEY_PAGE_UP:
        break;
    case GLUT_KEY_PAGE_DOWN:
        break;

    case GLUT_KEY_INSERT:
        break;

    case GLUT_KEY_HOME:
        break;
    case GLUT_KEY_END:
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
    gluLookAt(200*cos(cameraAngle), 200*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
    //gluLookAt(0,0,200,	0,0,0,	0,1,0);


    //again select MODEL-VIEW
    glMatrixMode(GL_MODELVIEW);


    /****************************
    / Add your objects from here
    ****************************/
    //add objects

    drawAxes();
    drawGrid();

    //glColor3f(1,0,0);
    //drawSquare(10);

    //drawSS();

    glTranslatef(tx,ty,0);
    glTranslatef(0,0,radius);

    //glTranslatef(110,0,0);

    glRotatef(angle1,0,0,1);
    glRotatef(angle,0,1,0);
    drawCircle(radius,segments);
    //glTranslatef(0,10,0);
    //drawCircle(30,24);

    for(int i=0; i<segments; i++)
    {
        glBegin(GL_QUADS);
        {
            glVertex3f(points[i].x,-5,points[i].z);
            glVertex3f(points[i+1].x,-5,points[i+1].z);
            glVertex3f(points[i+1].x,5,points[i+1].z);
            glVertex3f(points[i].x,5,points[i].z);
        }
        glEnd();
    }

    glBegin(GL_QUADS);
    {
        glVertex3f(-radius,-3,0);
        glVertex3f(-radius,3,0);
        glVertex3f(radius,3,0);
        glVertex3f(radius,-3,0);

        glVertex3f(0,-3,radius);
        glVertex3f(0,3,radius);
        glVertex3f(0,3,-radius);
        glVertex3f(0,-3,-radius);
    }
    glEnd();




    //drawCone(20,50,24);

    //drawSphere(30,24,20);




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
    drawgrid=1;
    drawaxes=1;
    cameraHeight=150.0;
    cameraAngle=1.0;
    angle=0;
    angle1=0;
    translate=0;
    tx=0;
    ty=0;
    radius=30;
    segments=24;
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
    gluPerspective(80,	1,	1,	1000.0);
    //field of view in the Y (vertically)
    //aspect ratio that determines the field of view in the X direction (horizontally)
    //near distance
    //far distance
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

    glutCreateWindow("My OpenGL Program");

    init();

    glEnable(GL_DEPTH_TEST);	//enable Depth Testing

    glutDisplayFunc(display);	//display callback function
    glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

    glutKeyboardFunc(keyboardListener);
    glutSpecialFunc(specialKeyListener);
    glutMouseFunc(mouseListener);

    glutMainLoop();		//The main loop of OpenGL

    return 0;
}
