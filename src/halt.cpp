#include "../include/halt.hpp"

Halt::Halt(std::string message, bool successful_exit)
{
  what_message_ = message;
  successful_exit_ = successful_exit;
}

const char* Halt::what() const noexcept //override
{
  return what_message_.c_str();
}

const bool Halt::isSucceed() const
{
  return successful_exit_;
}
