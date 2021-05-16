// William C Coughlin
#pragma once
#ifndef ANIMAL_H
#endif

#include <string>
#include <fstream>

using namespace std;

class Animal {
private:
	string name;
	string type;
	string color;
	string description;
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
	void writeToFileNew(ofstream f, string n, string t, string c, string d, string a) {
		f << "Name: " << n << endl;
		f << "Type: " << t << endl;
		f << "Color: " << c << endl;
		f << "Descpription: " << d << endl;
		f << "Age: " << a << endl;
		f << "\n";
		if (f.fail()) {
			cout << "Failure writing to file." << endl;
		}
	}

	// adds new animal to file, for misc animals without a color
	void writeToFileNew(ofstream f, string n, string s, string d, string a) {
		f << "Name: " << n << endl;
		f << "Species: " << s << endl;
		f << "Descpription: " << d << endl;
		f << "Age: " << a << endl;
		f << "\n";
		if (f.fail()) {
			cout << "Failure writing to file." << endl;
		}
	}
};