#ifndef __CELESTIAL_H_INCLUDED__
#define __CELESTIAL_H_INCLUDED__

#include <GL/glut.h>
#include <GL/freeglut.h>

#include "ScreenPt.h"

class Celestial
{
  public:
    Celestial(const char* caption, int x, int y, float radiusRelative = 1.0);
  protected:
    const char* caption;
    const GLint x;
    const GLint y;
    const GLint radiusRelative;
    void circleMidpoint(GLint xc, GLint yc, GLint radius);
    void circlePlotPoints(GLint xc, GLint yc, ScreenPt circPt);
    void setPixel(GLint xPos, GLint yPos);
  private:
    static const float EARTH_PIXEL_RADIUS;
    virtual void draw() = 0;
};

#endif
