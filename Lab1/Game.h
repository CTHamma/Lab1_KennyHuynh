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
	string getGame()
	{
		return m_gName;
	}
	string getPublisher()
	{
		return m_publisher;
	}
	string getDeveloper()
	{
		return m_developer;
	}
	void getNumberA(int numberAchievements[]);
};