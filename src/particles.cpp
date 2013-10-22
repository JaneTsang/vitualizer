//
//  particles.cpp
//  mySketch
//
//  Created by 曾凡预 on 13-10-21.
//
//

#include "particles.h"

void particles::setup( ofColor aColor, float aRotation, float aSpeed, float aSize) {
    
    
    color = aColor;
    rotation = aRotation;
    speed = aSpeed;
    
    pos.x = 1;
    pos.y = 1;
    
    alpha = 255;
    size=aSize;
   
}

void particles::update(){
    alpha -= speed/2;
    rotation += 0.5;
    
    if (alpha < 0){
        alpha = 0;
    }
}

void particles::draw(){
    float x1= size ;
    
    float yy=rotation*0.4;
    for (int i=1; i<NUM; i=i+2) {
           x1=x1*sqrt(2)/2;
    ofPushMatrix();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
      float r = ofMap(yy/10, 0,60, 0, 360);
 ofRotateZ(r);
    ofSetColor(color+i, alpha+i);
    ofFill();
    ofRect(pos.x,pos.y,x1*2,x1*2);
    ofSetColor(color-100, alpha+100);
    ofFill();
    ofCircle(pos.x,pos.y, x1);
    
    
    ofPopMatrix();
       }
    
}