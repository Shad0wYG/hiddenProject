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

	friend void operator<<(ostream& console, Location& loc);
	friend void operator>>(ifstream& console, Location& loc);
};

class Event {
protected:
	int eventNo = -1;
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

	///Getters

	int getEventNo() {
		return this->eventNo;
	}

	string getName() {
		return this->name;
	}

	VENUE getVenue() {
		return this->venue;
	}


	//Setters


	void seteventNo(int no) {
		if (this->venue == THEATER) {
			if (no < 1 || no > 5) throw exception("Invalid event");
			else this->eventNo = no;
		}

		else if (this->venue == MOVIES) {
			if (no < 1 || no > 4) throw exception("Invalid event");
			else this->eventNo = no;
		}
	}

	void setName() { // tf do i put in ()
		if (this->venue == THEATER) {
			switch (this->eventNo) {
			case(1): {
				this->name = "HAMLET";
				break;
			}
			case(2): {
				this->name = "LONG_DAY";
				break;
			}
			case(3): {
				this->name = "AFRAID";
				break;
			}
			case(4): {
				this->name = "DEATH_SALESMAN";
				break;
			}

			case(5): {
				this->name = "OEDIPUS";
				break;
			}


			}
		}
		else if (this->venue == MOVIES) {
			switch (this->eventNo) {
			case(1): {
				this->name = "TOP_GUN";
				break;
			}
			case(2): {
				this->name = "BL_PANTH";	
				break;
			}
			case(3): {
				this->name = "AVATAR";
				break;
			}
			case(4): {
				this->name = "SCREAM";
				break;
			}
			}

		}


	}

	void setVenue(VENUE ven) {
		this->venue = ven;
	}



	friend void operator<<(ostream& console, Event& event);
	friend void operator>>(ifstream& console, Event& event);
};

class Ticket {
protected:
	char* id;
	Event event;
	Location location;

public:

	char* getTicketID() {
		return this->id;
	}


	void setTicketID() {
		Randomizer rand;
		this->id = rand.getRandID();
	}



	friend void operator<<(ostream& console, Ticket& ticket);
	friend void operator>>(istream& console, Ticket& ticket);
};

///Location Operators

void operator<<(ostream& console, Location& loc) {

	//console << "\nLOCATION OUT";

	console << loc.getRoom() << "\n";
	console << loc.getSeatNo() << "\n";
	console << loc.getSeatType() << "\n";
	console << loc.getZone() << "\n";


}


void operator>>(ifstream& console, Location& loc) {
	int _room;
	console >> _room;
	loc.setRoom(_room);
	
	int nr;
	console >> nr;
	loc.setZone(toZone(nr));


	int _seat;
	console >> _seat;
	loc.setSeatNoAndType(_seat);

}


///Event Operators

void operator<<(ostream& console, Event& event) {

	//console << "\nEVENT OUT";

	console << event.getEventNo() << "\n";
	console << event.getName() << "\n";
	console << event.getVenue() << "\n";
}


void operator>>(ifstream& console, Event& event) {

	int no;
	console >> no;
	event.setVenue(toVenue(no));
	
	int no2;
	console >> no2;
	event.seteventNo(no2);

	event.setName();

}


///Ticket Operators

void operator<<(ostream& console, Ticket& ticket) {
	
	//console << "\nTICKET OUT";

	console << ticket.getTicketID() << "\n";
	console << ticket.event;
	console << ticket.location;

}

/// idk ig mai uita te alta data ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void operator>>(istream& console, Ticket& ticket) {
	ticket.setTicketID();
	Event ev;




}


