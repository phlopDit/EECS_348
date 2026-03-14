#ifndef EXPRESSIONERROR.H
#define EXPRESSIONERROR.H
#include <stdexcept>
#include <string>

class ExpressionError : public std::runtime_error {
    public:
        explicit ExpressionError(const std::string& message);       
};

#endif