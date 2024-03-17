#include "binarytohex.h"
#include "validnumberconversions.h"
#include <math.h>
#include <stdexcept>

std::string BinaryToHex::ConvertIntegerPartToHex(std::string integerPart)
{
    if (integerPart == "0")
    {
        return "0";
    }
    else
    {
        std::string hex;

        std::string paddedIntegerPart = integerPart;
        int length = integerPart.size();
        int padding = length % 4;

        if (padding != 0)
        {
            paddedIntegerPart = std::string(4 - padding, '0') + integerPart;
            length = paddedIntegerPart.size();
        }

        for (int i = 0; i < length; i += 4)
        {
            std::string binaryDigit = paddedIntegerPart.substr(i, 4);
            hex += ConvertToHex(binaryDigit);
        }

        return hex;
    }
}

std::string BinaryToHex::ConvertFractionalPartToHex(std::string fractionalPart, int precision)
{
    if (fractionalPart == "0")
    {
        return "";
    }
    else
    {
        std::string hex;

        std::string paddedFractionalPart = fractionalPart;
        int length = fractionalPart.size();
        int padding = length % 4;
        auto defaultPrecision = 0;

        if (padding != 0)
        {
            paddedFractionalPart = fractionalPart + std::string(4 - padding, '0');
            length = paddedFractionalPart.size();
        }

        for (int i = 0; i < length; i += 4)
        {
            std::string binaryDigit = paddedFractionalPart.substr(i, 4);
            hex += ConvertToHex(binaryDigit);
        }

        if (precision == -1)
        {
            defaultPrecision = hex.size();
        }
        else
        {
            defaultPrecision = hex.size() < precision ? hex.size() : precision;
        }

        return hex.substr(0, defaultPrecision);
    }
}

char BinaryToHex::ConvertToHex(std::string binaryNumber)
{
    int hexDigit = 0;
    for (size_t i = 0; i < binaryNumber.size(); i++)
    {
        hexDigit += (binaryNumber[i] - '0') * pow(_binaryBase, binaryNumber.size() - i - 1);
    }

    if (hexDigit >= 0 && hexDigit <= 9)
    {
        return hexDigit + '0';
    }
    else if (hexDigit >= 10 && hexDigit <= 15)
    {
        return hexDigit - 10 + 'A';
    }
    else
    {
        throw std::invalid_argument("Invalid argument for hex conversion");
    }
}

BinaryToHex::BinaryToHex()
{
}

std::string BinaryToHex::Convert(std::string binaryNumber, int precision)
{
    ValidNumberConversions::IsBinaryNumber(binaryNumber);

    size_t dotPosition = binaryNumber.find('.');

    std::string integerPart = binaryNumber.substr(0, dotPosition);
    std::string fractionalPart = (dotPosition != std::string::npos) ? binaryNumber.substr(dotPosition + 1) : "0";

    std::string hexIntegerPart = ConvertIntegerPartToHex(integerPart);
    std::string hexFractionalPart = ConvertFractionalPartToHex(fractionalPart, precision);

    if (hexFractionalPart != "")
    {
        return hexIntegerPart + "." + hexFractionalPart;
    }
    else
    {
        return hexIntegerPart;
    }
}
