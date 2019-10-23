#ifndef __TIME_H__
#define __TIME_H__

#include <iostream>
#include <cstdio>
#include <ctime>

namespace util_time {

int year(std::time_t now = time(0)) {
	tm *ltm = localtime(&now);
	return int(1900 + ltm->tm_year);
}

int month(std::time_t now = time(0)) {
	tm *ltm = localtime(&now);
	return int(1 + ltm->tm_mon);
}

int day(std::time_t now = time(0)) {
	tm *ltm = localtime(&now);
	return int(ltm->tm_mday);
}

int hour(std::time_t now = time(0)) {
	tm *ltm = localtime(&now);
	return int(1 + ltm->tm_hour);
}

int minute(std::time_t now = time(0)) {
	tm *ltm = localtime(&now);
	return int(1 + ltm->tm_min);
}

int second(std::time_t now = time(0)) {
	tm *ltm = localtime(&now);
	return int(1 + ltm->tm_sec);
}

unsigned long int epoch_msec(std::time_t now = time(0)) {
	return ( std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
}

unsigned long int epoch_sec(std::time_t now = time(0)) {
	return ( std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count());
}

std::string string(std::string delim = "") {


	std::time_t now = time(0);
	tm *ltm = localtime(&now);
	std::string t;
	if (delim == "") {
		t =  std::to_string(year(now))     + "/"
		     + std::to_string(month(now))  + "/"
		     + std::to_string(day(now))    + " "
		     + std::to_string(hour(now))   + ":"
		     + std::to_string(minute(now)) + ":"
		     + std::to_string(second(now));
	} else {
		t =  std::to_string(year(now))     + delim
		     + std::to_string(month(now))  + delim
		     + std::to_string(day(now))    + delim
		     + std::to_string(hour(now))   + delim
		     + std::to_string(minute(now)) + delim
		     + std::to_string(second(now));

	}

	return t;
}

}

#endif