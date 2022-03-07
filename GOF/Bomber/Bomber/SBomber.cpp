#include <memory>

#include "SBomber.h"
#include "SBomberImpl.h"

SBomber::SBomber()
: bomber(std::move(std::unique_ptr<SBomberImpl>(new SBomberImpl))) {}

SBomber::~SBomber() {}

bool SBomber::GetExitFlag() const { 
    return bomber->GetExitFlag();    
}

void SBomber::MoveObjects() {
    bomber->MoveObjects();
}

void SBomber::CheckObjects() {
    bomber->CheckObjects();
}

void SBomber::ProcessKBHit() {
    bomber->ProcessKBHit();
}

void SBomber::DrawFrame() {
    bomber->DrawFrame();
}

void SBomber::TimeStart() {
    bomber->TimeStart();
}

void SBomber::TimeFinish() {
    bomber->TimeFinish();
}