#include "ActionAddTriangle.h"
#include "..\Figures\CTraingle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionAddTriangle::ActionAddTriangle(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionAddTriangle::Execute()
{
	Point P1, P2,P3;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo SqrGfxInfo;
	SqrGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	SqrGfxInfo.FillClr = pGUI->getCrntFillColor();
	SqrGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Square data from the user

	pGUI->PrintMessage("New Triangle: Click at Top Point");
	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);

	pGUI->PrintMessage("New Triangle: Click at leftCorner point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);
	pGUI->PrintMessage("New Triangle: Click at rightCorner point");
	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P3.x, P3.y);

	pGUI->ClearStatusBar();



	//Step 3 - Create a Circle with the parameters read from the user
	CTraingle* T = new CTraingle(P1,P2,P3, SqrGfxInfo);

	//Step 4 - Add the Circle to the list of figures
	pManager->AddFigure(T);
}
