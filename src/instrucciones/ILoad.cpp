#include "../../include/instrucciones/ILoad.hpp"

ILoad::ILoad(std::string& opcode, std::string& operando): Instruccion_Interfaz(opcode, operando)
{
  tipoAcceso_ = isInmediatoOIndirecto(operandoI_);
}

int ILoad::ejecutar(Memoria& memoria, bool debug)
{
  if (debug)
    std::cout << opcode_ << operando_ << '\n';
  if (tipoAcceso_ == Inmediato)
  {
    memoria.escribir(0, operandoI_);
  }
  else if (tipoAcceso_ == Directo)
  {
    memoria.escribir(0, (memoria)[operandoI_]);
  }
  else if (tipoAcceso_ == Indirecto)
  {
    memoria.escribir(0, (memoria)[(memoria)[operandoI_]]);
  }
  else
  {
    throw Halt("Ha ocurrido un error interno:\nEl parser no funciona bien\n");
  }
  return 0;
}
