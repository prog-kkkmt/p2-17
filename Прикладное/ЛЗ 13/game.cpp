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
        this->name = "����� ������";
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
            std::cout << "� ��� �� ������� ���� " << std::endl;
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
            std::cout << "� ��� �� ������� ���� " << std::endl;
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
            std::cout << "� ��� �� ������� ���� " << std::endl;
            this->move();
        }
    }

    int move()
    {
        int choice;
        std::cout << "����� �����: " << std::endl;
        std::cout << "1) ����� ����� (���� - 10, ���� - 1, ��������� ����)" << std::endl;
        std::cout << "2) �������� (���� - 15, ���� - 5)" << std::endl;
        std::cout << "3) ���� ������������ (���� - 30, hp + 10, ���� - 10)" << std::endl;
        std::cout << "4) ���� �� ���� (������� ����)" << std::endl;
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
        this->name = "����� �������";
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
            std::cout << "� ��� �� ������� ���� " << std::endl;
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
            std::cout << "� ��� �� ������� ���� " << std::endl;
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
            std::cout << "� ��� �� ������� ���� " << std::endl;
            this->move();
        }
    }

    int move()
    {
        int choice;
        std::cout << "����� �����: " << std::endl;
        std::cout << "1) ������ �� ���������� (���� - 30, ���� - 5)" << std::endl;
        std::cout << "2) ������� ���� (���� - 10, ���� - 1)" << std::endl;
        std::cout << "3) ���� � ����� (���� - 20, ���� - 3)" << std::endl;
        std::cout << "4) ���� �� ���� (������� ����)" << std::endl;
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
        this->name = "���������� ���";
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
            std::cout << "� ��� �� ������� ���� " << std::endl;
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
            std::cout << "� ��� �� ������� ���� " << std::endl;
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
            std::cout << "� ��� �� ������� ���� " << std::endl;
            this->move();
        }
    }

    int move()
    {
        int choice;
        std::cout << "����� �����: " << std::endl;
        std::cout << "1) ����� ������ (���������� ���������� ����) (���� - 50, ���� - 8)" << std::endl;
        std::cout << "2) �������� (���� - 15, ���� - 3)" << std::endl;
        std::cout << "3) ���� � ��������� (���� - 20, ���� - 4)" << std::endl;
        std::cout << "4) ������� �����(������� ����)" << std::endl;
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
        this->name = "������� ������";
        this->hp = 70;
    }

    int careless_handling_firearm(int chance)
    {
        if (this->mana >= 9 or mana_over())
        {
            this->mana -= 9;
            if (chance == 1)
                return 100;
            std::cout << "���� ... ������ �� ������� ... :)" << std::endl;
            return 0;
        }
        else
        {
            std::cout << "� ��� �� ������� ���� " << std::endl;
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
        std::cout << "����� �����: " << std::endl;
        std::cout << "1) ������������ ��������� � ���������� (� ������ 50% - ������� ����������, 9 ����)" << std::endl;
        std::cout << "2) ������ ��������� (hp + 10, ���a + 2)" << std::endl;
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
    if (name == "����� ������")
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
            std::cout << name << " ���� � �����!" << std::endl;
            return 0;
        }
    }
    else if (name == "������� �����")
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
            std::cout << name << " ���� � �����!" << std::endl;
            return 0;
        }
    }
    else if (name == "���������� ���")
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
            std::cout << name << " ���� � �����!" << std::endl;
            return 0;
        }
    }
    else if (name == "������� ������")
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
            std::cout << name << " ���� � �����!" << std::endl;
            return 0;
        }
    }
}

std::string menu()
{
    int choice;
    std::string name;

    std::cout << "����� ���������: " << std::endl;
    std::cout << "1) ����� ������" << std::endl;
    std::cout << "2) ����� �������" << std::endl;
    std::cout << "3) ���������� ���" << std::endl;
    std::cout << "4) ������� ������" << std::endl;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
    {
        name = "����� ������";
        break;
    }
    case 2:
    {
        name = "����� �������";
        break;
    }
    case 3:
    {
        name = "���������� ���";
        break;
    }
    case 4:
    {
        name = "������� ������";
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
    std::cout << "������� �� ����� ����� �������� ����� ������� ������� � �������� � 4 �����! " << std::endl;
    std::cout << "��� ������� � ���� �������� ���������, � ���� ���� ����������?...: " << std::endl;
    std::cout << "�� ����� �� �����! �������� � ��������� ������..." << std::endl;
    std::string player_one = menu();
    std::string player_two = menu();
    fight(0, player_one, player_two);
}
