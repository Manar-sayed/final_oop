
#ifndef ACTION_SAVE
#define ACTION_SAVE

#include "Action.h"


class Save :public Action {
private:
	//make file name
	string fileName;
	int count;

public:
	Save(ApplicationManager* pApp, int count = 0);
	//void Readprameters();
	virtual void Execute();

};

#endif