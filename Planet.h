#ifndef __PLANET_H_INCLUDED__
#define __PLANET_H_INCLUDED__

#include <cmath>

#include "Celestial.h"

class Planet : public Celestial 
{
  public:
    Planet(const char* caption, 
           int x, 
           int y, 
           float radiusRelative = 1.0, 
           float distanceFromSunAU = 1.0);
  private:
    static const int EARTH_PIXEL_ORBIT_MAJOR_AXIS;
    static const int EARTH_PIXEL_ORBIT_MINOR_AXIS;
    const float distanceFromSunAU;
    void draw();
    void ellipseMidpoint(float xCenter, float yCenter, int Rx, int Ry);
    void ellipsePlotPoints(float xCenter, float yCenter, float x, float y);
};

#endif
