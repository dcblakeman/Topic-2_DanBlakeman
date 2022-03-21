//Daniel Blakeman
//CIS 2201 502
//01-20-2022
//Design and implement an ADT for a one-person guessing game that chooses n random integers in the range of 1 to m and asks the user to guess them.  
//The same integer might be chosen more than once.  For example, the game might choose the following four integers that range from 1 to 10: 4, 6, 1, 6.

#include "Game.h"
#include <iostream>
#include <stdio.h>		/* printf, scanf, puts, NULL */
#include <stdlib.h>	/*srand, rand */
#include <time.h>		/* time */
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	//Variables
	string play_again = "Y";
	int max_number;  // Max Amount to Guess From
	int player_guess = 0; // Player Chooses Numbers to Guess
	int number_of_integers = 0;
	int correct_guesses;;
	int counter;

	//Objects
	Game myGame;

	//Initialize random seed
	srand(time(NULL));

	//Functions
	//Repeat while user wants to play
	do
	{
		//Enter number of integers
		cout << "Please enter the number of integers: ";
		cin >> number_of_integers;

		//Max number to guess from
		cout << "Please enter the maximum number to choose from: ";
		cin >> max_number;

		//Random number generator for max number entered
		myGame.randomNumberGenerator(max_number);

		//While user does not win
		do
		{
			//Clear the integer vector
			myGame.clearIntegerVector();

			//Start counter at 0
			counter = 0;

			//User enters their guesses
			cout << "Enter your guesses for the " << number_of_integers << " integers in the range from 1 to " << max_number << " that have been selected. \n";
			do 
			{
				cout << "Enter Number: ";
				cin >> player_guess;
				if (player_guess > max_number || player_guess < 1)
					cout << "Choose a different number\n";
				else
				{
					myGame.playerGuesses(player_guess);
					counter++;
				}
				

			} while (counter < number_of_integers);
			

			//Sort Vectors
			myGame.sortVectors();

			//Compare Vectors
			correct_guesses = myGame.compareVectors();
			if (correct_guesses != number_of_integers)
			{
				cout << " " << correct_guesses << " of your guesses are correct. Guess again.\n";
				cout << "Number of Integers: " << number_of_integers << "\n";
			}
				

		} while (correct_guesses != number_of_integers);
		
		
		//If user wins
		if (correct_guesses == number_of_integers)
		{
			cout << "You are correct! Play again? ('Y' or 'N')";
			cin >> play_again;
		}
		
		//Clear Random Vector
		myGame.clearRandomVector();

	} while (play_again == "Y");

	return 0;
}