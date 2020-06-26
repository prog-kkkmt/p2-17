#ifndef DIVISION_H_INCLUDED
#define DIVISION_H_INCLUDED

class class_division
{
private:
    long int number_one, number_two;
public:
    void division()
    {
begin:
        std::cout<<"=========Частное двух чисел========="<<std::endl;
        std::cout<<"Введите два числа через пробел или с новой строчки:"<<std::endl;
        std::cin>>number_one>>number_two;
        if(number_one == 0 && number_two == 0)
        {
            std::cout<<"Нельзя делить ноль на ноль!"<<std::endl;
            std::cout<<"Повторите ещё раз..."<<std::endl;
            system("pause");
            system("cls");
            goto begin;
        }
        else
        {
            std::cout<<"Частное двух введённых чисел равна: "<<number_one/number_two<<std::endl;
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
            file<<"|| Операция: Деление"<<std::endl;
            file<<"|| Первое число: "<<number_one<<std::endl;
            file<<"|| Второе число: "<<number_two<<std::endl;
            file<<"|| Частное чисел: "<<number_one/number_two<<std::endl;
            file<<"======================================="<<std::endl;
            file.close();
        }
        else
        {
            std::ofstream file;
            file.open("history.txt", std::ios_base::app);
            file<<"|| Операция: Деление"<<std::endl;
            file<<"|| Первое число: "<<number_one<<std::endl;
            file<<"|| Второе число: "<<number_two<<std::endl;
            file<<"|| Частное чисел: "<<number_one/number_two<<std::endl;
            file<<"======================================="<<std::endl;
            file.close();
        }
    }
};

#endif // DIVISION_H_INCLUDED
