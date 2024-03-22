#include "binarytodecimal.h"
std::string BinaryToDecimal::CovertIntegerPartToDecimal(std::string integerPart)
{
    if (integerPart == "0")
    {
        return 0;
    }
    else
    {
        long long decimal = 0;
        int i = 0;
        auto defaultintegerPart = integerPart;
        while (defaultintegerPart != "")
        {
            auto digit = defaultintegerPart.back();
            defaultintegerPart.pop_back();
            decimal += (digit - '0') * pow(_binaryBase, i);
            i++;
        }
        return std::to_string(decimal);
    }
}

std::string BinaryToDecimal::ConvertFractionalPartToDecimal(std::string fractionalPart, int precision)
{
    if (fractionalPart == "0")
    {
        return "";
    }
    else
    {
        auto length = fractionalPart.length();
        long double decimal = 0.0;
        auto defaultPrecision = 0;

        if (precision != -1)
        {
            defaultPrecision = precision;
        }
        else
        {
            defaultPrecision = length;
        }

        for (auto i = 0; i < length; ++i)
        {
            if (fractionalPart[i] == '1')
            {
                decimal += pow(_binaryBase, static_cast<long long>(-i - 1));
            }
        }

        std::string result;

        while (decimal != 0 && defaultPrecision-- > 0)
        {
            decimal *= 10;
            result += std::to_string(static_cast<int>(decimal));
            decimal -= static_cast<int>(decimal);
        }

        return result;
    }
}

BinaryToDecimal::BinaryToDecimal()
{
}

std::string BinaryToDecimal::Convert(std::string binaryNumber, int precision)
{
    ValidNumberConversions::IsBinaryNumber(binaryNumber);

    size_t dotPosition = binaryNumber.find('.');

    std::string integerPart = binaryNumber.substr(0, dotPosition);
    std::string fractionalPart = (dotPosition != std::string::npos) ? binaryNumber.substr(dotPosition + 1) : "0";

    auto decimalIntegerPart = CovertIntegerPartToDecimal(integerPart);
    auto decimalFractionalPart = ConvertFractionalPartToDecimal(fractionalPart, precision);

    if (decimalFractionalPart.empty())
    {
        return decimalIntegerPart;
    }
    else
    {
        return decimalIntegerPart + "." + decimalFractionalPart;
    }
}
