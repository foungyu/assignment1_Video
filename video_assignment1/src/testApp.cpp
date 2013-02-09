#include "testApp.h"
#include "ofMain.h"
#define pixelElement 5
#define playerW 480
#define playerH 270
#define stageW 800
#define stageH 540
#define tx 8
#define ty 9
//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0,0,0);
    myPlayer.loadMovie("video_1.mp4");
    //myPlayer.loadMovie("video_1.mov"); //Loads video resources
    myPlayer.play();
    myPlayer.setLoopState(OF_LOOP_NONE);
    
    /*ofTrueTypeFont::setGlobalDpi(72);
    
	verdana14.loadFont("verdana.ttf", 14, true, true);
	verdana14.setLineHeight(18.0f);
	verdana14.setLetterSpacing(1.037);
*/
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    //ofSetColor(225,0,0);
	//verdana14.drawString("Font Example - use keyboard to type", 30, 35);

    ofSetColor(255,255,255);

    //myPlayer.update();
    //float videoPos=myPlayer.getPosition();
    //myPlayer.setPosition(videoPos);
    myFrame+=dir;
    if(myFrame>myPlayer.getTotalNumFrames()){
        myFrame=0;
    }else if(myFrame<0){
        myFrame=myPlayer.getTotalNumFrames();
    }
    myPlayer.setFrame(myFrame);
    myPlayer.update();
    myPlayer.draw(0, 0,240,135);
    
    unsigned char * pixels = myPlayer.getPixels();
    int diameter=1;
    int count=0;
    int radius=1;
    int addColorR=0;
    int addColorG=0;
    int addColorB=0;
    
    int countColor=0;
    countColor++;
    bool changeColor=false;
    if(countColor%50){
        changeColor=true;
    }
    for (int i = 0; i < playerW; i++){
        for (int j = 0; j < playerH; j++){
            float cRed;
            float cGreen;
            float cBlue;
            if(i%pixelElement==0&&j%pixelElement==0){
                if(bpp >= 3){
                    cRed = pixels[(j*playerW+i)*bpp+0];
                    cGreen = pixels[(j*playerW+i)*bpp+1];
                    cBlue = pixels[(j*playerW+i)*bpp+2];
                    if(bpp >= 4){
                        float cAlpha = pixels[(j*playerW+i)*bpp+3];
                    }
                }else if(bpp == 1){
                    float cGray = pixels[(j*playerW+i)];
                }
                count++;
                
                float origX=int(i/pixelElement)*tx;
                float origY=int(j/pixelElement)*ty;
                float disX=mouseX-origX;
                float disY=mouseY-origY;
                float targetX;
                float targetY;
                float dis=sqrt(disX*disX+disY*disY);
                if(int(cRed)!=0&&int(cGreen)!=0&&int(cBlue)!=0){
                /*if(changeColor==true){
                    ofSetColor(int(cRed)+ofRandomf()*200,int(cGreen),int(cBlue));
                    changeColor=false;
                }else{
                    ofSetColor(int(cRed),int(cGreen),int(cBlue));
                    
                 }*/
                ofSetColor(int(cRed)+ofRandomf()*200,int(cGreen),int(cBlue),10);
                
                targetX=origX;
                targetY=origY+sqrt(disY*disY);
                targetY=origY;
                /*if(dis<40){
                    targetX=playerW;
                    targetY=playerH;
                }else{*/
                    targetX=origX+dis*0.5;
                    targetY=origY;
                //}
                ofCircle(targetX+240,targetY,2);
                //ofLogNotice()<<dis;
                }
            }
        }
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key==' ') {
        dir*=-1;
    }else if (key == OF_KEY_UP){
         dir+=1;
    }else if (key == OF_KEY_DOWN){
        dir-=1;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}