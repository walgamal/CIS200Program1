#include "myString.h"
#include <iomanip>
#include <string>
#include <fstream>

int whichInst() {

	int userChoice = 0;

	cout << "Please select an instance you would like to apply this method to." << endl;

	do {

		cout << "For instance one, enter 1." << endl <<
			"for instance two, enter 2." << endl;

		cin >> userChoice;
		cout << endl;

		if (userChoice == 1) {
			return 1;
		}
		else if (userChoice == 2) {
			return 2;
		}
		else {
			cout << "Sorry, you have entered an invalid selection. Try again." << endl << endl;
		}

	} while ((userChoice != 1) && (userChoice != 2));

}

char sentinelCheck() {

	char sentinel;

	cout << "Enter 'y' to continue OR enter any other key to end the program: ";
	cin >> sentinel;

	return sentinel;
}

int askPos() {

	int Pos = 0;

	cout << "Please enter a number for position: ";
	cin >> Pos;

	return Pos;

}

int askLength() {

	int length = 0;

	cout << "Please enter a number for length: ";
	cin >> length;

	return length;

}

int main() {

	myString instance1;
	myString instance2;
	ofstream echoFile;
	string tempString;
	char sentinel = 'y';
	char charAtVal;
	bool methodStatus;
	bool isFull;
	bool isEmpty;
	bool isEqual;
	int instanceUsed;
	int userLength;
	int menuSelect;
	int userPos;
	
	echoFile.open("myStringLog.txt");

	echoFile << "Program Action - created myString instances 1 and 2\n";

	cout << "Hello, and welcome to the myString program by Wasim Algamal." << endl;

	while ((sentinel == 'y') || (sentinel == 'Y')) {

		cout << "Please make a selection from the menu below." << endl <<
			setfill('*') << setw(60) << "\n" << setfill(' ') <<
			"1: Set String" << endl <<
			"2: Get String" << endl <<
			"3: Size" << endl <<
			"4: Add Start" << endl <<
			"5: Add End" << endl <<
			"6: Part String" << endl <<
			"7: Replace Part String" << endl <<
			"8: Replace Whole String" << endl <<
			"9: Empty String?" << endl <<
			"10: Full String?" << endl <<
			"11: Compare String" << endl <<
			"12: Character at __" << endl <<
			"13: Initialize String" << endl <<
			"14: Print String" << endl <<
			"15: Instructions" << endl <<
			setfill('*') << setw(60) << "\n" << setfill(' ') <<
			"Your selection: ";

		echoFile << "Program Action - menu dispalyed and user asked for selection\n";

		cin >> menuSelect;
		cout << endl;

		echoFile << "User Action - user selected menu option " << menuSelect << endl;

		instanceUsed = '\0';
		userPos = '\0';
		isFull = NULL;
		isEmpty = NULL;
		isEqual = NULL;
		methodStatus = NULL;

		switch (menuSelect) {
		case 1:

			echoFile << "User Action - called setString method\n";

			instanceUsed = whichInst();
			
			if (instanceUsed == 1) {

				echoFile << "User Action - chose to apply method to instance 1\n";

				cout << "What would you like to set this string to (enter up to 25 characters): ";
				cin.clear();
				cin.ignore(10000, '\n');
				getline(cin, tempString);

				

				instance1.setString(tempString, methodStatus);

			}
			else if (instanceUsed == 2) {

				echoFile << "User Action - chose to apply method to instance 2\n";

				cout << "What would you like to set this string to (enter up to 25 characters): ";
				cin.clear();
				cin.ignore(10000, '\n');
				getline(cin, tempString);

				instance2.setString(tempString, methodStatus);

			}
			else {
				cout << "ERROR: Unable to set myString! Try Again.\n";
				echoFile << "PROGRAM ERROR: unable to select instance\n";
			}

			if (methodStatus == true) {
				echoFile << "User Action - user set instance to \"" << tempString << "\"\n";
				echoFile << "Program Action - program updated instance to \"" << tempString << "\"\n";
				echoFile << "Program Action - method was applied to myString successfully\n";
			}
			else {
				echoFile << "Program Action - method FAILED to be applied to myString\n";
			}
			
			break;
		case 2:

			echoFile << "User Action - called getString method\n";

			instanceUsed = whichInst();

			if (instanceUsed == 1) {

				echoFile << "User Action - chose to apply method to instance 1\n";

				cout << instance1.getString();

				echoFile << "Program Action - instance 1 string returned\n";
				echoFile << "Program Action - method was applied to myString successfully\n";

			}
			else if (instanceUsed == 2) {

				echoFile << "User Action - chose to apply method to instance 2\n";

				cout << instance2.getString();

				echoFile << "Program Action - instance 2 string returned\n";
				echoFile << "Program Action - method was applied to myString successfully\n";

			}
			else {
				cout << "ERROR: Unable to get myString! Try Again.\n";
				echoFile << "PROGRAM ERROR: unable to select instance\n";
			}

			cout << endl;

			break;
		case 3:

			echoFile << "User Action - called size method\n";

			instanceUsed = whichInst();

			if (instanceUsed == 1) {

				echoFile << "User Action - chose to apply method to instance 1\n";

				cout << "The size of this myString instance is: " << instance1.size() << endl;

				echoFile << "Program Action - returned instance 1 size\n";
				echoFile << "Program Action - method was applied to myString successfully\n";

			}
			else if (instanceUsed == 2) {

				echoFile << "User Action - chose to apply method to instance 2\n";

				cout << "The size of this myString instance is: " << instance2.size() << endl;

				echoFile << "Program Action - returned instance 2 size\n";
				echoFile << "Program Action - method was applied to myString successfully\n";

			}
			else {
				cout << "ERROR: Unable to retrieve size of myString! Try Again.\n";
				echoFile << "PROGRAM ERROR: unable to select instance\n";
			}

			break;
		case 4:

			echoFile << "User Action - called addStart method\n";

			instanceUsed = whichInst();

			if (instanceUsed == 1) {

				echoFile << "User Action - chose to apply method to instance 1\n";

				instance1.addStart(instance2, methodStatus);

			}
			else if (instanceUsed == 2) {

				echoFile << "User Action - chose to apply method to instance 2\n";

				instance2.addStart(instance1, methodStatus);

			}
			else {
				cout << "ERROR: Unable to add to start of myString! Try Again.\n";
				echoFile << "PROGRAM ERROR: unable to select instance";
			}

			if (methodStatus == true) {
				echoFile << "Program Action - program added to front of selected instance \n";
				echoFile << "Program Action - method was applied to myString successfully\n";
			}
			else {
				echoFile << "Program Action - method FAILED to be applied to myString\n";
			}

			break;
		case 5:

			echoFile << "User Action - called addEnd method\n";

			instanceUsed = whichInst();

			if (instanceUsed == 1) {

				echoFile << "User Action - chose to apply method to instance 1\n";

				instance1.addEnd(instance2, methodStatus);

			}
			else if (instanceUsed == 2) {

				echoFile << "User Action - chose to apply method to instance 2\n";

				instance2.addEnd(instance1, methodStatus);

			}
			else {
				cout << "ERROR: Unable to add to end of myString! Try Again.\n";
				echoFile << "PROGRAM ERROR: unable to select instance\n";
			}

			if (methodStatus == true) {
				echoFile << "Program Action - program added to end of selected instance \n";
				echoFile << "Program Action - method was applied to myString successfully\n";
			}
			else {
				echoFile << "Program Action - method FAILED to be applied to myString\n";
			}

			break;
		case 6:

			echoFile << "User Action - called partString method\n";

			instanceUsed = whichInst();

			userPos = askPos();
			echoFile << "Program Action - asks user for startPos\n";
			echoFile << "User Action - user selects startPos\n";

			userLength = askLength();
			echoFile << "User Action - user selected length\n";

			if (instanceUsed == 1) {

				echoFile << "User Action - chose to apply method to instance 1\n";

				instance1.partString(userPos, userLength, methodStatus).printString(methodStatus);

			}
			else if (instanceUsed == 2) {

				echoFile << "User Action - chose to apply method to instance 2\n";

				instance2.partString(userPos, userLength, methodStatus).printString(methodStatus);

			}
			else {
				cout << "ERROR: Unable to retrieve part myString! Try Again.\n";
				echoFile << "PROGRAM ERROR: unable to select instance\n";
			}

			if (methodStatus == true) {
				echoFile << "Program Action - program returned part string of selected instance using user startPos: " << userPos << 
					" and length: " << userLength << endl;
				echoFile << "Program Action - method was applied to myString successfully\n";
			}
			else {
				echoFile << "Program Action - method FAILED to be applied to myString\n";
			}

			break;
		case 7:

			echoFile << "User Action - called replPartString method\n";

			instanceUsed = whichInst();

			userPos = askPos();
			echoFile << "Program Action - asks user for startPos\n";
			echoFile << "User Action - user selects startPos\n";

			if (instanceUsed == 1) {

				echoFile << "User Action - chose to apply method to instance 1\n";

				instance1.replPartString(instance2, userPos, methodStatus);

				instance1.printString(methodStatus);


			}
			else if (instanceUsed == 2) {

				echoFile << "User Action - chose to apply method to instance 2\n";

				instance2.replPartString(instance1, userPos, methodStatus);

				instance2.printString(methodStatus);

			}
			else {
				cout << "ERROR: Unable to replace part myString! Try Again.\n";
				echoFile << "PROGRAM ERROR: unable to select instance\n";
			}

			if (methodStatus == true) {
				echoFile << "Program Action - program replaced part string of selected instance using user startPos: " << userPos << endl;
				echoFile << "Program Action - method was applied to myString successfully\n";
			}
			else {
				echoFile << "Program Action - method FAILED to be applied to myString\n";
			}

			break;
		case 8:

			echoFile << "User Action - called replWholeString method\n";

			instanceUsed = whichInst();

			if (instanceUsed == 1) {

				echoFile << "User Action - chose to apply method to instance 1\n";

				instance1.replWholeString(instance2);

				echoFile << "User Action - user replaced whole string of instance 1\n";

			}
			else if (instanceUsed == 2) {

				echoFile << "User Action - chose to apply method to instance 2\n";

				instance2.replWholeString(instance1);

				echoFile << "User Action - user replaced whole string of instance 2\n";

			}
			else {
				cout << "ERROR: Unable to replace whole myString! Try Again.\n";
				echoFile << "PROGRAM ERROR: unable to select instance\n";
			}

			break;
		case 9:

			echoFile << "User Action - called emptyString method\n";

			instanceUsed = whichInst();

			if (instanceUsed == 1) {

				echoFile << "User Action - chose to apply method to instance 1\n";

				isEmpty = instance1.emptyString();

				if (isEmpty == true) {
					cout << "This string is empty" << endl;
					echoFile << "Program Action - notifies user that string is empty\n";
				}
				else if (isEmpty == false) {
					cout << "This string is NOT empty" << endl;
					echoFile << "Program Action - notifies user that string is NOT empty\n";
				}
				else {
					cout << "ERROR: Unable to test if myString is empty! Try Again.\n";
					echoFile << "PROGRAM ERROR: unable to test if string is empty!\n";
				}

			}
			else if (instanceUsed == 2) {

				echoFile << "User Action - chose to apply method to instance 2\n";

				isEmpty = instance2.emptyString();

				if (isEmpty == true) {
					cout << "This string is empty" << endl;
					echoFile << "Program Action - notifies user that string is empty\n";
				}
				else if (isEmpty == false) {
					cout << "This string is NOT empty" << endl;
					echoFile << "Program Action - notifies user that string is NOT empty\n";
				}
				else {
					cout << "ERROR: Unable to test if myString is empty! Try Again.\n";
					echoFile << "PROGRAM ERROR: unable to test if string is empty!\n";
				}

			}
			else {
				cout << "ERROR: Unable to test if myString is empty! Try Again.\n";	
				echoFile << "PROGRAM ERROR: unable to select instance\n";
			}

			break;
		case 10:

			echoFile << "User Action - called fullString method\n";

			instanceUsed = whichInst();

			if (instanceUsed == 1) {

				echoFile << "User Action - chose to apply method to instance 1\n";

				isFull = instance1.fullString();

				if (isFull == true) {
					cout << "This string is full" << endl;
					echoFile << "Program Action - notifies user that string is full\n";
				}
				else if (isFull == false) {
					cout << "This string is NOT full" << endl;
					echoFile << "Program Action - notifies user that string is NOT full\n";
				}
				else {
					cout << "ERROR: Unable to test if myString is full! Try Again.\n";
					echoFile << "PROGRAM ERROR: unable to test if string is full!\n";
				}

			}
			else if (instanceUsed == 2) {

				echoFile << "User Action - chose to apply method to instance 2\n";

				isFull = instance2.fullString();

				if (isFull == true) {
					cout << "This string is full" << endl;
					echoFile << "Program Action - notifies user that string is full\n";
				}
				else if (isFull == false) {
					cout << "This string is NOT full" << endl;
					echoFile << "Program Action - notifies user that string is NOT full\n";
				}
				else {
					cout << "ERROR: Unable to test if myString is full! Try Again.\n";
					echoFile << "PROGRAM ERROR: unable to test if string is full!\n";
				}

			}
			else {
				cout << "ERROR: Unable to test if myString is full! Try Again.\n";
				echoFile << "PROGRAM ERROR: unable to select instance\n";
			}

			break;
		case 11:

			echoFile << "User Action - called compareString method\n";

			instanceUsed = whichInst();

			if (instanceUsed == 1) {

				echoFile << "User Action - chose to apply method to instance 1\n";

				isEqual = instance1.compareString(instance2);

				if (isEqual == true) {
					cout << "This two strings are the same" << endl;
					echoFile << "Program Action - notifies user that strings are the same\n";
				}
				else if (isEqual == false) {
					cout << "This two strings are NOT the same" << endl;
					echoFile << "Program Action - notifies user that strings are NOT the same\n";
				}
				else {
					cout << "ERROR: Unable to compare myString! Try Again.\n";
					echoFile << "PROGRAM ERROR: unable to compare strings!\n";
				}

			}
			else if (instanceUsed == 2) {

				echoFile << "User Action - chose to apply method to instance 2\n";

				isEqual = instance2.compareString(instance1);

				if (isEqual == true) {
					cout << "This two strings are the same" << endl;
					echoFile << "Program Action - notifies user that strings are the same\n";
				}
				else if (isEqual == false) {
					cout << "This two strings are NOT the same" << endl;
					echoFile << "Program Action - notifies user that strings are NOT the same\n";
				}
				else {
					cout << "ERROR: Unable to compare myString! Try Again.\n";
					echoFile << "PROGRAM ERROR: unable to compare strings!\n";
				}

			}
			else {
				cout << "ERROR: Unable to compare myStrings! Try Again.\n";	
				echoFile << "PROGRAM ERROR: unable to select instance\n";
			}

			break;
		case 12:

			echoFile << "User Action - called charAt method\n";

			instanceUsed = whichInst();

			userPos = askPos();
			echoFile << "Program Action - asks user for position\n";
			echoFile << "User Action - user selects postion\n";

			if (instanceUsed == 1) {

				echoFile << "User Action - chose to apply method to instance 1\n";

				charAtVal = instance1.charAt(userPos, methodStatus);

				if (charAtVal != '\0') {
					cout << "The character at postion " << userPos << " is \"" << charAtVal << "\"" << endl;
					echoFile << "Program action - notifies user that at user selected position: " << userPos << " there is character: " << charAtVal << endl;
				}

			}
			else if (instanceUsed == 2) {

				echoFile << "User Action - chose to apply method to instance 2\n";

				charAtVal = instance2.charAt(userPos, methodStatus);

				if (charAtVal != '\0') {
					cout << "The character at postion " << userPos << " is \"" << charAtVal << "\"" << endl;
					echoFile << "Program action - notifies user that at user selected position: " << userPos << " there is character: " << charAtVal << endl;
				}

			}
			else {
				cout << "ERROR: Unable to print character at " << userPos << "! Try Again.\n";		
				echoFile << "PROGRAM ERROR: unable to select instance\n";
			}

			if (methodStatus == true) {
				echoFile << "Program Action - program returns char: " << charAtVal << " at user selected postion: " << userPos << " of selected instance \n";
				echoFile << "Program Action - method was applied to myString successfully\n";
			}
			else {
				echoFile << "Program Action - method FAILED to be applied to myString\n";
			}

			break;
		case 13:

			echoFile << "User Action - called initString method\n";

			instanceUsed = whichInst();

			if (instanceUsed == 1) {

				echoFile << "User Action - chose to apply method to instance 1\n";

				instance1.initString();
				cout << "String initialized!" << endl;
				echoFile << "Program action - String initializes and program notifies user\n";

			}
			else if (instanceUsed == 2) {

				echoFile << "User Action - chose to apply method to instance 2\n";

				instance2.initString();
				cout << "String initialized!" << endl;
				echoFile << "Program action - String initializes and program notifies user\n";

			}
			else {
				cout << "ERROR: Unable to initialize myString! Try Again.\n";	
				echoFile << "PROGRAM ERROR: unable to select instance\n";
			}

			break;
		case 14:

			echoFile << "User Action - called printString method\n";

			instanceUsed = whichInst();

			if (instanceUsed == 1) {

				echoFile << "User Action - chose to apply method to instance 1\n";

				instance1.printString(methodStatus);

			}
			else if (instanceUsed == 2) {

				echoFile << "User Action - chose to apply method to instance 2\n";

				instance2.printString(methodStatus);

			}
			else {
				cout << "ERROR: Unable to print myString! Try Again.\n";
				echoFile << "PROGRAM ERROR: unable to select instance\n";
			}

			if (methodStatus == true) {
				echoFile << "Program action - string is printed\n";
				echoFile << "Program Action - method was applied to myString successfully\n";
			}
			else {
				echoFile << "Program Action - method FAILED to be applied to myString\n";
			}

			break;
		case 15:
			echoFile << "User Action - called for instruction\n";

			cout << "Instructions\n"
				<< setfill('=') << setw(145) << "\n" << setfill(' ')
				<< "Select a method, then select an instance to apply the method to!\n"
				<< "The methods are listed and explained below.\n"
				<< setfill('-') << setw(145) << "\n" << setfill(' ') <<
				"1: Set String - calls a void method that assigns a string value to myString (setString)" << 
				endl << setfill('~') << setw(145) << "\n" << setfill(' ') <<
				"2: Get String - calls a string method that returns myString's string data value (getString)" << 
				endl << setfill('~') << setw(145) << "\n" << setfill(' ') <<
				"3: Size - calls an integer method that retunrs the number of charactersin the myString (empty string is size zero)" <<
				endl << setfill('~') << setw(145) << "\n" << setfill(' ') <<
				"4: Add Start - calls a void method that adds the non-selected myString to the front of the selected myString" <<
				endl << setfill('~') << setw(145) << "\n" << setfill(' ') <<
				"5: Add End - calls a void method that adds the non-selected myString to the end of the selected myString" <<
				endl << setfill('~') << setw(145) << "\n" << setfill(' ') <<
				"6: Part String - calls a method that returns a myString from current myString's given starting postion for given length" <<
				endl << setfill('~') << setw(145) << "\n" << setfill(' ') <<
				"7: Replace Part String - calls a void method that replaces charaters of myString, from a given starting postion, with the non-selected myString" <<
				endl << setfill('~') << setw(145) << "\n" << setfill(' ') <<
				"8: Replace Whole String - calls a void method that replaces selected myString with the non-selected myString" <<
				endl << setfill('~') << setw(145) << "\n" << setfill(' ') <<
				"9: Empty String? - calls a boolean method that returns true if myString is empty [0 chars]" <<
				endl << setfill('~') << setw(145) << "\n" << setfill(' ') <<
				"10: Full String? - calls a boolean method that returns true if myString is full [25 chars]" <<
				endl << setfill('~') << setw(145) << "\n" << setfill(' ') <<
				"11: Compare String - calls a boolean method that compares the two myStrings and returns true if both strings are equal" <<
				endl << setfill('~') << setw(145) << "\n" << setfill(' ') <<
				"12: Character at ___ - calls a method that returns the character of selected myString at a given position" <<
				endl << setfill('~') << setw(145) << "\n" << setfill(' ') <<
				"13: Initialize String - calls a void method that resets/initializes string to null string" <<
				endl << setfill('~') << setw(145) << "\n" << setfill(' ') <<
				"14: Print String - calls a void method that prints myString data value" << endl <<
				setfill('=') << setw(145) << "\n" << setfill(' ');

			echoFile << "Program action - Instructions displayed\n";

			break;
		default:
			cout << "ERROR: Unable to Process Selection. Try Again.\n";		
			echoFile << "User ERROR: user entered invalid menu selection\n";
			break;
		}

		sentinel = sentinelCheck();
		echoFile << "Program Action - user is asked if they would like to continue\n";
		echoFile << "User Action - enters y for yes and anything else for no\n";
		echoFile << "Program action - loops if yes, ends if no\n";
		cout << endl;

	}

	cout << "Good-Bye! Thank you for using the myString Program!\n";

	echoFile << "Program action - Program ended!\n";

	echoFile.close();

	return 0;
}
