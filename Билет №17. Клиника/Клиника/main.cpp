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
        cout << "1. Ïàöèåíòîâ ïîáûâàâøèõ áîëüøå ðàçà" << endl;
        cout << "2. Îòíîñèòåëüíàÿ çàãðóçêà ïàöèåíòàìè ïî ñïåöèàëüíîñòè" << endl;
        cout << "3. Âûõîä" << endl;

        cin >> x;
        cout << endl;

		switch(x)
		{
		    case 1: p.print_patient(); break;
		    case 2: d.print_specialist(); break;
		    case 3: break;
		    default: cout << "Íåò òàêîãî ïóíêòà" << endl; break;
		};
	}
	while(x != 3);
    return 0;
}
