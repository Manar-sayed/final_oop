#include "CTraingle.h"
#include <string>
#include <fstream>
#include <iostream>



CTraingle::CTraingle(Point _P1, Point _P2, Point _P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo) {

	top = _P1;
	leftCorner = _P2;
	rightCorner = _P3;

}


CTraingle::CTraingle(){}

void CTraingle::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawTriangle(top, leftCorner, rightCorner, FigGfxInfo, Selected);

}
void CTraingle::Save(ofstream& OutFile)
{
	cout << "noooooon";
	OutFile << "\n" << "Traingle \t"
		<< ID
		<< "\t" << top.x
		<< "\t" << top.y
		<< "\t" << leftCorner.x
		<< "\t" << leftCorner.y
		<< "\t" << rightCorner.x
		<< "\t" << rightCorner.y
		<< ColorToString(this->FigGfxInfo.DrawClr);
	;
	if (!this->FigGfxInfo.isFilled) {
		cout << "fff";

		OutFile << "\t" << "Not_color_now!";

	}
	else {
		OutFile << "\t" << ColorToString(this->FigGfxInfo.FillClr);
	}
}

void CTraingle::Load(ifstream& Infile)
{
	string temp;
	Infile >> this->ID >> this->top.x >> this->top.y >> this->leftCorner.x >>
		this->leftCorner.y >>
		this->rightCorner.x >> 
		this->rightCorner.y;
	Infile >> temp;
	this->FigGfxInfo.DrawClr = StringToColor(temp);
	Infile >> temp;
	if (temp == "NON-FILLED") {
		this->FigGfxInfo.isFilled = false;
	}
	else
	{
		this->FigGfxInfo.FillClr = StringToColor(temp);
		this->FigGfxInfo.isFilled = true;
		cout << "fall";
	}
	this->Selected = false;
}
	
