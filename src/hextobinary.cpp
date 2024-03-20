#include "hextobinary.h"
#include "validnumberconversions.h"
#include <stdexcept>

std::string HexToBinary::ConvertIntegerPartToBinary(std::string integerPart)
{
    if (integerPart == "0")
    {
        return "0";
    }
    else
    {
        /*Code here*/
        /*Thanh Tung*/
        std::string binaryIntegerPart = "";
        for (char hexDigit : integerPart)
        {
            binaryIntegerPart += ConvertToBinary(hexDigit);
        }
        return binaryIntegerPart;
    }
}

std::string HexToBinary::ConvertFractionalPartToBinary(std::string fractionalPart, int precision)
{
    if (fractionalPart == "0")
    {
        return "";
    }
    else
    {
        /*Code here*/
        /*Thanh Tung*/
        std::string binaryFractionalPart = "";
        for (char hexDigit : fractionalPart)
        {
            binaryFractionalPart += ConvertToBinary(hexDigit);
            if (binaryFractionalPart.length() >= precision)
            {
                break;
            }
        }
        return binaryFractionalPart.substr(0, precision);
    }
}

std::string HexToBinary::ConvertToBinary(char hexDigit)
{
    switch (hexDigit)
    {
    case '0':
        return "0000";
    case '1':
        return "0001";
    case '2':
        return "0010";
    case '3':
        return "0011";
    case '4':
        return "0100";
    case '5':
        return "0101";
    case '6':
        return "0110";
    case '7':
        return "0111";
    case '8':
        return "1000";
    case '9':
        return "1001";
    case 'A':
        return "1010";
    case 'B':
        return "1011";
    case 'C':
        return "1100";
    case 'D':
        return "1101";
    case 'E':
        return "1110";
    case 'F':
        return "1111";
    default:
        throw std::invalid_argument("Invalid argument for hex conversion");
    }
}

std::string HexToBinary::Convert(std::string hexNumber, int precision)
{
    ValidNumberConversions::IsHexadecimalNumber(hexNumber);

    size_t dotPosition = hexNumber.find('.');

    std::string integerPart = hexNumber.substr(0, dotPosition);
    std::string fractionalPart = (dotPosition != std::string::npos) ? hexNumber.substr(dotPosition + 1) : "0";

    std::string binaryIntegerPart = this->ConvertIntegerPartToBinary(integerPart);
    std::string binaryFractionalPart = this->ConvertFractionalPartToBinary(fractionalPart, precision);

    if (binaryFractionalPart.empty())
    {
        return binaryIntegerPart;
    }
    else
    {
        return binaryIntegerPart + '.' + binaryFractionalPart;
    }
}

HexToBinary::HexToBinary()
{
}
