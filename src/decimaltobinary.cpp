#include "decimaltobinary.h"
#include "validnumberconversions.h"
#include <iostream>
#include <math.h>
using namespace std;
DecimalToBinary::DecimalToBinary()
{
    double decimalNumber, integerPart, fractionalPart, intergerPart2, fractionalPart2;
    int i = 0, p = 0, j, rem;
    int binaryIntegerPart[100], binaryFractionalPart[100];
    cout << "Nhap so thuc duong: ";
    cin >> decimalNumber;
    fractionalPart = modf(decimalNumber, &integerPart);
    int a = int(integerPart);
    int b = int(intergerPart2);
    
}

std::string DecimalToBinary::ConvertIntegerPartToBinary(std::string integerPart)
{
    if (integerPart == "0")
    {
        return "0";
    }
    else
    {
        while (a > 0)
        {
            rem = a % 2;
            a = a / 2;
            binaryIntegerPart[i] = rem;
            i++;
        }
        for (j = i - 1; j >= 0; j--)
        {
            cout << binaryIntegerPart[j];
        }
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
        cout << ".";
        while (fractionalPart > 0  && p < 5)
            {
                fractionalPart = fractionalPart * 2;
                fractionalPart2 = modf(fractionalPart, &intergerPart2);
                int b = int(intergerPart2);
                binaryFractionalPart[p] = b;
                p++;    
                fractionalPart = fractionalPart2; 
            }
        for (int u = 0; u <= p - 1; u++)
        {
            cout << binaryFractionalPart[u];
        }
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
