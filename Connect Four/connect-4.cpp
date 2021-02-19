#include <iostream>
using namespace std;

char Board[6][7];
int i, j, filled = 0;
int column;
int start_row, start_column;
int top_Of_Stack[7];
bool game_Over = false;

void create_Board();
void create_Stack();
void print_Board();
bool is_Game_Over(int p);
bool player_Turn(int p);

int main()
{

    create_Board();
    create_Stack();
    print_Board();
    while (filled < 42)
    {
        if (player_Turn(1))
            break;
        if (player_Turn(2))
            break;
        filled += 2;
    }

    if (filled == 42 and game_Over == false)
        cout << "It's a Draw :\\\\";
    return 0;
}

void create_Board()
{
    for (i = 0; i < 6; i++)
        for (j = 0; j < 7; j++)
            Board[i][j] = '-';
    return;
}

void create_Stack()
{
    for (i = 0; i < 7; i++)
        top_Of_Stack[i] = 6;
}
void print_Board()
{
    system("cls");
    cout << "\t\t\t\t\t\t\t\tConnect 4\n";
    cout << "\n\n";
    for (i = 0; i < 6; i++)
    {
        cout << "\t\t\t\t\t\t\t";
        for (j = 0; j < 7; j++)
            cout << Board[i][j] << "   ";
        cout << "\n\n";
    }
    cout << "\t\t\t\t\t\t\t";
    for (i = 1; i <= 7; i++)
        cout << i << "   ";
    cout << "\n\n";
    return;
}

bool player_Turn(int p)
{
    cout << "\n\t\t\t\t\t\t\t";
    cout << "Player " << p << " , Enter the column No : ";
    cin >> column;
    print_Board();
    if (1 <= column and column <= 7 and top_Of_Stack[column - 1] > 0)
    {
        if (p == 1)
            Board[--top_Of_Stack[column - 1]][column - 1] = 'X';
        else
            Board[--top_Of_Stack[column - 1]][column - 1] = 'O';
        print_Board();

        return is_Game_Over(p);
    }
    else
    {
        cout << "\t\t\t\t\t\t\t";
        cout << "Invalid Choice\n";
        return player_Turn(p);
    }
}
bool is_Game_Over(int p)
{

    i = top_Of_Stack[column - 1]; // Last Element's  row
    j = column - 1;               // Last Element's  column
    //Last Element => Board[i][j]

    //Horizontal
    start_column = j - 3;
    while (start_column < 0)
        start_column++;
    while (start_column <= j)
    {
        if (start_column >= 0 && start_column + 3 <= 6)
        {
            if (Board[i][start_column] == Board[i][start_column + 1] and Board[i][start_column + 1] == Board[i][start_column + 2] and Board[i][start_column + 2] == Board[i][start_column + 3])
            {
                cout << "\t\t\t\t\t\t\t";
                cout << "Player " << p << " wins ;)";
                game_Over = true;
                return true;
            }
        }
        start_column++;
    }
    //Vertical
    start_row = i - 3;
    while (start_row < 0)
        start_row++;
    while (start_row <= i)
    {
        if (start_row >= 0 and start_row + 3 <= 5)
        {
            if (Board[start_row][column - 1] == Board[start_row + 1][column - 1] and Board[start_row + 1][column - 1] == Board[start_row + 2][column - 1] and Board[start_row + 2][column - 1] == Board[start_row + 3][column - 1])
            {
                cout << "\t\t\t\t\t\t\t";
                cout << "Player " << p << " wins ;)";
                game_Over = true;
                return true;
            }
        }
        start_row++;
    }

    //Diagonal_1
    start_row = i - 3;
    start_column = j + 3;
    while (start_row < 0 or start_column > 6)
        start_row++, start_column--;
    while (start_row <= i)
    {
        if (start_row + 3 <= 5 and start_column - 3 >= 0)
        {
            if (Board[start_row][start_column] == Board[start_row + 1][start_column - 1] and Board[start_row + 1][start_column - 1] == Board[start_row + 2][start_column - 2] and Board[start_row + 2][start_column - 2] == Board[start_row + 3][start_column - 3])
            {
                cout << "\t\t\t\t\t\t\t";
                cout << "Player " << p << " wins ;)";
                game_Over = true;
                return true;
            }
        }
        start_row++;
        start_column--;
    }

    //Diagonal_2
    start_row = i - 3;
    start_column = j - 3;
    while (start_row < 0 or start_column < 0)
        start_row++, start_column++;
    while (start_row <= i)
    {
        if (start_row + 3 <= 5 and start_column + 3 <= 6)
        {
            if (Board[start_row][start_column] == Board[start_row + 1][start_column + 1] and Board[start_row + 1][start_column + 1] == Board[start_row + 2][start_column + 2] and Board[start_row + 2][start_column + 2] == Board[start_row + 3][start_column + 3])
            {
                cout << "\t\t\t\t\t\t\t";
                cout << "Player " << p << " wins ;)";
                game_Over = true;
                return true;
            }
        }
        start_row++;
        start_column++;
    }

    return false;
}