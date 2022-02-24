#pragma once

class Bomb;

class BombObserver {
public:
	virtual void HandleBombLanding(Bomb* bomb) = 0;
};

