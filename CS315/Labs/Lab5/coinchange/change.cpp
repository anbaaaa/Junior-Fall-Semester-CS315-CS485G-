#include <iostream>
#include <vector>

using namespace std;

vector<int> coinamnts;
int mincoins = -1;

void findmincoins(int amountleft, int coins) {
	if (amountleft == 0) {
		if (coins < mincoins || mincoins == -1) mincoins = coins;
	}
	for (int i=0; i<coinamnts.size(); i++) {
		if (amountleft >= coinamnts[i]) {
			findmincoins(amountleft-coinamnts[i], coins+1);
		}
	}
}
	

int main() {
	while (true) {
	cout << "enter the number of k denominations to provide: ";
	int denominations;
	cin >> denominations; 
	cout << "enter your " << denominations << " denominations:" << endl;
	for (int i=0; i<denominations; i++) {
		int number;
		cin >> number;
		coinamnts.push_back(number);
	}
	cout << "enter number of cents to compute for: ";
	int userinput;
	cin >> userinput;
	//userinput*=100;
	int coins=0;
	findmincoins(userinput, coins);
	cout << "minimum number of coins: " << mincoins << endl << endl;
	}
}