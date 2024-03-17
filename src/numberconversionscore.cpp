#include "numberconversionscore.h"
#include "qdebug.h"
#include "qlogging.h"

#include <stdexcept>

NumberConversionsCore::NumberConversionsCore()
{
    _context = std::make_unique<NumberConversionsContext>(std::make_unique<BinaryToDecimal>());
    _fromType = 0;
    _toType = 1;
    _types = NumberConversionTypes::BinaryToDecimal;
}

void NumberConversionsCore::IsNumberConvertable(std::string number)
{
    try
    {

        if (_context == nullptr)
        {
            throw std::runtime_error("Strategy not set");
        }

        this->ValidateNumber(number);
    }
    catch (...)
    {
        throw;
    }
}

NumberConversionTypes NumberConversionsCore::ChangeStrategyInternal(int fromType, int toType)
{

    if (fromType == toType)
    {
        this->_context->SetStrategy(std::make_unique<NullConvertNumber>());
        return NumberConversionTypes::NullConvertNumber;
    }

    if (fromType == 0)
    {
        if (toType == 1)
        {
            this->_context->SetStrategy(std::make_unique<BinaryToDecimal>());
            return NumberConversionTypes::BinaryToDecimal;
        }
        else if (toType == 2)
        {
            this->_context->SetStrategy(std::make_unique<BinaryToHex>());
            return NumberConversionTypes::BinaryToHex;
        }
    }
    else if (fromType == 1)
    {
        if (toType == 0)
        {
            this->_context->SetStrategy(std::make_unique<DecimalToBinary>());
            return NumberConversionTypes::DecimalToBinary;
        }
        else if (toType == 2)
        {
            this->_context->SetStrategy(std::make_unique<DecimalToHex>());
            return NumberConversionTypes::DecimalToHex;
        }
    }
    else if (fromType == 2)
    {
        if (toType == 0)
        {
            this->_context->SetStrategy(std::make_unique<HexToBinary>());
            return NumberConversionTypes::HexToBinary;
        }
        else if (toType == 1)
        {
            this->_context->SetStrategy(std::make_unique<HexToDecimal>());
            return NumberConversionTypes::HexToDecimal;
        }
    }

    throw std::runtime_error("Invalid conversion type");
}

std::string NumberConversionsCore::ConvertInternal(std::string number, int precision)
{
    try
    {
        return this->_context->Convert(number, precision);
    }
    catch (...)
    {
        throw;
    }
}

std::string NumberConversionsCore::MakeStandardNumber(std::string number)
{
    auto standardNumber = QString::fromStdString(number).toUpper();
    return standardNumber.toStdString();
}

void NumberConversionsCore::ValidateNumber(std::string number)
{
    try
    {
        if (_types == NumberConversionTypes::BinaryToDecimal || _types == NumberConversionTypes::BinaryToHex)
        {
            ValidNumberConversions::IsBinaryNumber(number);
        }
        else if (_types == NumberConversionTypes::HexToBinary || _types == NumberConversionTypes::HexToDecimal)
        {
            ValidNumberConversions::IsHexadecimalNumber(number);
        }
        else
        {
            ValidNumberConversions::IsDecimalNumber(number);
        }
    }
    catch (...)
    {
        throw;
    }
}

NumberConversionTypes NumberConversionsCore::GetConversionType() const
{
    return _types;
}

std::string NumberConversionsCore::Convert(std::string number, int precision)
{
    try
    {
        auto standardNumber = this->MakeStandardNumber(number);
        this->ValidateNumber(standardNumber);
        return this->ConvertInternal(standardNumber, precision);
    }
    catch (...)
    {
        throw;
    }
}

int NumberConversionsCore::GetFromType() const
{
    return _fromType;
}

int NumberConversionsCore::GetToType() const
{
    return _toType;
}

int NumberConversionsCore::GetFromBaseNumber() const
{
    return this->_context->GetFromBase();
}

int NumberConversionsCore::GetToBaseNumber() const
{
    return this->_context->GetToBase();
}

void NumberConversionsCore::ChangeFromType(int fromType)
{
    _fromType = fromType;
    _types = ChangeStrategyInternal(fromType, _toType);
}

void NumberConversionsCore::ChangeToType(int toType)
{
    _toType = toType;
    _types = ChangeStrategyInternal(_fromType, toType);
}
