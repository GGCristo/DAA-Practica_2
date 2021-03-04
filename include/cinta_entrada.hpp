#pragma once
#include <vector>

class CintaEntrada
{
  public:
    CintaEntrada();
    const size_t get_sz();
    static CintaEntrada& get_instance();
    void set_cinta_entrada(const std::vector<int>&);
    const int operator [] (int);
    CintaEntrada(const CintaEntrada&) = delete;
    CintaEntrada& operator = (const CintaEntrada&) = delete;
  private:
    int read();
    std::vector<int> cinta_entrada_;
    int cabeza_;
};
