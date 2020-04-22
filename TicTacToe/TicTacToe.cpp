#include <iostream> 
#include <string> 
#include "PlayField.h"
#include "TreeNode.h"

using namespace std;

#pragma region CrossesAndNoughts

int crossScore = 0, noughtScore = 0, drawScore = 0;

void printLine() {
	static const string line = "-------";
	cout << line << endl;
}


void PrintCell(PlayField::CellState cell) {
	string str = "| ";
	switch (cell) {
	case PlayField::csCross:
		str = "|X";
		break;
	case PlayField::csNought:
		str = "|O";
		break;
	default:
		break;
	}
	cout << str;
}

void PrintField(PlayField field) {
	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++)
			PrintCell(field[PlayField::CellIdx::CreateCell(j, i)]);
		cout << "|" << endl;
	}
	printLine();
}

void recursiveTreeWalk(TreeNode*& root)
{
	for (int i = 0; i < 9; ++i) {
		auto startField = root->value();
		if (startField[PlayField::CellIdx::CreateCell(i % 3, i / 3)] == PlayField::csEmpty) {
			auto newField = startField.makeMove(PlayField::CellIdx::CreateCell(i % 3, i / 3));
			auto newRoot = new TreeNode(root, newField);
			root->addChild(newRoot);
		}
	}
	for (int i = 0; i < root->childCount(); i++)
	{
		auto newRoot = root->operator[](i);
		if (newRoot.isTerminal()) //если дошли до выйгрыша или тупика
		{
			// проверяем что же все-таки произошло....
			// на этапах проверки я не выводил поле и того кто победил, но при пустом поле вывод работает догло... 
			// поэтому он закомментирован
			auto stat = newRoot.fieldStatus();
			if (stat == PlayField::FieldStatus::fsCrossesWin)
			{
				//cout << "x" << endl;
				crossScore++;
			}
			else if (stat == PlayField::FieldStatus::fsNoughtsWin)
			{
				//cout << "o" << endl;
				noughtScore++;
			}
			else if (stat == PlayField::FieldStatus::fsDraw)
			{
				//cout << "draw" << endl;
				drawScore++;
			}
			//PrintField(newRoot.value());
		}
		else
		{ // ныряем глубже
			TreeNode* temp = &newRoot;
			recursiveTreeWalk(temp);
		}
	}
}

//функция нужна для того, чтобы задать начальное положение поля(сначала первыми всегда ходят крестики, смена строн происходит автоматически)
TreeNode AddCrossOrNought(TreeNode*& root, int index)
{
	auto startField = root->value();
	auto newField = startField.makeMove(PlayField::CellIdx::CreateCell(index % 3, index / 3));
	auto newRoot = new TreeNode(root, newField);
	root->addChild(newRoot);
	return root->operator[](0);
}
#pragma endregion

int main()
{
	//Крестики нолики
#pragma region CrossesAndNoughts
	cout << endl << endl;
	printLine();
	PlayField emptyField; //создаем пустое поле

	TreeNode root = TreeNode(nullptr, emptyField); // задаем корень дереву
	TreeNode* temp;

	// для того чтобы уменьшить время выполнения алгоритма лучше задать какую-то стартовую ситуацию
	temp = &root;
	root = AddCrossOrNought(temp, 0); // ставим крестик в верхний левый угол и перезаписываем корень(теперь это стартовая ситуация)

	temp = &root;
	root = AddCrossOrNought(temp, 4);// ставим нолик в центр и перезаписываем корень(теперь это стартовая ситуация)

	temp = &root;
	recursiveTreeWalk(temp);// "уходим нырять" и считаем победы или их отсутвие(ничья)
	cout << "crosses: " << crossScore << " draw: " << drawScore << " noughts: " << noughtScore;
#pragma endregion
	return 0;
}