#include "exceptions.h"

const char *EventException::what() const noexcept {
    return this->message.c_str();
}

EventException::EventException(std::string message) : message(std::move(message)) {}