#include <iostream>
#include <math.h>
#include"Header.h"
#define PI 3.141592653589793

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;

myRectangle::myRectangle(int _x,int _y)
{
	x = _x;
	y = _y;
}

void myRectangle::Play(int a)
{
	x += a;
}

myWindow::myWindow(int _x, int _y, int h)
{
	x = _x;
	y = _y;
}

void myWindow::DrawWin(Brush^ _br, Graphics^ graphics, Pen^ pen,int h)
{
	graphics->FillRectangle(_br, x + 12*h, y + 3*h, 7*h, 7*h);
	graphics->DrawRectangle(pen, x + 12 * h, y + 3 * h, 7*h, 7*h);
	graphics->FillRectangle(_br, x + 22 * h, y + 3 * h, 7 * h, 7 * h);
	graphics->DrawRectangle(pen, x + 22 * h, y + 3 * h, 7 * h, 7 * h);
	graphics->FillRectangle(_br, x + 32*h, y + 3 * h, 7 * h, 7 * h);
	graphics->DrawRectangle(pen, x + 32*h, y + 3 * h, 7 * h, 7 * h);
}

void myWindow::PlayWin(int a)
{
	x += a;
}

myDoor::myDoor(int _x, int _y, int h)
{
	x = _x;
	y = _y;
}

void myDoor::DrawDoor(Pen^ pen, Graphics^ graphics,int h)
{
	graphics->FillRectangle(Brushes::SaddleBrown, x, y + 5 * h, 7 * h, 9 * h);
	graphics->DrawRectangle(pen, x, y + 5 * h, 7 * h, 9 * h);
}

void myDoor::PlayDoor(int a)
{
	x += a;
}

myTube::myTube(int _x,int _y)
{
	x = _x;
	y = _y;
}

void myTube::DrawTube(Pen^ pen, Graphics^ graphics, int h)
{
	graphics->FillRectangle(Brushes::Gray, x + 23 * h, y - 6 * h, 4 * h, 8 * h);
	graphics->DrawRectangle(pen, x + 23 * h, y - 6 *h, 4 * h, 8 * h);
}

void myTube::DrawSmoke(Graphics^ graphics, int h)
{
	graphics->FillEllipse(Brushes::DarkGray, x + 24 * h + (rand() % 5 + 1), y - 16 * h - (rand() % 5 + 1), 4 * h, 4 * h);
	graphics->FillEllipse(Brushes::Gray, x + 22 * h + (rand() % 5 + 1), y - 12 * h - (rand() % 5 + 1), 5 * h, 5 * h);
	graphics->FillEllipse(Brushes::DarkGray, x + 22 * h + (rand() % 5 + 1), y - 19 * h - (rand() % 5 + 1), 3 * h, 3 * h);
	graphics->FillEllipse(Brushes::Gray, x + 21 * h + (rand() % 5 + 1), y - 15*h - (rand() % 5 + 1), 3 * h, 3 * h);
}

void myTube::PlayTube(int a)
{
	x += a;
}

myLine::myLine(int _Xa, int _Ya, int _Xb, int _Yb)
{
	Xa = _Xa;
	Ya = _Ya;
	Xb = _Xb;
	Yb = _Yb;
}

void myLine::DrawLn(Pen^ pen, Graphics^ graphics)
{
	graphics->DrawLine(pen, Xa, Ya, Xb, Yb);
}

void myLine::PlayLine(int a)
{
	Xa += a; Xb += a;
}

Scep::Scep(int _x,int _y, int h)
{
	Xa = _x + 42 * h;
	Ya = _y + 11 * h;
	Xb = Xa + 4 * h;
	Yb = Ya;
}

Wheel::Wheel(int _x, int _y, int h)
{
	x = _x + 11*h;
	y = _y + 13*h;
	r = 6 * h;
}

void Wheel::DrawWheel(Pen^ pen, Graphics^ graphics, int h)
{
	p1 = Point(x + r / 2, y);
	p2 = Point(x + r / 2, y + r);
	p3 = Point(x, y + r / 2);
	p4 = Point(x + r, y + r / 2);
	p5 = Point(x + 3 * h + 3 * h * sqrt(2) / 2, y + 3 * h + 3 * h * sqrt(2) / 2);
	p6 = Point(x + 3 * h - 3 * h * sqrt(2) / 2, y + 3 * h - 3 * h * sqrt(2) / 2);
	p7 = Point(x + 3 * h + 3 * h * sqrt(2) / 2, y + 3 * h - 3 * h * sqrt(2) / 2);
	p8 = Point(x + 3 * h - 3 * h * sqrt(2) / 2, y + 3 * h + 3 * h * sqrt(2) / 2);

	graphics->DrawEllipse(pen, x, y, r, r);
	graphics->DrawLine(pen, p1, p2);
	graphics->DrawLine(pen, p3, p4);
	graphics->DrawLine(pen, p5, p6);
	graphics->DrawLine(pen, p7, p8);
}
void Wheel::PlayWheel(int a)
{
	x += a;
}

vagon::vagon(int _x, int _y, int h)
{
	x = _x;
	y = _y;
	window = new myWindow(_x, _y, h);
	door = new myDoor(_x, _y, h);
	scep = new Scep(_x, _y, h);
	wheel1 = new Wheel(_x, _y, h);
	wheel2 = new Wheel(_x + 17*h, _y, h);
}
void vagon::DrawVagon(Graphics^ graphics, Pen^ pen, Brush^ color, int h)
{
	graphics->FillRectangle(color, x, y, 42 * h, 14 * h);//корпус
	graphics->DrawRectangle(pen, x, y, 42 * h, 14 * h);
	window->DrawWin(Brushes::SkyBlue, graphics, pen, h);
	door->DrawDoor(pen, graphics, h);
	scep->DrawLn(pen, graphics);
	wheel1->DrawWheel(pen, graphics, h);
	wheel2->DrawWheel(pen, graphics, h);
}

void vagon::PlayVag(int a)
{
	window->PlayWin(a);
	wheel1->PlayWheel(a);
	wheel2->PlayWheel(a);
	scep->PlayLine(a);
	door->PlayDoor(a);
}

parovoz::parovoz(int _x, int _y, int h)
{
	x = _x;
	y = _y;
	door = new myDoor(x, y,h);
	wheel1 = new Wheel(x-2*h, y,h);
	wheel2 = new Wheel(x + 10*h, y, h);
	tube = new myTube(x, y);
}

void parovoz::DrawParovoz(Pen^ pen, Graphics^ graphics, Brush^ color , int h)
{
	graphics->FillRectangle(color, x, y+2*h, 33 * h, 12 * h);// корпус
	graphics->DrawRectangle(pen, x, y + 2 * h, 33 * h, 12 * h);
	graphics->FillRectangle(color, x, y - 10 * h, 13 * h, 13 * h); // кабина
	graphics->DrawLine(pen, x, y + 3*h, x, y - 10 * h);
	graphics->DrawLine(pen, x, y - 10 * h, x + 13*h, y - 10 * h);
	graphics->DrawLine(pen, x + 13 * h, y - 10 * h, x + 13 * h, y +2*h);
	door->DrawDoor(pen, graphics,h);
	tube->DrawTube(pen, graphics,h);
	wheel1->DrawWheel(pen, graphics,h);
	wheel2->DrawWheel(pen, graphics, h);
}

void parovoz::Playparovoz(int a,Graphics^ graphics, int h)
{
	wheel1->PlayWheel(a);
	wheel2->PlayWheel(a);
	tube->PlayTube(a);
	tube->DrawSmoke(graphics,h);
	door->PlayDoor(a);
}
