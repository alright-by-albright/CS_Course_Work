#include <iostream>
using namespace std;

int Josephus(int, int);

int main() {
	int n, m, winner;
	cout << "Let's play Hot Potato!\n";
	cout << "Please enter the number of players:\n";
	cin >> n;
	cout << "Please enter the number of passes before a player is eliminated:\n";
	cin >> m;
	winner = Josephus(n, m);
	cout << "The winner is player " << winner << "!\n";
}

// This is the function that will be called recursively to solve our hot potato problem.  As long as n isn't 1,
// the function is repeatedly called with the party size (n) decrimented by 1 and number of passes per round (m).
// The result is increased by the 1 less than the number of passes per round, then the modulus of n incrimented
// by 1 is finally returned.
// Why the extra bit? Specifically the m-1) % n + 1.
// This is because the function is looking at the position with n - 1 participants, but we're actually starting
// at n. The m - 1 % n + 1 lets us adjust the position for the correct starting position.

int Josephus(int n, int m) {
	if (n == 1) return 1;
	else return (Josephus(n - 1, m) + m - 1) % n + 1;
}
// By using this recursive solution we've solved the Josephus problem in O(n) time for a strictly linear
// time complexity growth as the number of inputs increases. Several potential solutions were examined before 
// this solution was chosen for its efficiency. The basis for this code was found on geeksforgeeks.

// A vector and list based solutions using push_back or popping were considered, but not chosen due to 
// more punishing time complexities of O(n^2)