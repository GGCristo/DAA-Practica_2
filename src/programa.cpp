#include "../include/programa.hpp"

Programa::Programa(char* fichero)
{
  halt_ = false;
  std::fstream f_programaRAM;
  f_programaRAM.open(fichero, std::ios::in);
  if (!f_programaRAM)
  {
    throw "No se ha podido cargar el programa";
  }
  std::string linea, palabra1, palabra2, palabra3;
  while(getline(f_programaRAM, linea))
  {
    std::stringstream linea_stream(linea);
    if (linea[0] != '#' && linea[0] != ';')
    {
      while(linea_stream >> palabra1)
      {
        // La línea tiene etiqueta
        if (palabra1[palabra1.size() - 1] == ':')
        {
          palabra1.erase(palabra1.end() - 1);
          linea_stream >> palabra2;
          linea_stream >> palabra3;
          if (palabra2[palabra2.size() - 1] == ':' || palabra3[palabra3.size() - 1] == ':')
          {
            throw "Solo puede haber una etiqueta por línea\n";
          }
          set_etiquetas_.insertar(palabra1, programa_.size());
          insertar_instruccion(Instruccion(palabra2, palabra3));
        }
        // La línea no tiene etiqueta
        else
        {
          linea_stream >> palabra2;
          if (palabra2[palabra2.size() - 1] == ':')
          {
            throw "La etiqueta tiene que ser el primer valor de la línea\n";
          }
          insertar_instruccion(Instruccion(palabra1, palabra2));
        }
      }
    }
  }
  f_programaRAM.close();
}

const bool Programa::isHalt()
{
  return halt_;
}

void Programa::insertar_instruccion(Instruccion instruccion)
{
  programa_.push_back(instruccion);
}

const Instruccion& Programa::operator [](int index)
{
  return programa_[index];
}

const Instruccion& Programa::operator [](int index) const
{
  return programa_[index];
}

void Programa::ejecutar(bool debug)
{
  Memoria* memoria = &Memoria::get_instance();
  CintaSalida* cinta_salida = &CintaSalida::get_instance();
  CintaEntrada* cinta_entrada = &CintaEntrada::get_instance();
  Pc* pc = &Pc::get_instance();
  if (pc->get_Pc() >= programa_.size())
  {
    throw Halt("SEGFAULT: Se ha terminado el programa sin alcanzar el estado HALT\n");
  }
  std::string opcode = programa_[pc->get_Pc()].opcode_;
  std::string operando = programa_[pc->get_Pc()].operando_;
  if (debug) std::cout << opcode << ' ' << operando << '\n';
  if (opcode == "load" || opcode == "LOAD")
  {
    if (isInmediato(opcode, operando))
    {
      memoria -> escribir(0, std::stoi(operando));
    }
    else
    {
      memoria -> escribir(0, (*memoria)[std::stoi(operando)]);
    }
    pc -> incrementar();
  }
  else if (opcode == "store" || opcode == "STORE")
  {
    if (isIndirecto(opcode, operando))
    {
      memoria -> escribir((*memoria)[std::stoi(operando)], memoria->get_acumulador());
    }
    else
    {
      memoria -> escribir(std::stoi(operando), memoria->get_acumulador());
    }
    pc -> incrementar();
  }
  else if (opcode == "add" || opcode == "ADD")
  {
    if (isInmediato(opcode, operando))
    {
      memoria -> escribir(0, memoria->get_acumulador() + std::stoi(operando));
    }
    else
    {
      memoria -> escribir(0, memoria->get_acumulador() + (*memoria)[std::stoi(operando)]);
    }
    pc -> incrementar();
  }
  else if (opcode == "sub" || opcode == "SUB")
  {
    if (isInmediato(opcode, operando))
    {
      memoria -> escribir(0, memoria->get_acumulador() - std::stoi(operando));
    }
    else
    {
      memoria -> escribir(0, memoria->get_acumulador() - (*memoria)[std::stoi(operando)]);
    }
    pc -> incrementar();
  }
  else if (opcode == "mult" || opcode == "MULT")
  {
    if (isInmediato(opcode, operando))
    {
      memoria -> escribir(0, memoria->get_acumulador() * std::stoi(operando));
    }
    else
    {
      memoria -> escribir(0, memoria->get_acumulador() * (*memoria)[std::stoi(operando)]);
    }
    pc -> incrementar();
  }
  else if(opcode == "div" || opcode == "DIV")
  {
    if (isInmediato(opcode, operando))
    {
      memoria -> escribir(0, memoria->get_acumulador() / std::stoi(operando));
    }
    else
    {
      memoria -> escribir(0, memoria->get_acumulador() / (*memoria)[std::stoi(operando)]);
    }
    pc -> incrementar();
  }
  else if (opcode == "read" || opcode == "READ")
  {
    if (isIndirecto(opcode, operando))
    {
      memoria -> escribir((*memoria)[std::stoi(operando)], cinta_entrada->read());
    }
    else
    {
      memoria -> escribir(std::stoi(operando), cinta_entrada->read());
    }
    pc -> incrementar();
  }
  else if (opcode == "write" || opcode == "WRITE")
  {
    if (isInmediato(opcode, operando))
    {
      cinta_salida -> write(std::stoi(operando));
    }
    else
    {
      cinta_salida->write((*memoria)[std::stoi(operando)]);
    }
    pc -> incrementar();
  }
  else if (opcode == "jump" || opcode == "JUMP")
  {
    pc -> jump(set_etiquetas_.buscar(operando));
  }
  else if (opcode == "jgtz" || opcode == "JGTZ")
  {
    if (memoria->get_acumulador() > 0)
    {
      pc -> jump(set_etiquetas_.buscar(operando));
    }
    else
    {
      if (debug) std::cout << "[No se realiza el salto\n]";
      pc -> incrementar();
    }
  }
  else if (opcode == "jzero" || opcode == "JZERO")
  {
    if (memoria->get_acumulador() == 0)
    {
      pc -> jump(set_etiquetas_.buscar(operando));
    }
    else
    {
      if (debug) std::cout << "[No se realiza el salto]\n";
      pc -> incrementar();
    }
  }
  else if (opcode == "halt" || opcode == "HALT")
  {
    halt_ = true;
  }
  else
  {
    throw Halt("La operacion " + opcode + " no existe\n");
  }
}

bool isInmediato(const std::string& opcode, std::string& operando)
{
  bool posible_inmediato = false;
  try
  {
    if (operando[0] == '=')
    {
      operando.erase(operando.begin());
      posible_inmediato = true;
    }
    std::stoi(operando);
    return posible_inmediato;
  }
  catch (std::invalid_argument &e)
  {
    if (posible_inmediato)
    {
      throw Halt("La operación " + opcode + " =" + operando + " no es valida\n");
    }
    throw Halt("La operación " + opcode + ' ' + operando + " no es valida\n");
  }
}

bool isIndirecto(const std::string& opcode, std::string& operando)
{
  bool posible_indirecto = false;
  try
  {
    if (operando[0] == '*')
    {
      operando.erase(operando.begin());
      posible_indirecto = true;
    }
    std::stoi(operando);
    return posible_indirecto;
  }
  catch (std::invalid_argument &e)
  {
    if (posible_indirecto)
    {
      throw Halt("La operación " + opcode + " *" + operando + " no es valida\n");
    }
    throw Halt("La operación " + opcode + ' ' + operando + " no es valida\n");
  }
}
