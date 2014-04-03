#ifndef __SCREENPT_H_INCLUDED__
#define __SCREENPT_H_INCLUDED__

#include <GL/glut.h>

class ScreenPt
{
  public:
    ScreenPt();
    GLint getx() const;
    GLint gety() const;
    void incrementx();
    void decrementy();
    void setCoords (GLint xCoordValue, GLint yCoordValue);
  private:
    GLint x, y;
};

#endif
