#ifndef NUMBERCONVERSIONSCONTROLLER_H
#define NUMBERCONVERSIONSCONTROLLER_H
#include "numberconversionscore.h"
#include <QObject>
#include <memory>

class NumberConversionsController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int fromType READ getFromType WRITE setFromType NOTIFY fromTypeChanged)
    Q_PROPERTY(int toType READ getToType WRITE setToType NOTIFY toTypeChanged)
  public:
    explicit NumberConversionsController(QObject* parent = nullptr);
    Q_ENUM(NumberConversionTypes)

    int getFromType() const;
    int getToType() const;
    void setFromType(int fromType);
    void setToType(int toType);

  private:
    std::unique_ptr<NumberConversionsCore> _core;

  public slots:
    void changeFromType(int fromType);
    void changeToType(int toType);
    void convertNumber(QString number, int precision);

  signals:
    void resultChanged(QString result);
    void fromTypeChanged(int fromType);
    void toTypeChanged(int toType);
    void errorOccurred(QString error);
};

#endif // NUMBERCONVERSIONSCONTROLLER_H
