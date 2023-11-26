#pragma once
#include <iostream>
#include <string>
using namespace std;


class Ticket {

	/// Attributes & Defaults

private:
	string ticketID = "*";
	int row = -1;
	int seat = -1;
	bool isVIPSeat = false;
	bool isSpecialNeedsSeat = false;

public:

	/// Magic numbers

	static const int ID_LENGTH = 6;
	static const int MIN_ROW_NO = 1;
	static const int MAX_ROW_NO = 7;
	static const int MIN_SEAT_NO = 1;
	static const int MAX_SEAT_NO = 15;
	static const int MAX_NO_TICKETS = 105;
	static int TICKETS_SOLD;


	/// Getters
	
		string getID() {
			return this->ticketID;

		}

		int getRow() {
			return this->row;
		}

		int getSeat() {
			return this->seat;
		}

		bool getVIPSeat() {
			return this->isVIPSeat;
		}

		bool getSpecialNeedsSeat() {
			return this->isSpecialNeedsSeat;
		}


	void printSeatType() {
		if (isVIPSeat) cout << "VIP Seat";
		else if (isSpecialNeedsSeat) cout << "Special Needs Seat";
		else cout << "Standard Seat";

		}

	

	/// Setters

	void setID(string ID) {

		if (ID.size() != ID_LENGTH) {
			throw exception("ID size is invalid");
		}

		this->ticketID = ID;
	}

	void setRow(int newRow) {
		if (newRow < MIN_ROW_NO || newRow > MAX_ROW_NO) {
			throw exception("Row number is invalid");
		}

		this->row = newRow;
	}

	void setSeat(int newSeat) {
		if (newSeat < MIN_SEAT_NO || newSeat > MAX_SEAT_NO) {
			throw exception("Seat number is invalid");
		}

		this->seat = newSeat;
	}

private: 
	void hasVIPSeat() {
		this->isVIPSeat = true;
	}
	void hasNonVIPSeat() {
		this->isVIPSeat = false;
	}
	void hasSpecialNeedsSeat() {
		this->isSpecialNeedsSeat = true;
	}
	void hasNonSpecialNeedsSeat() {
		this->isSpecialNeedsSeat = false;
	}

public:
	void setSeatType() {
		if (row >= 3 && row <= 5 && seat >= 3 && seat <= 13) {
			hasVIPSeat();
		}
		else hasNonVIPSeat();

		if (row >= 3 && row <= 5 && seat <= 3 && seat >= 13) {
			hasSpecialNeedsSeat();
		}
		else hasNonSpecialNeedsSeat();

	}



	int checkTicketsLeft() {
		return MAX_NO_TICKETS - TICKETS_SOLD;
	}



	/// Constructor
	Ticket(string code, int row, int seat) {
		setID(code);
		setRow(row);
		setSeat(seat);
		setSeatType();
		TICKETS_SOLD++;
	}



	/// Destructor
	~Ticket() {
		TICKETS_SOLD--;
	}

};

int Ticket::TICKETS_SOLD = 0;

void operator<<(ostream& console, Ticket ticket) {
	console << "*********************************";
	console << "\n Ticket ID: " << ticket.getID();
	console << "\n Row No: " << ticket.getRow();
	console << "\n Seat No: " << ticket.getSeat();
	console << "\n Seat Type: "; ticket.printSeatType();

}