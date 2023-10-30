#include "test.h"

void Integration::printLoadingBar()
{
	system("CLS");
}

bool Integration::testing()
{
	_loaded = 0;
	printLoadingBar();

	return true;
}

Integration::Integration()
{
	_loadingMax = 100 * 4 * 3;
	_loaded = 0;
	_rotationState = 0;

	// vider les tables
	_starting.resetAllCells();
	_left.resetAllCells();
	_right.resetAllCells();
	_top.resetAllCells();
	_bottom.resetAllCells();

	_startingNoMoves.resetAllCells();

	_startingDoubleFusion.resetAllCells();
	_leftDoubleFusion.resetAllCells();
	_rightDoubleFusion.resetAllCells();
	_topDoubleFusion.resetAllCells();
	_bottomDoubleFusion.resetAllCells();

	// en classique
	_starting.setCell(1, 1, Cell(2));
	_starting.setCell(2, 2, Cell(2));
	_starting.setCell(1, 2, Cell(2));
	_starting.setCell(2, 1, Cell(2));

	_left.setCell(0, 1, Cell(4));
	_left.setCell(0, 2, Cell(4));

	_right.setCell(3, 1, Cell(4));
	_right.setCell(3, 2, Cell(4));

	_top.setCell(1, 0, Cell(4));
	_top.setCell(2, 0, Cell(4));

	_bottom.setCell(1, 3, Cell(4));
	_bottom.setCell(2, 3, Cell(4));

	// en noMove
	_startingNoMoves.setCell(0, 0, Cell(4));
	_startingNoMoves.setCell(0, 1, Cell(2));
	_startingNoMoves.setCell(0, 2, Cell(4));
	_startingNoMoves.setCell(0, 3, Cell(2));

	_startingNoMoves.setCell(1, 0, Cell(2));
	_startingNoMoves.setCell(1, 1, Cell(4));
	_startingNoMoves.setCell(1, 2, Cell(2));
	_startingNoMoves.setCell(1, 3, Cell(4));

	_startingNoMoves.setCell(2, 0, Cell(4));
	_startingNoMoves.setCell(2, 1, Cell(2));
	_startingNoMoves.setCell(2, 2, Cell(4));
	_startingNoMoves.setCell(2, 3, Cell(2));

	_startingNoMoves.setCell(3, 0, Cell(2));
	_startingNoMoves.setCell(3, 1, Cell(4));
	_startingNoMoves.setCell(3, 2, Cell(2));
	_startingNoMoves.setCell(3, 3, Cell(4));

	// en doubleFusion
	_startingDoubleFusion.setCell(0, 0, Cell(4));
	_startingDoubleFusion.setCell(0, 1, Cell(2));
	_startingDoubleFusion.setCell(0, 2, Cell(2));
	_startingDoubleFusion.setCell(0, 3, Cell(2));

	_startingDoubleFusion.setCell(1, 0, Cell(4));
	_startingDoubleFusion.setCell(1, 1, Cell(4));
	_startingDoubleFusion.setCell(1, 2, Cell(2));
	_startingDoubleFusion.setCell(1, 3, Cell(2));

	_startingDoubleFusion.setCell(2, 0, Cell(2));
	_startingDoubleFusion.setCell(2, 1, Cell(2));
	_startingDoubleFusion.setCell(2, 2, Cell(2));
	_startingDoubleFusion.setCell(2, 3, Cell(2));

	_startingDoubleFusion.setCell(3, 0, Cell(2));
	_startingDoubleFusion.setCell(3, 1, Cell(4));
	_startingDoubleFusion.setCell(3, 2, Cell(2));
	_startingDoubleFusion.setCell(3, 3, Cell(4));
	//
	_leftDoubleFusion.setCell(0, 0, Cell(8));
	_leftDoubleFusion.setCell(0, 1, Cell(2));
	_leftDoubleFusion.setCell(0, 2, Cell(4));
	_leftDoubleFusion.setCell(0, 3, Cell(4));

	_leftDoubleFusion.setCell(1, 0, Cell(4));
	_leftDoubleFusion.setCell(1, 1, Cell(4));
	_leftDoubleFusion.setCell(1, 2, Cell(4));
	_leftDoubleFusion.setCell(1, 3, Cell(2));

	_leftDoubleFusion.setCell(2, 1, Cell(2));
	_leftDoubleFusion.setCell(2, 3, Cell(4));

	_leftDoubleFusion.setCell(3, 1, Cell(4));
	//
	_rightDoubleFusion.setCell(0, 1, Cell(2));

	_rightDoubleFusion.setCell(1, 1, Cell(4));
	_rightDoubleFusion.setCell(1, 3, Cell(4));

	_rightDoubleFusion.setCell(2, 0, Cell(8));
	_rightDoubleFusion.setCell(2, 1, Cell(2));
	_rightDoubleFusion.setCell(2, 2, Cell(4));
	_rightDoubleFusion.setCell(2, 3, Cell(2));

	_rightDoubleFusion.setCell(3, 0, Cell(4));
	_rightDoubleFusion.setCell(3, 1, Cell(4));
	_rightDoubleFusion.setCell(3, 2, Cell(4));
	_rightDoubleFusion.setCell(3, 3, Cell(4));
	//
	_topDoubleFusion.setCell(0, 0, Cell(4));
	_topDoubleFusion.setCell(1, 0, Cell(8));
	_topDoubleFusion.setCell(2, 0, Cell(4));
	_topDoubleFusion.setCell(3, 0, Cell(2));

	_topDoubleFusion.setCell(0, 1, Cell(4));
	_topDoubleFusion.setCell(1, 1, Cell(4));
	_topDoubleFusion.setCell(2, 1, Cell(4));
	_topDoubleFusion.setCell(3, 1, Cell(4));

	_topDoubleFusion.setCell(0, 2, Cell(2));
	_topDoubleFusion.setCell(3, 2, Cell(2));

	_topDoubleFusion.setCell(3, 3, Cell(4));
	//
	_bottomDoubleFusion.setCell(3, 0, Cell(2));

	_bottomDoubleFusion.setCell(0, 1, Cell(4));
	_bottomDoubleFusion.setCell(3, 1, Cell(4));

	_bottomDoubleFusion.setCell(0, 2, Cell(2));
	_bottomDoubleFusion.setCell(1, 2, Cell(8));
	_bottomDoubleFusion.setCell(2, 2, Cell(4));
	_bottomDoubleFusion.setCell(3, 2, Cell(2));

	_bottomDoubleFusion.setCell(0, 3, Cell(4));
	_bottomDoubleFusion.setCell(1, 3, Cell(4));
	_bottomDoubleFusion.setCell(2, 3, Cell(4));
	_bottomDoubleFusion.setCell(3, 3, Cell(4));
}