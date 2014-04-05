#include <iostream>
#include <GL/glut.h>

#include "Planet.h"
#include "Sun.h"

// Window display size
GLsizei winWidth = 1280, winHeight = 1024;   

// Initialize method
void init()
{
  // Get and display your OpenGL version
  std::cout << "Your OpenGL version is " << glGetString(GL_VERSION) << std::endl;

  // Black background
  glClearColor(0.0, 0.0, 0.0, 0.0);

  // Projection on World Coordinates 
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0,(GLdouble) winWidth , 0.0,(GLdouble) winHeight);
}

// Draw method
void displayFcn()
{
  int xc = winWidth / 2, yc = winHeight / 2;
  float green[3] = {0.0, 0.75, 0.0};
  float orange[3] = {1.0, 0.6, 0};
  float red[3] = {1.0, 0.0, 0.0};
  float blue[3] = {0.0, 0.0, 1.0};

  // Clear display window.
  glClear(GL_COLOR_BUFFER_BIT);  

  glColor3f(1.0, 0.0, 0.0);

  Sun sun("Sun", xc, yc, 3.0);

  glColor3fv(green);
  Planet earth("Earth", xc, yc, 1.0, 1.0);

  glColor3fv(orange);
  Planet mercury("Mercury", xc, yc, 0.382, 0.387);

  glColor3fv(blue);
  Planet venus("Venus", xc, yc, 0.949, 0.723);

  glColor3fv(red);
  Planet mars("Mars", xc, yc, 0.532, 1.524);


  glFlush( );
}

// Window redraw method
void winReshapeFcn(GLint newWidth, GLint newHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity( );
    gluOrtho2D(0.0,(GLdouble) newWidth, 0.0,(GLdouble) newHeight);
    glClear(GL_COLOR_BUFFER_BIT);  
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);

    glutCreateWindow("Rice Homework 3 - Planets");
    init();
    glutDisplayFunc(displayFcn);

    glutReshapeFunc(winReshapeFcn);
    glutMainLoop();

    return 0;
}
