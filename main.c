//#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

double x1 = 1, y1 = 1, z1 = 1, d = 0, d2 = 0, d3 = 0, d4 = 0;
int m = 1;

void lengan()
{
//    glPushMatrix();
//    glTranslated(10,0,0);
    glRectd(-10,-2,10,2);
//    glPopMaXtrCix();
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);

    glRotated(d4,0,0,1);

    glPushMatrix();
    glTranslated(-20,0,0);
    glRotated(d,0,0,1);
    lengan();
    glPopMatrix();
//    glLoadIdentity();

    glPushMatrix();
    glTranslated(0,20,0);
    glRotated(d2,0,0,1);
    lengan();
    glPopMatrix();
//    glLoadIdentity();

    glPushMatrix();
    glTranslated(20,0,0);
    glRotated(d3,0,0,1);
    lengan();
    glPopMatrix();
//    glLoadIdentity();

    glLoadIdentity();
    glBegin(GL_LINES);
    glVertex2d(50,0);
    glVertex2d(-50,0);
    glEnd();
    glBegin(GL_LINES);
    glVertex2d(0,50);
    glVertex2d(0,-50);
    glEnd();

    glFlush();

}

void input(unsigned char key, int x, int y)
{
    if(key=='w')
    {
        if(m == 1){
            d+=1;
            display();
        }
        if(m == 2){
            d2+=1;
            display();
        }
        if(m == 3){
            d3+=1;
            display();
        }
        if(m == 4){
            d4+=1;
            display();
        }
    }
    if(key=='s')
    {
        if(m == 1){
            d-=1;
            display();
        }
        if(m == 2){
            d2-=1;
            display();
        }
        if(m == 3){
            d3-=1;
            display();
        }
        if(m == 4){
            d4-=1;
            display();
        }
    }

    if(key=='1')
    {
        m=1;
        display();
    }
    if(key=='2')
    {
        m=2;
        display();
    }
    if(key=='3')
    {
        m=3;
        display();
    }
    if(key=='4')
    {
        m=4;
        display();
    }
//    if(key=='s')
//    {
//        posY-=0.2;
//        display();
//    }
//    if(key=='d')
//    {
//        posX+=0.2;
//        display();
//    }
//    if(key=='a')
//    {
//        posX-=0.2;
//        display();
//    }
}
void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50.0,50.0,-50.0,50.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.0,0.0,0.0);
}
int main(int argc, char* argv[])

{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Transform");
    glutDisplayFunc(display);
    glutKeyboardFunc(input);
    myinit();
    glutMainLoop();
    return 0;
}
