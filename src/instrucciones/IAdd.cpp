#include "../../include/instrucciones/IAdd.hpp"

IAdd::IAdd(std::string& opcode, std::string& operando): Instruccion_Interfaz(opcode, operando)
{
  tipoAcceso_ = isInmediatoOIndirecto(operandoI_);
}

int IAdd::ejecutar(Memoria& memoria, bool debug)
{
  if (tipoAcceso_ == Inmediato)
  {
    memoria.escribir(0, memoria.get_acumulador() + operandoI_);
  }
  else if (tipoAcceso_ == Directo)
  {
    memoria.escribir(0, memoria.get_acumulador() + (memoria)[operandoI_]);
  }
  else if (tipoAcceso_ == Indirecto)
  {
    memoria.escribir(0, memoria.get_acumulador() + (memoria)[(memoria)[operandoI_]]);
  }
  else
  {
    throw Halt("Ha ocurrido un error interno:\nEl parser no funciona bien\n");
  }
  return 0;
}
