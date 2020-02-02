#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"PhoneBook.h"
using namespace std;

void Customer::AddCustomer()
{
	long long int dummy_no = 0;
	cout << "\nEnter the Name of the customer : ";
	cin >> p1->name;

	cout << "\nEnter the Phone Number : ";
	cin >> dummy_no;

	p1->ph_no.push_back(dummy_no);
}
void Customer::DisplayCustomer()
{
	vector <long long int>::iterator itr;
	cout << "\nName : " << p1->name;
	for (itr = p1->ph_no.begin(); itr < p1->ph_no.end(); itr++)
	{
		cout << "Phone No. :" << *itr;
	}

}
void Customer::SearchCustomer(vector<Customer> vc)
{
	int choice = 0;
	cout << "\nSearch by Name? Press 0";
	cout << "\nSearch by Phone Number? Press 1";
	cout << "\nSearch by Name? Press 0";
	cin >> choice;
	if (choice == 0)
	{
		//search by name
		string nm = "";
		int flag = 0;
		cout << "\nEnter the name of customer to be searched";
		cin >> nm;
		for (int i = 0; i < vc.size(); i++)
		{
			PhoneBook *dummyp;
			dummyp = vc[i].getCustomer();
			if (dummyp->name == nm)
			{
				flag = 1;
				cout << "\nMatch Found";
				vc[i].DisplayCustomer();
				break;
			}
		}
		if (flag == 0)
		{
			cout << "\nNo match found";
		}
	}
	else if (choice == 1)
	{
		long long int ph = 0;
		long long int *ph1_ptr;//as 
		int flag = 0;
		cout << "\nEnter the Phone Number of customer to be searched";
		cin >> ph;
		for (int i = 0; i < vc.size(); i++)
		{
			PhoneBook *dummyp;
			dummyp = vc[i].getCustomer();
			ph1_ptr = dummyp->ph_no.data();
			//as in dummy ptr phno is stored in vector it cannot be accessed directly 
			//so use a LLinteger pointer that points to data stored at that ptr location

			if (*ph1_ptr == ph)
			{
				flag = 1;
				cout << "\nMatch Found";
				vc[i].DisplayCustomer();
				break;
			}
		}
		if (flag == 0)
		{
			cout << "\nNo match found";
		}
	}
	else
	{
		cout << "\nInvalid Choice";
	}
}


void Customer::UpdateCustomer(vector<Customer> vc)
{
	int choice = 0;
	cout << "\nUpdate by Name? Press 0";
	cout << "\nUpdate by Phone Number? Press 1" << endl;

	cin >> choice;
	if (choice == 0)
	{
		//search by name
		string nm = "";
		long long int upPhno = 0;
		long long int *upptr;
		int flag = 0;
		cout << "\nEnter the name of customer : ";
		cin >> nm;
		for (int i = 0; i < vc.size(); i++)
		{
			PhoneBook *dummyp;
			dummyp = vc[i].getCustomer();
			if (dummyp->name == nm)
			{
				flag = 1;
				cout << "\nMatch Found";
				vc[i].DisplayCustomer();
				cout << "\nEnter the updated Phone no : ";
				cin >> upPhno;
				//p1->ph_no = upPhno;//this is not possible


				upptr = p1->ph_no.data();
				*upptr = upPhno;


				//updated now
				vc[i].DisplayCustomer();

				break;
			}
		}
		if (flag == 0)
		{
			cout << "\nNo match found";
		}
	}
	else if (choice == 1)
	{
		long long int ph = 0;
		long long int *ph1_ptr;//as 
		int flag = 0;
		cout << "\nEnter the Phone Number of customer to be searched";
		cin >> ph;
		for (int i = 0; i < vc.size(); i++)
		{
			PhoneBook *dummyp;
			dummyp = vc[i].getCustomer();
			ph1_ptr = dummyp->ph_no.data();
			//as in dummy ptr phno is stored in vector it cannot be accessed directly 
			//so use a LLinteger pointer that points to data stored at that ptr location

			if (*ph1_ptr == ph)
			{
				flag = 1;
				string upName;
				cout << "\nMatch Found";

				vc[i].DisplayCustomer();

				cout << "\nEnter updated name : ";
				cin >> upName;
				//dummyp->name = upName;
				p1->name = upName;
				cout << "\nName Updated Successfully" << endl;
				vc[i].DisplayCustomer();
				break;
			}
		}
		if (flag == 0)
		{
			cout << "\nNo match found";
		}
	}
	else
	{
		cout << "\nInvalid Choice";
	}
}



PhoneBook* Customer::getCustomer()
{
	PhoneBook *p;
	p = new PhoneBook;
	p->name = p1->name;
	p->ph_no = p1->ph_no;
	return p;
}