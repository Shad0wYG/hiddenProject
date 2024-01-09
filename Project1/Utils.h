#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Classes.h"

enum VENUE { THEATER = 1, MOVIES = 2};

enum ZONE { LEFT = 1, RIGHT = 2, TOP = 3, MIDDLE = 4};

enum EVENTTheater { HAMLET = 1, LONG_DAY = 2, AFRAID = 3, DEATH_SALESMAN = 4, OEDIPUS = 5 };
//Hamlet - Willian Shakespeare   
//Long Day's Journey Into Night - Eugene O'Neill
//Who's Afraid of Virginia Woolf? - Edward Albee
//Death of a Salesman - Arthur Miller
//Oedipus Rex by Sophocles


enum EVENTMovies { TOP_GUN =1, BL_PANTH = 2, AVATAR =3, SCREAM =4 }; 
//Top Gun: Maverick
//Black Panther: Wakanda Forever
//Avatar: The Way of Water
//Scream


const char* toString(ZONE p) {
	switch (p)
	{
	case ZONE::LEFT:
		return "Left";
	case ZONE::RIGHT:
		return "Right";
	case ZONE::TOP:
		return "Top";
	}

}

ZONE toZone(int nr) {
	switch (nr) {
	case(1): return LEFT;
	case(2): return RIGHT;
	case(3): return TOP; 
	}
}

VENUE toVenue(int nr) {
	switch (nr) {
	case(1): return THEATER;
	case(2): return MOVIES;

	}
}


class Randomizer {
protected:
	char allCharacters[40] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890" };
	const int MAXRAND = 36;

public:
	char* getRandID(){
		char v[6];
		for (int i = 0; i < 6; i++) {
			v[i] = allCharacters[rand() % MAXRAND];
		}

		return v;
	}

};


