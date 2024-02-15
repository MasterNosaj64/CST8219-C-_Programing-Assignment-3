/************************************************************************************************************
Filename: Frame.cpp
Version: 1.0
Author: Jason Waid
Student Number: 040912687
Course Name: C++
Course Code: CST8219
Lab Section: 303
Assignment Number: 2
Assignment Name: Animation Project in C
Due Date: 2019/09/11
Submission Date: 2019/09/11
Professor's Name: Mohamed Abouseif
List of source files: Animation.cpp, Frame.cpp, AnimationManager.coo
Purpose: All the logic for initializing, alloacting, deallocting and editing memory exists in this file
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

/************************************************************************************************************
Function name: operator<<
Purpose: Overloads << operator when printing frame data members
In parameters: ostream&, Frame& 
Out parameters: ostream&
Version: 2.0
Author: Jason Waid
*************************************************************************************************************/
ostream& operator<<(ostream& output, Frame& frame) {

	output << "frameName = " << frame.frameName << endl;

	return output;
}



