/*
 * Clock.h
 *
 *  Created on: Jan 18, 2021
 *      Author: Blake Condrey
 *
 *      Header file to hold Class and function declarations
 */

// Zybooks 4.16 Separate files

#ifndef CLOCK_H_
#define CLOCK_H_

#include <ctime>		// to gather time since epoch (Jan 1 1970)
using namespace std;

class Clock {		// uncovered topic thus far but used cplusplus.com/doc/tutorial/classes/ for reference
	public:
	/* Resource:
	 * softwaretestinghelp.com/date-and-time-in-cpp/
	 */
		time_t ttime = time(0);
		tm *local_time = localtime(&ttime);
		int hour = local_time->tm_hour;
		int min = local_time->tm_min;
		int sec = local_time->tm_sec;

// Function Declarations below from Clock.cpp

void Display12HrFormat();

void Display24HrFormat();

void PrintHorizontalStarBorder();

void DisplayTime();

void DisplayMenu();

void ClearScreen();

void AddOneHour();

void AddOneMinute();

void AddOneSecond();

void RunClockProgram();

};



#endif /* CLOCK_H_ */

