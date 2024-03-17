#include "validnumberconversions.h"

#include <regex>
#include <string>
ValidNumberConversions::ValidNumberConversions()
{
}

bool ValidNumberConversions::IsBinaryNumber(std::string binaryNumber)
{
    std::regex pattern("^[0-1]+(\\.[0-1]+)?$");
    if (!std::regex_match(binaryNumber, pattern))
    {
        throw std::invalid_argument("The number must be binary");
    }
    return true;
}

bool ValidNumberConversions::IsDecimalNumber(std::string decimalNumber)
{
    std::regex pattern("^(0|[1-9]\\d*)(\\.\\d+)?$");
    if (!std::regex_match(decimalNumber, pattern))
    {
        throw std::invalid_argument("The number must be decimal");
    }
    return true;
}

bool ValidNumberConversions::IsHexadecimalNumber(std::string hexadecimalNumber)
{
    std::regex pattern("^[0-9A-Fa-f]+(\\.[0-9A-Fa-f]+)?$");
    if (!std::regex_match(hexadecimalNumber, pattern))
    {
        throw std::invalid_argument("The number must be hexadecimal");
    }
    return true;
}
