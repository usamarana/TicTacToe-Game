#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

char tictac[3][3] = { '1','2','3','4','5','6','7','8','9' };
bool allocated[9] = {true, true, true, true, true, true, true, true, true};
char user = 'X';
char computer;
char compUser;
int drawNum;
void board()  //in order to display the array above I created a function which will not return anything
{
		system("cls");//this clears the board after each loop
	cout << "\n [Tic Tac Toe] \n Made By Usamarana" << endl;
	for (int i = 0; i < 3; i++) //"i" represents columns 
	{
		cout << "---------------" << endl;
		for (int j = 0; j < 3; j++) //"j" represents rows
		{
			cout << " | ";
			cout << tictac[i][j] << " ";
		}
		cout << endl;
	}
}
int input(int inpt) // place holders for X and O
{
	//---------------------------------------
	if (inpt == 1)
	{
		if (tictac[0][0] == '1')
			tictac[0][0] = user;
		else
		{
			cout << "\nPlace already marked! Try a different place." << endl;
			//			input();
		}
	}
	else if (inpt == 2)
	{
		if (tictac[0][1] == '2')
			tictac[0][1] = user;
		else
		{
			cout << "\nPlace already marked! Try a different place." << endl;
			//			input();
		}
	}
	else if (inpt == 3)
	{
		if (tictac[0][2] == '3')
			tictac[0][2] = user;
		else
		{
			cout << "\nPlace already marked! Try a different place." << endl;
			//			input(inpt);
		}
	}
	//---------------------------
	else if (inpt == 4)
	{
		if (tictac[1][0] == '4')
			tictac[1][0] = user;
		else
		{
			cout << "\nPlace already marked! Try a different place." << endl;
			//			input();
		}
	}
	else if (inpt == 5)
	{
		if (tictac[1][1] == '5')
			tictac[1][1] = user;
		else
		{
			cout << "\nPlace already marked! Try a different place." << endl;
			//			input(inpt);
		}
	}
	else if (inpt == 6)
	{
		if (tictac[1][2] == '6')
			tictac[1][2] = user;
		else
		{
			cout << "\nPlace already marked! Try a different place." << endl;
			//			input(inpt);
		}
	}
	//---------------------------
	else if (inpt == 7)
	{
		if (tictac[2][0] == '7')
			tictac[2][0] = user;
		else
		{
			cout << "\nPlace already marked! Try a different place." << endl;
			//			input(inpt);
		}
	}
	else if (inpt == 8)
	{
		if (tictac[2][1] == '8')
			tictac[2][1] = user;
		else
		{
			cout << "\nPlace already marked! Try a different place." << endl;
			//			input();
		}
	}
	else if (inpt == 9)
	{
		if (tictac[2][2] == '9')
			tictac[2][2] = user;
		else
		{
			cout << "\nPlace already marked! Try a different place." << endl;
			//			input();
		}
		return '/';
	}
}
void changeUser() { //If X has taken the turn then O plays and vice versa
	if (user == 'X')
		user = 'O';
	else
		user = 'X';
}

/*
00 01 02
10 11 12
20 21 22
*/
char checkWinner()
{
	// NEW APPROACH 

	if (tictac[0][0] != ' ' && (tictac[0][0] == tictac[0][1] && tictac[0][0] == tictac[0][2] ||
		tictac[0][0] == tictac[1][0] && tictac[0][0] == tictac[2][0] ||
		tictac[0][0] == tictac[1][1] && tictac[0][0] == tictac[2][2]))
		return tictac[0][0];

	if (tictac[1][1] != ' ' && (tictac[1][1] == tictac[1][0] && tictac[1][1] == tictac[1][2] ||
		tictac[1][1] == tictac[0][1] && tictac[1][1] == tictac[2][1] ||
		tictac[1][1] == tictac[2][0] && tictac[1][1] == tictac[0][2]))
		return tictac[1][1];

	if (tictac[2][2] != ' ' && (tictac[2][2] == tictac[0][2] && tictac[2][2] == tictac[1][2] ||
		tictac[2][2] == tictac[2][0] && tictac[2][2] == tictac[2][1]))
		return tictac[2][2];

	return '/';
}
bool IsAllCellTaken() {
	for (int i = 0; i < 9; i++ ) {
		if (allocated[i]) {
			return false;
		}
	}
	return true;
}
int main() {
	drawNum = 0;
	while (1)
	{
		drawNum++;
		if (checkWinner() == 'X')
		{
			board();
			cout << "\nX wins!!" << endl;
			break;
		}
		else if (checkWinner() == 'O')
		{
			board();
			cout << "\nO wins!!" << endl;
			break;
		}
		else if (checkWinner() == '/' && IsAllCellTaken()) //(checkWinner() == '/' && drawNum > 9)
		{
			board();
			cout << "\nIt's a draw!" << endl;
			break;
		}
		board();
		int inpt;
		cout << "\nIt's " << user << "'s turn." << "\nPress the number where you want the input to go: " << endl;
		cin >> inpt;
		if ((inpt < 1) || (inpt > 9)) {
			continue;
		} else if (!allocated[inpt -1]) {
			cout << "stop!" << endl;
			continue;
		}
		allocated[inpt - 1] = false;
		input(inpt);
		changeUser();
	}
	system("pause");
}
