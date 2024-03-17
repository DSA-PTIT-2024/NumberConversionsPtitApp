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
        /*Nhu Tuan*/
        return "";
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
        /*Nhu Tuan*/
        return "";
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

    if (fractionalBinary != "")
    {
        return integerBinary + "." + fractionalBinary;
    }
    else
    {
        return integerBinary;
    }
}
