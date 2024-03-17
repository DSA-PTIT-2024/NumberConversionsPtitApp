#ifndef NUMBERCONVERSIONSCORE_H
#define NUMBERCONVERSIONSCORE_H
#include "binarytodecimal.h"
#include "binarytohex.h"
#include "decimaltobinary.h"
#include "decimaltohex.h"
#include "hextobinary.h"
#include "hextodecimal.h"
#include "nullconvertnumber.h"
#include "numberconversionscontext.h"
#include "numberconversiontypes.h"
#include "validnumberconversions.h"
#include <memory>
#include <string>
class NumberConversionsCore
{
  private:
    std::unique_ptr<NumberConversionsContext> _context;
    int _fromType, _toType;
    NumberConversionTypes _types;

    NumberConversionTypes ChangeStrategyInternal(int fromType, int toType);

    std::string ConvertInternal(std::string number, int precision);
    std::string MakeStandardNumber(std::string number);

    void ValidateNumber(std::string number);

  public:
    NumberConversionsCore();

    void IsNumberConvertable(std::string number);

    std::string Convert(std::string number, int precision = 10);

    int GetFromType() const;
    int GetToType() const;

    int GetFromBaseNumber() const;
    int GetToBaseNumber() const;
    void ChangeFromType(int fromType);
    void ChangeToType(int toType);

    NumberConversionTypes GetConversionType() const;
};

#endif // NUMBERCONVERSIONSCORE_H
