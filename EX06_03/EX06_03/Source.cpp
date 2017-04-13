#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	int year;
	string rankOutput;
	char g, genderInput;
	string nameInput;
	string filename = "yob";
	cout << "Enter the year: ";
	cin >> year;
	filename += (to_string(year) + ".txt"); //creating filename
	//to_string() converts int year to string ??
	
	do {
		cout << "Enter the gender (F or M): ";
		cin >> genderInput;
		g = toupper(genderInput);
		if (g != 'F' && g != 'M')
			cout << "ERROR. Character entered is not an option." << endl;
	} while (g != 'F' && g != 'M');

	cout << "Enter the name: "; //needs correct capitalization
	cin >> nameInput;

	fstream file;
	file.open(filename, ios::in);
	if (file.fail()) {
		cout << "can't open file" << endl;
		return 0;
	}
	string word;
	vector<string> name;
	vector<string> gender;
	vector<string> rank;
	while (file >> word) {
		name.push_back(word);
		file >> word;
		gender.push_back(word);
		file >> word;
		rank.push_back(word);
	}
	int save = -1;
	for (int i = 0; i < name.size(); i++) {
		if (name[i] == nameInput && gender[i][0] == genderInput) 
			save = i;
	}
	if (save != -1) {
		rankOutput = rank[save];
		cout << nameInput << " is ranked #" << rankOutput << " in the year " << year << endl;
	}
	else
		cout << "SRRY dont have that one" << endl;
}