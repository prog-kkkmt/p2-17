#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

class Character
{
protected:
    std::string name;
    int hp = 0;
    int mana = 10;

public:
    void mana_recovery()
    {
        this->mana += 2;
    }

    int mana_over()
    {
        if (this->mana <= 0)
            return 1;
        return 0;
    }

    int game_over()
    {
        if (this->hp <= 0)
            return 1;
        return 0;
    }

    void damage(int amount_of_damage)
    {
        this->hp -= amount_of_damage;
        game_over();
    }

    void how()
    {
        std::cout << "HP: " << this->hp << std::endl;
        std::cout << "MANA: " << this->mana << std::endl;
    }
};

class foma : public Character
{
public:
    foma()
    {
        this->name = "Фомин Даниил";
        this->hp = 80;
    }

    int pinok()
    {
        if (this->mana >= 1 or mana_over())
        {
            this->mana -= 1;
            return 10;
        }
        else
        {
            std::cout << "У вас не хватает маны " << std::endl;
            this->move();
        }
    }

    int ukus()
    {
        if (this->mana >= 10 or mana_over())
        {
            this->mana -= 10;
            this->hp += 10;
            return 30;
        }
        else
        {
            std::cout << "У вас не хватает маны " << std::endl;
            this->move();
        }
    }

    int apperkot()
    {
        if (this->mana >= 5 or mana_over())
        {
            this->mana -= 5;
            return 15;
        }
        else
        {
            std::cout << "У вас не хватает маны " << std::endl;
            this->move();
        }
    }

    int move()
    {
        int choice;
        std::cout << "Выбор удара: " << std::endl;
        std::cout << "1) Пинок ногой (Урон - 10, Мана - 1, Пробивает блок)" << std::endl;
        std::cout << "2) Апперкот (Урон - 15, Мана - 5)" << std::endl;
        std::cout << "3) Укус программиста (Урон - 30, hp + 10, Мана - 10)" << std::endl;
        std::cout << "4) Уйти на пару (пропуск хода)" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            return this->pinok();
        case 2:
            return this->apperkot();
        case 3:
            return this->ukus();
        default:
            return 0;
        }
    }
};

class jarik : public Character
{
public:
    jarik()
    {
        this->name = "Фомин Ярослав";
        this->hp = 60;
    }

    int plevok()
    {
        if (this->mana >= 5 or mana_over())
        {
            this->mana -= 5;
            return 30;
        }
        else
        {
            std::cout << "У вас не хватает маны " << std::endl;
            this->move();
        }
    }

    int double_punch()
    {
        if (this->mana >= 1 or mana_over())
        {
            this->mana -= 1;
            return 10;
        }
        else
        {
            std::cout << "У вас не хватает маны " << std::endl;
            this->move();
        }
    }

    int lokot()
    {
        if (this->mana >= 3 or mana_over())
        {
            this->mana -= 3;
            return 20;
        }
        else
        {
            std::cout << "У вас не хватает маны " << std::endl;
            this->move();
        }
    }

    int move()
    {
        int choice;
        std::cout << "Выбор удара: " << std::endl;
        std::cout << "1) Плевок на противника (Урон - 30, Мана - 5)" << std::endl;
        std::cout << "2) Двойной удар (Урон - 10, Мана - 1)" << std::endl;
        std::cout << "3) Удар с локтя (Урон - 20, Мана - 3)" << std::endl;
        std::cout << "4) Уйти на пару (Пропуск хода)" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            return this->plevok();
        case 2:
            return this->double_punch();
        case 3:
            return this->lokot();
        default:
            return 0;
        }
    }
};

class juk : public Character
{
public:
    juk()
    {
        this->name = "Константин Жук";
        this->hp = 100;
    }

    int vyshmat()
    {
        if (this->mana >= 8 or mana_over())
        {
            this->mana -= 8;
            return 50;
        }
        else
        {
            std::cout << "У вас не хватает маны " << std::endl;
            this->move();
        }
    }

    int poshechina()
    {
        if (this->mana >= 3 or mana_over())
        {
            this->mana -= 3;
            return 15;
        }
        else
        {
            std::cout << "У вас не хватает маны " << std::endl;
            this->move();
        }
    }

    int u_turn()
    {
        if (this->mana >= 4 or mana_over())
        {
            this->mana -= 4;
            return 20;
        }
        else
        {
            std::cout << "У вас не хватает маны " << std::endl;
            this->move();
        }
    }

    int move()
    {
        int choice;
        std::cout << "Выбор удара: " << std::endl;
        std::cout << "1) Сдать вышмат (шокирующий противника урон) (Урон - 50, Мана - 8)" << std::endl;
        std::cout << "2) Пощечина (Урон - 15, Мана - 3)" << std::endl;
        std::cout << "3) Удар с разворота (Урон - 20, Мана - 4)" << std::endl;
        std::cout << "4) Поехать домой(Пропуск хода)" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            return this->vyshmat();
        case 2:
            return this->poshechina();
        case 3:
            return this->u_turn();
        default:
            return 0;
        }
    }
};

class grish : public Character
{
public:
    grish()
    {
        this->name = "Гришаев Андрей";
        this->hp = 70;
    }

    int careless_handling_firearm(int chance)
    {
        if (this->mana >= 9 or mana_over())
        {
            this->mana -= 9;
            if (chance == 1)
                return 100;
            std::cout << "Нууу ... Видимо не сегодня ... :)" << std::endl;
            return 0;
        }
        else
        {
            std::cout << "У вас не хватает маны " << std::endl;
            this->move();
        }
    }

    int adrenaline_injection()
    {
        this->hp += 10;
        this->mana += 2;
        return 0;
    }

    int move()
    {
        int choice;
        std::cout << "Выбор удара: " << std::endl;
        std::cout << "1) Неосторожное обращение с зажигалкой (с шансом 50% - Убивает противника, 9 маны)" << std::endl;
        std::cout << "2) Выпить энергетик (hp + 10, манa + 2)" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            return this->careless_handling_firearm(1 + rand() % 2);
        case 2:
            return this->adrenaline_injection();
        default:
            return 0;
        }
    }
};

int fight(int damage, std::string name, std::string enemy)
{
    if (name == "Фомин Даниил")
    {
        static foma a;
        a.damage(damage);
        if (!a.game_over())
        {
            std::cout << "-------------" << name << "-------------" << std::endl;
            a.mana_recovery();
            a.how();
            fight(a.move(), enemy, name);
        }
        else
        {
            std::cout << name << " ушел в армию!" << std::endl;
            return 0;
        }
    }
    else if (name == "Ярослав Фомин")
    {
        static jarik a;
        a.damage(damage);
        if (!a.game_over())
        {
            std::cout << "-------------" << name << "-------------" << std::endl;
            a.mana_recovery();
            a.how();
            fight(a.move(), enemy, name);
        }
        else
        {
            std::cout << name << " ушел в армию!" << std::endl;
            return 0;
        }
    }
    else if (name == "Константин Жук")
    {
        static juk a;
        a.damage(damage);
        if (!a.game_over())
        {
            std::cout << "-------------" << name << "-------------" << std::endl;
            a.mana_recovery();
            a.how();
            fight(a.move(), enemy, name);
        }
        else
        {
            std::cout << name << " ушел в армию!" << std::endl;
            return 0;
        }
    }
    else if (name == "Гришаев Андрей")
    {
        static grish a;
        a.damage(damage);
        if (!a.game_over())
        {
            std::cout << "-------------" << name << "-------------" << std::endl;
            a.mana_recovery();
            a.how();
            fight(a.move(), enemy, name);
        }
        else
        {
            std::cout << name << " ушел в армию!" << std::endl;
            return 0;
        }
    }
}

std::string menu()
{
    int choice;
    std::string name;

    std::cout << "Выбор персонажа: " << std::endl;
    std::cout << "1) Фомин Даниил" << std::endl;
    std::cout << "2) Фомин Ярослав" << std::endl;
    std::cout << "3) Константин Жук" << std::endl;
    std::cout << "4) Гришаев Андрей" << std::endl;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
    {
        name = "Фомин Даниил";
        break;
    }
    case 2:
    {
        name = "Фомин Ярослав";
        break;
    }
    case 3:
    {
        name = "Константин Жук";
        break;
    }
    case 4:
    {
        name = "Гришаев Андрей";
        break;
    }
    default:
        break;
    }
    return name;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Сегодня на нашей арене сразятся самые отпетые негодяи и должники с 4 курса! " << std::endl;
    std::cout << "Кто выживет в этом нелегком испытании, а кого ждет отчисление?...: " << std::endl;
    std::cout << "Да решит же битва! Жестокая и нещадащая никого..." << std::endl;
    std::string player_one = menu();
    std::string player_two = menu();
    fight(0, player_one, player_two);
}
