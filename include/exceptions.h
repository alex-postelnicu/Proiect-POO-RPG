#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

using namespace std;

class InventoryFull : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Backpack full!";
    }
};

class InvalidItem : public exception
{
private:
    string error_message;

public:
    explicit InvalidItem(int i)
    {
        error_message="There isn't an item at ["+to_string(i)+"] . Choose a correct slot!";
    }

    const char* what() const noexcept override
    {
        return error_message.c_str();
    }
};

#endif
