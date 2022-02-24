#pragma once

#include <vector>

#include "DynamicObject.h"
#include "LevelGUI.h"
#include "Bomb.h"
#include "Commands.h"
#include "House.h"
#include "Tank.h"
#include "Ground.h"
#include "BombIterator.h"

class CollisionDetector {
public:
    virtual void CheckPlaneAndLevelGUI(DynamicObject* plane, LevelGUI* gui, bool& exitFlag) = 0;
    virtual void CheckBombsAndGround(vector<DynamicObject*>& vecDynamicObj,
        std::vector<GameObject*>& vecStaticObj,
        CommandInterface& commandInterface,
        int16_t& score) = 0;

    virtual ~CollisionDetector() = default;
};

class BaseCollisionDetector : public CollisionDetector {
public:
    void CheckPlaneAndLevelGUI(DynamicObject* plane, LevelGUI* gui, bool& exitFlag) override {
        if(plane->GetX() > gui->GetFinishX()) {
            exitFlag = true;
        }
    }

    void CheckBombsAndGround(vector<DynamicObject*>& vecDynamicObj,
        std::vector<GameObject*>& vecStaticObj,
        CommandInterface& commandInterface,
        int16_t& score) override {

        vector<Bomb*> vecBombs = FindAllBombs(vecDynamicObj);
        Ground* pGround = FindGround(vecStaticObj);
        const double y = pGround->GetY();
        for (size_t i = 0; i < vecBombs.size(); i++)
        {
            if (vecBombs[i]->GetY() >= y) // Пересечение бомбы с землей
            {
                pGround->AddCrater(vecBombs[i]->GetX());
                CheckDestoyableObjects(vecBombs[i], vecStaticObj, commandInterface, score);
                commandInterface.Invoke(new DeleteDynamicObjCommand(vecBombs[i], vecDynamicObj));
            }
        }
    }
private:
    vector<Bomb*> FindAllBombs(vector<DynamicObject*>& vecDynamicObj) const
    {
        vector<Bomb*> vecBombs;
        BombIterator it(vecDynamicObj);
        while (*it.next() != nullptr) vecBombs.push_back(dynamic_cast<Bomb*>(*it));

        return vecBombs;
    }

    Ground* FindGround(std::vector<GameObject*>& vecStaticObj) const
    {
        Ground* pGround;

        for (size_t i = 0; i < vecStaticObj.size(); i++)
        {
            pGround = dynamic_cast<Ground*>(vecStaticObj[i]);
            if (pGround != nullptr)
            {
                return pGround;
            }
        }

        return nullptr;
    }

    vector<DestroyableGroundObject*> FindDestoyableGroundObjects(
        std::vector<GameObject*>& vecStaticObj) const
    {

        vector<DestroyableGroundObject*> vec;
        Tank* pTank;
        House* pHouse;
        for (size_t i = 0; i < vecStaticObj.size(); i++)
        {
            pTank = dynamic_cast<Tank*>(vecStaticObj[i]);
            if (pTank != nullptr)
            {
                vec.push_back(pTank);
                continue;
            }

            pHouse = dynamic_cast<House*>(vecStaticObj[i]);
            if (pHouse != nullptr)
            {
                vec.push_back(pHouse);
                continue;
            }
        }

        return vec;
    }

    void __fastcall CheckDestoyableObjects(Bomb* pBomb,
        vector<GameObject*>& vecStaticObj,
        CommandInterface commandInterface,
        int16_t& score)
    {
        vector<DestroyableGroundObject*> vecDestoyableObjects = FindDestoyableGroundObjects(vecStaticObj);
        const double size = pBomb->GetWidth();
        const double size_2 = size / 2;
        for (size_t i = 0; i < vecDestoyableObjects.size(); i++)
        {            
            const double x1 = pBomb->GetX() - size_2;
            const double x2 = x1 + size;
            if (vecDestoyableObjects[i]->isInside(x1, x2))
            {
                /*score += vecDestoyableObjects[i]->GetScore();
                commandInterface.Invoke(
                    new DeleteStaticObjCommand(vecDestoyableObjects[i], vecStaticObj));*/
                vecDestoyableObjects[i]->Notify();
            }
        }
    }
};