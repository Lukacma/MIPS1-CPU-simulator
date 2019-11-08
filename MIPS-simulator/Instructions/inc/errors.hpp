#ifndef ERRORS_H
#define ERRORS_H
#include <exception>
#include <string>
#include <stdexcept>
class arithmetic_exception : public std::runtime_error
{
public:
    arithmetic_exception(const std::string &what) : runtime_error(what){};
};

class memory_exception : public std::runtime_error
{
public:
    memory_exception(const std::string &what) : runtime_error(what){};
};

class invalid_instruction : public std::runtime_error
{
public:
    invalid_instruction(const std::string &what) : runtime_error(what){};
};

class IO_error : public std::runtime_error
{
public:
    IO_error(const std::string &what) : runtime_error(what){};
};

class Internal_error : public std::runtime_error
{
public:
    Internal_error(const std::string &what) : runtime_error(what){};
};

#endif
