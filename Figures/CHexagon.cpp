#include "CHexagon.h"
#include <string>
#include <fstream>
#include <iostream>
CHexagon::CHexagon(Point _P1, int _lenght, int _height, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo) {

	TopLeftCorner = _P1;
	length = _lenght;
	height = _height;

}

CHexagon::CHexagon() {

}


void CHexagon::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawPolygon(TopLeftCorner, length, height, FigGfxInfo, Selected);


}

void CHexagon::Save(ofstream& OutFile)
{
	cout << "noooooon";
	OutFile << "\n" << "Hexagon \t"
		<< ID
		<< "\t" << TopLeftCorner.x
		<< "\t" << TopLeftCorner.y
		<< "\t" << length
		<< "\t" << height<<"\t"
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

void CHexagon::Load(ifstream& Infile)
{
	string temp;
	Infile >> this->ID >> this->TopLeftCorner.x 
		>> this->TopLeftCorner.y >>
		
		this->TopLeftCorner.y >>
		 this->length >>
		this->height;
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
