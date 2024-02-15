/************************************************************************************************************
Filename: AnimationManager.cpp
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
List of source files: Animation.cpp, Frame.cpp, AnimationManager.cpp, VideoFrame.cpp, AudioFrame.cpp
Purpose: All the logic for adding, editing, deleting and reporting the list of Animations is contained in this file.
As well as all logic manipulating the Animation data members.
***********************************************************************************************************/
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;
#include "Frame.h"
#include "AudioFrame.h"
#include "VideoFrame.h"
#include "Animation.h"
#include "AnimationManager.h"

/***********************************************
Function Name: EditAnimation
Purpose: Modifies the animation frame
Function In parameters: nan
Function Out parameters: nan
Version: 2.0
Author: Jason Waid
***********************************************/
void AnimationManager::EditAnimation() {
	int animationIndex = 0;

	//checks if any animations are present before applying logic
	if (animations.size() != 0) {

		cout << "Which Animation do you wish to edit? Please give the index (from 0 to " << animations.size() - 1 << "): ";
		cin >> animationIndex;

		//ensures the user doesn't go out of bounds
		if ((animationIndex >= 0) && (animationIndex <= animations.size() - 1)) {

			cout << "Editing Animation #" << animationIndex << endl;

			int menu = 0;

			//simple menu for modifying frames
			while(menu != 4){

				cout << "MENU" << endl;
				cout << "1. Insert a Frame" << endl;
				cout << "2. Delete a Frame" << endl;
				cout << "3. Edit a Frame" << endl;
				cout << "4. Quit" << endl;

				cin >> menu;

				switch (menu) {
				case 1:
					cin >> animations[animationIndex];
					break;
				case 2:
					animations[animationIndex].DeleteFrame();
					break;
				case 3:
					animations[animationIndex].EditFrame();
					break;
				case 4:
					cout << "Animation #" << animationIndex << " edit complete" << endl;
					break;
				default:
					cout << "ERROR: Please enter Menu options 1 through 4" << endl;
					break;
				}
			}
		}
		else
		{
			cout << "ERROR: Invalid index" << endl;
		}
	}
	else
	{
		cout << "No Animations are present" << endl;
	}
}

/***********************************************
Function Name: DeleteAnimation
Purpose: Deletes the animation the user decides
Function In parameters: nan
Function Out parameters: nan
Version: 2.0
Author: Jason Waid
***********************************************/
void AnimationManager::DeleteAnimation() {
	int animationIndex = 0;

	cout << "Delete an Animation from the Animation Manager" << endl;
	//checks if any animations are present before applying logic
	if (animations.size() != 0) {

		cout << "Which Animation do you wish to delete? Please give the index in the range 0 to " << animations.size() - 1 << ": ";
		cin >> animationIndex;

		//ensures the user doesn't go out of bounds
		if ((animationIndex <= animations.size() - 1) && (animationIndex >= 0)) {

			animations.erase(animations.begin() + animationIndex);

			cout << "Animation #" << animationIndex << " deleted" << endl;
		}
		else
		{
			cout << "ERROR: Invalid index" << endl;
		}
	}
	else 
	{
		cout << "There are no Animations to delete" << endl;
	}
}
/***********************************************
Function Name: operator>>
Purpose: overloaded >> operator for std::istream
Function In parameters: istream& , AnimationManager&
Function Out parameters: istream&
Version: 2.0
Author: Jason Waid
***********************************************/
istream& operator>>(std::istream& input, AnimationManager& aManager) {
	
	Animation *animationP = nullptr;

	string animationName = "";

	cout << "Add an Animation to the Animation Manager" << endl;
	cout << "Please enter the Animation Name: ";

	input >> animationName;

	/*
	Original Code
	animationP = new Animation(animationName);
	*/
	cout << "Animation " << animationName << " added at the back of animations" << endl;

	//Adds animation to the back fo the list
	/*Original Code
	aManager.animations.push_back(*animationP);
	*/
	aManager.animations.push_back(Animation(animationName));


	animationP = nullptr;
	return input;
}
/***********************************************
Function Name: operator<<
Purpose: overloaded << operator for std::istream
Function In parameters: ostream& , AnimationManager&
Function Out parameters: ostream&
Version: 1.0
Author: Jason Waid
***********************************************/
ostream& operator<<(std::ostream& output, AnimationManager& aManager) {

	int i = 0;
	cout << "AnimationManager: " << aManager.managerName << endl;

	//will loop through all data in the animation manager
	for (auto loop = aManager.animations.begin(); loop < aManager.animations.end(); loop++) {

		output << "Animation: " << i++ << endl;
		output << *loop;

	}

	return output;
}