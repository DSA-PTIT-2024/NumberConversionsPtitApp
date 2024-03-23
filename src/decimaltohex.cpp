#include "decimaltohex.h"
#include <math.h>
#include <queue>
#include <regex>
#include <stack>
#include <string>
std::string DecimalToHex::ConvertIntegerPartToHex(std::string integerPart)
{
    if (integerPart == "0")
    {
        return "0";
    }
    else
    {
        /*Code here*/
        /*Chi Thinh done*/
        auto decimal = std::stoll(integerPart);
        std::stack<long long> remainder;
        std::string result;
        while (decimal != 0)
        {
            remainder.push(static_cast<int>(decimal % _hexBase));
            decimal /= _hexBase;
        }

        while (!remainder.empty())
        {
            result += ConvertToHex(remainder.top());
            remainder.pop();
        }
        return result;
    }
}

std::string DecimalToHex::ConvertFractionalPartToHex(std::string fractionalPart, int precision)
{
    if (fractionalPart == "0")
    {
        return "";
    }
    else
    {
        /*Code here*/
        /*Chi Thinh done*/
        auto length = fractionalPart.length();
        auto decimal = std::stold(std::string("0." + fractionalPart));
        int defaultPrecision = 0;
        std::queue<int> remainder;
        std::string result;


        if (precision != -1)
        {
            defaultPrecision = precision;
        }
        else
        {
            defaultPrecision = _defaultPrecision;
        }

        while (decimal > 0 && defaultPrecision-- > 0)
        {
            decimal *= _hexBase;
            remainder.push(decimal);
            decimal -= remainder.back();
        }

        while (!remainder.empty())
        {
            result += ConvertToHex(remainder.front());
            remainder.pop();
        }

        return result;
    }
}

/*helpfull function*/
char DecimalToHex::ConvertToHex(int number)
{
    if (number >= 0 && number <= 9)
    {
        return static_cast<char>(number + '0');
    }
    else
    {
        return static_cast<char>(number - 10 + 'A');
    }
    throw std::invalid_argument("Number must be between 0 and 15");
}

DecimalToHex::DecimalToHex()
{
}

std::string DecimalToHex::Convert(std::string decimalNumber, int precision)
{
    ValidNumberConversions::IsDecimalNumber(decimalNumber);

    size_t dotPosition = decimalNumber.find('.');

    auto integerPart = decimalNumber.substr(0, dotPosition);
    auto fractionalPart = (dotPosition != std::string::npos) ? decimalNumber.substr(dotPosition + 1) : "0";

    auto integerPartHex = ConvertIntegerPartToHex(integerPart);
    auto fractionalPartHex = ConvertFractionalPartToHex(fractionalPart, precision);

    if (fractionalPartHex.empty())
    {
        return integerPartHex;
    }
    else
    {
        return integerPartHex + "." + fractionalPartHex;
    }
}

int DecimalToHex::GetFromBase()
{
    return _decimalBase;
}
