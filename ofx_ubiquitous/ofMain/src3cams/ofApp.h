#pragma once

#include "ofMain.h"
#include "ofxOSC.h"
#define camNum 3

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    ofURLFileLoader FileLoader;
    ofImage image1;
    ofImage image2;
    ofImage image3;
    ofImage image4,image5,image6,image7,image8,image9;
    
    ofImage drawImage;
    vector <ofImage> images;
    int frameNum1;
    int frameNum2;
    int frameNum3;
    int frameNum4,frameNum5,frameNum6,frameNum7,frameNum8,frameNum9;
    int drawFrame1;
    int drawFrame2;
    int drawFrame3;
    
    float loopSec1;
    float loopSec2;
    float loopSec3;
    
    vector<int> frameNums;
    
    int playmode;
    
    int searchedFrame1;
    int searchedFrame2;
    int searchedFrame3;
    string faceid1;
    string faceid2;
    string faceid3;
    
    ofFile file1;
    ofFile file2;
    ofFile file3;
    
    ofxOscReceiver receiver;
    ofxOscSender sender;
    ofVideoGrabber videoGrabber;
    
};
