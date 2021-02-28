#pragma once
#include <unordered_map>
class SetEtiquetas
{
  public:
    SetEtiquetas();
    void insertar(std::string, int);
    int buscar(std::string) const;
  private:
    //TODO comprueba el impacto en rendimiento si intercambias el orden del pair
    std::unordered_map<std::string, int> set_etiquetas_;
};
