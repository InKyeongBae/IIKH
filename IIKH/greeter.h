#pragma once
#include <iostream>
using namespace::std;

class Greeter {
public:
	Greeter();
private:
	int choice;
	void print_greeting();
	int select_start_option();

};