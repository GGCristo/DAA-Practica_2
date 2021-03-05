#include "../../include/instrucciones/ISub.hpp"

ISub::ISub(std::string& opcode, std::string& operando): Instruccion_Interfaz(opcode, operando)
{
  tipoAcceso_ = isInmediatoOIndirecto(operandoI_);
}

int ISub::ejecutar(Memoria& memoria, bool debug)
{
  if (debug)
    std::cout << opcode_ << operando_ << '\n';
  if (Inmediato)
  {
    memoria.escribir(0, memoria.get_acumulador() - operandoI_);
  }
  else if (Directo)
  {
    memoria.escribir(0, memoria.get_acumulador() - (memoria)[operandoI_]);
  }
  else if (Indirecto)
  {
    memoria.escribir(0, memoria.get_acumulador() - (memoria)[(memoria)[operandoI_]]);
  }
  else
  {
    throw Halt("Ha ocurrido un error interno:\nEl parser no funciona bien\n");
  }
  return 0;
}
