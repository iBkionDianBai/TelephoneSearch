#include "main.h"

ExMessage my_msg1;
void Display::displayall(struct Enterprise *Ent , int count)
{
	int i = 0;
	int t = 55;
	while (i<count)
	{
		Table::drawtext_content(120,t, Ent[i].name);
		Table::drawtext_content(220,t, Ent[i].type);
		Table::drawtext_content(320,t, Ent[i].phone);
		Table::drawtext_content(420,t, Ent[i].address);
		Table::drawtext_content(540,t, Ent[i].post);
		i++;
		t += 25;
	}
}

void Display::displaypart(struct Enterprise *Ent , int count)
{
	Table::tablerender();
	int i = 0;
	int t = 55;
	char input[20];
	InputBox(input, 20, "请输入您要显示的类型", "输入内容", "如：科技企业", 200, 1, false);
	while (i < count)
	{
		if (strcmp(Ent[i].type, input) == 0)
		{
			Table::drawtext_content(120, t, Ent[i].name);
			Table::drawtext_content(220, t, Ent[i].type);
			Table::drawtext_content(320, t, Ent[i].phone);
			Table::drawtext_content(420, t, Ent[i].address);
			Table::drawtext_content(540, t, Ent[i].post);
			t += 25;
		}
		i++;
	}
}
