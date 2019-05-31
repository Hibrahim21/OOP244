#ifndef CELLPHONE_H
#define CELLPHONE_H
namespace sict {

	struct CellPhone {

		char m_model[32];
		double m_price;

	};

	void display(const CellPhone &phone);
	void display(const CellPhone[], int elements);
}
#endif
