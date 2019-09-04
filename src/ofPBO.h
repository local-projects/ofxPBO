/*
 * ofPBO.h
 *
 *  Created on: 08/04/2012
 *      Author: arturo
 */

#pragma once
#include "ofMain.h"
//#include "ofConstants.h"
//#include "ofTexture.h"
//#include "ofThread.h"
#include "Poco/Condition.h"

class ofPBO: public ofThread {
public:
	ofPBO();
	virtual ~ofPBO();

	void allocate(ofTexture & tex, int numPBOs);
	void loadData(const ofPixels & pixels, bool threaded=true);
	void updateTexture();
	void threadedFunction();

private:
	ofTexture texture;
	vector<GLuint> pboIds;
	size_t indexUploading = 0;
	size_t indexToUpdate = 0;
	unsigned int dataSize;
	Poco::Condition condition;
	GLubyte* gpu_ptr;
	const unsigned char* cpu_ptr;
	bool pboUpdated;
	bool lastDataUploaded;
};

