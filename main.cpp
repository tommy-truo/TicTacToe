#include <iostream>
#include <array>

using namespace std;


void displayBoard(array<array<char, 3>, 3> board)
{
	cout << endl;
	cout << "   |   |   " << endl;
	cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << "___|___|___" << endl;

	cout << "   |   |   " << endl;
	cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "___|___|___" << endl;

	cout << "   |   |   " << endl;
	cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
	cout << "   |   |   " << endl;
}


char choosePosition(array<array<char, 3>, 3> board, char token)
{
	array<array<char, 3>, 3> _board = board;
	char _token = token;
	
	cout << endl;
	cout << "Player " << token << ", Choose a grid position (enter its number)" << endl;
	cout << ">>>";
	char position;
	char positionEntry;

	cin >> position;

	while (position != '1' && position != '2' && position != '3' && position != '4' && position != '5' && position != '6' && position != '7' && position != '8' && position != '9')
	{
		cout << endl << "That is not an option!" << endl;
		cout << "Player " << token << ", Choose a grid position (enter its number)" << endl;
		cout << ">>>";
		cin >> position;
	}
	
	switch (position)
	{
	case '1':
		positionEntry = board[0][0];
		break;
	case '2':
		positionEntry = board[0][1];
		break;
	case '3':
		positionEntry = board[0][2];
		break;
	case '4':
		positionEntry = board[1][0];
		break;
	case '5':
		positionEntry = board[1][1];
		break;
	case '6':
		positionEntry = board[1][2];
		break;
	case '7':
		positionEntry = board[2][0];
		break;
	case '8':
		positionEntry = board[2][1];
		break;
	case '9':
		positionEntry = board[2][2];
		break;
	}

	if ((positionEntry == 'X') || (positionEntry == 'O'))
	{
		cout << endl;
		cout << "That grid position is already taken." << endl;
		choosePosition(_board, _token);
	}
	else
	{
		return position;
	}
}


array<array<char, 3>, 3> updateBoard(array<array<char, 3>, 3> board, char token, char position)
{
	switch (position)
	{
	case '1':
		board[0][0] = token;
		break;
	case '2':
		board[0][1] = token;
		break;
	case '3':
		board[0][2] = token;
		break;
	case '4':
		board[1][0] = token;
		break;
	case '5':
		board[1][1] = token;
		break;
	case '6':
		board[1][2] = token;
		break;
	case '7':
		board[2][0] = token;
		break;
	case '8':
		board[2][1] = token;
		break;
	case '9':
		board[2][2] = token;
		break;
	}

	return board;
}


bool checkForWinner(array<array<char, 3>, 3> board)
{
	//Checks for horizontal or vertical win
	for (int i = 0; i < 3; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))
		{
			return true;
		}

		if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]))
		{
			return true;
		}
	}

	//Checks for diagonal win
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) || (board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))
	{
		return true;
	}

	return false;
}


bool checkForTie(array<array<char, 3>, 3> board)
{
	int freeSpaces = 0;

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if ((board[row][col] != 'X') && (board[row][col] != 'O'))
			{
				freeSpaces = freeSpaces + 1;
			}
		}
	}

	if (freeSpaces == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool askForReplay()
{
	cout << endl;
	cout << "Would you like to replay? (y/n)" << endl;
	cout << ">>>";

	char option;
	cin >> option;

	while ((option != 'y') && (option != 'n'))
	{
		cout << endl << "That is not an option!" << endl;
		cout << "Would you like to replay? (y/n)" << endl;
		cout << ">>>";
		cin >> option;
	}

	switch (option)
	{
	case 'y': return true; break;
	case 'n': return false; break;
	}
}

void playGame()
{
	array<array<char, 3>, 3> board = { { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} } };
	char currentToken = 'O';
	char position = ' ';
	bool gameWon = false;
	bool gameTie = false;

	while ((gameWon == false) && (gameTie == false))
	{
		switch (currentToken)
		{
		case 'X': currentToken = 'O'; break;
		case 'O': currentToken = 'X'; break;
		}

		displayBoard(board);

		position = choosePosition(board, currentToken);

		board = updateBoard(board, currentToken, position);

		gameWon = checkForWinner(board);

		gameTie = checkForTie(board);
	}


	cout << endl << endl << endl;
	displayBoard(board);

	if (gameTie == true)
	{
		cout << "It is a tie!" << endl;
	}
	else if (gameWon == true)
	{
		cout << "Player " << currentToken << " WON!!!" << endl;
	}


	if (askForReplay() == true)
	{
		cout << endl << endl << endl;
		playGame();
	}
	else
	{
		cout << endl << "Thanks for playing!" << endl;
	}
}


void mainMenu()
{
	cout << "Welcome to Two Player Tic Tac Toe!" << endl << endl << endl;
	cout << "Would you like to play? (y/n)" << endl << ">>>";
	
	char option;
	cin >> option;

	while ((option != 'y') && (option != 'n'))
	{
		cout << endl << "That is not an option!" << endl;
		cout << "Would you like to play? (y/n)" << endl << ">>>";
		cin >> option;
	}

	switch (option)
	{
	case 'n':
		cout << endl << "Thanks for playing!" << endl;
		break;
	case 'y':
		cout << endl << endl;
		playGame();
		break;
	}
}


int main()
{
	mainMenu();
	return 0;
}