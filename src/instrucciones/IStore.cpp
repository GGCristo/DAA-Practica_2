#include "../../include/instrucciones/IStore.hpp"

IStore::IStore(std::string& opcode, std::string& operando): Instruccion_Interfaz(opcode, operando)
{
  tipoAcceso_ = isIndirecto(operandoI_);
}

int IStore::ejecutar(Memoria& memoria, bool debug)
{
  if (debug)
    std::cout << opcode_ << operando_ << '\n';
  if (tipoAcceso_ == Directo)
  {
    memoria.escribir(operandoI_, memoria.get_acumulador());
  }
  else if (tipoAcceso_ == Indirecto)
  {
    memoria.escribir((memoria)[operandoI_], memoria.get_acumulador());
  }
  else
  {
    throw Halt("Ha ocurrido un error interno:\nEl parser no funciona bien\n");
  }
  return 0;
}
