#include <iostream>
#include<stdio.h>
#include <easyx.h>
using namespace std;
void drawtext()
{
	settextstyle(48,0,L"Î¢ÈíÑÅºÚ");
	settextcolor(RGB(0,0,0));
	setbkmode(TRANSPARENT);
	outtextxy(200, 200,L"Hello World!");
}
void drawsharp()
{
	for (int i=100;i <= 500;i++)
	{
		
		for (int j = 100;j <= 500;j++)
		{
			putpixel(i,j,RGB(255,255,255));
		}
	}
	rectangle(200, 200, 300, 300);
	setfillcolor(RGB(93, 122, 83));
	fillrectangle(200, 200, 300, 300);
}
int main(void)
{
	initgraph(500, 500, EX_SHOWCONSOLE);
	setbkcolor(RGB(238,178,191));
	cleardevice();
	drawsharp();
	drawtext();
	system("pause");
	return 0;
}