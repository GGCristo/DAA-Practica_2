#include "../include/halt.hpp"

Halt::Halt(const std::string& message) : what_message_(message)
{}

const char* Halt::what() const noexcept //override
{
  return what_message_.c_str();
}
