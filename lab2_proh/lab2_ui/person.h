#pragma once

#include <iostream>

struct PersonId
{
public:
    PersonId();
    PersonId(unsigned series, unsigned number);
    unsigned Series() const;
    unsigned Number() const;
    bool friend operator==(const PersonId & a, const PersonId & b);
    bool friend operator!=(const PersonId & a, const PersonId & b);
private:
    unsigned _series;
    unsigned _number;
};
std::ostream & operator<<(std::ostream & out, const PersonId & id);


struct Person
{
public:
    Person();
    Person(PersonId id,
           std::string firstName,
           std::string middleName,
           std::string lastName);

    const PersonId & Id() const;
    std::string FullName() const;
    bool friend operator==(const Person & a, const Person & b);
    bool friend operator!=(const Person & a, const Person & b);
private:
    PersonId _id;
    std::string _firstName;
    std::string _middleName;
    std::string _lastName;
};
std::ostream & operator<<(std::ostream & out, const Person & person);
