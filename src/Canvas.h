#ifndef CANVAS_H
#define CANVAS_H
#include "IntRect.h"
#include "Point2.h"
#include "RealRect.h"
#include <GL/glut.h>
#include <math.h>
#include <stack>
#include <iostream>
using namespace std;


class Canvas {

public:
	Canvas(int width, int height, char * windowTitle); // constructor1
	~Canvas ();
	void setWindow(float l, float r, float b, float t);
	void setViewport(int l, int r, int b, int t);
	IntRect getViewport(void); // divulge the viewport data
	RealRect getWindow(void); // divulge the window data
	float getWindowAspectRatio(void);
	void clearScreen();
	void setBackgroundColor(float r, float g, float b);
	void setColor(float r, float g, float b);
	void lineTo(float x, float y);
	void lineTo(Point2 p);
	void moveTo(float x, float y);
	void moveTo(Point2 p);
	void moveRel(float dx, float dy);
    void lineRel(float dx, float dy);
	void turnTo(float angle);
	void turnRight(float angle);
	void turnLeft(float angle);
    void forward(float dist, int isVisible);
    float getAngle();
    Point2 getLastPosition();

private:
    Point2 CP; // current position in the world
    IntRect viewport; // the current view port
    RealRect window; // the current window
    float CD;
    stack<Point2> * lastPositions;
    Point2 lastPosition;
};
#endif

