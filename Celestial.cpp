#include "Celestial.h"

// Everything else will be relative size where this == 1.0
const float Celestial::EARTH_PIXEL_RADIUS = 20;

Celestial::Celestial(const char* caption, int x, int y, float radiusRelative) : 
  caption(caption), x(x), y(y), radiusRelative(EARTH_PIXEL_RADIUS * radiusRelative)
{
  // Subclasses should probably call draw() here
}

void Celestial::circleMidpoint(GLint xc, GLint yc, GLint radius)
{
  ScreenPt circPt;
  GLint p = 1 - radius; // Initial value for midpoint parameter.
  circPt.setCoords (0, radius); // Set coordinates for top point of circle.

  /* Plot the initial point in each circle quadrant. */
  circlePlotPoints(xc, yc, circPt);

  /* Calculate next point and plot in each octant. */
  while (circPt.getx ( ) < circPt.gety ( )) {
    circPt.incrementx ( );
    if (p < 0)
      p += 2 * circPt.getx ( ) + 1;
    else {
      circPt.decrementy ( );
      p += 2 * (circPt.getx ( ) - circPt.gety ( )) + 1;
    }
    circlePlotPoints(xc, yc, circPt);
  }
}

void Celestial::circlePlotPoints(GLint xc, GLint yc, ScreenPt circPt) 
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

void Celestial::setPixel(GLint xPos, GLint yPos) 
{
  glBegin(GL_POINTS);
  glVertex2i(xPos, yPos);
  glEnd();
}

