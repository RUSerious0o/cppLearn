#pragma once

#include <stdint.h>
#include <chrono>
#include <iostream>
#include <queue>

#include "GameObject.h"

class LevelGUI : public GameObject {
public:

    LevelGUI() : bombsNumber(0), score(0), passedTime(0), fps(0), height(0), 
        startTime(std::chrono::steady_clock::now()), tankMessage("") { }

    void __fastcall SetParam(uint64_t passedTimeNew, uint64_t fpsNew, uint16_t bombsNumberNew, int16_t scoreNew);
    
    void __fastcall SetHeight(uint16_t heightN) { height = heightN; };
    
    inline uint16_t GetFinishX() const { return finishX; }
    inline void SetFinishX(uint16_t finishXN) { finishX = finishXN; }

    void Draw() const override;

    void CheckTankMessage();
    void CheckTrees();
private:
    uint16_t height;
    uint16_t finishX = 109;

    uint64_t passedTime, fps;
    uint16_t bombsNumber;
    int16_t score;

    std::chrono::time_point<std::chrono::steady_clock> startTime;
    std::string tankMessage;

    const int TANK_MSG_DELAY = 3;
    int tankMsgTime = 0;

    const int TREES_GROW_DELAY = 3;
    int treesGrowTime = 4;
};



