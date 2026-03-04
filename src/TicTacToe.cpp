#include "../include/TicTacToe.hpp"

TicTacToe::TicTacToe()
{
	for (auto &row : _board)
	{
		row.fill(Player::NONE);
	}
}

bool TicTacToe::makeMove(int row, int col, Player player)
{
	// Check if player input is out of range
	if (row < 0 || row > 2 || 
		col < 0 || col > 2)
		return false;

	if (_board[row][col] != Player::NONE)
		return false;

	_board[row][col] = player;
	return true;
}

Player TicTacToe::checkWinner() const
{
	for (int i = 0; i < 3; i++)
	{
		if (_board[i][0] == _board[i][1] &&
			_board[i][1] == _board[i][2] &&
			_board[i][0] != Player::NONE)
			return _board[i][0];

		if (_board[0][i] == _board[1][i] &&
			_board[1][i] == _board[2][i] &&
			_board[0][i] != Player::NONE)
			return _board[0][i];
	}

	// Check diagonal  down right field
	if (_board[0][0] == _board[1][1] &&
		_board[1][1] == _board[2][2] &&
		_board[0][0] != Player::NONE)
		return _board[0][0];

	// Check diagonal  down left field
	if (_board[0][2] == _board[1][1] &&
		_board[1][1] == _board[2][0] &&
		_board[0][2] != Player::NONE)
		return _board[0][2];

	return Player::NONE;
}

bool TicTacToe::isBoardFull() const
{
	// Check if there is and empty field and if it is return false, otherwise return true
	for (const auto& row : _board)
	{
		for (Player cell : row)
		{
			if (cell == Player::NONE)
				return false;
		}
	}

	return true;
}

std::optional<std::pair<int, int>> TicTacToe::findBestMove()
{
	int bestScore = -1000;
	std::optional<std::pair<int, int>> bestMove;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (_board[i][j] == Player::NONE)
			{
				_board[i][j] = Player::O;
				int score = minimax(false);
				_board[i][j] = Player::NONE;

				if (score > bestScore)
				{
					bestScore = score;
					bestMove = { i, j };
				}
			}
		}
	}

	return bestMove;
}

int TicTacToe::minimax(bool isMaximizing)
{
	Player winner = checkWinner();

	if (winner == Player::O)
		return 1;
	if (winner == Player::X)
		return -1;
	if (isBoardFull())
		return 0;

	if (isMaximizing)
	{
		int bestScore = -1000;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (_board[i][j] == Player::NONE)
				{
					_board[i][j] = Player::O;
					int score = minimax(false);
					_board[i][j] = Player::NONE;
					bestScore = std::max(bestScore, score);
				}
			}
		}

		return bestScore;
	}
	else
	{
		int bestScore = 1000;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (_board[i][j] == Player::NONE)
				{
					_board[i][j] = Player::X;
					int score = minimax(true);
					_board[i][j] = Player::NONE;
					bestScore = std::min(bestScore, score);
				}
			}
		}

		return bestScore;
	}
}