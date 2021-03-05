#pragma once
#include <vector>
#include <iostream>

class Memoria
{
  public:
    Memoria(){};
    ~Memoria(){};
    size_t get_sz();
    int operator [](int);
    // escribir (posicion, valor);
    int get_acumulador();
    std::ostream& mostrar(std::ostream& os = std::cout);
    void escribir(unsigned long, int);
  private:
    std::vector<int> memoria_;
};
