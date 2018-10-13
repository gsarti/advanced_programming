/**
    Advanced Programming 2018-2019
    Purpose: Implement the Sieve of Eratosthenes in C++ (upper bound included)

    @author Gabriele Sarti
    @version 13/10/18
*/

#include <iostream>
#include <cmath>


int main()
{
    int size{0};

    std::cout << "insert number: ";
    std::cin >> size;

    bool * primes{new bool[size]};
    std::fill(primes + 1, primes + size, true); // 1 is not a prime number

    for (int i{2}; i <= std::sqrt(size); i++) //sqrt(size) is the largest divisor for size
    {
        if (primes[i - 1]) //compute only for prime values
        {
            for (int j{i * i}; j <= size; j+=i)
            {
                primes[j - 1] = false; // Multiples of i are not primes by definition
            }
        }
    }

    for (int i{1}; i <= size; i++)
    {
        if (primes[i - 1])
            std::cout << i << std::endl;
    }
    
    return 0;
}