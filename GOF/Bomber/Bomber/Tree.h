#pragma once

#include "DestroyableGroundObject.h"

class TreeState;

class Tree : public DestroyableGroundObject {
public:
	Tree();	
	~Tree();
	void Draw() const override;
	void Grow();
	void SetState(TreeState*);

	inline uint16_t GetScore() const override { return score; }
	bool __fastcall isInside(double x1, double x2) const override { return false; }
private:
	TreeState* currentState;
	const uint16_t score = 10;
};


