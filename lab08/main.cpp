#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // hsbr zr jpqr, jpe zivj o esdyrf, yjod mohhs lmre ejsy jr esd ysalomh snpiy
    ifstream fin("input.txt");
    string s;
    getline(fin, s);
    cout << s.find_first_of("z") << endl;
    return 0;
}
