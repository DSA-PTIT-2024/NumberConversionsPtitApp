#ifndef HEXTODECIMAL_H
#define HEXTODECIMAL_H

#include "numberconversionsstrategy.h"
#include <string>
class HexToDecimal : public NumberConversionsStrategy
{
  private:
    const int _decimalBase = 10;
    const int _hexadecimalBase = 16;
    const int _defaultPrecision = 10;

    std::string CovertIntegerPartToDecimal(std::string integerPart);
    std::string ConvertFractionalPartToDecimal(std::string fractionalPart, int precision);
    int ConvertToDecimal(char hexDigit);

  public:
    HexToDecimal();
    std::string Convert(std::string hexNumber, int precision) override;
    int GetFromBase() override
    {
        return _hexadecimalBase;
    }
    int GetToBase() override
    {
        return _decimalBase;
    }
};

#endif // HEXTODECIMAL_H
