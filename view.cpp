//
//  view.cpp
//  ProgrammingLanguageResearchProject
//
//  Created by Dongyue Zhang on 2023-09-27.
//

#include "view.hpp"
#include <iostream>
#include <string>

void displayMenu(int& menuItem, TravelExpense& te)
{
    std::string chose;
    
    while (menuItem == 0) {
        delimiter("", '-');
        std::cout << "Please choose a operation you want to perform" << "\n";
        std::cout << "1. Reload 100 Travel Expenses" << "\n";
        std::cout << "2. Save all Travel Expenses to a CSV file" << "\n";
        std::cout << "3. Display all Travel Expenses" << "\n";
        std::cout << "4. Create a new Travel Expense" << "\n";
        std::cout << "5. Edit a Travel Expense" << "\n";
        std::cout << "6. Delete a Travel Expense" << std::endl;
        std::cin >> chose;
        
        if (isdigit(chose[0]))
        {
            switch (std::stoi(chose)) {
                case RELOAD:
                    menuItem = RELOAD;
                    break;
                case PRESIST:
                    menuItem = PRESIST;
                    break;
                case DISPLAY:
                    menuItem = DISPLAY;
                    break;
                case CREATE:
                    menuItem = CREATE;
                    getInfo(te);
                    break;
                case EDIT:
                    menuItem = EDIT;
                    getInfo(te);
                    break;
                case DELETE:
                    menuItem = DELETE;
                    del(te);
                    break;
                default:
                    std::cout << "Invalid number of chose! Please try again." << "\n";
                    break;
            }
        } else {
            std::cout << "Invalid chose! Please enter a number of menu." << "\n";
        }
    }
}
    
void getInfo(TravelExpense& te)
{
    std::string input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getInput("ref_number: ", input);
    te.setRef_number(input);
    
    getInput("disclosure_group: ", input);
    te.setDisclosure_group(input);
    
    getInput("title_en: ", input);
    te.setTitle_en(input);
    
    getInput("title_fr: ", input);
    te.setTitle_fr(input);
    
    getInput("name: ", input);
    te.setName(input);
    
    getInput("purpose_en: ", input);
    te.setPurpose_en(input);
    
    getInput("purpose_fr: ", input);
    te.setPurpose_fr(input);
    
    getInput("start_date: ", input);
    te.setStart_date(input);
    
    getInput("end_date: ", input);
    te.setEnd_date(input);
    
    getInput("destination_en: ", input);
    te.setDestination_en(input);
    
    getInput("destination_fr: ", input);
    te.setDestination_fr(input);

    getInput("airfare: ", input);
    te.setAirfare(std::stof(input));

    getInput("other_transport: ", input);
    te.setOther_transport(std::stof(input));

    getInput("lodging: ", input);
    te.setLodging(std::stof(input));
    
    getInput("meals: ", input);
    te.setMeals(std::stof(input));
    
    getInput("other_expenses: ", input);
    te.setOther_expenses(std::stof(input));
    
    getInput("total: ", input);
    te.setTotal(std::stof(input));
    
    getInput("additional_comments_en: ", input);
    te.setAdditional_comments_en(input);
    
    getInput("additional_comments_fr: ", input);
    te.setAdditional_comments_fr(input);

    getInput("owner_org: ", input);
    te.setOwner_org(input);
    
    getInput("owner_org_title: ", input);
    te.setOwner_org_title(input);
    
}

void displayRecords(std::vector<TravelExpense>& travelExpenses)
{
    delimiter("Printing TravelExpenses", '-');
    for (TravelExpense te : travelExpenses) {
        std::cout << te.toString() << "\n";
        delimiter("", '-');
    }
}
void del(TravelExpense& te)
{
    std::string recordToDelete;
    std::cout << "Please enter the ref_number of the record you want to delete: ";
    std::cin >> recordToDelete;
    te.setRef_number(recordToDelete);
}

void getInput(std::string promp, std::string& var)
{
    std::cout << promp;
    std::getline(std::cin, var);
}

void delimiter(std::string msg, char c)
{
    int len = 100;
    int clen = static_cast<int>(len - msg.length());
    for (int i=0; i < clen/2; i++)
    {
        std::cout << c;
    }
    std::cout << msg;
    for (int i=0; i < clen/2; i++)
    {
        std::cout << c;
    }
    std::cout << std::endl;
}

