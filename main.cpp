#include <iostream>
#include "mygraphics.h"
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
bool gameover, fi;
int w, h;
int x, y, fruitx, fruity, score, blocksize, a, b, t, body, speed;
int bx[793] = {}, by[793] = {};
char dir, buff;

void maximizeWindow()
{ //This function is defined to Maximize window
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_SHOWMAXIMIZED);
}
void mover(int a[], int s)
{
    for (int i = 1; i <= s + 3; i++)
        a[i - 1] = a[i];
}
void display()
{
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "    SSSSSSSSSSSSSSS                                   kkkkkkkk                                       GGGGGGGGGGGGG" << endl;
    cout << "  SS:::::::::::::::S                                  k::::::k                                    GGG::::::::::::G" << endl;
    cout << " S:::::SSSSSS::::::S                                   k:::::k                                  GG:::::::::::::::G" << endl;
    cout << " S:::::S     SSSSSSS                                   k:::::k                                 G:::::GGGGGGGG::::G" << endl;
    cout << " S:::::S          nnnn  nnnnnnnn      aaaaaaaaaaaaa    k:::::k    kkkkkkk eeeeeeeeeeee        G:::::G       GGGGGG  aaaaaaaaaaaaa      mmmmmmm    mmmmmmm       eeeeeeeeeeee" << endl;
    cout << " S:::::S          n:::nn::::::::nn    a::::::::::::a   k:::::k   k:::::kee::::::::::::ee     G:::::G                a::::::::::::a   mm:::::::m  m:::::::mm   ee::::::::::::e" << endl;
    cout << "  S::::SSSS       n::::::::::::::nn   aaaaaaaaa:::::a  k:::::k  k:::::ke::::::eeeee:::::ee   G:::::G                aaaaaaaaa:::::a m::::::::::mm::::::::::m e::::::eeeee:::ee" << endl;
    cout << "   SS::::::SSSSS  nn:::::::::::::::n           a::::a  k:::::k k:::::ke::::::e     e:::::e   G:::::G    GGGGGGGGGG           a::::a m::::::::::::::::::::::me::::::e     e:::e" << endl;
    cout << "     SSS::::::::SS  n:::::nnnn:::::n    aaaaaaa:::::a  k::::::k:::::k e:::::::eeeee::::::e   G:::::G    G::::::::G    aaaaaaa:::::a m:::::mmm::::::mmm:::::me:::::::eeeee::::e" << endl;
    cout << "        SSSSSS::::S n::::n    n::::n  aa::::::::::::a  k:::::::::::k  e:::::::::::::::::e    G:::::G    GGGGG::::G  aa::::::::::::a m::::m   m::::m   m::::me::::::::::::::::e" << endl;
    cout << "             S:::::Sn::::n    n::::n a::::aaaa::::::a  k:::::::::::k  e::::::eeeeeeeeeee     G:::::G        G::::G a::::aaaa::::::a m::::m   m::::m   m::::me::::::eeeeeeeeee" << endl;
    cout << "             S:::::Sn::::n    n::::na::::a    a:::::a  k::::::k:::::k e:::::::e               G:::::G       G::::Ga::::a    a:::::a m::::m   m::::m   m::::me:::::::e" << endl;
    cout << " SSSSSSS     S:::::Sn::::n    n::::na::::a    a:::::a  k:::::k k:::::ke::::::::e               G:::::GGGGGGGG::::Ga::::a    a:::::a m::::m   m::::m   m::::me::::::::e" << endl;
    cout << " S::::::SSSSSS:::::Sn::::n    n::::na:::::aaaa::::::a  k:::::k  k:::::ke::::::::eeeeeeee        GG:::::::::::::::Ga:::::aaaa::::::a m::::m   m::::m   m::::m e::::::::eeeeeeee" << endl;
    cout << " S:::::::::::::::SS n::::n    n::::n a::::::::::::::a k::::::k   k:::::kee:::::::::::::e          GGG::::::::::::G a::::::::::::::a m::::m   m::::m   m::::m  ee:::::::::::::e" << endl;
    cout << "  SSSSSSSSSSSSSSS   nnnnnn    nnnnnn  aaaaaaaaaaaaaaa kkkkkkkk    kkkkkkk eeeeeeeeeeeeee             GGGGGGGGGGGGG  aaaaaaaaaaaaaaaammmmmm   mmmmmm   mmmmmm    eeeeeeeeeeeeee" << endl;
}
void setup()
{
    showConsoleCursor(false);
    maximizeWindow();
    getWindowDimensions(w, h);
    blocksize = 30;
    srand(time(0));
    w = (w / blocksize) * blocksize;
    h = (h / blocksize) * blocksize;
    a = blocksize / 2;
    body = 3;
    dir = buff = '\0';
    x = ((w / 2) / 30) * 30;
    y = ((h / 2) / 30) * 30;
    gameover = false;
    for (int i = 0; i < 3; i++)
        bx[i] = x + ((i + 3) * 30);
    for (int i = 0; i < body; i++)
        by[i] = y;
    fruitx = (((rand() % (w - 30)) / 30) * 30) + 30;
    fruity = (((rand() % (h - 30)) / 30) * 30) + 30;
    t = 0;
    fi = true;
    by[body - 1] = y;
    score = 0;
    speed = 1024;
    showConsoleCursor(false);
}
void draw()
{
    // drawRectangle(0,0,w,h,255,255,255);
    drawLine(0, 0, w, 0, 255, 255, 255);
    drawLine(0, 0, 0, h, 255, 255, 255);
    drawLine(w, 0, w, h, 255, 255, 255);
    drawLine(0, h, w, h, 255, 255, 255);
    drawRectangle(x - a, y - a, x + a, y + a, 255, 0, 0, 255, 0, 0);

    drawRectangle(fruitx - a, fruity - a, fruitx + a, fruity + a, 0, 255, 0, 0, 255, 0);
    drawRectangle(bx[0] - a, by[0] - a, bx[0] + a, by[0] + a, 0, 0, 0, 0, 0, 0);
}
void input()
{

    if (kbhit())
    {
        buff = getch();
        if (buff == 'a' || buff == 'A' || buff == 75 || buff == 'd' || buff == 'D' || buff == 77 || buff == 'w' || buff == 'W' || buff == 72 || buff == 's' || buff == 'S' || buff == 80)
        {
            if (fi)
            {
                dir = buff;
                fi = false;
                drawRectangle((((w / 2) / 30) * 30) - a, (((h / 2) / 30) * 30) - a, (((w / 2) / 30) * 30) + a, (((h / 2) / 30) * 30) + a, 0, 0, 0, 0, 0, 0);
            }
            else if (dir == 75 && (buff == 'w' || buff == 'W' || buff == 72 || buff == 's' || buff == 'S' || buff == 80))
                dir = buff;
            else if (dir == 77 && (buff == 'w' || buff == 'W' || buff == 72 || buff == 's' || buff == 'S' || buff == 80))
                dir = buff;
            else if (dir == 72 && (buff == 'a' || buff == 'A' || buff == 75 || buff == 'd' || buff == 'D' || buff == 77))
                dir = buff;
            else if (dir == 80 && (buff == 'a' || buff == 'A' || buff == 75 || buff == 'd' || buff == 'D' || buff == 77))
                dir = buff;
        }
        buff = '/0';
    }
}
void logic()
{
    if (dir == 'a' || dir == 'A' || dir == 75)
    {
        dir = 75;
        x -= 30;
    }
    if (dir == 'd' || dir == 'D' || dir == 77)
    {
        dir = 77;
        x += 30;
    }
    if (dir == 'w' || dir == 'W' || dir == 72)
    {
        dir = 72;
        y -= 30;
    }
    if (dir == 's' || dir == 'S' || dir == 80)
    {
        dir = 80;
        y += 30;
    }
    for (int i = 0; i < body - 1; i++)
    {
        if (x == bx[i] && y == by[i])
            gameover = true;
    }
    bx[body + 1] = x;
    by[body + 1] = y;
    mover(bx, body);
    mover(by, body);
    if (x > w || x < 0 || y < 0 || y > h)
        gameover = true;
    if (x == fruitx && y == fruity)
    {
        score++;
        // if(score==1)
        //   drawRectangle((((w/2)/30)*30)-a,(((h/2)/30)*30)-a,(((w/2)/30)*30)+a,(((h/2)/30)*30)+a,0,0,0,0,0,0);
        body++;
        fruitx = (((rand() % (w - 30)) / 30) * 30) + 30;
        fruity = (((rand() % (h - 30)) / 30) * 30) + 30;
    }
    t = 0;
    //time++;
}
main()
{
    setup();
    display();
    getch();
    system("cls");
    while (!gameover)
    {
        if (t >= speed)
            draw();
        input();
        if (t >= speed && fi == false)
            logic();
        t++;
    }
    system("cls");
    cout << "Score: " << score * 10;
    getch();
    getch();
    getch();
    return 0;
}