//Daniel Blakeman
//CIS 2201 502
//01-20-2022
//Design and implement an ADT for a one-person guessing game that chooses n random integers in the range of 1 to m and asks the user to guess them.  
//The same integer might be chosen more than once.  For example, the game might choose the following four integers that range from 1 to 10: 4, 6, 1, 6.

#include "Game.h" // Implementation
#include <iostream>
#include <vector>
#include <algorithm>

//Functions
void Game::randomNumberGenerator(int& max_number)
{
	for (int n = 0; n < max_number; n++)
	{
		//Generate a number between 1 and max number
		int random_number = rand() % max_number + 1;
		random_vector.push_back(random_number);
	}
}
void Game::sortVectors()
{
	sort(integer_vector.begin(), integer_vector.end());
	sort(random_vector.begin(), random_vector.end());
}

int Game::compareVectors()
{
	//Variables
	int correct_guesses = 0;

	if (random_vector != integer_vector)
	{
		//Compare Vectors
		for (int x : random_vector)
		{
			cout << "x = " << x << "\n";

			for (int y : integer_vector)
			{
				cout << "y = " << y << "\n";

				if (x == y)
				{
					correct_guesses += 1;
					cout << "Correct guesses: " << correct_guesses << "\n";

				}
				break;
			}
		}

		cout << "Random Vector: ";
		for (int x : random_vector)
			cout << x;
		cout << "\n";

		cout << "Integer Vector: ";
		for (int x : integer_vector)
			cout << x;
		cout << "\n";

		return correct_guesses;

	}
	else
		return integer_vector.size();

}

void Game::clearIntegerVector()
{
	integer_vector.clear();
}

void Game::clearRandomVector()
{
	random_vector.clear();
}

void Game::playerGuesses(int player_guess)
{
	integer_vector.push_back(player_guess);
}