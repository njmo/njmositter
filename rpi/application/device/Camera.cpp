/*
 * Camera.cpp
 *
 *  Created on: Aug 21, 2017
 *      Author: njmo
 */

#include "Camera.hpp"
#include <iostream>

namespace device {

Camera::Camera()
	: cap(0)
{
	if (!cap.isOpened()) {
		 nannyLogError("OpenCV Failed to open camera");
	}
}


void Camera::getFrame(CameraCaptureResponse &response)
{
  utils::Timer timer;
	Mat frame,send;
	int jpegqual = 80;
	std::vector < uchar > encoded;
  do
  {
	  cap >> frame;
  }while( frame.size().width == 0 );
	resize(frame, send, Size(800, 600), 0, 0, INTER_LINEAR);
	std::vector < int > compression_params;
	compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
	compression_params.push_back(jpegqual);

	imencode(".jpg", send, encoded, compression_params);
//	imshow("send", send);
	int total_pack = 1 + (encoded.size() - 1) / 4096 ;

	const u32 sizeOfFrame = encoded.size() - 1;
	response.size = sizeOfFrame;
	memcpy(response.frame,&encoded[0],sizeOfFrame);
	u32 msPassed = timer.getMilisecondPassed();
}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

} /* namespace device */
