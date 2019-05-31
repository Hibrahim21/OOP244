/*
Name: Hamza Ibrahim
Seneca email: hibrahim21@myseneca.ca
Seneca ID: 107467185
*/

#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H
#include <iostream>

namespace ama {

	class ErrorState {
		char * e_message;

	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& other) = delete;
		ErrorState& operator=(const ErrorState& other) = delete;
		~ErrorState();
		operator bool() const;
		ErrorState& operator=(const char* pText);
		void message(const char* pText);
		const char* message() const;
	};

	std::ostream& operator<<(std::ostream&, const ErrorState&);

}

#endif // !AMA_ERRORSTATE_H
