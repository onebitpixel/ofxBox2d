/*
 *  ofxBox2dCircle.cpp
 *  ofxBox2dExample
 *
 *  Created by Todd Vanderlin on 3/7/11.
 *  Copyright 2011 Interactive Design. All rights reserved.
 *
 */

#include "ofxBox2dCircle.h"

//------------------------------------------------
ofxBox2dCircle::ofxBox2dCircle() {
}

//------------------------------------------------
void ofxBox2dCircle::setup(b2World * b2dworld, float x, float y, float radius) {
	
	
	if(b2dworld == NULL) {
		ofLog(OF_LOG_NOTICE, "ofxBox2dCircle :: setup : - must have a valid world -");
		return;
	}
	
	// these are used to create the shape
	b2BodyDef	  bodyDef;
	b2CircleShape shape;
	
	shape.m_p.SetZero();
	shape.m_radius		= radius / OFX_BOX2D_SCALE;
	this->radius		= radius;
	
	fixture.shape		= &shape;
	fixture.density		= density;
	fixture.friction	= friction;
	fixture.restitution	= bounce;
	
	if(density == 0.f)	bodyDef.type	= b2_staticBody;
	else				bodyDef.type	= b2_dynamicBody;
	
	bodyDef.position.Set(x/OFX_BOX2D_SCALE, y/OFX_BOX2D_SCALE);
	
	body  = b2dworld->CreateBody(&bodyDef);
	body->CreateFixture(&fixture);
}

//------------------------------------------------
float ofxBox2dCircle::getRadius() {
	return radius;
}

//------------------------------------------------ 
/*
 TODO: Should we even do this....?
 Im not sure about this it seems like a bad idea.
 I cant figure out another way to change the radius of
 a shape that we have
 
 -- any help here :) --
 
 */
void ofxBox2dCircle::setRadius(float r) {
	/*
	 if(body != NULL) {
	 for(b2Shape* s=body->GetShapeList(); s; s=s->GetNext()) {
	 body->DestroyShape(s);
	 }
	 
	 circle.radius	    = r/OFX_BOX2D_SCALE;
	 circle.density		= mass;
	 circle.restitution  = bounce;
	 circle.friction		= friction;
	 
	 //body = world->CreateBody(&bodyDef);
	 body->SetLinearVelocity(b2Vec2(0.0, 0.0));
	 body->CreateShape(&circle);
	 body->SetMassFromShapes();
	 }
	 */
	printf("this does nothing yst!!!\n");
}

//------------------------------------------------
void ofxBox2dCircle::draw() {
	
	if(!isBody()) return;
	
	ofPushMatrix();
	ofTranslate(getPosition().x, getPosition().y, 0);
	ofRotate(getRotation(), 0, 0, 1);
	ofCircle(0, 0, radius);
	ofSetColor(0);
	ofLine(0, 0, radius, 0);
	ofPopMatrix();
	
}














