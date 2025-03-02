#include "main.h"

void Table::drawline(int x1,int y1,int x2,int y2)
{
	line(x1,y1 ,x2 ,y2);
}

void Table::drawtext(int x, int y, const char content[50])
{
	outtextxy(x, y, content);
}

void Table::drawtext_content(int x, int y, char content[50])
{
	//settextstyle(20, 0, ("΢���ź�"));
	outtextxy(x, y, content);
}

void Table::tablerender()
{
	setbkcolor(RGB(246, 219, 198));
	cleardevice();
	setlinecolor(RGB(54, 29, 50));
	setbkmode(TRANSPARENT);
	settextcolor(RGB(54, 29, 50));
	settextstyle(20, 0, ("΢���ź�"));

	Table::drawtext(120, 10, "��λ����");
	Table::drawtext(220, 10, "��λ����");
	Table::drawtext(320, 10, "��λ�绰");
	Table::drawtext(420, 10, "��λ��ַ");
	Table::drawtext(550, 10, "��������");

	Table::drawline(100, 50, 700, 50);
}

