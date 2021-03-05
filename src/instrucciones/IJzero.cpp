#include "../../include/instrucciones/IJzero.hpp"

IJzero::IJzero(std::string& opcode, std::string& operando, Pc& pc, SetEtiquetas& set_etiquetas):
Instruccion_Interfaz(opcode, operando)
{
  pc_ = &pc;
  set_etiquetas_ = &set_etiquetas;
}

int IJzero::ejecutar(Memoria& memoria, bool debug)
{
  if (debug)
    std::cout << opcode_ << operando_ << '\n';
  if (memoria.get_acumulador() == 0)
  {
    pc_ -> jump(set_etiquetas_ -> buscar(operando_));
  }
  else if (debug)
  {
    std::cout << "[No se realiza el salto] Acumulador es: " << memoria.get_acumulador() << '\n';
  }
  return 0;
}
