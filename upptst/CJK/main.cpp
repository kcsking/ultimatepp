#include <CtrlLib/CtrlLib.h>

using namespace Upp;

struct MyApp : TopWindow {
	void Paint(Draw& w) {
		String text;
		text << WString(0x1F603, 1).ToString();
		text << " Quick brown fox, 訓民正音 (훈민정음) ";
		
		w.DrawRect(GetSize(), White());
		int y = 10;
		int x = 10;
		for(int i = 0; i < Font::GetFaceCount(); i++)
		{
			Font fnt(i, 30);
			if(fnt.IsSpecial()) continue;
			fnt.Italic();
			String n = AsString(i) + ": " + fnt.GetFaceName() + ": ";
			if(fnt.IsSpecial())
				n << " (special)";
			w.DrawText(x, y, n, StdFont());
			w.DrawText(x + GetTextSize(n, StdFont()).cx, y, text, fnt);
			y += fnt.GetLineHeight() + 10;
			if(y > GetSize().cy) {
				x += GetSize().cx / 3;
				if(x > GetSize().cx)
					return;
				y = 10;
			}
		}
	}
};

GUI_APP_MAIN {
	MyApp().Sizeable().Zoomable().Run();
}