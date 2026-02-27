#include "Movie.h"
#include <string.h>

void Movie::set_name(const char *name){
    strcpy(this->name, name);
}
void Movie::set_year(int year){
    this->year = year;
}
void Movie::set_score(double score){
    this->score = score;
}
void Movie::set_length(int length){
    this->length = length;
}
char *Movie::get_name(){
    return this->name;
}
int Movie::get_year(){
    return this->year;
}
double Movie::get_score(){
    return this->score;
}
int Movie::get_length(){
    return this->length;
}
// TODO
int Movie::get_passed_years(){
    return 2026-this->year;
}
