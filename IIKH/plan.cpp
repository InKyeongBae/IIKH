#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "plan.h"

PlanDB::PlanDB() {
	enum {};
	ifstream planDB;
	planDB.open("planDB.txt");

	if (planDB.is_open()) {
		stringstream stream;
		string parse;
		for (string tuple; getline(planDB, tuple);) {
			stream.str(tuple);
			vector<string> split_data;
			while (stream >> parse) {
				split_data.push_back(parse);
			};
			//Construct Plan
			cout << split_data[0] << split_data[1] << split_data[2] << split_data[3];
		}
	}
}