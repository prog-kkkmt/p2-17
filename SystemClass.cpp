#include <iostream>
#include <vector>

using namespace std;

class tanks
{
private:
	void move()
	{
		cout << "Move" << endl;
	}

	void collision()
	{
		cout << "collision" << endl;
	}

public:
	virtual void Fire()
	{
		cout << "No type";
	}
};

class IFV : public tanks
{
private:
	void AutoGun()
	{
		cout << "AutoGun" << endl;
	}

	void ATR()
	{
		cout << "ATR" << endl;
	}
public:
	virtual void Fire()
	{
			AutoGun();
			ATR();
	}
};

class MBT : private tanks
{
private:
	void Gun()
	{
		cout << "Gun";
	}
public:
	virtual void Fire()
	{
		Gun();
	}
};

class BMPT : private tanks
{
private:
	void Gun()
	{
		cout << "Gun" << endl;
	}

	void AutoGun()
	{
		cout << "AutoGun" << endl;
	}
public:
	virtual void Fire()
	{
			AutoGun();
			Gun();
	}
};

class interfaceTanks : public IFV, public MBT, public BMPT
{

};

int main()
{
	tanks* player = new tanks;
	delete player;
	tanks *tanks = player;
	
	int i;
	cin >> i;
	
	if(i == 1)
		IFV* player = new IFV;
	else if(i == 2)
		BMPT* player = new BMPT;
	else if(i == 3)
		MBT* player = new MBT;
	

	
	tanks->Fire();
}