#include <cmath>
#include <iostream>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "ScreenPt.h"

void ellipseMidpoint(int xCenter, int yCenter, int Rx, int Ry);
void circleMidpoint(GLint xc, GLint yc, GLint radius);

// Window display size
GLsizei winWidth = 800, winHeight = 600;   

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
  // Clear display window.
  glClear(GL_COLOR_BUFFER_BIT);  

  glColor3f(1.0, 0.0, 0.0);

  GLint xc = 400, yc = 300, radius = 10;

  circleMidpoint(xc + 200, yc, radius);

  // Ellipse
  ellipseMidpoint(xc, yc, 200, 100);

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

void setPixel(GLint xPos, GLint yPos)
{
  glBegin(GL_POINTS);
  glVertex2i(xPos, yPos);
  glEnd();
}

void ellipsePlotPoints(int xCenter, int yCenter, int x, int y)
{
  setPixel(xCenter + x, yCenter + y);
  setPixel(xCenter - x, yCenter + y);
  setPixel(xCenter + x, yCenter - y);
  setPixel(xCenter - x, yCenter - y);
}

void ellipseMidpoint (int xCenter, int yCenter, int Rx, int Ry)
{
  int Rx2 = Rx * Rx;
  int Ry2 = Ry * Ry;
  int twoRx2 = 2 * Rx2;
  int twoRy2 = 2 * Ry2;
  int p;
  int x = 0;
  int y = Ry;
  int px = 0;
  int py = twoRx2 * y;
  /* Plot the initial point in each quadrant. */
  ellipsePlotPoints (xCenter, yCenter, x, y);
  /* Region 1 */
  p = ceil (Ry2 - (Rx2 * Ry) + (0.25 * Rx2));
  while (px < py) {
    x++;
    px += twoRy2;
    if (p < 0)
      p += Ry2 + px;
    else {
      y--;
      py -= twoRx2;
      p += Ry2 + px - py;
    }
    ellipsePlotPoints (xCenter, yCenter, x, y);
  }

  /* Region 2 */
  p = ceil (Ry2 * (x+0.5) * (x+0.5) + Rx2 * (y-1) * (y-1) - Rx2 * Ry2);
  while (y > 0) {
    y--;
    py -= twoRx2;
    if (p > 0)
      p += Rx2 - py;
    else {
      x++;
      px += twoRy2;
      p += Rx2 - py + px;
    }
    ellipsePlotPoints(xCenter, yCenter, x, y);
  }
}

void circlePlotPoints(GLint xc, GLint yc, ScreenPt circPt)
{
  setPixel(xc + circPt.getx(), yc + circPt.gety());
  setPixel(xc - circPt.getx(), yc + circPt.gety());
  setPixel(xc + circPt.getx(), yc - circPt.gety());
  setPixel(xc - circPt.getx(), yc - circPt.gety());
  setPixel(xc + circPt.gety(), yc + circPt.getx());
  setPixel(xc - circPt.gety(), yc + circPt.getx());
  setPixel(xc + circPt.gety(), yc - circPt.getx());
  setPixel(xc - circPt.gety(), yc - circPt.getx());
}

void circleMidpoint (GLint xc, GLint yc, GLint radius)
{
  ScreenPt circPt;
  GLint p = 1 - radius; // Initial value for midpoint parameter.
  circPt.setCoords (0, radius); // Set coordinates for top point of circle.

  /* Plot the initial point in each circle quadrant. */
  circlePlotPoints (xc, yc, circPt);

  /* Calculate next point and plot in each octant. */
  while (circPt.getx ( ) < circPt.gety ( )) {
    circPt.incrementx ( );
    if (p < 0)
      p += 2 * circPt.getx ( ) + 1;
    else {
      circPt.decrementy ( );
      p += 2 * (circPt.getx ( ) - circPt.gety ( )) + 1;
    }
    circlePlotPoints (xc, yc, circPt);
  }
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
