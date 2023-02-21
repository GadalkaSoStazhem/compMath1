#include "cases.h"
#include "io.h"
#include "my_locale.h"

#include <iostream>

using namespace std;

int main() {

    locale out_comma (cout.getloc(), new my_locale);
    cout.imbue(out_comma);
    locale in_comma (cin.getloc(), new my_locale);
    cin.imbue(in_comma);

    io in;
    cases option;
    int method = in.get_method();
    switch (method) {
        case 1: {
            option.console_input();
            break;
        }
        case 2: {
            option.file_input();
            break;
        }
        case 3: {
            option.rand_input();
            break;
        }
        default:{
            cout << "Неверный параметр" << endl;
            break;
        }
    }
    return 0;
}
