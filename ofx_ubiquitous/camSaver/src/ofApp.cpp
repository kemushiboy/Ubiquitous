#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  //  ofHttpResponse resp = ofLoadURL("http://www.google.com/robots.txt");
  //  cout << resp.data << endl;
   
  //  ofSetFrameRate(15);
    frameNum = 0;
//    drawFrame = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    cout << "start frame" << frameNum << endl;
   // image.loadImage("http://172.32.3.83:8080/?action=snapshot");
    //image.loadImage("http://www.extremetech.com/wp-content/uploads/2014/02/webcam.jpg");
    image.loadImage("http://172.32.3.111:8080/?action=snapshot");
  //  image2.loadImage("http://192.168.0.107:8080/?action=snapshot");
 //   image3.loadImage("http://192.168.0.104:8080/?action=snapshot");

    
    cout << "loaded" << endl;
   //    image.loadImage("http://2.imimg.com/data2/HU/VH/MY-2937582/microsoft-web-cam-live-studio-500x500.jpg");
    // for(int i=0; i<camNum; i++){
    image.rotate90(2);
     image.saveImage("/Users/Ishikawa/cam1/" + ofToString(frameNum) +".jpg");
  //  image2.saveImage("/Users/Ishikawa/cam2/" + ofToString(frameNum) +".jpg");
 //   image3.saveImage("/Users/Ishikawa/cam3/" + ofToString(frameNum) +".jpg");
    
    
    //     cout << "save" << endl;}
    
    
    
    

  //  image.loadImage("http://192.168.0.103:8080/?action=snapshot");
 //    image.saveImage("/Users/Ishikawa/cam2/" + ofToString(frameNum) +".jpg");
 //   image.loadImage("http://192.168.0.104:8080/?action=snapshot");
 //    image.saveImage("/Users/Ishikawa/cam3/" + ofToString(frameNum) +".jpg");

    
    //images.push_back(image);
   // FileLoader.saveTo("http://192.168.11.12:8080/?action=stream", "Users/Ishikawa/cam1/ .jpg");
    
//    switch (playmode){
//        case 0:
//            drawFrame = frameNum;
//            break;
//            
//        case 1:
//            break;
//            
//        { case 2:
//            drawFrame-=3;
//            if(drawFrame < 0)
//                drawFrame = 0;
//            break;
//        }
//            
//        {case 3:
//            drawFrame+=3;
//            if(drawFrame > frameNum)
//                drawFrame = frameNum;
//            break;
//        }
//            
//    }
  
    
    frameNum++;
}

//--------------------------------------------------------------
void ofApp::draw(){
 //   image.draw(0,0);
//     drawImage.loadImage("test/" + ofToString(drawFrame) +".jpg");
//    drawImage.draw(0, 0);
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//    switch (key) {
//        {  case 's':
//            playmode = 1;
//            drawFrame = frameNum;
//            break;
//        }
//    
//        {  case 'p':
//            playmode = 0;
//            break;
//        }
//           
//        { case 'r':
//            playmode = 2;
//            break;
//        }
//            
//        {   case 'f':
//            playmode = 3;
//            break;
//        }
//            
//        {default:
//            break;}
//    }
//    

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

   // FileLoader.saveTo("http://192.168.11.12:8080/?action=stream", "test.jpeg");
   // FileLoader.get("http://192.168.11.12:8080/?action=stream");

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
