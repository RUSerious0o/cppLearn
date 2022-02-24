#pragma once

class DestroyableGroundObject;
class Bomb;

class LandObjectObserver {
public:
	virtual void DestroyObject(DestroyableGroundObject* object, Bomb* bomb) = 0;
};

