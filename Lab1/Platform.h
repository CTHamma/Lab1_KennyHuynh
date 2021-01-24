#pragma once
#include <iostream>
using namespace std;

class Platform {
private:
	string m_pName,
		m_manufacturer;
	int m_numberOfGames;
public:
	Game* gamePtr;
	bool hasGame = false;
	int numGames;
	// Constructors
	Platform() // Default constructor
	{
		m_pName = "NONE";
		m_manufacturer = "NONE";
	}
	Platform(string console, string company)
	{
		m_pName = console;
		m_manufacturer = company;
	}

	// Inline functions
	void setName(string name)
	{
		m_pName = name;
	}
	string getName()
	{
		return m_pName;
	}

	void setManufacturer(string manufacturer)
	{
		m_manufacturer = manufacturer;
	}
	string getManufacturer()
	{
		return m_manufacturer;
	}

	void setNumberG(int numberGames)
	{
		m_numberOfGames = numberGames;
	}
	int getNumberG()
	{
		return m_numberOfGames;
	}
};