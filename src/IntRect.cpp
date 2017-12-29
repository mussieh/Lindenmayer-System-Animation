#include "IntRect.h"

IntRect::IntRect() {
	l = 0; r = 100; b = 0; t = 100;
}// constructors

IntRect::IntRect(int left, int right, int bottom, int top){
	l = left; r = right; b = bottom; t = top;
}

void IntRect::set(int left, int right, int bottom, int top)
{
	l = left; r = right; b = bottom; t = top;
}

int IntRect::getLeft(void)      //left boundary
{
  return l;
}

int IntRect::getRight(void)      //right
{
  return r;
}

int IntRect::getTop(void)
{
  return t;
}

int IntRect::getBottom(void)
{
  return b;
}

void IntRect::draw(void)
{
  glRectf( l, b, r, t);
}
