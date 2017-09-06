#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //  ofHttpResponse resp = ofLoadURL("http://www.google.com/robots.txt");
    //  cout << resp.data << endl;
    
    ofSetFrameRate(30);
    frameNum1 = 0;
    frameNum2 = 0;
    frameNum3 = 0;
    frameNum4,frameNum5,frameNum6,frameNum7,frameNum8,frameNum9 = 0;
    for(int i=0; i<camNum; i++){
        frameNums.push_back(0);
    }
    drawFrame1 = 5;
    drawFrame2 = 5;
    drawFrame3 = 5;
    
    searchedFrame1 = 0;
    searchedFrame2 = 0;
    searchedFrame3 = 0;
    
    loopSec1 = 0;
     loopSec2 = 0;
     loopSec3 = 0;
    
    playmode = 0;
    receiver.setup( 57120 );
    sender.setup("127.0.0.1", 8000);
   // videoGrabber.setDeviceID(0);
  //  videoGrabber.initGrabber(320, 240);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //images.push_back(image);
    // FileLoader.saveTo("http://192.168.11.12:8080/?action=stream", "test.jpg");
    
    ofFile file;
    
  //  for(int i=0; i<camNum; i++){
  //      while(file.doesFileExist("/Users/Ishikawa/cam" +ofToString(1+i) + "/" + ofToString(frameNums[i]) +".jpg")){
  //          frameNums[i]++;
  //      }
  //      frameNums[i]--;
  //  }
    
    while(file.doesFileExist("/Users/Ishikawa/cam1/" + ofToString(frameNum1) +".jpg") || file.doesFileExist("/Users/Ishikawa/cam1/" + ofToString(frameNum1+100) +".jpg") ){
              frameNum1++;
          }
   // cout << frameNum1<< endl;
    
  while(file.doesFileExist("/Users/Ishikawa/cam2/" + ofToString(frameNum2) +".jpg")){
        frameNum2++;
    }
    
    while(file.doesFileExist("/Users/Ishikawa/cam3/" + ofToString(frameNum3) +".jpg")){
        frameNum3++;
    }
/*    while(file.doesFileExist("/Users/Ishikawa/cam4/" + ofToString(frameNum4) +".jpg")){
        frameNum4++;
    }
    while(file.doesFileExist("/Users/Ishikawa/cam5/" + ofToString(frameNum5) +".jpg")){
        frameNum5++;
    }
    while(file.doesFileExist("/Users/Ishikawa/cam6/" + ofToString(frameNum6) +".jpg")){
        frameNum6++;
    }
    while(file.doesFileExist("/Users/Ishikawa/cam7/" + ofToString(frameNum7) +".jpg")){
        frameNum7++;
    }
    while(file.doesFileExist("/Users/Ishikawa/cam8/" + ofToString(frameNum8) +".jpg")){
        frameNum8++;
    }
    while(file.doesFileExist("/Users/Ishikawa/cam9/" + ofToString(frameNum9) +".jpg")){
        frameNum9++;
    }*/

    frameNum1--;
    frameNum2--;
    frameNum3--;
 /* frameNum4--;
    frameNum5--;
    frameNum6--;
    frameNum7--;
    frameNum8--;
    frameNum9--; */
    
    
    
    if(playmode == 0){
//        for(int i=0; i<camNum; i++){/Users/Ishikawa/cam1
//            ofImage tempImg;
//            tempImg.loadImage("/Users/Ishikawa/cam" + ofToString(i+1) + "/" + ofToString(frameNums[i]) +".jpg");
//            images.push_back(tempImg);
//        }
        
        
        
        image1.loadImage("/Users/Ishikawa/cam1/" + ofToString(frameNum1-5) +".jpg");
        image2.loadImage("/Users/Ishikawa/cam2/" + ofToString(frameNum2-5) +".jpg");
        image3.loadImage("/Users/Ishikawa/cam3/" + ofToString(frameNum3-5) +".jpg");
     /* image4.loadImage("/Users/Ishikawa/cam4/" + ofToString(frameNum4) +".jpg");
        image5.loadImage("/Users/Ishikawa/cam5/" + ofToString(frameNum5) +".jpg");
        image6.loadImage("/Users/Ishikawa/cam6/" + ofToString(frameNum6) +".jpg");
        image7.loadImage("/Users/Ishikawa/cam7/" + ofToString(frameNum7) +".jpg");
        image8.loadImage("/Users/Ishikawa/cam8/" + ofToString(frameNum8) +".jpg");
        image9.loadImage("/Users/Ishikawa/cam9/" + ofToString(frameNum9) +".jpg"); */
    
    }
    
    
    
    if(playmode == 1){
        if(searchedFrame1 >0){
        drawFrame1 -= ((frameNum1 - searchedFrame1)/100);
        }
        else{
            drawFrame1 = frameNum1-5;
        }
        
        if(searchedFrame2 >0){
        drawFrame2 -= ((frameNum2 - searchedFrame2)/100);
        }
        else{
            drawFrame2 = frameNum2-5;
        }
        
    
        if(searchedFrame3 >0){
        drawFrame3 -= ((frameNum3 - searchedFrame3)/100);
        }
        else{
            drawFrame3 = frameNum3-5;
        }
        
        
        if(drawFrame1 -loopSec1 < searchedFrame1){
            drawFrame1 = searchedFrame1+loopSec1;
            loopSec1 += 0.25;
            if(loopSec1 > 15)
                loopSec1 = -15;
        }
        
        if(drawFrame2 -loopSec2 < searchedFrame2){
            drawFrame2 = searchedFrame2+loopSec2;
            loopSec2 += 0.25;
            if(loopSec2 > 15)
                loopSec2 = -15;
        }
        
        if(drawFrame3 -loopSec3 < searchedFrame3){
            drawFrame3 = searchedFrame3+loopSec3;
            loopSec3 += 0.25;
            if(loopSec3 > 15)
                loopSec3 = -15;
        
        }
        
        image1.loadImage("/Users/Ishikawa/cam1/" + ofToString(drawFrame1) +".jpg");
        image2.loadImage("/Users/Ishikawa/cam2/" + ofToString(drawFrame2) +".jpg");
        image3.loadImage("/Users/Ishikawa/cam3/" + ofToString(drawFrame3) +".jpg");
    
    
        
    }
  //  videoGrabber.update();
    
    
    
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
    //
    //    frameNum++;
    
    
    while( receiver.hasWaitingMessages() )
    {
        //次のメッセージを取得
       // cout << "recieveOSCmessage\n\n\n\n\n" << endl;
         playmode = 1;
        ofxOscMessage m;
        receiver.getNextMessage( &m );
        if(m.getAddress() == "/cam1recognize"){
            searchedFrame1 = ofToInt(m.getArgAsString(0));
             drawFrame1 = frameNum1;
        }
        
        else if(m.getAddress() == "/cam2recognize"){
            searchedFrame2 = ofToInt(m.getArgAsString(0));
             drawFrame2 = frameNum2;
        }
        
        else if(m.getAddress() == "/cam3recognize"){
            searchedFrame3 = ofToInt(m.getArgAsString(0));
          drawFrame3 = frameNum3;
        }
        
        cout << "recieve OSC" << endl;
      //  }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
  //  for(int i=0; i<camNum; i++){
  //      images[i].draw(i*480,0,480,360);
  //  }
    
    
    
    
    image1.draw(0,0, 640, 480);
    image2.draw(640,0, 640, 480);
    image3.draw(0,480, 640, 480);
 /*   image4.draw(0,360, 480, 360);
    image5.draw(480,360, 480, 360);
    image6.draw(480*2,360, 480, 360);
    image7.draw(0,360*2, 480, 360);
    image8.draw(480,360*2, 480, 360);
    image9.draw(480*2,360*2, 480, 360);*/
    
    
    
    
    
  //  videoGrabber.draw(640, 480, 640, 480);

    //  drawImage.loadImage("test/" + ofToString(drawFrame) +".jpg");
    //  drawImage.draw(0, 0);
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        {  case 's':
            playmode = 1;
//            drawFrame = frameNum1;
            searchedFrame1 = 0;
            searchedFrame2 = 0;
            searchedFrame3 = 0;
            
            playmode = 1;
            drawFrame1 = frameNum1;
            drawFrame2 = frameNum2;
            drawFrame3 = frameNum3;
            break;
        }
            
         
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
            
        {   case '1':
            
//            unsigned char *pix= videoGrabber.getPixels();
//            ofImage img;
//            img.setFromPixels(pix, 640, 480, OF_IMAGE_COLOR);
//            img.saveImage("/Users/Ishikawa/recognize/" +ofToString(frameNum1) + ".jpg");
            
            ofxOscMessage m;
            m.setAddress("/capture");
            m.addStringArg(ofToString(frameNum1) + ".jpg");
            sender.sendMessage(m);
            
//            drawFrame1 = frameNum1;
//            drawFrame2 = frameNum2;
//            drawFrame3 = frameNum3;
            break;
            
        }
            
        {   case '0':
            playmode = 0;
            searchedFrame1 = 0;
            searchedFrame2 = 0;
            searchedFrame3 = 0;
            break;
        }
    
            
        {default:
            break;}
    }
    
    
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
