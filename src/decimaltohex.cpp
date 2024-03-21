#include "decimaltohex.h"
#include <math.h>
#include <regex>
#include <string>
#include <stack>
#include <queue>
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
        auto defaultintegerPart = stoll(integerPart);
        std::stack<long long> st;
        while (defaultintegerPart != 0) {
            st.push(defaultintegerPart % _hexBase);
            defaultintegerPart /= _hexBase;
        }
        std::string result;
        while(!st.empty()){
            result += ConvertToHex(st.top());
            st.pop();
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
        long long length = fractionalPart.length();
        auto hexadecimal = std::stold(std::string("0." + fractionalPart));
        int defaultPrecision = 0;

        if (precision != -1)
        {
            defaultPrecision = precision;
        }
        else
        {
            defaultPrecision = _defaultPrecision;
        }
        std::queue<int> q;
        while(hexadecimal > 0 && defaultPrecision-- > 0)
        {
            hexadecimal *= _hexBase;
            q.push(hexadecimal);
            hexadecimal -= q.back();
        }
        std::string result;
        while(!q.empty())
        {
            result += ConvertToHex(q.front());
            q.pop();
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
