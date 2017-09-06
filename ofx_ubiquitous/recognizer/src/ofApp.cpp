#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    receiver.setup(8000);
    sender.setup("127.0.0.1",57120);
    
  //  videoGrabber.setDeviceID(0);
  //  videoGrabber.initGrabber(640, 480);
}

//--------------------------------------------------------------
void ofApp::update(){
  //  videoGrabber.update();
    while( receiver.hasWaitingMessages() )
    {
        //次のメッセージを取得
        cout << "recieveOSC" << endl;
        /*unsigned char *pix= videoGrabber.getPixels();
        ofImage img;
        img.setFromPixels(pix, 640, 480, OF_IMAGE_COLOR);
        img.saveImage("/Users/Ishikawa/recognize/test.jpg");*/

        
                
        ofxOscMessage m;
        receiver.getNextMessage( &m );
         if(m.getAddress() == "/reset"){
                ofxOscMessage mess;
                mess.setAddress("/reset");
                mess.addStringArg(".jpg");
                sender.sendMessage(mess);
        
        }
        
       // else{
        string filename = m.getArgAsString(0);
        cout << "filename == " << filename << endl;
        string command1 = "python /Users/Ishikawa/facepp-python-sdk/cam1Recognize.py "+filename;
        string command2 = "python /Users/Ishikawa/facepp-python-sdk/cam2Recognize.py "+filename;
        string command3 = "python /Users/Ishikawa/facepp-python-sdk/cam3Recognize.py "+filename;
        string command4 = "python /Users/Ishikawa/facepp-python-sdk/cam4Recognize.py "+filename;
        string command5 = "python /Users/Ishikawa/facepp-python-sdk/cam5Recognize.py "+filename;
        string command6 = "python /Users/Ishikawa/facepp-python-sdk/cam6Recognize.py "+filename;
        string command7 = "python /Users/Ishikawa/facepp-python-sdk/cam7Recognize.py "+filename;
        string command8 = "python /Users/Ishikawa/facepp-python-sdk/cam8Recognize.py "+filename;
        //string command9 = "python /Users/Ishikawa/facepp-python-sdk/cam9Recognize.py "+filename;
        
        string command = command1+" & "+command2+" & "+command3+" & "+command4+" & "+command5+" & "+command6+" & "+command7+" & "+command8;
        
       // string comand = "python /Users/Ishikawa/facepp-python-sdk/OSCtest.py";
        system(command.c_str());
        }
        
    
    }
//}

//--------------------------------------------------------------
void ofApp::draw(){
   // videoGrabber.draw(0, 0, 320, 240);
}

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
