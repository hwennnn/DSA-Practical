#include<string>
#include<iostream>

using namespace std;
#include "Employee.h"

// command to compile in g++
// g++ --std=c++17 *.cpp -o ./output.out && ./output.out
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   

    Employee e1("William","Lin", 1000);
    Employee e2("Elon","Musk", 2000);

    cout << e1.getYearlySalary() << " " << e2.getYearlySalary() << endl;

    e1.setMonthlySalary(e1.getMonthlySalary()*1.1);
    e2.setMonthlySalary(e2.getMonthlySalary()*1.1);

    cout << e1.getYearlySalary() << " " << e2.getYearlySalary() << endl;

    return 0;
}
