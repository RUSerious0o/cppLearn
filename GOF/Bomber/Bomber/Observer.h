#pragma once

class DestroyableGroundObject;

class Observer {
public:
	virtual void DestroyObject(DestroyableGroundObject* object) {}
};

