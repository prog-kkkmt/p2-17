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

class Alien : public Character
{
public:
    Alien()
    {
        this->name = "Alien";
        this->hp = 80;
    }

    int summon_the_face()
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

    int alien_bite()
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

    int tail_piercing()
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
        std::cout << "1) Призыв лицехвата (Урон - 10, Мана - 1, Пробивает блок)" << std::endl;
        std::cout << "2) Пронзание хвостом (Урон - 15, Мана - 5)" << std::endl;
        std::cout << "3) Укус чужого (Урон - 30, hp + 10, Мана - 10)" << std::endl;
        std::cout << "4) Пропуск хода" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            return this->summon_the_face();
        case 2:
            return this->tail_piercing();
        case 3:
            return this->alien_bite();
        default:
            return 0;
        }
    }
};

class Ruy : public Character
{
public:
    Ruy()
    {
        this->name = "Ruy";
        this->hp = 60;
    }

    int hadouken()
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

    int suffocating()
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
        std::cout << "1) Haduken (Урон - 30, Мана - 5)" << std::endl;
        std::cout << "2) Двойной удар (Урон - 10, Мана - 1)" << std::endl;
        std::cout << "3) Удушающий (Урон - 20, Мана - 3)" << std::endl;
        std::cout << "4) Пропуск хода" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            return this->hadouken();
        case 2:
            return this->double_punch();
        case 3:
            return this->suffocating();
        default:
            return 0;
        }
    }
};

class Balrog : public Character
{
public:
    Balrog()
    {
        this->name = "Balrog";
        this->hp = 100;
    }

    int black_punch()
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

    int uppercut()
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
        std::cout << "1) Черный удар (Урон - 50, Мана - 8)" << std::endl;
        std::cout << "2) Апперкот (Урон - 15, Мана - 3)" << std::endl;
        std::cout << "3) Удар с разворота (Урон - 20, Мана - 4)" << std::endl;
        std::cout << "4) Пропуск хода" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            return this->black_punch();
        case 2:
            return this->uppercut();
        case 3:
            return this->u_turn();
        default:
            return 0;
        }
    }
};

class VincentVega : public Character
{
public:
    VincentVega()
    {
        this->name = "Vincent Vega";
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
        std::cout << "1) Неосторожное обращение с огнестрелом (с шансом 50% - Убивает противника, 9 маны)" << std::endl;
        std::cout << "2) Укол атреналина в сердце (hp + 10, манa + 2)" << std::endl;
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
    if (name == "alien")
    {
        static Alien a;
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
            std::cout << name << " проиграл!" << std::endl;
            return 0;
        }
    }
    else if (name == "ruy")
    {
        static Ruy a;
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
            std::cout << name << " проиграл!" << std::endl;
            return 0;
        }
    }
    else if (name == "balrog")
    {
        static Balrog a;
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
            std::cout << name << " проиграл!" << std::endl;
            return 0;
        }
    }
    else if (name == "vincent vega")
    {
        static VincentVega a;
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
            std::cout << name << " проиграл!" << std::endl;
            return 0;
        }
    }
}

std::string menu()
{
    int choice;
    std::string name;
    std::cout << "Выбор персонажа: " << std::endl;
    std::cout << "1) Alien" << std::endl;
    std::cout << "2) Ruy" << std::endl;
    std::cout << "3) Balrog" << std::endl;
    std::cout << "4) Vincent Vega" << std::endl;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
    {
        name = "alien";
        break;
    }
    case 2:
    {
        name = "ruy";
        break;
    }
    case 3:
    {
        name = "balrog";
        break;
    }
    case 4:
    {
        name = "vincent vega";
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
    std::string player_one = menu();
    std::string player_two = menu();
    fight(0, player_one, player_two);
}
