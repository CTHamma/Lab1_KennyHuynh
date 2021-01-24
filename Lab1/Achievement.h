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
	void setTitle(string award)
	{
		m_title = award;
	}
	string getTitle()
	{
		return m_title;
	}

	void setDescription(string detail)
	{
		m_description = detail;
	}
	string getDescription()
	{
		return m_description;
	}

	void setScore(int points)
	{
		m_score = points;
	}
	int getScore()
	{
		return m_score;
	}
};