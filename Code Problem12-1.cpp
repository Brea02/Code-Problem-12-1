#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstdlib>
#include<iomanip>

using namespace std;

//function prototypes
void pressEnterToContinue();
bool readFromFile(string filename);

int main() {
	string datafile;
	cout << "P12-1 program!\n";
	cout << "Enter filename: ";
	getline(cin, datafile);
	bool status = readFromFile(datafile);
	if (status) cout << "Success!\n";
	else cout << "failure. :-( \n";
	pressEnterToContinue();
}

//functions

bool readFromFile(string filename) {
	ifstream inFile;		//input filestream for reading in our data
	int countCharacter = 0;
	int countWord = 0;
	inFile.open(filename);	//attempt to open the specified text file

	if (inFile.fail()) {	//error when problem occurs
		cout << "read error - sorry\n";
		return false;
	}
	//from in class stuff
	if (inFile.is_open()) {

		string word, wordAtPosn;
		char ch;

		while (!inFile.eof()) {
			inFile >> word;
			countWord++;

			//cout << setw(2) << countWord << ". " << left << setw(20) << word << right;

			int i = 0;
			//int countCharacter;
			while (i < word.length()) {
				ch = tolower(word.at(i));
				if (ch != ' ') {
					//countAllVowels++;
					countCharacter++;
				}
				i++;
			}
		}
		cout << "Words: " << countWord << endl;
		cout << "Characters: " << countCharacter << endl;
	}

	/*
	//if here then read in data until we're done
	while (true) {
		//inFile >> movieTitle >> year;
		if (inFile.fail()) break; //when there no more data to read

		//cout << movieTitle << ": " << year << endl;
	}
	*/
	//close the file and return
	inFile.close();
	return true;
}


//
void pressEnterToContinue() {
	cout << "\nPress enter to continue... \n";
	cin.clear();
	while (cin.get() != '\n') continue;
}