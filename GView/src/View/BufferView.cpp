#include "GViewApp.hpp"

using namespace GView::View;
using namespace AppCUI::Input;

const char hexCharsList[]                    = "0123456789ABCDEF";
const unsigned int characterFormatModeSize[] = { 2 /*Hex*/, 3 /*Oct*/, 4 /*signed 8*/, 3 /*unsigned 8*/ };
const std::string_view hex_header = "00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F 10 11 12 13 14 15 16 17 18 19 1A 1B 1C 1D 1E 1F ";
const std::string_view oct_header =
      "000 001 002 003 004 005 006 007 010 011 012 013 014 015 016 017 020 021 022 023 024 025 026 027 030 031 032 033 034 035 036 037 ";
const std::string_view signed_dec_header = "  +0   +1   +2   +3   +4   +5   +6   +7   +8   +9  +10  +11  +12  +13  +14  +15  +16  +17  +18 "
                                           " +19  +20  +21  +22  +23  +24  +25  +26  +27  +28  +29  +30  +31  ";
const std::string_view unsigned_dec_header =
      " +0  +1  +2  +3  +4  +5  +6  +7  +8  +9 +10 +11 +12 +13 +14 +15 +16 +17 +18 +19 +20 +21 +22 +23 +24 +25 +26 +27 +28 +29 +30 +31 ";

const char16_t CodePage_437[] = {
    0x0020, 0x263A, 0x263B, 0x2665, 0x2666, 0x2663, 0x2660, 0x2022, 0x25D8, 0x25CB, 0x25D9, 0x2642, 0x2640, 0x266A, 0x266B, 0x263C,
    0x25BA, 0x25C4, 0x2195, 0x203C, 0x00B6, 0x00A7, 0x25AC, 0x21A8, 0x2191, 0x2193, 0x2192, 0x2190, 0x221F, 0x2194, 0x25B2, 0x25BC,
    0x0020, 0x0021, 0x0022, 0x0023, 0x0024, 0x0025, 0x0026, 0x0027, 0x0028, 0x0029, 0x002A, 0x002B, 0x002C, 0x002D, 0x002E, 0x002F,
    0x0030, 0x0031, 0x0032, 0x0033, 0x0034, 0x0035, 0x0036, 0x0037, 0x0038, 0x0039, 0x003A, 0x003B, 0x003C, 0x003D, 0x003E, 0x003F,
    0x0040, 0x0041, 0x0042, 0x0043, 0x0044, 0x0045, 0x0046, 0x0047, 0x0048, 0x0049, 0x004A, 0x004B, 0x004C, 0x004D, 0x004E, 0x004F,
    0x0050, 0x0051, 0x0052, 0x0053, 0x0054, 0x0055, 0x0056, 0x0057, 0x0058, 0x0059, 0x005A, 0x005B, 0x005C, 0x005D, 0x005E, 0x005F,
    0x0060, 0x0061, 0x0062, 0x0063, 0x0064, 0x0065, 0x0066, 0x0067, 0x0068, 0x0069, 0x006A, 0x006B, 0x006C, 0x006D, 0x006E, 0x006F,
    0x0070, 0x0071, 0x0072, 0x0073, 0x0074, 0x0075, 0x0076, 0x0077, 0x0078, 0x0079, 0x007A, 0x007B, 0x007C, 0x007D, 0x007E, 0x2302,
    0x00C7, 0x00FC, 0x00E9, 0x00E2, 0x00E4, 0x00E0, 0x00E5, 0x00E7, 0x00EA, 0x00EB, 0x00E8, 0x00EF, 0x00EE, 0x00EC, 0x00C4, 0x00C5,
    0x00C9, 0x00E6, 0x00C6, 0x00F4, 0x00F6, 0x00F2, 0x00FB, 0x00F9, 0x00FF, 0x00D6, 0x00DC, 0x00A2, 0x00A3, 0x00A5, 0x20A7, 0x0192,
    0x00E1, 0x00ED, 0x00F3, 0x00FA, 0x00F1, 0x00D1, 0x00AA, 0x00BA, 0x00BF, 0x2310, 0x00AC, 0x00BD, 0x00BC, 0x00A1, 0x00AB, 0x00BB,
    0x2591, 0x2592, 0x2593, 0x2502, 0x2524, 0x2561, 0x2562, 0x2556, 0x2555, 0x2563, 0x2551, 0x2557, 0x255D, 0x255C, 0x255B, 0x2510,
    0x2514, 0x2534, 0x252C, 0x251C, 0x2500, 0x253C, 0x255E, 0x255F, 0x255A, 0x2554, 0x2569, 0x2566, 0x2560, 0x2550, 0x256C, 0x2567,
    0x2568, 0x2564, 0x2565, 0x2559, 0x2558, 0x2552, 0x2553, 0x256B, 0x256A, 0x2518, 0x250C, 0x2588, 0x2584, 0x258C, 0x2590, 0x2580,
    0x03B1, 0x00DF, 0x0393, 0x03C0, 0x03A3, 0x03C3, 0x00B5, 0x03C4, 0x03A6, 0x0398, 0x03A9, 0x03B4, 0x221E, 0x03C6, 0x03B5, 0x2229,
    0x2261, 0x00B1, 0x2265, 0x2264, 0x2320, 0x2321, 0x00F7, 0x2248, 0x00B0, 0x2219, 0x00B7, 0x221A, 0x207F, 0x00B2, 0x25A0, 0x0020
};
bool DefaultAsciiMask[256] = {
    false, false, false, false, false, false, false, false, false, true,  false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false, false, false, true,  true,  true,  true,  true,  true,
    false, true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,
    true,  true,  false, false, true,  false, false, true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,
    true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  false, true,  false, false,
    true,  false, true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,  true,
    true,  true,  true,  true,  true,  true,  true,  true,  true,  false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false
};

BufferView::Config BufferView::config;

BufferView::BufferView(const std::string_view& _name, Reference<GView::Object> _obj)
{
    this->obj  = _obj;
    this->name = _name;
    this->chars.Fill('-', 1024, ColorPair{ Color::Black, Color::DarkBlue });
    this->Layout.nrCols            = 8;
    this->Layout.charFormatMode    = CharacterFormatMode::Hex;
    this->Layout.lineAddressSize   = 8;
    this->Layout.lineNameSize      = 8;
    this->Layout.charactersPerLine = 1;
    this->Layout.visibleRows       = 1;
    this->Layout.xName             = 0;
    this->Layout.xNumbers          = 0;
    this->Layout.xAddress          = 0;
    this->Layout.xText             = 0;
    this->CodePage                 = CodePage_437;
    this->Cursor.currentPos        = 0;
    this->Cursor.startView         = 0;
    this->StringInfo.start         = GView::Utils::INVALID_OFFSET;
    this->StringInfo.end           = GView::Utils::INVALID_OFFSET;
    this->StringInfo.middle        = GView::Utils::INVALID_OFFSET;
    this->StringInfo.type          = StringType::None;
    this->StringInfo.minCount      = 4;
    memcpy(this->StringInfo.AsciiMask, DefaultAsciiMask, 256);

    if (config.Loaded == false)
        LoadConfig();
}
bool BufferView::LoadConfig()
{
    config.Colors.Ascii       = ColorPair{ Color::Red, Color::DarkBlue };
    config.Colors.Unicode     = ColorPair{ Color::Yellow, Color::DarkBlue };
    config.Colors.Selection   = ColorPair{ Color::Black, Color::White };
    config.Colors.Cursor      = ColorPair{ Color::Black, Color::Yellow };
    config.Colors.Line        = ColorPair{ Color::Gray, Color::DarkBlue };
    config.Colors.Header      = ColorPair{ Color::White, Color::Magenta };
    config.Colors.Normal      = ColorPair{ Color::Silver, Color::DarkBlue };
    config.Colors.Inactive    = ColorPair{ Color::Gray, Color::DarkBlue };
    config.Colors.OutsideZone = ColorPair{ Color::Gray, Color::DarkBlue };

    config.Loaded = true;
    return true;
}
void BufferView::MoveTo(unsigned long long offset, bool select)
{
    if (this->obj->cache.GetSize() == 0)
        return;
    if (offset > (obj->cache.GetSize() - 1))
        offset = obj->cache.GetSize() - 1;

    auto h  = this->Layout.visibleRows;
    auto sz = this->Layout.charactersPerLine * h;
    if ((offset >= this->Cursor.startView) && (offset < this->Cursor.startView + sz))
    {
        this->Cursor.currentPos = offset;
        return; // nothing to do ... already in visual space
    }

    if (offset < this->Cursor.startView)
        this->Cursor.startView = offset;
    else
    {
        auto dif = this->Cursor.currentPos - this->Cursor.startView;
        if (offset >= dif)
            this->Cursor.startView = offset - dif;
        else
            this->Cursor.startView = 0;
    }
    this->Cursor.currentPos = offset;
}
void BufferView::MoveScrollTo(unsigned long long offset)
{
    if (this->obj->cache.GetSize() == 0)
        return;
    if (offset > (obj->cache.GetSize() - 1))
        offset = obj->cache.GetSize() - 1;
    auto old               = this->Cursor.startView;
    this->Cursor.startView = offset;
    if (this->Cursor.startView > old)
        MoveTo(this->Cursor.currentPos + (this->Cursor.startView - old), false);
    else
    {
        auto dif = old - Cursor.startView;
        if (dif <= this->Cursor.currentPos)
            MoveTo(this->Cursor.currentPos - dif, false);
        else
            MoveTo(0, false);
    }
}
void BufferView::MoveToSelection(unsigned int selIndex)
{
    unsigned long long start, end;

    if (this->selection.GetSelection(selIndex, start, end))
    {
        if (this->Cursor.currentPos != start)
            MoveTo(start, false);
        else
            MoveTo(end, false);
    }
}
void BufferView::SkipCurentCaracter(bool selected)
{
    unsigned long long tr, fileSize;

    auto buf = this->obj->cache.Get(this->Cursor.currentPos, 1);

    if (buf.Empty())
        return;
    auto toSkip = *buf.data;

    fileSize = this->obj->cache.GetSize();
    for (tr = this->Cursor.currentPos; tr < fileSize;)
    {
        auto buf = this->obj->cache.Get(tr, 256);
        if (buf.Empty())
            break;
        for (unsigned int gr = 0; gr < buf.length; gr++, tr++)
            if (buf.data[gr] != toSkip)
                break;
    }
    MoveTo(tr, selected);
}
void BufferView::MoveTillNextBlock(bool select, int dir)
{
    // GView::Objects::FileZones* zone;
    // switch (File->ColorMode)
    //{
    // case GView::Constants::COLORMODE_OBJECTS:
    //    zone = &File->Zones.Objects;
    //    break;
    // case GView::Constants::COLORMODE_TYPE:
    //    zone = &InitData->TypeZones;
    //    break;
    // default:
    //    return;
    //};
    // unsigned int count = zone->GetCount();
    // const GView::Objects::FileZone* z;
    // if (dir == 1)
    //{
    //    for (unsigned int tr = 0; tr < count; tr++)
    //    {
    //        z = zone->Get(tr);
    //        if (z->Start > this->Cursor.currentPos)
    //        {
    //            MoveTo(z->Start, select);
    //            return;
    //        }
    //    }
    //}
    // else
    //{
    //    for (int tr = ((int) count) - 1; tr >= 0; tr--)
    //    {
    //        z = zone->Get(tr);
    //        if (z->End < this->Cursor.currentPos)
    //        {
    //            MoveTo(z->Start, select);
    //            return;
    //        }
    //    }
    //}
}
void BufferView::MoveTillEndBlock(bool selected)
{
    unsigned long long tr, gr, fileSize;
    bool found;

    fileSize = this->obj->cache.GetSize();

    for (tr = this->Cursor.currentPos; tr < fileSize;)
    {
        auto buf = this->obj->cache.Get(tr, 256);
        if (buf.Empty())
            break;
        if (buf.data[0] == 0)
        {
            found = true;
            for (gr = 0; (gr < 32) && (found) && (gr < buf.length); gr++)
            {
                if (buf.data[gr] != 0)
                    found = false;
            }
            if (found)
            {
                if (tr > 0)
                    tr--;
                if (tr < this->Cursor.currentPos)
                    return;
                break;
            }
            tr += gr;
        }
        else
            tr++;
    }
    MoveTo(tr, selected);
}

void BufferView::UpdateStringInfo(unsigned long long offset)
{
    auto buf = this->obj->cache.Get(offset, 1024);
    if (buf.Empty())
    {
        StringInfo.start  = GView::Utils::INVALID_OFFSET;
        StringInfo.end    = GView::Utils::INVALID_OFFSET;
        StringInfo.middle = GView::Utils::INVALID_OFFSET;
        StringInfo.type   = StringType::None;
        return;
    }

    // check for ascii
    {
        auto* s = buf.data;
        auto* e = s + buf.length;

        if (StringInfo.AsciiMask[*s])
        {
            while ((s < e) && (StringInfo.AsciiMask[*s]))
                s++;
            if (s - buf.data >= StringInfo.minCount)
            {
                // ascii string found
                StringInfo.start = offset;
                StringInfo.end   = offset + (s - buf.data);
                StringInfo.type  = StringType::Ascii;
                return;
            }
        }
    }

    // check for unicode
    {
        auto* s = (char16_t*) buf.data;
        auto* e = s + buf.length / 2;
        if ((s < e) && ((*s) < 256) && (StringInfo.AsciiMask[*s]))
        {
            while ((s < e) && ((*s) < 256) && (StringInfo.AsciiMask[*s]))
                s++;
            if (s - (char16_t*) buf.data >= StringInfo.minCount)
            {
                // ascii string found
                StringInfo.start  = offset;
                StringInfo.end    = offset + ((const unsigned char*) s - buf.data);
                StringInfo.middle = offset + (s - (char16_t*) buf.data);
                StringInfo.type   = StringType::Unicode;
                return;
            }
        }
    }

    // compute the size of non-string data
    StringInfo.start  = offset;
    StringInfo.middle = GView::Utils::INVALID_OFFSET;
    StringInfo.type   = StringType::None;

    {
        auto* s = buf.data;
        auto* e = s + buf.length;

        while (s < e)
        {
            while ((s < e) && (!StringInfo.AsciiMask[*s]))
                s++;
            if (s == e)
                break;
            // reached a possible string --> check for minim size
            auto* s_s = s;
            auto* s_e = s + StringInfo.minCount;
            if (s_e <= e)
            {
                while ((s_s < s_e) && (StringInfo.AsciiMask[*s_s]))
                    s_s++;
                if (s_s == s_e)
                {
                    // found a possible string at 's' position --> stop before 's'
                    StringInfo.end = offset + (s - buf.data);
                    return;
                }
            }
            // check if not an unicode string
            auto* u_s = (char16_t*) s;
            auto* u_e = u_s + StringInfo.minCount;
            if ((((const unsigned char*) u_e) + 1) <= e)
            {
                while ((u_s < u_e) && (*u_s < 256) && (StringInfo.AsciiMask[*u_s]))
                    u_s++;
                if (u_s == u_e)
                {
                    // found a possible unicode at 's' position --> stop before 's'
                    StringInfo.end = offset + (s - buf.data);
                    return;
                }
            }
            // no possible string found --> advance to next non_ascii character
            s = s_s;
        }
    }
    // all buffer was process and nothing was found
    StringInfo.end = offset + buf.length;
}

ColorPair BufferView::OffsetToColorZone(unsigned long long offset)
{
    return config.Colors.Normal;
}
ColorPair BufferView::OffsetToColor(unsigned long long offset)
{
    // check strings
    if ((offset >= StringInfo.start) && (offset < StringInfo.end))
    {
        switch (StringInfo.type)
        {
        case StringType::Ascii:
            return config.Colors.Ascii;
        case StringType::Unicode:
            return config.Colors.Unicode;
        }
    }
    else
    {
        UpdateStringInfo(offset);
        //if (StringInfo.type == StringType::None)
        //{
        //    LocalString<128> tmp;
        //    tmp.Format("No string: Start: %d, Size: %d ", (int) StringInfo.start, (int) (StringInfo.end - StringInfo.start));
        //    LOG_INFO(tmp.GetText());
        //}
        if ((offset >= StringInfo.start) && (offset < StringInfo.end))
        {
            switch (StringInfo.type)
            {
            case StringType::Ascii:
                return config.Colors.Ascii;
            case StringType::Unicode:
                return config.Colors.Unicode;
            }
        }
    }

    // not a string --> check the zone
    return OffsetToColorZone(offset);
}

void BufferView::UpdateViewSizes()
{
    // need to recompute all offsets lineAddressSize
    auto sz            = this->Layout.lineNameSize;
    this->Layout.xName = 0;

    if (this->Layout.lineAddressSize > 0)
    {
        this->Layout.xAddress = sz;
        if (sz > 0)
        {
            sz += this->Layout.lineAddressSize + 1; // one extra space
            this->Layout.xAddress++;
        }
        else
            sz += this->Layout.lineAddressSize;
    }

    if (sz > 0)
        sz += 3; // 3 extra spaces between offset (address) and characters
    this->Layout.xNumbers = sz;
    if (this->Layout.nrCols == 0)
    {
        this->Layout.xText = sz;
        // full screen --> ascii only
        auto width = (unsigned int) this->GetWidth();
        if (sz + 1 < width)
            this->Layout.charactersPerLine = width - (1 + sz);
        else
            this->Layout.charactersPerLine = 1;
    }
    else
    {
        this->Layout.xText = sz + this->Layout.nrCols * (characterFormatModeSize[(unsigned int) this->Layout.charFormatMode] + 1) + 3;
        this->Layout.charactersPerLine = this->Layout.nrCols;
    }
    // compute visible rows
    this->Layout.visibleRows = this->GetHeight();
    if (this->Layout.visibleRows > 0)
        this->Layout.visibleRows--;
    if (this->Layout.visibleRows == 0)
        this->Layout.visibleRows = 1;
}
void BufferView::PrepareDrawLineInfo(DrawLineInfo& dli)
{
    if (dli.recomputeOffsets)
    {
        // need to recompute all offsets
        dli.offsetAndNameSize = this->Layout.lineAddressSize;
        if (this->Layout.lineNameSize > 0)
        {
            if (dli.offsetAndNameSize > 0)
                dli.offsetAndNameSize += this->Layout.lineNameSize + 1; // one extra space
            else
                dli.offsetAndNameSize += this->Layout.lineNameSize;
        }
        if (dli.offsetAndNameSize > 0)
            dli.offsetAndNameSize += 3; // 3 extra spaces between offset (address) and characters
        if (this->Layout.nrCols == 0)
        {
            // full screen --> ascii only
            auto width      = (unsigned int) this->GetWidth();
            dli.numbersSize = 0;
            if (dli.offsetAndNameSize + 1 < width)
                dli.textSize = width - (1 + dli.offsetAndNameSize);
            else
                dli.textSize = 0;
        }
        else
        {
            auto sz         = characterFormatModeSize[(unsigned int) this->Layout.charFormatMode];
            dli.numbersSize = this->Layout.nrCols * (sz + 1) + 3; // one extra space between chrars + 3 spaces at the end
            dli.textSize    = this->Layout.nrCols;
        }
        // make sure that we have enough buffer
        this->chars.Resize(dli.offsetAndNameSize + dli.textSize + dli.numbersSize);
        dli.recomputeOffsets = false;
    }
    auto buf          = this->obj->cache.Get(dli.offset, dli.textSize);
    dli.start         = buf.data;
    dli.end           = buf.data + buf.length;
    dli.chNameAndSize = this->chars.GetBuffer();
    dli.chText        = dli.chNameAndSize + (dli.offsetAndNameSize + dli.numbersSize);
    dli.chNumbers     = dli.chNameAndSize + dli.offsetAndNameSize;
}
void BufferView::WriteHeaders(Renderer& renderer)
{
    renderer.FillHorizontalLine(0, 0, this->GetWidth(), ' ', config.Colors.Header);
    WriteTextParams params(WriteTextFlags::OverwriteColors | WriteTextFlags::SingleLine | WriteTextFlags::ClipToWidth);
    params.Align = TextAlignament::Left;
    params.Y     = 0;
    params.Color = config.Colors.Header;
    if (this->Layout.lineNameSize > 0)
    {
        params.X     = this->Layout.xName;
        params.Width = this->Layout.lineNameSize;
        renderer.WriteText("Name", params);
    }
    if (this->Layout.lineAddressSize > 0)
    {
        params.X     = this->Layout.xAddress;
        params.Width = this->Layout.lineAddressSize;
        renderer.WriteText("Address", params);
    }
    if (this->Layout.nrCols != 0)
    {
        params.X     = this->Layout.xNumbers;
        params.Width = this->Layout.xText - (this->Layout.xNumbers + 3);
        switch (this->Layout.charFormatMode)
        {
        case CharacterFormatMode::Hex:
            renderer.WriteText(hex_header, params);
            break;
        case CharacterFormatMode::Octal:
            renderer.WriteText(oct_header, params);
            break;
        case CharacterFormatMode::SignedDecimal:
            renderer.WriteText(signed_dec_header, params);
            break;
        case CharacterFormatMode::UnsignedDecimal:
            renderer.WriteText(unsigned_dec_header, params);
            break;
        }
    }
    params.X     = this->Layout.xText;
    params.Width = this->Layout.charactersPerLine;
    renderer.WriteText("Text", params);
}
void BufferView::WriteLineAddress(DrawLineInfo& dli)
{
    unsigned long long ofs = dli.offset;
    auto c                 = config.Colors.Inactive;
    auto n                 = dli.chNameAndSize;

    if (HasFocus())
        c = OffsetToColorZone(dli.offset);

    if (this->Layout.lineNameSize > 0)
    {
        auto e      = n + this->Layout.lineNameSize;
        auto txt    = std::string_view{ "Header", 6 };
        auto nm     = txt.data();
        auto nm_end = nm + txt.size();
        while (n < e)
        {
            if (nm < nm_end)
                n->Code = *nm;
            else
                n->Code = ' ';
            n->Color = c;
            n++;
            nm++;
        }
        n->Code  = ' ';
        n->Color = c;
        n++;
    }

    if (this->Layout.lineAddressSize > 0)
    {
        auto prev_n = n;
        auto s      = n + this->Layout.lineAddressSize - 1;
        n           = s + 1;
        // hex
        while (s >= prev_n)
        {
            s->Code  = hexCharsList[ofs & 0xF];
            s->Color = c;
            ofs >>= 4;
            s--;
        }
        if ((ofs > 0) && (this->Layout.lineAddressSize >= 3))
        {
            // value is to large --> add some points
            s        = prev_n;
            s->Code  = '.';
            s->Color = c;
            s++;
            s->Code  = '.';
            s->Color = c;
        }
    }

    // clear space
    while (n < dli.chNumbers)
    {
        n->Code  = ' ';
        n->Color = c;
        n++;
    }
}
void BufferView::WriteLineTextToChars(DrawLineInfo& dli)
{
    auto cp      = config.Colors.Inactive;
    bool activ   = this->HasFocus();

    if (activ)
    {
        while (dli.start < dli.end)
        {
            cp = OffsetToColor(dli.offset);
            if (dli.offset == this->Cursor.currentPos)
                cp = config.Colors.Cursor;
            if (StringInfo.type == StringType::Unicode)
            {
                if (dli.offset > StringInfo.middle)
                    dli.chText->Code = ' ';
                else
                    dli.chText->Code = CodePage[obj->cache.GetFromCache(((dli.offset - StringInfo.start) << 1) + StringInfo.start)];               
            }
            else
            {
                dli.chText->Code = CodePage[*dli.start];
            }
            dli.chText->Color = cp;
            dli.chText++;
            dli.start++;
            dli.offset++;
        }
    }
    else
    {
        while (dli.start < dli.end)
        {
            dli.chText->Code  = CodePage[*dli.start];
            dli.chText->Color = config.Colors.Inactive;
            dli.chText++;
            dli.start++;
        }
    }
}
void BufferView::WriteLineNumbersToChars(DrawLineInfo& dli)
{
    auto c       = dli.chNumbers;
    auto cp      = config.Colors.Inactive;
    bool activ   = this->HasFocus();
    auto ut      = (unsigned char) 0;

    while (dli.start < dli.end)
    {
        if (activ)
        {
            cp = OffsetToColor(dli.offset);
            if (dli.offset == this->Cursor.currentPos)
            {
                cp = config.Colors.Cursor;
                if (c > this->chars.GetBuffer())
                    (c - 1)->Color = cp;
            }
        }
        switch (this->Layout.charFormatMode)
        {
        case CharacterFormatMode::Hex:
            c->Code  = hexCharsList[(*dli.start) >> 4];
            c->Color = cp;
            c++;
            c->Code  = hexCharsList[(*dli.start) & 0x0F];
            c->Color = cp;
            c++;
            break;
        case CharacterFormatMode::Octal:
            c->Code  = '0' + ((*dli.start) >> 6);
            c->Color = cp;
            c++;
            c->Code  = '0' + (((*dli.start) >> 3) & 0x7);
            c->Color = cp;
            c++;
            c->Code  = '0' + ((*dli.start) & 0x7);
            c->Color = cp;
            c++;
            break;
        case CharacterFormatMode::UnsignedDecimal:
            if ((*dli.start) < 10)
            {
                c->Code  = ' ';
                c->Color = cp;
                c++;
                c->Code  = ' ';
                c->Color = cp;
                c++;
                c->Code  = '0' + *dli.start;
                c->Color = cp;
                c++;
            }
            else if ((*dli.start) < 100)
            {
                c->Code  = ' ';
                c->Color = cp;
                c++;
                c->Code  = '0' + ((*dli.start) / 10);
                c->Color = cp;
                c++;
                c->Code  = '0' + ((*dli.start) % 10);
                c->Color = cp;
                c++;
            }
            else
            {
                ut       = *dli.start;
                c->Code  = '0' + (ut / 100);
                c->Color = cp;
                c++;
                ut       = ut % 100;
                c->Code  = '0' + (ut / 10);
                c->Color = cp;
                c++;
                ut       = ut % 10;
                c->Code  = '0' + ut;
                c->Color = cp;
                c++;
            }
            break;
        case CharacterFormatMode::SignedDecimal:
            int tmp   = *(const char*) dli.start;
            char sign = '+';
            if (tmp < 0)
            {
                sign = '-';
                tmp  = -tmp;
            }
            if (tmp == 0)
                sign = ' ';
            if (tmp < 10)
            {
                c->Code  = ' ';
                c->Color = cp;
                c++;
                c->Code  = ' ';
                c->Color = cp;
                c++;
                c->Code  = sign;
                c->Color = cp;
                c++;
                c->Code  = '0' + tmp;
                c->Color = cp;
                c++;
            }
            else if (tmp < 100)
            {
                c->Code  = ' ';
                c->Color = cp;
                c++;
                c->Code  = sign;
                c->Color = cp;
                c++;
                c->Code  = '0' + (tmp / 10);
                c->Color = cp;
                c++;
                c->Code  = '0' + (tmp % 10);
                c->Color = cp;
                c++;
            }
            else
            {
                c->Code  = sign;
                c->Color = cp;
                c++;
                c->Code  = '0' + (tmp / 100);
                c->Color = cp;
                c++;
                tmp      = tmp % 100;
                c->Code  = '0' + (tmp / 10);
                c->Color = cp;
                c++;
                tmp      = tmp % 10;
                c->Code  = '0' + tmp;
                c->Color = cp;
                c++;
            }
            break;
        }
        c->Code  = ' ';
        c->Color = cp;
        c++;

        if (activ)
        {
            if (StringInfo.type == StringType::Unicode)
            {
                if (dli.offset > StringInfo.middle)
                    dli.chText->Code = ' ';
                else
                    dli.chText->Code = CodePage[obj->cache.GetFromCache(((dli.offset - StringInfo.start) << 1) + StringInfo.start)];
            }
            else
            {
                dli.chText->Code = CodePage[*dli.start];
            }
        }
        else
        {
            dli.chText->Code = CodePage[*dli.start];
        }

        dli.chText->Color = cp;
        dli.chText++;
        dli.start++;
        dli.offset++;
    }
}
void BufferView::Paint(Renderer& renderer)
{
    if (HasFocus())
        renderer.Clear(' ', config.Colors.Normal);
    else
        renderer.Clear(' ', config.Colors.Inactive);

    DrawLineInfo dli;
    WriteHeaders(renderer);
    for (unsigned int tr = 0; tr < this->Layout.visibleRows; tr++)
    {
        dli.offset = ((unsigned long long) this->Layout.charactersPerLine) * tr + this->Cursor.startView;
        if (dli.offset >= this->obj->cache.GetSize())
            break;
        PrepareDrawLineInfo(dli);
        WriteLineAddress(dli);
        if (this->Layout.nrCols == 0)
            WriteLineTextToChars(dli);
        else
            WriteLineNumbersToChars(dli);
        renderer.WriteSingleLineCharacterBuffer(0, tr + 1, chars);
    }
}
void BufferView::OnAfterResize(int width, int height)
{
    this->UpdateViewSizes();
}

bool BufferView::OnKeyEvent(AppCUI::Input::Key keyCode, char16_t charCode)
{
    bool select = ((keyCode & Key::Shift) != Key::None);
    if (select)
        keyCode = static_cast<Key>((unsigned int) keyCode - (unsigned int) Key::Shift);

    // tratare cazuri editare
    // if (this->EditMode)
    //{
    //    if ((KeyCode == Key::Tab) || (KeyCode == (Key::Tab | Key::Ctrl)))
    //    {
    //        if (IsNormalRow())
    //        {
    //            editNumbers    = !editNumbers;
    //            editNumbersOfs = 0;
    //        }
    //        return true;
    //    }
    //    if (KeyCode == Key::Backspace)
    //    {
    //        if (editNumbersOfs > 0)
    //            editNumbersOfs--;
    //        return true;
    //    }
    //    if (charCode >= 32)
    //    {
    //        AddChar(charCode);
    //        return true;
    //    }
    //}

    switch (keyCode)
    {
    case Key::Down:
        MoveTo(this->Cursor.currentPos + this->Layout.charactersPerLine, select);
        return true;
    case Key::Up:
        if (this->Cursor.currentPos > this->Layout.charactersPerLine)
            MoveTo(this->Cursor.currentPos - this->Layout.charactersPerLine, select);
        else
            MoveTo(0, select);
        return true;
    case Key::Left:
        if (this->Cursor.currentPos > 0)
            MoveTo(this->Cursor.currentPos - 1, select);
        return true;
    case Key::Right:
        MoveTo(this->Cursor.currentPos + 1, select);
        return true;
    case Key::PageDown:
        MoveTo(this->Cursor.currentPos + this->Layout.charactersPerLine * this->Layout.visibleRows, select);
        return true;
    case Key::PageUp:
        if (this->Cursor.currentPos > this->Layout.charactersPerLine * this->Layout.visibleRows)
            MoveTo(this->Cursor.currentPos - (this->Layout.charactersPerLine * this->Layout.visibleRows), select);
        else
            MoveTo(0, select);
        return true;
    case Key::Home:
        MoveTo(this->Cursor.currentPos - (this->Cursor.currentPos - this->Cursor.startView) % this->Layout.charactersPerLine, select);
        return true;
    case Key::End:
        MoveTo(
              this->Cursor.currentPos - (this->Cursor.currentPos - this->Cursor.startView) % this->Layout.charactersPerLine +
                    this->Layout.charactersPerLine - 1,
              select);
        return true;

    case Key::Ctrl | Key::Up:
        if (this->Cursor.startView > this->Layout.charactersPerLine)
            MoveScrollTo(this->Cursor.startView - this->Layout.charactersPerLine);
        else
            MoveScrollTo(0);
        return true;
    case Key::Ctrl | Key::Down:
        MoveScrollTo(this->Cursor.startView + this->Layout.charactersPerLine);
        return true;
    case Key::Ctrl | Key::Left:
        if (this->Cursor.startView >= 1)
            MoveScrollTo(this->Cursor.startView - 1);
        return true;
    case Key::Ctrl | Key::Right:
        MoveScrollTo(this->Cursor.startView + 1);
        return true;

    case Key::Ctrl | Key::Home:
        MoveTo(0, select);
        return true;
    case Key::Ctrl | Key::End:
        MoveTo(this->obj->cache.GetSize(), select);
        return true;
    case Key::Ctrl | Key::PageUp:
        // MoveToEndOrStartZone(select, true);
        return true;
    case Key::Ctrl | Key::PageDown:
        // MoveToEndOrStartZone(select, false);
        return true;

    case Key::Ctrl | Key::Alt | Key::PageUp:
        MoveTillNextBlock(select, -1);
        return true;
    case Key::Ctrl | Key::Alt | Key::PageDown:
        MoveTillNextBlock(select, 1);
        return true;

    case Key::Alt | Key::N1:
        MoveToSelection(0);
        return true;
    case Key::Alt | Key::N2:
        MoveToSelection(1);
        return true;
    case Key::Alt | Key::N3:
        MoveToSelection(2);
        return true;
    case Key::Alt | Key::N4:
        MoveToSelection(3);
        return true;
    case Key::Alt | Key::N0:
        MoveToSelection(4);
        return true;

    case Key::E:
        MoveTillEndBlock(select);
        return true;
    case Key::S:
        SkipCurentCaracter(select);
        return true;
        // case VK_MULTIPLY: if (this->File->Bookmarks[0]!=INVALID_FILE_POSITION)
        // MoveTo(this->File->Bookmarks[0],select); return true; case VK_NUMPAD0	:
        // this->startViewPoz=this->Cursor.currentPos; return true;

        // case VK_NUMPAD8	: MoveScrollTo(this->startViewPoz-nrX); return true;
        // case VK_NUMPAD2	: MoveScrollTo(this->startViewPoz+nrX); return true;
        // case VK_NUMPAD4	: MoveScrollTo(this->startViewPoz-1); return true;
        // case VK_NUMPAD6	: MoveScrollTo(this->startViewPoz+1); return true;
        // case VK_NUMPAD5	: MoveScrollTo(this->Cursor.currentPos-(nrX*(ObjectR.h-2)/2)); return true;
        // case VK_NUMPAD9 : MoveToPrevSection(); return true;
        // case VK_NUMPAD3 : MoveToNextSection(); return true;
        // case VK_NUMPAD7 : this->startViewPoz=this->Cursor.currentPos; return true;
        // case VK_NUMPAD0	: MoveToAlignSection();return true;

        // case VK_MULTIPLY: MoveTo(GetInfo()->F.g->GetEntryPoint(),select); return true;
    };

    if ((charCode >= '0') && (charCode <= '9'))
    {
        // auto addr = this->Bookmarks.Get(charCode - '0');
        // if (addr != GView::Utils::INVALID_OFFSET)
        //    MoveTo(addr, select);
        return true;
    }

    switch (charCode)
    {
    case '[':
        if (this->Layout.lineAddressSize > 0)
            Layout.lineAddressSize--;
        this->UpdateViewSizes();
        return true;
    case ']':
        if (this->Layout.lineAddressSize < 32)
            this->Layout.lineAddressSize++;
        this->UpdateViewSizes();
        return true;
    case '{':
        if (this->Layout.lineNameSize > 0)
            this->Layout.lineNameSize--;
        this->UpdateViewSizes();
        return true;
    case '}':
        if (this->Layout.lineNameSize < 32)
            this->Layout.lineNameSize++;
        this->UpdateViewSizes();
        return true;
    }

    return false;
}
bool BufferView::GoTo(unsigned long long offset)
{
    return false;
}
bool BufferView::Select(unsigned long long offset, unsigned long long size)
{
    return false;
}
std::string_view BufferView::GetName()
{
    return this->name;
}
void BufferView::AddZone(unsigned long long start, unsigned long long size, ColorPair col, std::string_view name)
{
    this->zList.Add(start, size, col, name);
}
void BufferView::AddBookmark(unsigned char bookmarkID, unsigned long long fileOffset)
{
    if (bookmarkID < 10)
        this->bookmarks[bookmarkID] = fileOffset;
}
void BufferView::AddOffsetTranslationMethod(std::string_view _name, MethodID _methodID)
{
    for (unsigned int tr = 0; tr < translationMethodsCount; tr++)
        if (this->translationMethods[tr].methodID == _methodID)
            return;
    if (translationMethodsCount >= sizeof(translationMethods) / sizeof(OffsetTranslationMethod))
        return;
    auto m      = &translationMethods[translationMethodsCount];
    m->methodID = _methodID;
    m->name     = _name;
    translationMethodsCount++;
}