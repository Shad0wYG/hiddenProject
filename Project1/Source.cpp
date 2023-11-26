#include <iostream>
#include <string>
#include "ClassDefinitions.h";

using namespace std;

int SeatMatrix[8][16];

void createSeatMatrix(int seatmatrix[8][16]) {
	for (int i = 1; i <= 2; i++) 
		for (int j = 1; j <= 15; j++) seatmatrix[i][j] = 1; /// Normal Seats

	for (int i = 3; i <= 5; i++) {

		for (int j = 1; j <= 2; j++) seatmatrix[i][j] = 2;		/// Special Needs Seats
		for (int j = 3; j <= 13; j++) seatmatrix[i][j] = 0;    /// VIP Seats
		for (int j = 14; j <= 15; j++) seatmatrix[i][j] = 2;		/// Special Needs Seats


	}
	for (int i = 6; i <= 7; i++) {
			for (int j = 1; j <= 15; j++) seatmatrix[i][j] = 1; /// Normal Seats
			
		}
}


void printSeatMatrix(int seatmatrix[8][16]) {
	for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= 15; j++) cout << seatmatrix[i][j] << " ";
		cout << "\n";
	}

}

int main() {
	//createSeatMatrix(SeatMatrix);
	//printSeatMatrix(SeatMatrix);

	Ticket testTicket("SGA791", 4, 8);
	cout << testTicket;

}