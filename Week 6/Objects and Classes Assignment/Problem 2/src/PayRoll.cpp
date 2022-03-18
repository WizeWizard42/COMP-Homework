#include <string>
#include <iostream>

#include "include/PayRoll.h" // Header file is in "include" subdirectory

int PayRoll::nextID = 1;

PayRoll::PayRoll()
{
    employeeID = nextID;
    employeeName = "John Doe";

    hourlyPay = -1; // -1 signals pay/hours haven't been set.
    hoursPerWeek = -1;
    weeklyPay = hourlyPay * hoursPerWeek;

    nextID++;
}
PayRoll::PayRoll(const std::string& employeeName, const int hourlyPay, const int hoursPerWeek)
{
    employeeID = nextID;
    this->employeeName = employeeName;

    this->hourlyPay = hourlyPay;
    this->hoursPerWeek = hoursPerWeek;
    weeklyPay = this->hourlyPay * this->hoursPerWeek;

    nextID++;
}

int PayRoll::GetNextID() const
{
    return nextID;
}

int PayRoll::GetEmployeeID() const
{
    return employeeID;
}

std::string PayRoll::GetEmployeeName() const
{
    return employeeName;
}
void PayRoll::SetEmployeeName(const std::string& employeeName)
{
    this->employeeName = employeeName;
}

int PayRoll::GetHourlyPay() const
{
    return hourlyPay;
}
void PayRoll::SetHourlyPay(const int hourlyPay)
{
    this->hourlyPay = hourlyPay;
    UpdateWeeklyPay();
}

int PayRoll::GetHoursPerWeek() const
{
    return hoursPerWeek;
}
void PayRoll::SetHoursPerWeek(const int hoursPerWeek)
{
    if (hoursPerWeek > 60)
    {
        std::cout << "Error: Too many hours per week. Please input 60 hours or less." << std::endl;
        return;
    }
    this->hoursPerWeek = hoursPerWeek;
    UpdateWeeklyPay();
}

int PayRoll::GetWeeklyPay() const
{
    return weeklyPay;
}
void PayRoll::UpdateWeeklyPay()
{
    weeklyPay = hourlyPay * hoursPerWeek;
}
