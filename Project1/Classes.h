#pragma once
#include <iostream>
#include <fstream>
#include "Classes.h"

using namespace std;

enum ZONE  { LEFT = 1, RIGHT = 2, TOP = 3 };


class Location {
private:
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
		cout << "\n Ctor1";

		this->setRoom(Room);
		this->setZone(Zone);
		this->setSeatNoAndType(SeatNo);

	}


	///Dtor
	~Location() {
		cout << "\n Dtor";
	}
};

class Event {
	string name = "";

};

class Ticket {
	Event event;
	Location location;

};