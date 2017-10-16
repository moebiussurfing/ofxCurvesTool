#pragma once

#include "ofMain.h"

#include "ofxCurvesTool.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	
	ofxCurvesTool curvesTool;
	ofImage img;
	bool show;
    
    float cnt = 0;
    int amount = amount;
};
