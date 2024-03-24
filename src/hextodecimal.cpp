#include "hextodecimal.h"
#include "validnumberconversions.h"
#include <math.h>
#include <queue>
#include <stack>
#include <stdexcept>
std::string HexToDecimal::CovertIntegerPartToDecimal(std::string integerPart)
{
    if (integerPart == "0")
    {
        return "0";
    }
    else
    {
        /*Code here*/
        /*Tran Hung done*/
        unsigned long long decimal = 0;
        int power = 0;
        std::stack<char> integerPartStack;
        std::string result;
        for (int i = integerPart.size() - 1; i >= 0; i--)
        {
            decimal += ConvertToDecimal(integerPart[i]) * pow(_hexadecimalBase, power);
            power++;
        }

        while (decimal != 0)
        {
            integerPartStack.push(static_cast<char>(decimal % _decimalBase));
            decimal /= _decimalBase;
        }

        while (!integerPartStack.empty())
        {
            result += std::to_string(integerPartStack.top());
            integerPartStack.pop();
        }

        return result;
    }
}

std::string HexToDecimal::ConvertFractionalPartToDecimal(std::string fractionalPart, int precision)
{
    if (fractionalPart == "0")
    {
        return "";
    }
    else
    {
        /*Code here*/
        /*Tran Hung done*/
        size_t length = fractionalPart.size();
        long double decimal = 0.0;
        int defaultPrecision = 0;
        std::string result;
        std::queue<char> fractionalPartQueue;

        for (int i = 0; i < length; i++)
        {
            decimal += ConvertToDecimal(fractionalPart[i]) * pow(_hexadecimalBase, static_cast<long long>(-i - 1));
        }

        if (precision != -1)
        {
            defaultPrecision = precision;
            while (decimal != 0 && defaultPrecision-- > 0)
            {
                decimal *= _decimalBase;
                fractionalPartQueue.push(static_cast<char>(decimal));
                decimal -= static_cast<int>(decimal);
            }
        }
        else
        {
            while (decimal != 0)
            {
                decimal *= _decimalBase;
                fractionalPartQueue.push(static_cast<char>(decimal));
                decimal -= static_cast<int>(decimal);
            }
        }

        while (!fractionalPartQueue.empty())
        {
            result += std::to_string(fractionalPartQueue.front());
            fractionalPartQueue.pop();
        }

        return result;
    }
}

/*helpfull function*/
int HexToDecimal::ConvertToDecimal(char hexDigit)
{
    if (hexDigit >= '0' && hexDigit <= '9')
    {
        return hexDigit - '0';
    }
    else if (hexDigit >= 'A' && hexDigit <= 'F')
    {
        return hexDigit - 'A' + 10;
    }

    throw std::invalid_argument("Invalid hexadecimal digit");
}

HexToDecimal::HexToDecimal()
{
}

std::string HexToDecimal::Convert(std::string hexNumber, int precision)
{
    ValidNumberConversions::IsHexadecimalNumber(hexNumber);

    size_t dotPosition = hexNumber.find('.');

    std::string integerPart = hexNumber.substr(0, dotPosition);
    std::string fractionalPart = (dotPosition != std::string::npos) ? hexNumber.substr(dotPosition + 1) : "0";

    std::string integerPartDecimal = CovertIntegerPartToDecimal(integerPart);
    std::string fractionalPartDecimal = ConvertFractionalPartToDecimal(fractionalPart, precision);

    if (fractionalPartDecimal.empty())
    {
        return integerPartDecimal;
    }
    else
    {
        return integerPartDecimal + "." + fractionalPartDecimal;
    }
}
