#include <iostream>
#include <string>
//#include "ClassDefinitions.h";

using namespace std;

int SeatMatrix[8][16];

void createSeatMatrix(int seatmatrix[8][16]) {
	for (int i = 0; i < 2; i++) 
		for (int j = 0; j < 15; j++) seatmatrix[i][j] = 1;

	for (int i = 2; i < 5; i++) {

		for (int j = 0; j < 2; j++) seatmatrix[i][j] = 2;
		for (int j = 2; j < 13; j++) seatmatrix[i][j] = 0;
		for (int j = 13; j < 15; j++) seatmatrix[i][j] = 2;


	}
	for (int i = 5; i < 7; i++) {
			for (int j = 0; j < 15; j++) seatmatrix[i][j] = 1;
			
		}
}


void printSeatMatrix(int seatmatrix[8][16]) {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 15; j++) cout << seatmatrix[i][j] << " ";
		cout << "\n";
	}

}

int main() {
	createSeatMatrix(SeatMatrix);
	printSeatMatrix(SeatMatrix);

}