#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <utility>

// creation interface input
class Input
{
public:
    virtual ~Input() = default;
    virtual std::pair<int, int> demanderCoordonnees() const = 0;
    virtual int demanderColonne() const = 0;
    virtual std::string getString(const std::string &) const = 0;
    virtual int getInt(const std::string &) const = 0;
};

#endif // INPUT_H
