#include <iostream>
#include <chrono>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <algorithm>

class Timer
{
public:
    using clock_t = std::chrono::steady_clock;
    using time_point_t = clock_t::time_point;

    Timer() : m_begin(clock_t::now()) {}

    ~Timer()
    {
        auto end = clock_t::now();

        std::cout << "micro : " << std::chrono::duration_cast <std::chrono::microseconds> (end - m_begin).count() << std::endl;
    }

private:
    time_point_t m_begin;
};

int main()
{
    const int N = 1e5;
    std::array < int, N > arr;
    std::vector < int > vec;
    std::deque < int > deq;
    std::list < int > lst;
    std::forward_list < int > flst;

    for (auto i = 0; i < N; ++i)
    {
        arr[i] = N - i;
    }

    vec.reserve(N);

    for (auto i = 0; i < N; ++i)
    {
        vec.push_back(N - i);
        deq.push_back(N - i);
        lst.push_back(N - i);
    }

    for (auto i = 0; i < N; ++i)
    {
        flst.push_front(i);
    }

    std::cout << "Array:\nstd::sort - ";
    {
        Timer t;

        std::sort(std::begin(arr), std::end(arr));
    }

    std::cout << ".sort() - forbidden" << std::endl;

    std::cout << std::endl;

    std::cout << "Vector:\nstd::sort - ";

    {
        Timer t;

        std::sort(std::begin(vec), std::end(vec));
    }

    std::cout << ".sort() - forbidden" << std::endl;

    std::cout << std::endl;

    std::cout << "Deque:\nstd::sort - ";

    {
        Timer t;

        std::sort(std::begin(deq), std::end(deq));
    }

    std::cout << ".sort() - forbidden" << std::endl;

    std::cout << std::endl;

    std::cout << "List:\nstd::sort - forbidden " << std::endl;

    std::cout << ".sort() - ";

    {
        Timer t;

        lst.sort();
    }

    std::cout << std::endl;

    std::cout << "Forward list:\nstd::sort - forbidden " << std::endl;

    std::cout << ".sort() - ";

    {
        Timer t;

        flst.sort();
    }

    /*
   Container    Microseconds (approx)
  ______________________________________
    Array               213250.0
    Vector              227000.0
    Forward
     List               144750.0
    Deque               938703.0
    List                157750.0
*/

    // the most effective way to sort some kind of an array is to use the "flist.sort()" method

    system("pause");

    return EXIT_SUCCESS;
}
