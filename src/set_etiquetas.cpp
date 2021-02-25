#include "../include/set_etiquetas.hpp"

SetEtiquetas::SetEtiquetas()
{}

void SetEtiquetas::insertar(std::string etiqueta, int direccion)
{
  set_etiquetas_.insert(std::make_pair(etiqueta, direccion));
}
