#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include <windows.h>
#include <glut.h>

#define pi (2*acos(0.0))

double cameraHeight=0;
double cameraAngle;
int drawgrid;
int drawaxes;
double angle;
double radius,height,var;

struct point
{
	double x,y,z;
}pos;

struct up
{
	double x,y,z;
}u;

struct look
{
	double x,y,z;
}l;

struct right
{
	double x,y,z;
}r;

void drawAxes()
{
	if(drawaxes==1)
	{
            glColor3f(1.0, 1.0, 1.0);
            glBegin(GL_LINES);{
		    glColor3f(1, 0, 0);
			glVertex3f( 100,0,0);
			glVertex3f(-100,0,0);

            glColor3f(0, 1, 0);
			glVertex3f(0,-100,0);
			glVertex3f(0, 100,0);

            glColor3f(0, 0, 1);
			glVertex3f(0,0, 100);
			glVertex3f(0,0,-100);
		}glEnd();
	}
}


void drawGrid()
{
	int i;
	if(drawgrid==1)
	{
		glColor3f(0.6, 0.6, 0.6);	//grey
		glBegin(GL_LINES);{
			for(i=-8;i<=8;i++){

				if(i==0)
					continue;	//SKIP the MAIN axes

				//lines parallel to Y-axis
				glVertex3f(i*10, -90, 0);
				glVertex3f(i*10,  90, 0);

				//lines parallel to X-axis
				glVertex3f(-90, i*10, 0);
				glVertex3f( 90, i*10, 0);


			}
		}glEnd();
	}
}

void drawSquare(double a)
{
    glColor3f(1,1,1);
	glBegin(GL_QUADS);{
		glVertex3f( a, a,2);
		glVertex3f( a,-a,2);
		glVertex3f(-a,-a,2);
		glVertex3f(-a, a,2);
	}glEnd();
}




void drawSphere(double radius,int slices,int stacks)
{
	struct point points[100][100];
	int i,j;
	double h,r;
	//generate points
	for(i=0;i<=stacks;i++)
	{
		h=radius*sin(((double)i/(double)stacks)*(pi/2));
		r=radius*cos(((double)i/(double)stacks)*(pi/2));
		for(j=0;j<=slices;j++)
		{
			points[i][j].x=r*cos(((double)j/(double)slices)*.5*pi);
			points[i][j].y=r*sin(((double)j/(double)slices)*.5*pi);
			points[i][j].z=h;
		}
	}
	//draw quads using generated points
	for(i=0;i<stacks;i++)
	{
        //glColor3f((double)i/(double)stacks,(double)i/(double)stacks,(double)i/(double)stacks);
         glColor3f(1,0,0);
		for(j=0;j<slices;j++)
		{
			glBegin(GL_QUADS);{
			    //upper hemisphere
				/*glVertex3f(points[i][j].x,points[i][j].y,points[i][j].z);
				glVertex3f(points[i][j+1].x,points[i][j+1].y,points[i][j+1].z);
				glVertex3f(points[i+1][j+1].x,points[i+1][j+1].y,points[i+1][j+1].z);
				glVertex3f(points[i+1][j].x,points[i+1][j].y,points[i+1][j].z);*/
                //lower hemisphere
                glVertex3f(points[i][j].x,points[i][j].y,-points[i][j].z);
				glVertex3f(points[i][j+1].x,points[i][j+1].y,-points[i][j+1].z);
				glVertex3f(points[i+1][j+1].x,points[i+1][j+1].y,-points[i+1][j+1].z);
				glVertex3f(points[i+1][j].x,points[i+1][j].y,-points[i+1][j].z);
			}glEnd();
		}
	}
}




void drawcylinder(double radius,int height,int slices,int stacks)
{
	struct point points[100][100];
	int i,j;
	double h,r;
	//generate points
	for(i=0;i<=stacks;i++)
	{
		h=height*sin(((double)i/(double)stacks)*(pi/2));
		//r=radius*cos(((double)i/(double)stacks)*(pi/2));
		r=radius;
		for(j=0;j<=slices;j++)
		{
			points[i][j].x=r*cos(((double)j/(double)slices)*.5*pi);
			points[i][j].y=r*sin(((double)j/(double)slices)*.5*pi);
			points[i][j].z=h;
		}
	}
	//draw quads using generated points
	for(i=0;i<stacks;i++)
	{
        //glColor3f((double)i/(double)stacks,(double)i/(double)stacks,(double)i/(double)stacks);
         glColor3f(0,1,0);
		for(j=0;j<slices;j++)
		{
			glBegin(GL_QUADS);{
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
			}glEnd();
		}
	}
}


void keyboardListener(unsigned char key, int x,int y){
	switch(key){

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


void specialKeyListener(int key, int x,int y){
	switch(key){
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



void display(){

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
	gluLookAt(pos.x, pos.y, pos.z, pos.x + l.x, pos.y + l.y, pos.z + l.z, u.x, u.y ,u.z);
	//gluLookAt(100+cameraHeight,100,0,	0,0,0,	0,0,1);


	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	/****************************
	/ Add your objects from here
	****************************/
	//add objects

	drawAxes();
	drawGrid();

    //glColor3f(1,0,0);
    //drawSquare(80);
    //drawSphere();
    //drawSS();

    //drawCircle(60,64);

    //drawCone(60,90,94);

    //drawSphere(20,79,80);
    //drawcylinder(10,30,79,80);
    //drawSquare(20);
    double dist=radius+height;
    glPushMatrix();
    {
        glTranslatef(dist-2,0,0);
        glRotatef(90,0,1,0);
        drawSquare(height);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glTranslatef(-(dist+2),0,0);
        glRotatef(90,0,1,0);
        drawSquare(height);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glTranslatef(0,dist+2,0);
        glRotatef(90,1,0,0);
        drawSquare(height);
    }
    glPopMatrix();


    glPushMatrix();
    {
        glTranslatef(-0,-(dist-2),0);
        glRotatef(90,1,0,0);
        drawSquare(height);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glTranslatef(0,0,-(dist+2));
        drawSquare(height);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glTranslatef(0,0,dist-2);
        drawSquare(height);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glTranslatef(0,-height,-height);
        glRotatef(90,0,1,0);
        glRotatef(180,1,0,0);
        drawcylinder(radius,height,79,80);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glTranslatef(0,-height,height);
        glRotatef(270,0,0,1);
        glRotatef(90,1,0,0);
        drawcylinder(radius,height,79,80);
    }
    glPopMatrix();


   glPushMatrix();
    {
        glTranslatef(-height,0,height);
        glRotatef(270,0,1,0);
        glRotatef(90,1,0,0);
        drawcylinder(radius,height,79,80);
    }
    glPopMatrix();

     glPushMatrix();
    {
        glTranslatef(-height,0,-height);
        glRotatef(180,0,1,0);
        glRotatef(90,1,0,0);
        drawcylinder(radius,height,79,80);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glTranslatef(-height,-height,0);
        glRotatef(180,0,0,1);
         drawcylinder(radius,height,79,80);
    }
    glPopMatrix();

     glPushMatrix();
    {
        glTranslatef(-height,height,0);
        glRotatef(90,0,0,1);
         drawcylinder(radius,height,79,80);
    }
    glPopMatrix();


    glPushMatrix();
    {
        glTranslatef(0,height,height);
        glRotatef(270,0,1,0);
         drawcylinder(radius,height,79,80);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glTranslatef(0,height,-height);
        glRotatef(90,0,1,0);
         drawcylinder(radius,height,79,80);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glTranslatef(height,0,-height);
        glRotatef(270,1,0,0);
         drawcylinder(radius,height,79,80);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glTranslatef(height,-height,0);
        glRotatef(180,1,0,0);
         drawcylinder(radius,height,79,80);
    }
    glPopMatrix();


    glPushMatrix();
    {
        glTranslatef(height,0,height);
        glRotatef(90,1,0,0);
         drawcylinder(radius,height,79,80);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glTranslatef(height,height,0);
         drawcylinder(radius,height,79,80);
    }
    glPopMatrix();




    glPushMatrix();
    {
        glTranslatef(height,height,height);
        glRotatef(90,1,0,0);
        drawSphere(radius,79,80);
    }
    glPopMatrix();

     glPushMatrix();
    {

        glTranslatef(height,height,-height);
        //glRotatef(pi,1,0,0);
         drawSphere(radius,79,80);
    }
    glPopMatrix();


    glPushMatrix();
    {
        glTranslatef(height,-height,-height);
        glRotatef(270,1,0,0);
         drawSphere(radius,79,80);
    }
    glPopMatrix();

     glPushMatrix();
    {
        glTranslatef(height,-height,height);
        glRotatef(180,1,0,0);
         drawSphere(radius,79,80);
    }
    glPopMatrix();



     glPushMatrix();
    {
        glTranslatef(-height,height,height);
       glRotatef(180,0,1,0);
         drawSphere(radius,79,80);
    }
    glPopMatrix();

     glPushMatrix();
    {
        glTranslatef(-height,height,-height);
        glRotatef(90,0,1,0);
         drawSphere(radius,79,80);
    }
    glPopMatrix();



     glPushMatrix();
    {
        glTranslatef(-height,-height,height);
        glRotatef(180,0,1,0);
        glRotatef(270,0,0,1);
         drawSphere(radius,79,80);
    }
    glPopMatrix();

     glPushMatrix();
    {
        glTranslatef(-height,-height,-height);
        glRotatef(180,0,0,1);
        drawSphere(radius,79,80);
    }

    glPopMatrix();

     //drawSphere(30,79,80);
    //offline(30);

	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}


void animate(){
	//angle+=0.05;
	//codes for any changes in Models, Camera
	glutPostRedisplay();
}

void init(){
	//codes for initialization
	drawgrid=0;
	drawaxes=1;
	cameraHeight=0.0;
	cameraAngle=1.0;
	angle=1.2*pi/180;
	var=3;

	pos.x=100;
	pos.y=100;
	pos.z=0;

	u.x=0;
	u.y=0;
	u.z=1;

	l.x= -1/sqrt(2);
	l.y = -1/sqrt(2);
	l.z =0;

	r.x= -1/sqrt(2);
	r.y = 1/sqrt(2);
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
	gluPerspective(80,	1,	1,	1000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance
}



int main(int argc, char **argv){
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
