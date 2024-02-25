#include "Employee.h"
#include <iostream> 
#include <string> 
#include <vector> 
#include<algorithm> 
using namespace std;
void Employee::showInfo() {
	std::cout << "\nEmployee data:\n";
	std::cout << "Name: " << name << "\nIdentification Number: " << identificationNumber << "\nEmployee Class: "
		<< enumToString(employeeClass) << "\nSalary: " << salary << "\nExperience Months: " << experienceMonths << endl;
}
void Employee::countSalary() {
	if (name != "unknown", identificationNumber != "Not Entered", employeeClass != EmployeeClass::Unknown) {
		salary = controlClass(employeeClass) + controlExperience(experienceMonths);

	}
}
double Employee::controlClass(EmployeeClass x) {//poziciis mixedvit daabrunebs gansxvavebul tanxas 
	if (x == EmployeeClass::CIO) {
		return 9000;
	}
	else if (x == EmployeeClass::PM) {
		return 5500;
	}
	else if (x == EmployeeClass::TST) {
		return 4000;
	}
	else {
		return 3000;
	}
}
double Employee::controlExperience(int x) {//stajis mixedvit daabrunebs gansxvavebul tanxas 
	if (x < 6) {
		return 0;
	}
	if (x >= 6 && x < 12) {
		return 400;
	}
	if (x >= 12) {
		return 700;
	}
}
void Tester::countSalary() {//gamotvlis shemosavals 
	if (name != "unknown", identificationNumber != "Not Entered", employeeClass != EmployeeClass::Unknown && level != Level::Junior) {
		salary = controlClass(employeeClass) + controlExperience(experienceMonths) + controlLevel();//gatvaliscinebulia kvalipikaciac 
	}
}

double Tester::controlLevel() {//kvalipikaciis mixedvit daabrunebs gansxvavebul tanxas 
	if (level == Level::Senior) {
		return 1000;
	}
	else if (level == Level::Middle) {
		return 500;
	}
	else { return 0; }
}
void Tester::showInfo() {//begdvis funkcia 
	Employee::showInfo();
	cout << "Level: " << enumToString(level) << endl;//begdavs kvalipikaciasac 
}
void Developer::showInfo() {
	Employee::showInfo();
	cout << "Level: " << enumToString(level) << endl;
}
void Developer::countSalary() {
	if (name != "unknown", identificationNumber != "Not Entered", employeeClass != EmployeeClass::Unknown && level != Level::Junior) {
		salary = controlClass(employeeClass) + controlExperience(experienceMonths) + controlLevel();
	}
}
double Developer::controlLevel() {
	if (level == Level::Senior) {
		return 1000;
	}
	else if (level == Level::Middle) {
		return 500;
	}
	else { return 0; }
}
void FrontendDeveloper::showInfo() {
	Developer::showInfo();
	cout << "Used Technology: " << enumToString(teknolgiya->frontendTech) << endl;
}
void BackendDeveloper::showInfo() {
	Developer::showInfo();
	cout << "Used Technology: " << enumToString(teknolgiya->frontendTech) << endl;
}
void CIO::showInfo() {
	Employee::showInfo();
}
void CIO::countSalary() {
	Employee::countSalary();
}
void Engineer::countSalary() {
	//tu klasis velebi nakulisxmevi mnishvnelobei ar aris 
	if (name != "unknown", identificationNumber != "Not Entered", employeeClass != EmployeeClass::Unknown && level != Level::Junior) {
		salary = controlClass(employeeClass) + controlExperience(experienceMonths) + controlLevel();
	}
}
double Engineer::controlLevel() {
	if (level == Level::Senior) {
		return 1000;
	}
	else if (level == Level::Middle) {
		return 500;
	}
	else { return 0; }
}
void Engineer::showInfo() {
	Employee::showInfo();
	cout << "Level: " << enumToString(level) << endl;
}
void ProjectManager::showInfo() {
	Employee::showInfo();
}
void ProjectManager::countSalary() {
	Employee::countSalary();
}
EmployeePriorityQueue& EmployeePriorityQueue::operator=(const EmployeePriorityQueue& other) {//minigebis operatori 
	if (this != &other) {
		size = other.size;
		std::copy(other.employees, other.employees + size, employees);//kopireba otheridan chvens obieetshi 
	}
	cout << "\n= operator is work! " << endl;
	return *this;//daabrune obiekti 
}
EmployeePriorityQueue::EmployeePriorityQueue(const EmployeePriorityQueue& other) : size(other.size) {//copy konstruktori 
	std::copy(other.employees, other.employees + size, employees);
	cout << "\nCopy constructo is work! " << endl;
}
void EmployeePriorityQueue::push(Employee* emp) {//damadebis funkcia 
	if (size == MAX_SIZE) {
		std::cout << "Priority Queue is full. Cannot add more employees.\n";
		return;
	}
	employees[size++] = emp;
	std::sort(employees, employees + size, [](const Employee* a, const Employee* b) {//shemosavalis mixedvit daasortavs, prioriti aris bevri shemosavali 
		return a->getSalary() > b->getSalary();
		});
}
void EmployeePriorityQueue::printQueue() const {//begdvis funkcia 
	for (int i = 0; i < size; ++i) {
		employees[i]->showInfo();
		std::cout << "------------------------\n";
	}
}

Employee* EmployeePriorityQueue::pop() {//amoshlis funkcia 
	if (size == 0) {
		return nullptr;
	}
	Employee* topEmployee = employees[0]; // dasackishi index0 elementi aighe 

	// miachoche marcxvniv 
	for (int i = 0; i < size - 1; ++i) {
		employees[i] = employees[i + 1];
	}

	//gaatavisuple 
	employees[size - 1] = nullptr;

	--size; // Boyutu azalt 
	return topEmployee;
}

bool isUnique(const std::string& newId) {//aris tu ara id rodesme gamogenebuli 
	return std::find(UsersIds.begin(), UsersIds.end(), newId) == UsersIds.end();
}

bool isElevenDigitNumber(const std::string& id) {//sheicavs 11 ricxvs 
	return id.size() == 11 && std::all_of(id.begin(), id.end(), ::isdigit);
}
std::string getUniqueID() {//momxmareblidan uniqaluri id-s migebaze uzrunvelgops 
	std::string userInput;
	do {
		std::cout << "Please enter an 11-digit number for the ID: ";
		std::cin >> userInput;

		if (!isUnique(userInput) || !isElevenDigitNumber(userInput)) {
			if (!isUnique(userInput)) {
				cout << "Plese eter unique id, this id already taken: " << endl;
			}
			std::cout << "Please enter an 11 - digit number, and make sure it contains only digits(no letters)!\n ";

		}
		else {
			std::cout << "Unique id saved." << std::endl;
			UsersIds.push_back(userInput);//tu uniqaluria id-ebshi daamade 
			break;
		}
	} while (true);

	return userInput;
}
void correctLevel(Level& level) {//konsolidan momxmareblis scor monacebis shetanaze uzrunvegops 
	std::string levelStr;
	std::string validValues[] = { "JUNIOR", "MIDDLE", "SENIOR" };
	bool isValid = false;

	while (!isValid) {
		std::cout << "Enter level (JUNIOR, MIDDLE, SENIOR): ";
		std::cin >> levelStr;

		// Convert string to uppercase for case-insensitive comparison 
		std::transform(levelStr.begin(), levelStr.end(), levelStr.begin(), ::toupper);//stringis enumshi tranformireba 

		// Check if the entered value is in the validValues array 
		if (std::find(std::begin(validValues), std::end(validValues), levelStr) != std::end(validValues)) {
			isValid = true;
		}
		else {
			std::cout << "Invalid input. Please enter a valid level.\n";
		}
	}

	// Convert string to Level enum 
	if (levelStr == "JUNIOR") {
		level = Level::Junior;
	}
	else if (levelStr == "MIDDLE") {
		level = Level::Middle;
	}
	else if (levelStr == "SENIOR") {
		level = Level::Senior;
	}
	else {
		std::cout << "Invalid level. Defaulting to Junior.\n";
		level = Level::Junior;
	}
}
Technology* getTechnology(bool isBackend) {
	if (isBackend) {
		std::cout << "Enter backend technology (Spring, Django, DotNet): ";
		std::string backendStr;
		std::cin >> backendStr;

		// Convert string to BackendTechnology enum 
		transform(backendStr.begin(), backendStr.end(), backendStr.begin(), ::toupper);

		BackendTechnology backend;
		if (backendStr == "SPRING") {
			backend = BackendTechnology::Spring;
		}
		else if (backendStr == "DJANGO") {
			backend = BackendTechnology::Django;
		}
		else if (backendStr == "DOTNET") {
			backend = BackendTechnology::DotNet;
		}
		else {
			std::cout << "Invalid backend technology. Defaulting to Spring.\n";
			backend = BackendTechnology::Spring;
		}

		return new Technology(backend);
	}
	else {
		std::cout << "Enter frontend technology (Angular, React, Vue): ";
		std::string frontendStr;
		std::cin >> frontendStr;

		// Convert string to FrontendTechnology enum 
		transform(frontendStr.begin(), frontendStr.end(), frontendStr.begin(), ::toupper);

		FrontendTechnology frontend;
		if (frontendStr == "ANGULAR") {
			frontend = FrontendTechnology::Angular;
		}
		else if (frontendStr == "REACT") {
			frontend = FrontendTechnology::React;
		}
		else if (frontendStr == "VUE") {
			frontend = FrontendTechnology::Vue;
		}
		else {
			std::cout << "Invalid frontend technology. Defaulting to React.\n";
			frontend = FrontendTechnology::React;
		}

		return new Technology(frontend);
	}
}
Employee* createEmployee() {
	std::string name, id, employeeClassStr;
	int experienceMonths;
	EmployeeClass employeeClass;
	Level level;

	std::cout << "Enter employee name: ";
	std::cin >> name;

	id = getUniqueID();

	std::cout << "Enter experience months: ";
	std::cin >> experienceMonths;

	std::string validValues[] = { "CIO", "PM", "BD", "FD", "DB", "DE", "TST" };
	bool isValid = false;

	while (!isValid) {
		std::cout << "Enter employee class (CIO, PM, BD, FD, DB, DE, TST): ";
		std::cin >> employeeClassStr;

		// Convert string to uppercase for case-insensitive comparison 
		std::transform(employeeClassStr.begin(), employeeClassStr.end(), employeeClassStr.begin(), ::toupper);

		// Check if the entered value is in the validValues array 
		if (std::find(std::begin(validValues), std::end(validValues), employeeClassStr) != std::end(validValues)) {
			isValid = true;
		}
		else {
			std::cout << "Invalid input. Please enter a valid employee class.\n";
		}
	}

	// Convert string to EmployeeClass enum 
	if (employeeClassStr == "CIO") {
		employeeClass = EmployeeClass::CIO;
	}
	else if (employeeClassStr == "PM") {
		employeeClass = EmployeeClass::PM;
	}
	else if (employeeClassStr == "BD") {
		employeeClass = EmployeeClass::BD;
	}
	else if (employeeClassStr == "FD") {
		employeeClass = EmployeeClass::FD;
	}
	else if (employeeClassStr == "DB") {
		employeeClass = EmployeeClass::DB;
	}
	else if (employeeClassStr == "DE") {
		employeeClass = EmployeeClass::DE;
	}
	else if (employeeClassStr == "TST") {
		employeeClass = EmployeeClass::TST;
	}
	else {
		std::cout << "Invalid employee class. Defaulting to Unknown.\n";
		employeeClass = EmployeeClass::Unknown;
	}

	// tu kvalipikaciis veli velis mkone obiektebia(anu tu arkeulia TST, DB, DE, BD, FD 
	if (employeeClass == EmployeeClass::TST || employeeClass == EmployeeClass::DB || employeeClass == EmployeeClass::DE || employeeClass == EmployeeClass::BD || employeeClass == EmployeeClass::FD) {
		correctLevel(level);
		// Create and return the corresponding object 
		if (employeeClass == EmployeeClass::TST) {
			return new Tester(name, id, employeeClass, experienceMonths, level);
		}
		if (employeeClass == EmployeeClass::DB) {
			return new DatabaseEngineer(name, id, employeeClass, experienceMonths, level);
		}
		if (employeeClass == EmployeeClass::DE) {
			return new DevOpsEngineer(name, id, employeeClass, experienceMonths, level);
		}
		if (employeeClass == EmployeeClass::BD || employeeClass == EmployeeClass::FD) {
			bool isBackend = (employeeClass == EmployeeClass::BD);
			Technology* technology = getTechnology(isBackend);

			if (employeeClass == EmployeeClass::BD) {
				return new BackendDeveloper(name, id, employeeClass, experienceMonths, level, technology);
			}
			else {
				return new FrontendDeveloper(name, id, employeeClass, experienceMonths, level, technology);
			}
		}
	}

	return new CIO(name, id, employeeClass, experienceMonths);
}
