#pragma once
#include <iostream>
#include <math.h>
#include "cstdlib"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;

class myRectangle 
{
private:

public:
	int x;
	int y;

	myRectangle() {};
	myRectangle(int _x,int _y);

    void myRectangle::Play(int a);

	~myRectangle() {};
};


class myWindow : public myRectangle
{
public:
	myWindow() {};
	myWindow(int _x,int _y, int h);

	void myWindow::DrawWin(Brush^ _br, Graphics^ graphics, Pen^ pen, int h);
	void myWindow::PlayWin(int a);

	~myWindow() {};
};

class myDoor : public myRectangle
{
public:
	myDoor() {};
	myDoor(int _x,int _y, int h);
	void DrawDoor(Pen^ pen, Graphics^ graphics, int h);
	void PlayDoor(int a);

	~myDoor() {};
};

class myTube : public myRectangle
{
public:
	myTube() {};
	myTube(int _x, int _y);

	void myTube::DrawSmoke(Graphics^ graphics, int h);
	void myTube::DrawTube(Pen^ pen, Graphics^ graphics, int h);
	void myTube::PlayTube(int a);

	~myTube() {};
};

class Wheel : public myRectangle
{
public:
	int r;
	Point p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16;

	Wheel() {};
	Wheel(int _Xa, int _Ya, int h);

	void Wheel::DrawWheel(Pen^ pen, Graphics^ graphics, int h);
	void Wheel::PlayWheel(int a);

	~Wheel() {};
};

class myLine
{
public:
	int Xa;
	int Ya;
	int Xb;
	int Yb;

	myLine() {};
	myLine(int _Xa, int _Ya, int _Xb, int _Yb);

	void myLine::DrawLn(Pen^ pen, Graphics^ graphics);
	void myLine::PlayLine(int a);

	~myLine() {};
};

class Scep : public myLine
{
public:
	Scep() {};
	Scep(int _x, int _y, int h);

	~Scep() {};
};

class vagon : public myRectangle
{
private:
	myWindow* window;
	myDoor* door;
	Scep* scep;
	Wheel* wheel1;
	Wheel* wheel2;
public:

	vagon() {};
	vagon(int x,int y, int h);
	void vagon::DrawVagon(Graphics^ graphics, Pen^ pen, Brush^ color, int h);
	void vagon::PlayVag(int a);

	~vagon() {};
};

class parovoz : public myRectangle
{
private:
	myDoor* door;
	Wheel* wheel1;
	Wheel* wheel2;
	myTube* tube;
public:
	parovoz() {};
	parovoz(int _x, int _y, int h);

	void parovoz::DrawParovoz(Pen^ pen, Graphics^ graphics, Brush^ color, int h);
	void parovoz::Playparovoz(int a, Graphics^ graphics, int h);
};
