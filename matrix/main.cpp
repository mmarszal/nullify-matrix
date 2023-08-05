//
//  main.cpp
//  matrix
//
//  Created by Mark Marszal on 2023-08-05.
//

#include <iostream>
#include <array>
#include <vector>
#include <set>

template <typename T>
using Row3 = std::array<T, 3>;

template <typename T>
using Row4 = std::array<T, 4>;

template <typename T, std::size_t R, std::size_t C>
using Matrix = std::array<std::array<T, C>, R>;

template <typename T, std::size_t R, std::size_t C>
Matrix<T, R, C> parse(const Matrix<T, R, C> &m) {
    Matrix<T, R, C> n = m;
    std::set<std::size_t> rowClear;
    std::set<std::size_t> columnClear;
    
    std::size_t rowIndex = 0;
    
    for (const std::array<T, C> &row : m) {
        std::size_t colIndex = 0;
        
        for (int col : row) {
            if (col == 0) {
                rowClear.insert(rowIndex);
                columnClear.insert(colIndex);
            }
            
            ++colIndex;
        }
        
        ++rowIndex;
    }
    
    for (auto row : rowClear) {
        n[row].fill(0);
    }
    
    for (auto col : columnClear) {
        for (auto &row : n) {
            row[col] = 0;
        }
    }
    
    return n;
}

int main(int argc, const char * argv[]) {
    
    // 3 x 3 Matrix
    Matrix<int, 3, 3> m = {{
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    }};
    
    std::cout << "Original Matrix: \n\n";
    for (const Row3<int> &row : m) {
        std::cout << row[0] << " " << row[1] << " " << row[2] << std::endl;
    }
    std::cout <<  "\n";
    
    Matrix<int, 3, 3> n = parse(m);
    
    std::cout << "Modified Matrix:\n\n";
    for (const Row3<int> &row : n) {
        std::cout << row[0] << " " << row[1] << " " << row[2] << std::endl;
    }
    
    // 3 x 4 Matrix
    
    Matrix<int, 3, 4> m4 = {{
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    }};
    
    std::cout << "Original Matrix4: \n\n";
    for (const Row4<int> &row : m4) {
        std::cout << row[0] << " " << row[1] << " " << row[2] << " " << row[3] << std::endl;
    }
    std::cout <<  "\n";
    
    Matrix<int, 3, 4> n4 = parse(m4);
    
    std::cout << "Modified Matrix4:\n\n";
    for (const Row4<int> &row : n4) {
        std::cout << row[0] << " " << row[1] << " " << row[2] << " " << row[3] << std::endl;
    }
    
    return 0;
}
