// Programmed by William C Coughlin

#include <iostream>
#include <fstream>
#include <string>
#include "Animal.h"

using namespace std;

void displayMenu();
ofstream openOutFile(const char*);
void closeOutFile(const char*);
ifstream openInFile(const char*);
void closeInFile(const char*);

int main() {
	const char* dogFile = "DogData.txt";
	const char* catFile = "CatData.txt";
	const char* miscFile = "MiscAnimalData.txt";

	
	char response;

	do {

		displayMenu();

		cin >> response;

		// Tests if user inputted valid response & asks for correct response until given
		while (response != '1' && response != '2' && response != '3' && response != '4' && response != '5' && response != '6') {
			cout << "Invalid response...\nPlease enter valid operation" << endl;
			cin.clear();
			cin.ignore(1000, 'n');
			cin >> response;
		}

		// Gets input from user and enters it as new entry to file
		if (response == '1') {
			string name;
			string species;
			string type;
			string color;
			string description;
			string age;

			cin.ignore(1000, '\n');
			cout << "Is animal a dog, cat, or other? (For other enter species name)" << endl;
			getline(cin, species);
			cout << "Please enter the following information..." << endl;
			cout << "Name: ";
			getline(cin, name);
			if (species == "dog" || species == "Dog" || species == "cat" || species == "Cat") {
				cout << "Breed: ";
				getline(cin, type);
				cout << "Color: ";
				getline(cin, color);
			}
			
			cout << "Description: ";
			getline(cin, description);
			cout << "Age (in years): ";
			getline(cin, age);

			Animal animalEntry(name, type, color, description, age);
			if (species == "Dog" || species == "dog") {
				animalEntry.writeToFileNew(openOutFile(dogFile), name, type, color, description, age);
				closeOutFile(dogFile);
			}
			else if (species == "Cat" || species == "cat") {
				animalEntry.writeToFileNew(openOutFile(catFile), name, type, color, description, age);
				closeOutFile(catFile);
			}
			else {
				animalEntry.writeToFileNew(openOutFile(miscFile), name, species, description, age);
				closeOutFile(miscFile);
			}
		}
		else if (response == '2') {
			cout << "Call to search" << endl;
		}
		else if (response == '3') {
			cout << "Call to view all" << endl;
		}
		else if (response == '4') {
			cout << "Call to remove" << endl;
		}
		else if (response == '5') {
			cout << "Call to update" << endl;
		}
	} while (response != '6');
	return 0;
}

// Displays menu with list of available operations
void displayMenu() {
	cout << "What operation would you like to perform?" << endl;
	cout << "*********************************************" << endl;
	cout << "Enter:" << endl;
	cout << "\t1. Add new animal to database" << endl;
	cout << "\t2. Search database" << endl;
	cout << "\t3. View all records in database" << endl;
	cout << "\t4. Remove animal from database" << endl;
	cout << "\t5. Update animal info" << endl;
	cout << "\t6. Quit" << endl;
}

// Opens file for writing to
ofstream openOutFile(const char* n) {
	ofstream f(n, ios::out|ios::app);
	if (f.fail()) {
		cout << "File failed to open." << endl;
	}
	else {
		std::cout << "File opened in writing mode: " << n << endl;
		return f;
	}
}

// Closes an output file
void closeOutFile(const char* n) {
	ofstream f;
	f.close();
}

// Open file for reading from
ifstream openInFile(const char* n) {
	ifstream f(n);
	if (f.fail()) {
		std::cout << "File failed to open." << endl;
	}
	else {
		std::cout << "File opened in reading mode: " << n << endl;
		return f;
	}
}

// Closes an input file
void closeInFile(const char* n) {
	ifstream f(n);
	f.close();
}
