#include "numberconversionscontroller.h"

NumberConversionsController::NumberConversionsController(QObject* parent) : QObject{parent}
{
    _core = std::make_unique<NumberConversionsCore>();
}

int NumberConversionsController::getFromType() const
{
    return this->_core->GetFromType();
}

int NumberConversionsController::getToType() const
{
    return this->_core->GetToType();
}

void NumberConversionsController::setFromType(int fromType)
{
    this->_core->ChangeFromType(fromType);

    emit fromTypeChanged(fromType);
}

void NumberConversionsController::setToType(int toType)
{
    this->_core->ChangeToType(toType);
    emit toTypeChanged(toType);
}

void NumberConversionsController::changeFromType(int fromType)
{
    setFromType(fromType);
}

void NumberConversionsController::changeToType(int toType)
{
    setToType(toType);
}

void NumberConversionsController::convertNumber(QString number, int precision)
{
    try
    {
        auto result = QString::fromStdString(_core->Convert(number.toStdString(), precision));
        emit resultChanged(result);
    }
    catch (const std::invalid_argument& e)
    {
        QString error = QString::fromStdString(e.what());
        emit errorOccurred(error);
    }
}
