#include "ofApp.h"

// add saving and loading

void ofApp::setup() {
    ofSetVerticalSync(true);
    curvesTool.setup();
    amount = 256;
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
    
    cnt++;
    cnt %= amount;
    
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
