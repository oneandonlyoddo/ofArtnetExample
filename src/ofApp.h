#pragma once

#include "ofMain.h"
#include "ofxArtnet.h"
#include "ofxGui.h"
#include "constants.h"



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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    
    
    ofxArtnet artnet;
    unsigned char dmxData[NUM_OF_CHANNELS];
    
    ofxPanel gui;
    
    vector <ofxIntSlider*> slider;
    
    
    ofxToggle sendData;
    
    vector <string> channelNames;
    
    
		
};
