#pragma once
#include <vector>

class CintaSalida
{
  public:
    static CintaSalida& get_instance();
    const int operator [] (int);
    const size_t get_sz();
    CintaSalida(const CintaSalida&) = delete;
    CintaSalida& operator = (const CintaSalida&) = delete;
  private:
    CintaSalida();
    std::vector<int> cinta_salida_;
    int cabeza_ = 0;
    void write(int);
    friend class Programa;
};
