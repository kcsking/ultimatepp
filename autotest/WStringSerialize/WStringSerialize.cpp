#include <Core/Core.h>

using namespace Upp;

CONSOLE_APP_MAIN
{
	Vector<WString> x;
	LoadFromFile(x, GetDataFile("wstring.bin"));
	DDUMPC(x);
	CheckLogEtalon();
	RLOG("================= OK");
}
