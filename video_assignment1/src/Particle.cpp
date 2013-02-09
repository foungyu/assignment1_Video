//
//  Particle.cpp
//  video_assignment1
//
//  Created by foungyu on 13/2/6.
//
//

#include "Particle.h"
#include "ofMain.h"
Particle::Particle(float px,float py)
{
    x = px;
	y = py;
	
	age = 0;
	dead = false;
	//maxAge = ofRandom(0, 50)+250;
    maxAge=250;
}
void Particle::update()
{
    
    if(y<ofGetViewportHeight()){
        y=y+ofRandomf()*10;
    }
	age++;
    if (age >= maxAge) dead = true;
}

void Particle::draw(int pr,int pg ,int pb)
{
    r=pr;
    g=pg;
    b=pb;
	//ofSetColor(pr,pg,pb);
	//ofCircle(x, y, 3);
}