#pragma once
#include <vector>
#include <iostream>

class CintaSalida
{
  public:
    CintaSalida();
    const int operator [] (int);
    const size_t get_sz();
    std::ostream& mostrar(std::ostream& os = std::cout);
  private:
    std::vector<int> cintaSalida_;
    int cabeza_ = 0;
    void write(int);
    friend class IWrite;
};
