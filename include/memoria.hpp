#pragma once
#include <vector>
#include <iostream>

class Memoria
{
  public:
    Memoria(){};
    ~Memoria(){};
    const size_t get_sz();
    const int operator [](int);
    // escribir (posicion, valor);
    const int get_acumulador();
    std::ostream& mostrar(std::ostream& os = std::cout);
    void escribir(int, int);
  private:
    std::vector<int> memoria_;
};
