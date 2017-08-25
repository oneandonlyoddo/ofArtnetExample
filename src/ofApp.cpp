#include "ofApp.h"
#include "constants.h"

//--------------------------------------------------------------
void ofApp::setup(){
    artnet.setup("10.7.171.50");
    gui.setup("slider");
    gui2.setup("fade");
    
    for (int i = 0; i < NUM_OF_CHANNELS; i++ ){
        channelNames.push_back("channel "+std::to_string(i));
        fadeUp.push_back(true);
    }
    
    channelNames[0] = "Lamp on off";
    channelNames[1] = "Shutter Speed";
    channelNames[2] = "Shutter Controll";
    channelNames[3] = "Focus Speed";
    channelNames[4] = "Focus";
    
    //196 shutter max?!
    //200 focus max
    
    /*
     shutter speed 5 full open 11.7s
     shutter speed 255 full open 1.3s
     */
    
    
    for (int i = 0; i < NUM_OF_CHANNELS; i++ ){
        ofxIntSlider* sl = new ofxIntSlider();
        gui.add(sl->setup(channelNames[i], 0, 0, 255));
        slider.push_back(sl);
        dmxData[i] = 0;
        ofxToggle* toggle = new ofxToggle();
        gui2.add(toggle->setup("fade"+ std::to_string(i),false ));
        toggles.push_back(toggle);
    }
    
    gui2.setPosition(gui.getPosition().x *2 + gui.getWidth(), gui.getPosition().y);
    
    
    
    gui.add(sendData.setup("Send Data", false));
    
    
    ofSetWindowShape(gui.getPosition().x *4 + gui.getWidth()*2, gui.getPosition().y*2 + gui.getHeight());
   
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < NUM_OF_CHANNELS; i++ ){
        dmxData[i] = *slider[i];
        if (*toggles[i]){
            if(fadeUp[i]){
                if(*slider[i]<255){
                    *slider[i] = *slider[i]+1;
                }else{
                    fadeUp[i] = false;
                }
                
            } else{
                if(*slider[i]>0){
                    *slider[i] = *slider[i]-1;
                }else{
                    fadeUp[i] = true;
                }
            }
            
        }
    }
    
    if (sendData){
        artnet.sendDmx(ADAPTER_ADRESS, dmxData, NUM_OF_CHANNELS);
    }
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    gui.draw();
    gui2.draw();
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
