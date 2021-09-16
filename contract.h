/*
	Contract - a small contract support header
	Author: MrFranQx

	How to use:
	1. #include this header
	2. Optionally set default_action
	3. Use expects() at the beginning of the function to check its arguments
	   and/or ensures() at the end of the function to check the return value

	How it works:
	It either throws an exception or terminates the program, based on default_action.
	expects() and ensures() is the same except of the message;
	they have to be separate functions to express they intent more clearly.

	More info in README.md
*/

#pragma once

#ifndef CONTRACT_H
#define CONTRACT_H

#include <stdexcept>
#include <exception>

namespace Contract {
	enum class Action {
		exception = 0,
		terminate = 1
	};
	// exception thrown when contract is violated
	class Contract_violation : public std::logic_error { using std::logic_error::logic_error; };
	
	Action default_action = Action::exception;

	void expects(bool expr) // expresses argument expectations
	{
		if (!expr) {
			if (default_action == Action::exception)
				throw Contract_violation("Preconditions violated");
			else if (default_action == Action::terminate)
				std::terminate();
			else
				throw std::logic_error("Contract check handle failed");
		}
	}
	
	void ensures(bool expr) // expresses return value assurance
	{
		if (!expr) {
			if (default_action == Action::exception)
				throw Contract_violation("Postconditions violated");
			else if (default_action == Action::terminate)
				std::terminate();
			else
				throw std::logic_error("Contract check handle failed");
		}
	}
}

#endif // CONTRACT_H