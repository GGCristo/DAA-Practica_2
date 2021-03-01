#include "../include/set_etiquetas.hpp"

SetEtiquetas::SetEtiquetas()
{}

void SetEtiquetas::insertar(std::string etiqueta, int direccion)
{
  set_etiquetas_.insert(std::make_pair(etiqueta, direccion));
}

int SetEtiquetas::buscar(std::string etiqueta) const
{
  auto buscar = set_etiquetas_.find(etiqueta);
  if (buscar == set_etiquetas_.end())
  {
    throw std::out_of_range("La etiqueta " + etiqueta + " no ha sido definida\n");
  }
  return buscar -> second;
}
