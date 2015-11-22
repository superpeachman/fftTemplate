#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /*--------------------------------------------------------------
     
     
     FFT
     
     
     --------------------------------------------------------------*/
    buffer_size = fft_size * 2;
    left = new float[buffer_size];
    magnitudeL = new float[fft_size];
    phaseL = new float[fft_size];
    powerL = new float[fft_size];
    right = new float[buffer_size];
    magnitudeR = new float[fft_size];
    phaseR = new float[fft_size];
    powerR = new float[fft_size];
    ofSoundStreamSetup(0, 2, this, 44100, buffer_size, 4);
    tempL = new float[fft_size];
    tempR = new float[fft_size];
    for (int i = 0; i < fft_size; i++) {
        tempL[i] = 0.0f;
        tempR[i] = 0.0f;
    }
    
    gapTime = 0;
    curTime = 0;
    preTime = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    /*--------------------------------------------------------------
     
     
     FFT
     
     
     --------------------------------------------------------------*/
    curTime = ofGetElapsedTimef();
    gapTime = curTime - preTime;
    gapTime = ofClamp(gapTime, 0.0f, 1.0f);
    preTime = curTime;
    avg_powerL = 0.0;
    avg_powerR = 0.0;
    max_tempL = 0.0;
    max_tempR = 0.0;
    myfft.powerSpectrum(0, fft_size, left, buffer_size,	magnitudeL, phaseL, powerL, &max_magL, &avg_powerL);
    myfft.powerSpectrum(0, fft_size, right, buffer_size, magnitudeR, phaseR, powerR, &max_magR, &avg_powerR);
    
    for (int i = 0; i < fft_size; i++) {
        tempL[i] *= 0.97f;
        tempR[i] *= 0.97f;
        tempL[i] = max(magnitudeL[i], tempL[i])*gapTime;
        tempR[i] = max(magnitudeR[i], tempR[i])*gapTime;
        if(max_tempL < tempL[i]) max_tempL = tempL[i];
        if(max_tempR < tempR[i]) max_tempR = tempR[i];
        //printf("tempL %f \n", tempL[i]);
        //printf("tempR %f \n", tempR[i]);
    }
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    for (int i = 0; i < bufferSize; i++){
        left[i] = input[i*2];
        right[i] = input[i*2+1];
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

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
