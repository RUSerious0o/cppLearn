#include "Tree.h"

#include "TreeState.h"

Tree::Tree() : currentState(new TreeStateSmall) {}

Tree::~Tree() { delete currentState; }

void Tree::Draw() const {
	currentState->Draw(this);
}

void Tree::Grow() {
	currentState->Grow(this);
}

void Tree::SetState(TreeState* newState) {
	delete currentState;
	currentState = newState;
}