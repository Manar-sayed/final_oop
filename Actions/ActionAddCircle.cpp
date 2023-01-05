
#include "..\Figures\CCircle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "ActionAddCircle.h"

ActionAddCircle::ActionAddCircle(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddCircle::Execute()
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


	//Step 1 - Read Square data from the user

	pGUI->PrintMessage("New Circle: Click at Center");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Circle: Click at second point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	pGUI->ClearStatusBar();


	//Step 2 - prepare Circle data
	//User has entered two points P1&P2
	//2.1- Identify the center of circle
	Point center;
	center.x = P1.x < P2.x ? P1.x : P2.x;
	center.y = P1.y < P2.y ? P1.y : P2.y;

	//2.2- Calcuate radius
	//int radius = sqrt(pow((P2.x-P1.x),2)+pow((P2.y-P1.y),2));
	int radius = sqrt(((P2.x - P1.x) * (P2.x - P1.x)) + ((P2.y - P1.y) * (P2.y - P1.y)));


	//Step 3 - Create a Circle with the parameters read from the user
	CCircle* C = new CCircle(center, radius, SqrGfxInfo);

	//Step 4 - Add the Circle to the list of figures
	pManager->AddFigure(C);
}
