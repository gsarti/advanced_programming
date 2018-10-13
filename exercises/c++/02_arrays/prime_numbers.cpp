/**
    Advanced Programming 2018-2019
    Purpose: Populate an array with the first n prime numbers between 0 and 100, 100 excluded.

    @author Gabriele Sarti
    @version 13/10/18
*/

const int SIZE = 100; //The upper bound for finding primes


int main()
{
    // Since even numbers cannot be primes, SIZE / 2 is the safest upper bound for the array size.
    // Li(x) and x/(log(x) - 1) do not provide a safe upper bound for the number on prime numbers up to SIZE.
    int * primes{new int[SIZE / 2]};
    int count{0};

    for (int  i{2}; i < SIZE; ++i)
    {
        bool  is_prime{true};
        for (int  j{2}; j < i; ++j)
        {
            if (i % j == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
        {
            primes[count++] = i;
        }
    }

    return 0;
}