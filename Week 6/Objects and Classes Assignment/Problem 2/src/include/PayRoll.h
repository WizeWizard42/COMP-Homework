#ifndef PAYROLL_H
#define PAYROLL_H

#include <string>

class PayRoll
{
    public:
        PayRoll();
        PayRoll(const std::string& employeeName, const int hourlyPay, const int hoursPerWeek);

        int GetNextID() const;

        int GetEmployeeID() const;

        std::string GetEmployeeName() const;
        void SetEmployeeName(const std::string& employeeName);

        int GetHourlyPay() const;
        void SetHourlyPay(const int hourlyPay);

        int GetHoursPerWeek() const;
        void SetHoursPerWeek(const int hoursPerWeek);

        int GetWeeklyPay() const;
        // Calculates weekly pay by multiplying hourlyPay and hoursPerWeek.
        void UpdateWeeklyPay();

    private:
        int employeeID;
        std::string employeeName;

        int hourlyPay;
        int hoursPerWeek;
        int weeklyPay;

        // Next available employee ID, used in construction.
        static int nextID;
};

#endif // PAYROLL_H