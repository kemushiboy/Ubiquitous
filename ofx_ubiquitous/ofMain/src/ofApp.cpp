#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //  ofHttpResponse resp = ofLoadURL("http://www.google.com/robots.txt");
    //  cout << resp.data << endl;
    
    ofSetFrameRate(60);
    frameNum1 = 0;
    frameNum2 = 0;
    frameNum3 = 0;
    frameNum4=0,frameNum5,frameNum6,frameNum7,frameNum8,frameNum9 = 0;
    for(int i=0; i<camNum; i++){
        frameNums.push_back(0);
    }
    drawFrame1 = 5;
    drawFrame2 = 5;
    drawFrame3 = 5;
    drawFrame4,drawFrame5,drawFrame6,drawFrame7,drawFrame8,drawFrame9 = 5;
    
    searchedFrame1 = 0;
    searchedFrame2 = 0;
    searchedFrame3 = 0;
    searchedFrame4,searchedFrame5,searchedFrame6,searchedFrame7,searchedFrame8,searchedFrame9 = 0;
    
    
    loopSec1 = 0;
     loopSec2 = 0;
     loopSec3 = 0;
    loopSec4,loopSec5,loopSec6,loopSec7,loopSec8,loopSec9 = 0;
    
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
    
    while(file.doesFileExist("/Users/Ishikawa/cam2/" + ofToString(frameNum2) +".jpg") || file.doesFileExist("/Users/Ishikawa/cam2/" + ofToString(frameNum2+100) +".jpg")){
        frameNum2++;
    }
    
    while(file.doesFileExist("/Users/Ishikawa/cam3/" + ofToString(frameNum3) +".jpg")|| file.doesFileExist("/Users/Ishikawa/cam3/" + ofToString(frameNum3+100) +".jpg")){
        frameNum3++;
    }
    while(file.doesFileExist("/Users/Ishikawa/cam4/" + ofToString(frameNum4) +".jpg")|| file.doesFileExist("/Users/Ishikawa/cam4/" + ofToString(frameNum4+100) +".jpg")){
        frameNum4++;
    }
    while(file.doesFileExist("/Users/Ishikawa/cam5/" + ofToString(frameNum5) +".jpg")|| file.doesFileExist("/Users/Ishikawa/cam5/" + ofToString(frameNum5+100) +".jpg")){
        frameNum5++;
    }
    while(file.doesFileExist("/Users/Ishikawa/cam6/" + ofToString(frameNum6) +".jpg")|| file.doesFileExist("/Users/Ishikawa/cam6/" + ofToString(frameNum6+100) +".jpg")){
        frameNum6++;
    }
    while(file.doesFileExist("/Users/Ishikawa/cam7/" + ofToString(frameNum7) +".jpg")|| file.doesFileExist("/Users/Ishikawa/cam7/" + ofToString(frameNum7+100) +".jpg")){
        frameNum7++;
    }
    while(file.doesFileExist("/Users/Ishikawa/cam8/" + ofToString(frameNum8) +".jpg")|| file.doesFileExist("/Users/Ishikawa/cam8/" + ofToString(frameNum8+100) +".jpg")){
        frameNum8++;
    }
    while(file.doesFileExist("/Users/Ishikawa/cam9/" + ofToString(frameNum9) +".jpg")|| file.doesFileExist("/Users/Ishikawa/cam9/" + ofToString(frameNum9+100) +".jpg")){
        frameNum9++;
    }

    frameNum1--;
    frameNum2--;
    frameNum3--;
    frameNum4--;
    frameNum5--;
    frameNum6--;
    frameNum7--;
    frameNum8--;
    frameNum9--;
    
    
    
    if(playmode == 0){
//        for(int i=0; i<camNum; i++){/Users/Ishikawa/cam1
//            ofImage tempImg;
//            tempImg.loadImage("/Users/Ishikawa/cam" + ofToString(i+1) + "/" + ofToString(frameNums[i]) +".jpg");
//            images.push_back(tempImg);
//        }
        
        
        
        image1.loadImage("/Users/Ishikawa/cam1/" + ofToString(frameNum1-5) +".jpg");
        image2.loadImage("/Users/Ishikawa/cam2/" + ofToString(frameNum2-5) +".jpg");
        image3.loadImage("/Users/Ishikawa/cam3/" + ofToString(frameNum3-5) +".jpg");
        image4.loadImage("/Users/Ishikawa/cam4/" + ofToString(frameNum4-5) +".jpg");
        image5.loadImage("/Users/Ishikawa/cam5/" + ofToString(frameNum5-5) +".jpg");
        image6.loadImage("/Users/Ishikawa/cam6/" + ofToString(frameNum6-5) +".jpg");
        image7.loadImage("/Users/Ishikawa/cam7/" + ofToString(frameNum7-5) +".jpg");
        image8.loadImage("/Users/Ishikawa/cam8/" + ofToString(frameNum8-5) +".jpg");
        image9.loadImage("/Users/Ishikawa/cam9/" + ofToString(frameNum9-5) +".jpg");
    
    }
    
    
    
    if(playmode == 1){
        timer++;
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
        
        if(searchedFrame4 >0){
            drawFrame4 -= ((frameNum4 - searchedFrame4)/100);
        }
        else{
            drawFrame4 = frameNum4-5;
        }
        
        if(searchedFrame5 >0){
            drawFrame5 -= ((frameNum5 - searchedFrame5)/100);
        }
        else{
            drawFrame5 = frameNum5-5;
        }
        
        if(searchedFrame6 >0){
            drawFrame6 -= ((frameNum6 - searchedFrame6)/100);
        }
        else{
            drawFrame6 = frameNum6-5;
        }
        
        if(searchedFrame7 >0){
            drawFrame7 -= ((frameNum7 - searchedFrame7)/100);
        }
        else{
            drawFrame7 = frameNum7-5;
        }
        
        if(searchedFrame8 >0){
            drawFrame8 -= ((frameNum8 - searchedFrame8)/100);
        }
        else{
            drawFrame8 = frameNum8-5;
        }
        
        if(searchedFrame9 >0){
            drawFrame9 -= ((frameNum9 - searchedFrame9)/100);
        }
        else{
            drawFrame9 = frameNum9-5;
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
        
        if(drawFrame4 -loopSec4 < searchedFrame4){
            drawFrame4 = searchedFrame4+loopSec4;
            loopSec4 += 0.25;
            if(loopSec4 > 15)
            loopSec4 = -15;
        }
        
        if(drawFrame5 -loopSec5 < searchedFrame5){
            drawFrame5 = searchedFrame5+loopSec5;
            loopSec5 += 0.25;
            if(loopSec5 > 15)
            loopSec5 = -15;
        }
        
        if(drawFrame6 -loopSec6 < searchedFrame6){
            drawFrame6 = searchedFrame6+loopSec6;
            loopSec6 += 0.25;
            if(loopSec6 > 15)
            loopSec6 = -15;
        }
        
        if(drawFrame7 -loopSec7 < searchedFrame7){
            drawFrame7 = searchedFrame7+loopSec7;
            loopSec7 += 0.25;
            if(loopSec7 > 15)
            loopSec7 = -15;
        }
        
        if(drawFrame8 -loopSec8 < searchedFrame8){
            drawFrame8 = searchedFrame8+loopSec8;
            loopSec8 += 0.25;
            if(loopSec8 > 15)
            loopSec8 = -15;
        }
        
        if(drawFrame9 -loopSec9 < searchedFrame9){
            drawFrame9 = searchedFrame9+loopSec9;
            loopSec9 += 0.25;
            if(loopSec9 > 15)
            loopSec9 = -15;
        }
        
        image1.loadImage("/Users/Ishikawa/cam1/" + ofToString(drawFrame1) +".jpg");
        image2.loadImage("/Users/Ishikawa/cam2/" + ofToString(drawFrame2) +".jpg");
        image3.loadImage("/Users/Ishikawa/cam3/" + ofToString(drawFrame3) +".jpg");
        image4.loadImage("/Users/Ishikawa/cam4/" + ofToString(drawFrame4) +".jpg");
        image5.loadImage("/Users/Ishikawa/cam5/" + ofToString(drawFrame5) +".jpg");
        image6.loadImage("/Users/Ishikawa/cam6/" + ofToString(drawFrame6) +".jpg");
        image7.loadImage("/Users/Ishikawa/cam7/" + ofToString(drawFrame7) +".jpg");
        image8.loadImage("/Users/Ishikawa/cam8/" + ofToString(drawFrame8) +".jpg");
        image9.loadImage("/Users/Ishikawa/cam9/" + ofToString(drawFrame9) +".jpg");
        
        if(timer > 60*30){
            playmode = 0;
            searchedFrame1 = 0;
            searchedFrame2 = 0;
            searchedFrame3 = 0;
            searchedFrame4 = 0;
            searchedFrame5 = 0;
            searchedFrame6 = 0;
            searchedFrame7 = 0;
            searchedFrame8 = 0;
            searchedFrame9 = 0;
            timer = 0;
        }
        
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
        
        else if(m.getAddress() == "/cam4recognize"){
            searchedFrame4 = ofToInt(m.getArgAsString(0));
            drawFrame4 = frameNum4;
        }
        
        else if(m.getAddress() == "/cam5recognize"){
            searchedFrame5 = ofToInt(m.getArgAsString(0));
            drawFrame5 = frameNum5;
        }
        
        else if(m.getAddress() == "/cam6recognize"){
            searchedFrame6 = ofToInt(m.getArgAsString(0));
            drawFrame6 = frameNum6;
        }
        
        else if(m.getAddress() == "/cam7recognize"){
            searchedFrame7 = ofToInt(m.getArgAsString(0));
            drawFrame7 = frameNum7;
        }
        
        else if(m.getAddress() == "/cam8recognize"){
            searchedFrame8 = ofToInt(m.getArgAsString(0));
            drawFrame8 = frameNum8;
        }
        
        else if(m.getAddress() == "/cam9recognize"){
            searchedFrame9 = ofToInt(m.getArgAsString(0));
            drawFrame9 = frameNum9;
        }
        else if(m.getAddress() == "/reset"){
            playmode = 0;
            searchedFrame1 = 0;
            searchedFrame2 = 0;
            searchedFrame3 = 0;
            searchedFrame4 = 0;
            searchedFrame5 = 0;
            searchedFrame6 = 0;
            searchedFrame7 = 0;
            searchedFrame8 = 0;
            searchedFrame9 = 0;
            cout << "reset ";
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
    
    
    
    
    image1.draw(0,0, 640, 360);
    image2.draw(640,0, 640, 360);
    image3.draw(640*2,0, 640, 360);
    image4.draw(0,360, 640, 360);
    image5.draw(640,360, 640, 360);
    image6.draw(640*2,360, 640, 360);
    image7.draw(0,360*2, 640, 360);
    image9.draw(640*2,360*2, -640, 360);
    image8.draw(640*2,360*2, 640, 360);
    
    
    
    
    
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
            m.addStringArg(ofToString(frameNum9) + ".jpg");
            sender.sendMessage(m);
            
//            drawFrame1 = frameNum1;
//            drawFrame2 = frameNum2;
//            drawFrame3 = frameNum3;
            cout << "sendOSC" << endl;
            break;
            
        }
            
        {   case '0':
            playmode = 0;
            searchedFrame1 = 0;
            searchedFrame2 = 0;
            searchedFrame3 = 0;
            searchedFrame4 = 0;
            searchedFrame5 = 0;
            searchedFrame6 = 0;
            searchedFrame7 = 0;
            searchedFrame8 = 0;
            searchedFrame9 = 0;
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
