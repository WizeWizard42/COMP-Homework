/*
 * This program defines and implements the PayRoll class.
 * The PayRoll class stores an employee's ID, name, hourly pay and weekly hours.
 * The class also calculates and stores gross weekly pay based on hourly pay and hours worked.
 */
#include <array>
#include <iostream>
#include <string>

#include "include/PayRoll.h" // Header file is in "include" subdirectory

int main(void)
{
    std::array<PayRoll, 7> employees;

    for (PayRoll& employee : employees)
    {
        std::string currentName = "John Doe";
        int currentHourlyPay = -1;
        int currentHoursPerWeek = -1;

        std::cout << "Enter employee name:" << std::endl;
        std::getline(std::cin, currentName);
        std::cout << std::endl;
        employee.SetEmployeeName(currentName);

        std::cout << "Enter hourly pay: $" << std::flush;
        std::cin >> currentHourlyPay;
        employee.SetHourlyPay(currentHourlyPay);
        
        while (currentHoursPerWeek > 60 || currentHoursPerWeek < 0)
        {
            std::cout << "Enter hours per week: " << std::flush;
            std::cin >> currentHoursPerWeek;
            employee.SetHoursPerWeek(currentHoursPerWeek);
        }
        std::cout << std::endl;
        std::cin.ignore();
    }

    for (PayRoll& employee : employees)
    {
        std::cout << "Employee ID: " << employee.GetEmployeeID() << std::endl;
        std::cout << "Employee Name: " << employee.GetEmployeeName() << std::endl;
        std::cout << "Gross Weekly Salary: " << employee.GetWeeklyPay() << std::endl << std::endl;
    }

    return 0;
}
