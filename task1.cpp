#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <map>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include "locale.h"

using namespace std;

vector<string> split(const string& s);

int main(int argc, char* argv[])
{
    list <string> lines;
    vector <string> sublines; // используетс€ в разделении строки на слова
    string buff;
    ifstream txtFile;
    map <string, double> data; 

    // »тератор
    // it->first - дл€ keys
    // it->second - дл€ value

    map <string, double> :: iterator it;

    txtFile.open(argv[1]);

    while (getline(txtFile, buff)) // «аносим все строки в лист lines
    {
        lines.push_back(buff);
    }

    string Line="";
    
    for (string line : lines) {
        Line += line;
        Line += " ";
    }

        Line += "\n";

        for (int i = 0; Line[i] != '\n'; i++) {
            if (isalnum(Line[i]) == false) Line[i] = ' ';
        }

        sublines = split(Line); // ƒелим строку Line на слова в вектор sublines

        int S = size(sublines);

        for (string word : sublines) {
            data[word]++;
        }

        ofstream out;
        out.open(argv[2]);

        it = max_element(data.begin(), data.end());
        for (int i = 0; size(data)!=0; it = max_element(data.begin(), data.end()), i++) {  // выводим их
            out << it->first << "\t" << it->second << "\t" << it->second*100/S << '%' << endl;
            data.erase(it);
        }
        out.close();
        txtFile.close();
        cout << argv[1] << ' ' << argv[2];

    return 0;
}

vector<string> split(const string& s)
{
    vector<string> ret;
    istringstream iss(s);
    std::copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(ret));
    return ret;
}