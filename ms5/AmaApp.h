/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/

#ifndef AMA_AMAAPP_H
#define AMA_AMAAPP_H
//#include "iProduct.h"
#include "Product.h"
#include "Utilities.h"
#include "Perishable.h"
#include "Sort.cpp"

namespace ama {

	class AmaApp {

		char m_filename[256];
		iProduct* m_products[100];
		int m_noOfProducts;

		AmaApp(const AmaApp&) = delete;
		AmaApp& operator=(const AmaApp&) = delete;

		void pause() const; // COMPLETE
		int menu() const; // COMPLETE
		void loadProductRecords(); // COMPLETE
		void saveProductRecords() const; // COMPLETE
		void listProducts() const; // COMPLETE
		iProduct* find(const char* sku) const; // COMPLETE
		void addQty(iProduct* product); // COMPLETE
		void addProduct(char tag); // COMPLETE

	public:

		AmaApp(const char*); // COMPLETE
		~AmaApp(); // COMPLETE
		int run(); // COMPLETE
	};
}
#endif // !AMA_AMAAPP_H
