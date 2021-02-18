#include <iostream>
using namespace std;

int i, j, player = 1, e = 0, t, c = 1;

int *P = 0, A[3][3];

void create();
void display();
void input();
void check();
void result();

int main()
{
	create();
	input();
	return 0;
}

void create()
{
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			A[i][j] = c++;
	P = &A[0][0];
	display();
}

void display()
{
	system("cls");
	cout << "\n\t  Tic Tac Toe\n\n\n";
	for (i = 0; i < 3; i++)
	{
		cout << "\t";
		for (j = 0; j < 3; j++)
		{
			if (A[i][j] >= 1 && A[i][j] <= 9)
				cout << " " << A[i][j] << " ";
			else
				cout << " " << char(A[i][j]) << " ";
			if (j < 2)
				cout << " | ";
		}
		cout << endl;
		if (i < 2)
			cout << "\t_______________\n\n";
	}
	cout << endl
		 << endl;
}

void input()
{
	if (player == 1)
		cout << "\n\tPlayer 1 / (X) 's Turn\n";
	else
		cout << "\n\tPlayer 2 / (O) 's Turn\n";

	cout << "\n\tEnter the position : ";

	cin >> t;

	if (*(P + t - 1) == 'O' || *(P + t - 1) == 'X' || t > 9 || t < 1)
	{
		display();
		cout << "\tEnter a valid choice\n";
		input();
	}
	if (player == 1)
	{
		*(P + t - 1) = 'X';
		player = 2;
		e++;
	}
	else if (player == 2)
	{
		*(P + t - 1) = 'O';
		player = 1;
		e++;
	}

	display();

	if (e >= 5)
		check();
	else
		input();
}

void check()
{
	// Rows
	for (i = 0; i < 3; i++)
		if ((A[i][0] == 'O' || A[i][0] == 'X') && A[i][0] == A[i][1] && A[i][1] == A[i][2])
			result();

	// Columns
	for (j = 0; j < 3; j++)
		if ((A[0][j] == 'O' || A[0][j] == 'X') && A[0][j] == A[1][j] && A[1][j] == A[2][j])
			result();

	//Diagonal 1
	if (A[0][0] != 1 && A[0][0] == A[1][1] && A[1][1] == A[2][2])
		result();

	//Diagonal 2
	if (A[2][0] != 7 && A[2][0] == A[1][1] && A[1][1] == A[0][2])
		result();

	if (e == 9)
	{
		cout << "\tIt's a Draw -__-";
		exit(0);
	}
	else
		input();
}

void result()
{
	if (player == 1)
		cout << "\tPlayer 2 wins :)\n";
	else
		cout << "\tPlayer 1 wins :)\n";
	exit(0);
}
