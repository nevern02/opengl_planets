#include "Sun.h"

const float Sun::COLOR[3] = {1.0, 1.0, 0.0};

Sun::Sun(const char* caption, int x, int y, float radiusRelative) : 
  Celestial(caption, x, y, radiusRelative)
{
  glColor3fv(COLOR);
  draw();

  glRasterPos2i(x, y);
  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)caption);
}

void Sun::draw()
{
  circleMidpoint(x, y, radiusRelative);
}
