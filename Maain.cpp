#include<iostream>
#include<string>
#include<vector>
#include"PhoneBook.h"
using namespace std;


int main()
{
	vector <Customer>vc1;
	vector <Customer>::iterator itr1;
	char ch = '\0';
	int s = 0;//search variable
	int swVar = 0;
	do
	{
		Customer c;

		c.AddCustomer();
		c.DisplayCustomer();
		vc1.push_back(c);
		cout << endl;
		cout << vc1.capacity();
		cout << "\nUpdate in List 1/0??";
		cin >> s;
		if (s == 1)
		{
			c.UpdateCustomer(vc1);
		}
		cout << "\nEnter the choice as y to continue" << endl;
		cin >> ch;
	} while (ch == 'Y' || ch == 'y');
	cout << "\nPopping Data...........";

	/*for (itr1 = vc1.begin(); itr1 < vc1.end(); itr1++)
	{
	cout << *itr1;
	}*/
	for (int i = 0; i < vc1.size(); i++)
	{
		vc1[i].DisplayCustomer();
	}





	system("pause");
	return 0;
}