#include "CCircle.h"
#include <string>
#include <fstream>
#include <iostream>

CCircle::CCircle(Point P, int _radius, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P;
	radius = _radius;
	ID++;
}

CCircle::CCircle(){}

void CCircle::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawCircle(center, radius, FigGfxInfo, Selected);

}

void CCircle::Save(ofstream& OutFile)
{
	cout << "noooooon";
	OutFile << "\n" << "circle \t" << ID
		<< "\t" << center.x << "\t" << center.y << "\t" << radius << "\n"
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
void CCircle::Load(ifstream& Infile)
{
	string temp;
	Infile >> this->ID >> this->center.x
		>> this->center.y >>
		this->radius ;
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

