#include "person.h"
Person::Person(PersonId id,
       std::string firstName,
       std::string middleName,
       std::string lastName)
{
    _id = id;
    _firstName = firstName;
    _middleName = middleName;
    _lastName = lastName;
}

Person::Person()
{
    _firstName = "invalid";
    _middleName = "invalid";
    _lastName = "invalid";
}

PersonId::PersonId()
{
    _series = -1;
    _number = -1;
}

PersonId::PersonId(unsigned series, unsigned number)
{
    _series = series;
    _number = number;
}

unsigned PersonId::Number() const
{
    return _number;
}

unsigned PersonId::Series() const
{
    return _number;
}

bool operator!=(const PersonId & a, const PersonId & b) {
    return  a._number != b._number ||
            a._series != b._series;
}

bool operator==(const PersonId & a, const PersonId & b)
{
    return !operator!=(a,b);
}

std::ostream & operator<<(std::ostream & out, const PersonId & id)
{
    out << id.Number() << " " << id.Series();
    return out;
}







const PersonId & Person::Id() const
{
    return _id;
}

std::string Person::FullName() const
{
    return _firstName + _middleName + _lastName;
}

std::ostream & operator<<(std::ostream & out, const Person & person)
{
    out << "{"
        << "id: " << person.Id() << ","
        << "name:" << person.FullName()
        << "}";
    return out;
}

bool operator!=(const Person & a, const Person & b) {
    return  a._firstName != b._firstName ||
            a._middleName != b._middleName ||
            a._lastName != b._lastName ||
            a._id != b._id;
}

bool operator==(const Person & a, const Person & b)
{
    return !operator!=(a,b);
}

