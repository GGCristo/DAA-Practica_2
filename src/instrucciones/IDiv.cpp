#include "../../include/instrucciones/IDiv.hpp"

IDiv::IDiv(std::string& opcode, std::string& operando): Instruccion_Interfaz(opcode, operando)
{
  tipoAcceso_ = isInmediatoOIndirecto(operandoI_);
}

int IDiv::ejecutar(Memoria& memoria, bool debug)
{
  int denominador;
  if (tipoAcceso_ == Inmediato)
  {
    denominador = operandoI_;
  }
  else if (tipoAcceso_ == Directo)
  {
    denominador = memoria[operandoI_];
  }
  else if (tipoAcceso_ == Indirecto)
  {
    denominador = memoria[memoria[operandoI_]];
  }
  else
  {
    throw Halt("Ha ocurrido un error interno:\nEl parser no funciona bien\n");
  }
  if (denominador == 0)
  {
    throw Halt("Se ha intentado dividir entre cero\n");
  }
  memoria.escribir(0, memoria.get_acumulador() / denominador);
  return 0;
}
