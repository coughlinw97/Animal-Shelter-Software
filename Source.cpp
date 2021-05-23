// Programmed by William C Coughlin

#include <iostream>
#include <fstream>
#include <string>
#include "Animal.h"

using namespace std;

void displayMenu();

int main() {
	
	char RESPONSE;

	do {

		displayMenu();

		cin >> RESPONSE;

		// Tests if user inputted valid response & asks for correct response until given
		while (RESPONSE != '1' && RESPONSE != '2' && RESPONSE != '3' && RESPONSE != '4' && RESPONSE != '5' && RESPONSE != '6') {
			cout << "Invalid response...\nPlease enter valid operation" << endl;
			cin.clear();
			cin.ignore(1000, 'n');
			cin >> RESPONSE;
		}

		// Gets input from user and enters it as new entry to file
		if (RESPONSE == '1') {
			string name;
			string species;
			string breed;
			string color;
			string description;
			string goodWithKids;
			string age;

			cin.ignore(1000, '\n');
			cout << "Is animal a dog, cat, or other? (For other enter species name)" << endl;
			getline(cin, species);
			cout << "Please enter the following information..." << endl;
			cout << "Name: ";
			getline(cin, name);

			if (species == "dog" || species == "Dog" || species == "cat" || species == "Cat") {
				cout << "Breed: ";
				getline(cin, breed);
				cout << "Color: ";
				getline(cin, color);
				cout << "Good with kids: ";
				getline(cin, goodWithKids);
				if (goodWithKids == "Yes", "yes", "y", "True", "true") {
					goodWithKids = "Yes";
				}
				else
					goodWithKids = "No";
			}
			
			cout << "Description: ";
			getline(cin, description);
			cout << "Age (in years): ";
			getline(cin, age);

			Animal animalEntry(name, breed, color, description, age);
			if (species == "Dog" || species == "dog") {
				animalEntry.writeToFileNew("DogData.txt", name, breed, color, description, goodWithKids, age);
			}
			else if (species == "Cat" || species == "cat") {
				animalEntry.writeToFileNew("CatData.txt", name, breed, color, description, goodWithKids, age);
			}
			else {
				fstream miscFile("MiscAnimalData.txt", ios::app);
				animalEntry.writeToFileNew("MiscAnimalData.txt", name, species, description, age);
			}
		}

		// Search for entry by name and type
		else if (RESPONSE == '2') {
			string ANIMAL_RESPONSE;
			cout << "What type of animal are you searching for? (Enter 'Dog', 'Cat', or 'Other')" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			getline(cin, ANIMAL_RESPONSE);

			if (ANIMAL_RESPONSE == "Dog" || ANIMAL_RESPONSE == "dog") {
				cout << "Enter name of dog you're searching for" << endl;
				string NAME;
				getline(cin, NAME);
				Animal::searchFileForEntry("DogData.txt", NAME);
			}
			else if (ANIMAL_RESPONSE == "Cat" || ANIMAL_RESPONSE == "cat") {
				cout << "Enter name of cat you're searching for" << endl;
				string NAME;
				getline(cin, NAME);
				Animal::searchFileForEntry("CatData.txt", NAME);
			}
			else if (ANIMAL_RESPONSE == "Other" || ANIMAL_RESPONSE == "other") {
				cout << "Enter name of animal you're searching for" << endl;
				string NAME;
				getline(cin, NAME);
				Animal::searchFileForEntry("MiscAnimalData.txt", NAME);
			}
		}

		else if (RESPONSE == '3') {
			cout << "Call to view all" << endl;
		}

		
		else if (RESPONSE == '4') {
			string ANIMAL_RESPONSE;
			cout << "What type of animal are you removing? (Enter 'Dog', 'Cat', or 'Other')" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			getline(cin, ANIMAL_RESPONSE);

			if (ANIMAL_RESPONSE == "Dog" || ANIMAL_RESPONSE == "dog") {
				cout << "Enter name of dog you're removing" << endl;
				string NAME;
				getline(cin, NAME);
				Animal::removeEntryFromFile("DogData.txt", "TempFile.txt", NAME);
			}

			else if (ANIMAL_RESPONSE == "Cat" || ANIMAL_RESPONSE == "cat") {
				cout << "Enter name of cat you're removing" << endl;
				string NAME;
				getline(cin, NAME);
				Animal::removeEntryFromFile("CatData.Txt", "TempFile.txt", NAME);
			}

			else if (ANIMAL_RESPONSE == "Other" || ANIMAL_RESPONSE == "other") {
				cout << "Enter name of animal you're removing" << endl;
				string NAME;
				getline(cin, NAME);
				Animal::removeEntryFromFile("MiscAnimalData.txt", "TempFile.txt", NAME);
			}
		}
		

		else if (RESPONSE == '5') {
			cout << "Call to update" << endl;
		}

	} while (RESPONSE != '6');

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
