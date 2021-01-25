#include <iostream>
#include <string>
#include "Achievement.h"
#include "Game.h"
#include "Platform.h"

using namespace std;

int main()
{
	Platform* platformPtr;
	
	string inputPlatform, inputManufacturer, inputGame, inputPublisher, inputDeveloper, inputTitle, inputDescription;
	int numOfGames, numOfAchievements, numOfinputScore, numOfPlatforms, platformSelect, gameSelect, inputScore;
	bool menu = true;

	// Create a user input size for platforms
	cout << "How many consoles?: ";
	cin >> numOfPlatforms;
	platformPtr = new Platform[numOfPlatforms];
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// User inputs platform details
	for (int i = 0; i < numOfPlatforms; ++i)
	{
		cout << "Enter name of console: (" << i << "/" << numOfPlatforms << ")" << endl;
		getline(cin, inputPlatform);
		platformPtr[i].setName(inputPlatform);
		
		cout << "Enter name of manufacturer" << endl;
		getline(cin, inputManufacturer);
		platformPtr[i].setManufacturer(inputManufacturer);
	}

	// Menu system for selecting console
	while (menu == true)
	{
		for (int i = 0; i < numOfPlatforms; i++)
		{
			cout << i << "." << platformPtr[i].getName() << "\t\t" << platformPtr[i].getManufacturer() << endl << endl;
		}
		cout << "Select your console: ";
		cin >> platformSelect;

		if (platformSelect >= 0 && platformSelect <= numOfPlatforms)
		{
			// Create a user input size for games
			if (platformPtr[platformSelect].hasGame == false)
			{
				cout << "How many games do you want entered?: ";
				cin >> numOfGames;
				platformPtr[platformSelect].numGames = numOfGames;
				platformPtr[platformSelect].gamePtr = new Game[numOfGames];
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				// User inputs game details
				for (int i = 0; i < platformPtr[platformSelect].numGames; i++)
				{
					cout << "What game are you entering? (" << i << "/" << platformPtr[platformSelect].numGames << ")" << endl;
					getline(cin, inputGame);
					platformPtr[platformSelect].gamePtr[i].setGame(inputGame);

					cout << "What publisher? \n";
					getline(cin, inputPublisher);
					platformPtr[platformSelect].gamePtr[i].setPublisher(inputPublisher);

					cout << "What developer? \n";
					getline(cin, inputDeveloper);
					platformPtr[platformSelect].gamePtr[i].setDeveloper(inputDeveloper);
				}
				platformPtr[platformSelect].hasGame = true;
			}

			else
			{
				for (int i = 0; i < platformPtr[platformSelect].numGames; i++)
				{
					cout << platformPtr[platformSelect].gamePtr[i].getGame();
					cout << "\t\t" << platformPtr[platformSelect].gamePtr[i].getPublisher();
					cout << "\t\t" << platformPtr[platformSelect].gamePtr[i].getDeveloper() << endl << endl;
				}
			}



			// User sets achievements for game
			while (menu == true)
			{
				for (int i = 0; i < platformPtr[platformSelect].numGames; i++)
				{
					cout << i << "." << platformPtr[platformSelect].gamePtr[i].getGame();
					cout << "\t\t" << platformPtr[platformSelect].gamePtr[i].getPublisher();
					cout << "\t\t" << platformPtr[platformSelect].gamePtr[i].getDeveloper() << endl << endl;
				}

				cout << "Select game: ";
				cin >> gameSelect;

				if (gameSelect >= 0 && gameSelect <= numOfGames)
				{
					// User enters achievements
					if (platformPtr[platformSelect].gamePtr[gameSelect].hasAchievements == false)
					{
						cout << "How many Achievements?: ";
						cin >> numOfAchievements;
						platformPtr[platformSelect].gamePtr[gameSelect].numAchievements = numOfAchievements;
						platformPtr[platformSelect].gamePtr[gameSelect].achievementPtr = new Achievement[numOfAchievements];
						cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

						for (int i = 0; i < platformPtr[platformSelect].gamePtr[gameSelect].numAchievements; i++)
						{
							cout << "Enter achievement title? (" << i << "/" << platformPtr[platformSelect].gamePtr[gameSelect].numAchievements << ")" << endl;
							getline(cin, inputTitle);
							platformPtr[platformSelect].gamePtr[gameSelect].achievementPtr[i].setTitle(inputTitle);

							cout << "Add a Description? \n";
							getline(cin, inputDescription);
							platformPtr[platformSelect].gamePtr[gameSelect].achievementPtr[i].setDescription(inputDescription);

							cout << "How much is it worth? (points, currency, collectables) etc.\n";
							cin >> inputScore;
							platformPtr[platformSelect].gamePtr[gameSelect].achievementPtr[i].setScore(inputScore);
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						}
						platformPtr[platformSelect].gamePtr[gameSelect].hasAchievements = true;
						break;
					}

					// If achievements are already entered
					else
					{
						for (int i = 0; i < platformPtr[platformSelect].gamePtr[gameSelect].numAchievements; i++)
						{
							cout << platformPtr[platformSelect].gamePtr[gameSelect].achievementPtr[i].getTitle();
							cout << "\t\t" << platformPtr[platformSelect].gamePtr[gameSelect].achievementPtr[i].getDescription();
							cout << "\t\t" << platformPtr[platformSelect].gamePtr[gameSelect].achievementPtr[i].getScore() << endl << endl;
						}
						break;
					}
				}

				else if (gameSelect < 0)
				{
					cout << "Enter an integer number between 0 and the max value\n";
				}
			}

			// Displays achievements
			for (int i = 0; i < platformPtr[platformSelect].gamePtr[gameSelect].numAchievements; i++)
			{
				cout << platformPtr[platformSelect].gamePtr[gameSelect].achievementPtr[i].getTitle();
				cout << "\t\t" << platformPtr[platformSelect].gamePtr[gameSelect].achievementPtr[i].getDescription();
				cout << "\t\t" << platformPtr[platformSelect].gamePtr[gameSelect].achievementPtr[i].getScore() << endl << endl;
				break;
			}
		}

		else if (platformSelect < 0)
		{
			break;
		}
	}
	return 0;
}
