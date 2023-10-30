#include "test.h"

void Integration::printLoadingBar()
{
	system("CLS");
	int lengthProgressBar = 20;
	int pct = (_loaded * 100) / _loadingMax;
	int progressBar = pct / (100 / lengthProgressBar);
	switch (_rotationState)
	{
	case 0:
		cout << "-";
		break;
	case 1:
		cout << "\\";
		break;
	case 2:
		cout << "|";
		break;
	case 3:
		cout << "/";
		break;
	default:
		cout << "-";
		break;
	}
	_rotationState++;
	_rotationState %= 4;
	cout << " [";
	for (int i = 0; i < progressBar; i++)
	{
		cout << "-";
	}
	for (int i = 0; i < lengthProgressBar - progressBar; i++)
	{
		cout << " ";
	}
	cout << "] " << pct << "%" << endl;
}

bool Integration::testing()
{
	_loaded = 0;
	for (int i = 0; i < 100; i++)
	{
		printLoadingBar();

		// table classic
		_actualTest.resetAllCells();
		_actualTest.createCopy(_starting);
		_actualTest.actionLeft(true);
		if (!_actualTest.compare(_left))
		{
			printLoadingBar();
			cout << "Normal: left";
			_starting.ShowGrid(false);
			_left.ShowGrid(false);
			_actualTest.ShowGrid(false);
			return false;
		}
		_loaded++;
		printLoadingBar();

		_actualTest.resetAllCells();
		_actualTest.createCopy(_starting);
		_actualTest.actionRight(true);
		if (!_actualTest.compare(_right))
		{
			printLoadingBar();
			cout << "Normal: right";
			_starting.ShowGrid(false);
			_right.ShowGrid(false);
			_actualTest.ShowGrid(false);
			return false;
		}
		_loaded++;
		printLoadingBar();

		_actualTest.resetAllCells();
		_actualTest.createCopy(_starting);
		_actualTest.actionUp(true);
		if (!_actualTest.compare(_top))
		{
			printLoadingBar();
			cout << "Normal: top";
			_starting.ShowGrid(false);
			_top.ShowGrid(false);
			_actualTest.ShowGrid(false);
			return false;
		}
		_loaded++;
		printLoadingBar();

		_actualTest.resetAllCells();
		_actualTest.createCopy(_starting);
		_actualTest.actionDown(true);
		if (!_actualTest.compare(_bottom))
		{
			printLoadingBar();
			cout << "Normal: bottom";
			_starting.ShowGrid(false);
			_bottom.ShowGrid(false);
			_actualTest.ShowGrid(false);
			return false;
		}
		_loaded++;
		printLoadingBar();

		// table noMoves
		_actualTest.resetAllCells();
		_actualTest.createCopy(_startingNoMoves);
		_actualTest.actionLeft(true);
		if (!_actualTest.compare(_startingNoMoves))
		{
			printLoadingBar();
			cout << "NoMoves: left";
			_startingNoMoves.ShowGrid(false);
			_startingNoMoves.ShowGrid(false);
			_actualTest.ShowGrid(false);
			return false;
		}
		_loaded++;
		printLoadingBar();

		_actualTest.resetAllCells();
		_actualTest.createCopy(_startingNoMoves);
		_actualTest.actionRight(true);
		if (!_actualTest.compare(_startingNoMoves))
		{
			printLoadingBar();
			cout << "NoMoves: right";
			_startingNoMoves.ShowGrid(false);
			_startingNoMoves.ShowGrid(false);
			_actualTest.ShowGrid(false);
			return false;
		}
		_loaded++;
		printLoadingBar();

		_actualTest.resetAllCells();
		_actualTest.createCopy(_startingNoMoves);
		_actualTest.actionUp(true);
		if (!_actualTest.compare(_startingNoMoves))
		{
			printLoadingBar();
			cout << "NoMoves: top";
			_startingNoMoves.ShowGrid(false);
			_startingNoMoves.ShowGrid(false);
			_actualTest.ShowGrid(false);
			return false;
		}
		_loaded++;
		printLoadingBar();

		_actualTest.resetAllCells();
		_actualTest.createCopy(_startingNoMoves);
		_actualTest.actionDown(true);
		if (!_actualTest.compare(_startingNoMoves))
		{
			printLoadingBar();
			cout << "NoMoves: bottom";
			_startingNoMoves.ShowGrid(false);
			_startingNoMoves.ShowGrid(false);
			_actualTest.ShowGrid(false);
			return false;
		}
		_loaded++;
		printLoadingBar();

		// table DoubleFusion
		_actualTest.resetAllCells();
		_actualTest.createCopy(_startingDoubleFusion);
		_actualTest.actionLeft(true);
		if (!_actualTest.compare(_leftDoubleFusion))
		{
			printLoadingBar();
			cout << "DoubleFusion: left";
			_startingDoubleFusion.ShowGrid(false);
			_leftDoubleFusion.ShowGrid(false);
			_actualTest.ShowGrid(false);
			return false;
		}
		_loaded++;
		printLoadingBar();

		_actualTest.resetAllCells();
		_actualTest.createCopy(_startingDoubleFusion);
		_actualTest.actionRight(true);
		if (!_actualTest.compare(_rightDoubleFusion))
		{
			printLoadingBar();
			cout << "DoubleFusion: right";
			_startingDoubleFusion.ShowGrid(false);
			_rightDoubleFusion.ShowGrid(false);
			_actualTest.ShowGrid(false);
			return false;
		}
		_loaded++;
		printLoadingBar();

		_actualTest.resetAllCells();
		_actualTest.createCopy(_startingDoubleFusion);
		_actualTest.actionUp(true);
		if (!_actualTest.compare(_topDoubleFusion))
		{
			printLoadingBar();
			cout << "DoubleFusion: top";
			_startingDoubleFusion.ShowGrid(false);
			_topDoubleFusion.ShowGrid(false);
			_actualTest.ShowGrid(false);
			return false;
		}
		_loaded++;
		printLoadingBar();

		_actualTest.resetAllCells();
		_actualTest.createCopy(_startingDoubleFusion);
		_actualTest.actionDown(true);
		if (!_actualTest.compare(_bottomDoubleFusion))
		{
			system("CLS");
			printLoadingBar();
			cout << "DoubleFusion: bottom";
			_startingDoubleFusion.ShowGrid(false);
			_bottomDoubleFusion.ShowGrid(false);
			_actualTest.ShowGrid(false);
			return false;
		}
		_loaded++;
		printLoadingBar();

	}
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