#include "main.h"

#define PIC_WIDTH  800
#define PIC_HEIGHT 600

IMAGE my_img;

int main()
{
	initgraph(PIC_WIDTH, PIC_HEIGHT, EW_SHOWCONSOLE);
	loadimage(&my_img, "bgk3.jpg", PIC_WIDTH, PIC_HEIGHT, 1);
	Frontpage frp{};
	frp.run();
	return 0;
}

void Button::button(int x, int y, int w, int h, TCHAR* text)
{
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(237, 210, 203));
	fillroundrect(x, y, x + w, y + h, 10, 10);

	TCHAR s[50] = "hello";
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;

	outtextxy(tx, ty, text);
}

void Button::back(int x, int y, int w, int h)
{
	TCHAR s[50] = "·µ»Ø";
	Button::button(x, y, w, h, s);
}


bool Divide::divide(char inputcode[])
{
	char havecode[20] = { "abc123" };
	if (strcmp(havecode, inputcode) == 0)
		return true;
	else
		return false;
}

void Window::render()
{
	cleardevice();
	putimage(0, 0, &my_img);
	setbkmode(TRANSPARENT);
	settextcolor(RGB(54, 29, 50));
	settextstyle(20, 0, ("Î¢ÈíÑÅºÚ"));
}

