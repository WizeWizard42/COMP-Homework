#include "include/Calculator.h"

Calculator::Calculator()
{
    value = 0.0;
}

void Calculator::Add(const double val)
{
    value += val;
}

void Calculator::Subtract(const double val)
{
    value -= val;
}

void Calculator::Multiply(const double val)
{
    value *= val;
}

void Calculator::Divide(const double val)
{
    value /= val;
}

void Calculator::Clear()
{
    value = 0.0;
}

double Calculator::GetValue() const
{
    return value;
}
