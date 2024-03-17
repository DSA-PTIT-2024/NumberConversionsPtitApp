#ifndef NULLCONVERTNUMBER_H
#define NULLCONVERTNUMBER_H

#include "numberconversionsstrategy.h"

class NullConvertNumber : public NumberConversionsStrategy
{
  public:
    NullConvertNumber();
    std::string Convert(std::string number, int precision) override;
    int GetFromBase() override;
    int GetToBase() override;
};

#endif // NULLCONVERTNUMBER_H
