
#include <iostream>

#include "Plane.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

void Plane::Draw() const
{    
    DrawBody();
    DrawWings();
    DrawTail();    
}

void Plane::SetColor(MyTools::ConsoleColor color) const {
    MyTools::SetColor(color);
}

void Plane::DrawBody() const {
    SetColor(CC_LightBlue);
    GotoXY(x, y);
    cout << "=========>";
}

void Plane::DrawWings() const {
    SetColor(CC_LightBlue);
    GotoXY(x + 3, y - 1);
    cout << "\\\\\\\\";
    GotoXY(x + 3, y + 1);
    cout << "////";
}
void Plane::DrawTail() const {
    SetColor(CC_LightBlue);
    GotoXY(x - 2, y - 1);
    cout << "===";
}