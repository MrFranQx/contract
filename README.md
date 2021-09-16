# Contract

Because a support for contracts is missing in C++, I have written this simple header.

## Instructions
1. `#include` the header
2. (optional) set the `Contract::Action` to either `exception` (default) or `terminate`
3. Use one or both of the contracts:
    - `Contract::expects()` at the beginning of the function to check the arguments
    - `Contract::ensures()` at the end of the function to check the return value

By default, if a contract is violated, it throws a `Contract_violation` exception (derivative of `std::logic_error`),
but it can be also set to use `std::terminate()` (see step 2).

Any feedback is highly appreciated!