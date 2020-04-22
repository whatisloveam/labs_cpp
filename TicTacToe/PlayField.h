#pragma once
#include <cassert>
#include <vector>

class PlayField {
public:
	enum CellState { csEmpty, csCross, csNought };
	class CellIdx {
	public:
		static CellIdx CreateCell(int x, int y) {
			assert(x >= 0 && y >= 0 && x <= 2 && y <= 2);
			return { x, y };
		}

		int GetX() {
			return x;
		}

		int GetY() {
			return y;
		}
	private:
		int x;
		int y;
		CellIdx(int x, int y) {
			this->x = x;
			this->y = y;
		}
	};
	CellState operator[](CellIdx idx);
	std::vector<CellIdx*> GetEmptyCells();
	enum FieldStatus { fsInvalid, fsNormal, fsCrossesWin, fsNoughtsWin, fsDraw };
	FieldStatus checkFieldStatus();
	PlayField makeMove(CellIdx idx) const;
private:
	PlayField operator+(CellIdx idx);
	CellState state[9]{ csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty,csEmpty };
	int GetLinearIdxFromCell(CellIdx index) const;
	PlayField::CellIdx GetCellIdxFromLinear(int index) const;
	PlayField::CellState IdentifyWhoseMove() const;
	PlayField::CellState CheckForWin(int* line) const;
};
