#include "../../include/instrucciones/IRead.hpp"

IRead::IRead(std::string& opcode, std::string& operando, CintaEntrada& cinta_entrada): Instruccion_Interfaz(opcode, operando), cinta_entrada_(&cinta_entrada)
{
  tipoAcceso_ = isIndirecto(operandoI_);
}

int IRead::ejecutar(Memoria& memoria)
{
  if (tipoAcceso_ == Indirecto)
  {
    memoria.escribir((memoria)[operandoI_], cinta_entrada_ -> read());
  }
  else if (tipoAcceso_ == Directo)
  {
    memoria.escribir(operandoI_, cinta_entrada_-> read());
  }
  else
  {
    throw Halt("Ha ocurrido un error interno:\nEl parser no funciona bien\n");
  }
  return 0;
}
