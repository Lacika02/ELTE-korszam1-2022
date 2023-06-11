#include <cstdlib>
#include <iostream>
#include <chrono>
#include <random>
// #include<gsl/gsl_rng.h>

class Timer
{
private:
    std::chrono::high_resolution_clock::time_point start_time;
    std::chrono::high_resolution_clock::time_point stop_time;

public:
    void start()
    {
        start_time = std::chrono::high_resolution_clock::now();
    }

    void stop()
    {
        stop_time = std::chrono::high_resolution_clock::now();
    }

    double measure()
    {
        using namespace std::chrono;
        return duration_cast<nanoseconds>(stop_time - start_time).count() / 1.0;
    }
};

template <typename T>
class Random
{
private:
    T generator;

public:
    Random()
        : generator(std::chrono::high_resolution_clock::now().time_since_epoch().count())
    {
    }

    int generate_integer(int begin, int end)
    {
        return std::uniform_int_distribution<int>(begin, end - 1)(generator);
    }
   
};

int main()
{
    constexpr int n = 300000000;
    Random<std::minstd_rand> mr;
    Random<std::mt19937> mt;
    Random<std::mt19937_64> mt64;
    Timer t;
        t.start();
        for (int i = 0; i < n; ++i)
        {
            /* static_cast<volatile void> */ (std::rand() % 10);
        }
        t.stop();
        std::cout << "rand  pici határban     " << t.measure() / n << " ns per rand" << std::endl;

        t.start();
        for (int i = 0; i < n; ++i)
        {
            /* static_cast<volatile void> */ (mr.generate_integer(0, 10));
        }
        t.stop();
        std::cout << "minstd   pici határban      " << t.measure() / n << " ns per rand" << std::endl;

        t.start();
        for (int i = 0; i < n; ++i)
        {
            /* static_cast<volatile void> */ (mt.generate_integer(0, 10));
        }
        t.stop();
        std::cout << "mersenne  pici határban     " << t.measure() / n << " ns per rand" << std::endl;

        t.start();
        for (int i = 0; i < n; ++i)
        {
            /* static_cast<volatile void> */ (mt64.generate_integer(0, 10));
        }
        t.stop();
        std::cout << "mersenne 64  pici határban " << t.measure() / n << " ns per rand" << std::endl;
  
// nagyobb range-ben



   t.start();
        for (int i = 0; i < n; ++i)
        {
            /* static_cast<volatile void> */ (std::rand() % 100000);
        }
        t.stop();
        std::cout << "rand  nagy határban      " << t.measure() / n << " ns per rand" << std::endl;

        t.start();
        for (int i = 0; i < n; ++i)
        {
            /* static_cast<volatile void> */ (mr.generate_integer(0, 100000));
        }
        t.stop();
        std::cout << " minstd   nagy határban       " << t.measure() / n << " ns per rand" << std::endl;

        t.start();
        for (int i = 0; i < n; ++i)
        {
            /* static_cast<volatile void> */ (mt.generate_integer(0, 100000));
        }
        t.stop();
        std::cout << "mersenne   nagy számokkal     " << t.measure() / n << " ns per rand" << std::endl;

        t.start();
        for (int i = 0; i < n; ++i)
        {
            /* static_cast<volatile void> */ (mt64.generate_integer(0, 100000));
        }
        t.stop();
        std::cout << "mersenne 64  nagy számokkal   " << t.measure() / n << " ns per rand" << std::endl;


// pici range eloszlás 
std::cout << " 100-ig random számok:" <<std::endl;
  std::cout << " \n rand():  \n  " <<std::endl;
for (int i = 0; i < 10; ++i)
        {
             std::cout <<"  "<<(std::rand() % 100);
        }

   std::cout << " \n minstd_rand-:    " <<std::endl;
for (int i = 0; i < 10; ++i)
        {
             std::cout << "  "<<(mr.generate_integer(0, 100));

        }
std::cout << " \n mersenne:    " <<std::endl;
for (int i = 0; i < 10; ++i)
        {
             std::cout << "  "<<(mt.generate_integer(0, 100));
        
        }
std::cout << " \n mersenne 64:    "<<std::endl;        
for (int i = 0; i < 10; ++i)
        {
             std::cout <<"  "<<(mt64.generate_integer(0, 100));
        }
std::cout << " \nkis számoknál én azt tapasztaltam, hogy a rand() a leggyorsabb és randomabb is \n" <<std::endl;



std::cout << " százezerig random számok:" <<std::endl;

std::cout << " \n rand():  \n  " <<std::endl;
for (int i = 0; i < 10; ++i)
        {
             std::cout <<"  "<<(std::rand() % 100000);
        }

   std::cout << " \n minstd_rand-:    " <<std::endl;
for (int i = 0; i < 10; ++i)
        {
             std::cout << "  "<<(mr.generate_integer(0, 100000));

        }
std::cout << " \n mersenne:    " <<std::endl;
for (int i = 0; i < 10; ++i)
        {
             std::cout << "  "<<(mt.generate_integer(0, 100000));
        
        }
std::cout << " \n mersenne 64:    "<<std::endl;        
for (int i = 0; i < 10; ++i)
        {
             std::cout <<"  "<<(mt64.generate_integer(0, 100000));
};
std::cout << " \n itt már a rand() sokszor ugyanabban az intervallumban mozog, és szerintem a mersennék lettek a legjobbak. \n" <<std::endl;

};
