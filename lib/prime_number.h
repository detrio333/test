#pragma once
#include <array>

constexpr bool primeTest(const unsigned int p, const unsigned int i)
{
    if (i == 1)
        return true;
    return p % i != 0 && primeTest(p, i - 1);
}

constexpr bool isPrime(const unsigned int number)
{
    return primeTest(number, number - 1);
}

constexpr unsigned int nextPrime(const unsigned int number)
{
    if (isPrime(number + 1))
        return number + 1;
    else
        return nextPrime(number + 1);
}

template<unsigned int N>
struct PrimeNumberArray
{
    constexpr PrimeNumberArray() : array_()
    {
        array_[0] = 1;
        for (auto i = 1; i < N; i++)
            array_[i] = nextPrime(array_[i - 1]);
    }
    std::array<unsigned int, N> array_;
};

template<unsigned int N>
constexpr std::array<unsigned int, N> generatePrimeNumberArray()
{
    PrimeNumberArray<N> primeNumberArray;
    return primeNumberArray.array_;
}

static_assert(nextPrime(1) == 2);
static_assert(nextPrime(2) == 3);
static_assert(nextPrime(3) == 5);
static_assert(nextPrime(4) == 5);
static_assert(nextPrime(5) == 7);
static_assert(isPrime(13), "13 is prime");
static_assert(!isPrime(12), "12 is not prime");
static_assert(generatePrimeNumberArray<5>().size() == 5);
static_assert(generatePrimeNumberArray<5>().at(0) == 1);
static_assert(generatePrimeNumberArray<5>().at(1) == 2);
static_assert(generatePrimeNumberArray<5>().at(2) == 3);
static_assert(generatePrimeNumberArray<5>().at(3) == 5);
static_assert(generatePrimeNumberArray<5>().at(4) == 7);