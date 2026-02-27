#pragma once

class MovieSeries {
private:
    Movie *movie_list[16];
    int count;
public:
    void init();
    void add(Movie *m);
    void print();
    void sort();
};
