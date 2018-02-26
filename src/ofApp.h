#pragma once

#include "ofMain.h"
#include "ofxStreetView.h"



const ofVec3f verts[35] = {
	{ -2.5703f,    0.78053f,  -2.4e-05f },
	{ -0.89264f,  0.022582f,  0.018577f },
	{ 1.6878f,   -0.017131f,  0.022032f },
	{ 3.4659f,    0.025667f,  0.018577f },
	{ -2.5703f,    0.78969f, -0.001202f },
	{ -0.89264f,   0.25121f,   0.93573f },
	{ 1.6878f,     0.25121f,    1.1097f },
	{ 3.5031f,     0.25293f,   0.93573f },
	{ -2.5703f,     1.0558f, -0.001347f },
	{ -0.89264f,    1.0558f,    1.0487f },
	{ 1.6878f,      1.0558f,    1.2437f },
	{ 3.6342f,      1.0527f,    1.0487f },
	{ -2.5703f,     1.0558f,        0.f },
	{ -0.89264f,    1.0558f,        0.f },
	{ 1.6878f,      1.0558f,        0.f },
	{ 3.6342f,      1.0527f,        0.f },
	{ -2.5703f,     1.0558f,  0.001347f },
	{ -0.89264f,    1.0558f,   -1.0487f },
	{ 1.6878f,      1.0558f,   -1.2437f },
	{ 3.6342f,      1.0527f,   -1.0487f },
	{ -2.5703f,    0.78969f,  0.001202f },
	{ -0.89264f,   0.25121f,  -0.93573f },
	{ 1.6878f,     0.25121f,   -1.1097f },
	{ 3.5031f,     0.25293f,  -0.93573f },
	{ 3.5031f,     0.25293f,        0.f },
	{ -2.5703f,    0.78969f,        0.f },
	{ 1.1091f,      1.2179f,        0.f },
	{ 1.145f,        6.617f,        0.f },
	{ 4.0878f,      1.2383f,        0.f },
	{ -2.5693f,     1.1771f, -0.081683f },
	{ 0.98353f,     6.4948f, -0.081683f },
	{ -0.72112f,    1.1364f, -0.081683f },
	{ 0.9297f,       6.454f,        0.f },
	{ -0.7929f,      1.279f,        0.f },
	{ 0.91176f,     1.2994f,        0.f }
};

const uint32_t tri2[52 * 3] = {
	5, 1, 6,
	1, 2, 6,
	2, 3, 6,
	6, 3, 7,
	4, 8, 3,
	3, 8, 7,
	6, 10, 5,
	5, 10, 9,
	6, 7, 10,
	10, 7, 11,
	8, 12, 7,
	7, 12, 11,
	10, 14, 9,
	9, 14, 13,
	11, 15, 10,
	10, 15, 14,
	11, 12, 15,
	15, 12, 16,
	18, 17, 14,
	13, 14, 17,
	14, 15, 18,
	18, 15, 19,
	16, 20, 15,
	15, 20, 19,
	17, 18, 21,
	21, 18, 22,
	19, 23, 18,
	18, 23, 22,
	19, 20, 23,
	23, 20, 24,
	21, 22, 1,
	22, 2, 1,
	23, 3, 22,
	22, 3, 2,
	23, 24, 3,
	3, 24, 4,
	4, 24, 25,
	4, 25, 8,
	25, 24, 16,
	16, 24, 20,
	25, 16, 8,
	8, 16, 12,
	1, 26, 21,
	1, 5, 26,
	21, 26, 17,
	17, 26, 13,
	26, 5, 13,
	13, 5, 9,
	27, 28, 29,
	30, 31, 32,
	33, 35, 34
};

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);


	ofVbo boat;
	void drawBoat();

	ofCamera cam;
	ofxStreetView streetview;


	float lr;
	float ud;
	float fb;
	float yaw;
	int pSize;
	int zoom;

	ofPolyRenderMode renderMode;

	int currentCam;
	const int CAM_0 = 0;
	const int CAM_1 = 1;
	const int CAM_2 = 2;
	const int CAM_3 = 3;
	const int CAM_END = 4;


	/// CODE A MODIFIER...

	void setupProjection();
	void setupCam();
	ofMatrix4x4 lookAtMatrix(ofVec3f p, ofVec3f e, ofVec3f u);





};