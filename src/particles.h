//
//  particles.h
//  mySketch
//
//  Created by 曾凡预 on 13-10-21.
//
//

#ifndef mySketch_particles_h
#define mySketch_particles_h
#include "ofMain.h"
#define NUM 200

class particles {
	
public:
    void setup( ofColor aColor, float aRotation, float aSpeed,float aSize);
    void update();
    void draw();
  
    
    ofColor color;
    float rotation;
    float speed;
    float size;
    float alpha;
    ofPoint pos;
    
    
};


#endif
