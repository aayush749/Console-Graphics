#include "Graphics.h"

int main()
{
    Graphics::init(50, 50);
    Graphics::putpixel(1, 1);
    Graphics::putpixel(1, 2);
    Graphics::putpixel(5, 5);
    Graphics::display();
}