#include "hextodecimal.h"

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
        long long decimal = 0;
        int power = 0;
        for (int i = integerPart.size() - 1; i >= 0; i--)
        {
            decimal += ConvertToDecimal(integerPart[i]) * pow(_hexadecimalBase, power);
            power++;
        }
        return std::to_string(decimal);
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
        auto defaultPrecision = 0;
        std::string result;

        for (auto i = 0; i < length; ++i)
        {
            decimal += ConvertToDecimal(fractionalPart[i]) * pow(_hexadecimalBase, static_cast<long long>(-i - 1));
        }

        if (precision != -1)
        {
            defaultPrecision = precision;
        }
        else
        {
            while (decimal != 0)
            {
                decimal *= _decimalBase;
                result += std::to_string(static_cast<int>(decimal));
                decimal -= static_cast<int>(decimal);
            }

            return result;
        }

        while (decimal != 0 && defaultPrecision-- > 0)
        {
            decimal *= _decimalBase;
            result += std::to_string(static_cast<int>(decimal));
            decimal -= static_cast<int>(decimal);
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
