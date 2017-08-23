#include "ofApp.h"
#include "constants.h"

//--------------------------------------------------------------
void ofApp::setup(){
    artnet.setup("10.7.171.50");
    gui.setup();
    
    for (int i = 0; i < NUM_OF_CHANNELS; i++ ){
        channelNames.push_back("channel "+std::to_string(i));
    }
    
    channelNames[0] = "Pan";
    channelNames[2] = "Tilt";
    channelNames[9] = "Dimmer";
    channelNames[8] = "Function";
    channelNames[7] = "Speed";
    channelNames[6] = "Shutter";
    
    
    for (int i = 0; i < NUM_OF_CHANNELS; i++ ){
        ofxIntSlider* sl = new ofxIntSlider();
        gui.add(sl->setup(channelNames[i], 0, 0, 255));
        slider.push_back(sl);
        dmxData[i] = 0;
    }
    
    
    
    gui.add(sendData.setup("Send Data", false));
    
    ofSetWindowShape(gui.getPosition().x *2 + gui.getWidth(), gui.getPosition().y*2 + gui.getHeight());
   
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < NUM_OF_CHANNELS; i++ ){
        dmxData[i] = *slider[i];
    }
    
    if (sendData){
        artnet.sendDmx(ADAPTER_ADRESS, dmxData, NUM_OF_CHANNELS);
    }
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
