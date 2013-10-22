#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    volume = 0;
    pitch = 0;
    
    volumeSmoothSlow = 0;
    pitchSmoothSlow = 0;
    rotation=0;
}

//--------------------------------------------------------------
void testApp::update(){
    rotation = pitch *100;
    size=pitch * 100;
    
    sat = 180;
    bri = ofMap(volume, 0, 0.2, 0, 500, true);
    hue = ofMap(pitch, 0, 3000, 0, 360, true);
    
    color.setHsb(hue, sat, 255);
    
    float speed = volume * 100;
    
    particles myparticle;
    myparticle.setup(color, rotation, speed, size);
    particle.push_back(myparticle);


}

//--------------------------------------------------------------
void testApp::draw(){
        for (int i = 0; i < 800; i++){
    particle[i].draw();
        }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::audioIn(float * input, int bufferSize, int nChannels){
    
    
    float rms = 0;
    for (int i = 0; i < bufferSize; i++){
        rms += input[i] * input[i];
    }
    rms /= (float)bufferSize;
    rms = sqrt(rms);
    
    volume = 0.9f * volume + 0.1 * rms;
    volumeSmoothSlow = 0.99f * volumeSmoothSlow + 0.01 * rms;
    
    
  
    
    
    
    int zeroCrossingCount = 0;
    
    for (int i = 0; i < bufferSize; i++){
        

        
        bool curSign = input[i] > 0 ? true : false;
        
        if (curSign != bSignOflastValue){
            zeroCrossingCount++;
        }
        bSignOflastValue = curSign;
    }
    
    float pitchVal = zeroCrossingCount * (44100.0 / (float)bufferSize) * (0.5);
    pitch = 0.9f * pitch + 0.1 * pitchVal;
    pitchSmoothSlow = 0.99f * pitchSmoothSlow + 0.01f * pitchVal;
    
    
}


