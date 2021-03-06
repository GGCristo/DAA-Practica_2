#pragma once
#include <unordered_map>
class SetEtiquetas
{
  public:
    SetEtiquetas();
    void insertar(std::string, int);
    int buscar(std::string) const;
  private:
    std::unordered_map<std::string, int> set_etiquetas_;
};
