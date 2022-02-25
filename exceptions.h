//
// Created by andre on 5/10/2021.
//

#ifndef A45_ANDRENYKY_EXCEPTIONS_H
#define A45_ANDRENYKY_EXCEPTIONS_H


#include <exception>
#include <string>

class EventException: public std::exception{

public:

    explicit EventException(std::string message);

    const char *what() const noexcept override;

private:
    std::string message;

};

#endif //A45_ANDRENYKY_EXCEPTIONS_H
