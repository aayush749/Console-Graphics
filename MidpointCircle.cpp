#include <iostream>
#include <vector>
#include "Graphics.h"
#include "Color.h"

class MidpointCircle
{
private:
    MidpointCircle() = default;
public:
    using point = std::pair<int, int>;
    static std::vector<point> draw(const int radius, const point& center = {0, 0})
    {
        std::vector<point> points;
        const auto[cX, cY] = center;
        int x = 0, y = radius;

        int P = 1 - radius;

        while (x <= y)
        {
            Graphics::putpixel(cX + x, y + cY);
            Graphics::putpixel(cX + x, -y + cY);
            Graphics::putpixel(cX + -x, y + cY);
            Graphics::putpixel(cX + -x, -y + cY);
            Graphics::putpixel(cX + y, x + cY);
            Graphics::putpixel(cX + y, -x + cY);
            Graphics::putpixel(cX + -y, x + cY);
            Graphics::putpixel(cX + -y, -x + cY);
            points.emplace_back(cX + x, y + cY);
            points.emplace_back(cX + x, -y + cY);
            points.emplace_back(cX + -x, y + cY);
            points.emplace_back(cX + -x, -y + cY);
            points.emplace_back(cX + y, x + cY);
            points.emplace_back(cX + y, -x + cY);
            points.emplace_back(cX + -y, x + cY);
            points.emplace_back(cX + -y, -x + cY);

            if (P < 0)
                P = P + 2 * x + 1;
            else
            {
                P = P + 2 * (x - y) + 1;
                y--;
            }
            x++;
        }
        return points;
    }
};

int main()
{
    Graphics::init(50, 50);
    const auto points = MidpointCircle::draw(5, {-20, -10});
    
    Graphics::display(true, ColorName::MAGENTA);
}