#pragma once
#include <vector>

struct Matrix {
    std::vector<int> data;
    unsigned width, height;
};



template<class RandomIterator>
void transpose(RandomIterator first, RandomIterator last, int m)
{
    const int mn1 = (last - first - 1);
    const int n   = (last - first) / m;
    std::vector<bool> visited(last - first);
    RandomIterator cycle = first;
    while (++cycle != last) {
        if (visited[cycle - first])
            continue;
        int a = cycle - first;
        do  {
            a = a == mn1 ? mn1 : (n * a) % mn1;
            std::swap(*(first + a), *cycle);
            visited[a] = true;
        } while ((first + a) != cycle);
    }
}


/**
  * Функция транспонирования матрицы.
  * 
  * @param matrix - входная матрица для транспонирования.
  * @return - возвращается транспонированная матрица
  *
  */
Matrix TransposeMatrix(Matrix matrix) {
    transpose(matrix.data.begin(),matrix.data.end(),matrix.width);
    std::swap(matrix.height,matrix.width);
    return matrix;
}
