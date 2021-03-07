#pragma once
#include <vector>
#include <iostream>
#include <fstream>

class CintaSalida
{
  public:
    CintaSalida();
    size_t get_sz();
    void volcar(char*);
    std::ostream& mostrar(std::ostream& os = std::cout);
  private:
    std::vector<int> cintaSalida_;
    int cabeza_;
    void write(int);
    friend class IWrite;
};
