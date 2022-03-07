#pragma once

#include <iostream>
#include "Bomb.h"
#include "MyTools.h"

class BombDecorator : public Bomb {
public:
	BombDecorator(Bomb* baseBomb) : baseBomb(baseBomb) {}
    ~BombDecorator() override { delete baseBomb; }

    BombDecorator(const BombDecorator& base) {        
        CopyFields(base);
    }

    BombDecorator& operator=(const BombDecorator& base) {
        CopyFields(base);
    }

	void Draw() const override {
        baseBomb->Draw();
        MyTools::GotoXY(baseBomb->GetX(), baseBomb->GetY() - baseBomb->getHeight());
        std::cout << "|";
    }

    void SetPos(double nx, double ny) override { 
        x = nx; 
        y = ny; 
        baseBomb->SetPos(nx, ny);
    }

    void SetSpeed(double sp) override { 
        speed = SPEED_MULTIPLIER * sp; 
        baseBomb->SetSpeed(SPEED_MULTIPLIER * sp);
    }
    void SetDirection(double dx, double dy) override { 
        xDirction = dx;
        yDirection = dy; 
        baseBomb->SetDirection(dx, dy);
    }

    void Move(uint16_t time) override { 
        x += xDirction * speed * time * 0.001; 
        y += yDirection * speed * time * 0.001; 
        baseBomb->Move(time);
    };

    int getHeight() override { return baseBomb->getHeight() + 1; }

    BombDecorator* Clone() override {
        return new BombDecorator(*this);
    }
private:	
	const double SPEED_MULTIPLIER = 1.6;
    Bomb* baseBomb;

    void CopyFields(const BombDecorator& base) {
        baseBomb = base.baseBomb->Clone();

        x = base.x;
        y = base.y;
        width = base.width;
        speed = base.speed;
        xDirction = base.xDirction;
        yDirection = base.yDirection;

        for (BombObserver* observer : base.observers) {
            observers.push_back(observer);
        }
    }
};