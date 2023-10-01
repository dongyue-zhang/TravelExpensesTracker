//
//  TravelExpenseDAO.cpp
//  ProgrammingLanguageResearchProject
//
//  Created by Dongyue Zhang on 2023-09-27.
//
#include "view.hpp"
#include "TravelExpenseDAO.hpp"
#include <iostream>
#include <fstream> // * Use of an API library
#include <sstream>


int readFromDataset(const int& recordNum, std::vector<TravelExpense>& travelExpenses)
{
    std::string line, word; // * Declaration of variables
    std::vector<std::string> words; // * Declatation of arrays
    std::fstream fin;
    travelExpenses.clear();
    
    try
    {
        fin.open("travelq.csv", std::ios::in);
        if (fin) {
            
            // * Loop structure
            // Get 10 records from the csv file
            for (int i = 0; i<recordNum+1; i++){
                
                // Getting a line from input stream
                getline(fin, line);
                
                // Print out the header
                if (i == 0) {
                    //std::cout << line << "\n";
                    //std::cout << "------------------------------------------------------------------------------------------" << "\n";
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
                    if (words[13].compare("NULL") != 0) {
                        te.setLodging(std::stof(words[13]));
                    }
                    if (words[14].compare("NULL") != 0) {
                        te.setMeals(std::stof(words[14]));
                    }
                    
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
            return 1;
            
        }
            else{
                throw 404;
                
            }
            
        }catch (int err){
            std::cout << "File Not Found" << "\n";
            std::cout << "Error code: " << err << "\n";
            return -1;
        }
}

void resistToFile(std::vector<TravelExpense>& travelExpenses)
{
    std::ofstream file("presistedRecord.txt");
    for (int i = 0; i < travelExpenses.size(); i++)
    {
        file << travelExpenses.at(i).getRef_number() << ", ";
        file << travelExpenses.at(i).getDisclosure_group() << ", ";
        file << travelExpenses.at(i).getTitle_en() << ", ";
        file << travelExpenses.at(i).getTitle_fr() << ", ";
        file << travelExpenses.at(i).getName() << ", ";
        file << travelExpenses.at(i).getPurpose_en() << ", ";
        file << travelExpenses.at(i).getPurpose_fr() << ", ";
        file << travelExpenses.at(i).getStart_date() << ", ";
        file << travelExpenses.at(i).getEnd_date() << ", ";
        file << travelExpenses.at(i).getDestination_en() << ", ";
        file << travelExpenses.at(i).getDestination_fr() << ", ";
        file << travelExpenses.at(i).getAirfare() << ", ";
        file << travelExpenses.at(i).getOther_transport() << ", ";
        file << travelExpenses.at(i).getLodging() << ", ";
        file << travelExpenses.at(i).getMeals() << ", ";
        file << travelExpenses.at(i).getOther_expenses() << ", ";
        file << travelExpenses.at(i).getTotal() << ", ";
        file << travelExpenses.at(i).getAdditional_comments_en() << ", ";
        file << travelExpenses.at(i).getAdditional_comments_fr() << ", ";
        file << travelExpenses.at(i).getOwner_org() << ", ";
        file << travelExpenses.at(i).getOwner_org_title() << "\n";
    }
    file.close();
}
    
void create(TravelExpense& te, std::vector<TravelExpense>& travelExpenses)
{
    travelExpenses.push_back(te);
}

int edit(TravelExpense& te, std::vector<TravelExpense>& travelExpenses)
{
    for (int i = 0; i < travelExpenses.size(); i++)
    {
        if (travelExpenses.at(i).getRef_number() == te.getRef_number())
        {
            travelExpenses.at(i) = te;
            return 1;
        }
        
    }
    return 0;
        
    
}
int del(TravelExpense& te, std::vector<TravelExpense>& travelExpenses)
{
    for (int i = 0; i < travelExpenses.size(); i++)
    {
        if (travelExpenses.at(i).getRef_number() == te.getRef_number())
        {
            travelExpenses.erase(travelExpenses.begin() + i);
            return 1;
        }
    }
    return 0;
        
}
