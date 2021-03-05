#pragma once
#include <string>
class Pc
{
  public:
    Pc();
    int acceso();
    void jump(int);
    const std::string peek();
  private:
    int pc_;
};
