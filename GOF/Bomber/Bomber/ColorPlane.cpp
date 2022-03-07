#include "ColorPlane.h"
#include "MyTools.h"

using namespace MyTools;

void ColorPlane::DrawBody() const {
    SetColor(CC_Cyan);
    GotoXY(x, y);
    std::cout << "=========>";
}

void ColorPlane::DrawWings() const {
    SetColor(CC_LightCyan);
    GotoXY(x + 3, y - 1);
    std::cout << "\\\\\\\\";
    GotoXY(x + 3, y + 1);
    std::cout << "////";
}
void ColorPlane::DrawTail() const {
    SetColor(CC_LightGreen);
    GotoXY(x - 2, y - 1);
    std::cout << "===";
}