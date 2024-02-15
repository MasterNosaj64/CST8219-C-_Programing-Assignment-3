/************************************************************************************************************
Filename: VideoFrame.cpp
Version: 2.0
Author: Jason Waid
Student Number: 040912687
Course Name: C++
Course Code: CST8219
Lab Section: 303
Assignment Number: 3
Assignment Name: Animation Project in C
Due Date: 2019/30/11
Submission Date: 2019/30/11
Professor's Name: Mohamed Abouseif
List of source files: Animation.cpp, Frame.cpp, AnimationManager.cpp, VideoFrame.cpp, AudioFrame.cpp
Purpose: 
************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
#include <iomanip>
using namespace std;
#include "Frame.h"
#include "VideoFrame.h"
#include "Animation.h"
#include "AnimationManager.h"

/************************************************************************************************************
Function name: operator<<
Purpose: Overloads << operator when printing frame data members
In parameters: ostream&, VideoFrame&
Out parameters: ostream&
Version: 2.0
Author: Jason Waid
*************************************************************************************************************/
ostream& operator<<(ostream& output, VideoFrame& frame) {

	Frame *frameP = &frame;

	output << "VideoFrame: " << *frameP;
	output << "Lempel-Ziv-Welch Lossless Compression" << endl;
	output << "----------------------------------------------------------------------------------------" << endl;
	output << "colours: \t | 2\t | 4\t | 8\t | 16\t | 32\t | 64\t | 128\t | 256" << endl;
	output << "----------------------------------------------------------------------------------------" << endl;
	output << "file size (MB): ";
	frameP = nullptr;
	return output;
}

/************************************************************************************************************
Function name: CalculateFrameResource
Purpose: Calculates the resources for the given frame
In parameters: ostream&, Frame&
Out parameters: ostream&
Version: 1.0
Author: Jason Waid
*************************************************************************************************************/
void VideoFrame::CalculateFrameResource() {

	for (int i = 0; i < BITS; i++) {
		cout << fixed;
		cout << setprecision(3);
		cout << " | " << size / (COMPRESSION_RATIO * BITDEPTH_FACTOR[i]);

	}
	cout << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;


}