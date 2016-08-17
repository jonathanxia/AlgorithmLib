#pragma once
#include <stdexcept>
#include <string>
namespace AlgLib
{
    class bad_dimension : public std::invalid_argument
    {
    public:
        bad_dimension(const std::string& er) : std::invalid_argument(er)
        {
        }

    private:
        std::string msg;
    };

    class not_square_matrix : public bad_dimension
    {
    public:
        using bad_dimension::bad_dimension;
    };
}
