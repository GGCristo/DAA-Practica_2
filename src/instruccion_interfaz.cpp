#include "../include/instruccion_interfaz.hpp"

Instruccion_Interfaz::Instruccion_Interfaz(const std::string& opcode, const std::string& operando):
opcode_(opcode), operando_(operando)
{
}

// int Instruccion_Interfaz::isInmediato(int& operandoI)
// {
//   bool posible_inmediato = false;
//   try
//   {
//     if (operando_[0] == '=')
//     {
//       operando_.erase(operando_.begin());
//       posible_inmediato = true;
//     }
//     operandoI = std::stoi(operando_);
//     if (posible_inmediato)
//     {
//       return Inmediato;
//     }
//     return Directo;
//   }
//   catch (std::invalid_argument &e)
//   {
//     if (posible_inmediato)
//     {
//       throw Halt("La operación " + opcode_ + " =" + operando_ + " no es valida\n");
//     }
//     throw Halt("La operación " + opcode_ + ' ' + operando_ + " no es valida\n");
//   }
// }

std::ostream& Instruccion_Interfaz::mostrar (std::ostream& os)
{
  os << opcode_ << ' '<< operando_ << '\n';
  return os;
}

int Instruccion_Interfaz::isIndirecto(int& operandoI)
{
  bool posible_indirecto = false;
  try
  {
    if (operando_[0] == '*')
    {
      operando_.erase(operando_.begin());
      posible_indirecto = true;
    }
    operandoI = std::stoi(operando_);
    if (posible_indirecto)
    {
      return Indirecto;
    }
    return Directo;
  }
  catch (std::invalid_argument &e)
  {
    if (posible_indirecto)
    {
      throw Halt("La operación " + opcode_ + " *" + operando_ + " no es valida\n");
    }
    throw Halt("La operación " + opcode_ + ' ' + operando_ + " no es valida\n");
  }
}

int Instruccion_Interfaz::isInmediatoOIndirecto(int& operandoI)
{
  bool posible_indirecto = false;
  bool posible_inmediato = false;
  try
  {
    if (operando_[0] == '*')
    {
      operando_.erase(operando_.begin());
      posible_indirecto = true;
    }
    else if (operando_[0] == '=')
    {
      operando_.erase(operando_.begin());
      posible_inmediato = true;
    }
    operandoI = std::stoi(operando_);
    if (posible_indirecto)
    {
      return Indirecto;
    }
    else if (posible_inmediato)
    {
      return Inmediato;
    }
    return Directo;
  }
  catch (std::invalid_argument &e)
  {
    if (posible_indirecto)
    {
      throw Halt("La operación " + opcode_ + " *" + operando_ + " no es valida\n");
    }
    else if (posible_inmediato)
    {
      throw Halt("La operación " + opcode_ + " =" + operando_ + " no es valida\n");
    }
    throw Halt("La operación " + opcode_ + ' ' + operando_ + " no es valida\n");
  }
}
