#include "printtestimage.h"
#include "painter.h"

void PrintTestImage::render(std::ostream &out)
{
    Painter p(out, _name);
    p.Comment("BACK PORCH");
    p.SkipToFirstLine();
    p.Comment("VISIBLE AREA");
    p.PrintSolidLine(Painter::COLOR_WHITE);
    p.Comment("200 lines delay minus 2 instructions");
    p.SkipLines(200);
    p.SetColor(Painter::COLOR_CYAN);
    p.Comment("show for 80 lines, then clear");
    p.SkipLines(80);
    p.SetColor(Painter::COLOR_BLACK);
    p.Comment("sleep for rest of frame (198 lines)");
    p.SkipLines(198);
    p.PrintSolidLine(Painter::COLOR_WHITE);
    p.Comment("FRONT PORCH");
    p.Finalize();
}
