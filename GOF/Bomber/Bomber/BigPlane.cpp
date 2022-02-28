#include "BigPlane.h"
#include "MyTools.h"

using namespace MyTools;

void BigPlane::DrawBody() const {
    SetColor(CC_LightBlue);
    GotoXY(x-1, y);
    std::cout << "==========>";
}

void BigPlane::DrawWings() const {
    SetColor(CC_LightBlue);
    GotoXY(x + 3, y - 3);
    std::cout << "\\\\";
    GotoXY(x + 3, y - 2);
    std::cout << "\\\\\\";
    GotoXY(x + 3, y - 1);
    std::cout << "\\\\\\\\";
    GotoXY(x + 3, y + 1);
    std::cout << "////";
    GotoXY(x + 3, y + 2);
    std::cout << "///";
    GotoXY(x + 3, y + 3);
    std::cout << "//";
}

void BigPlane::DrawTail() const {
    SetColor(CC_LightBlue);
    GotoXY(x - 2, y - 1);
    std::cout << "\\\\";
}