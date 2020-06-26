#ifndef SUBTRACTION_H_INCLUDED
#define SUBTRACTION_H_INCLUDED

class class_subtraction
{
private:
    long int number_one, number_two;
public:
    void subtraction()
    {
        std::cout<<"=========Разность двух чисел========="<<std::endl;
        std::cout<<"Введите два числа через пробел или с новой строчки:"<<std::endl;
        std::cin>>number_one>>number_two;
        std::cout<<"Разность двух введённых чисел равна: "<<number_one-number_two<<std::endl;

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
            file<<"|| Операция: Вычитание"<<std::endl;
            file<<"|| Первое число: "<<number_one<<std::endl;
            file<<"|| Второе число: "<<number_two<<std::endl;
            file<<"|| Разность чисел: "<<number_one-number_two<<std::endl;
            file<<"======================================="<<std::endl;
            file.close();
        }
        else
        {
            std::ofstream file;
            file.open("history.txt", std::ios_base::app);
            file<<"|| Операция: Разность"<<std::endl;
            file<<"|| Первое число: "<<number_one<<std::endl;
            file<<"|| Второе число: "<<number_two<<std::endl;
            file<<"|| Разность чисел: "<<number_one-number_two<<std::endl;
            file<<"======================================="<<std::endl;
            file.close();
        }
    }
};

#endif // SUBTRACTION_H_INCLUDED
