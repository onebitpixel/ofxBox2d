

#pragma once
#include "ofMain.h"
#include "ofxBox2dBaseShape.h"

class ofxBox2dRect : public ofxBox2dBaseShape {

private:
	float _width, _height;

public:
	
	//------------------------------------------------
	ofxBox2dRect();	
	
	//------------------------------------------------
	void setup(b2World * b2dworld, ofRectangle rec);
	void setup(b2World * b2dworld, float x, float y, float w, float h);
	
	float getWidth();
	float getHeight();
	
	//------------------------------------------------
	void draw();
	
};














