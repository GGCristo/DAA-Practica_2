#pragma once
#include <vector>
#include <iostream> // TODO borrar

#include "halt.hpp"

class CintaEntrada
{
  public:
    CintaEntrada();
    ~CintaEntrada();
    const size_t get_sz();
    void set_cinta_entrada(const std::vector<int>&);
    const int operator [] (int);
    std::ostream& mostrar(std::ostream& os = std::cout);
  private:
    int read();
    std::vector<int> cintaEntrada_;
    int cabeza_;
    friend class IRead;
};
