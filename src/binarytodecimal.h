#ifndef BINARYTODECIMAL_H
#define BINARYTODECIMAL_H

#include "numberconversionsstrategy.h"

class BinaryToDecimal : public NumberConversionsStrategy
{
  private:
    const int _decimalBase = 10;
    const int _binaryBase = 2;
    const int _defaultPrecision = 10;

    std::string CovertIntegerPartToDecimal(std::string integerPart);
    std::string ConvertFractionalPartToDecimal(std::string fractionalPart, int precision);

  public:
    BinaryToDecimal();

    std::string Convert(std::string binaryNumber, int precision = 0) override;
    int GetFromBase() override
    {
        return _binaryBase;
    }
    int GetToBase() override
    {
        return _decimalBase;
    }
};

#endif // BINARYTODECIMAL_H
