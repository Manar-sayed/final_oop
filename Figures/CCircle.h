
#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point center;
	int radius;
public:
	CCircle(Point, int, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	virtual void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	CCircle(void);
};


#endif