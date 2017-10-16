#include "ofApp.h"

// add saving and loading

void ofApp::setup() {
    ofSetVerticalSync(true);
    
     amount = 256;
    curvesTool.setup(amount);
     curvesTool.load("curves.yml"); //needed because it fills polyline
    
    img.allocate(amount, amount, OF_IMAGE_GRAYSCALE);
    show = true;
    
    cnt = 0;
}  

void ofApp::update() {
    for(int x = 0; x < amount; x++) {
        for(int y = 0; y < amount; y++) {
            img.setColor(x, y, ofColor(curvesTool[x]));
        }
    }
    img.update();
    
    cnt+= 0.1;

    cnt = fmod(cnt,amount);
    
}

void ofApp::draw() {
    ofBackground(0);
    ofTranslate(16, 16);
    if(show) {
        ofSetColor(255);
//        curvesTool.draw();
        curvesTool.draw(0,0,cnt);
        img.draw(amount, 0);
    }
    
    ofSetColor(255,0,0);
    ofDrawLine(0, amount-curvesTool[cnt], ofGetWidth(),amount-curvesTool[cnt]);
    ofDrawCircle(cnt,amount-curvesTool[cnt],3);
    
    float lerp_amt = ofMap(cnt,0,amount-1,0,1);
    ofNoFill();
    ofSetColor(255);

    //--result based on interpolation
    ofPushMatrix();
    ofTranslate(0, amount + 10 );
    float vv = curvesTool.getAt(cnt);
    ofDrawRectangle(0,0,vv,50);
    ofDrawBitmapString(ofToString(vv,2),0,10);
    ofPopMatrix();
    
    //----result based on lut[index]
    ofPushMatrix();
    ofTranslate(0, amount + 60 );
    ofDrawRectangle(0,0,curvesTool[cnt],50);
    ofDrawBitmapString(ofToString(curvesTool[cnt]),0,10);
    ofPopMatrix();
}

void ofApp::keyPressed(int key) {
    if(key == '\t') {
        show = !show;
    }
    if(key == 's') {
        curvesTool.save("curves.yml");
    }
    if(key == 'l') {
        curvesTool.load("curves.yml");
    }
}
