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
        /*Tran Hung*/
        return "";
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
        /*Tran Hung*/
        return "";
    }
}

/*helpfull function*/
// int HexToDecimal::ConvertToDecimal(char hexDigit)
// {
//     if (hexDigit >= '0' && hexDigit <= '9')
//     {
//         return hexDigit - '0';
//     }
//     else if (hexDigit >= 'A' && hexDigit <= 'F')
//     {
//         return hexDigit - 'A' + 10;
//     }

//     throw std::invalid_argument("Invalid hexadecimal digit");
// }

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
