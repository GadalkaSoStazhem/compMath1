//
// Created by Boss on 21.02.2023.
//

#ifndef COMPMATH1_CASES_H
#define COMPMATH1_CASES_H

#include "calculations.h"
#include "io.h"

class cases {
public:
    void console_input(){
        int size = in.get_size();
        if (size == NULL)
            return;
        double **arr = in.console(size);
        calc.get_triangle(arr, size);
        double det = calc.tr_determinant(arr, size);
        cout <<"Определитель треугольной матрицы: " << round(det * 100) / 100 << endl;
        calc.def_solution(det, arr, size);
        delete [] arr;
    }

    void file_input(){
        string number;
        cout << "Введите номер файла от 1 до 9" << endl;
        cin >> number;
        if (stoi(number) < 1 || stoi(number) > 9){
            cout << "Неправильный номер файла" << endl;
            exit(0);
        }
        double **arr = in.from_file(number);
        int size = in.size_from_file(number);
        cout << "Матрица СЛАУ из файла" << endl;
        in.print_matrix(arr, size);
        calc.get_triangle(arr, size);
        double det = calc.tr_determinant(arr, size);
        cout <<"Определитель треугольной матрицы: " << round(det * 1000) / 1000 << endl;
        calc.def_solution(det, arr, size);
        delete [] arr;
    }

    void rand_input(){
        int size = in.get_size();
        if (size == NULL)
            return;
        double **arr = in.get_random(size);
        cout << "Матрица СЛАУ со случайными коэффициентами" << endl;
        in.print_matrix(arr, size);
        calc.get_triangle(arr, size);
        double det = calc.tr_determinant(arr, size);
        cout <<"Определитель треугольной матрицы: " <<round(det * 1000) / 1000 << endl;
        calc.def_solution(det, arr, size);
        delete [] arr;
    }
private:
    calculations calc;
    io in;
};


#endif //COMPMATH1_CASES_H
