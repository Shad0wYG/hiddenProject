#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Utils.h"
#include "Classes.h";


using namespace std;
void displayMenu();
void reqTicketLocation(VENUE ven);

void readFromFile(ifstream& file) {
	if (!file.is_open()) {
		throw exception("File does not exist.");
	}
	while (!file.eof()) {
		char buffer[255];
		file.getline(buffer, 255);
		cout << buffer << '\n';
	}
}

void updateLog(fstream& file) {

}

void readLog(fstream& file) {
	if (!file.is_open()) {
		throw exception("File probably misplaced.");
	}
	while (!file.eof()) {
		char buffer[255];
		file.getline(buffer, 255);
		cout << buffer << '\n';
	}
}

void reqTicketEvent(char ans, ifstream& request) {

	ifstream evTheater("EventsTheater.txt");
	ifstream evMovies("EventsMovies.txt");
	Event current;


	readFromFile(request);
	cin >> ans;

	switch (ans)
	{
	case('1'): {

		current.setVenue(THEATER);
		readFromFile(evTheater);
		cin >> ans;
		current.seteventNo(ans);
		current.setName(current.getEventNo());

		reqTicketLocation(THEATER);

		break;
	}

	case('2'): {

		current.setVenue(MOVIES);
		readFromFile(evMovies);
		cin >> ans;
		current.seteventNo(ans);
		current.setName(current.getEventNo());

		reqTicketLocation(MOVIES);

		break;
	}

	default: {
		displayMenu();
		break;
	}
	}

}

void reqTicketLocation(VENUE venue) {
	char ans;
	bool ok = false;
	Location current;
	ifstream seatingT("MenuSeatTheater.txt");
	ifstream seatingM("MenuSeatMovie.txt");

	if (venue == THEATER) readFromFile(seatingT);
	else readFromFile(seatingM);
	while (!ok) {
		ok = true;
		cin >> ans;
		switch (ans) {
		case('1'): {
			current.setZone(LEFT);
			break;
		}
		case('2'): {
			if (venue == THEATER) current.setZone(RIGHT);
			else if (venue == MOVIES) current.setZone(MIDDLE);
			break;
		}
		case('3'): {
			if (venue == THEATER) current.setZone(TOP);
			else if (venue == MOVIES) current.setZone(RIGHT);
			break;
		}
		default: {
			cout << "\nWrong value, try again\n";
			ok = false;
		}

		}
	}

}


void displayMenu() {



	fstream log("log.txt");
	ifstream start("MenuStart.txt");
	ifstream view("MenuView.txt");
	ifstream request("MenuRequest.txt");
	bool leave=false;

	readFromFile(start);
	char ans = -100;
	cin >> ans;
	switch (ans) {
	case('1'): {
		readFromFile(view);
		readLog(log);
		break; 
	}
	case('2'): {
		reqTicketEvent(ans, request);




		updateLog(log);
		break;
	}
	case('0'): {
		leave = true;
		break;
	}
	default: displayMenu();

	if (leave) break;

	}




	//if (!leave) displayMenu();
}
