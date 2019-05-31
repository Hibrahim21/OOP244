#include "CellPhone.h"
#include <iostream>
using namespace std;

void sict::display(const CellPhone &phone)
{
	cout << "Phone " << phone.m_model << " costs $" << phone.m_price << "!" << endl;

}
void sict::display(const CellPhone phone[], int elements)
{
	int i;
	double cheapest = phone[0].m_price;
	cout << "------------------------------" << endl;
	cout << "Phones available at the mall:" << endl;
	cout << "------------------------------" << endl;
	for (i = 0; i < elements; i++)
	{
		cout << i + 1 << ". ";
		display(phone[i]);
	}
	cout << "------------------------------" << endl;

	for (i = 0; i < elements; i++)
	{
		if (phone[i].m_price < cheapest)
		{
			cheapest = phone[i].m_price;
		}
	}
	cout << "The cheapest phone costs $" << cheapest << "." << endl;
	cout << "------------------------------" << endl;
}
