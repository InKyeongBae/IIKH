#pragma once
#include <iostream>
using namespace::std;

class Greeter {
private:
	int option_choice = 0;

public:
	Greeter();
	void print_greeting();
	int select_start_option();
};