#include "../../include/instrucciones/IMult.hpp"

IMult::IMult(std::string& opcode, std::string& operando, Memoria& memoria): Instruccion_Interfaz(opcode, operando)
{
  tipoAcceso_ = isInmediatoOIndirecto(operandoI_);
  memoria_ = &memoria;
}

int IMult::ejecutar()
{
  int operandoDerecho;
  if (tipoAcceso_ == Inmediato)
  {
    operandoDerecho = operandoI_;
  }
  else if (tipoAcceso_ == Directo)
  {
    operandoDerecho = (*memoria_)[operandoI_];
  }
  else if (tipoAcceso_ == Indirecto)
  {
    operandoDerecho = (*memoria_)[(*memoria_)[operandoI_]];
  }
  else
  {
    throw Halt("Ha ocurrido un error interno:\nEl parser no funciona bien\n");
  }
  overflow(memoria_ -> get_acumulador(), operandoDerecho);
  memoria_ -> escribir(0, memoria_ -> get_acumulador() * operandoDerecho);
  return 0;
}

void IMult::overflow(int a, int b)
{
  if ((a > INT_MAX / b) ||
      (a < INT_MIN / b))
  {
    std::cerr << "Warning: Ha habido un overflow\n";
  }
}
