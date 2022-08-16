#include "Commands.h"

const double DropBombCommand::DEFAULT_SPEED = 2.0;

void DropBombCommand::Execute() {
    double x = plane->GetX() + X_OFFSET;
    double y = plane->GetY() + Y_OFFSET;

    bomb->SetDirection(X_DIRECTION, Y_DIRECTION);
    bomb->SetSpeed(speed);
    bomb->SetPos(x, y);
    bomb->SetWidth(craterSize);
}

void DeleteBombCommand::Execute() {
    auto it = objects.begin();
    for (; it != objects.end(); it++) {
        if (*it == obj) {
            auto temp = it;
            //delete* temp;
            objects.erase(it);            

            break;
        }
    }
}

void DeleteStaticObjCommand::Execute() {
    auto it = objects.begin();
    for (; it != objects.end(); it++) {
        if (*it == obj) {
            auto temp = it;
            delete *temp;
            objects.erase(it);            

            break;
        }
    }
}

