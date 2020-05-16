#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct RazSpec
{
    int raz_code;
    string name;
};

struct Items
{
    int item_code;
    string oboz;
    string name;
    string ed_izm;
};

struct Composition
{
    int comp_code;
    int yzl_code;
    int podyzl_code;
    int kol_vo;
    int position;
};

void get_rz (vector <RazSpec>& Table)
{
    ifstream fin;
    fin.open("input_rz.txt");
    RazSpec a;
    while (fin >> a.raz_code >> a.name)
        Table.push_back(a);
    fin.close();
}

void del_rz (vector <RazSpec>& Table)
{
    int rc;
    bool b = false;
    cout << "input raz_code: ";
    cin >> rc;
    if (Table.size() > 0)
    {
        for (int i = 0; i < Table.size(); i++)
            if (Table[i].raz_code == rc)
            {
                Table.erase(Table.begin() + i);
                b = true;
            }
    }
    else
        cout << "Wrong code, try again" << endl;
}

void out_rz (vector <RazSpec>& Table)
{
    for (int i = 0; i < Table.size(); i++)
        cout << Table[i].raz_code << " " << Table[i].name << endl;
    cout << endl;
}

void change_rz (vector <RazSpec>& Table)
{
    int rc, buf;
    bool b = false;
    RazSpec a;
    cout << "input raz_code: ";
    cin >> rc;
    if (Table.size() > 0)
    {
        for (int i = 0; i < Table.size(); i++)
            if (Table[i].raz_code == rc)
            {
                b = true;
                buf = i;
            }
        if (b)
        {
            cout << "Change this->  " << Table[buf].raz_code << " " << Table[buf].name << endl;
            cin >> a.raz_code >> a.name;

            Table[buf].raz_code = a.raz_code;
            Table[buf].name = a.name;
        }
    }
    else
        cout << "Wrong item_code\n" << "You are in menu now" << endl;

}

void add_rz (vector <RazSpec>& Table)
{
    RazSpec a;
    cout << "Input 'raz_code' and 'name': ";
    cin >> a.raz_code >> a.name;
    Table.push_back(a);
}

void wrtofi_rz (vector <RazSpec>& Table)
{
    ofstream fout;
    fout.open("output_rz.txt");
    for (int i = 0; i < Table.size(); i++)
        fout << Table[i].raz_code << " " << Table[i].name << endl;
    fout.close();
}

void menu_rz (vector <RazSpec>& Table)
{
    int choice = 0;
	cout << "1) Get 'RazSpec' from file" << endl;
	cout << "2) Add" << endl;
	cout << "3) Delete" << endl;
	cout << "4) Change" << endl;
	cout << "5) Write to file" << endl;
	cout << "6) Exit" << endl;
	while (choice != 6)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            get_rz(Table);
            break;
        case 2:
            add_rz(Table);
            break;
        case 3:
            del_rz(Table);
            break;
        case 4:
            change_rz(Table);
            break;
        case 5:
            wrtofi_rz(Table);
            break;
        }
        out_rz(Table);
    }

}

//-------------------------------------------------------------------------------------

void get_items (vector <Items>& Table)
{
    ifstream fin;
    Items a;
    fin.open("input_items.txt");
    while (fin >> a.item_code >> a.oboz >> a.name >> a.ed_izm)
        Table.push_back(a);
    fin.close();
}

void del_items (vector <Items>& Table)
{
    int item;
    bool b = false;
    cout << "input item_code: ";
    cin >> item;
    if (Table.size() > 0)
    {
        for (int i = 0; i < Table.size(); i++)
            if (Table[i].item_code == item)
            {
                Table.erase(Table.begin() + i);
                b = true;
            }
    }
    else
        cout << "Wrong item_code\n" << "You are in menu now" << endl;
}

void out_items (vector <Items>& Table)
{
    for (int i = 0; i < Table.size(); i++)
        cout << Table[i].item_code << " " << Table[i].oboz
        << " " << Table[i].name << " " << Table[i].ed_izm << endl;
    cout << endl;
}

void change_items (vector <Items>& Table)
{
    int item, buf;
    bool b = false;
    Items a;
    cout << "input items_code: ";
    cin >> item;
    if (Table.size() > 0)
    {
        for (int i = 0; i < Table.size(); i++)
            if (Table[i].item_code == item)
            {
                b = true;
                buf = i;
            }

        if (b)
        {
            cout << "Change this->  " << Table[buf].item_code << " " << Table[buf].oboz
            << " " << Table[buf].name << " " << Table[buf].ed_izm << endl;

            cin >> a.item_code >> a.oboz >> a.name >> a.ed_izm;
            Table[buf].item_code = a.item_code;
            Table[buf].oboz = a.oboz;
            Table[buf].name = a.name;
            Table[buf].ed_izm = a.ed_izm;
        }
    }
    else
        cout << "Wrong item_code\n" << "You are in menu now" << endl;
}

void add_items (vector <Items>& Table)
{
    Items a;
    cout << "Input 'item_code', 'oboz', 'name', 'ed_izm': ";
    cin >> a.item_code >> a.oboz >> a.name >> a.ed_izm;
    Table.push_back(a);
}

void wrtofi_items (vector <Items>& Table)
{
    ofstream fout;
    fout.open("output_items.txt");
    for (int i = 0; i < Table.size(); i++)
        fout << Table[i].item_code << " " << Table[i].oboz
        << " " << Table[i].name << " " << Table[i].ed_izm << endl;
    fout.close();
}

void menu_items (vector <Items>& Table)
{
    int choice = 0;
	cout << "1) Get 'Items' from file" << endl;
	cout << "2) Add" << endl;
	cout << "3) Delete" << endl;
	cout << "4) Change" << endl;
	cout << "5) Write to file" << endl;
	cout << "6) Exit" << endl;
	while (choice != 6)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            get_items(Table);
            break;
        case 2:
            add_items(Table);
            break;
        case 3:
            del_items(Table);
            break;
        case 4:
            change_items(Table);
            break;
        case 5:
            wrtofi_items(Table);
            break;
        }
        out_items(Table);
    }
}

//-------------------------------------------------------------------------------------

void get_comp (vector <Composition>& Table)
{
    ifstream fin;
    fin.open("input_comp.txt");
    Composition a;
    while (fin >> a.comp_code >> a.yzl_code >> a.podyzl_code >> a.kol_vo >> a.position)
        Table.push_back(a);
    fin.close();
}

void del_comp (vector <Composition>& Table)
{
    int comp;
    bool b = false;
    cout << "input comp_code: ";
    cin >> comp;
    if (Table.size() > 0)
    {
        for (int i = 0; i < Table.size(); i++)
        if (Table[i].comp_code == comp)
            {
                Table.erase(Table.begin() + i);
                b = true;
            }
    }
    else
        cout << "Wrong item_code\n" << "You are in menu now" << endl;
}

void out_comp (vector <Composition>& Table)
{
    for (int i = 0; i < Table.size(); i++)
        cout << Table[i].comp_code << " " << Table[i].yzl_code
        << " " << Table[i].podyzl_code << " "
        << Table[i].kol_vo << " " << Table[i].position << endl;
    cout << endl;
}

void change_comp (vector <Composition>& Table)
{
    int comp, buf;
    bool b = false;
    Composition a;
    cout << "input comp_code: ";
    cin >> comp;
    if (Table.size() > 0)
    {
        for (int i = 0; i < Table.size(); i++)
            if (Table[i].comp_code == comp)
            {
                b = true;
                buf = i;
            }

        if (b)
        {
            cout << "Change this-> " << Table[buf].comp_code << " " << Table[buf].yzl_code
            << " " << Table[buf].podyzl_code << " "
            << Table[buf].kol_vo << " " << Table[buf].position << endl;

            cin >> a.comp_code >> a.yzl_code >> a.podyzl_code >> a.kol_vo >> a.position;
            Table[buf].comp_code = a.comp_code;
            Table[buf].yzl_code = a.yzl_code;
            Table[buf].podyzl_code = a.podyzl_code;
            Table[buf].kol_vo = a.kol_vo;
            Table[buf].position = a.position;
        }
    }
    else
        cout << "Wrong item_code\n" << "You are in menu now" << endl;
}

void add_comp (vector <Composition>& Table)
{
    Composition a;
    cout << "Input 'comp_code', 'yzl_code', 'podyzl_code', 'kol_vo', 'position': ";
    cin >> a.comp_code >> a.yzl_code >> a.podyzl_code >> a.kol_vo >> a.position;
    Table.push_back(a);
}

void wrtofi_comp (vector <Composition>& Table)
{
    ofstream fout;
    fout.open("output_comp.txt");
    for (int i = 0; i < Table.size(); i++)
        fout << Table[i].comp_code << " " << Table[i].yzl_code
        << " " << Table[i].podyzl_code << " "
        << Table[i].kol_vo << " " << Table[i].position << endl;
    fout.close();
}

void menu_comp (vector <Composition>& Table)
{
    int choice = 0;
	cout << "1) Get 'Composition' from file" << endl;
	cout << "2) Add" << endl;
	cout << "3) Delete" << endl;
	cout << "4) Change" << endl;
	cout << "5) Write to file" << endl;
	cout << "6) Exit" << endl;
	while (choice != 6)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            get_comp(Table);
            break;
        case 2:
            add_comp(Table);
            break;
        case 3:
            del_comp(Table);
            break;
        case 4:
            change_comp(Table);
            break;
        case 5:
            wrtofi_comp(Table);
            break;
        }
        out_comp(Table);
    }

}
void Chooce_your_table()
{
    cout << "Chooce your table: " << endl;
	cout << "1) RazSpec" << endl;
	cout << "2) Items" << endl;
	cout << "3) Composition" << endl;
	cout << "4) Exit" << endl;
}

int main()
{
	vector <RazSpec> Table_razspec;
	vector <Items> Table_items;
	vector <Composition> Table_composition;

	Chooce_your_table();
	int choice = 0;
	while (choice != 4)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            menu_rz(Table_razspec);
            break;
        case 2:
            menu_items(Table_items);
            break;
        case 3:
            menu_comp(Table_composition);
            break;
        }
        Chooce_your_table();
    }
	return 0;
}
