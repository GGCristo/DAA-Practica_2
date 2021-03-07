#pragma once
#include <vector>
#include <iostream>

class CintaSalida
{
  public:
    CintaSalida();
    int operator [] (int);
    size_t get_sz();
    std::ostream& mostrar(std::ostream& os = std::cout);
  private:
    std::vector<int> cintaSalida_;
    int cabeza_;
    void write(int);
    friend class IWrite;
};
