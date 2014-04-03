#ifndef __CELESTIAL_H_INCLUDED__
#define __CELESTIAL_H_INCLUDED__

#include <GL/glut.h>

class Celestial
{
  private:
    void circleMidpoint(GLint xc, GLint yc, GLint radius) const;
    void circlePlotPoints(GLint xc, GLint yc, ScreenPt circPt) const;
    void ellipseMidpoint (int xCenter, int yCenter, int Rx, int Ry);
    void ellipsePlotPoints(int xCenter, int yCenter, int x, int y);
    void setPixel(GLint xPos, GLint yPos);
};

#endif
