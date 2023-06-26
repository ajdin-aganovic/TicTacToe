#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

/*

	0 1 2
	3 4 5
	6 7 8

*/

void TTTSketch(char ttt[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i % 3 == 0 && i != 0)
			cout << endl;
		cout << "[ " << ttt[i] <<" ]";
	}
	cout << endl;
}

bool isWin(char ttt[])
{ 
	

	if ((ttt[0] == ttt[1] && ttt[1] == ttt[2]))
		return true;
	else if ((ttt[3] == ttt[4] && ttt[4]== ttt[5]))
		return true; 	   		
	else if ((ttt[6] == ttt[7] && ttt[7]== ttt[8]))
		return true; 
	else if ((ttt[0] == ttt[3] && ttt[3]==ttt[6]))
		return true; 
	else if ((ttt[1] == ttt[4] && ttt[4]==ttt[7]))
		return true; 
	else if ((ttt[2] == ttt[5] && ttt[5]==ttt[8]))
		return true;
	else if ((ttt[0] == ttt[4] && ttt[4]==ttt[8]))
		return true; 
	else if ((ttt[2] == ttt[4] && ttt[4]==ttt[6]))
		return true;

	return false;
}

void main()
{
	string user1, user2 = "";
	cout << "Please enter username for the Player 1" << endl;
	cin >> user1;
	cout << "Please enter username for the Player 2" << endl;
	cin >> user2;

	char ttt[] = {'1','2','3','4','5','6','7','8','9'};
	int position = 0;

	string currentUser = "";
	string otherUser = "";

	int picker = rand() % 1;
	if (picker == 0)
	{
		currentUser = user1;
		otherUser = user2;
	}
	else
	{
		currentUser = user2;
		otherUser = user1;
	}
	cout << "First move: " << currentUser << endl;
	system("cls");

	for (int i = 0; i < 9; i++)
	{
		if (i % 2 == 0) {
			cout << currentUser + " please make your move" << endl;
			TTTSketch(ttt, 9);
			cin >> position;
			ttt[position - 1] = 'X';
			if (isWin(ttt) == true)
			{
				cout << "Congratulations " << currentUser << "\nYou won" << endl;
				TTTSketch(ttt, 9);
				break;
			}
			system("CLS");
		}
		else
		{
			cout << otherUser << " please make your move" << endl;
			TTTSketch(ttt, 9);
			cin >> position;
			ttt[position - 1] = 'O';
			if (isWin(ttt) == true)
			{
				cout << "Congratulations " << otherUser << "\nYou won" << endl;
				TTTSketch(ttt, 9);
				break;
			}
			system("CLS");

		}
	}

	if (isWin(ttt) == false || isWin(ttt) == false)
	{
		cout << "It is a draw" << endl;
		TTTSketch(ttt,9);
	}
	
	
}