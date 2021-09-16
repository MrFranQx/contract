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
	class Contract_violation : public std::logic_error { using std::logic_error::logic_error; };
	Action default_action = Action::exception;
	void expects(bool expr)
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
	void ensures(bool expr)
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