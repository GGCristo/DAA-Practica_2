#include "../../include/instrucciones/IWrite.hpp"

IWrite::IWrite(std::string& opcode, std::string& operando, CintaSalida& cinta_salida): Instruccion_Interfaz(opcode, operando), cinta_salida_(&cinta_salida)
{
  tipoAcceso_ = isInmediatoOIndirecto(operandoI_);
}

int IWrite::ejecutar(Memoria& memoria, bool debug)
{
  if (operandoI_ == 0)
  {
    throw Halt("No se puede acceder al acumulador directamente con \"WRITE\"\n");
  }
  if (debug)
    std::cout << opcode_ << operando_ << '\n';
  if (tipoAcceso_ == Inmediato)
  {
    cinta_salida_ -> write(operandoI_);
  }
  else if (tipoAcceso_ == Directo)
  {
    cinta_salida_ -> write((memoria)[operandoI_]);
  }
  else if (tipoAcceso_ == Indirecto)
  {
    cinta_salida_->write((memoria)[(memoria)[operandoI_]]);
  }
  else
  {
    throw Halt("Ha ocurrido un error interno:\nEl parser no funciona bien\n");
  }
  return 0;
}
