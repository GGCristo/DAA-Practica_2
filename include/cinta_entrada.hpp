#pragma once
#include <vector>
#include <iostream>
#include <fstream>

#include "halt.hpp"

class CintaEntrada
{
  public:
    CintaEntrada() = default;
    explicit CintaEntrada(char*);
    ~CintaEntrada();
    size_t get_sz();
    void set_cinta_entrada(const std::vector<int>&);
    std::ostream& mostrar(std::ostream& os = std::cout);
  private:
    int read();
    std::vector<int> cintaEntrada_;
    unsigned long cabeza_;
    friend class IRead;
};
