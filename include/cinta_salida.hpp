#pragma once
#include <vector>

class CintaSalida
{
  public:
    CintaSalida(const CintaSalida&) = delete;
    CintaSalida& operator = (const CintaSalida&) = delete;
    static CintaSalida& get_instance();
    void write(int);
  private:
    CintaSalida();
    std::vector<int> cinta_salida_;
    int cabeza_ = 0;
};
