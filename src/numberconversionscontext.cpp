#include "numberconversionscontext.h"

void NumberConversionsContext::SetStrategy(std::unique_ptr<NumberConversionsStrategy> strategy)
{
    _strategy = std::move(strategy);
}

std::string NumberConversionsContext::Convert(std::string number, int precision) const
{
    try
    {
        return _strategy->Convert(number, precision);
    }
    catch (const std::invalid_argument& e)
    {
        throw;
    }
}

int NumberConversionsContext::GetFromBase() const
{
    return this->_strategy->GetFromBase();
}

int NumberConversionsContext::GetToBase() const
{
    return this->_strategy->GetToBase();
}

NumberConversionsContext::NumberConversionsContext(std::unique_ptr<NumberConversionsStrategy>&& strategy)
{
    _strategy = std::move(strategy);
}
