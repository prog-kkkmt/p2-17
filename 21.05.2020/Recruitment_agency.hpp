#ifndef _Recruitment_agency_
#define _Recruitment_agency_
#include <iostream>
#include <fstream>
#include <vector>
#include <locale>
#include <cstring>

using namespace std;

class Recruitment_agency
{
private:
    struct posts
    {
        int post_kod;
        string post_name;
    };

    struct professions
    {
        int profession_cod;
        string profession_name;
    };
    struct form
    {
        int form_code;
        string form_name;
    };
    struct computer_LVL
    {
        int LVL_cod;
        string LVL_name;
    };
    struct vacancy
    {
        int vacancy_cod;
        int publ_date;
        string vacancy_name;
        int salary;
        string feasibility;
        string post_cod;
        string form_cod;
        string LVL_cod;

    };
    string S;
    string S2;
    string S3;
    string S4;
    string S5;

    posts count1;
    professions count2;
    form count3;
    computer_LVL count4;
    vacancy count5;

    vector<posts> table;
    vector<professions> table2;
    vector<form> table3;
    vector<computer_LVL> table4;
    vector<vacancy> table5;

    void write_to_file_posts(vector<posts>& table, string S);
    void write_to_file_professions(vector<professions>& table2, string S2);
    void write_to_file_form(vector<form>& table3, string S3);
    void write_to_file_computer_LVL(vector<computer_LVL>& table4, string S4);
    void write_to_file_vacancy(vector<vacancy>& table5, string S5);
public:
    void add_to_posts_vector(string S);
    void write_to_file_posts_HTML();
    void post_write();
    void post_delete();
    void post_add();
    void post_rewrite();
    void post_menu();

    void add_to_professions_vector(string S2);
    void write_to_file_professions_HTML();
    void professions_write();
    void professions_delete();
    void professions_add();
    void professions_rewrite();
    void professions_menu();

    void add_to_form_vector(string S3);
    void write_to_file_form_HTML();
    void form_write();
    void form_delete();
    void form_add();
    void form_rewrite();
    void form_menu();

    void add_to_computer_LVL_vector(string S4);
    void write_to_file_computer_LVL_HTML();
    void computer_LVL_write();
    void computer_LVL_delete();
    void computer_LVL_add();
    void computer_LVL_rewrite();
    void computer_LVL_menu();

    void add_to_vacancy_vector(string S5);
    void write_to_file_vacancy_HTML();
    void vacancy_write();
    void vacancy_delete();
    void vacancy_add();
    void vacancy_rewrite();
    void vacancy_menu();
};
#endif // _Recruitment_agency_
