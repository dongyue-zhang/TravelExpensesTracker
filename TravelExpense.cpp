//
//  TravelExpense.cpp
//  ProgrammingLanguageResearchProject
//
//  Created by Dongyue Zhang on 2023-09-18.
//  Impelementation of TravelExpense.hpp

#include "TravelExpense.hpp"
#include <string>

void TravelExpense::setRef_number(std::string r) {
    ref_number = r;
}
std::string TravelExpense::getRef_number() {
    return ref_number;
}
void TravelExpense::setDisclosure_group(std::string d) {
    disclosure_group = d;
}

std::string TravelExpense::getDisclosure_group() {
    return disclosure_group;
}
void TravelExpense::setTitle_en(std::string t) {
    title_en = t;
}
std::string TravelExpense::getTitle_en(){
    return title_en;
}

void TravelExpense::setTitle_fr(std::string t) {
    title_fr = t;
}
std::string TravelExpense::getTitle_fr(){
    return title_fr;
}
void TravelExpense::setName(std::string n) {
    name = n;
}
std::string TravelExpense::getName() {
    return name;
}
void TravelExpense::setPurpose_en(std::string p) {
    purpose_en = p;
}
std::string TravelExpense::getPurpose_en(){
    return purpose_en;
}
void TravelExpense::setPurpose_fr(std::string p) {
    purpose_fr = p;
}
std::string TravelExpense::getPurpose_fr() {
    return purpose_fr;
}
void TravelExpense::setStart_date(std::string s) {
    start_date = s;
}
std::string TravelExpense::getStart_date() {
    return start_date;
}
void TravelExpense::setEnd_date(std::string e) {
    end_date = e;
}
std::string TravelExpense::getEnd_date(){
    return end_date;
}
void TravelExpense::setDestination_en(std::string d) {
    destination_en = d;
}
std::string TravelExpense::getDestination_en(){
    return destination_en;
}
void TravelExpense::setDestination_fr (std::string d) {
    destination_fr = d;
}
std::string TravelExpense::getDestination_fr(){
    return destination_fr;
}
void TravelExpense::setAirfare(float a) {
    airfare = a;
}
float TravelExpense::getAirfare(){
    return airfare;
}
void TravelExpense::setOther_transport(float o) {
    other_transport = o;
}
float TravelExpense::getOther_transport() {
    return other_transport;
}
void TravelExpense::setLodging(float l){
    lodging = l;
}
float TravelExpense::getLodging() {
    return lodging;
}
void TravelExpense::setMeals(float m) {
    meals = m;
}
float TravelExpense::getMeals(){
    return meals;
}
void TravelExpense::setOther_expenses(float o) {
    other_expenses = o;
}
float TravelExpense::getOther_expenses(){
    return other_expenses;
}
void TravelExpense::setTotal(float t) {
    total = t;
}
float TravelExpense::getTotal(){
    return total;
}
void TravelExpense::setAdditional_comments_en(std::string a) {
    additional_comments_en = a;
}
std::string TravelExpense::getAdditional_comments_en(){
    return additional_comments_en;
}
void TravelExpense::setAdditional_comments_fr(std::string a) {
    additional_comments_fr = a;
}
std::string TravelExpense::getAdditional_comments_fr(){
    return additional_comments_fr;
}
void TravelExpense::setOwner_org(std::string o) {
    owner_org = o;
}
std::string TravelExpense::getOwner_org(){
    return owner_org;
}
void TravelExpense::setOwner_org_title(std::string o) {
    owner_org_title = o;
}
std::string TravelExpense::getOwner_org_title(){
    return owner_org_title;
}
std::string TravelExpense::toString() {
    std::string s;
    s.append(getRef_number() + ", ");
    s.append(getDisclosure_group() + ", ");
    s.append(getTitle_en() + ", ");
    s.append(getTitle_fr() + ", ");
    s.append(getName() + ", ");
    s.append(getPurpose_en() + ", ");
    s.append(getPurpose_fr() + ", ");
    s.append(getStart_date() + ", ");
    s.append(getEnd_date() + ", ");
    s.append(getDestination_en() + ", ");
    s.append(getDestination_fr() + ", ");
    s.append(std::to_string(getAirfare()) + ", ");
    s.append(std::to_string(getOther_transport()) + ", ");
    s.append(std::to_string(getLodging()) + ", ");
    s.append(std::to_string(getMeals()) + ", ");
    s.append(std::to_string(getOther_expenses()) + ", ");
    s.append(getAdditional_comments_en() + ", ");
    s.append(getAdditional_comments_fr() + ", ");
    s.append(getOwner_org() + ", ");
    s.append(getOwner_org_title());
    return s;
}



