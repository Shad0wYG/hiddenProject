#pragma once
#include <iostream>
#include <fstream>
#include "Classes.h"
#include "Utils.h";
#include <string>

using namespace std;


class Location {
protected:
	int room = -1; //could be room1,room2
	ZONE zone = LEFT;
	int seatNo = -1; // 1-10/row if left/right, 1-20/row if top
	bool isSpecialSeat = false; //first row 
	


public:

	///Getters
	int getRoom() {
		return this->room;
	}

	ZONE getZone() {
		return this->zone;
	}

	int getSeatNo() {
		return this->seatNo;
	}

	bool getSeatType() {
		return this->isSpecialSeat;
	}


	void printZone() {
		switch (this->zone) {
		case(1): 
			cout << "LEFT";
			return;
		case(2):
			cout << "RIGHT";
			return;
		case (3): 
			cout << "TOP";
			return;
		}
	}


	///Setters
	void setRoom(int roomNo) {
		if (roomNo == 1 || roomNo == 2) {
			this->room = roomNo;
		}

		else throw exception("Wrong value");
	}

	void setZone(ZONE Zone) {
		this->zone = Zone;

	}

	void setSeatNoAndType(int SeatNo) {
		if (this->zone != TOP) {
			if (SeatNo >= 1 && SeatNo <= 100) {
				this->seatNo = SeatNo;
				if (seatNo <= 10) isSpecialSeat = true;
				else isSpecialSeat = false;
			}
		}

		else {
			if (SeatNo >= 1 && SeatNo <= 120) {
				this->seatNo = SeatNo;
				if (seatNo <= 20) isSpecialSeat = true;
				else isSpecialSeat = false;
			}
		}

	}

	///Ctors
	Location(int Room, ZONE Zone, int SeatNo) {
		//cout << "\n CtorLoc";

		this->setRoom(Room);
		this->setZone(Zone);
		this->setSeatNoAndType(SeatNo);

	}


	///Dtor
	~Location() {
		//cout << "\n DtorLoc";
	}
};

class Event {
protected:
	string name = "";
	VENUE venue;

public:

	void printEvents() {
		if (this->venue == THEATER) {
			cout << "\n1: Hamlet - Willian Shakespeare";
			cout << "\n2: Long Day's Journey Into Night - Eugene O'Neill";
			cout << "\n3: Who's Afraid of Virginia Woolf? - Edward Albee";
			cout << "\n4: Death of a Salesman - Arthur Miller";
			cout << "\n5: Oedipus Rex by Sophocles";

		}
		else if (this->venue == MOVIES) {
			cout << "\n1: Top Gun: Maverick";
			cout << "\n2: Black Panther: Wakanda Forever";
			cout << "\n3: Avatar: The Way of Water";
			cout << "\n4: Scream";
		}

	}



};

class Ticket {
protected:
	char* id;
	Event event;
	Location location;

public:

	void setTicketID() {
		Randomizer rand;
		this->id = rand.getRandID();
	}


};