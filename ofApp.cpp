#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(255);
	ofEnableDepthTest();
	ofSetWindowTitle("Insta");

	ofSetCircleResolution(32);
	ofNoFill();
	ofSetLineWidth(0.1);

	this->noise_source_angle = ofRandom(10);

}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	float radius_step = 50;
	float tmp_angle = this->noise_source_angle;
	float noise_step = 0.02;
	float x, y;

	cam.begin();

	for (int i = ofGetWidth(); i > radius_step; i -= radius_step) {
		ofPushMatrix();

		ofNoFill();
		ofSetColor(32);
		ofCircle(0, 0, 0, i);

		x = i * cos((ofNoise(tmp_angle) * 720) * DEG_TO_RAD);
		y = i * sin((ofNoise(tmp_angle) * 720) * DEG_TO_RAD);

		ofFill();

		ofSetColor(255, 0, 0);
		ofSphere(ofVec3f(x, y, 0), 20);

		ofRotateY(180);
		ofRotateX(180);
		ofSetColor(0, 0, 255);
		ofSphere(ofVec3f(x, y, 0), 20);

		tmp_angle += noise_step;

		ofPopMatrix();
	}

	cam.end();

	this->noise_source_angle += noise_step * 2;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}