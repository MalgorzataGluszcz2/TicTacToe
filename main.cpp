#include <iostream>
#include "include/TicTacToe.hpp"

void gameTitle();
void drawBoad(const Board &board);
void theWinner(Player player, TicTacToe game);

int main()
{
	TicTacToe game;
	Player currentPlayer = Player::X;

	gameTitle();

	while (game.checkWinner() == Player::NONE && !game.isBoardFull())
	{
		drawBoad(game.getBoard());
		std::cout << '\n';

		if (currentPlayer == Player::X)
		{
			int row, col;
			std::cout << "Enter row and column (0 - 2 0 - 2): ";
			std::cin >> row >> col;
			std::cout << '\n';

			if (!game.makeMove(row, col, Player::X))
			{
				std::cout << "Invalid move! Please enter a proper row and column again :";
				continue;
			}
		}
		else
		{
			auto move = game.findBestMove();
			if (move.has_value())
			{
				game.makeMove(move->first, move->second, Player::O);
			}
		}

		currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
	}

	drawBoad(game.getBoard());

	theWinner(currentPlayer, game);

	std::cin.get();
	std::cin.get();

	return 0;
}

void gameTitle()
{
	std::cout << "============== WELCOME TO MY GAME TIC TAC TOE ==============\n";
}

void drawBoad(const Board& board) 
{
	std::cout << "\n-------------\n";
	
	for (int i = 0; i < 3; i++)
	{
		std::cout << "| ";
		
		for (int j = 0; j < 3; j++)
		{
			char symbol = ' ';
			if (board[i][j] == Player::X)
				symbol = 'X';
			if (board[i][j] == Player::O)
				symbol = 'O';

			std::cout << symbol << " | ";
		}

		std::cout << "\n-------------\n";
	}
}

void theWinner(Player player, TicTacToe game)
{
	Player winner = game.checkWinner();

	if (winner == Player::X)
		std::cout << "You win! Congratulations!\n";
	else if (winner == Player::O)
		std::cout << "AI win!\n";
	else
		std::cout << "Draw!\n";
}