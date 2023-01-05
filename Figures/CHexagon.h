
#ifndef CHEXAGON_H
#define CHEXAGON_H

#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point TopLeftCorner;
	int length;
	int height;
public:
	CHexagon(Point, int,int, GfxInfo FigureGfxInfo);
	CHexagon();
	virtual void DrawMe(GUI* pOut) const;
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
};

#endif