#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Utils.h"
#include "Classes.h";


using namespace std;

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

void updateLog() {

}

void readLog() {

}


void displayMenu() {

	fstream log("log.txt");
	ifstream start("MenuStart.txt");
	ifstream view("MenuView.txt");
	ifstream request("MenuRequest.txt");
	bool leave=false;

	readFromFile(start);
	char ans;
	cin >> ans;
	switch (ans) {
	case('1'): {
		readFromFile(view);
		readLog();
		break; 
	}
	case('2'): {
		readFromFile(request);



		updateLog();
		break;
	}
	case('0'): {
		leave = true;
		break;
	}
	default: displayMenu();

	if (leave) break;

	}




	if (!leave) displayMenu();
}
