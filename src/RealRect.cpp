#include "RealRect.h"


RealRect::RealRect()
{
	l = 0; r = 100; b = 0; t = 100;
}
RealRect::RealRect(float left, float right, float bottom, float top)
{
	l = left; r = right; b = bottom; t = top;
}
void RealRect::set(float left, float right, float bottom, float top)
{
	l = left; r = right; b = bottom; t = top;
}

float RealRect::getLeft(void)      //left boundary
{
  return l;
}

float RealRect::getRight(void)      //right
{
  return r;
}

float RealRect::getTop(void)
{
  return t;
}

float RealRect::getBottom(void)
{
  return b;
}

void RealRect::draw(void)
{
  glRectf( l, b, r, t);
}
