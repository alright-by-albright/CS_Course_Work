#include <iostream>
using namespace std;

int Josephus(int, int);

int main() {
	int n, m, winner;
	cout << "Let's play Hot Potato!\n";
	cout << "Please enter the number of players:\n";
	cin >> n;
	//cin.ignore();
	//cin.clear();
	cout << "Please enter the number of passes before a player is eliminated:\n";
	cin >> m;
	//cin.ignore();
	//cin.clear();
	winner = Josephus(n, m);
	cout << "The winner is player " << winner << "!\n";
}

int Josephus(int n, int m) {
	if (n == 1) return 1;
	else return (Josephus(n - 1, m) + m - 1) % n + 1;
}