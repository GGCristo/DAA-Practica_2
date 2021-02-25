#pragma once
#include <iostream>
#include <vector>

class CintaEntrada
{
  public:
    CintaEntrada(const CintaEntrada&) = delete;
    CintaEntrada& operator = (const CintaEntrada&) = delete;
    static CintaEntrada& get_instance();
    void set_cinta_entrada(std::vector<int>&);
    int read();
  private:
    CintaEntrada();
    std::vector<int> cinta_entrada_;
    int cabeza_;
};
