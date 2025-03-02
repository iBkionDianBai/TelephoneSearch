#pragma once
//通过预编译的方式去掉UNICODE字符集，以避免相关的问题
#ifdef UNICODE
#undef UNICODE
#endif //UNICODE

#include <stdio.h>
#include <string.h>
#include <easyx.h>
#include <string>
#include <graphics.h>
#include <iostream>
#include <conio.h>
using namespace std;

#define PIC_WIDTH  800
#define PIC_HEIGHT 600

#define N 1024

struct Enterprise
{
	char name[50];
	char type[50];
	char phone[50];
	char address[50];
	char post[50];
};

class Window
{
public:

	inline static bool havemsg()
	{
		return ::peekmessage(&my_msg, EM_MOUSE | EM_KEY);
	}
	inline static const ExMessage& getmsg()
	{
		return my_msg;
	}
	static void render();
private:
	//声明指向获取到的设备消息的指针变量并获取消息
	inline static ExMessage my_msg;
};

class Button
{
public:
	static void button(int x, int y, int w, int h, TCHAR* text);
	static void back(int x, int y, int w, int h);
};

class Divide
{
public:
	bool divide(char inputcode[]);
};

class Frontpage
{
	enum Operator
	{
		Admin,
		User
	};

public:
	void run();

	int menu();

	void admin();
	void user();

	void back_main();


	ExMessage my_msg;
};

class Management_op
{
	enum Operator
	{
		Display_op,
		Add,
		Del,
		Modify,
		Search_op,
		List,
		Print_op
	};

	enum User
	{
		Display_us,
		Search_us,
		Print_us
	};
public:
	void run_op();
	void run_ur();

	void read_op();
	void read_ur();
	void display_op();
	void display_ur();
	void add();
	void del();
	void modify();
	void search();
	void print();

	void list_phone(int count);
	void list_name(int count);
	void list_post(int count);

	ExMessage my_msg;
};

class Table
{
public:
	static void drawline(int x1, int y1, int x2, int y2);
	static void drawtext(int x, int y, const char content[50]);
	static void drawtext_content(int x, int y, char content[50]);
	static void tablerender();
};

class Display
{
public:
	static void displayall(struct Enterprise* Ent, int count);
	static void displaypart(struct Enterprise* Ent, int count);
};