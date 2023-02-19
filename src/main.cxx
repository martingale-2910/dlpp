#include <valarray> // std::valarray
#include <cassert> // assert

// NUMERIC

// Row-oriented vectors and matrices
using vecd = std::valarray<double>;
using matd = std::valarray<vecd>;

matd transpose(matd const & m)
{
    std::size_t nrows = m.size();
    std::size_t ncols = m[0].size();
    matd mt(ncols);
    for (std::size_t i = 0; i < ncols; ++i)
    {
        mt[i] = vecd(nrows);
        for (std::size_t j = 0; j < ncols; ++j)
        {
            mt[i][j] = m[j][i];
        }
    }
    return mt;
}

/*
 * d = v1*v1
 * v1 - n dim row vector (n cols)
 * v1 - n dim col vector (n rows)
 * d - scalar
*/
double matmul(vecd const & v1, vecd const & v2)
{
    assert(v1.size() == v2.size());
    return (v1*v2).sum();
}

/* 
 * r = M*v
 * M - n x m dim matrix (n rows, m cols)
 * v - m dim col vector (m rows)
 * r - n dim col vector (n rows)
*/
vecd matmul(matd const & M, vecd const & v)
{
    assert(M[0].size() == v.size());
    std::size_t nrows = M.size();
    vecd res(nrows);
    for (std::size_t i  = 0; i < nrows; ++i)
    {
        res[i] = matmul(M[i], v);
    }
    return res;
}

/*
 * r = v*M
 * M - n x m dim matrix (n rows, m cols)
 * v - n dim row vector (n cols)
 * r - m dim row vector (m cols)
*/
vecd matmul(vecd const & v, matd const & M)
{
    assert(v.size() == M.size());
    std::size_t nrows = M.size();
    std::size_t ncols = v.size();
    vecd res(0.0, ncols);
    for (std::size_t i = 0; i < nrows; ++i)
    {
        res += v[i]*M[i]; 
    }
    return res;
}

/*
 * M3 = M1*M2
 * M1 - n x m dim matrix
 * M2 - m x n dim matrix
 * M3 - n x m dim matrix
*/
matd matmul(matd const & M1, matd const & M2)
{
    assert((M1.size() == M2[0].size()) && (M2.size() == (M1[0]).size()));
    std::size_t nrows = M1.size();
    matd res(nrows);
    for (std::size_t i = 0; i < nrows; ++i)
    {
        res[i] = matmul(M1[i], M2);
    }
    return res;
}

int main(int argc, char** argv)
{
    return 0;
}