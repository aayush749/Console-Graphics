#include <iostream>
#include <utility>
#include <vector>
#include "Graphics.h"

class Bresenham
{
private:
    Bresenham() = default;
public:
    using point = std::pair<int, int>;

    static std::vector<point> draw(const point& start, const point& end)
    {
        std::vector<point> points;
        const auto[sX, sY] = start;
        const auto[eX, eY] = end;

        const int dx = eX - sX;
        const int dy = eY - sY;

        int P = 2 * dy - dx;
        int x = sX, y = sY;
        while(x <= eX)
        {
            Graphics::putpixel(x, y);
            points.emplace_back(x, y);
            x++;
            if (P < 0)
                P = P + 2 * dy;
            else
            {
                P = P + 2 * (dy - dx) + 1;
                y++;
            }
        }
        return points;
    }
};

std::ostream& operator<<(std::ostream& os, const Bresenham::point& p)
{
    return os << '(' << p.first << ", " << p.second << ')';
}

int main()
{
    Graphics::init(50, 50, '.');
    const auto points = Bresenham::draw({-5, -7}, {10, 20});
    // for (const auto& p : points)
    //     std::cout << p << std::endl;
    Graphics::display();
}