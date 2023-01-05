#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point TopLeftCorner;	
	int length;
public:
	CSquare(Point , int, GfxInfo FigureGfxInfo );
	CSquare();
	virtual void DrawMe(GUI* pOut) const;
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
};

#endif