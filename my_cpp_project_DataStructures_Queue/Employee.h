#pragma once
#include <iostream> 
#include <vector> 
#include <string> 
#include <algorithm> 
using namespace std;

enum class Level { //დეველოპერს, ინჟინერსა და ტესტერს აქვთ საკუთარი კვალიფიკაციიs დონის განმსაზღვრელი კატეგორია, სამიდან ერთ - ერთი: 
	//1. Senior 2. Middle 3. Junior 
	Junior, Middle, Senior
};

enum class EmployeeClass {
	// CIO – “CIO”, Project Manager – “PM”, Backend Developer -“BD”, Frontend Developer – “FD”, Database Engineer – “DB”, DevOps Engineer –“DE”, Tester – “TST” 
	Unknown, CIO, PM, BD, FD, DB, DE, TST,
};

enum class BackendTechnology {//დამატებითი ველი, რომელიც განსაზღვრავს იმ ტექნოლოგიას, რომელსაც Backend Developer იყენებს 
	Spring, Django, DotNet
};

enum class FrontendTechnology {//დამატებითი ველი, რომელიც განსაზღვრავს იმ ტექნოლოგიას, რომელსაც Frontend Developer იყენებს 
	Angular, React, Vue
};

template <typename EnumType>
//es khazi gansazghvravs punktsias, romelits ighebs enum t’ip’is p’aramet’rs da gardakmnis am enum mnishvnelobas st’rikonad shablonis gamoq’enebit. 
std::string enumToString(EnumType value) {
	//es amots’mebs aris tu ara p’aramet’rad aghebuli enum t’ip’i igive Level enum t’ip’is.gamoq’eneba 'constexpr if' apasebs am mdgomareobas k’omp’ilatsiis dros.   
	if constexpr (std::is_same<EnumType, Level>::value) {
		switch (value) {
		case EnumType::Junior:return "Junior";
		case EnumType::Middle:return "Middle";
		case EnumType::Senior:return "Senior";
		default: return "Unknown";
		}
	}
	//is amots’mebs aris tu ara p’aramet’rad aghebuli enum t’ip’i igive EmployeeClass enum t’ip’is.gamoq’eneba constexpr if apasebs am mdgomareobas k’omp’ilatsiis dros. 
	else if constexpr (std::is_same<EnumType, EmployeeClass>::value) {
		switch (value) {
		case EnumType::CIO: return "CIO";
		case EnumType::PM:return "PM";
		case EnumType::BD:return "BD";
		case EnumType::FD:return "FD";
		case EnumType::DB:return "DB";
		case EnumType::DE:return "DE";
		case EnumType::TST: return "TST";
		default:return "Unknown";
		}
	}
	//is amots’mebs aris tu ara p’aramet’rad aghebuli enum t’ip’i igive BackendTechnology enum t’ip’is. gamoq’eneba constexpr if apasebs am mdgomareobas k’omp’ilatsiis dros. 
	else if constexpr (std::is_same<EnumType, BackendTechnology>::value) {
		switch (value) {
		case EnumType::Spring:return "Spring";
		case EnumType::Django:return "Django";
		case EnumType::DotNet:return "DotNet";
		default:return "Unknown";
		}
	}
	//is amots’mebs aris tu ara p’aramet’rad aghebuli enum t’ip’i igive FrontendTechnology enum t’ip’is. gamoq’eneba constexpr if apasebs am mdgomareobas k’omp’ilatsiis dros. 
	else if constexpr (std::is_same<EnumType, FrontendTechnology>::value) {
		switch (value) {
		case EnumType::Angular: return "Angular";
		case EnumType::React: return "React";
		case EnumType::Vue: return "Vue";
		default: return "Unknown";
		}
	}
	else {
		return "Unknown";
	}
}

class Technology {//rata Developer klasshi iyos Tecnology-is veli da shvili klasebi mas gamigenos 
public:
	BackendTechnology backendTech;
	FrontendTechnology frontendTech;
	//tu obiekti aris backendeveloperi da parametrad anijebs mxolod backend teknologiebs (BackendTechnology enumidan) 
	Technology(BackendTechnology backend = BackendTechnology::Spring) :
		backendTech(backend) {}
	//tu obiekti aris frontend developeri da parametrad anijebs mxolod frontend teknologiebs (BackendTechnology enumidan) 
	Technology(FrontendTechnology frontend = FrontendTechnology::React)
		:frontendTech(frontend) {}
};

static vector<string>UsersIds; //rata shevamocmot aris tu ara axali obiektis id uniqaluri, mis cina obiektebis id-ebi unda shevinaxot vektorshi 


class Employee {
protected:
	string name;
	string identificationNumber;
	EmployeeClass employeeClass;
	double salary;
	int experienceMonths;

public:
	Employee(string name = "unknown", string identificationNumber = "Not Entered",//konstruktori 
		EmployeeClass employeeClass = EmployeeClass::Unknown, int experienceMonths = 0)
		: name(name),
		identificationNumber(identificationNumber),
		employeeClass(employeeClass),
		experienceMonths(experienceMonths) {
		countSalary();//klasisi shemosavlis vels sheavsevs. poziciis da stajis mixedvit. zoq klasshi gatvaliswinebulia kvalipikaciac 
		if (!identificationNumber.empty()) {//tu carieli ar aris daamate. vici rom naqulisxmevic itvleba 
			UsersIds.push_back(identificationNumber);//daamade vektorshi 
		}
	}

	~Employee() {}//destruktori 
	double getSalary() const {//shemosavlis velis getter funkcia 
		return salary;
	}
	virtual void showInfo();//abstrakt begdvis funkcia 
	void virtual countSalary();//shemosavalis gamotvlis funkcia 
	double controlClass(EmployeeClass x);//poziciis kontroli 
	double controlExperience(int x);//stajis shesamocmebeli funkcia 
	void virtual makeAbstract() = 0; //abstract funkcia 
};

class Tester : public Employee {
private:
	Level level;//kvalipikaciis donis gansazgvreli funkcia 

public:
	Tester(string name, string identificationNumber, EmployeeClass employeeClass, int experienceMonths, Level level)//konstruktori 
		: Employee(name, identificationNumber, employeeClass, experienceMonths), level(level) {
		countSalary();//hemosavlis gamotvlis funkcia poziciis, kvalipikaciis da stajis gatvaliscinebit 
	}
	void countSalary();
	double controlLevel();
	void showInfo() override;//begdvis funkcia 
	void makeAbstract() {}
};

class Developer : public Employee {
protected:
	Level level;
	Technology* teknolgiya;//developeris mier gomogenebuli teknologia 

public:
	Developer(string name, string identificationNumber, EmployeeClass employeeClass, int experienceMonths, Level level, Technology* teknolgiya)
		: Employee(name, identificationNumber, employeeClass, experienceMonths), level(level), teknolgiya(teknolgiya) {
		countSalary();
	}

	void virtual showInfo() override;
	void countSalary();
	double controlLevel();
	void makeAbstract() {}
	void virtual makeAbstractDeveloper() = 0;
};

class FrontendDeveloper : public Developer {
public:
	FrontendDeveloper(string name, string identificationNumber, EmployeeClass employeeClass,//konstruktor 
		int experienceMonths, Level level, Technology* technology)
		: Developer(name, identificationNumber, employeeClass, experienceMonths, level, technology) {}

	void showInfo() override;
	void makeAbstractDeveloper() {}
};

class BackendDeveloper : public Developer {
public:
	BackendDeveloper(string name, string identificationNumber, EmployeeClass employeeClass,
		int experienceMonths, Level level, Technology* technology)
		: Developer(name, identificationNumber, employeeClass, experienceMonths, level, technology) {}
	void showInfo() override;
	void makeAbstractDeveloper() {}
};

class CIO : public Employee {
public:
	CIO(string name, string identificationNumber, EmployeeClass employeeClass, int experienceMonths)
		: Employee(name, identificationNumber, employeeClass, experienceMonths) {}
	void showInfo();
	void countSalary();
	void makeAbstract() {}
};

class Engineer : public Employee {
protected:
	Level level;

public:
	Engineer(string name, string identificationNumber, EmployeeClass employeeClass, int experienceMonths, Level level)
		: Employee(name, identificationNumber, employeeClass, experienceMonths), level(level) {
		countSalary();
	}
	void countSalary();
	double controlLevel();
	void virtual showInfo() override;
	void makeAbstract() {}
	void virtual makeAbstractEngineer() = 0;
};

class DevOpsEngineer : public Engineer {
public:
	DevOpsEngineer(string name, string identificationNumber, EmployeeClass employeeClass, int experienceMonths, Level level)
		: Engineer(name, identificationNumber, employeeClass, experienceMonths, level) {}
	void showInfo() { Engineer::showInfo(); }
	void makeAbstractEngineer() {}
};

class DatabaseEngineer : public Engineer {
public:
	DatabaseEngineer(string name, string identificationNumber, EmployeeClass employeeClass, int experienceMonths, Level level)
		: Engineer(name, identificationNumber, employeeClass, experienceMonths, level) {}
	void showInfo() { Engineer::showInfo(); }
	void makeAbstractEngineer() {}
};

class ProjectManager : public Employee {
public:
	ProjectManager(string name, string identificationNumber, EmployeeClass employeeClass, int experienceMonths)
		: Employee(name, identificationNumber, employeeClass, experienceMonths) {}
	void showInfo();
	void countSalary();
	void makeAbstract() {}
};

class EmployeePriorityQueue {
private:
	static const int MAX_SIZE = 100;
	Employee* employees[MAX_SIZE];
	int size;

public:
	EmployeePriorityQueue() : size(0) {}
	~EmployeePriorityQueue() {}
	EmployeePriorityQueue& operator=(const EmployeePriorityQueue& other);//minigebis operatori 

	//(copy constructor) 
	EmployeePriorityQueue(const EmployeePriorityQueue& other);
	void push(Employee* emp);//elementis damadebis funkcia 
	Employee* pop();//elementis amoshli funqcia 
	void printQueue() const;//begdvis funkcia 
};


bool isUnique(const std::string&);//funkcia romelic sheamocmebs aris tu ara id rodesme gamogenebuli 

bool isElevenDigitNumber(const std::string&);
std::string getUniqueID();
Employee* createEmployee();//axali obiektis shekmnis funkcia 
void correctLevel(Level& level); //momxmarebelma level velis shevsebistvis unda sheigvanos scori monacemi 
Technology* getTechnology(bool isBackend);//momxmarebelma technology  velis shevsebistvis unda sheigvanos scori monacemi 

