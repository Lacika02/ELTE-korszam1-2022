#include <iostream>
#include <cstdlib>
template<typename T> T sq (T x) { return x*x; }
int main(int argc, char *argv[])
{
    double b = sq(atof(argv[1]));
    
    std::cout << b << std::endl;

    return 0;
}
 