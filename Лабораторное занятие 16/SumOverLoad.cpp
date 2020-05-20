#include<iostream>

class Fraction
{
public:
    int numenator;
    int denumenator;

    void input_fract()
    {
        std::cout << "Input fraction" << std::endl;
        std::cin >> numenator >> denumenator;
    }

    void output_fract()
    {
        std::cout << numenator << "/" << denumenator << std::endl;
    }
};

Fraction sum(Fraction f1, Fraction f2)
{
    Fraction res;
    if(f1.denumenator != f2.denumenator)
    {
        res.denumenator = f1.denumenator * f2.denumenator;
        res.numenator = (f1.numenator * f2.denumenator) + (f2.numenator * f1.denumenator);
    }
    else
    {
        res.denumenator = f1.denumenator;
        res.numenator = f1.numenator + f2.numenator;
    }
    return res;
}

Fraction div(Fraction f1, Fraction f2)
{
    Fraction res;
    res.numenator = f1.numenator * f2.denumenator;
    res.denumenator = f1.denumenator * f2.numenator;
    return res;
}

Fraction prod(Fraction f1, Fraction f2)
{
    Fraction res;
    res.numenator = f1.numenator * f2.numenator;
    res.denumenator = f1.denumenator * f2.denumenator;
    return res;
}

Fraction my_abs(Fraction f1)
{
    f1.numenator = (f1.numenator < 0) ? f1.numenator * -1 : f1.numenator;
    f1.denumenator = (f1.denumenator < 0) ? f1.denumenator * -1 : f1.denumenator;
    return f1;
}

void eq(Fraction f1, Fraction f2)
{
    if((f1.numenator == f2.numenator) && (f1.denumenator == f2.denumenator))
        std::cout << "True\n";
    else
        std::cout << "False\n";
}

void gt(Fraction f1, Fraction f2)
{
    double res1, res2;
    res1 = f1.numenator / (double)f1.denumenator;
    res2 = f2.numenator / (double)f2.denumenator;
    if(res1 > res2)
        std::cout << "1 more\n";
    else if(res1 == res2)
        std::cout << "Equal\n";
    else
        std::cout << "2 more\n";
}

int main()
{
    Fraction f1;
    f1.input_fract();
    Fraction f2;
    f2.input_fract();
    std::cout << "Sum: \n";
    sum(f1, f2).output_fract();
    std::cout << "Div: \n";
    div(f1, f2).output_fract();
    std::cout << "Prod: \n";
    prod(f1, f2).output_fract();
    std::cout << "My_abs: \n";
    my_abs(f1).output_fract();
    std::cout << "Eq: \n";
    eq(f1, f2);
    std::cout << "Gt: \n";
    gt(f1, f2);
    return 0;
}
