#pragma once
#include <iostream>
#include <unordered_map>

enum class ColorName
{
    RED, GREEN, BLUE, BLACK, YELLOW, MAGENTA, CYAN, WHITE, RESET
};

class Color
{
private:
    Color() = default;
public:
    static void init()
    {
        if (s_initialized)
            return;

        s_colorCodes = {
            {   ColorName::RED, "\033[31m" },
            {   ColorName::GREEN, "\033[32m" },
            {   ColorName::BLUE, "\033[34m" },
            {   ColorName::BLACK, "\033[30m" },
            {   ColorName::YELLOW, "\033[33m" },
            {   ColorName::MAGENTA, "\033[35m" },
            {   ColorName::CYAN, "\033[36m" },
            {   ColorName::WHITE, "\033[37m "},
            {   ColorName::RESET, "\033[0m" }
        };
    
        s_initialized = true;
    } 
    static const std::string& GetColorCodeStr(ColorName color)
    {
        return s_colorCodes.at(color);
    }
public:
    static inline std::unordered_map<ColorName, std::string> s_colorCodes;
private:
    static inline bool s_initialized = false;
};