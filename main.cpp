#include <stdio.h>
#include <Windows.h>
#include <list>
#include <algorithm>
#include <fstream>
#include <cassert>
#include <iostream>
#include <sstream>



struct StudentAccount {
	std::string Name;
	std::string gradeNumber;
	std::string attendanceNumber;
};

int main() {

	SetConsoleOutputCP(65001);
	std::list<StudentAccount> studentAccounts;

	std::ifstream inputFile("PG3_05_02.txt");

	assert(inputFile.is_open());



	std::string line;

	while (getline(inputFile, line)) {

		std::istringstream lineStream(line);

		std::string account;

		while (getline(lineStream, account, ',')) 
		{
			StudentAccount studentAccount{};
			studentAccount.Name = account;

			std::string gradeNumber = account.substr(2, 3);
			std::string attendanceNumber = account.substr(6, 4);

			studentAccount.gradeNumber = gradeNumber.c_str();
			studentAccount.attendanceNumber = attendanceNumber.c_str();
			studentAccounts.emplace_back(studentAccount);
		}

	}

	inputFile.close();

	studentAccounts.sort([](const StudentAccount& a, const StudentAccount& b)
		{
			return std::atoi((a.gradeNumber + a.attendanceNumber).c_str()) < std::atoi((b.gradeNumber + b.attendanceNumber).c_str());

		});

	for (auto& accountName : studentAccounts) {
		std::cout << accountName.Name << std::endl;
	}







	return 0;
}