#ifndef SQRT_H_INCLUDED
#define SQRT_H_INCLUDED

class class_sqrt
{
private:
    long int number_one;
public:
    void Sqrt()
    {
        std::cout<<"=========Корень числа========="<<std::endl;
        std::cout<<"Введите число, корень которого Вам необходимо найти:"<<std::endl;
        std::cin>>number_one;
        if(number_one < 0)
        {
            number_one = abs(number_one);
            std::cout<<"Корень числа равен: "<<sqrt(number_one)<<std::endl;
        }
        else
        {
            std::cout<<"Корень числа равен: "<<sqrt(number_one)<<std::endl;
        }

        std::fstream file;
        file.open("history.txt");
        int size = 0;
        file.seekg(0, std::ios::end);
        size = file.tellg();
        if(size == 0 || size == -1)
        {
            std::ofstream file;
            file.open("history.txt");
            file<<"======================================="<<std::endl;
            file<<"||              История                "<<std::endl;
            file<<"======================================="<<std::endl;
            file<<"|| Операция: Корень"<<std::endl;
            file<<"|| Число: "<<number_one<<std::endl;
            file<<"|| Корень: "<<sqrt(number_one)<<std::endl;
            file<<"======================================="<<std::endl;
            file.close();
        }
        else
        {
            std::ofstream file;
            file.open("history.txt", std::ios_base::app);
            file<<"|| Операция: Корень"<<std::endl;
            file<<"|| Число: "<<number_one<<std::endl;
            file<<"|| Корень: "<<sqrt(number_one)<<std::endl;
            file<<"======================================="<<std::endl;
            file.close();
        }
    }
};

#endif // SQRT_H_INCLUDED
