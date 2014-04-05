#ifndef __SUN_H_INCLUDED__
#define __SUN_H_INCLUDED__

#include "Celestial.h"

class Sun : public Celestial
{
  public:
    Sun(const char* caption, int x, int y, float radiusRelative = 1.0);
  private:
    static const float COLOR[3];
    void draw();
};

#endif
