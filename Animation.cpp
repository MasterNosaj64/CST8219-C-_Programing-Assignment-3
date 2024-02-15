/************************************************************************************************************
Filename: Animation.cpp
Version: 3.0
Author: Jason Waid
Student Number: 040912687
Course Name: C++
Course Code: CST8219
Lab Section: 303
Assignment Number: 
Assignment Name: Animation Project in C
Due Date: 2019/30/11
Submission Date: 2019/30/11
Professor's Name: Mohamed Abouseif
List of source files: Animation.cpp, Frame.cpp, AnimationManager.cpp, VideoFrame.cpp, AudioFrame.cpp
Purpose: All the logic for manipulating frames
************************************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;
#include "Frame.h"
#include "Animation.h"
#include "AnimationManager.h"
#include "VideoFrame.h"
#include "AudioFrame.h"


/************************************************************************************************************
Function name: ~Animation
Purpose: Deconstructor for Animation object
In parameters: ostream&, Frame&
Out parameters: ostream&
Version: 1.0
Author: Jason Waid
*************************************************************************************************************/
Animation::~Animation() {
	
	for (auto i = frames.begin(); i != frames.end(); i++) {

		delete* i;
	}
	
}


/************************************************************************************************************
Function name: Animation
Purpose: Edits the frames in the Animation
In parameters: None
Out parameters: None
Version: 3.0
Author: Jason Waid
*************************************************************************************************************/
void Animation::EditFrame() {

	char tempFrameName[64];//temp space for taking input for frameName
	double size = 0; //holds duration temporarily for the frame
	int frameCounter = 0; //counts frames
	int index = 0; //holds index
	Frame *frameP = nullptr;

	cout << "Edit a Frame in the Animation" << endl;

	//checks if frames are present first
	if (frames.empty() == false) {
		
		//this logic counts the frames by incrementing the frameCounter for every iteration
		for (Frame* i : frames) {
			frameCounter++;
		}

		cout << "There are " << frameCounter << " Frame(s) in the list. Please specify the index (<=" << frameCounter - 1 << ") to edit at : ";
		cin >> index;

		//ensures the user doesn't go out of bounds
		if ((index >= 0) && (index <= frameCounter - 1))
		{
			frameCounter = 0;//resets frameCounter so that it may be resued

			for (auto i = frames.begin(); i != frames.end(); i++) {
				
				if (frameCounter == index) {//once we've iterated to the correct frame (determined by index) logic will apply
					frameP = *i;
					cout << "The name and size of this Frame are " << *frameP << ". What do you wish to replace them with?" << endl;
					cin >> tempFrameName;
					
					do {

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cin >> size;

					} while (cin.fail() || size <  0);
			
					VideoFrame* videoP;
					AudioFrame* audioP;

					if (dynamic_cast<VideoFrame*>(*i) != nullptr) {
						
						/*Original Code
						*i = new VideoFrame(tempFrameName, size);
						*/

						videoP = dynamic_cast<VideoFrame*>(*i);
						*videoP = VideoFrame(tempFrameName, size);

					}
					else {
						
						/*Original Code
						*i = new AudioFrame(tempFrameName, size);
						*/
						
						audioP = dynamic_cast<AudioFrame*>(*i);
						*audioP = AudioFrame(tempFrameName, size);
						
					}
					
					cout << "Frame #" << index << " edit completed" << endl;
					break;
				}

				frameCounter++;
			}
		}
		else
		{
			cout << "ERROR: Invalid input" << endl;
		}
	}
	else
	{
		cout << "There are no Frames in the Animation" << endl;
	}
	frameP = nullptr;
}

/************************************************************************************************************
Function name: DeleteFrame
Purpose: Deletes a frame in a animation
In parameters:	nan
Out parameters: nan
Version: 2.0
Author: Jason Waid
*************************************************************************************************************/
void Animation::DeleteFrame() {
	//checks if any frames are present fist
	if (frames.empty() == false) {

		frames.pop_front();
		cout << "First Frame deleted" << endl;
	}
	else
	{
		cout << "This are no Frames in the Animation" << endl;
	}
}
/************************************************************************************************************
Function name: operator>>
Purpose: Overloads the >> operation when entering data for frames
In parameters: istream&, Animation&
Out parameters: istream&
Version: 2.0
Author: Jason Waid
*************************************************************************************************************/
istream& operator>>(istream& input, Animation& animation) {
	char tempFrameName[64];
	double size = 0;
	char frameType = 0;
	Frame* newFrame = nullptr;

	cout << "Insert a Frame in the Animation" << endl;
	cout << "Please enter the Frame frameName: ";
	input >> tempFrameName;
	
	do {

		input.clear();
		input.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter the Frame size(MB): ";
		input >> size;

	} while (input.fail() || size < 0);

	

	cout << "Please enter the Frame type (AudioFrame = A, VideoFrame = V): ";
	
	//new object is created

	while ((frameType != 'A') && (frameType != 'V')) {

		input >> frameType;

		switch (frameType) {

		case 'A':
		
			newFrame = new AudioFrame(tempFrameName, size);
			animation.frames.push_front(newFrame);
			break;


		case 'V':

			newFrame = new VideoFrame(tempFrameName, size);
			animation.frames.push_front(newFrame);
			break;


		default:
			cout << "Invalid Frame Type - Try Again" << endl;
			break;
		}


	}

	cout << "Frame " << tempFrameName << " Frame* added at the front of frames" << endl;
	newFrame = nullptr;
	return input;
}
/************************************************************************************************************
Function name: operator<<
Purpose: Overloads the << operation when outputing data for frames
In parameters: ostream&, Animation&
Out parameters: ostream&
Version: 2.0
Author: Jason Waid
*************************************************************************************************************/
ostream& operator<<(ostream& output, Animation& animation) {
	int counter = 0;

	output << "\tAnimation name is " << animation.animationName << endl;
	output << "\tReport the Animation" << endl;
	//checks if frames are present first
	if (animation.frames.empty() == false) {
		//loops through all the frames
		

		for (auto it = animation.frames.begin(); it != animation.frames.end(); it++) {
			
			output << "\tFrame #" << counter++ << endl;
			
			if (dynamic_cast<VideoFrame*>(*it) != nullptr) {

				cout << *dynamic_cast<VideoFrame*>(*it);
			}
			else {


				cout << *dynamic_cast<AudioFrame*>(*it);
			}
	
			
			(*it)->CalculateFrameResource();
		
		}
		
	}
	else
	{
		output << "\tNo frames in the Animation" << endl;
	}
	return output;
}