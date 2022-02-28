#include <iostream>
#include <string>

class Employee{
    std::string name;
    int age;

    std::string position; // 직책
    int rank; // 순위

public:
    Employee(std::string name, int age, std::string position, int rank) : name(name), age(age), position(position), rank(rank) {}
    Employee(const Employee& employee){
        name = employee.name;
        age = employee.age;
        position = employee.position;
        rank = employee.rank;
    }
    Employee() {}

    void print_info(){
        std::cout << name << " (" << position << ", " << age << ") ==> " << calculate_pay() << "0000won" << std::endl;
    }
    int calculate_pay() {return 200 + rank * 50;}
};
class Manager {
    std::string name;
    int age;

    std::string position; // 직책
    int rank; // 순위
    int year_of_service; // 근속년수
public:
    Manager(std::string name, int age, std::string position, int rank, int year_of_service) 
    : year_of_service(year_of_service), name(name), age(age), position(position), rank(rank) {}
    Manager(const Manager& manager){
        name = manager.name;
        age = manager.age;
        position = manager.position;
        rank = manager.rank;
        year_of_service = manager.year_of_service;
    }
    Manager(){}
    int calculate_pay() {return 200 + rank * 50 + 5 * year_of_service;}
    void print_info(){
        std::cout << name << " (" << position << ", " << age << ") ==> " << calculate_pay() << "0000won" << std::endl;
    }
};
class EmployeeList {
    int alloc_employee; // 할당한 총 직원 수
    int current_employee; // 현재 직원 수
    int current_manager; // 현재 매니저 수

    Employee** employee_list; // 직원 데이터
    Manager** manager_list; // 매니저 데이터

public:
    EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
        employee_list = new Employee*[alloc_employee];
        manager_list = new Manager*[alloc_employee];

        current_employee = 0;
        current_manager = 0;
    }
    void add_employee(Employee* employee){
        // current_employee보다 alloc_employee가 더 많아지는 경우 반드시 재할당을 해야 하나
        // 단순하게 alloc_employee > current_employee라 생각
        employee_list[current_employee] = employee;
        current_employee++;
    }
    void add_manager(Manager* manager){
        manager_list[current_manager] = manager;
        current_manager++;
    }
    int current_employee_num() {return current_employee;}

    void print_employee_info(){
        int total_pay = 0;
        for (int i=0;i<current_employee;i++){
            employee_list[i]->print_info();
            total_pay += employee_list[i]->calculate_pay();
        }
        for (int i=0;i<current_manager;i++){
            manager_list[i]->print_info();
            total_pay += manager_list[i]->calculate_pay();
        }

        std::cout << "Pay : " << total_pay << "0000 won" << std::endl;
    }
    ~EmployeeList(){
        for (int i=0;i<current_employee;i++)
            delete employee_list[i];
        for (int i=0;i<current_manager;i++)
            delete manager_list[i];
        
        delete[] employee_list;
        delete[] manager_list;
    }
};

int main(){
    EmployeeList emp_list(10);
    emp_list.add_employee(new Employee("Ahn", 34, "B", 1));
    emp_list.add_employee(new Employee("Kim", 34, "C", 1));

    emp_list.add_manager(new Manager("Yun", 47, "A", 5, 16));
    emp_list.add_employee(new Employee("Park", 26, "D", 0));
    emp_list.print_employee_info();
    return 0;
}