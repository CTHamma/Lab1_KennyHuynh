#pragma once
#include <iostream>
using namespace std;

class Platform {
private:
	string m_name,
		m_manufacturer;
	int m_numberOfGames;
public:
	// Constructors
	Platform() // Default constructor
	{
		m_name = "NONE";
		m_manufacturer = "NONE";
	}
	Platform(string console, string company)
	{
		m_name = console;
		m_manufacturer = company;
	}

	// Inline functions
	string getName()
	{
		return m_name;
	}
	string getManufacturer()
	{
		return m_manufacturer;
	}
	void getNumberG(int numberGames[]);
};