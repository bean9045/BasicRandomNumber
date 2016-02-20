#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main()
{
	const int MIN_VALUE = 50;
	const int MAX_VALUE = 100;

	unsigned seed = static_cast<unsigned>(time(0));
	srand(seed);

	int userGuess = 0;

	bool done = false;

	do
	{
		int random = (rand() % (1 + MAX_VALUE - MIN_VALUE)) + MIN_VALUE;

		bool correctGuess = false;

		do
		{
			cout << "Guess a number between \"50\" and \"100\": " << flush;
			cin >> userGuess;

			if (!cin)
			{
				cin.clear();
				cin.ignore(100, '\n');

				cout << "Please only enter numeric values." << endl;

			} else if (userGuess < MIN_VALUE || userGuess > MAX_VALUE)
			{
				cout << "The range is between \"50\" and \"100\". Please input a number within that range." << endl;

			} else if (userGuess > random)
			{
				cout << "Too high, try again." << endl;

			} else if (userGuess < random)
			{
				cout << "Too low, try again." << endl;

			} else if (userGuess == random)
			{
				correctGuess = true;
			}
		} while (!correctGuess);

		cout << "You guessed: " << "\"" << random << "\"" << ", and that is correct!" << endl;

		bool validInput = false;

		do
		{
			char answer;
			cout << "Would you like to exit? (y/n): " << flush;
			cin >> answer;

			switch (answer)
			{
				case 'y':
				case 'Y': cout << "Exiting..." << endl;
						   validInput = true;
						   done = true;
						   break;
				case 'n':
				case 'N': cout << "Continuing..." << endl << endl;
						    validInput = true;
						    break;

				default:  cout << "Please input either \"y\" or \"n\"." << endl;
						    cin.clear();
						    cin.ignore(100, '\n');
						    break;
			}
		} while (!validInput);

	} while (!done);

	return 0;
}
