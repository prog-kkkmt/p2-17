#ifndef SUMM_H_INCLUDED
#define SUMM_H_INCLUDED

class class_summ
{
private:
    long int number_one, number_two;
public:
    void summ()
    {
        std::cout<<"=========Сумма двух чисел========="<<std::endl;
        std::cout<<"Введите два числа через пробел или с новой строчки:"<<std::endl;
        std::cin>>number_one>>number_two;
        std::cout<<"Сумма двух введённых чисел равна: "<<number_one+number_two<<std::endl;

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
            file<<"|| Операция: Сумма"<<std::endl;
            file<<"|| Первое число: "<<number_one<<std::endl;
            file<<"|| Второе число: "<<number_two<<std::endl;
            file<<"|| Сумма чисел: "<<number_one+number_two<<std::endl;
            file<<"======================================="<<std::endl;
            file.close();
        }
        else
        {
            std::ofstream file;
            file.open("history.txt", std::ios_base::app);
            file<<"|| Операция: Сумма"<<std::endl;
            file<<"|| Первое число: "<<number_one<<std::endl;
            file<<"|| Второе число: "<<number_two<<std::endl;
            file<<"|| Сумма чисел: "<<number_one+number_two<<std::endl;
            file<<"======================================="<<std::endl;
            file.close();
        }
    }
};

#endif // SUMM_H_INCLUDED
