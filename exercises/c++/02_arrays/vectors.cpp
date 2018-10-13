/**
    Advanced Programming 2018-2019
    Purpose: Implement eratosthenes.cpp and prime_numbers.cpp using std::vector

    @author Gabriele Sarti
    @version 13/10/18
*/

#include <vector>
#include <cmath>
#include <iostream>

/**
    Initializes an array of prime numbers from 0 to N using vectors.

    @param size the outer upper bound for the prime numbers.
    @return an std::vector containing the prime numbers.
*/
std::vector<int> prime_numbers_vector(int size)
{
    std::vector<int> primes;

    for (int  i{2}; i < size; ++i)
    {
        bool  is_prime{true};
        for (int  j{2}; j < i; j++)
        {
            if (i % j == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
        {
            primes.push_back(i);
        }
    }
    return primes;
}

/**
    Perform the Sieve of Eratosthenes algorithm using vectors.

    @param size the inner upper bound for the algorithm.
    @return nothing.
*/
void eratosthenes_vector(int size)
{
    std::vector<bool> primes(size, true);
    primes[0] = false; //1 is not a prime number

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
}

int main()
{
    int n = 100;
    std::cout << "Prime numbers with vectors:" << std::endl;
    std::vector<int> primes = prime_numbers_vector(n);
    for (int i{1}; i < primes.size(); i++)
    {
            std::cout << primes[i] << std::endl;
    }
    std::cout << "Sieve of Eratosthenes with vectors:" << std::endl;
    eratosthenes_vector(n);
    return 0;
}