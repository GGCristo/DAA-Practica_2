#include "../../include/instrucciones/IStore.hpp"

IStore::IStore(std::string& opcode, std::string& operando, Memoria& memoria):
Instruccion_Interfaz(opcode, operando)
{
  tipoAcceso_ = isIndirecto(operandoI_);
  memoria_ = &memoria;
}

int IStore::ejecutar()
{
  if (tipoAcceso_ == Directo)
  {
    (*memoria_).escribir(operandoI_, (*memoria_).get_acumulador());
  }
  else if (tipoAcceso_ == Indirecto)
  {
    (*memoria_).escribir(((*memoria_))[operandoI_], (*memoria_).get_acumulador());
  }
  else
  {
    throw Halt("Ha ocurrido un error interno:\nEl parser no funciona bien\n");
  }
  return 0;
}
