#include "binarytohex.h"
#include "validnumberconversions.h"
#include <math.h>
#include <stdexcept>
#include <queue>
std::string BinaryToHex::ConvertIntegerPartToHex(std::string integerPart)
{
    if (integerPart == "0")
    {
        return "0";
    }
    else
    {
        std::string hex;
        std::queue<char> makeGroup;
        auto length = integerPart.size();
        auto padding = length % 4;

        if (padding != 0)
        {
            int paddingSize = 4 - padding;
            for (size_t i = 0; i < paddingSize; i++)
            {
                makeGroup.push('0');
            }

            length += paddingSize - 2;
        }

        for (size_t i = 0; i < length; i++)
        {
            makeGroup.push(integerPart[i]);
        }

        while (!makeGroup.empty())
        {
            std::string binaryDigit = "";
            for (size_t i = 0; i < 4; i++)
            {
                binaryDigit += makeGroup.front();
                makeGroup.pop();
            }
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
        std::queue<char> makeGroup;
        auto length = fractionalPart.size();
        auto padding = length % 4;
        int defaultPrecision = 0;

        for(size_t i = 0; i < length; i++)
        {
            makeGroup.push(fractionalPart[i]);
        }

        if (padding != 0)
        {
            int paddingSize = 4 - padding;

            for (size_t i = 0; i < paddingSize; i++)
            {
                makeGroup.push('0');
            }

            length += paddingSize - 1;
        }

        while (!makeGroup.empty())
        {
            std::string binaryDigit = "";
            for (size_t i = 0; i < 4; i++)
            {
                binaryDigit += makeGroup.front();
                makeGroup.pop();
            }
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

    if (hexFractionalPart.empty())
    {
        return hexIntegerPart;
    }
    else
    {
        return hexIntegerPart + "." + hexFractionalPart;
    }
}
