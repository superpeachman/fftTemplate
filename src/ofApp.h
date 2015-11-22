#pragma once

#include "ofMain.h"
#include "fft.h"

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    private:
    /*--------------------------------------------------------------
     
     
     FFT
     
     
     --------------------------------------------------------------*/
    static const int fft_size = 2048;
    ofSoundStream soundStream;
    void audioIn(float* input, int bufferSize, int nChannels);
    
    float *left, *right;
    float *magnitudeL, *phaseL, *powerL, *tempL;
    float *magnitudeR, *phaseR, *powerR, *tempR;
    float max_tempL, max_tempR, max_magL, max_magR, avg_powerL, avg_powerR;
    int buffer_size;
    class fft myfft;
    
    float preTime, curTime, gapTime;
		
};
