#include "../../include/instrucciones/IRead.hpp"

IRead::IRead(std::string& opcode, std::string& operando, Memoria& memoria, CintaEntrada& cinta_entrada):
Instruccion_Interfaz(opcode, operando), cinta_entrada_(&cinta_entrada)
{
  tipoAcceso_ = isIndirecto(operandoI_);
  memoria_ = &memoria;
}

int IRead::ejecutar()
{
  if (tipoAcceso_ == Indirecto)
  {
    (*memoria_).escribir(((*memoria_))[operandoI_], cinta_entrada_ -> read());
  }
  else if (tipoAcceso_ == Directo)
  {
    (*memoria_).escribir(operandoI_, cinta_entrada_-> read());
  }
  else
  {
    throw Halt("Ha ocurrido un error interno:\nEl parser no funciona bien\n");
  }
  return 0;
}
