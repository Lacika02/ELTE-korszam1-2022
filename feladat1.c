#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

double sqrt_newton(double num, double x0,int N){
    for (int i = 0; i <N ; i++)
    {
        double xuj=num-((num*num-x0)/(2*num) ) ;
        num=xuj ;
    }
    return num;
}

int main(int argc, char const *argv[])
{
    const int N = atof(argv[3]);
    const double x0 = atof(argv[2]);
    const double num = atof(argv[1]);
    double sat=sqrt_newton(num,x0,N);
    printf("%f",sat);
    return 0;
}