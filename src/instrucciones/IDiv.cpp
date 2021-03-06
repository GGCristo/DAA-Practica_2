#include "../../include/instrucciones/IDiv.hpp"

IDiv::IDiv(std::string& opcode, std::string& operando, Memoria& memoria):
Instruccion_Interfaz(opcode, operando)
{
  tipoAcceso_ = isInmediatoOIndirecto(operandoI_);
  memoria_ = &memoria;
}

int IDiv::ejecutar()
{
  int denominador;
  if (tipoAcceso_ == Inmediato)
  {
    denominador = operandoI_;
  }
  else if (tipoAcceso_ == Directo)
  {
    denominador = (*memoria_)[operandoI_];
  }
  else if (tipoAcceso_ == Indirecto)
  {
    denominador = (*memoria_)[(*memoria_)[operandoI_]];
  }
  else
  {
    throw Halt("Ha ocurrido un error interno:\nEl parser no funciona bien\n");
  }
  if (denominador == 0)
  {
    throw Halt("Se ha intentado dividir entre cero\n");
  }
  (*memoria_).escribir(0, (*memoria_).get_acumulador() / denominador);
  return 0;
}
