/*
 * Clock.cpp
 *
 *  Created on: Jan 18, 2021
 *      Author: Blake Condrey
 */
#include "Clock.h"

#include <ctime>		// to gather time since epoch (Jan 1 1970)
#include <iostream>		// input/output
#include <vector>		// vector to hold menu options
#include <string>		// work with strings
#include <Windows.h>	// cross-platform functionality of sleep()
#include <unistd.h>		// cross-platform functionality of sleep()
#include <winuser.h>	// GetAsyncKeyState -> // docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getasynckeystate
using namespace std;

/* Resource:
 * softwaretestinghelp.com/date-and-time-in-cpp/
 */
time_t ttime = time(0);
tm *local_time = localtime(&ttime);
int hour = local_time->tm_hour;
int min = local_time->tm_min;
int sec = local_time->tm_sec;

void Clock::Display12HrFormat() {		// function builds a the time as a string
	if (hour > 12) {					// in 12-hr format
		if ((hour - 12) < 10) {			// ex. "16" = "04"
			cout << "0" << hour - 12 << ":";
		}
		else {
			cout << hour - 12 << ":";
		}
		if (min < 10) {
			cout << "0" << min << ":"; // added "0" in string manually to concatenate "0" + n minutes
		}
		else {
			cout << min << ":";
		}
		if (sec > 9) {
			cout << sec << " PM";
		}
		else {
			cout << "0" << sec << " PM"; // added "0" in string manually to concatenate "0" + n seconds
		}
	}
	else {
		cout << hour << ":";
		if (min < 10) {
			cout << "0" << min << ":";	// added "0" in string manually to concatenate "0" + n minutes
		}
		else {
			cout << min << ":";
		}
		if (sec > 9) {
			cout << sec << " AM";
		}
		else {
			cout << "0" << sec << " AM"; // added "0" in string manually to concatenate "0" + n seconds
		}
	}
}

void Clock::Display24HrFormat() {		// function concatenates time into string for output

	if (hour < 10) {
		cout << "0" << hour << ":";
	}
	else {
		cout << hour << ":";
	}
	if (min < 10) {
		cout << "0" << min << ":";
	}
	else {
		cout << min << ":";
	}
	if (sec > 9) {
		cout << sec;
	}
	else {
		cout << "0" << sec;
	}
}

void Clock::PrintHorizontalStarBorder() {  // function to print 26 asteriks, no need to re-write this block constantly

	const int BOX_WIDTH = 26;

	for (int i = 0; i <= BOX_WIDTH; ++i) {
		cout << "*";
	}
}

void Clock::DisplayTime() {			// shaky output for the time display but it works

	cout << "\t\t";
	PrintHorizontalStarBorder();
	cout << "  ";
	PrintHorizontalStarBorder();
	cout << endl;
	cout << "\t\t*      12-Hour Clock      *";
	cout << "  *      24-Hour Clock      *" << endl;
	cout <<"\t\t*      ";
	Display12HrFormat();			// invocation displays the 12-hr format in box
	cout << "        *  *       ";
	Display24HrFormat();			// invocation displays the 24-hr format in box
	cout << "          *" << endl;
	cout << "\t\t";
	PrintHorizontalStarBorder();
	cout << "  ";
	PrintHorizontalStarBorder();
}

void Clock::DisplayMenu() {
	const vector<string> MENU_OPTIONS = {"1 - Add One Hour", "2 - Add One Minute", "3 - Add One Second", "4 - Exit Program"};
	// placed the menu options in a vector for easy maintenance

	int userChoice;		// for switch to capture user input and determine route

	cout << "\t\t";
	PrintHorizontalStarBorder();
	cout << "\n";
	for (int i = 0; i < MENU_OPTIONS.size(); ++i) {
		cout << "\t\t* " << MENU_OPTIONS[i] << endl;
	}
	cout << "\t\t";
	PrintHorizontalStarBorder();
	cout << "\n\n";

	cin >> userChoice;
								// each case calls sleep to pause program for about one second
	switch (userChoice) {
	case 1:
		Sleep(1000);
		AddOneHour();			// adds hour to output
		RunClockProgram();		// returns hour added to new display
		break;
	case 2:
		Sleep(1000);
		AddOneMinute();			// adds one min to output
		RunClockProgram();		// returns new time plus one minute
		break;
	case 3:
		Sleep(1000);
		AddOneSecond();			// adds one second to output
		RunClockProgram();		// returns new time plus one second
		break;
	case 4:
		cout << "Goodbye!" << endl;
		exit(1);
		break;					// terminates program
	default:
		cout << "Invalid choice." << endl;
		DisplayMenu();			// function calls itself to re-enter menu for user input other than 1-4
	}
}

void Clock::ClearScreen() {
	cout << ("\n\n\n\n");		// no actual clear functions available that clear console in eclipse							// this function simply prints new lines to "clear" the terminal.
}

void Clock::AddOneHour() {
	++hour;		// increment hour
}

void Clock::AddOneMinute() {
	if (min == 59) {
		++min;
		min = min - 60;	// ensures min doesn't increment to display "60" and reverts back to 0
	}
	else {
		++min;		// increment minute
	}
}

void Clock::AddOneSecond() {
	if (sec == 59) {
		++sec;
		sec = sec - 60; // ensures sec doesn't increment to display "60" and reverts back to 0
	}
	else {
		++sec;		// increment second
	}
}

void Clock::RunClockProgram() {
	cout << "\n\nPress ESC at any time enter menu options." << endl;
	bool esc = false;		// boolean to evaluate if ESC key hit
	while (!esc) {			// while !esc is true (is so because !esc means false)
		DisplayTime();
		AddOneSecond();
		Sleep(1000);
		ClearScreen();
		if (GetAsyncKeyState(VK_ESCAPE)) {	// user hits esc key causes DisplayTime() to stop
			esc = true;
		DisplayMenu();						// Menu displays to work with user clock
		}
	}

}



