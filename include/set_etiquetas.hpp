#pragma once
#include <unordered_map>
class SetEtiquetas
{
  public:
    SetEtiquetas();
    void insertar(std::string, int);
  private:
    std::unordered_map<std::string, int> set_etiquetas_;
};
