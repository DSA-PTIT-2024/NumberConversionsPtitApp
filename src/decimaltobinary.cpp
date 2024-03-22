#include "decimaltobinary.h"
#include "validnumberconversions.h"
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
        std::string binary;
        while (decimal > 0)
        {
            binary = std::to_string(decimal % _binaryBase) + binary;
            decimal /= _binaryBase;
        }
        return binary;
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
        auto defaultPrecision = 0;

        if (precision == -1)
        {
            defaultPrecision = _defaultPrecision;
        }
        else
        {
            defaultPrecision = precision;
        }

        while (decimal > 0 && defaultPrecision > 0)
        {
            decimal *= _binaryBase;
            binary += std::to_string(static_cast<int>(decimal));
            decimal -= static_cast<int>(decimal);
            defaultPrecision--;
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
