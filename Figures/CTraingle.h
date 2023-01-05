#ifndef CTRAINGLE_H
#define CTRAINGLE_H

#include "CFigure.h"

class CTraingle : public CFigure
{
private:
	Point top;
	Point leftCorner;
	Point rightCorner;
public:
	CTraingle(Point,Point,Point , GfxInfo );
	CTraingle();
	virtual void DrawMe(GUI* pOut) const;
	void Save(ofstream& OutFile);
	virtual void Load(ifstream& file);
};

#endif