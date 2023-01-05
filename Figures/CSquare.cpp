#include "CSquare.h"
#include <string>
#include <fstream>
#include <iostream>
CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
}
CSquare::CSquare(){
}
	

void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
	

}
void CSquare::Save(ofstream& OutFile)
{
	cout << "noooooon";
	OutFile << "\n" << "Square \t"
		<< ID
		<< "\t" << TopLeftCorner.x
		<< "\t" << TopLeftCorner.y
		<< "\t" << length
		<< "\t" 
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

void CSquare::Load(ifstream& Infile)
{
	string temp;
	Infile >> this->ID >> this->TopLeftCorner.x
		>> this->TopLeftCorner.y
		>> this->length;
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
