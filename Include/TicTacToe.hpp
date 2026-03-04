#pragma once
#include <array>
#include <optional>

enum class Player
{
	NONE,
	X,
	O
};

using Board = std::array<std::array<Player, 3>, 3>;

class TicTacToe
{
public:
	TicTacToe();

	void mainMenu();
	void startGame();
	bool makeMove(int row, int col, Player player);
	Player checkWinner() const;
	bool isBoardFull() const;
	const Board& getBoard() const { return _board; };
	std::optional<std::pair<int, int>> findBestMove();

private:
	Board _board;
	int minimax(bool isMaximizing);
};