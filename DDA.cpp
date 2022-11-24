#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <numeric>
#include <limits>
#include "Graphics.h"

class DDA
{
private:
    DDA() = default;
public:
    using point = std::pair<int, int>;
    static std::vector<point> draw(const point& start, const point& end)
    {
        std::vector<point> points;

        const auto[sX, sY] = start;
        const auto[eX, eY] = end;

        const auto dx = eX - sX;
        const auto dy = eY - sY;

        const auto steps = std::max(std::abs(dx), std::abs(dy));

        const float xInc = dx / static_cast<float>(steps);
        const float yInc = dy / static_cast<float>(steps);

        float x = sX, y = sY;

        for(int i = 0; i < steps; i++)
        {
            Graphics::putpixel(std::round(x), std::round(y));
            points.emplace_back(std::round(x), std::round(y));
            x += xInc;
            y += yInc;
        }
        return points;
    }
};

std::ostream& operator<<(std::ostream& os, const DDA::point& p)
{
    return os << '(' << p.first << ", " << p.second << ')';
}

int main()
{
    Graphics::init(50, 50, '.');
    const std::vector<DDA::point> points = DDA::draw({5, 7}, {30, 40});
    Graphics::display();
}