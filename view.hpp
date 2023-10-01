//
//  view.hpp
//  ProgrammingLanguageResearchProject
//
//  Created by Dongyue Zhang on 2023-09-27.
//

#ifndef view_hpp
#define view_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include "TravelExpense.hpp"

enum menuItem{RELOAD=1,PRESIST=2,DISPLAY=3,CREATE=4,EDIT=5,DELETE=6};

void displayMenu(int& menuItem, TravelExpense& travelExpense);
void getInput(std::string promp, std::string& var);
void getInfo(TravelExpense& te);
void displayRecords(std::vector<TravelExpense>& travelExpense);
void del(TravelExpense& travelExpense);
void delimiter(std::string msg, char c);
#endif /* view_hpp */
