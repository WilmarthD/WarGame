
//--------------------------------------------------------------------------------------------------
//File Name: standards.cpp
//Associated file: standards.h
//Members:
//	1 Constructor : Default
//	Standard Methods:
//		Get - N/A
//		Set - N/A 
//		Print - N/A 
//	Other Methods:
//	PrintDivider, PrintCenteredMessage, PrintFileName, CheckInput 
//
//	Friends:
//	Destructor
//--------------------------------------------------------------------------------------------------

#include "standards.h"

void PrintDivider(ofstream& output, char symbol, int length)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: OutputDivider
// Description: Outputs a divider to the output file.
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	//Output line of specified symbol and length
	output << setfill(symbol) << setw(length) << symbol << setfill(' ') << endl;
}

void PrintCenteredMessage(ofstream& output, int width, string message)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: OutputCenteredMessage
// Description: Outputs and centers any message on the width.
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	int stringLengthMessage;

	//Finds length of the message passed in
	stringLengthMessage = static_cast<int>(message.length());

	//Outputs centered message 
	output << right << setfill(' ') << setw((width + stringLengthMessage) / 2) << message << endl;
}

void PrintFileName(ofstream& output, string fileType, string fileName)
///////////////////////////////////////////////////////////////////////////////////////////////////
// Function Name: PrintFileName
// Description: Outputs file type and name to output file.
///////////////////////////////////////////////////////////////////////////////////////////////////
{
	//Output the file type and name
	output << "The " << fileType << " file can be found in the file(s), " << fileName << endl;
}

void CheckInput(ofstream& output, ifstream& input, string inputName, string outputName)
{
	//Check existence of file
	if (!input)
	{
		//Output that the file doesn't exist
		cout << "Input file doesn't exist" << endl << endl;
		output << "Input file doesn't exist" << endl << endl;

	}

	//Peek inside input file
	input.peek();

	//Check for data in input file
	if (input.eof())
	{
		//Output input file is empty to screen
		cout << "Error: input file " << inputName << " is empty" << endl << endl;
		output << "Error: input file " << inputName << " is empty" << endl << endl;
	}
	else
	{
		//Output that input file opened
		cout << "Input file " << inputName << " successfully opened" << endl;
		output << "Input file " << inputName << " successfully opened" << endl;

		//Output what output file will be used
		cout << "Output found in file " << outputName << endl << endl;
		output << "Output found in file " << outputName << endl << endl;
	}
}
