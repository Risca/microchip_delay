#include "painter.h"

#include <ostream>
#include <sstream>
#include <string>

#define INNER_LOOP_MAX_TICKS    (256*3 - 1)

Painter::Painter(std::ostream &out, const std::string &name) : _out(out), _labelCount(100), _tickCount(0), MAX_TICKS(33132)
{
    _out << name << std::endl;
}

void Painter::Comment(const std::string &comment)
{
    _out << ";" << comment << std::endl;
}

int Painter::SkipToFirstLine()
{
    Comment("initial delay from VSYNC high: ~10.5 us -> 33*31.5 - 10.5 - 1 = 1028 us");
    return SkipCycles(2 * 1028);
}

int Painter::SkipLines(int lines)
{
    Comment(static_cast<std::stringstream&>(std::stringstream() << "SkipLines(" << lines << ")").str());
    return SkipCycles(lines*63 - 2);
}

int Painter::PrintSolidLine(Painter::Color color)
{
    int ticks = SetColor(color);
    ticks += SkipCycles(62);
    ticks += ClearColor();
    return ticks;
}

int Painter::SetColor(Painter::Color color)
{
    std::string c = "SetColor(";
    switch (color) {
    case COLOR_BLACK:
        c += "BLACK";
        break;
    case COLOR_BLUE:
        c += "BLUE";
        break;
    case COLOR_GREEN:
        c += "GREEN";
        break;
    case COLOR_CYAN:
        c += "CYAN";
        break;
    case COLOR_RED:
        c += "RED";
        break;
    case COLOR_MAGENTA:
        c += "MAGENTA";
        break;
    case COLOR_YELLOW:
        c += "YELLOW";
        break;
    case COLOR_WHITE:
        c += "WHITE";
        break;
    default:
        c += "???";
        break;
    }
    c += ")";
    Comment(c);
    if (color == COLOR_BLACK) {
        _out << "\tclrf\tPORTA" << std::endl;
        _out << "\tnop" << std::endl;
    }
    else {
        _out << "\tmovlw\tD'" << (int)color << "'" << std::endl;
        _out << "\tmovwf\tPORTA" << std::endl;
    }
    _tickCount += 2;
    return 2;
}

int Painter::ClearColor()
{
    Comment("ClearColor()");
    _out << "\tclrf\tPORTA" << std::endl;
    _tickCount++;
    return 1;
}

int Painter::Nop()
{
    _out << "\tnop" << std::endl;
    _tickCount++;
    return 1;
}

int Painter::SkipCycles(int cycles)
{
    Comment(static_cast<std::stringstream&>(std::stringstream() << "delay_cycles(" << cycles << ") {").str());
    int remaining_ticks = cycles;
    int inner_loops = 0;
    int outer_loops = 0;
    if (remaining_ticks > 3) {
        const bool needs_outer_loop = remaining_ticks <= (2 + INNER_LOOP_MAX_TICKS + 2) ? false : true;
        const int setup_ticks = needs_outer_loop ? 4 : 2;
        remaining_ticks -= setup_ticks;
        if (needs_outer_loop) {
            ++outer_loops;
            while (remaining_ticks > INNER_LOOP_MAX_TICKS + 2) {
                ++outer_loops;
                remaining_ticks -= INNER_LOOP_MAX_TICKS;
            }
            remaining_ticks -= outer_loops * 3 - 1;
        }
        inner_loops = (remaining_ticks + 1) / 3;
        remaining_ticks -= (inner_loops - 1)*3 + 2;
        if (inner_loops == 256) {
            inner_loops = 0;
        }
        if (outer_loops) {
            _out << "\tmovlw\tD'" << outer_loops << "'" << std::endl;
            _out << "\tmovwf\tg_WaitCount2" << std::endl;
        }
        _out << "\tmovlw\tD'" << inner_loops << "'" << std::endl;
        _out << "\tmovwf\tg_WaitCount1" << std::endl;
        _out << "u" << _labelCount << std::endl;
        _out << "\tdecfsz\tg_WaitCount1, f" << std::endl;
        _out << "\tgoto\tu" << _labelCount << std::endl;
        if (outer_loops) {
            _out << "\tdecfsz\tg_WaitCount2, f" << std::endl;
            _out << "\tgoto\tu" << _labelCount << std::endl;
        }
    }
    while (remaining_ticks--) {
        _out << "\tnop" << std::endl;
    }
    _labelCount++;
    Comment("}");
    _tickCount += cycles;
    return cycles;
}

void Painter::BeginLine()
{
    _lineTickStart = _tickCount;
}

int Painter::EndLine()
{
    // 31.5 us - 2 instructions == 61 instructions
    int ticksLeftInLine = 61 - (_tickCount - _lineTickStart);
    return SkipCycles(ticksLeftInLine);
}

int Painter::GetTickCount() const
{
    return _tickCount;
}

void Painter::Finalize(bool vsync)
{
    if (vsync) {
        _out << "WaitForVSyncLow" << _labelCount << std::endl;
        _out << "\tbtfsc\tPORTC, 3" << std::endl;
        _out << "\tgoto\tWaitForVSyncLow" << _labelCount << std::endl;
        _labelCount++;
    }
    else {
        SkipCycles(MAX_TICKS - _tickCount);
    }
    _out << "\tgoto\tEndFrame" << std::endl;
}
