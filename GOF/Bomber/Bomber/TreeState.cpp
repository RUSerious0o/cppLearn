#include "TreeState.h"

#include <iostream>

#include "Tree.h"
#include "MyTools.h"

using MyTools::GotoXY;

void TreeStateSmall::Draw(const Tree* tree) const {
	GotoXY(tree->GetX(), tree->GetY() - 2);
	std::cout << "  \\|/  ";	
	GotoXY(tree->GetX(), tree->GetY() - 1);
	std::cout << "   |   ";
	GotoXY(tree->GetX(), tree->GetY());
	std::cout << "   |   ";
}

void TreeStateSmall::Grow(Tree* tree) {
	tree->SetState(new TreeStateMedium);
}

void TreeStateMedium::Draw(const Tree* tree) const {
	GotoXY(tree->GetX(), tree->GetY() - 3);
	std::cout << " \\/|\\/ ";
	GotoXY(tree->GetX(), tree->GetY() - 2);
	std::cout << "  \\|/  ";
	GotoXY(tree->GetX(), tree->GetY() - 1);
	std::cout << "   |   ";
	GotoXY(tree->GetX(), tree->GetY());
	std::cout << "   |   ";
}

void TreeStateMedium::Grow(Tree* tree) {
	tree->SetState(new TreeStateBig);
}

void TreeStateBig::Draw(const Tree* tree) const {
	GotoXY(tree->GetX(), tree->GetY() - 4);
	std::cout << " /\\|/\\ ";
	GotoXY(tree->GetX(), tree->GetY() - 3);
	std::cout << "/\\/|\\/\\";
	GotoXY(tree->GetX(), tree->GetY() - 2);
	std::cout << "  \\|/  ";
	GotoXY(tree->GetX(), tree->GetY() - 1);
	std::cout << "   |   ";
	GotoXY(tree->GetX(), tree->GetY());
	std::cout << "   |   ";
}

void TreeStateBig::Grow(Tree* tree) {}