#include "ofApp.h"
#include <cmath>




// p postion de l'observateur
// o position regardée
// u verter vers le haut de la camera
ofMatrix4x4 ofApp::lookAtMatrix(ofVec3f p, ofVec3f o, ofVec3f u)
{



	// Matrice de rotation
	ofMatrix4x4 R;


	// Matrice de translation
	ofMatrix4x4 T;


	return R*T;
}





//--------------------------------------------------------------
void ofApp::setup() {
	ofSetVerticalSync(true);
	ofEnableDepthTest();

	//streetview.setLatLon(40.75732,-73.985951);  // Time Sq
	//streetview.setLatLon(40.768153,-73.981473); // Columbus Circus
	//streetview.setLatLon(40.751511, -73.993953);  // Penn Station
	streetview.setLatLon(45.192651, 5.718228); // IUT
	streetview.setZoom(3);

	pSize = 3;
	renderMode = OF_MESH_POINTS;

	lr = 0;
	fb = 0;
	ud = 0,

		yaw = 0;

	currentCam = CAM_0;
	zoom = 90;

	boat.setVertexData(&verts[0], 35, GL_STATIC_DRAW);
	boat.setIndexData(&tri2[0], 52 * 3, GL_STATIC_DRAW);

}

void ofApp::drawBoat()
{
	boat.drawElements(GL_TRIANGLES, 52 * 3);
}

//--------------------------------------------------------------
void ofApp::update() {
	streetview.update();

	glPointSize(pSize);
}


void ofApp::setupProjection()
{
	glMatrixMode(GL_PROJECTION);
	ofPushMatrix();
	ofMatrix4x4 proj;
	proj.makePerspectiveMatrix(90, ofGetWidth() / float(ofGetHeight()), 0.1, 1000);
	glLoadMatrixf(proj.getPtr());
}



// Positionnez vous en ofVec3f(0, 0, 1)
// Regrdez vers ofVec3f(0, 1, 1)
// Le haut est  ofVec3f(0, 0, 1)
void ofApp::setupCam()
{
	ofMatrix4x4 modelView = lookAtMatrix(ofVec3f(lr, fb, ud), ofVec3f(lr, fb + 1, ud), ofVec3f(0, 0, 1));

	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(modelView.getPtr());
}



//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(0);


	setupProjection();

	glMatrixMode(GL_MODELVIEW);
	ofPushMatrix();







	setupCam();
	ofDrawAxis(1);
	streetview.draw();







	ofPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	ofPopMatrix();
	glMatrixMode(GL_PROJECTION);
	ofPopMatrix();

	ofColor(100);
	std::stringstream sts;
	sts << "Cam : " << currentCam << std::endl;
	sts << "up/down : " << ud << std::endl;
	sts << "front/back : " << fb << std::endl;
	sts << "left/right : " << lr << std::endl;
	sts << "yaw : " << yaw << std::endl;
	sts << "point Size : " << pSize << std::endl;
	sts << "zoom : " << zoom << std::endl;
	ofDrawBitmapString(sts.str(), 10, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == '+')
	{
		zoom--;
	}
	if (key == '-')
	{
		zoom++;

	}


	if (key == 'z')
	{
		pSize++;
	}
	if (key == 's')
	{
		pSize++;
	}
	if (key == 'm')
	{
		if (renderMode == OF_MESH_POINTS)
			renderMode = OF_MESH_WIREFRAME;
		else if (renderMode == OF_MESH_WIREFRAME)
			renderMode = OF_MESH_FILL;
		else if (renderMode == OF_MESH_FILL)
			renderMode = OF_MESH_POINTS;
	}
	float dXYZ = 1;
	if (key == OF_KEY_LEFT) {
		lr -= dXYZ;
	}
	if (key == OF_KEY_RIGHT) {
		lr += dXYZ;
	}
	if (key == OF_KEY_UP) {
		ud -= dXYZ;
	}
	if (key == OF_KEY_DOWN) {
		ud += dXYZ;
	}
	if (key == 'a') {
		fb += dXYZ;
	}
	if (key == 'q') {
		fb -= dXYZ;
	}

	if (key == 'c')
	{
		currentCam = currentCam++;
		if (currentCam == CAM_END)
			currentCam = 0;
	}

	if (key == 'd')
	{
		std::cout << cam.getModelViewMatrix() << std::endl << std::endl;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	yaw = x / float(ofGetWidth()) * 360;
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
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}