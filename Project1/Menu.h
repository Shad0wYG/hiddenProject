#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Utils.h"
#include "Classes.h";


using namespace std;
void displayMenu();
void reqTicketZone(VENUE ven);
void getSeat(Location current);


Location current;
Event Current;
Ticket CurrentTicket;
Randomizer r;

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

	int intans;
	bool ok = false;
	bool ok2 = false;
	ifstream evTheater("EventsTheater.txt");
	ifstream evMovies("EventsMovies.txt");
	//Event current;

		readFromFile(request);

		while (!ok) {
			ok = true;
			cin >> ans;
			switch (ans)
			{
			case('1'): {

				Current.setVenue(THEATER);
				readFromFile(evTheater);
				while (!ok2) {
					cin >> ans;
					if (ans >= '1' && ans <= '5') {
						intans = ans - '0';
						Current.seteventNo(intans);
						Current.setName(Current.getEventNo());

						reqTicketZone(THEATER);
						ok2 = true;
					}
					else cout << "Wrong value, try again.\n";
				}
				ok = true;
				break;
			}

			case('2'): {

				Current.setVenue(MOVIES);
				readFromFile(evMovies);
				while (!ok2) {
					cin >> ans;
					if (ans >= '1' && ans <= '4') {
						intans = ans - '0';
						Current.seteventNo(intans);
						Current.setName(Current.getEventNo());

						reqTicketZone(MOVIES);
						ok2 = true;
						//cout << "esti in pl";
					}
					else cout << "Wrong value, try again.\n";
				}
				ok = true;
				break;
			}
			default: {
				cout << "Wrong value, try again.\n";
				ok = false;
				}
			}
		}
	}


void reqTicketZone(VENUE venue) {
	int seat;
	char ans;
	bool ok = false;
	//Location current;
	ifstream seatingT("MenuSeatTheater.txt");
	ifstream seatingM("MenuSeatMovie.txt");

	if (venue == THEATER) {
		readFromFile(seatingT); current.setVenue(THEATER);
	}
	else {
		readFromFile(seatingM); current.setVenue(MOVIES);
	}

	while (!ok) {
		ok = true;
		cin >> ans;
		switch (ans) {
		case('1'): {
			current.setZone(LEFT);
			///cout << current.getZone();  ////
			cout << "Enter seat No:\n";
			cin >> seat;
			current.setSeatNoAndType(seat);
			//cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
			break;
		}
		case('2'): {
			if (venue == THEATER) current.setZone(RIGHT);
			else if (venue == MOVIES) current.setZone(MIDDLE);
			cout << "Enter seat No:\n";
			cin >> seat;
			current.setSeatNoAndType(seat);
			//cout << "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB";
			break;
		}
		case('3'): {
			if (venue == THEATER) current.setZone(TOP);
			else if (venue == MOVIES) current.setZone(RIGHT);
			cout << "Enter seat No:\n";
			cin >> seat;
			current.setSeatNoAndType(seat);
			//cout << "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC";
			//cout << current.getSeatNo() << " " << current.getSeatType();
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

	while (!leave) {

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
			//cout << "esti bn";
			//current.printLocation();
			//Current.printEvent();
			CurrentTicket.setLocation(current);
			CurrentTicket.setEvent(Current);
			CurrentTicket.setTicketID();

			cout << "\nTicket with ID " << CurrentTicket.getTicketID() << " has been created.\n";
			

			updateLog(log);
			break;
			}
		case('0'): {
			leave = true;
			break;
			}
		default: {
			cout << "Wrong value, try again.\n";
			}

		}

	}

}
