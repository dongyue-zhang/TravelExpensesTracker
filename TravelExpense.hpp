//
//  TravelExpense.hpp
//  ProgrammingLanguageResearchProject
//
//  Created by Dongyue Zhang on 2023-09-18.
//  Header file for Transfer Object class that maps to each row of travelq.csv

#ifndef TravelExpense_hpp
#define TravelExpense_hpp

#include <stdio.h>
#include <string>

class TravelExpense
{
private:
    std::string ref_number;
    std::string disclosure_group;
    std::string title_en;
    std::string title_fr;
    std::string name;
    std::string purpose_en;
    std::string purpose_fr;
    std::string start_date;
    std::string end_date;
    std::string destination_en;
    std::string destination_fr;
    float airfare;
    float other_transport;
    float lodging;
    float meals;
    float other_expenses;
    float total;
    std::string additional_comments_en;
    std::string additional_comments_fr;
    std::string owner_org;
    std::string owner_org_title;
    
public:
    void setRef_number(std::string r);
    std::string getRef_number();
    void setDisclosure_group(std::string d);
    std::string getDisclosure_group();
    void setTitle_en(std::string t);
    std::string getTitle_en();
    void setTitle_fr(std::string t);
    std::string getTitle_fr();
    void setName(std::string n);
    std::string getName();
    void setPurpose_en(std::string p);
    std::string getPurpose_en();
    void setPurpose_fr(std::string p);
    std::string getPurpose_fr();
    void setStart_date(std::string s);
    std::string getStart_date();
    void setEnd_date(std::string e);
    std::string getEnd_date();
    void setDestination_en(std::string d);
    std::string getDestination_en();
    void setDestination_fr (std::string d);
    std::string getDestination_fr();
    void setAirfare(float a);
    float getAirfare();
    void setOther_transport(float o);
    float getOther_transport();
    void setLodging(float l);
    float getLodging();
    void setMeals(float m);
    float getMeals();
    void setOther_expenses(float o);
    float getOther_expenses();
    void setTotal(float t);
    float getTotal();
    void setAdditional_comments_en(std::string a);
    std::string getAdditional_comments_en();
    void setAdditional_comments_fr(std::string a);
    std::string getAdditional_comments_fr();
    void setOwner_org(std::string o);
    std::string getOwner_org();
    void setOwner_org_title(std::string o);
    std::string getOwner_org_title();
    std::string toString();
};

#endif /* TravelExpense_hpp */
