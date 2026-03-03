#include <iostream>

void mainMenu();
void startGame();
void drawBoard();
void playerChoose();
void insertPlayerChoose();
bool makeMove(int row, int col);
bool isFieldEmpty();

int getCurrentPlayer();

int currentPlayer = 2;
char playerInput = ' ';

char gameBoard[3][3] =
{
	{' ',  ' ', ' '},
	{' ',  ' ', ' '},
	{' ',  ' ', ' '}
};

int main()
{
	mainMenu();
	startGame();

	drawBoard();
	playerChoose();
	drawBoard();

	std::cin.get();
	std::cin.get();
	return 0;
}

void mainMenu()
{
	int chooseAnswer = 0;
	std::cout << "========== Welcome to my tic tac toe game ==========\n";
	std::cout << "1. Start game\n";
	std::cout << "2. Options\n";
	std::cout << "3. Author\n";
	std::cout << "0. Quit\n";
	std::cin >> chooseAnswer;
}

void startGame()
{
	char playerAnswer;
	std::cout << "Choose X or O ";
	std::cin >> playerAnswer;
}

void drawBoard()
{
	std::cout << "-------------\n";

	for (int i = 0; i < 3; i++)
	{
		std::cout << "| ";
		for (int j = 0; j < 3; j++)
		{
			std::cout << gameBoard[i][j] << " | ";
		}

		std::cout << "\n-------------\n";
	}
}

void playerChoose()
{
	std::cout << "Choose your field (0, 1, 2, 3, 4, 5, 6, 7, 8)";
	std::cin >> playerInput;
	// Row 0
	if (playerInput == '0' && isFieldEmpty())
	{
		makeMove(0, 0);
	}
	else if (playerInput == '1' && isFieldEmpty())
	{
		makeMove(0, 1);
	}
	else if (playerInput == '2' && isFieldEmpty())
	{
		makeMove(0, 2);
	}

	// Row 1
	if (playerInput == '3' && isFieldEmpty())
	{
		makeMove(1, 0);
	}
	else if (playerInput == '4' && isFieldEmpty())
	{
		makeMove(1, 1);
	}
	else if (playerInput == '5' && isFieldEmpty())
	{
		makeMove(1, 2);
	}

	// Row 2
	if (playerInput == '6' && isFieldEmpty())
	{
		makeMove(2, 0);
	}
	else if (playerInput == '7' && isFieldEmpty())
	{
		makeMove(2, 1);
	}
	else if (playerInput == '8' && isFieldEmpty())
	{
		makeMove(2, 2);
	}
}

void insertPlayerChoose()
{

}

bool makeMove(int row, int col)
{
	gameBoard[row][col] = (currentPlayer == 1) ? 'X' : 'O';
	currentPlayer = 3 - currentPlayer;
	return true;
}

bool isFieldEmpty()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (gameBoard[i][j] == ' ')
			{
				return true;
			}
		}
	}

	return false;
}

int getCurrentPlayer()
{
	return currentPlayer;
}