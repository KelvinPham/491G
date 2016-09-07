#include <iostream>
#include <random>
using namespace std;

int main(int argc, char* argv[]) {
	const int LARGEST_POSSIBLE = 3;
	const int NUMBER_OF_PRIZES = 5;
	
	random_device rd;
	default_random_engine engine(rd());


	uniform_int_distribution<int> distr(1, LARGEST_POSSIBLE);
	uniform_int_distribution<int> rand(1, NUMBER_OF_PRIZES);
	
	int winningDoor = distr(engine);
	int prizes = rand(engine);

	int choice;
	cout << "Select a door to choose from 1-3 \n";
	cin >> choice;
	int revealGoat = distr(engine);
	if (winningDoor == 1) {
		while (revealGoat == winningDoor || revealGoat == choice) {
			 revealGoat = distr(engine);
		}
		if (revealGoat == 2) {
			cout << "Behind Door Number 2 is a Goat \n ";
		}
		else {
			cout << "Behind Door Number 3 is a Goat \n";
		}
	}
	if (winningDoor == 2) {
		while (revealGoat == winningDoor || revealGoat == choice) {
			int revealGoat = distr(engine);
		}
		if (revealGoat == 1) {
			cout << "Behind Door Number 1 is a Goat \n";
		}
		else {
			cout << "Behind Door Number 3 is a Goat \n";
		}
	}
	if (winningDoor == 3) {
		while (revealGoat == winningDoor || revealGoat == choice) {
			int revealGoat = distr(engine);
		}
		if (revealGoat == 1) {
			cout << "Behind Door Number 1 is a Goat \n";
		}
		else {
			cout << "Behind Door Number 2 is a Goat \n";
		}
	}
	char swap;
	int swappedDoor;
	cout << "Do you want to switch the other unknown door? y/n \n";
	cin >> swap;
	if (swap == 'y' || swap == 'Y') {
		swappedDoor = distr(engine);
		while (swappedDoor == revealGoat || swappedDoor == choice) {
			swappedDoor = distr(engine);
		}
		choice == swappedDoor;
	}
	if (choice == winningDoor) {
		if (prizes == 1) {
			cout << "Congrats you won the prize of a new car \n";
		}
		else if (prizes == 2) {
			cout << "Congrats you won the prize of a vacation in Hawaii \n";
		}
		else if (prizes == 3) {
			cout << "Congrats you won the prize of five grand \n";
		}
		else if (prizes == 4) {
			cout << "Congrats you won the prize of a house \n";
		}
		else {
			cout << "Congrats you won the prize goat food \n";
		}
	}
	else {
		cout << "Sorry you got the goat \n";
	}

}
