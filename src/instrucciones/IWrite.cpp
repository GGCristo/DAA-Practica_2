#include "../../include/instrucciones/IWrite.hpp"

IWrite::IWrite(std::string& opcode, std::string& operando, Memoria& memoria, CintaSalida& cinta_salida):
Instruccion_Interfaz(opcode, operando), cinta_salida_(&cinta_salida)
{
  tipoAcceso_ = isInmediatoOIndirecto(operandoI_);
  memoria_ = &memoria;
}

int IWrite::ejecutar()
{
  if (operandoI_ == 0)
  {
    throw Halt("No se puede acceder al acumulador directamente con \"WRITE\"\n");
  }
  if (tipoAcceso_ == Inmediato)
  {
    cinta_salida_ -> write(operandoI_);
  }
  else if (tipoAcceso_ == Directo)
  {
    cinta_salida_ -> write(((*memoria_))[operandoI_]);
  }
  else if (tipoAcceso_ == Indirecto)
  {
    cinta_salida_->write(((*memoria_))[((*memoria_))[operandoI_]]);
  }
  else
  {
    throw Halt("Ha ocurrido un error interno:\nEl parser no funciona bien\n");
  }
  return 0;
}
