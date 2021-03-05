#pragma once
#include <vector>
#include <iostream> // TODO borrar

#include "halt.hpp"

class CintaEntrada
{
  public:
    CintaEntrada();
    ~CintaEntrada();
    size_t get_sz();
    void set_cinta_entrada(const std::vector<int>&);
    int operator [] (int);
    std::ostream& mostrar(std::ostream& os = std::cout);
  private:
    int read();
    std::vector<int> cintaEntrada_;
    unsigned long cabeza_;
    friend class IRead;
};
