/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/

#include <iostream>
#include <string.h>
#include "ErrorState.h"

using namespace std;

namespace ama {

	ErrorState::ErrorState(const char * errorMessage) {
		if (errorMessage == nullptr) {
			e_message = nullptr;

		}

		else if (errorMessage[0] == '\0') {
			e_message = nullptr;
		}

		else {
			e_message = new char[strlen(errorMessage)];
			strncpy(e_message, errorMessage, strlen(errorMessage) + 1);
		}
	}

	ErrorState::~ErrorState() {
		if (e_message != nullptr) {
			delete[] e_message;
		}
		e_message = nullptr;
	}

	ErrorState::operator bool() const {
		if (e_message != nullptr && e_message[0] != '\0') {
			return true;
		}
		else return false;
	}

	ErrorState & ErrorState::operator=(const char * pText) {
		message(pText);
		return *this;
	}

	void ErrorState::message(const char * pText) {
		if (e_message != nullptr) {
			delete[] e_message;
		}

		if (pText == nullptr || pText[0] == '\0') {
			e_message = nullptr;
		}
		else {
			if (e_message != nullptr) {
				delete[] e_message;
			}
			e_message = new char[strlen(pText) + 1];
			strncpy(e_message, pText, strlen(pText) + 1);
		}
	}

	const char * ErrorState::message() const {
		if (operator bool() != true) {
			return nullptr;
		}
		else return this->e_message;

	}

	std::ostream & operator<<(std::ostream & os, const ErrorState & idk) {
		if (bool(idk) == true) {
			os << idk.message();
		}
		return os;
	}
}