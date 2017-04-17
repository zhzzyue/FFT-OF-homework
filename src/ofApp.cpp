#include "ofApp.h"

float x, y, angle = 0;



//--------------------------------------------------------------
void ofApp::setup(){
//    fbo.allocate(400, 400, GL_RGBA);
    
    song.load("Upbeat Pop Background Music - Party Time!.mp3");
    while (! song.isLoaded()); // spin wheels till loaded
    nBandsToGet = 512;  // up to 512
    
    fftSmoothed = new float[8192];
    for (int i = 0; i < 8192; i++){
        fftSmoothed[i] = 0;
    }
    
    val = ofSoundGetSpectrum(nBandsToGet);// request 6 values for fft
    for (int i = 0;i < nBandsToGet; i++){
        fftSmoothed[i] *= 0.96f;
        if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
    }

        song.play();

}

//--------------------------------------------------------------
void ofApp::update(){

    ofSoundUpdate();
    val = ofSoundGetSpectrum(nBandsToGet);
    for (int i = 0;i < nBandsToGet; i++){
        fftSmoothed[i] *= 0.96f;
        if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
    }
    cout << ofToString(fftSmoothed[0]*20) << endl;
//    ofBackground(0x23,0x32,0x37);
    
    // update the sound playing system:
    // ofSoundUpdate();
    
    val = ofSoundGetSpectrum(nBandsToGet);  // get array of floats (1 for each band)
    
//    for (int i = 0;i < nBandsToGet; i++){
//        color = val[i];
//            
//        }
    
    ofBackground(0x23,fftSmoothed[1]*100,fftSmoothed[0]*100);
    
    for (int i = 0;i < nBandsToGet; i++){
        
        // let the smoothed value sink to zero:
        fftSmoothed[i] *= 0.96f;
        
        // take the max, either the smoothed or the incoming:
        if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
        
    }
}


//float getX (int deg, int radius) {
//    float x = radius * cos(ofDegToRad(deg)) + ofGetWidth()/2;
//    return (x);
//}
//
//float getY (int deg, int radius) {
//    float y = radius * sin(ofDegToRad(deg)) + ofGetHeight()/2;
//    return (y);


//}

//--------------------------------------------------------------
void ofApp::draw(){
//    int r = 100;  // radius
//    
//    x = r * cos( ofDegToRad(angle) ) + ofGetWidth()/2;
//    y = r * sin( ofDegToRad(angle) ) + ofGetHeight()/2;
//    
//    angle -= 1;
//    if (angle >= 360) angle = 0; //TWO_PI
    
    
    // do this one last
//    ofSetColor(255, 0, 0);
//    ofCircle(x, y, 20);

    
    // draw the fft results:
//    ofSetColor(0x98,0x4b,0x43,255);
    
    // cos & sin take RADIANS.
    // 2pi radians would be 2 x 57.2958 x 3.1416 = 360 degrees
    // Therefore to draw a whole circle you would use 0-TWO_PI to draw a whole circle
//    
//    for (int i = 0;i < nBandsToGet; i++){
//        float x1 = getX(i, r);
//        float y1 = getY(i, r);
//        float x2 = getX(i, r + 2000 * val[i/8]);  // up to 2k larger (theoretically) but it will never get even close
//        float y2 = getY(i, r + 2000 * val[i/8]);
//        ofDrawLine (x1, y1, x2, y2);  // we only care about bottom 8th of the spectrum
//        
//    }
    for (int i = nBandsToGet/2; i < nBandsToGet; i++){
        //(we use negative height here, because we want to flip them
        //because the top corner is 0,0)
    

        ofSetColor(0x98,0x4b,0x43, i);
        ofDrawCircle(ofGetWindowWidth()/2,ofGetWindowHeight()/2, (1*val[i])*800);

    }
    
    for (int i = 0; i < nBandsToGet/2; i++){
        //(we use negative height here, because we want to flip them
        //because the top corner is 0,0)
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofPushMatrix();
        ofTranslate(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
        ofRotateZ(i);
        ofSetColor(255, 255, 255);
        ofRect(0,0,400+(1*val[i])*80,400+(1*val[i])*80);
        ofNoFill();
        ofSetColor(i/2, 144, i/2);
        ofRect(0,0,100+(1*val[i])*400,100+(1*val[i])*400);
        ofPopMatrix();
    }
    
   


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
