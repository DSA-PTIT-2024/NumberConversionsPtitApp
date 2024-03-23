#ifndef BINARYTOHEX_H
#define BINARYTOHEX_H

#include "numberconversionsstrategy.h"

class BinaryToHex : public NumberConversionsStrategy
{
  private:
    const int _binaryBase = 2;
    const int _hexBase = 16;
    const int _defaultPrecision = 10;

    std::string ConvertIntegerPartToHex(std::string integerPart);
    std::string ConvertFractionalPartToHex(std::string fractionalPart, int precision);

    char ConvertToHex(std::string binaryNumber);

  public:
    BinaryToHex();
    std::string Convert(std::string binaryNumber, int precision = 0) override;
    int GetFromBase() override
    {
        return _binaryBase;
    }
    int GetToBase() override
    {
        return _hexBase;
    }
};

#endif // BINARYTOHEX_H
