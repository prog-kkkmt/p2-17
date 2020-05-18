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
            this->price = value;
            break;
        }
    }

    void write_to_file(std::string name_file)
    {
        std::ofstream out;
        out.open(name_file, std::ios::app);
        out << code << " " << max_distance << " " << min_distance << " " << price << std::endl;
        out.close();
    }
};

class Cities
{
public:
    int code;
    double distance;
    int code_rate;

    Cities(int code_city, double distance, int code_rate)
    {
        this->code = code_city;
        this->distance = distance;
        this->code_rate = code_rate;
    }

    void change(int num, int value)
    {
        switch (num)
        {
        case 1:
            this->code = value;
            break;
        case 2:
            this->distance = value;
            break;
        case 3:
            this->code_rate = value;
            break;
        }
    }

    void write_to_file(std::string name_file)
    {
        std::ofstream out;
        out.open(name_file, std::ios::app);
        out << code << " " << distance << " " << code_rate << std::endl;
        out.close();
    }
};

class Conversations
{
public:
    int code;
    int code_city;
    char* start;
    size_t len;
    int duration;

    Conversations(int code, int code_city, std::string str, int duration)
    {
        this->code = code;
        this->code_city = code_city;
        this->duration = duration;
        this->len = str.length() + 1;
        this->start = new char[str.length() + 1];
        std::strcpy(this->start, str.c_str());
    }

    void change(int num, int value)
    {
        switch (num)
        {
        case 1:
            this->code = value;
            break;
        case 2:
            this->code_city = value;
            break;
        case 3:
            this->duration = value;
            break;
        }
    }

    void write_to_file(std::string name_file)
    {
        std::ofstream out;
        out.open(name_file, std::ios::app);
        out << code << " " << code_city << " " << start << " " << duration << std::endl;
        out.close();
    }

    void delete_member()
    {
        delete[] start;
    }
};

void read_file_rate(std::vector<Rate>& rates, std::string name_file)
{
    std::ifstream in(name_file);
    int code, min_dist, max_dist;
    double price;
    while (in >> code >> min_dist >> max_dist >> price)
        rates.push_back(Rate(code, min_dist, max_dist, price));
    in.close();
}

void read_file_city(std::vector<Cities>& cities, std::string name_file)
{
    std::ifstream in(name_file);
    int code, code_rate;
    double distance;
    while (in >> code >> distance >> code_rate)
        cities.push_back(Cities(code, distance, code_rate));
    in.close();
}

void read_file_conversation(std::vector<Conversations>& conversation, std::string name_file)
{
    std::ifstream in(name_file);
    int code;
    int code_city;
    std::string start;
    int duration;
    while (in >> code >> code_city >> start >> duration)
        conversation.emplace_back(code, code_city, start, duration);
    in.close();
}

int search_record_rate(std::vector<Rate>& obj, int num)
{
    int i;
    for (i = 0; obj[i].code != num; i++)
        ;
    return i;
}

int search_record_city(std::vector<Cities>& obj, int num)
{
    int i;
    for (i = 0; obj[i].code != num; i++)
        ;
    return i;
}

int search_record_conversation(std::vector<Conversations>& obj, int num)
{
    int i;
    for (i = 0; obj[i].code != num; i++)
        ;
    return i;
}

int menu(std::vector<Rate>& rates, std::vector<Cities> &cities, std::vector<Conversations> &conversations, std::string table_name)
{
    int choice;
    std::cout << table_name << std::endl;
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
        if(table_name == "rates")
            read_file_rate(rates, "input_rates.txt");
        else if(table_name == "cities")
            read_file_city(cities, "input_cities.txt");
        else
            read_file_conversation(conversations, "input_conversations.txt");
        std::cout << "Удачно" << std::endl;
        menu(rates, cities, conversations, table_name);
        break;
    }
    case 2:
    {
        int num;
        std::cout << "Код записи" << std::endl;
        std::cin >> num;
        if (table_name == "rates")
            rates.erase(rates.begin() + search_record_rate(rates, num));
        else if (table_name == "cities")
            cities.erase(cities.begin() + search_record_city(cities, num));
        else
            conversations.erase(conversations.begin() + search_record_conversation(conversations, num));
        menu(rates, cities, conversations, table_name);
        break;
    }
    case 3:
    {
        if (table_name == "rates")
        {
            int code, min_dist, max_dist;
            double price;
            std::cout << "Input code, min dist, max dist, price" << std::endl;
            std::cin >> code >> min_dist >> max_dist >> price;
            rates.push_back(Rate(code, min_dist, max_dist, price));
        }
        else if (table_name == "cities")
        {
            int code, code_rate;
            double distance;
            std::cout << "Input code, distance, code rate" << std::endl;
            std::cin >> code >> distance >> code_rate;
            cities.push_back(Cities(code, distance, code_rate));
        }
        else
        {
            int code;
            int code_city;
            std::string start;
            int duration;
            std::cout << "Input code, code_city, start, duration" << std::endl;
            std::cin >> code >> code_city >> start >> duration;
            conversations.push_back(Conversations(code, code_city, start, duration));
        }
        std::cout << "Удачно" << std::endl;
        menu(rates, cities, conversations, table_name);
        break;
    }
    case 4:
    {
        int num;
        std::cout << "Код записи" << std::endl;
        std::cin >> num;
        if (table_name == "rates")
        {
            std::cout << "Изменить 1 code; 2 min dist; 3 max dist; 4 price (номер значение)" << std::endl;
            int c, value;
            std::cin >> c >> value;
            rates[search_record_rate(rates, num)].change(c, value);
        }
        else if (table_name == "cities")
        {
            std::cout << "Изменить 1 code; 2 distance; 3 code rate (номер значение)" << std::endl;
            int c, value;
            std::cin >> c >> value;
            cities[search_record_city(cities, num)].change(c, value);
        }
        else
        {
            std::cout << "Изменить 1 code; 2 code_city; 3 duration (номер значение)" << std::endl;
            int c, value;
            std::cin >> c >> value;
            conversations[search_record_conversation(conversations, num)].change(c, value);
        }
        menu(rates, cities, conversations, table_name);
        break;
    }
    case 5:
    {
        if (table_name == "rates")
            for (int i = 0; i < rates.size(); i++)
                rates[i].write_to_file("output_rate.txt");
        else if (table_name == "cities")
            for (int i = 0; i < cities.size(); i++)
                cities[i].write_to_file("output_city.txt");
        else
            for (int i = 0; i < conversations.size(); i++)
                conversations[i].write_to_file("output_conversation.txt");
        menu(rates, cities, conversations, table_name);
        break;
    }
    case 6:
        for (int i = 0; i < conversations.size(); i++)
            conversations[i].delete_member();
        return 0;
    default:
        menu(rates, cities, conversations, table_name);
        break;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<Rate> rates;
    std::vector<Cities> cities;
    std::vector<Conversations> conversations;
    std::string table_name;
    while (1)
    {
        std::cout << "Введите название таблицы (rates, cities, conversations)" << std::endl;
        std::cin >> table_name;
        if (table_name == "rates" or table_name == "cities" or table_name == "conversations")
            break;
    }

    menu(rates, cities, conversations, table_name);
    return 0;
}
