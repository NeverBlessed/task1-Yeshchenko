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
    vector <string> sublines; // ������������ � ���������� ������ �� �����
    string buff;
    ifstream txtFile;
    map <string, double> data; 

    // ��������
    // it->first - ��� keys
    // it->second - ��� value

    map <string, double> :: iterator it;

    txtFile.open(argv[1]);

    while (getline(txtFile, buff)) // ������� ��� ������ � ���� lines
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

        sublines = split(Line); // ����� ������ Line �� ����� � ������ sublines

        int S = size(sublines);

        for (string word : sublines) {
            data[word]++;
        }

        ofstream out;
        out.open(argv[2]);

        it = max_element(data.begin(), data.end());
        for (int i = 0; size(data)!=0; it = max_element(data.begin(), data.end()), i++) {  // ������� ��
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