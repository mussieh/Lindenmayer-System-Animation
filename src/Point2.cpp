#include "Point2.h"


Point2::Point2() {x = 0.0f; y = 0.0f;} // constructor1

Point2::Point2(float xx, float yy) {x = xx; y = yy;} // constructor2

void Point2::set(float xx, float yy) {x = xx; y = yy;}

float Point2::getX() {return x;}

float Point2::getY() {return y;}

void Point2::setX(float xx) {x = xx;}

void Point2::setY(float yy) {y = yy;}

void Point2::draw(void) {
		glBegin(GL_POINTS); // draw this point
		    glVertex2f( (GLfloat) x, (GLfloat) y);
		glEnd();
}


