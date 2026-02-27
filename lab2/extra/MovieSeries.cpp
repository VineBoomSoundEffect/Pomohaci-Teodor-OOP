#include <iostream>
#include "Movie.h"
#include "MovieSeries.h"
#include "funcs.h"
#include <string.h>

void MovieSeries::init(){
    this->count = 0;
}
void MovieSeries::add(Movie *m){
    movie_list[count] = m;
    count++;
}
void MovieSeries::print(){
    for(int i=0;i<this->count;i++) {
        std::cout << "name: " << movie_list[i]->get_name() << " " <<
                     "year: " << movie_list[i]->get_year() << " " <<
                     "score: " << movie_list[i]->get_score() << " " <<
                     "length: " << movie_list[i]->get_length() << " " <<
                     "passed years: " << movie_list[i]->get_passed_years() << "\n";
    }
}
void MovieSeries::sort(){
    int max;
    Movie *aux;
    for (int i=0;i<this->count-1;i++) {
        max = i;
            for (int j=i+1;j<this->count;j++){
            if (movie_compare_passed_years(*this->movie_list[max], *this->movie_list[j]) == -1) {
                max = j;
            }
        }
        aux = this->movie_list[i];
        this->movie_list[i] = this->movie_list[max];
        this->movie_list[max] = aux;
    }
}
