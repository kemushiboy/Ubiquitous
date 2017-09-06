#include "ofApp.h"
using namespace ofxCv;
using namespace cv;


//--------------------------------------------------------------
void ofApp::setup(){
  //  ofSetFrameRate(10);
    frameNum = 0;
   // cam.setDeviceID(0);
   // cam.initGrabber(640, 480);
    
    // imitate() will set up previous and diff
	// so they have the same size and type as cam
	//imitate(previous, image);
	//imitate(diff, image);
    image.loadImage(ofToString(frameNum) + ".jpg");
    copy(image, previous);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    curMax = 0;
   // image.loadImage(ofToString(frameNum) + ".jpg");
    
    while(image.loadImage(ofToString(frameNum) + ".jpg")){
        curMax = 0;
       // if(image.loadImage(ofToString(frameNum+3000) + ".jpg")){
       //     frameNum += 3000;
       //     copy(image, previous);
       //     break;
       // }
    	// take the absolute difference of prev and cam and save it inside diff
		absdiff(previous, image, diff);
        copy(image, previous);
		diff.update();
		
		// like ofSetPixels, but more concise and cross-toolkit
		//copy(image, previous);
		
		// this is the key line: get the average of each column
		columnMean = meanCols(diff);
        
        for(int k = 0; k < 3; k++) {
            // use the correct color for each channel
            switch(k) {
                    case 0: ofSetColor(ofColor::red); break;
                    case 1: ofSetColor(ofColor::blue); break;
                    case 2: ofSetColor(ofColor::green); break;
            }
            
            for(int i = 0; i < columnMean.rows; i++) {
                // Vec3b is one way of storing 24-bit (3 byte) colors
                Vec3b cur = columnMean.at<Vec3b>(i);
                if(cur[k]>curMax){
                    curMax = cur[k];
                }
            }
        }
        
        if(curMax > 50){
            string comand = "python /Users/Ishikawa/facepp-python-sdk/cam1.py " +ofToString(frameNum) + ".jpg";
            system(comand.c_str());
            
        }
        cout << curMax << endl;
        frameNum++;
    }
    
    
}

//--------------------------------------------------------------
/*void ofApp::draw(){
    ofSetColor(255);
	//cam.draw(0, 0);
	
	//ofTranslate(320, 0);
	diff.draw(0, 0);
	// draw the mean for each channel
   
    ofDrawBitmapString(ofToString(curMax), 10, 480);
    if(curMax > 30){
        ofImage img;
        unsigned char *pix= cam.getPixels();
        img.setFromPixels(pix, 640, 480, OF_IMAGE_COLOR);
        string PictureName = ofGetTimestampString() + "_1";
        //img.saveImage(PictureName + ".jpg");
        img.saveImage("/Users/Ishikawa/test/" +PictureName + ".jpg");
        cout << "captured!" << endl;
        
        string comand = "python /Users/Ishikawa/facepp-python-sdk/cam1.py /Users/Ishikawa/test/" +PictureName + ".jpg";
        system(comand.c_str());
    }
    
}*/

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
