#include <iostream>
#include <math.h>
#include <cstdlib>
#include <time.h>

using namespace std;

const int IGNORE_CHARS = 256;
const int OFFSET = 1;
const int RANGE = 9;

int GetNumberFromUser();
int GetSecretNumber();
bool IsGuessNumberValid(int number);
bool IsGuessNumberMatchSecretNumber(int guessNumber, int secretNumber);
bool PromptUserPlayAgain();
void ResetInformationGame();
void RunProgram();


int numberOfGuesses = log(RANGE);

int main() {

	RunProgram();

	return 0;
}

void RunProgram() {
	srand((unsigned)time(NULL));

	int secretNumber = GetSecretNumber();

	do
	{
		cout << "The range of the number between " << OFFSET << " and " << RANGE << endl;
		int guessNumber = GetNumberFromUser();

		while (numberOfGuesses > 0 && !IsGuessNumberMatchSecretNumber(guessNumber, secretNumber)) {
			cout << "Please guess again!!" << endl;
			guessNumber = GetNumberFromUser();
		}

	} while(PromptUserPlayAgain());

	cout << "See you again :3";
}

void ResetInformationGame() {
	numberOfGuesses = log(RANGE);
}

bool PromptUserPlayAgain() {
	system("CLS");
	bool isAgain = false;
	if (numberOfGuesses <= 0) {
		cout << "Your turn is over!" << endl;
	}
	char c;
	cout << "Do you want to play again? Enter Y" << endl;
	cout << "Choose: ";
	cin >> c;

	if (c == 'Y' || c == 'y') {
		system("CLS");
		isAgain = true;
		ResetInformationGame();
	}

	return isAgain;
}


bool IsGuessNumberMatchSecretNumber(int guessNumber, int secretNumber) {
	bool isMatched = false;

	if (guessNumber > secretNumber) {
		cout << "The guess number is greater than the secret number" << endl;
		--numberOfGuesses;
	}
	else if (guessNumber < secretNumber) {
		cout << "The guess number is less than the secret number" << endl;
		--numberOfGuesses;
	}
	else {
		cout << "Congratulation, Your answer is exactly the secret number :>" << endl;
		isMatched = true;
		ResetInformationGame();
	}

	return isMatched;
}

int GetSecretNumber() {
	return OFFSET + (rand() % RANGE);
}

bool IsGuessNumberValid(int number) {
	return number < OFFSET || number > RANGE;
}

int GetNumberFromUser() {
	bool failure;
	int number;
	do {
		failure = false;
		cout << "Please enter the guess number: ";
		cin >> number;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(IGNORE_CHARS, '\n');
			failure = true;
			cout << "Please enter again!The number is not valid!" << endl;
			//--numberOfGuesses;
		}
		else if (IsGuessNumberValid(number)) {
			cout << "The number is not valid" << endl;
			//--numberOfGuesses;
			failure = true;
		}
	} while (failure && numberOfGuesses > 0);

	return number;
}
