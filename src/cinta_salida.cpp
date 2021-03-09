#include "../include/cinta_salida.hpp"

CintaSalida::CintaSalida()
{
  cabeza_ = 0;
}

void CintaSalida::write(int valor)
{
  cintaSalida_.push_back(valor);
  cabeza_++;
}

void CintaSalida::volcar(char* fichero)
{
  // std::cout << "Escribiendo en la cinta de Salida...\n";

  std::fstream f_cinta_output;
  f_cinta_output.open(fichero, std::ios::out);
  if(!f_cinta_output)
  {
    throw "No se ha podido escribir en la cinta de salida\n";
  }

  for (size_t i = 0; i < get_sz(); i++)
  {
    f_cinta_output << cintaSalida_[i] << ' ';
  }

  f_cinta_output.close();
}

size_t CintaSalida::get_sz()
{
  return cintaSalida_.size();
}

std::ostream& CintaSalida::mostrar(std::ostream& os)
{
  for (size_t i = 0; i < cintaSalida_.size(); i++)
  {
    std::cout << cintaSalida_[i] << '\n';
  }
  return os;
}
