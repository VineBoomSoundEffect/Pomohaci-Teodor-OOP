#include "Movie.h"
#include "funcs.h"
#include <string.h>

int movie_compare_name(Movie m1, Movie m2) {
    char *x1 = m1.get_name();
    char *x2 = m2.get_name();
    return strcmp(x1, x2);
}
int movie_compare_year(Movie m1, Movie m2) {
    int x1 = m1.get_year();
    int x2 = m2.get_year();
    if(x1 > x2) return 1;
    if(x1 < x2) return -1;
    return 0;
}
int movie_compare_score(Movie m1, Movie m2) {
    double x1 = m1.get_score();
    double x2 = m2.get_score();
    if(x1 > x2) return 1;
    if(x1 < x2) return -1;
    return 0;
}
int movie_compare_length(Movie m1, Movie m2) {
    double x1 = m1.get_length();
    double x2 = m2.get_length();
    if(x1 > x2) return 1;
    if(x1 < x2) return -1;
    return 0;
}
int movie_compare_passed_years(Movie m1, Movie m2) {
    int x1 = m1.get_passed_years();
    int x2 = m2.get_passed_years();
    if(x1 > x2) return 1;
    if(x1 < x2) return -1;
    return 0;
}
