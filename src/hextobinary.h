#ifndef HEXTOBINARY_H
#define HEXTOBINARY_H

#include "numberconversionsstrategy.h"
#include "validnumberconversions.h"
#include <stdexcept>
#include <string>

class HexToBinary : public NumberConversionsStrategy
{
  private:
    const int _hexBase = 16;
    const int _binaryBase = 2;
    const int _defaultPrecision = 10;

    std::string ConvertIntegerPartToBinary(std::string integerPart);
    std::string ConvertFractionalPartToBinary(std::string fractionalPart, int precision);

    std::string ConvertToBinary(char hexDigit);

  public:
    HexToBinary();
    std::string Convert(std::string hexNumber, int precision) override;
    int GetFromBase() override
    {
        return _hexBase;
    }
    int GetToBase() override
    {
        return _binaryBase;
    }
};

#endif // HEXTOBINARY_H
