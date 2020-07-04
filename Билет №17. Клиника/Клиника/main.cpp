#include "doctors.h"
#include "patients.h"
#include "diagnosis.h"
#include "appointments.h"


using namespace std;

int main()
{
	setlocale(LC_ALL,"Rus");
	int x;
    Patient p;
	Doctors d;

	do
    {
        cout << endl;
        cout << "1. ��������� ���������� ������ ����" << endl;
        cout << "2. ������������� �������� ���������� �� �������������" << endl;
        cout << "3. �����" << endl;

        cin >> x;
        cout << endl;

		switch(x)
		{
		    case 1: p.print_patient(); break;
		    case 2: d.print_specialist(); break;
		    case 4: break;
		    default: cout << "��� ������ ������" << endl; break;
		};
	}
	while(x != 4);
    return 0;
}
