#pragma once
#include <iostream>
#include <string>
using namespace std;


enum Room {ROOM01 =1, ROOM02, ROOM03, ROOM04}; ///could give unique names to the rooms in the future

class Movie {
private:

	/// Attributes
	string movieName = "-";
	Room room;
	string date = "01/01/1970"; /// dd/mm/yyyy



public:
	
	/// Getters

	string getMovieName() {
		return this->movieName;
	}

	Room getRoom() {
		return this->room;
	}

	string getDate() {
		return this->date;
	}


	/// Setters

	void setMovieName(const string movie) {
		if (movie.empty()) {
			throw exception("\nNo movie name inserted. ");
		}
		else {
			this->movieName = movie;

		}
	}

	void setRoom(enum Room bruh) {
		/*switch (room) {
		case(ROOM01):
			this->room = ROOM01;
		case(ROOM02):
			this->room = ROOM02;
		case(ROOM03):
			this->room = ROOM03;
		case(ROOM04): 
			this->room = ROOM04;}*/

		this->room = bruh;

	}

	void setDate(string newDate) {

		if (newDate[2] != '/' || newDate[5] != '/') {
			throw exception("Invalid Date Format");
		}

		this->date = newDate;

	}


	

	void printRoom(enum Room room) {

		switch (room) {

		case(ROOM01): {
			cout << "Room 01";
			return; 
		}

		case(ROOM02): {
			cout << "Room 02";
			return;
		}

		case(ROOM03): {
			cout << "Room 03";
			return; 
		}

		case(ROOM04): {
			cout << "Room 04";
			return;
		}
		
		
		}


	}



	Movie(string movie, Room roomNo, string date) {
		setMovieName(movie);
		setRoom(roomNo);
		setDate(date);
	}


};


class Seat {

	/// Attributes
	int row = -1;
	int seat = -1;
	bool isVIPSeat = false;
	bool isSpecialNeedsSeat = false;


	///Magic numbers
	static const int MIN_ROW_NO = 1;
	static const int MAX_ROW_NO = 7;
	static const int MIN_SEAT_NO = 1;
	static const int MAX_SEAT_NO = 15;
	static const int MAX_NO_TICKETS = 105;
	static int TICKETS_SOLD;


public:
	/// Getters

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

	int checkTicketsLeft() {
		return MAX_NO_TICKETS - TICKETS_SOLD;
	}


	/// Setters

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


	void setSeat(int row, int seat) {
		setRow(row);
		setSeat(seat);
		setSeatType();
		TICKETS_SOLD++;
	}


		/// Constructor
	Seat(int row, int seat) {
		setRow(row);
		setSeat(seat);
		setSeatType();
		TICKETS_SOLD++;
	}


		 /// Copy constructor
	Seat( Seat& seat) {
		this->row = seat.row;
		this->seat = seat.seat;
		this->isVIPSeat = seat.isVIPSeat;
		this->isSpecialNeedsSeat = seat.isSpecialNeedsSeat;


	}

	/// Destructor
	~Seat() {

	}

	void operator=(const Seat& source) {
		if (&source == this) return;
		else {
			this->setRow(source.row);
			this->setSeat(source.seat);
			this->isVIPSeat = source.isVIPSeat;
			this->isSpecialNeedsSeat = source.isSpecialNeedsSeat;
		}
	}



};

class Ticket {

	/// Attributes & Defaults


private:
	string ticketID = "*";
	Seat seat;
	Movie movie;

public:

	/// Magic numbers

	static const int ID_LENGTH = 6;



	/// Getters
	
	string getID() {
			return this->ticketID;

		}

	int getSeatRow() {
		return this->seat.getRow();
	}
	int getSeatNo() {
		return this->seat.getSeat();
	}
	bool getVIPSeatStatus() {
		return this->seat.getVIPSeat();

	}
	bool getSpecialNeedsSeatStatus() {
		return this->seat.getSpecialNeedsSeat();
	}

	void printSeatType() {

		if (this->getVIPSeatStatus()) {
			cout << "VIP Seat";
		}
		else if (this->getSpecialNeedsSeatStatus()) {
			cout << "Special Needs Seat";
		}
		else cout << "Standard Seat";

	}




	/// Setters

	void setID(string ID) {

		if (ID.size() != ID_LENGTH) {
			throw exception("ID size is invalid");
		}

		this->ticketID = ID;
	}

	void setSeatRow(int x) {
		seat.setRow(x);
	}

	void setSeatNo(int x) {
		seat.setSeat(x);
	}



	/// Constructor
	Ticket(string code, int row, int seat, string movieName, string Date, Room roomNo ) : seat(row, seat), movie(movieName, roomNo, Date) {
		setID(code);
	}




	/// Destructor
	~Ticket() {
	}

};

int Seat::TICKETS_SOLD = 0;

void operator<<(ostream& console, Ticket& ticket) {
	console << "*********************************";


	


	console << "\n Ticket ID: " << ticket.getID();
	console << "\n Row No: " << ticket.getSeatRow();
	console << "\n Seat No: " << ticket.getSeatNo();
	console << "\n Seat Type: "; ticket.printSeatType();

}

void operator>>(istream& console, Ticket& ticket) {
	cout << "Insert the desired row number: ";
	int newRow;
	console >> newRow;
	ticket.setSeatRow(newRow);

	cout << "Insert the desired seat number: ";
	int newSeat;
	console>> newSeat;
	ticket.setSeatNo(newSeat);

}



