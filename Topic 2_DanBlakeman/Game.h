 #pragma once
//Daniel Blakeman
//CIS 2201 502
//01-20-2022
//Design and implement an ADT for a one-person guessing game that chooses n random integers in the range of 1 to m and asks the user to guess them.  
//The same integer might be chosen more than once.  For example, the game might choose the following four integers that range from 1 to 10: 4, 6, 1, 6.

//Game.h //Declarations
#ifndef GAME_H
#define GAME_H
#include <vector>
#include <string>

using namespace std;



class Game
{

public:
	int compareVectors();
	void sortVectors();
	void randomNumberGenerator(int& max_number);
	void clearIntegerVector();
	void clearRandomVector();
	void playerGuesses(int player_guess);

private:
	//Vectors
	vector<int> random_vector;
	vector<int> integer_vector;
}; // End Game Interface
#endif
