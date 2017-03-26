#include <cstdint>
#include <iostream>
#include <vector>
#include <stdexcept>

template<class T>
class Mat {
private:
    std::vector<std::vector<T>> mat;
    typedef std::vector<T> Container;
public:
    Mat() {};
    Mat(std::pair<std::size_t, std::size_t> p) : mat(p.first, std::vector<T>(p.second, 0)) {}
    Mat(std::pair<std::size_t, std::size_t> p, T val) : mat(p.first, std::vector<T>(p.second, val)) {}
    Mat(const Mat &o) : mat(o.mat) {}
    std::size_t row() const
    {
        return mat.size();
    }
    std::size_t col() const
    {
        return mat.empty() ? 0 : mat[0].size();
    }
    Container &operator[](std::size_t n)
    {
        return mat[n];
    }
    const Container &operator[](std::size_t n) const
    {
        return mat[n];
    }
    void fill(std::size_t n)
    {
        for (std::size_t i = 0; i < mat.size(); ++i) {
            for (std::size_t j = 0; j < mat[0].size(); ++j) {
                this->mat[i][j] = n;
            }
        }
    }
    Mat operator+(const Mat &o) const throw(std::invalid_argument, std::logic_error)
    {
        if (mat.empty()) {
            throw std::logic_error("Matrix is empty.\n");
        }
        Mat ret = o;
        if (this->col() != o.col() || this->row() != o.row()) {
            throw std::invalid_argument("Matrixes have different size.\n");
        } else {
            for (std::size_t i = 0; i < o.mat.size(); ++i) {
                for (std::size_t j = 0; j < o.mat[0].size(); ++j) {
                    ret.mat[i][j] = this->mat[i][j] + o.mat[i][j];
                }
            }
        }
        return ret;
    }
    Mat operator+=(const Mat &o)
    {
        *this = *this + o;
        return *this;
    }
    Mat operator*(const Mat &o) const throw(std::invalid_argument, std::logic_error)
    {
        if (mat.empty()) {
            throw std::logic_error("Matrix is empty.\n");
        }
        Mat ret({this->row(), o.col()});
        if (this->col() != o.row()) {
            throw std::invalid_argument("Nonconformant arguments, op1.col() != op2.row()");
        } else {
            for (std::size_t i = 0; i < this->row(); ++i) {
                for (std::size_t j = 0; j < o.col(); ++j) {
                    for (std::size_t k = 0; k < o.row(); ++k) {
                        ret.mat[i][j] += this->mat[i][k] * o.mat[k][j];
                    }
                }
            }
        }
        return ret;
    }
    Mat operator*=(const Mat &o)
    {
        *this = *this * o;
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &out, const Mat &o)
    {
        for (std::size_t i = 0; i < o.mat.size(); ++i) {
            for (std::size_t j = 0; j < o.mat[0].size(); ++j) {
                std::cout << o.mat[i][j] << ' ';
            }
            std::cout << '\n';
        }
        return out;
    }
};
