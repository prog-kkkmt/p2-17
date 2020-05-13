#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Rate
{
public:
    int code;
    int min_distance;
    int max_distance;
    double price;

    Rate(int code, int min_dist, int max_dist, double price)
    {
        this->code = code;
        this->min_distance = min_dist;
        this->max_distance = max_dist;
        this->price = price;
    }

    void change_price(double value)
    {
        this->price = value;
    }

    void change(int num, int value)
    {
        switch (num)
        {
        case 1:
            this->code = value;
            break;
        case 2:
            this->min_distance = value;
            break;
        case 3:
            this->max_distance = value;
            break;
        case 4:
            change_price(value);
            break;
        }
    }

    
};

void read_file(std::vector<Rate>& rates)
{
    std::ifstream in("input.txt");
    int code, min_dist, max_dist;
    double price;
    while (in >> code >> min_dist >> max_dist >> price)
    {
        Rate r(code, min_dist, max_dist, price);
        rates.push_back(r);
    }
    in.close();
}

int search_record(std::vector<Rate>& rates, int num)
{
    for (int i = 0; i < rates.size(); i++)
        if (rates[i].code == num)
            return i;
}

void delete_record(std::vector<Rate>& rates, int num)
{
    rates.erase(rates.begin() + num);
}

void add_record(std::vector<Rate>& rates, int code, int min_dist, int max_dist, double price)
{
    Rate r(code, min_dist, max_dist, price);
    rates.push_back(r);
}

void write_file(std::vector<Rate>& rates)
{
    std::ofstream out;
    out.open("output.txt");
    if (out.is_open())
        for (int i = 0; i < rates.size(); i++)
            out << rates[i].code << " " << rates[i].max_distance << " " << rates[i].min_distance << " " << rates[i].price << std::endl;
}

int menu(std::vector<Rate>& rates)
{
    int choice;
    std::cout << "1) Выгрузить из файла input.txt" << std::endl;
    std::cout << "2) Удалить запись" << std::endl;
    std::cout << "3) Добавить запись" << std::endl;
    std::cout << "4) Изменить запись" << std::endl;
    std::cout << "5) Записать в файл запись" << std::endl;
    std::cout << "6) Выход" << std::endl;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
    {
        read_file(rates);
        std::cout << "Удачно" << std::endl;
        menu(rates);
        break;
    }
    case 2:
    {
        int num;
        std::cout << "Код записи" << std::endl;
        std::cin >> num;
        delete_record(rates, search_record(rates, num));
        menu(rates);
        break;
    }
    case 3:
    {
        int code, min_dist, max_dist;
        double price;
        std::cout << "Input code, min dist, max dist, price" << std::endl;
        std::cin >> code >> min_dist >> max_dist >> price;
        add_record(rates, code, min_dist, max_dist, price);
        std::cout << "Удачно" << std::endl;
        menu(rates);
        break;
    }
    case 4:
    {
        int num;
        std::cout << "Код записи" << std::endl;
        std::cin >> num;
        std::cout << "Изменить 1 code; 2 min dist; 3 max dist; 4 price (номер значение)" << std::endl;
        int c, value;
        std::cin >> c >> value;
        rates[search_record(rates, num)].change(c, value);
        menu(rates);
        break;
    }
    case 5:
    {
        write_file(rates);
        menu(rates);
        break;
    }
    case 6:
        return 0;
    default:
        menu(rates);
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<Rate> rates;
    menu(rates);
    return 0;
}
