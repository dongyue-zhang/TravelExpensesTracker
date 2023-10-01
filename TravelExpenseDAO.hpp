//
//  TravelExpenseDAO.hpp
//  ProgrammingLanguageResearchProject
//
//  Created by Dongyue Zhang on 2023-09-27.
//

#ifndef TravelExpenseDAO_hpp
#define TravelExpenseDAO_hpp

#include <stdio.h>
#include "TravelExpense.hpp"

int readFromDataset(const int& recordNum, std::vector<TravelExpense>& travelExpenses);
void resistToFile(std::vector<TravelExpense>& travelExpenses);
void create(TravelExpense& te, std::vector<TravelExpense>& travelExpenses);
int edit(TravelExpense& te, std::vector<TravelExpense>& travelExpenses);
int del(TravelExpense& te, std::vector<TravelExpense>& travelExpenses);

#endif /* TravelExpenseDAO_hpp */
