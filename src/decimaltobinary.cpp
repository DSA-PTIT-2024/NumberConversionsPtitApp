#include "decimaltobinary.h"
#include "validnumberconversions.h"
#include <math.h>
#include <queue>
#include <stack>
#include <string>
DecimalToBinary::DecimalToBinary()
{
}

std::string DecimalToBinary::ConvertIntegerPartToBinary(std::string integerPart)
{
    if (integerPart == "0")
    {
        return "0";
    }
    else
    {
        /*Code here*/
        /*Nhu Tuan done*/
        long long decimal = std::stoll(integerPart);
        std::string result;
        std::stack<int> remainder;

        while (decimal != 0)
        {
            remainder.push(static_cast<int>(decimal % _binaryBase));
            decimal /= _binaryBase;
        }

        while (!remainder.empty())
        {
            result += std::to_string(remainder.top());
            remainder.pop();
        }

        return result;
    }
}

std::string DecimalToBinary::ConvertFractionalPartToBinary(std::string fractionalPart, int precision)
{
    if (fractionalPart == "0")
    {
        return "";
    }
    else
    {
        /*Code here*/
        /*Nhu Tuan done*/
        long double decimal = std::stold("0." + fractionalPart);
        std::string binary;
        int defaultPrecision = 0;
        std::queue<int> remainder;

        if (precision == -1)
        {
            defaultPrecision = _defaultPrecision;
        }
        else
        {
            defaultPrecision = precision;
        }

        while (decimal != 0 && defaultPrecision-- > 0)
        {
            decimal *= _binaryBase;
            remainder.push(static_cast<int>(decimal));
            decimal -= remainder.back();
        }

        while (!remainder.empty())
        {
            binary += std::to_string(remainder.front());
            remainder.pop();
        }

        return binary;
    }
}

std::string DecimalToBinary::Convert(std::string decimalNumber, int precision)
{
    ValidNumberConversions::IsDecimalNumber(decimalNumber);

    size_t dotPosition = decimalNumber.find('.');

    std::string integerPart = decimalNumber.substr(0, dotPosition);

    std::string fractionalPart = (dotPosition != std::string::npos) ? decimalNumber.substr(dotPosition + 1) : "0";

    auto integerBinary = ConvertIntegerPartToBinary(integerPart);
    auto fractionalBinary = ConvertFractionalPartToBinary(fractionalPart, precision);

    if (fractionalBinary.empty())
    {
        return integerBinary;
    }
    else
    {
        return integerBinary + "." + fractionalBinary;
    }
}
