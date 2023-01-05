/*#include "Load.h"
#include"Action.h"
#include <fstream>
#include "../Figures/CCircle.h"
#include "../Figures/CHexagon.h"
#include "../Figures/CSquare.h"
#include "../Figures/CTraingle.h"
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"
#include <iostream>


ActionLoad::ActionLoad(ApplicationManager* pApp) :Action(pApp) {}
/*void ActionLoad::Execute()
{
    int r, g, b;
    int figuerCount=0;
    ifstream outPut;
    string figName;
    int flag=0;
    CFigure* cF;
    GUI* gu = pManager->GetGUI();
    gu->PrintMessage("enter the file to load..");
    FileName = gu->GetSrting();
    outPut.open(FileName + ".txt");

    if (outPut.fail()) {
        gu->PrintMessage("fail!");
        return;
    }
    gu->ClearDrawArea();
    pManager->deleteALLFig();

    //to load colors from save
    outPut >> r >> g >> b;
    color drawClr(r, g, b);
    outPut >> r >> g >> b;
    color FillClr(r, g, b);

    outPut >> r >> g >> b;
    color bkgclr(r, g, b);

    while (figuerCount)
    {
        outPut >> figuerCount;
        outPut >> figName;

        if (figName == "circle")
        {
            cF = new CCircle();
            cout << "Elipse" << endl;
        }
        else if (figName == "Square") {
            cF = new CSquare();
            cout << "Square" << endl;
        }
        else if (figName == "Triangle")
        {
            cF = new CTraingle();
            cout << "Triangle" << endl;
        }
        else if (figName == "Hexagon") {
            cF = new CHexagon();
            cout << "Hexagon" << endl;
        }

        cF->Load(outPut);
        pManager->AddFigure(cF);






        outPut >> figuerCount;
        outPut >> figName;
        cout << figName;

        if (figName == "circle") {
            cF = new CCircle();
        }
        // cF->Load(outPut);
        pManager->UpdateInterface();
        pManager->AddFigure(cF);
    }
}


void ActionLoad::Execute()
{
	int r, g, b;
	ifstream File;
	bool flag = false;
	string figName, drawclr, fillclr;
	int figcount=0;
	CFigure* fig;
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("please write the file name -->");
	FileName = pGUI->GetSrting();


	File.open(FileName + ".txt");


	if (File.fail())
	{
		pGUI->PrintMessage("invalid name");
		return;
	}
	pGUI->ClearDrawArea();
	pManager->deleteALLFig();

	File >> r >> g >> b;
	color drawClr(r, g, b);
	File >> r >> g >> b;
	color FillClr(r, g, b);

	File >> r >> g >> b;
	color bkgclr(r, g, b);
	File >> figcount;

	while (figcount)
	{
		cout << figcount;
		File >> figName;
		if (figName == "circle")
		{
			fig = new CCircle();
			cout << "circle" << endl;
		}
		else if (figName == "Square") {
			fig = new CSquare();
			cout << "Square" << endl;
		}
		else if (figName == "Triangle")
		{
			fig = new CTraingle();
			cout << "Triangle" << endl;
		}
		else if (figName == "Hexagon") {
			fig = new CHexagon();
			cout << "Hexagon" << endl;
		}

        fig->Load(File);
		pManager->AddFigure(fig);

		figcount--;
	}
	pManager->UpdateInterface();    //draw the figure list
	pGUI->PrintMessage("File loaded successfully...^_^");
	pGUI->ClearStatusBar();
}*/

#include "Load.h"
#include"..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

#include "..\Figures\CHexagon.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CTraingle.h"
#include<fstream>
#include <iostream>



ActionLoad::ActionLoad(ApplicationManager* pApp) : Action(pApp)
{
}


void ActionLoad::Execute()
{
	int r, g, b;
	ifstream File;
	bool flag = false;
	string figName, drawclr, fillclr;
	int figcount;
	CFigure* fig;
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("please write the file name -->");
	FileName = pGUI->GetSrting();


	File.open(FileName + ".txt");


	if (File.fail())
	{
		pGUI->PrintMessage("invalid name");
		return;
	}
	pGUI->ClearDrawArea();
	//pManager->deleteALLFig();

	File >> r >> g >> b;
	color drawClr(r, g, b);
	File >> r >> g >> b;
	color FillClr(r, g, b);

	File >> r >> g >> b;
	color bkgclr(r, g, b);
	File >> figcount;

	while (figcount)
	{
		cout << figcount;
		File >> figName;

	   if (figName == "Square") {
			fig = new CSquare();
			cout << "Square" << endl;
		}
		else if (figName == "Traingle")
		{
			fig = new CTraingle();
			cout << "Traingle" << endl;
		}
		else if (figName == "Hexagon") {
			fig = new CHexagon();
			cout << "Hexagon" << endl;
		}

	   fig->Load(File);
		pManager->AddFigure(fig);

		figcount--;
	}
	pManager->UpdateInterface();    //draw the figure list
	pGUI->PrintMessage("File loaded successfully...^_^");
	pGUI->ClearStatusBar();
}