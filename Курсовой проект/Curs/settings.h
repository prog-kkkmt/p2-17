#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

class settings
{
private:
    std::string pass, new_pass;
public:
    void open_history()
    {
        std::cout<<"Открытие истории..."<<std::endl;
        std::cout<<"После того, как Вы закроете историю, Вы будете перенаправлены в меню настроек."<<std::endl;
        system("history.txt");
        system("cls");
    }

    void clear_history()
    {
        std::cout<<"Проводится очистка истории..."<<std::endl;
        std::ofstream clear_file("history.txt", std::ios_base::trunc);
        clear_file.close();
    }

    void change_password()
    {
        std::ofstream file("password.txt", std::ios_base::trunc);
        std::cout<<"Введите новый пароль:"<<std::endl;
        std::cin>>pass;
        file<<pass;
        file.close();
        std::cout<<"Пароль успешно изменён!"<<std::endl;
    }

    int settings_menu()
    {
begin:
        int choise;
        std::cout<<"========Настройки========="<<std::endl;
        std::cout<<"||1. Просмотр истории   ||"<<std::endl;
        std::cout<<"||2. Очистка истории    ||"<<std::endl;
        std::cout<<"||3. Смена пароля       ||"<<std::endl;
        std::cout<<"||4. Выход из настроек  ||"<<std::endl;
        std::cout<<"=========================="<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Ваш выбор: ";
        std::cin>>choise;

        switch(choise)
        {
        case 1:
        {
            system("cls");
            open_history();
            goto begin;
        }
        case 2:
        {
            system("cls");
            clear_history();
            system("pause");
            system("cls");
            goto begin;
        }
        case 3:
        {
            system("cls");
            change_password();
            system("pause");
            system("cls");
            goto begin;
        }
        case 4:
        {
            return 0;
        }
        default:
        {
            system("cls");
            std::cout<<"Неправильный ввод, пожалуйста, повторите попытку..."<<std::endl<<std::endl;
            system("pause");
            system("cls");
            goto begin;
        }
        }

    }
    void open_settings()
    {
        std::ifstream file("password.txt");
        while(file)
        {
            file>>pass;
        }
        std::string entry;
        std::cout<<"Добро пожаловать в настройки программы!"<<std::endl;
        std::cout<<std::endl;
        std::cout<<"Для продолжения введите пароль преподавателя!"<<std::endl;
retry:
        std::cout<<"Для выхода введите 'Quit'"<<std::endl;
        std::cin>>entry;
        if(entry == pass)
        {
            system("cls");
            std::cout<<"Пароль успешно введён! Переход в настройки..."<<std::endl;
            system("pause");
            system("cls");
            settings_menu();
        }
        else if(entry == "Quit")
        {

        }
        else
        {
            system("cls");
            std::cout<<"Пароль введён неверно! Повторите попытку..."<<std::endl<<std::endl;
            goto retry;
        }
    }
};

#endif // SETTINGS_H_INCLUDED
