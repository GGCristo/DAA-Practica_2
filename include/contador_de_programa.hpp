#pragma once
#include <string>
class Pc
{
  public:
    Pc();
    const int acceso();
    void jump(int);
    void incrementar();
    const std::string peek();
  private:
    int pc_;
};
