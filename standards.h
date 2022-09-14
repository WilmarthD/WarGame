#ifndef STANDARDS_H
#define STANDARDS_H

//--------------------------------------------------------------------------------------------------
//File Name: standards.h
//Associated file: standards.cpp
//Members:
//	1 Constructor : Default
//	Standard Methods:
//		Get - N/A
//		Set - N/A
//		Print - N/A
//	Other Methods:
//	PrintDivider, PrintCenteredMessage, PrintFileName, CheckInput
//	Friends:
//	Destructor
//--------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//Print Divider
void PrintDivider(ofstream& output, char symbol, int length);

//Print Centered Message
void PrintCenteredMessage(ofstream& output, int width, string message);

//Print File Name
void PrintFileName(ofstream& output, string fileType, string fileName);

//Check for input file
void CheckInput(ofstream& output, ifstream& input, string inputName, string outputName);

#endif // !standards
