//
// Created by Boss on 21.02.2023.
//

#ifndef COMPMATH1_CHECKER_H
#define COMPMATH1_CHECKER_H

#include <regex>
#include <string>

using namespace std;

class checker {
public:
    bool enter_check (string line){
        regex r_comma (R"([+-]?([0-9]+([,][0-9]*)?|[,][0-9]+))");
        return regex_match(line, r_comma);
    }

    bool is_double(string line){
        regex r_point (R"([+-]?([0-9]+([.][0-9]*)?|[.][0-9]+))");
        return regex_match(line, r_point);
    }
};


#endif //COMPMATH1_CHECKER_H
