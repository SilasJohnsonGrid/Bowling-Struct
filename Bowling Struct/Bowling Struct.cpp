// Bowling Struct.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>

#include<iomanip>

#include<fstream>

using namespace std;

// # of players
#define NO_PLAYERS 10

// define and make the struct
struct BowlingS
{
	char names[NO_PLAYERS][100];

	int scores[NO_PLAYERS][6];

	double avg_scores[NO_PLAYERS];

	int n;
};

// making the GetBowlingData function to read and take the names and scores from, also pass by reference
bool GetBowlingData(BowlingS& Read) {

	// reading BowlingScores.txt

	ifstream in("BowlingScores1.txt");

	// Check
	if (!in.fail())

	{
		while (!in.eof())

		{
			// reading the text
			in >> Read.names[Read.n] >> Read.scores[Read.n][0] >> Read.scores[Read.n][1] >> Read.scores[Read.n][2] >> Read.scores[Read.n][3] >> Read.scores[Read.n][4] >> Read.scores[Read.n][5];
			
			Read.n++;

		}
		
		// returning true or false
		return true;

	}

	return false;

}
// Calculating the average scores also pass by reference
void GetAverageScore(BowlingS& Score) {

	// for loop to check all the scores
	for (int i = 0; i < Score.n; i++)
	{

		Score.avg_scores[i] = 0;
		// adding all the scores up and dividing to get the average
		for (int j = 0; j < 6; j++)
		{

			Score.avg_scores[i] += Score.scores[i][j];

		}

		Score.avg_scores[i] = Score.avg_scores[i] / 6.0;

	}

}



//printing the results and pass by reference
void PrettyPrintResults(BowlingS& Print) {

	// lineing up the results and spacing them out
	cout << left << setw(15) << "Name" << "Score1\tScore2\tScore3\tScore4\tScore5\tScore6\tAvg_Score" << endl;

	for (int i = 0; i < Print.n; i++)
	{
		cout << left << setw(15) << Print.names[i] << "\t";

		for (int j = 0; j < 6; j++)

			cout << Print.scores[i][j] << "\t";

		cout << fixed << Print.avg_scores[i] << endl;
	}
}
int main() {

	BowlingS Bowling;

	//set the n value to 0

	Bowling.n = 0;

	// calling the functions 
	if (GetBowlingData(Bowling))
	{
		GetAverageScore(Bowling);

		PrettyPrintResults(Bowling);

	}

	system("pause");

	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
