#pragma once

#include "ofMain.h"
#include "Particle.h"
#define size 2000
class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    ofVideoPlayer myPlayer;
    ofPixels pix;
   
    int bpp =3;
    ofTexture myTexture;
    Particle* p[size];
    int particleCount=0;
    int myFrame=0;
    int dir=1;
    ofTrueTypeFont	verdana14;
    string typeStr1="Press SPACE = Reverse video.";
    string typeStr2="Press UP = Play quickly";
    string typeStr3="Press DOWN = Play slowly";
    

};
