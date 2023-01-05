#include "ActionAddHexagon.h"
#include "..\Figures\CHexagon.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"


ActionAddHexagon::ActionAddHexagon(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddHexagon::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Hexagon data from the user

	pGUI->PrintMessage("New Hexagon: Click at first point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Hexagon: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->ClearStatusBar();


	//Step 2 - prepare hexagon data
	//User has entered two points P1&P2
	//2.1- Identify the Top left corner of the hexagon
	Point topLeftCorner;
	topLeftCorner.x = P1.x < P2.x ? P1.x : P2.x;
	topLeftCorner.y = P1.y < P2.y ? P1.y : P2.y;

	//2.2- Calcuate hexagon side legnth
	//The hexagon side length would be the differance distance between the two points x axis coordinates
	//The hexagon height would be the differance distance between the two points y axis coordinates
	int SideLength = abs(P1.x - P2.x);
	int height= abs(P1.y - P2.y);


	//Step 3 - Create a Hexagon with the parameters read from the user
	CHexagon* H = new CHexagon(topLeftCorner, SideLength,height, SqrGfxInfo);

	//Step 4 - Add the Hexagon to the list of figures
	pManager->AddFigure(H);
}
