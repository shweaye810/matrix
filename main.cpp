#include <algorithm>
#include <complex>
#include <iostream>

#include "matrix.hpp"

using namespace std;

int main()
{
    {
        cout << "____Testing int____\n";
        cout << "____Constructor____\n";
        Mat<int> mat1({3, 3}, 1);

        cout << mat1;
        cout << endl;

        cout << "____Testing operator[]____\n";
        Mat<int> mat2({3, 4});
        for (size_t i = 0; i < mat2.row(); ++i) {
            for (size_t j = 0; j < mat2.col(); ++j) {
                mat2[i][j] = (i + 1) * (j + 1);
            }
        }
        //mat2.fill(2);
        cout << mat2;
        cout << endl;
        cout << "____Testing operator+____\n";
        try {
            decltype(mat1) mat3 = mat1 + mat1;
            cout << mat3;
            cout << endl;
        }  catch (const exception &e) {
            cout << e.what() << endl;
        }
        cout << "____Testing operator*____\n";
        try {
            decltype(mat1) mat4;
            mat4 *= mat2;
            cout << mat4;
            cout << endl;
        } catch (const exception &e) {
            cout << e.what() << endl;
        }

        try {
            decltype(mat1) mat4 = mat1 * mat2;
            cout << mat4;
            cout << endl;
        } catch (const exception &e) {
            cout << e.what() << endl;
        }
        cout << "********************END********************\n";
    }
    {
        cout << "____Testing long____\n";
        cout << "____Constructor____\n";
        Mat<long> mat1({3, 3}, 1e7);

        cout << mat1;
        cout << endl;

        cout << "____Testing operator[]____\n";
        decltype(mat1) mat2({3, 4});
        for (size_t i = 0; i < mat2.row(); ++i) {
            for (size_t j = 0; j < mat2.col(); ++j) {
                mat2[i][j] = (i + 1) * (j + 1) * 1e7;
            }
        }
        //mat2.fill(2);
        cout << mat2;
        cout << endl;
        cout << "____Testing operator+____\n";
        try {
            decltype(mat1) mat3 = mat1 + mat1;
            cout << mat3;
            cout << endl;
        }  catch (const exception &e) {
            cout << e.what() << endl;
        }
        cout << "____Testing operator*____\n";
        try {
            decltype(mat1) mat4;
            mat4 *= mat2;
            cout << mat4;
            cout << endl;
        } catch (const exception &e) {
            cout << e.what() << endl;
        }

        try {
            decltype(mat1) mat4 = mat1 * mat2;
            cout << mat4;
            cout << endl;
        } catch (const exception &e) {
            cout << e.what() << endl;
        }
        cout << "********************END********************\n";
    }
    {
        cout << "____Testing double____\n";
        cout << "____Constructor____\n";
        Mat<double> mat1({3, 3}, 1e20);

        cout << mat1;
        cout << endl;

        cout << "____Testing operator[]____\n";
        decltype(mat1) mat2({3, 4});
        for (size_t i = 0; i < mat2.row(); ++i) {
            for (size_t j = 0; j < mat2.col(); ++j) {
                mat2[i][j] = (i + 1) * (j + 1) * 1e30;
            }
        }
        //mat2.fill(2);
        cout << mat2;
        cout << endl;
        cout << "____Testing operator+____\n";
        try {
            decltype(mat1) mat3 = mat1 + mat1;
            cout << mat3;
            cout << endl;
        }  catch (const exception &e) {
            cout << e.what() << endl;
        }
        cout << "____Testing operator*____\n";
        try {
            decltype(mat1) mat4;
            mat4 *= mat2;
            cout << mat4;
            cout << endl;
        } catch (const exception &e) {
            cout << e.what() << endl;
        }

        try {
            decltype(mat1) mat4 = mat1 * mat2;
            cout << mat4;
            cout << endl;
        } catch (const exception &e) {
            cout << e.what() << endl;
        }
        cout << "********************END********************\n";
    }
    {
        cout << "____Testing double____\n";
        cout << "____Constructor____\n";
        Mat<complex<double>> mat1({3, 3}, complex<double>(1e20, 1));

        cout << mat1;
        cout << endl;

        cout << "____Testing operator[]____\n";
        decltype(mat1) mat2({3, 4});
        for (size_t i = 0; i < mat2.row(); ++i) {
            for (size_t j = 0; j < mat2.col(); ++j) {
                mat2[i][j] = complex<double>((i + 1) * (j + 1) * 1e30, (i + 1) * (j + 1));
            }
        }
        //mat2.fill(2);
        cout << mat2;
        cout << endl;
        cout << "____Testing operator+____\n";
        try {
            decltype(mat1) mat3 = mat1 + mat1;
            cout << mat3;
            cout << endl;
        }  catch (const exception &e) {
            cout << e.what() << endl;
        }
        cout << "____Testing operator*____\n";
        try {
            decltype(mat1) mat4;
            mat4 *= mat2;
            cout << mat4;
            cout << endl;
        } catch (const exception &e) {
            cout << e.what() << endl;
        }

        try {
            decltype(mat1) mat4 = mat1 * mat2;
            cout << mat4;
            cout << endl;
        } catch (const exception &e) {
            cout << e.what() << endl;
        }
        cout << "********************END********************\n";
    }
    return 0;
}
