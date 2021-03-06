#pragma once

class Pc
{
  public:
    Pc();
    int acceso();
    void jump(int);
    int peek();
  private:
    int pc_;
};
