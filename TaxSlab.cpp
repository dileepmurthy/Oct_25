#include <iostream>
#include <vector>
using namespace std;

struct TaxSlab {
    double lowerLimit;
    double upperLimit;
    double rate; // e.g., 0.10 = 10%
};

class TaxCalculator {
private:
    vector<TaxSlab> slabs;

public:
    TaxCalculator() {
        // initialize slab data
        slabs = {
            {0, 1000, 0.10},
            {1000, 10000, 0.20},
            {10000, 50000, 0.30},
            {50000, 1e9, 0.40} // infinity
        };
    }

    double calculateTax(double income) {
        double tax = 0.0;

        for (auto& slab : slabs) {
            if (income > slab.lowerLimit) {
                double taxableAmount = min(income, slab.upperLimit) - slab.lowerLimit;
                tax += taxableAmount * slab.rate;

                if (income <= slab.upperLimit)
                    break; // stop once we reach the correct slab
            }
        }

        return tax;
    }
};

int main() {
    TaxCalculator calc;

    vector<double> incomes = {800, 5000, 15000, 60000};
    for (double income : incomes) {
        double tax = calc.calculateTax(income);
        cout << "Income: ₹" << income << " => Tax: ₹" << tax << endl;
    }

    return 0;
}
