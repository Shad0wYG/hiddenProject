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

	void getsVIPSeat() {
		this->isVIPSeat = true;
	}
	void getsNonVIPSeat() {
		this->isVIPSeat = false;
	}
	void getsSpecialNeedsSeat() {
		this->isSpecialNeedsSeat = true;
	}
	void getsNonSpecialNeedsSeat() {
		this->isSpecialNeedsSeat = false;
	}

	void getSeatType() {
		if (row >= 3 && row <= 5 && seat >= 3 && seat <= 13) {
			getsVIPSeat();
		}
		else getsNonVIPSeat;

		if (row >= 3 && row <= 5 && seat <= 3 && seat >= 13) {
			getsSpecialNeedsSeat();
		}
		else getsNonSpecialNeedsSeat();

	}



	/// Constructor
	Ticket(string code, int row, int seat) {
		setID(code);
		setRow(row);
		setSeat(seat);
		getSeatType();
	}


};


class Movie {


};

class Location {


};


