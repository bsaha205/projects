#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include <windows.h>
#include <glut.h>

#define pi (2*acos(0.0))

double cameraHeight;
double cameraAngle;
int drawgrid;
int drawaxes;
double angle1,angle2,angle3,angle4,angle5;

struct point
{
	double x,y,z;
};


void drawAxes()
{
	if(drawaxes==1)
    {
        glTranslatef(0,0,100);
        glColor3f(1.0, 1.0, 1.0);
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
    //glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);{
		glVertex3f( a, a,0);
		glVertex3f( a,-a,0);
		glVertex3f(-a,-a,0);
		glVertex3f(-a, a,0);
	}glEnd();
}




/*void drawSS()
{
    glColor3f(1,0,0);
    drawSquare(20);

    glRotatef(angle,0,0,1);
    glTranslatef(110,0,0);
    glRotatef(2*angle,0,0,1);
    glColor3f(0,1,0);
    drawSquare(15);

    glPushMatrix();
    {
        glRotatef(angle,0,0,1);
        glTranslatef(60,0,0);
        glRotatef(2*angle,0,0,1);
        glColor3f(0,0,1);
        drawSquare(10);
    }
    glPopMatrix();

    glRotatef(3*angle,0,0,1);
    glTranslatef(40,0,0);
    glRotatef(4*angle,0,0,1);
    glColor3f(1,1,0);
    drawSquare(5);
}*/

void keyboardListener(unsigned char key, int x,int y){
	switch(key){

		case '1':
		    if(angle1>-90)
			angle1 -=1;
			break;

        case '2':
            if(angle1<0)
			angle1 +=1;
			break;

        case '3':
		    if(angle2<90)
			angle2 +=1;
			break;

        case '4':
            if(angle2>0)
			angle2 -=1;
			break;

        case '5':
		    if(angle3<90)
			angle3 +=1;
			break;

        case '6':
            if(angle3>0)
			angle3 -=1;
			break;

        case '7':
		    if(angle4>-90)
			angle4 -=1;
			break;

        case '8':
            if(angle4<0)
			angle4 +=1;
			break;

        case '9':
		    if(angle5>-90)
			angle5 -=1;
			break;

        case '0':
            if(angle5<0)
			angle5 +=1;
			break;
		default:
			break;
	}
}


void specialKeyListener(int key, int x,int y){
	switch(key){
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



     glPushMatrix();
    {
        glColor3f(1,0,0);
        drawSquare(30);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glColor3f(0,1,0);
        glTranslatef(30,0,0);
        glRotatef(angle1,0,1,0);
        glTranslatef(30,0,0);
        drawSquare(30);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glColor3f(0,0,1);
        glTranslatef(0,30,0);
        glRotatef(angle2,1,0,0);
        glTranslatef(0,30,0);
        drawSquare(30);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glColor3f(1,1,0);
        glTranslatef(-30,0,0);
        glRotatef(angle3,0,1,0);
        glTranslatef(-30,0,0);
        drawSquare(30);
    }
    glPopMatrix();

    glTranslatef(0,-30,0);
    glRotatef(angle4,1,0,0);

    glPushMatrix();
    {
        glColor3f(1,0,1);
        //glRotatef(3*angle,0,0,1);
        glTranslatef(0,-30,0);
        drawSquare(30);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glColor3f(0,1,1);
        glTranslatef(0,-60,0);
        glRotatef(angle5,1,0,0);
        glTranslatef(0,-30,0);
        drawSquare(30);
    }
    glPopMatrix();

    //drawSS();

    //drawCircle(30,24);

    //drawCone(20,50,24);

	//drawSphere(30,24,20);




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
	cameraHeight=150.0;
	cameraAngle=1.0;
	angle1=0;
	angle2=0;
	angle3=0;
	angle4=0;
	angle5=0;

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
	//glutMouseFunc(mouseListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
