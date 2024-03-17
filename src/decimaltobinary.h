#ifndef DECIMALTOBINARY_H
#define DECIMALTOBINARY_H
#include "numberconversionsstrategy.h"
#include <math.h>
#include <regex>
#include <string>
class DecimalToBinary : public NumberConversionsStrategy
{
  private:
    const int _decimalBase = 10;
    const int _binaryBase = 2;
    const int _defaultPrecision = 10;

    std::string ConvertIntegerPartToBinary(std::string integerPart);
    std::string ConvertFractionalPartToBinary(std::string fractionalPart, int precision);

  public:
    DecimalToBinary();
    std::string Convert(std::string decimalNumber, int precision = 0) override;
    int GetFromBase() override
    {
        return _decimalBase;
    }
    int GetToBase() override
    {
        return _binaryBase;
    }
};
#endif // DECIMALTOBINARY_H
