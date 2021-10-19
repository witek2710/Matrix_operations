#pragma once
#include <sstream>
#include <algorithm>

class StringHelp {

public:
	static void replace(std::stringstream &ss, const char replaceElement, const char elementToReplace)
	{
		std::string s = ss.str();
		std::replace(s.begin(), s.end(), replaceElement, elementToReplace);
		ss.str(s);
	}

	static int checkSlashes(std::stringstream & ss)
	{
		std::string s = ss.str();
		int n = std::count(s.begin(), s.end(), '/');
		ss.str(s);
		return n; 
	}
	static bool checkIfThereIsNotTwoSlashesInRow(std::stringstream &ss) {

		std::string s = ss.str();
		std::string slash = "/";
		std::string lastCharacter;
		std::string firstCharacter; 
		for (int i = 0; i < s.length(); i++)
		{
			firstCharacter = s[i];
			if (i != 0) {
				lastCharacter = s[i - 1];
			}
			if ((firstCharacter == "/") && (lastCharacter == "/")) return false;
		}

		return true; 
	}
};
