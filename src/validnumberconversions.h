#ifndef VALIDNUMBERCONVERSIONS_H
#define VALIDNUMBERCONVERSIONS_H

#include <string>
class ValidNumberConversions
{
  public:
    ValidNumberConversions();
    static bool IsBinaryNumber(std::string binaryNumber);
    static bool IsDecimalNumber(std::string decimalNumber);
    static bool IsHexadecimalNumber(std::string hexadecimalNumber);
};

#endif // VALIDNUMBERCONVERSIONS_H
