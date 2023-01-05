
#ifndef ACTION_LOAD_H
#define ACTION_LOAD_H
#include "Action.h"

class ActionLoad : public Action
{
private:
	string FileName;
	//int FigCnt;
	int FigCount;
public:
	ActionLoad(ApplicationManager* pApp);
	virtual void Execute();

};

#endif