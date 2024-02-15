/************************************************************************************************************
Filename: AudioFrame.cpp
Version: 1.0
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
List of source files: Animation.cpp, Frame.cpp, AnimationManager.cpp, AudioFrame.cpp, VideoFrame.cpp
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
#include "Animation.h"
#include "AnimationManager.h"
#include "AudioFrame.h"

/************************************************************************************************************
Function name: operator<<
Purpose: Overloads << operator when printing frame data members
In parameters: ostream&, Frame&
Out parameters: ostream&
Version: 1.0
Author: Jason Waid
*************************************************************************************************************/
ostream& operator<<(ostream& output, AudioFrame& frame) {

	Frame* frameP = &frame;

	output << "AudioFrame: " << *frameP;
	output << "MP3 Lossy Compression" << endl;
	output << "------------------------------------------------------" << endl;
	output << "bitrate (kbits/s): \t | 128\t | 160\t | 192\t" << endl;
	output << "------------------------------------------------------" << endl;
	output << "file size (MB): \t";
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
void AudioFrame::CalculateFrameResource() {
	
	for (int i = 0; i < RATES; i++) {
		cout << fixed;
		cout << setprecision(3);
		cout << " | " << size / (COMPRESSION_RATIO[i]);

	}
	cout << endl;
	cout << "------------------------------------------------------" << endl;



}

