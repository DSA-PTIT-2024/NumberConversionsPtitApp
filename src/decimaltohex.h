#ifndef DECIMALTOHEX_H
#define DECIMALTOHEX_H

#include "numberconversionsstrategy.h"
#include "validnumberconversions.h"
#include <string>

class DecimalToHex : public NumberConversionsStrategy
{
  private:
    const int _decimalBase = 10;
    const int _hexBase = 16;
    const int _defaultPrecision = 10;

    std::string ConvertIntegerPartToHex(std::string integerPart);
    std::string ConvertFractionalPartToHex(std::string fractionalPart, int precision);

    char ConvertToHex(int number);

  public:
    DecimalToHex();
    std::string Convert(std::string decimalNumber, int precision = 0) override;
    int GetFromBase() override;
    int GetToBase() override
    {
        return _hexBase;
    }
};

#endif // DECIMALTOHEX_H
