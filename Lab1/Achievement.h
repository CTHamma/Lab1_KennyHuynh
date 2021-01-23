#pragma once
#include <iostream>
using namespace std;

class Achievement {
private:
	string m_title,
		m_description;
	int m_score;
public:
	// Constructors
	Achievement() // Default constructor
	{
		m_title = "NONE";
		m_description = "NONE";
		m_score = 0;
	}
	Achievement(string award, string detail, int value)
	{
		m_title = award;
		m_description = detail;
		m_score = value;
	}

	// Inline functions
	string getTitle()
	{
		return m_title;
	}
	string getDescription()
	{
		return m_description;
	}
	int getScore()
	{
		return m_score;
	}
};