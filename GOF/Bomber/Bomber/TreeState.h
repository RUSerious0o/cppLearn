#pragma once

class Tree;

class TreeState {
public:
	virtual void Grow(Tree*) = 0;
	virtual void Draw(const Tree*) const = 0;
};

class TreeStateSmall : public TreeState {
public:
	void Grow(Tree*) override;
	void Draw(const Tree*) const override;
};

class TreeStateMedium : public TreeState {
public:
	void Grow(Tree*) override;
	void Draw(const Tree*) const override;
};

class TreeStateBig : public TreeState {
public:
	void Grow(Tree*) override;
	void Draw(const Tree*) const override;
};
