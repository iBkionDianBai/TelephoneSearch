#include "main.h"

Divide dive;
HWND my_win;
Management_op man;

int cheak;
char inputcode[20];

void Frontpage::run()
{
	Window::render();
	TCHAR s[50] = "����Ա";
	TCHAR s1[50] = "�û�";
	
	Button::button(280, 200, 230, 50, s);
	Button::button(280, 300, 230, 50, s1);

	TCHAR s2[50] = "�˳�";
	Button::button(20, 20, 50, 20, s2);
	int op = 3;
	
	while (true)
	{
		if (Window::havemsg())
		{
			my_msg = Window::getmsg();
			switch (my_msg.message)
			{
				case WM_LBUTTONDOWN:
					if (my_msg.x >= 280 && my_msg.x <= 280 + 230 && my_msg.y >= 200 && my_msg.y <= 200 + 50)
					{
						op = 0;
					}
					if (my_msg.x >= 280 && my_msg.x <= 280 + 230 && my_msg.y >= 300 && my_msg.y <= 300 + 50)
					{
						op = 1;
					}
					if (my_msg.x >= 20 && my_msg.x <= 20 + 50 && my_msg.y >= 20 && my_msg.y <= 20 + 20)
					{
						op = 27;
					}
				break;
			default:
				break;
			}
		}
		switch (op)
		{
		case 3:
			cout << "You are now at menu!" << endl;
			break;
		case 27:
			my_win = GetHWnd();
			cheak = MessageBox(my_win, "��ȷ��Ҫ�˳���", "�˳�", MB_OKCANCEL);
			if (cheak == IDOK)
			{ 
				closegraph();
				return;
			}
			else
				op = 3;
			break;
		case Frontpage::Admin:
			admin();
			op = 3;
			break;
		case Frontpage::User:
			user();
			op = 3;
			break;
		default:
			break;
		}

		FlushBatchDraw();
	}
	EndBatchDraw();
}

int Frontpage::menu()
{
	int op = 0;
    return op;
}

void Frontpage::admin()
{
	cout << "admin" << endl;
	InputBox(inputcode, 20, "����������ʶ����", "����ʶ����", "��123456" , 200,1,false);
	if(dive.Divide::divide(inputcode))
	{
		man.run_op();
	}
	else
	{
		my_win = GetHWnd();
		MessageBox(my_win, "����ʶ���벻��ȷ��", "��ʾ", MB_OK);
	}
	
}

void Frontpage::user()
{
	cout << "user" << endl;
	my_win = GetHWnd();
	MessageBox(my_win, "��ӭʹ�ã�", "��ӭ", MB_OK);
	man.run_ur();
}

void Frontpage::back_main()
{

}





