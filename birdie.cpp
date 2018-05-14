#include "birdie.h"

#include "painter.h"

void Birdie::render(std::ostream &out)
{
    Painter p(out, _name);
    p.Comment("BACK PORCH");
    p.SkipCycles(63);
    p.SkipToFirstLine();
    p.Comment("VISIBLE AREA");
    p.SkipCycles(2);
    p.SkipLines(20);
    p.SkipCycles(5);
    for (int i = 0; i < 10; ++i) {
        if (i % 2) {
            p.SkipCycles(63);
        }
        else {
            p.SkipCycles(2);
            p.BeginLine();
            // 'B'
            p.SetColor(Painter::COLOR_WHITE);
            p.SkipCycles(3);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'I'
            p.SetColor(Painter::COLOR_WHITE);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'R'
            p.SetColor(Painter::COLOR_WHITE);
            p.SkipCycles(3);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'D'
            p.SetColor(Painter::COLOR_WHITE);
            p.SkipCycles(3);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'I'
            p.SetColor(Painter::COLOR_WHITE);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'E'
            p.SetColor(Painter::COLOR_WHITE);
            p.SkipCycles(3);
            p.ClearColor();
            p.EndLine();
        }
    }
    for (int i = 0; i < 20; ++i) {
        if (i % 2) {
            p.SkipCycles(63);
        }
        else {
            p.SkipCycles(2);
            p.BeginLine();
            // 'B'
            p.SetColor(Painter::COLOR_CYAN);
            p.ClearColor();
            p.SetColor(Painter::COLOR_CYAN);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'I'
            p.SetColor(Painter::COLOR_CYAN);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'R'
            p.SetColor(Painter::COLOR_CYAN);
            p.ClearColor();
            p.SetColor(Painter::COLOR_CYAN);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'D'
            p.SetColor(Painter::COLOR_CYAN);
            p.ClearColor();
            p.SetColor(Painter::COLOR_CYAN);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'I'
            p.SetColor(Painter::COLOR_CYAN);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'E'
            p.SetColor(Painter::COLOR_CYAN);
            p.ClearColor();
            p.EndLine();
        }
    }
    for (int i = 0; i < 10; ++i) {
        if (i % 2) {
            p.SkipCycles(63);
        }
        else {
            p.SkipCycles(2);
            p.BeginLine();
            // 'B'
            p.SetColor(Painter::COLOR_MAGENTA);
            p.SkipCycles(3);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'I'
            p.SetColor(Painter::COLOR_MAGENTA);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'R'
            p.SetColor(Painter::COLOR_MAGENTA);
            p.SkipCycles(2);
            p.ClearColor();
            p.Nop();
            // ' '
            p.Nop();
            // 'D'
            p.SetColor(Painter::COLOR_MAGENTA);
            p.ClearColor();
            p.SetColor(Painter::COLOR_MAGENTA);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'I'
            p.SetColor(Painter::COLOR_MAGENTA);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'E'
            p.SetColor(Painter::COLOR_MAGENTA);
            p.SkipCycles(3);
            p.ClearColor();
            p.EndLine();
        }
    }
    for (int i = 0; i < 20; ++i) {
        if (i % 2) {
            p.SkipCycles(63);
        }
        else {
            p.SkipCycles(2);
            p.BeginLine();
            // 'B'
            p.SetColor(Painter::COLOR_RED);
            p.ClearColor();
            p.SetColor(Painter::COLOR_RED);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'I'
            p.SetColor(Painter::COLOR_RED);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'R'
            p.SetColor(Painter::COLOR_RED);
            p.ClearColor();
            p.SetColor(Painter::COLOR_RED);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'D'
            p.SetColor(Painter::COLOR_RED);
            p.ClearColor();
            p.SetColor(Painter::COLOR_RED);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'I'
            p.SetColor(Painter::COLOR_RED);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'E'
            p.SetColor(Painter::COLOR_RED);
            p.ClearColor();
            p.EndLine();
        }
    }
    for (int i = 0; i < 10; ++i) {
        if (i % 2) {
            p.SkipCycles(63);
        }
        else {
            p.SkipCycles(2);
            p.BeginLine();
            // 'B'
            p.SetColor(Painter::COLOR_BLUE);
            p.SkipCycles(3);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'I'
            p.SetColor(Painter::COLOR_BLUE);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'R'
            p.SetColor(Painter::COLOR_BLUE);
            p.ClearColor();
            p.SetColor(Painter::COLOR_BLUE);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'D'
            p.SetColor(Painter::COLOR_BLUE);
            p.SkipCycles(3);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'I'
            p.SetColor(Painter::COLOR_BLUE);
            p.ClearColor();
            // ' '
            p.Nop();
            // 'E'
            p.SetColor(Painter::COLOR_BLUE);
            p.SkipCycles(3);
            p.ClearColor();
            p.EndLine();
        }
    }
#if 1
    p.SkipLines(392);
    p.SkipLines(10);
    p.SkipCycles(14);
    out << "\tgoto\tEndFrame" << std::endl;
#else
    p.Finalize();
#endif
}
