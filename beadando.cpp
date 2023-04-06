#include <iostream>
#include <cstdlib>

template<typename T> T Newton (T num, T x0, int N)
{
    for (int i = 0; i < N; i++)
        {
            T xuj=num-((num*num-x0)/(2*num) ) ;
            num=xuj ;
            std::cout << num<< std::endl;
        }
return num;
}

int main(int argc, char *argv[])
{
    int N = atof(argv[3]);
    double x0 = atof(argv[2]);
    double num = atof(argv[1]);
    double b=Newton(num,x0,N);
    std::cout << b << std::endl;

    return 0;
}