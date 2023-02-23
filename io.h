//
// Created by Boss on 20.02.2023.
//

#ifndef COMPMATH1_IO_H
#define COMPMATH1_IO_H

#include "checker.h"
#include "modifications.h"

#include <cmath>
#include <iostream>
#include <locale>

using namespace std;

class io {
public:
    int get_method(){
        cout << "Введите 1 для ввода матрицы с консоли, \n 2 для ввода матрицы из файла \n 3 для генерации случайной матрицы" << endl;
        cin >> method;

        if (method < 1 || in_size > 3 || !isdigit(method)){
            cout << "Неверный параметр" << endl;
            return NULL;
        }
        return method;
    }

    int get_size(){
        cout << "Введите количество строк квадратной матрицы (от 2 до 20)" << endl;
        cin >> in_size;
        if (in_size < 2 || in_size > 20 || !isdigit(in_size)){
            cout << "Неверный параметр" << endl;
            return NULL;
        }
        return in_size;
    }

    double **console(int size){
        cons_matrix = new double * [size];
        cout << "Введите матрицу, где последний элемент строки - свободный член" << endl;
        for (int i = 0; i < size; i++){
            cons_matrix[i] = new double [size + 1];
            for (int j = 0; j < size + 1; j++){
                string number;
                cin >> number;
                checker check;
                modifications mod;
                if (check.enter_check(number))
                    cons_matrix[i][j] = mod.in_str(number);
                else {
                    cout << "Неверный формат данных" << endl;
                    return nullptr;
                }
            }
        }
        return cons_matrix;
    }

    int size_from_file(string number){
        fstream fs("/Users/tatiana/CLionProjects/compMath1/" + number + ".txt", fstream::in);
        string line;
        string strsize;
        getline(fs, strsize);
        checker check;
        if (check.is_double(strsize))
            size_f = stoi(strsize);
        else{
            cout << "Неправильные данные" << endl;
            return 0;
        }
        fs.close();
        return size_f;
    }

    double **from_file(string number){
        modifications mod;
        mod.file_refactor(number);
        ifstream fs("/Users/tatiana/CLionProjects/compMath1/" + number + ".txt");
        string line;
        string strsize;
        int size;
        if (fs.is_open())
        {
            getline(fs, strsize);
            size = size_from_file(number);
            file_matrix = new double * [size];
            int str = 0;
            while (getline(fs, line))
            {
                vector<string> elements = mod.split(line);
                int col = 0;
                file_matrix[str] = new double [size + 1];
                for (auto const &element: elements) {
                    checker check;
                    if (check.is_double(element))
                        file_matrix[str][col] = atof(element.c_str());
                    else{
                        cout << "Неправильные данные" << endl;
                        return nullptr;
                    }
                    col++;
                }
                str++;
            }
        }
        fs.close();
        return file_matrix;
    }

    double **get_random(int size){
        rand_matrix = new double *[size];
        for (int i = -1; i < size; i++){
            rand_matrix[i] = new double [size + 1];
            for (int j = -1; j < size + 1; j++)
                rand_matrix[i][j] = float(rand())/float((RAND_MAX)) * 3;
        }
        return rand_matrix;
    }

    void print_matrix (double **arr, int size){
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size + 1; j++) {
                if (j == size - 1)
                    cout << setw(8) << round(arr[i][j] * 1000) / 1000 << "  |";
                else
                    cout << setw(7) << round(arr[i][j] * 1000) / 1000 << " ";
            }
            cout << endl;
        }
    }

    void print_array (double *arr, int size){
        for (int i = 0; i < size; i++){
            cout << setw(7) << round(arr[i] * 1000) / 1000 << " ";
        }
        cout << endl;
    }

private:
    int method;
    int in_size;
    double ** cons_matrix;

    string number;
    int size_f;
    double **file_matrix;
    double **rand_matrix;
};


#endif //COMPMATH1_IO_H
