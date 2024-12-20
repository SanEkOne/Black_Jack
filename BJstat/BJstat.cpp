#include <iostream>
#include <fstream> 
#include <string> 
#include <ctime>

using namespace std;

int totalPoints = 0;

void Points(int winPoints) {
	totalPoints += winPoints;
}

int GetCard() {
	srand(time(NULL));
	return 1 + rand() % 11;
}

void OpenCards(int PlayerFirstCard, int PlayerSecondCard, int PlayerThirdCard, int DealerFirstCard, int DealerSecondCard, int DealerThirdCard) {
	cout << "Sum of your cards: ";
	int PlayerSum = PlayerFirstCard + PlayerSecondCard + PlayerThirdCard;
	cout << PlayerSum << endl;
	cout << "Sum of dealer cards: ";
	int DealerSum = DealerFirstCard + DealerSecondCard + DealerThirdCard;
	cout << DealerSum << endl;
	if (PlayerSum > 21) {
		cout << "You lose" << endl;
	}
	else if (PlayerSum == 21) {
		cout << "You win" << endl;
		Points(10);
	}
	else if (DealerSum > 21) {
		cout << "You win" << endl;
		Points(10);
	}
	else if (DealerSum == 21) {
		cout << "You lose" << endl;
	}
	else if (21 - DealerSum < 21 - PlayerSum) {
		cout << "You lose" << endl;
	}
	else if (21 - DealerSum > 21 - PlayerSum) {
		cout << "You win" << endl;
		Points(10);
	}
	else if (DealerSum == PlayerSum) {
		cout << "Draw" << endl;
		Points(5);
	}
}
void OpenSecondCards(int PlayerFirstCard, int PlayerSecondCard, int PlayerThirdCard, int PlayerFourthCard, int DealerFirstCard, int DealerSecondCard, int DealerThirdCard, int DealerFourthCard) {
	cout << "Sum of your cards: ";
	int PlayerSum = PlayerFirstCard + PlayerSecondCard + PlayerThirdCard + PlayerFourthCard;
	cout << PlayerSum << endl;
	cout << "Sum of dealer cards: ";
	int DealerSum = DealerFirstCard + DealerSecondCard + DealerThirdCard + DealerFourthCard;
	cout << PlayerSum << endl;
	if (PlayerSum > 21) {
		cout << "You lose" << endl;
	}
	else if (PlayerSum == 21) {
		cout << "You win" << endl;
		Points(10);
	}
	else if (DealerSum > 21) {
		cout << "You win" << endl;
		Points(10);
	}
	else if (DealerSum == 21) {
		cout << "You lose" << endl;
	}
	else if (21 - DealerSum < 21 - PlayerSum) {
		cout << "You lose" << endl;
	}
	else if (21 - DealerSum > 21 - PlayerSum) {
		cout << "You win" << endl;
		Points(10);
	}
	else if (DealerSum == PlayerSum) {
		cout << "Draw" << endl;
		Points(5);
	}
}

void OpenThirdCards(int PlayerFirstCard, int PlayerSecondCard, int PlayerThirdCard, int PlayerFourthCard, int PlayerFifthCard, int DealerFirstCard, int DealerSecondCard, int DealerThirdCard, int DealerFourthCard, int DealerFifthCard) {
	cout << "Sum of your cards: ";
	int PlayerSum = PlayerFirstCard + PlayerSecondCard + PlayerThirdCard + PlayerFourthCard + PlayerFifthCard;
	cout << PlayerSum << endl;
	cout << "Sum of dealer cards: ";
	int DealerSum = DealerFirstCard + DealerSecondCard + DealerThirdCard + DealerFourthCard + DealerFifthCard;
	cout << PlayerSum << endl;
	if (PlayerSum > 21) {
		cout << "You lose" << endl;
	}
	else if (PlayerSum == 21) {
		cout << "You win" << endl;
		Points(10);
	}
	else if (DealerSum > 21) {
		cout << "You win" << endl;
		Points(10);
	}
	else if (DealerSum == 21) {
		cout << "You lose" << endl;
	}
	else if (21 - DealerSum < 21 - PlayerSum) {
		cout << "You lose" << endl;
	}
	else if (21 - DealerSum > 21 - PlayerSum) {
		cout << "You win" << endl;
		Points(10);
	}
	else if (DealerSum == PlayerSum) {
		cout << "Draw" << endl;
		Points(5);
	}
}

int StartGame() {
	srand(time(NULL));

	int FirstDealerCard = 1 + rand() % 11;
	int SecondDealerCard = 1 + rand() % 11;
	cout << "Dealer cards:" << endl;
	cout << FirstDealerCard << " and " << 'X' << endl;

	cout << "Your cards: " << endl;
	int FirstCard = 1 + rand() % 11;
	int SecondCard = 1 + rand() % 11;
	cout << FirstCard << " and " << SecondCard << endl;
	if (FirstCard + SecondCard == 21) {
		cout << "You win" << endl;
		Points(10);
		return 0;
	}
	else if (FirstCard + SecondCard > 21) {
		cout << "You lose" << endl;
		return 0;
	}
	else if (FirstDealerCard + SecondDealerCard == 21) {
		cout << "You lose" << endl;
		cout << "Dealer cards:" << endl;
		cout << FirstDealerCard << " " << SecondDealerCard << endl;
		return 0;
	}
	else if (FirstDealerCard + SecondDealerCard > 21) {
		cout << "You win" << endl;
		cout << "Dealer cards:" << endl;
		cout << FirstDealerCard << " " << SecondDealerCard << endl;
		Points(10);
		return 0;
	}

	cout << endl;
	cout << "Add card?\nyes/no" << endl;
	char answer;
	cin >> answer;
	cout << endl;

	int newCard = 0;
	int DealerNewCard = 0;

	if (answer == 'y') {
		newCard = GetCard();
		cout << "New card: " << newCard << endl;
		cout << "Your cards:\n" << FirstCard << " and " << SecondCard << " and " << newCard << endl;

		if (FirstCard + SecondCard + newCard == 21) {
			cout << "You win" << endl;
			Points(10);
			return 0;
		}
		else if (FirstCard + SecondCard + newCard > 21) {
			cout << "You lose" << endl;
			return 0;
		}

		DealerNewCard = 1 + rand() % 11;
		if (FirstDealerCard + SecondDealerCard + DealerNewCard == 21) {
			cout << "You lose" << endl;
			cout << "Dealer cards:" << endl;
			cout << FirstDealerCard << " " << SecondDealerCard << " " << DealerNewCard << endl;
			return 0;
		}
		else if (FirstDealerCard + SecondDealerCard + DealerNewCard > 21) {
			cout << "You win" << endl;
			cout << "Dealer cards:" << endl;
			cout << FirstDealerCard << " " << SecondDealerCard << " " << DealerNewCard << endl;
			Points(10);
			return 0;
		}
	}
	else if (answer == 'n') {
		OpenCards(FirstCard, SecondCard, newCard, FirstDealerCard, SecondDealerCard, DealerNewCard);
		return 0;
	}

	cout << endl;
	cout << "Add card?\nyes/no" << endl;
	char answer2;
	cin >> answer2;
	cout << endl;

	int newCard2 = 0;
	int DealerNewCard2 = 0;
	DealerNewCard2 = 1 + rand() % 11;
	if (answer2 == 'y') {
		newCard2 = GetCard();
		cout << "New card: " << newCard2 << endl;
		cout << "Your cards:\n" << FirstCard << " and " << SecondCard << " and " << newCard << " and " << newCard2 << endl;

		if (FirstCard + SecondCard + newCard + newCard2 == 21) {
			cout << "You win" << endl;
			Points(10);
			return 0;
		}
		else if (FirstCard + SecondCard + newCard + newCard2 > 21) {
			cout << "You lose" << endl;
			return 0;
		}


		if (FirstDealerCard + SecondDealerCard + DealerNewCard + DealerNewCard2 == 21) {
			cout << "You lose" << endl;
			cout << "Dealer cards:" << endl;
			cout << FirstDealerCard << " " << SecondDealerCard << " " << DealerNewCard << " " << DealerNewCard2 << endl;
			return 0;
		}
		else if (FirstDealerCard + SecondDealerCard + DealerNewCard + DealerNewCard2 > 21) {
			cout << "You win" << endl;
			cout << "Dealer cards:" << endl;
			cout << FirstDealerCard << " " << SecondDealerCard << " " << DealerNewCard << " " << DealerNewCard2 << endl;
			Points(10);
			return 0;
		}
	}
	else if (answer2 == 'n') {
		OpenSecondCards(FirstCard, SecondCard, newCard, newCard2, FirstDealerCard, SecondDealerCard, DealerNewCard, DealerNewCard2);
		return 0;
	}

	cout << endl;
	cout << "Add card?\nyes/no" << endl;
	char answer3;
	cin >> answer3;
	cout << endl;

	int newCard3 = 0;
	int DealerNewCard3 = 0;
	DealerNewCard3 = 1 + rand() % 11;
	if (answer3 == 'y') {
		newCard3 = GetCard();
		cout << "New card: " << newCard3 << endl;
		cout << "Your cards:\n" << FirstCard << " and " << SecondCard << " and " << newCard << " and " << newCard2 << " and " << newCard3 << endl;
		if (FirstCard + SecondCard + newCard + newCard2 + newCard3 == 21) {
			cout << "You win" << endl;
			Points(10);
			return 0;
		}
		else if (FirstCard + SecondCard + newCard + newCard2 + newCard3 > 21) {
			cout << "You lose" << endl;
			return 0;
		}


		DealerNewCard3 = 1 + rand() % 11;
		if (FirstDealerCard + SecondDealerCard + DealerNewCard + DealerNewCard2 + DealerNewCard3 == 21) {
			cout << "You lose" << endl;
			cout << "Dealer cards:" << endl;
			cout << FirstDealerCard << " " << SecondDealerCard << " " << DealerNewCard << " " << DealerNewCard2 << " " << DealerNewCard3 << endl;
			return 0;
		}
		else if (FirstDealerCard + SecondDealerCard + DealerNewCard + DealerNewCard2 + DealerNewCard3 > 21) {
			cout << "You win" << endl;
			cout << "Dealer cards:" << endl;
			cout << FirstDealerCard << " " << SecondDealerCard << " " << DealerNewCard << " " << DealerNewCard2 << " " << DealerNewCard3 << endl;
			Points(10);
			return 0;
		}
	}
	else if (answer3 == 'n') {
		OpenThirdCards(FirstCard, SecondCard, newCard, newCard2, newCard3, FirstDealerCard, SecondDealerCard, DealerNewCard, DealerNewCard2, DealerNewCard3);
	}

	return 0;
}





int main() {

	char name[50];
	cout << "Enter your name: " << endl;
	cin >> name;
	cout << endl;

	char playAgain;
	do {
		StartGame();
		cout << endl;
		cout << "Play again\nyes/no" << endl;
		cin >> playAgain;
		cout << endl;
	} while (playAgain == 'y');

	cout << "Total points: " << totalPoints << endl;
	return 0;


	ofstream outFile("stat.txt");
	outFile << name << " " << totalPoints << endl;
	outFile.close();

	ifstream inFile("stat.txt");
	char line[50];
	while (inFile.getline(line, 50)) {
		cout << line << endl;
	}
	inFile.close();
}