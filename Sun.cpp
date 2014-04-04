#include "Sun.h"

const float Sun::COLOR[3] = {1.0, 1.0, 0.0};

Sun::Sun(int x, int y, float radiusRelative) : Celestial(x, y, radiusRelative)
{
  glColor3fv(COLOR);
  draw();
}

void Sun::draw()
{
  circleMidpoint(x, y, radiusRelative);
}
