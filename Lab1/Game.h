#pragma once
#include <iostream>
using namespace std;

class Game {
private:
	string m_gName,
		m_publisher,
		m_developer;
	int m_NumberOfAcheivements;
public:
	Achievement* achievementPtr;
	bool hasAchievements = false;
	int numAchievements;

	// Constructors
	Game() // Default constructor
	{
		m_gName = "NONE";
		m_publisher = "NONE";
		m_developer = "NONE";
	}
	Game(string gameName, string gamePublisher, string dev)
	{
		m_gName = gameName;
		m_publisher = gamePublisher;
		m_developer = dev;
	}

	// Inline functions
	void setGame(string gName)
	{
		m_gName = gName;
	}
	string getGame()
	{
		return m_gName;
	}

	void setPublisher(string publisher)
	{
		m_publisher = publisher;
	}
	string getPublisher()
	{
		return m_publisher;
	}

	void setDeveloper(string developer)
	{
		m_developer = developer;
	}
	string getDeveloper()
	{
		return m_developer;
	}

	void setNumberA(int numberAchievements)
	{
		m_NumberOfAcheivements = numberAchievements;
	}
	int getNumberA()
	{
		return m_NumberOfAcheivements;
	}
};