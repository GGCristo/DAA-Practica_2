#pragma once
#include <iostream>
#include <vector>

class CintaEntrada
{
  public:
    const int operator [] (int);
    const size_t get_sz();
    static CintaEntrada& get_instance();
    void set_cinta_entrada(std::vector<int>&);
    CintaEntrada(const CintaEntrada&) = delete;
    CintaEntrada& operator = (const CintaEntrada&) = delete;
  private:
    int read();
    CintaEntrada();
    std::vector<int> cinta_entrada_;
    int cabeza_;
    friend class Programa;
};
