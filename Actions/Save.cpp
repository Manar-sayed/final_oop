#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "Save.h"
#include <fstream>

Save::Save(ApplicationManager* pApp, int _count) :Action(pApp) {
    fileName = "testFirst";
    count = _count;

}





void Save::Execute() {
    /* if (count == 0) {
         Readprameters();
     }
     else {
         fileName = "Savedefault";
     }*/
    GUI* pGUI = pManager->GetGUI();
    pGUI->PrintMessage("PLZ enter file name");
    fileName = pGUI->GetSrting();
    ofstream savedFile;
    savedFile.open(fileName + ".txt");


    bool flag = false;
    if (savedFile.fail()) {
        flag = true;
    }


    while (flag)
    {
        pGUI->PrintMessage("Please write a valid name then press ENTER");
        fileName = pGUI->GetSrting();
        savedFile.open(fileName + ".txt");
        if (savedFile.good())//true if i opened file
            flag = false;
    }


    savedFile << pManager->colorToString(UI.DrawColor) << "\t";
    savedFile << pManager->colorToString(UI.FillColor) << "\t";
    savedFile << pManager->colorToString(UI.BkGrndColor) << "\t";
    pGUI->ClearStatusBar();
    savedFile << count << "\n";
    pManager->SaveFile(savedFile);
    savedFile.close();
    pGUI->PrintMessage("Your data has been seved successfully...");


    pGUI->ClearStatusBar();


    pManager->SaveFile(savedFile);//------------


}