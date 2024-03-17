#ifndef NUMBERCONVERSIONSSTRATEGY_H
#define NUMBERCONVERSIONSSTRATEGY_H

#include <string>

class NumberConversionsStrategy
{

  public:
    virtual std::string Convert(std::string, int) = 0;
    virtual int GetFromBase() = 0;
    virtual int GetToBase() = 0;
    virtual ~NumberConversionsStrategy(){};
};

#endif // NUMBERCONVERSIONSSTRATEGY_H
