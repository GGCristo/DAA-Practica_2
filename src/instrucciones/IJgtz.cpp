#include "../../include/instrucciones/IJgtz.hpp"

IJgtz::IJgtz(std::string& opcode, std::string& operando, Pc& pc, SetEtiquetas& set_etiquetas):
Instruccion_Interfaz(opcode, operando)
{
  pc_ = &pc;
  set_etiquetas_ = &set_etiquetas;
}

int IJgtz::ejecutar(Memoria& memoria, bool debug)
{
  if (debug)
    std::cout << opcode_ << operando_ << '\n';
  if (memoria.get_acumulador() > 0)
  {
    pc_ -> jump(set_etiquetas_ -> buscar(operando_));
  }
  else if (debug)
  {
    std::cout << "[No se realiza el salto] Acumulador es: " << memoria.get_acumulador() << '\n';
  }
  return 0;
}
