#include "ofApp.h"


//https://forum.openframeworks.cc/t/shader-and-particles-help-using-ofxgpuparticles/19586/2
//https://forum.openframeworks.cc/t/cant-apply-shader-to-an-offbo-the-result-is-just-blank/38738/20

//--------------------------------------------------------------
void ofApp::setup() {

	ofLogToConsole();

    ofBackground(0);
    ofSetFrameRate(60);
    
	image.loadImage("test.jpg");

	unsigned w = image.getWidth();
	unsigned h = image.getHeight();
	ofLogNotice("w") << w << ", h: " << h;

	//shader.setUniformTexture("tex0", image.getTextureReference(), 1);

    //if (ofIsGLProgrammableRenderer()) particles.loadShaders("shaders330/update", "shaders330/draw");
    //else particles.loadShaders("shaders120/update", "shaders120/draw");
    
	float* particlePosns = new float[w * h * 4];
	ofColor* particleColors = new ofColor[w * h];

	for (unsigned y = 0; y < image.getHeight(); ++y) {
		for (unsigned x = 0; x < image.getWidth(); ++x)	{

				unsigned idx = y * w + x;

				particlePosns[idx * 4] =  400.f * x / (float)w - 200.f;
				particlePosns[idx * 4 + 1] = 400.f * y / (float)h - 200.f;
				particlePosns[idx * 4 + 2] = 0.f;  // test value 1.0 - color blue
				particlePosns[idx * 4 + 3] = 0.f;

				particleColors[idx] = image.getColor(x, y);
		}
	}

	//Pass the colors into the ofxGpuParticles class.
	particles.init(w, h, particleColors);
	particles.loadDataTexture(ofxGpuParticles::POSITION, particlePosns);

	delete[] particlePosns;
	delete[] particleColors;
   
    // initial velocities
    particles.zeroDataTexture(ofxGpuParticles::VELOCITY);
    
    // listen for update event to set additonal update uniforms
    ofAddListener(particles.updateEvent, this, &ofApp::onParticlesUpdate);
}

//--------------------------------------------------------------
void ofApp::update()
{
    ofSetWindowTitle("Particles fps: " +  ofToString(ofGetFrameRate(), 2));
    particles.update();
}

// set any update uniforms in this function
void ofApp::onParticlesUpdate(ofShader& shader)
{
    ofVec3f mouse(ofGetMouseX() - .5f * ofGetWidth(), .5f * ofGetHeight() - ofGetMouseY() , 0.f);
    shader.setUniform3fv("mouse", mouse.getPtr());
    shader.setUniform1f("elapsed", ofGetLastFrameTime());
    shader.setUniform1f("radiusSquared", 200.f * 200.f);
	
	//shader.setUniformTexture("tex0", image.getTextureReference(), 0);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofBackground(ofColor::grey);
	//image.draw(0, 0);

    cam.begin();
    //ofEnableBlendMode(OF_BLENDMODE_ADD);
    particles.draw();
    //ofDisableBlendMode();
    cam.end();
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