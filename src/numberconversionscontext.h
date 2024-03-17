#ifndef NUMBERCONVERSIONSCONTEXT_H
#define NUMBERCONVERSIONSCONTEXT_H

#include "numberconversionsstrategy.h"
#include <memory>
#include <stdexcept>
#include <string>
class NumberConversionsContext
{
  private:
    std::unique_ptr<NumberConversionsStrategy> _strategy;

  public:
    void SetStrategy(std::unique_ptr<NumberConversionsStrategy> strategy);

    std::string Convert(std::string, int precision = 10) const;

    int GetFromBase() const;

    int GetToBase() const;

    explicit NumberConversionsContext(std::unique_ptr<NumberConversionsStrategy>&& strategy);

    virtual ~NumberConversionsContext() = default;
};

#endif // NUMBERCONVERSIONSCONTEXT_H
