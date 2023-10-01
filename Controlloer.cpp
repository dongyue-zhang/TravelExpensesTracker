//
//  main.cpp
//  ProgrammingLanguageResearchProject
//
//  Created by Dongyue Zhang on 2023-09-18.
//  This is a simple commend line program that reads travelq.csv, gets 10 records from the spread sheet and prints it out

#include "TravelExpense.hpp"
#include <iostream>
#include <fstream> // * Use of an API library
#include <sstream>
#include <unistd.h>

// Helper method that prints out header and 10 records
void printTravelExpenses(std::fstream& fin);

// Main function of the program
int main(int argc, const char * argv[]) {
    // Set the wording directory to the project folder
    std::filesystem::current_path("/Users/dongyuezhang/Desktop/Computer_Programming/23F-L4/Programming Language Research Project/ProgrammingLanguageResearchProject/ProgrammingLanguageResearchProject/");
    std::fstream fin;

    try {
        // * File-IO reading from the dataset
        // Try opening the csv file
        fin.open("travelq.csv", std::ios::in);
        if (fin) {
            // If the file exist, print it out
            std::cout << "Programmed by Dongyue Zhang" << "\n";
            // * Use of a method
            printTravelExpenses(fin);
            // Exit with successful code
            return 0;
        } else {
            // Else throw a exceprion
            throw 404;
        }
    } catch (int err){
        // * Exception handling
        // Handle exception and exist with unsuccessful code
        std::cout << "File Not Found" << "\n";
        std::cout << "Error code: " << err << "\n";
        return -1;
    }
}


void printTravelExpenses(std::fstream& fin) {
    std::string line, word; // * Declaration of variables
    std::vector<std::string> words; // * Declatation of arrays
    std::vector<TravelExpense> travelExpenses;
    
    // * Loop structure
    // Get 10 records from the csv file
    for (int i = 0; i<11; i++){
        
        // Getting a line from input stream
        getline(fin, line);
        
        // Print out the header
        if (i == 0) {
            std::cout << line << "\n";
            std::cout << "------------------------------------------------------------------------------------------" << "\n";
        } else {
            
            std::stringstream s(line);
            words.clear();
            TravelExpense te;
            std::string finalWord, longWord;
            bool isLong = false;
            // Process individual words
            while (getline(s, word, ',')){
                
                if (word.empty()){
                    word = "NULL";
                }
                
                finalWord = word;
                
                if (word.starts_with('"')) {
                    isLong = true;
                }
                // If the word is a long word which is inclosed by qoute marks,
                // append them together
                if (isLong) {
                    longWord.append(word);
                    if (word.ends_with('"')) {
                        isLong = false;
                        finalWord = longWord;
                        longWord = "";
                    }
                }
                
                // If the word is not inclosed by qoute marks
                // push it to the array holding the whole row
                if (!isLong) {
                    words.push_back(finalWord);
                }
            }
            
            // set TravelExpense properties
            te.setRef_number(words[0]);
            te.setDisclosure_group(words[1]);
            te.setTitle_en(words[2]);
            te.setTitle_fr(words[3]);
            te.setName(words[4]);
            te.setPurpose_en(words[5]);
            te.setPurpose_fr(words[6]);
            te.setStart_date(words[7]);
            te.setEnd_date(words[8]);
            te.setDestination_en(words[9]);
            te.setDestination_fr(words[10]);
            if (words[11].compare("NULL") != 0) {
                te.setAirfare(std::stof(words[11]));
            } else {
                te.setAirfare(0);
            }
            if (words[12].compare("NULL") != 0) {
                te.setOther_transport(std::stof(words[12]));
            }
            
            te.setLodging(std::stof(words[13]));
            te.setMeals(std::stof(words[14]));
            if (words[15].compare("NULL") != 0) {
                te.setOther_expenses(std::stof(words[15]));
            }
            te.setTotal(std::stof(words[16]));
            te.setAdditional_comments_en(words[17]);
            te.setAdditional_comments_fr(words[18]);
            te.setOwner_org(words[19]);
            te.setOwner_org_title(words[20]);
            
            // Push to the array holding TravelExpense
            travelExpenses.push_back(te);
        }
           
    }
    // Loop though the array and print them out
    for (TravelExpense te : travelExpenses) {
        std::cout << te.toString() << "\n";
        std::cout << "------------------------------------------------------------------------------------------" << "\n";
    }
    
}

