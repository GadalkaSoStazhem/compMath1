//
// Created by Boss on 21.02.2023.
//

#ifndef COMPMATH1_MODIFICATIONS_H
#define COMPMATH1_MODIFICATIONS_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class modifications {
public:
    double in_str(string number){
        replace(number.begin(), number.end(), ',', '.');
        return atof(number.c_str());
    }

    void file_refactor (string number){
        fstream fs("/Users/tatiana/CLionProjects/compMath1/" + number + ".txt", fstream::in | fstream::out);
        if (fs.is_open()) {
            while (!fs.eof()) {
                if (fs.get() == ',') {
                    fs.seekp((fs.tellp() - static_cast<streampos>(1)));
                    fs.put('.');
                    fs.seekp(fs.tellp());
                }
            }
            fs.close();
        } else {
            cout << "Не удалось открыть файл" << endl;
        }
    }


    vector <string> split(const string str)
    {
        vector <string > numbers;
        stringstream ss(str);
        string number;
        while (getline(ss, number, ' ')) {
            numbers.push_back(number);
        }
        return numbers;
    }

private:
    vector <string> numbers;
};


#endif //COMPMATH1_MODIFICATIONS_H
