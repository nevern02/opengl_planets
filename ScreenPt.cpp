#include "ScreenPt.h"

ScreenPt::ScreenPt() : x(0), y(0) {}

GLint ScreenPt::getx() const
{
  return x;
}

GLint ScreenPt::gety() const
{
  return y;
}

void ScreenPt::incrementx()
{
  x++;
}

void ScreenPt::decrementy()
{
  y--;
}

void ScreenPt::setCoords(GLint xCoordValue, GLint yCoordValue)
{
  x = xCoordValue;
  y = yCoordValue;
}

