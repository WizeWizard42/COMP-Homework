#ifndef CALCULATOR_H
#define CALCULATOR_H

/*
 * Basic Calculator class. Stores a value and provides methods for operations on that value.
 * Add, Subtract, Multiply, and Divide are supported.
 * The value can also be reset to 0, and there is of course a method to access the value.
 */
class Calculator
{
    public:
        Calculator();

        // Methods apply their respective operation on stored value.
        void Add(const double val);

        void Subtract(const double val);

        void Multiply(const double val);

        void Divide(const double val);

        // Sets value to 0.
        void Clear();

        // Getter for value.
        double GetValue() const;

    private:
        double value;
};

#endif // CALCULATOR_H
