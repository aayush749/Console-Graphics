#pragma once
#include <iostream>
#include <unordered_map>
#include <cstring>
#include "Color.h"

class Graphics
{
private:
    Graphics() = default;
public:
    static void init(int nRows, int nCols, char defaultBg = '.')
    {
        // initialize color system
        Color::init();

        s_rows = nRows;
        s_cols = nCols;
        s_grid = new char*[s_rows];
        s_colors = new ColorName*[s_rows];
        s_BgLetter = defaultBg;
        for (int i = 0; i < s_rows; ++i)
        {
            s_grid[i] = new char[s_cols];
            s_colors[i] = new ColorName[s_cols];

            std::memset(s_grid[i], defaultBg, s_cols);
            for (int j = 0; j < s_cols; j++)
            {
                s_colors[i][j] = ColorName::WHITE;
            }
        }

    }
    static void putpixel(int x, int y, ColorName color = ColorName::WHITE)
    {
        x = s_cols / 2 + x;
        y = s_rows / 2 - y - 1;    

        if (x < 0 || x >= s_cols || y < 0 || y >= s_rows)
            return;


        s_grid[y][x] = '*';
        s_colors[y][x] = color;
    }
    static void display(bool showAxis = true, ColorName axisColor = ColorName::GREEN)
    {
        static const auto& resetColor = Color::GetColorCodeStr(ColorName::RESET);
        for (int i = 0; i < s_rows; ++i)
        {
            for (int j = 0; j < s_cols; ++j)
            {
                bool isAnAxisPt = false;
                if (showAxis)
                {
                    isAnAxisPt = DrawAxis(axisColor, i, j);
                }
                if (isAnAxisPt)
                    continue;

                if (s_colors    [i][j] != ColorName::WHITE)
                {
                    ColorName color = s_colors[i][j];
                    const auto& colorCode = Color::GetColorCodeStr(color);
                    std::cout << colorCode << s_grid[i][j] << resetColor;
                }
                else
                {
                    std::cout<<s_grid[i][j];
                }
            }


            std::cout << std::endl;
        }
    }
private:
    static bool DrawAxis(ColorName axisColor, int i, int j)
    {
        // returns true if draws an axis point
        static const auto& resetColor = Color::GetColorCodeStr(ColorName::RESET);
        const auto& color = Color::GetColorCodeStr(axisColor);
        if (i == 0 && j == s_cols / 2)
        {
            std::cout<<color<<'^'<<resetColor;
            return true;
        }
        if (i == s_rows / 2 && j == 0)
        {
            std::cout<<color<<'<'<<resetColor;
            return true;
        }
        if (i == s_rows / 2 && j == s_cols - 1)
        {
            std::cout<<color<<'>'<<resetColor;
            return true;
        }
        if (i == s_rows - 1 && j == s_cols / 2)
        {
            std::cout<<color<<'v'<<resetColor;
            return true;
        }
        if (i == s_rows / 2)
        {
            if (j == s_cols / 2)
                std::cout << color << '+';
            else
                std::cout << color << '-';
            std::cout<<resetColor;
            return true;
        }
        if (j == s_cols / 2)
        {
            std::cout << color << '|';
            std::cout<<resetColor;
            return true;
        }
        return false;
    }
private:
    inline static int s_rows = 0, s_cols = 0;
    inline static char** s_grid = nullptr;
    inline static ColorName** s_colors = nullptr;
    inline static char s_BgLetter = '.';
};