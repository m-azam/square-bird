#include<windows.h>
#include<GL/glut.h>
#include<time.h>
#include<math.h>
#include<stdio.h>
#include<conio.h>
#define PI 3.14
int cam = -600, yax = 0, flag = 0, i, dis = 0, a[15] = { 541,930,600,541,930,600,541,930,600,541,930,600,541,930,600 }, c, temp, dot = 0, gameflag = 0;
time_t start, end;
GLfloat gx, gy;
void reshape(int w, int h);
void display();
void drawGround();
void drawObstacles();
void myMouse(int b, int s, int x, int y);
void drawPlayerModel(GLfloat x, GLfloat y);
void camMovement();
void air();
void gameover();
void congrats();
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius);
void renderBitmapString(float x, float y, float z, void *font, char*string);
void myKeyboard(unsigned char key, int x, int yq);
void sleep(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}
void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Game");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutIdleFunc(camMovement);
	glutKeyboardFunc(myKeyboard);
	glutMouseFunc(myMouse);
	glutMainLoop();
}
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-800, 800, -800, 800);
	glMatrixMode(GL_MODELVIEW);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.74902, 0.847059, 0.847059, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(-cam, 0, 0);
	time(&start);
	drawGround();
	drawObstacles();
	drawPlayerModel(cam, -700 + yax);
	glFlush();
	glutSwapBuffers();
}
void drawGround()
{
	int x;

	glColor3f(0.13, 0.55, 0.13);
	glBegin(GL_QUADS);
	glVertex2f(0, -700);
	glVertex2f(0, -720);
	glVertex2f(100000000, -720);
	glVertex2f(100000000, -700);
	glEnd();
	glColor3f(0.858824, 0.576471, 0.439216);
	glBegin(GL_QUADS);
	glVertex2f(0, -800);
	glVertex2f(0, -720);
	glVertex2f(100000000, -720);
	glVertex2f(100000000, -800);
	glEnd();

	glColor3f(.6, .6, .3);
	glBegin(GL_QUADS);
	glVertex2f(0, 0);
	glVertex2f(0, 100);
	glVertex2f(100000000, 100);
	glVertex2f(100000000, 0);
	glEnd();
	/*princess*/
	glColor3f(1, 0.43, 0.78);
	glBegin(GL_POLYGON);
	glVertex2f(14849 + 125, -700 + 100);
	glVertex2f(14849 + 175, -700 + 100);
	glVertex2f(14849 + 175, -700 + 130);
	glEnd();
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(14849 + 100, -700 + 60);
	glVertex2f(14849 + 100, -700 + 40);
	glVertex2f(14849 + 75, -700 + 50);
	glEnd();
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex2f(14849 + 100, -700 + 0);
	glVertex2f(14849 + 200, -700 + 0);
	glVertex2f(14849 + 200, -700 + 100);
	glVertex2f(14849 + 100, -700 + 100);
	glEnd();
	glPointSize(9.0);
	glColor3f(1, 0.43, 0.78);
	glBegin(GL_POINTS);
	glVertex2f(14849 + 130, -700 + 60);
	glEnd();
	glutPostRedisplay();
}
void drawObstacles()
{
	int i;
	for (i = 0, c = 0; i < 15; i++)
	{
		glColor3f(0, .5, 0);
		glBegin(GL_QUADS);

		glVertex2f(100 + a[i] + c, -700);
		glVertex2f(300 + a[i] + c, -700);
		glVertex2f(300 + a[i] + c, -300);
		glVertex2f(100 + a[i] + c, -300);
		glEnd();
		c = c + 900;
	}
}
void drawPlayerModel(GLfloat x, GLfloat y)
{
	gx = x;
	gy = y;
	if ((x + 100 > a[0] && x + 100 < 800 && y < -300) || (x + 100 > a[1] + 900 && x + 100 < 1179 + 900 && y < -300) || (x + 100 > a[2] + 1800 && x + 100 < 849 + 1800 && y < -300))
	{
		air();
	}
	if ((x + 100 > a[3] + 2700 && x + 100 < 800 + 2700 && y < -300) || (x + 100 > a[4] + 3600 && x + 100 < 1179 + 3600 && y < -300) || (x + 100 > a[5] + 4500 && x + 100 < 849 + 4500 && y < -300))
	{
		air();
	}
	if ((x + 100 > a[6] + 5400 && x + 100 < 800 + 5400 && y < -300) || (x + 100 > a[7] + 6300 && x + 100 < 1179 + 6300 && y < -300) || (x + 100 > a[8] + 7200 && x + 100 < 849 + 7200 && y < -300))
	{
		air();
	}
	if ((x + 100 > a[6] + 8100 && x + 100 < 800 + 8100 && y < -300) || (x + 100 > a[7] + 9000 && x + 100 < 1179 + 9000 && y < -300) || (x + 100 > a[8] + 9900 && x + 100 < 849 + 9900 && y < -300))
	{
		air();
	}
	if ((x + 100 > a[6] + 10800 && x + 100 < 800 + 10800 && y < -300) || (x + 100 > a[7] + 11700 && x + 100 < 1179 + 11700 && y < -300) || (x + 100 > a[8] + 12600 && x + 100 < 849 + 12600 && y < -300))
	{
		air();
	}
	if (y + 100 >= 0)
	{
		air();
	}
	drawFilledCircle(x + 600, 600, 100);
	/*complete*/
	if (x + 100 > 14649)
	{
		gameflag = 1;
		glColor3f(0.0, 0.0, 1.0);
		glColor3f(1.0, 0.0, 0.0);
		renderBitmapString(cam, 70, 0, GLUT_BITMAP_HELVETICA_18, "Congrats!");
		glutPostRedisplay();
	}
	/*body*/
	glColor3f(0.196078, 0.6, 0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x + 125, y + 100);
	glVertex2f(x + 125, y + 130);
	glVertex2f(x + 175, y + 100);
	glEnd();
	glColor3f(1, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(x + 200, y + 60);
	glVertex2f(x + 200, y + 40);
	glVertex2f(x + 225, y + 50);
	glEnd();
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex2f(x + 100, y + 0);
	glVertex2f(x + 200, y + 0);
	glVertex2f(x + 200, y + 100);
	glVertex2f(x + 100, y + 100);
	glEnd();
	glPointSize(9.0);
	glColor3f(0.196078, 0.6, 0.8);
	glBegin(GL_POINTS);
	glVertex2f(x + 170, y + 60);
	glEnd();
}
void myMouse(int b, int s, int x, int y)
{

	if (b == GLUT_LEFT_BUTTON && s == GLUT_DOWN)
	{
		if (gameflag == 0)
		{
			yax = yax + 100;
			dis = 0;
			glutPostRedisplay();
		}
	}
}
void myKeyboard(unsigned char key, int x, int yq)
{
	if (key == 'q')
	{
		exit(0);
	}
}
void camMovement()
{
	if (gameflag == 0)
	{
		if (gy > -700)
		{
			cam = cam + 10;
			time(&end);
			dis = dis + 10;
			if (dis > 350)
			{
				yax = yax - 10;
			}
			glutPostRedisplay();
		}
		else
		{
			cam = cam + 10;
			glutPostRedisplay();
		}
		if (difftime(start, end) > 1)
		{
			if (gy == -600)
			{
				exit(0);
			}
		}
	}
}
void air()
{
	gameflag = 1;
	glColor3f(0.0, 0.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	renderBitmapString(cam, 200, 0, GLUT_BITMAP_HELVETICA_18, "Game Over.");
	glutPostRedisplay();
}
void renderBitmapString(float x, float y, float z, void *font, char*string)
{

	char *c;

	glRasterPos3f(x, y, z);

	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius)
{
	int i;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;
	glColor3f(0.89, .75, 0.2);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius * cos(i *  twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();
}
