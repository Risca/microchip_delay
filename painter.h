#ifndef PAINTER_H
#define PAINTER_H

#include <string>
#include <ostream>

class Painter
{
public:
    enum Color {
        COLOR_BLACK = 0,
        COLOR_BLUE = 1,
        COLOR_GREEN = 2,
        COLOR_CYAN = 3,
        COLOR_RED = 4,
        COLOR_MAGENTA = 5,
        COLOR_YELLOW = 6,
        COLOR_WHITE = 7,
    };

    Painter(std::ostream& out, const std::string& name);

    void Comment(const std::string& comment);
    // these functions leave space for new color (2 instructions) before new line begins
    int SkipToFirstLine();
    int SkipLines(int lines);

    // will change to black at end of line. Will take 2 instructions more than 1 line
    int PrintSolidLine(Color color);

    // always take 2 instructions
    int SetColor(Color color);

    // 1 instruction
    int ClearColor();
    int Nop();

    int SkipCycles(int cycles);

    // Warning: Begin/EndLine are NOT recursive
    void BeginLine();
    // Will sleep until end of line, but leave 2 instructions for next line
    int EndLine();

    int GetTickCount() const;
    void Finalize(bool vsync = false);

private:
    std::ostream& _out;
    int _labelCount;
    int _tickCount;
    int _lineTickStart;
    const int MAX_TICKS;
};

#endif // PAINTER_H
