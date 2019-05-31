/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/

#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H
#include "Product.h"
#include "Date.h"
namespace ama {

	class Perishable : public Product {

		Date m_Expdate;

	public:
		Perishable(char = 'P');// : Product('P') { m_Expdate = Date(); }
		ostream& write(ostream& out, int writeMode) const;
		istream& read(istream& in, bool interractive);

	};
}
#endif // !AMA_PERISHABLE_H
