// William C Coughlin
#pragma once
#ifndef ANIMAL_H
#endif

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Animal {
private:
	string name;
	string type;
	string color;
	string description;
	string goodWithKids;
	string age;
	
public:
	Animal(string n, string t, string c, string d, string a) {
		name = n;
		type = t;
		color = c;
		description = d;
		age = a;
	}

	void setName(string n) {
		name = n;
	}

	string getName() {
		return name;
	}

	void setType(string t) {
		type = t;
	}

	string getType() {
		return type;
	}

	void setColor(string c) {
		color = c;
	}

	string getColor() {
		return color;
	}

	void setDescription(string d) {
		description = d;
	}

	string getDescription() {
		return description;
	}

	void setAge(double a) {
		age = a;
	}

	string getAge() {
		return age;
	}

	// adds new animal to file
	void writeToFileNew(string f, const string n, const string t, const string c, const string d, const string g, const string a) {
		ofstream file(f, ios::app);
		file << "Name: " << n << " Breed: " << t << " Color: " << c << " Description: " << d << " Good With Kids: " << g << " Age: " << a << endl;

		if (file.fail()) {
			cout << "Failure writing to file." << endl;
		}
		else
			cout << "Writing Successful" << endl;
	}

	// adds new animal to file, for misc animals without a color
	void writeToFileNew(string f, const string n, const string s, const string d, const string a) {
		ofstream file(f, ios::app);
		file << "Name: " << n << " Species: " << s << " Description: " << d  << " Age: " << a << endl;
		
		if (file.fail()) {
			cout << "Failure writing to file." << endl;
		}
		else
			cout << "Writing Successful" << endl;
		file.close();
	}

	
	// Searches file for entry by name
	static void searchFileForEntry(string f, const string n) {
		ifstream file(f);
		bool ENTRY_FOUND = false;
		string LINE;
		while (!file.eof() && !ENTRY_FOUND) {
			getline(file , LINE);
			int SEARCH = LINE.find(n, 0);
			if (SEARCH > 0) {
				ENTRY_FOUND = true;
				cout << LINE + "\n";
			}
		}
		file.close();
		if (!ENTRY_FOUND) {
			cout << "No record could be found" << endl;
		}
	}

	// Searches file for entry by name then removes it
	static void removeEntryFromFile(string f, string tempF, const string n) {
		ifstream inFile(f);
		ofstream tempOutFile(tempF, ios::trunc);
		bool ENTRY_FOUND = false;
		string LINE;

		while (!inFile.eof()) {
			getline(inFile, LINE);
			int SEARCH = LINE.find(n, 0);
			if (SEARCH == -1) {
				tempOutFile << LINE + "\n";
			}
			else if (SEARCH > 0) {
				ENTRY_FOUND = true;
			}
		}

		inFile.close();
		tempOutFile.close();

		if (!ENTRY_FOUND) {
			cout << "No record could be found" << endl;
		}
		else {
			ofstream outFile(f, ios::trunc);
			ifstream tempInFile(tempF);
			while (!tempInFile.eof()) {
				getline(tempInFile, LINE);
				outFile << LINE << endl;
			}
			cout << "Record successfully removed" << endl;
		}
	}
};