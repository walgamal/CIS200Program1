#pragma once

using namespace std;
#include <iostream>
#include <vector>

const int MAX_SIZE = 25;

class myString {
private:

	string storedString;
	vector<char> stringVect;

	void setStringToVect() {

		storedString.resize(stringVect.size());

		for (int i = 0; i < stringVect.size(); i++) {

			storedString[i] = stringVect[i];

		}

	}
	//method is used to keep stored string and stringVect the same

public:

	myString() {

		setStringToVect();
		//initialing in the constructor
	
	}

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------*/

	void setString(string userInput, bool& methodStatus){

		if (userInput.size() <= MAX_SIZE) {
			initString();
			storedString = userInput;

			for (const char& c : storedString) {

				stringVect.push_back(c);

			}
			//pushback and for loop take all chars from passed string and put them into vect

			cout << "Instance Updated!" << endl;
			methodStatus = true;
		}
		else {
			cout << "ERROR: You have entered more than 25 characters! Call the method to try again.\n\n";
			methodStatus = false;
		}
		//*Any function with methodStatus passed has an if-else statement to determine failure or success!!!***
		
	
	} // void method that set stored string and vector  using inputted string

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------*/

	string getString() { 

		cout << "String returned!\n";

		return storedString; 

	} // string method that returns value in myString in a string data value

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------*/

	int size() {

		int charCount = 0;

		for (const char& c : stringVect) {

				charCount++;

		}

		return charCount;

	} // returns integer of how many characters are in the string ? (empty string is size zero)

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------*/

	bool emptyString() {

		if (stringVect.size() == 0) {
			return true;
		}
		else {
			return false;
		}
	
	} // boolean method that returns true if myString contains the empty string

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------*/

	char charAt(int position, bool& methodStatus) {
	
		if (position >= stringVect.size() || position < 0) {
			cout << "Sorry! You have input an invalid starting position. Call the method to try again.\n\n";
			methodStatus = false;
			return '\0';
		}
		else if (position < stringVect.size() || position >= 0) {
			methodStatus = true;
			return stringVect[position];
		}
		else {
			cout << "ERROR: CharAt position issue\n\n";
			methodStatus = false;
			return '\0';
		}

	} // character method returns character at that position(if beyond end of string or if negative, error message print and statusMethod fails method )

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------*/

	void initString() {
	
		stringVect = {};

		setStringToVect();

	} // void method resets / initializes string to null string

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------*/

	void printString(bool& methodStatus) {

		if (stringVect.size() != 0) {
			for (const char& c : stringVect) {

				cout << c;

			}
			methodStatus = true;
		}
		else {
			cout << "There is nothing to print! This string is empty! Call the method to try again.";
			methodStatus = false;
		}

		cout << endl;

	} // void method to print string

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------*/

	void addStart(myString userMyString, bool& methodStatus) {

		if (stringVect.size() + userMyString.size() <= MAX_SIZE) {

			stringVect.reserve(stringVect.size() + distance(userMyString.stringVect.begin(), userMyString.stringVect.end()));
			stringVect.insert(stringVect.begin(), userMyString.stringVect.begin(), userMyString.stringVect.end());
			//reseres space in stringVect and insert new chars

			cout << "Added to start of instance\n";
			methodStatus = true;

		}
		else {
			cout << "ERROR: The two myStrings total more than 25 characters! Call the method to try again.\n\n";
			methodStatus = false;
		}

		setStringToVect();

	} // void method adds the string in the input parameter to the front of current string (if it exceeds 25 characters, error message apears)

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------*/

	void addEnd(myString userMyString, bool& methodStatus) {

		if (stringVect.size() + userMyString.size() <= MAX_SIZE) {

			stringVect.reserve(stringVect.size() + distance(userMyString.stringVect.begin(), userMyString.stringVect.end()));
			stringVect.insert(stringVect.end(), userMyString.stringVect.begin(), userMyString.stringVect.end());
			//reseres space in stringVect and insert new chars

			cout << "Added to start of instance\n";
			methodStatus = true;

		}
		else {
			cout << "ERROR: The two myStrings total more than 25 characters! Call the method to try again.\n\n";
			methodStatus = false;
		}


		setStringToVect();

	} // void method adds the string in the input parameter to the end of the current string (if it exceeds 25 characters, error message apears)

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------*/

	myString partString(int startPos, int length, bool& methodStatus) {

		myString returnMyString;
		int lengthCount = 0;

		if (startPos > stringVect.size() || startPos < 0) {
			cout << "Sorry! You have input an invalid starting position. Call the method to try again.\n\n";
			methodStatus = false;
			return returnMyString;
		}
		else if (startPos == stringVect.size()) {
			methodStatus = true;
			cout << "(This part string is empty.)\n";
			return returnMyString;
		}
		else if (startPos + length > stringVect.size()) {
			cout << "Sorry! You have input an invalid length. Call the method to try again.\n\n";
			methodStatus = false;
			return returnMyString;
		}
		else {

			returnMyString.stringVect.resize(length);

			for (int i = startPos; lengthCount < length; lengthCount++) {

				returnMyString.stringVect[lengthCount] = stringVect[i];

				i++;

			}

			methodStatus = true;

			return returnMyString;

		}
		
	}	// returns myString from current myString starting at startPos for length given (handled startPos < 0, startPos = size returns null string, handle startPos > size)
		// Also sets methodStatus accordingly

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------*/

	bool fullString() {

		if (stringVect.size() == MAX_SIZE) {
			return true;
		}
		else {
			return false;
		}

	} // boolean method that returns true if myString contains exactly 25 characters

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------*/

	bool compareString(myString userMyString) {

		if (stringVect == userMyString.stringVect) {
			return true;
		}
		else{
			return false;
		}

		setStringToVect();

	} // boolean method compares current value of string with input parameter string and returns true if both strings are equal

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------*/

	void replPartString(myString userMyString, int startPos, bool& methodStatus) {

		int posMove = startPos;

		if (startPos >= stringVect.size() || startPos < 0) {
			cout << "Sorry! You have input an invalid starting position. Call the method to try again.\n\n";
			methodStatus = false;
		}
		else if ((userMyString.stringVect.size() + startPos) > MAX_SIZE) {
			cout << "Sorry! Your start postion overflows the instance (start postion too high)! \nCall the method to try again.\n\n";
			methodStatus = false;
		}
		else {

			stringVect.resize(userMyString.stringVect.size() + startPos);
			//reserves space to avoid overflow

			for (int i = 0; i < userMyString.size(); i++) {

				stringVect[posMove] = userMyString.stringVect[i];
				posMove++;
			}
			//for loop locates startPos and adds chars from there

			methodStatus = true;

			setStringToVect();

		}
		

	} // void method replaces characters starting at startPos with input string (if exceeds 25 characters or invalid startPos, error message appears)

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------*/

	void replWholeString(myString userMyString) {

		stringVect = userMyString.stringVect;

		cout << "Whole String Replaced!" << endl << endl;

		setStringToVect();

	} // void method replaces what is currently in string with input parameter string

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------*/

};
