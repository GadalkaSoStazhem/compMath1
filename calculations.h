//
// Created by Boss on 20.02.2023.
//

#ifndef COMPMATH1_CALCULATIONS_H
#define COMPMATH1_CALCULATIONS_H

#include "io.h"

class calculations {
public:
    double tr_determinant(double **tr_matrix, int size){
        for (int i = 0; i < size; i++){
            det *= tr_matrix[i][i];
        }
        return det;
    }

    void get_triangle(double **matrix, int size){
        //search of maximum in a column
        for (int i = 0; i < size; i++){
            int index = 0;
            double max = 0;
            for (int j = i; j < size; j++){
                if (abs(matrix[j][i]) > max){
                    max = abs(matrix[j][i]);
                    index = j;
                }
            }

            //swap rows if needed
            for (int j = i; j < size + 1; j++){
                double tmp = matrix[i][j];
                matrix[i][j] = matrix[index][j];
                matrix[index][j] = tmp;
            }
            if (matrix[i][i] == 0){
                cout << "Система не является совместной и определенной" << endl;
                return;
            }
            //rationing of the row with the max value
            for (int k = size; k >= i; k--)
                if (matrix[i][i] != 0)
                    matrix[i][k] = matrix[i][k] / matrix[i][i];

            //rationing of other rows
            for (int k = i + 1; k < size; k++)
                for (int j = size; j >= i; j--)
                    matrix[k][j] -= matrix[k][i] * matrix[i][j];
        }
        cout << "Матрица ступенчатого вида" << endl;
        out.print_matrix(matrix, size);
    }

    double *get_answers(double **matrix, int size){
        answers = new double[size];
        //x_i = (b_i - sum(a_ij * x_j) / a_ii;
        for (int i = size - 1; i >= 0; i--){
            double sum = 0;
            for (int j = i + 1; j < size; j++){
                sum += matrix[i][j] * answers[j];
            }
            answers[i] = (matrix[i][size] - sum) / matrix[i][i];
        }

        return answers;
    }

    double *differences(double **matrix, int size, double *answers){
        diffs = new double [size];
        for (int i = 0; i < size; i++){
            double sum = 0;
            for (int j = 0; j < size; j++){
                sum += matrix[i][j] * answers[j];
            }
            diffs[i] = abs(sum - matrix[i][size]);
        }
        return diffs;
    }
    void def_solution(double det, double **matrix, int size){
        //th. Kronecker–Capelli, rang (A) != rang (A|B)
        if (det != 0 && det == det) {
            double *answers = get_answers(matrix, size);
            cout << "Корни системы: " << endl;
            out.print_array(answers, size);
            double *diffs = differences(matrix, size, answers);
            cout << "Столбец неувязок: " << endl;
            out.print_array(diffs, size);
            delete [] answers;
            delete [] diffs;
        }
        else
            cout << "Система не является совместной и определенной" << endl;
    }

private:
    double det = 1;
    double *answers;
    double *diffs;
    io out;

};


#endif //COMPMATH1_CALCULATIONS_H
