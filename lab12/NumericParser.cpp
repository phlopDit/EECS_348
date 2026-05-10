#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cctype>

class NumericParser {
public:
    /**
     * Extracts the first valid numeric value from a string.
     * Returns -999999.99 if no valid number is found or if out of range.
     */
    double extractNumeric(const std::string& str) {
        const double INVALID_VAL = -999999.99;
        int n = static_cast<int>(str.length());
        
        for (int i = 0; i < n; ++i) {
            // Check if current position could be the start of a number
            if (isdigit(str[i]) || str[i] == '.' || 
               (str[i] == '-' && i + 1 < n && (isdigit(str[i+1]) || str[i+1] == '.'))) {
                
                int start = i;
                bool hasDecimal = false;
                bool hasDigits = false;
                double value = 0.0;
                double sign = 1.0;

                // Handle leading sign
                if (str[i] == '-') {
                    sign = -1.0;
                    i++;
                }

                // Process Mantissa
                double fractionDivisor = 1.0;
                while (i < n && (isdigit(str[i]) || str[i] == '.')) {
                    if (str[i] == '.') {
                        if (hasDecimal) { 
                            return INVALID_VAL; 
                        }
                        hasDecimal = true;
                    } else {
                        hasDigits = true;
                        if (!hasDecimal) {
                            value = value * 10.0 + (str[i] - '0');
                        } else {
                            fractionDivisor *= 10.0;
                            value += (str[i] - '0') / fractionDivisor;
                        }
                    }
                    i++;
                }

                if (!hasDigits) {
                    i = start; // Reset and continue searching if it was just a '.' or '-'
                    continue;
                }

                value *= sign;

                // Process Scientific Notation
                if (i < n && (str[i] == 'e' || str[i] == 'E')) {
                    i++;
                    double expSign = 1.0;
                    if (i < n && (str[i] == '+' || str[i] == '-')) {
                        if (str[i] == '-') expSign = -1.0;
                        i++;
                    }

                    long long exponent = 0;
                    bool hasExpDigits = false;
                    while (i < n && isdigit(str[i])) {
                        exponent = exponent * 10 + (str[i] - '0');
                        hasExpDigits = true;
                        i++;
                        if (exponent > 400) break; // Prevent overflow during parsing
                    }

                    if (hasExpDigits) {
                        value *= std::pow(10.0, static_cast<double>(exponent * expSign));
                    } else {
                        return INVALID_VAL; // Invalid exponent format
                    }
                }

                // Range Check
                if (std::isinf(value) || std::isnan(value) || value < -999999.99 || value > 999999.99) {
                    return INVALID_VAL;
                }

                return value;
            }
        }

        return INVALID_VAL;
    }
};

int main() {
    NumericParser parser;
    std::string input;

    while (true) {
        std::cout << "Enter string (or 'END' to quit): ";
        if (!std::getline(std::cin, input) || input == "END") {
            std::cout << "Program terminated." << std::endl;
            break;
        }

        if (input.length() > 200) {
            input = input.substr(0, 200);
        }

        double result = parser.extractNumeric(input);

        if (result == -999999.99) {
            std::cout << "Invalid input: no valid floating-point number found" << std::endl;
            // std::cout<< std::endl;
        } else {
            std::cout << "Extracted number: " << std::fixed << std::setprecision(4) << result << std::endl;
            // std::cout<< std::endl;
        }
        std::cout<< std::endl;
    }

    return 0;
}