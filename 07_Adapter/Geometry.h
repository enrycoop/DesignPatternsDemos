#pragma once
#include <vector>

struct Point
{
    int x;
    int y;
};

struct Line
{
    Point start, end;
};


struct VectorObject
{
    virtual ~VectorObject() = default;
    virtual std::vector<Line>::iterator begin() = 0;
    virtual std::vector<Line>::iterator end() = 0;
};

struct VectorRectangle : VectorObject
{
    VectorRectangle(int x, int y, int width, int height)
    {
        lines.emplace_back(Line{Point{x,y}, Point{x+width,y}});
        lines.emplace_back(Line{Point{x+width,y}, Point{x+width,y+height}});
        lines.emplace_back(Line{Point{x,y}, Point{x,y+height}});
        lines.emplace_back(Line{Point{x,y+height}, Point{x+width,y+height}});
    }

    std::vector<Line>::iterator begin() override
    {
        return lines.begin();
    }

    std::vector<Line>::iterator end() override
    {
        return lines.end();
    }

private:
    std::vector<Line> lines;
};
