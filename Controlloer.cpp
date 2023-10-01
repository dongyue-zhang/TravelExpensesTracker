//
//  main.cpp
//  ProgrammingLanguageResearchProject
//
//  Created by Dongyue Zhang on 2023-09-18.
//  This is a simple commend line program that reads travelq.csv, gets 10 records from the spread sheet and prints it out

#include "view.hpp"
#include "TravelExpense.hpp"
#include "TravelExpenseDAO.hpp"

#include <iostream>
#include <fstream> // * Use of an API library
#include <sstream>
#include <unistd.h>

// Helper method that prints out header and 10 records
void printTravelExpenses(std::fstream& fin);
void dispatch(int& menuItem, const int& NUM_RECORDS, std::vector<TravelExpense>& travelExpenses, TravelExpense& te);

// Main function of the program
int main(int argc, const char * argv[]) {
    // Set the wording directory to the project folder
    std::filesystem::current_path("/Users/dongyuezhang/Desktop/Computer_Programming/23F-L4/Programming Language Research Project/ProgrammingLanguageResearchProject/ProgrammingLanguageResearchProject/");
    
    int const NUM_RECORDS = 100;
    std::vector<TravelExpense> travelExpenses;
    TravelExpense te;
    int menuItem;
    bool quit = false;
    
    delimiter("Programmed by Dongyue Zhang", '*');
    delimiter("Welcome to TravelExpenseTracker", '-');
    readFromDataset(NUM_RECORDS, travelExpenses);
    
    while (quit == false)
    {
        displayMenu(menuItem,te);
        dispatch(menuItem, NUM_RECORDS, travelExpenses, te);
        std::string choose;
        std::cout << "Do you want to perform another operation (Y/N): ";
        std::cin >> choose;
        if (choose.compare("N") == 0 || choose.compare("n") == 0)
        {
            quit = true;
            delimiter("Thank you for using TravelExpenseTracker!", '-');
        }
        menuItem = 0;
        
    }
    
}

void dispatch(int& menuItem, const int& NUM_RECORDS, std::vector<TravelExpense>& travelExpenses, TravelExpense& te)
{
    switch(menuItem)
    {
        case RELOAD:
            readFromDataset(NUM_RECORDS, travelExpenses);
            delimiter("Reloaded dataset", '-');
            break;
        case PRESIST:
            resistToFile(travelExpenses);
            delimiter("Records presisted to presistedRecord.txt", '-');
            break;
        case DISPLAY:
            displayRecords(travelExpenses);
            break;
        case CREATE:
            create(te, travelExpenses);
            delimiter("Record " + te.getRef_number() + " created.", '-');
            break;
        case EDIT:
            if (edit(te, travelExpenses)){
                delimiter("Record " + te.getRef_number() + " edited.", '-');
            } else {
                delimiter("Failed to edit: not record found by " + te.getRef_number() , '-');
            }
            break;
        case DELETE:
            if (del(te, travelExpenses)) {
                delimiter("Record " + te.getRef_number() + " deleted.", '-');
            } else {
                delimiter("Failed to delete: not record found by " + te.getRef_number() , '-');
            }
            break;
    }
}


