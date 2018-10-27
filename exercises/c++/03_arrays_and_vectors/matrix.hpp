#ifndef MATRIX_H__
#define MATRIX_H__

#include <array>
#include <iostream>

template<int size>
class Matrix 
{

    private:
        std::array<double, size> m_matrix;
        int m_rows;
        int m_columns;

    public:
        Matrix(const int rows, const int columns)
        {
            m_rows = rows;
            m_columns = columns;

            double init_seed = 0.0;

            for(int i = 0; i < m_rows; i++)
            {
                for(int j = 0; j < m_columns; j++)
                {
                    int pos_val = j + i * m_columns;
                    m_matrix[pos_val] = init_seed++;
                }
            }
        }

        const int rows() const { return m_rows; }
        const int columns() const {return m_columns; }

        /**
        Performs the transposition of the matrix

        @param none
        @return nothing, the object is changed consequently
        */
        void transpose()
        {
            std::array<double, size> t_matrix;
            
            for(int j = 0; j < m_rows; j++)
            {
                for(int i = 0; i < m_columns; i++)
                {
                    t_matrix[j * m_rows + i] = m_matrix[i * m_columns + j];
                }
            }
	
            m_matrix = t_matrix;
            
            int tmp = m_rows;
            m_rows = m_columns;
            m_columns = tmp;
        }

        const double& operator[](const std::size_t i) const { return m_matrix[i]; }
};

template <int size>
std::ostream& operator<<(std::ostream& os, const Matrix<size>& m)
{
    for(int i = 0; i < m.rows(); i++)
    {
        for(int j = 0; j < m.columns(); j++)
        {
            int pos_val = j + i * m.columns();
            os << m[pos_val] << " ";
        }
        
        os << std::endl;
    }
    os << std::endl << std::endl;
    return os;
}

#endif //MATRIX_H