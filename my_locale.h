//
// Created by Boss on 21.02.2023.
//

#ifndef COMPMATH1_MY_LOCALE_H
#define COMPMATH1_MY_LOCALE_H

#include <locale>

using namespace std;

class my_locale : public numpunct<char> {
public:
    char do_decimal_point() const {
        return ',';
    }
};


#endif //COMPMATH1_MY_LOCALE_H
