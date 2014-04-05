#include "Planet.h"

// These == distanceFromSunAU = 1.0
const int Planet::EARTH_PIXEL_ORBIT_MAJOR_AXIS = 350;
const int Planet::EARTH_PIXEL_ORBIT_MINOR_AXIS = 175;

Planet::Planet(const char* caption, 
               int x, 
               int y, 
               float radiusRelative, 
               float distanceFromSunAU) : 
  Celestial(caption, x, y, radiusRelative), distanceFromSunAU(distanceFromSunAU)
{
  draw();
}

void Planet::draw()
{
  int majorAxis = distanceFromSunAU * EARTH_PIXEL_ORBIT_MAJOR_AXIS;
  int minorAxis = distanceFromSunAU * EARTH_PIXEL_ORBIT_MINOR_AXIS;

  ellipseMidpoint(x, y, majorAxis, minorAxis);
  circleMidpoint(x + majorAxis, y, radiusRelative);

  glRasterPos2i(x + majorAxis, y);
  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (const unsigned char*)caption);
}

void Planet::ellipseMidpoint(float xCenter, float yCenter, int Rx, int Ry)
{
  float Rx2 = Rx * Rx;
  float Ry2 = Ry * Ry;
  float twoRx2 = 2 * Rx2;
  float twoRy2 = 2 * Ry2;
  float p;
  float x = 0;
  float y = Ry;
  float px = 0;
  float py = twoRx2 * y;
  /* Plot the initial point in each quadrant. */
  ellipsePlotPoints(xCenter, yCenter, x, y);
  /* Region 1 */
  p = ceil(Ry2 - (Rx2 * Ry) + (0.25 * Rx2));
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
    ellipsePlotPoints(xCenter, yCenter, x, y);
  }

  /* Region 2 */
  p = ceil(Ry2 * (x+0.5) * (x+0.5) + Rx2 * (y-1) * (y-1) - Rx2 * Ry2);
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

void Planet::ellipsePlotPoints(float xCenter, float yCenter, float x, float y)
{
  setPixel(xCenter + x, yCenter + y);
  setPixel(xCenter - x, yCenter + y);
  setPixel(xCenter + x, yCenter - y);
  setPixel(xCenter - x, yCenter - y);
}
