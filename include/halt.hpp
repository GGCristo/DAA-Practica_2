#pragma once
#include <stdexcept>
class Halt//: public std::logic_error
{
  public:
  Halt(std::string, bool successful_exit = false);
  const char* what() const noexcept; //override;
  const bool isSucceed() const;
  private:
  std::string what_message_;
  bool successful_exit_;
};
