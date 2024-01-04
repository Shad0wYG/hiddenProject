#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void displayMenu() {

	bool close = false;

	while (true) {

		close = false;
		if (close) break;
		else {
			cout << "\n\n------------ Ticketing App ------------\n\n";
			cout << "Options: \n1) View Tickets \n2) Request a Ticket\n";


			cout << "\nChoose a number (Press 0 to exit):\n\n";
			char choice;
			cin >> choice;
			if (choice == '0') break;
			else {

				switch (choice) {
				case '1': {
					cout << "\n#Viewing Tickets";
					//viewTickets();

					cout << "\n\nReturn? Press 0\n\n";
					char ret;
					cin >> ret;
					if (ret == '0');
					else close = true;
					break;
				}
				case '2': {
					cout << "\n#Requesting a Ticket\n";
					//reqTicket();

					cout << "\n\nReturn? Press 0\n\n";
					int ret;
					cin >> ret;
					if (ret == '0');
					else close = true;
					break;
				}
				}

			}
		}
	}




}
