#include "main.h"

Frontpage frp;
HWND my_win1;
Enterprise Ent[N];

void Management_op::run_op()
{
    Window::render();
    Management_op::read_op();

    TCHAR s[50] = "显示信息";
    TCHAR s1[50] = "增加信息";
    TCHAR s2[50] = "删除信息";
    TCHAR s3[50] = "更改信息";
    TCHAR s4[50] = "查询信息";
    TCHAR s5[50] = "导出文件";
    
    Button::button(280, 200, 230, 25, s);
    Button::button(280, 250, 230, 25, s1);
    Button::button(280, 300, 230, 25, s2);
    Button::button(280, 350, 230, 25, s3);
    Button::button(280, 400, 230, 25, s4);
    Button::button(280, 450, 230, 25, s5);
    
    Button::back(20, 20, 50, 20);

    int op = 7;

    while (true)
    {
        if (Window::havemsg())
        {
            my_msg = Window::getmsg();
            switch (my_msg.message)
            {
                case WM_LBUTTONDOWN:
                    if (my_msg.x >= 280 && my_msg.x <= 280 + 230 && my_msg.y >= 200 && my_msg.y <= 200 + 25)
                    {
                        op = 0;
                    }
                    if (my_msg.x >= 280 && my_msg.x <= 280 + 230 && my_msg.y >= 250 && my_msg.y <= 250 + 25)
                    {
                        op = 1;
                    }
                    if (my_msg.x >= 280 && my_msg.x <= 280 + 230 && my_msg.y >= 300 && my_msg.y <= 300 + 25)
                    {
                        op = 2;
                    }
                    if (my_msg.x >= 280 && my_msg.x <= 280 + 230 && my_msg.y >= 350 && my_msg.y <= 350 + 25)
                    {
                        op = 3;
                    }
                    if (my_msg.x >= 280 && my_msg.x <= 280 + 230 && my_msg.y >= 400 && my_msg.y <= 400 + 25)
                    {
                        op = 4;
                    }
                    if (my_msg.x >= 280 && my_msg.x <= 280 + 230 && my_msg.y >= 450 && my_msg.y <= 450 + 25)
                    {
                        op = 6;
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
        case 7:
            cout << "You are now at select menu!" << endl;
            break;
        case 27:
            frp.Frontpage::run();
            break;
        case Management_op::Display_op:
            Management_op::display_op();
            op = 7;
            break;
        case Management_op::Add:
            Management_op::add();
            op = 7;
            break;
        case Management_op::Del:
            Management_op::del();
            op = 7;
            break;
        case Management_op::Modify:
            Management_op::modify();
            op = 7;
            break;
        case Management_op::Search_op:
            Management_op::search();
            Button::back(20, 20, 50, 20);
            while (true)
            {
                if (Window::havemsg())
                {
                    my_msg = Window::getmsg();
                    switch (my_msg.message)
                    {
                    case WM_LBUTTONDOWN:
                        if (my_msg.x >= 20 && my_msg.x <= 20 + 50 && my_msg.y >= 20 && my_msg.y <= 20 + 20)
                        {
                            op = 7;
                            Window::render();
                            Management_op::read_ur();

                            Button::button(280, 200, 230, 25, s);
                            Button::button(280, 250, 230, 25, s1);
                            Button::button(280, 300, 230, 25, s2);
                            Button::button(280, 350, 230, 25, s3);
                            Button::button(280, 400, 230, 25, s4);
                            Button::button(280, 450, 230, 25, s5);

                            Button::back(20, 20, 50, 20);
                            break;
                        }
                    }
                }
                if (op == 7)
                    break;
            }
            break;
        case Management_op::Print_op:
            Management_op::print();
            op = 7;
            break;
        default:
            break;
        }
    }
}

void Management_op::run_ur()
{
    Window::render();
    Management_op::read_ur();

    TCHAR s[50] = "显示信息";
    TCHAR s1[50] = "查询信息";
    TCHAR s2[50] = "导出文件";

    Button::button(280, 250, 230, 25, s);
    Button::button(280, 300, 230, 25, s1);
    Button::button(280, 350, 230, 25, s2);

    Button::back(20, 20, 50, 20);
    int op = 3;
    while (true)
    {
        if (Window::havemsg())
        {
            my_msg = Window::getmsg();
            switch (my_msg.message)
            {
            case WM_LBUTTONDOWN:
                if (my_msg.x >= 280 && my_msg.x <= 280 + 230 && my_msg.y >= 250 && my_msg.y <= 250 + 25)
                {
                    op = 0;
                }
                if (my_msg.x >= 280 && my_msg.x <= 280 + 230 && my_msg.y >= 300 && my_msg.y <= 300 + 25)
                {
                    op = 1;
                }
                if (my_msg.x >= 280 && my_msg.x <= 280 + 230 && my_msg.y >= 350 && my_msg.y <= 350 + 25)
                {
                    op = 2;
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
            cout << "You are now at select menu!" << endl;
            break;
        case 27:
            frp.Frontpage::run();
            break;
        case Management_op::Display_us:
            Management_op::display_ur();
            op = 3;
            break;
        case Management_op::Search_us:
            Management_op::search();

            Button::back(20,20,50,20);
            while (true)
            {
                if (Window::havemsg())
                {
                    my_msg = Window::getmsg();
                    switch (my_msg.message)
                    {
                    case WM_LBUTTONDOWN:
                        if (my_msg.x >= 20 && my_msg.x <= 20 + 50 && my_msg.y >= 20 && my_msg.y <= 20 + 20)
                        {
                            op = 3;
                            Window::render();
                            Management_op::read_ur();

                            Button::button(280, 250, 230, 25, s);
                            Button::button(280, 300, 230, 25, s1);
                            Button::button(280, 350, 230, 25, s2);

                            Button::back(20, 20, 50, 20);
                            break;
                        }
                    }
                }
                if (op == 3)
                    break;
            }
            break;
        case Management_op::Print_us:
            Management_op::print();
            op = 3;
            break;
        default:
            break;
        }
    }
}

void Management_op::read_op()
{
    my_win1 = GetHWnd();
    int t = 0;
    FILE* file;
    errno_t err = fopen_s(&file, "Enterprise.txt", "rb + ");

    if (err != 0)
    {
        MessageBox(my_win1, "数据读取错误，请检查文件！", "错误", MB_OK);
        Management_op::run_op();
    }

    char line[N];
    while (fgets(line, N, file))
    {
        int se = sscanf_s(line, "%[^ ] %[^ ] %[^ ] %[^ ] %[^\n]",Ent[t].name,50, Ent[t].type,50 ,Ent[t].phone,50, Ent[t].address,50, Ent[t].post,50);
        cout << Ent[t].name << endl;
        cout << Ent[t].type << endl;
        cout << Ent[t].phone << endl;
        cout << Ent[t].address << endl;
        cout << Ent[t].post << endl;
        t++;
    }
    fclose(file);
    
}

void Management_op::read_ur()
{
    my_win1 = GetHWnd();
    int t = 0;
    FILE* file;
    errno_t err = fopen_s(&file, "Enterprise.txt", "rb+");
    if (err != 0)
    {
        MessageBox(my_win1, "数据读取错误，请联系管理员检查文件！", "错误", MB_OK);
        Management_op::run_ur();
    }

    char line[N];
    while (fgets(line, N, file))
    {
        int se = sscanf_s(line, "%[^ ] %[^ ] %[^ ] %[^ ] %[^\n]", Ent[t].name, 50, Ent[t].type, 50, Ent[t].phone, 50, Ent[t].address, 50, Ent[t].post, 50);
        cout << Ent[t].name << endl;
        cout << Ent[t].type << endl;
        cout << Ent[t].phone << endl;
        cout << Ent[t].address << endl;
        cout << Ent[t].post << endl;
        t++;
    }
    fclose(file);
}

void Management_op::display_op()
{
    Table::tablerender();

    TCHAR s[50] = "按单位类型显示";
    Button::button(20, 550, 150, 20, s);
    /*
    TCHAR s2[50] = "按单位电话排序";
    Button::button(180, 550, 150, 20, s2);
    TCHAR s3[50] = "按单位名称排序";
    Button::button(340, 550, 150, 20, s3);
    TCHAR s4[50] = "按邮政编码排序";
    Button::button(500, 550, 150, 20, s4);
    */
    Button::back(20, 20, 50, 20);

    int op = 1;
    int count = sizeof(Ent) / sizeof(Enterprise);
    while (true)
    {
        if (Window::havemsg())
        {
            my_msg = Window::getmsg();
            switch (my_msg.message)
            {
            case WM_LBUTTONDOWN:
                if (my_msg.x >= 20 && my_msg.x <= 20 + 150 && my_msg.y >= 550 && my_msg.y <= 550 + 20)
                {
                    op = 0;
                }
                /*
                if (my_msg.x >= 180 && my_msg.x <= 180 + 150 && my_msg.y >= 550 && my_msg.y <= 550 + 20)
                {
                    op = 2;
                }
                if (my_msg.x >= 340 && my_msg.x <= 340 + 150 && my_msg.y >= 550 && my_msg.y <= 550 + 20)
                {
                    op = 3;
                }
                if (my_msg.x >= 500 && my_msg.x <= 500 + 150 && my_msg.y >= 550 && my_msg.y <= 550 + 20)
                {
                    op = 4;
                }
                */
                if (my_msg.x >= 20 && my_msg.x <= 20 + 50 && my_msg.y >= 20 && my_msg.y <= 20 + 20)
                {
                    op = 27;
                }
                break;

            }
        }
        switch (op)
        {
        case 0:
            cout << "You will get listed content!" << endl;
            Display::displaypart(Ent, count);

            Button::back(20, 20, 50, 20);
            while (true)
            {
                if (Window::havemsg())
                {
                    my_msg = Window::getmsg();
                    switch (my_msg.message)
                    {
                    case WM_LBUTTONDOWN:
                        if (my_msg.x >= 20 && my_msg.x <= 20 + 50 && my_msg.y >= 20 && my_msg.y <= 20 + 20)
                        {
                            op = 27;
                        break;
                        }
                    }
                }
                if (op == 27)
                    break;
            }
            break;
        case 1:
            Display::displayall(Ent, count);
            break;
        case 2:
            Management_op::list_phone(count);
            op = 1;
            break;
        case 3:
            Management_op::list_name(count);
            op = 1;
            break;
        case 4:
            Management_op::list_post(count);
            op = 1;
            break;
        case 27:
            Management_op::run_op();
            break;
        }
    }
}

void Management_op::display_ur()
{
    Table::tablerender();
    
    //Table::drawtext(620, 10, "邮件地址");

    TCHAR s[50] = "按单位类型显示";
    Button::button(20, 550, 150, 20, s);
    /*
    TCHAR s2[50] = "按单位电话排序";
    Button::button(180, 550, 150, 20, s2);
    TCHAR s3[50] = "按单位名称排序";
    Button::button(340, 550, 150, 20, s3);
    TCHAR s4[50] = "按邮政编码排序";
    Button::button(500, 550, 150, 20, s4);
    */
    Button::back(20, 20, 50, 20);

    int op = 1;
    int count = sizeof(Ent) / sizeof(Enterprise);
    while (true)
    {
        if (Window::havemsg())
        {
            my_msg = Window::getmsg();
            switch (my_msg.message)
            {
            case WM_LBUTTONDOWN:
                if (my_msg.x >= 20 && my_msg.x <= 20 + 150 && my_msg.y >= 550 && my_msg.y <= 550 + 20)
                {
                    op = 0;
                }
                /*
                if (my_msg.x >= 180 && my_msg.x <= 180 + 150 && my_msg.y >= 550 && my_msg.y <= 550 + 20)
                {
                    op = 2;
                }
                if (my_msg.x >= 340 && my_msg.x <= 340 + 150 && my_msg.y >= 550 && my_msg.y <= 550 + 20)
                {
                    op = 3;
                }
                if (my_msg.x >= 500 && my_msg.x <= 500 + 150 && my_msg.y >= 550 && my_msg.y <= 550 + 20)
                {
                    op = 4;
                }
                */
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
        case 0:
            cout << "You will get listed content!" << endl;
            Display::displaypart(Ent,count);

            Button::back(20, 20, 50, 20);
            while (true)
            {
                if (Window::havemsg())
                {
                    my_msg = Window::getmsg();
                    switch (my_msg.message)
                    {
                    case WM_LBUTTONDOWN:
                        if (my_msg.x >= 20 && my_msg.x <= 20 + 50 && my_msg.y >= 20 && my_msg.y <= 20 + 20)
                        {
                            op = 27;
                            break;
                        }
                    }
                }
                if (op == 27)
                    break;
            }
            break;
        case 1:
            Display::displayall(Ent, count);
            break;
        case 2:
            Management_op::list_phone(count);
            Table::tablerender();
            Display::displayall(Ent, count);
            Button::back(20, 20, 50, 20);
            while (true)
            {
                if (Window::havemsg())
                {
                    my_msg = Window::getmsg();
                    switch (my_msg.message)
                    {
                    case WM_LBUTTONDOWN:
                        if (my_msg.x >= 20 && my_msg.x <= 20 + 50 && my_msg.y >= 20 && my_msg.y <= 20 + 20)
                        {
                            op = 27;
                            break;
                        }
                    }
                }
                if (op == 27)
                    break;
            }
            break;
        case 3:
            Management_op::list_name(count);
            Table::tablerender();
            Display::displayall(Ent, count);
            Button::back(20, 20, 50, 20);
            while (true)
            {
                if (Window::havemsg())
                {
                    my_msg = Window::getmsg();
                    switch (my_msg.message)
                    {
                    case WM_LBUTTONDOWN:
                        if (my_msg.x >= 20 && my_msg.x <= 20 + 50 && my_msg.y >= 20 && my_msg.y <= 20 + 20)
                        {
                            op = 27;
                            break;
                        }
                    }
                }
                if (op == 27)
                    break;
            }
            break;
        case 4:
            Management_op::list_post(count);
            Table::tablerender();
            Display::displayall(Ent, count);
            Button::back(20, 20, 50, 20);
            while (true)
            {
                if (Window::havemsg())
                {
                    my_msg = Window::getmsg();
                    switch (my_msg.message)
                    {
                    case WM_LBUTTONDOWN:
                        if (my_msg.x >= 20 && my_msg.x <= 20 + 50 && my_msg.y >= 20 && my_msg.y <= 20 + 20)
                        {
                            op = 27;
                            break;
                        }
                    }
                }
                if (op == 27)
                    break;
            }
            break;
        case 27:
            Management_op::run_ur();
            break;
        }
    }
}
void Management_op::add()
{
    FILE* file;
    errno_t err = fopen_s(&file, "Enterprise.txt", "a");
    char data[N];
    InputBox(data, N, "请输入您要添加的内容", "输入内容", "格式：单位名称 单位类型 单位电话 单位地址 单位邮编", 800, 1, false);
    fputs(data,file);
    fputc('\n', file);
    fclose(file);
}

void Management_op::del()
{
    FILE* file;
    errno_t err = fopen_s(&file,"Enterprise.txt", "r");
    FILE* tempFile;
    errno_t err2 = tmpfile_s(&tempFile);
    char buffer[1024];
    char data[N];
    InputBox(data, N, "请输入您要删除的内容", "输入内容", "格式：单位名称 单位类型 单位电话 单位地址 单位邮编", 800, 1, false);
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char* match = strstr(buffer, data);
        if (match == NULL) {
            fputs(buffer, tempFile);
        }
    }
    fclose(file);

    fopen_s(&file, "Enterprise.txt", "w");
    rewind(tempFile);
    while (fgets(buffer, sizeof(buffer), tempFile) != NULL) {
        fputs(buffer, file);
    }
    fclose(tempFile);
    fclose(file);
}

void Management_op::modify()
{
    FILE* file;
    errno_t err = fopen_s(&file, "Enterprise.txt", "r");
    FILE* tempFile;
    errno_t err2 = tmpfile_s(&tempFile);
    char data[N];
    char input[N];
    InputBox(data, N, "请输入您要修改的内容", "输入内容", "格式：单位名称 单位类型 单位电话 单位地址 单位邮编", 800, 1, true);
    InputBox(input, N, "请输入修改后的内容", "输入内容", "格式：单位名称 单位类型 单位电话 单位地址 单位邮编", 800, 1, true);
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char* match = strstr(buffer, data);
        if (match == NULL) {
            fputs(buffer, tempFile);
        }
        else
        {
            fputs(input , tempFile);
            fputc('\n', file);
        }
    }
    fclose(file);

    fopen_s(&file, "Enterprise.txt", "w");
    rewind(tempFile);
    while (fgets(buffer, sizeof(buffer), tempFile) != NULL) {
        fputs(buffer, file);
    }
    fclose(tempFile);
    fclose(file);
}

void Management_op::search()
{
    int i = 0;
    int t = 55;
    char data[20] = {};
    int count = sizeof(Ent) / sizeof(Enterprise);
    InputBox(data, 20, "请输入您要查找的单位信息", "输入内容", "如：单位名称或电话号码", 200, 1, true);
    while (i < count)
    {
        if (strcmp(Ent[i].name, data) == 0)
        {

            Table::tablerender();
            Table::drawtext(120, 10, "单位名称");
            Table::drawtext(220, 10, "单位类型");
            Table::drawtext(320, 10, "单位电话");
            Table::drawtext(420, 10, "单位地址");
            Table::drawtext(550, 10, "邮政编码");

            Table::drawline(100, 50, 700, 50);

            Table::drawtext_content(120, t, Ent[i].name);
            Table::drawtext_content(220, t, Ent[i].type);
            Table::drawtext_content(320, t, Ent[i].phone);
            Table::drawtext_content(420, t, Ent[i].address);
            Table::drawtext_content(540, t, Ent[i].post);
            t += 25;
        }

        if (strcmp(Ent[i].phone, data) == 0)
        {
            Table::tablerender();
            Table::drawtext(120, 10, "单位名称");
            Table::drawtext(220, 10, "单位类型");
            Table::drawtext(320, 10, "单位电话");
            Table::drawtext(420, 10, "单位地址");
            Table::drawtext(550, 10, "邮政编码");

            Table::drawline(100, 50, 700, 50);

            Table::drawtext_content(120, t, Ent[i].name);
            Table::drawtext_content(220, t, Ent[i].type);
            Table::drawtext_content(320, t, Ent[i].phone);
            Table::drawtext_content(420, t, Ent[i].address);
            Table::drawtext_content(540, t, Ent[i].post);
            t += 25;    
        }
        
        i++;
        /*
        if ((strcmp(Ent[i].name, data) != 0) && (strcmp(Ent[i].phone, data) != 0))
        {
            my_win1 = GetHWnd();
            MessageBox(my_win1, "该单位不存在", "错误", MB_OK);
            return;
        }
        */
    }
}

void Management_op::print()
{
    FILE* file;
    errno_t err = fopen_s(&file, "content.txt", "wb");
    int count = sizeof(Ent) / sizeof(Enterprise);
    int t=0;
    while (t < count)
    {
        fprintf(file, "%10s %20s %20s %20s %20s\n", Ent[t].name, Ent[t].type, Ent[t].phone, Ent[t].address, Ent[t].post);
        t++;
    }
    fclose(file);
    my_win1 = GetHWnd();
    MessageBox(my_win1, "您的文件已经导出!", "提示", MB_OK);
}

int cmp(const void* p, const void* q)
{
        Enterprise c = *(Enterprise*)p;
        Enterprise d = *(Enterprise*)q;
        if (c.phone != d.phone) {
            return c.phone > d.phone ? -1 : 1;
        }
        else return strcmp(c.name, d.name);
}
void Management_op::list_phone(int count)
{
    int i;
    qsort(Ent + 1, count, sizeof(Ent[1]), cmp);
}

void Management_op::list_name(int count)
{
    int i;
    int j;
    Enterprise Ent_temp;
    for (i = 0;i < count-1;i++)
    {
        for (j = i;j < count -1;j++)
        {
            if (strcmp(Ent[j].name, Ent[j + 1].name) > 0)
            {
                Ent_temp = Ent[j];
                Ent[j] = Ent[j + 1];
                Ent[j + 1] = Ent_temp;
            }
        }
    }
}

void Management_op::list_post(int count)
{
    int i;
    int j;
    Enterprise Ent_temp;
    for(i = 0;i < count-1;i++)
    {
        for (j = i;j < count -1;j++)
        {
            if (strcmp(Ent[j].post, Ent[j + 1].post) >= 0)
            {
                Ent_temp = Ent[j];
                Ent[j] = Ent[j + 1];
                Ent[j + 1] = Ent_temp;
            }
        }
    }
}
