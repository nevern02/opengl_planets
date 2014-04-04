#include "Planet.h"

// These == distanceFromSunAU = 1.0
const int Planet::EARTH_PIXEL_ORBIT_MAJOR_AXIS = 200;
const int Planet::EARTH_PIXEL_ORBIT_MINOR_AXIS = 100;

Planet::Planet(int x, int y, float radiusRelative, float distanceFromSunAU) : 
  Celestial(x, y, radiusRelative), distanceFromSunAU(distanceFromSunAU)
{
  draw();
}

void Planet::draw()
{
  float majorAxis = distanceFromSunAU * EARTH_PIXEL_ORBIT_MAJOR_AXIS;
  float minorAxis = distanceFromSunAU * EARTH_PIXEL_ORBIT_MINOR_AXIS;

  ellipseMidpoint(x, y, majorAxis, minorAxis);
  circleMidpoint(x + majorAxis, y, radiusRelative);
}

void Planet::ellipseMidpoint(int xCenter, int yCenter, int Rx, int Ry)
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
    ellipsePlotPoints (xCenter, yCenter, x, y);
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

void Planet::ellipsePlotPoints(int xCenter, int yCenter, int x, int y)
{
  setPixel(xCenter + x, yCenter + y);
  setPixel(xCenter - x, yCenter + y);
  setPixel(xCenter + x, yCenter - y);
  setPixel(xCenter - x, yCenter - y);
}
