#include <iostream>
#include <cstdlib>
//vector.h
//class vector
//{
    template<typename T>
    struct Vector2
            {
                T x, y;

                Vector2& operator+=( Vector2 const& v)
                {
                    x += v.x ; y += v.y;
                return*this;
                }

                 Vector2& operator-=( Vector2 const& v)
                {
                    x -= v.x ; y -= v.y;
                return*this;
                }

                 Vector2& operator*=( T const& lambda)
                {
                    x=x*lambda ; y= y*lambda;
                return*this;
                }
            };
    
    template<typename T> 
    Vector2<T> operator+( Vector2<T> const& a, Vector2<T> const& b)
    {
        return Vector2<T> { a.x+ b.x, a.y+ b.y};
    }
    template<typename T> 
    Vector2<T> operator-( Vector2<T> const& a, Vector2<T> const& b)
    {
        return Vector2<T> { a.x- b.x, a.y- b.y};
    }
    template<typename T> 
    Vector2<T> operator*( Vector2<T> const& a,  T const& b)
    {
        return Vector2<T> { a.x*b, a.y*b};
    }
    template<typename T> 
    Vector2<T> operator*( T const& b,Vector2<T>  const& a )
    {
        return Vector2<T> { b*a.x, b*a.y};
    }
    template<typename T> 
    Vector2<T> operator/( Vector2<T> const& a,  T const& b)
    {
        return Vector2<T> { a.x/b, a.y/b};
    }
    template<typename T> 
    Vector2<T> lenght(Vector2<T> const& a)
    {
        return(a.x*a.x+a.y*a.y);
    }
//};

int main(int argc, char *argv[])
{
    //vector v;
    double v2 = atof(argv[2]);
    double v1= atof(argv[1]);
    double u1=atof(argv[3]);
    double u2=atof(argv[4]);
    double lambda=atof(argv[5]);
    Vector2<double> v={v1,v2};
    std::cout<<v.x<<" "<<v.y<<" az első vektorom\n";
    Vector2<double> u={u1,u2};
    std::cout<<u.x<<" "<<u.y<<" a másik vektorom\n";
    auto w = v + u ;
    std::cout<<w.x<<" "<<w.y<<" az összegük\n";
    auto g = v - u ;
    std::cout<<g.x<<" "<<g.y<<" a különbségük\n";
    std::cout<<lambda<<" a lambdám \n";
    auto sajt=v*lambda;
    std::cout<<sajt.x<<" "<<sajt.y<<" vektor 1 szorzat balról\n";
    auto kecske=lambda*v;
    std::cout<<sajt.x<<" "<<sajt.y<<" vektor 1 szorzat jobbról\n";
    auto kecskesajt=v/lambda;
    std::cout<<kecskesajt.x<<" "<<kecskesajt.y<<" vektor 1 osztás jobbról\n";
    //double hossz=lenght(v);
    //std::cout<<hossz<<"a hosszam";
    for (int i = 0; i < 3; i++)
    {
        v+=u;
    }
    std::cout<<v.x<<" "<<v.y<<" az első vektoromból ez lett\n";
    for (int i = 0; i < 3; i++)
    {
        v-=u;
    }
    std::cout<<v.x<<" "<<v.y<<" az első vektoromból ez lett, ha ugyananyiszor kivonom ugyanazt\n";
    for (int i = 0; i < 3; i++)
    {
        v*=lambda;
    }
    std::cout<<v.x<<" "<<v.y<<" az első vektoromból ez lett, ha 3-szor megszorzom lambdával\n";
    return 0;
}