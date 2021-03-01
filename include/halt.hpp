#pragma once
#include <stdexcept>
class Halt//: public std::logic_error
{
  public:
  explicit Halt(const std::string&);
  const char* what() const noexcept; //override;
  private:
  std::string what_message_;
};
