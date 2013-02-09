
#include "ofMain.h"

#ifndef assignment1_Video_Particle_h
#define assignment1_Video_Particle_h
class Particle {
    
private:
	float x;
	float y;
    
	int r;
    int g;
    int b;
    int age;
	int maxAge;
    
public:
	Particle(float,float);
    void update();
	void draw(int,int,int);
	bool dead;
};

#endif
