#include <iostream>
#include "Achievement.h"
#include "Game.h"
#include "Platform.h"

using namespace std;

Platform numberGames;


int main()
{
	Platform* pGames = nullptr;
	Game* pAchievements = nullptr;

	Platform* platformPtr;
	
	string inputPlatform, inputManufacturer, inputGame, inputPublisher, inputDeveloper, inputTitle, inputDescription;
	int numOfGames, numOfAchievements, numOfinputScore, numOfPlatforms, platformSelect, gameSelect, inputScore;
	bool menu = true;

	// Create a user input size for games
	std::cout << "How many consoles?: ";
	std::cin >> numOfPlatforms;
	platformPtr = new Platform[numOfPlatforms];

	for (int i = 0; i < numOfPlatforms; ++i)
	{
		cout << "Enter name of console: (" << i << "/" << numOfPlatforms << ")" << endl;
		cin >> inputPlatform;
		platformPtr[i].setName(inputPlatform);

		cout << "Enter name of manufacturer" << endl;
		cin >> inputManufacturer;
		platformPtr[i].setManufacturer(inputManufacturer);
	}

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
			if (platformPtr[platformSelect].hasGame == false)
			{
				cout << "How many Games do you want entered?: ";
				cin >> numOfGames;
				platformPtr[platformSelect].numGames = numOfGames;
				platformPtr[platformSelect].gamePtr = new Game[numOfGames];

				for (int i = 0; i < platformPtr[platformSelect].numGames; i++)
				{
					cout << "What game are you entering? (" << i << "/" << platformPtr[platformSelect].numGames << ")" << endl;
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cin >> inputGame;
					platformPtr[platformSelect].gamePtr[i].setGame(inputGame);

					cout << "What publisher? \n";
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cin >> inputPublisher;
					platformPtr[platformSelect].gamePtr[i].setPublisher(inputPublisher);

					cout << "What developer? \n";
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cin >> inputDeveloper;
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
						// User enters achievemetns
						if (platformPtr[platformSelect].gamePtr[gameSelect].hasAchievements == false)
						{
							cout << "How many Achievements?: ";
							cin >> numOfAchievements;
							platformPtr[platformSelect].gamePtr[gameSelect].numAchievements = numOfAchievements;
							platformPtr[platformSelect].gamePtr[gameSelect].achievementPtr = new Achievement[numOfAchievements];

							for (int i = 0; i < platformPtr[platformSelect].gamePtr[gameSelect].numAchievements; i++)
							{
								cout << "Enter achievement title? (" << i << "/" << platformPtr[platformSelect].gamePtr[gameSelect].numAchievements << ")" << endl;
								cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								cin >> inputTitle;
								platformPtr[platformSelect].gamePtr[gameSelect].achievementPtr[i].setTitle(inputTitle);

								cout << "Add a Description? \n";
								cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								cin >> inputDescription;
								platformPtr[platformSelect].gamePtr[gameSelect].achievementPtr[i].setDescription(inputDescription);

								cout << "How much is it worth? (points, currency, collectables) etc.\n";
								cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								cin >> inputScore;
								platformPtr[platformSelect].gamePtr[gameSelect].achievementPtr[i].setScore(inputScore);
							}
							platformPtr[platformSelect].gamePtr[gameSelect].hasAchievements == true;
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
			}
		}
	return 0;
	}


	//// Create a user input size for games
	//std::cout << "How many Games do you want entered?: ";
	//std::cin >> sizeOfGList;
	//gameCount.setNumberG(sizeOfGList);

	//// Create a user input size for achievements
	//std::cout << "How many Achievements will this game have?: ";
	//std::cin >> sizeOfAList;
	//achievementCount.setNumberA(sizeOfAList);

	//// Create the array with the size the user input
	//Game* gameArray = new Game[sizeOfGList];
	//Achievement* achievementArray = new Achievement[sizeOfAList];

	//// Array of Games
	//for (int i = 0; i < sizeOfGList; ++i)
	//{
	//	cout << "Enter in the Game\n";
	//	cin >> inputGame;
	//	gameName.setGame(inputGame);

	//	cout << "What Publisher?\n";
	//	cin >> inputPublisher;
	//	gamePublisher.setPublisher(inputPublisher);

	//	cout << "What Developer?\n";
	//	cin >> inputDeveloper;
	//	gameDeveloper.setDeveloper(inputDeveloper);

	//	// Array of Achievements
	//	for (int j = 0; j < sizeOfAList; ++j)
	//	{
	//		cout << "Enter in the Achievement\n";
	//		cin >> inputTitle;
	//		achievementTitle.setTitle(inputTitle);

	//		cout << "Add a Description\n";
	//		cin >> inputDescription;
	//		achievementDescription.setDescription(inputDescription);

	//		cout << "How much is it worth? (points, currency, collectables) etc.\n";
	//		cin >> inputScore;
	//		achievementScore.setScore(inputScore);
	//	}
	//}

	//// Display game list
	//for (int i = 0; i < sizeOfGList; ++i)
	//{
	//	cout << gameName.getGame() << gamePublisher.getPublisher() << gameDeveloper.getDeveloper() << endl;

	//	for (int j = 0; j < sizeOfAList; ++j)
	//	{
	//		cout << achievementTitle.getTitle() << achievementDescription.getDescription() << achievementScore.getScore() << endl;
	//	}
	//}

	////Delete the array
	//delete[] gameArray;
	//delete[] achievementArray;
