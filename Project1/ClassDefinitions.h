#pragma once


class Ticket {

	/// Attributes & Defaults

private:
	string id = "";
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
			return this->id;

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

		this->id = ID;
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


	/// WILL FIX LATER I PROMISE 


	void getsVIPSeat() {
		this->isVIPSeat = true;
	}
	void getsNoVIPSeat() {
		this->isVIPSeat = false;
	}

	void getsSpecialNeedsSeat() {
		this->isSpecialNeedsSeat = true;
	}

	void getsNoSpecialNeedsSeat() {
		this->isSpecialNeedsSeat = false;
	}


	///WILL FIX THIS TOO 


	/// Constructor
	Ticket(string code, int row, int seat, bool isVIPSeat, bool isSpecialNeedsSeat) {
		this->id = code;
		this->row = row;
		this->seat = seat;
		this->isVIPSeat = isVIPSeat;
		this->isSpecialNeedsSeat = isSpecialNeedsSeat;
		

	}


};


class Movie {


};

class Location {


};


