#pragma once
#include <vector>
#include <iostream>

class Memoria
{
  public:
    static Memoria& get_instance();
    const size_t get_sz();
    const int operator [](int);
    std::ostream& mostrar(std::ostream& os = std::cout);
  private:
    Memoria(){};
    ~Memoria(){};
    // escribir (posicion, valor);
    void escribir(int, int);
    const int get_acumulador();
    std::vector<int> memoria_;
    friend class Programa;
};
