#include "../include/programa.hpp"

Programa::Programa(char* fichero)
{
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

void Programa::insertar_instruccion(Instruccion instruccion)
{
  programa_.push_back(instruccion);
}

const size_t Programa::get_sz()
{
  return programa_.size();
}

const size_t Programa::get_sz() const
{
  return programa_.size();
}

const Instruccion& Programa::operator [](int index)
{
  return programa_[index];
}

const Instruccion& Programa::operator [](int index) const
{
  return programa_[index];
}

int Programa::ejecutar(bool debug) const
{
  Memoria* memoria = &Memoria::get_instance();
  CintaSalida* cinta_salida = &CintaSalida::get_instance();
  CintaEntrada* cinta_entrada = &CintaEntrada::get_instance();
  Pc* pc = &Pc::get_instance();
  std::string opcode = programa_[pc->get_Pc()].opcode_;
  std::string operando = programa_[pc->get_Pc()].operando_;
  if (opcode == "load" || opcode == "LOAD")
  {
    if (debug) std::cout << opcode << ' ' << operando << '\n';
    if (isInmediato(opcode, operando))
      memoria -> escribir(0, std::stoi(operando));
    else
      memoria -> escribir(0, (*memoria)[std::stoi(operando)]);
    pc -> incrementar();
    return 1;
  }
  else if (opcode == "store" || opcode == "STORE") // TODO *
  {
    if (debug) std::cout << opcode << ' ' << operando << '\n';
    try
    {
      int i_operando = std::stoi(operando);
      memoria -> escribir(i_operando, memoria->get_acumulador());
    }
    catch (std::invalid_argument &e)
    {
      if (operando[0] == '*')
      {
        operando.erase(operando.begin());
        memoria -> escribir((*memoria)[std::stoi(operando)], memoria->get_acumulador());
      }
      else
      {
        throw Halt("La operación " + opcode + ' ' + operando + " no es valida\n");
      }
    }
    pc -> incrementar();
    return 1;
  }
  else if (opcode == "add" || opcode == "ADD")
  {
    if (debug) std::cout << opcode << ' ' << operando << '\n';
    if (isInmediato(opcode, operando))
      memoria -> escribir(0, memoria->get_acumulador() + std::stoi(operando));
    else
      memoria -> escribir(0, memoria->get_acumulador() + (*memoria)[std::stoi(operando)]);
    pc -> incrementar();
    return 1;
  }
  else if (opcode == "sub" || opcode == "SUB")
  {
    if (debug) std::cout << opcode << ' ' << operando << '\n';
    if (isInmediato(opcode, operando))
      memoria -> escribir(0, memoria->get_acumulador() - std::stoi(operando));
    else
      memoria -> escribir(0, memoria->get_acumulador() - (*memoria)[std::stoi(operando)]);
    pc -> incrementar();
    return 1;
  }
  else if (opcode == "mult" || opcode == "MULT")
  {
    if (debug) std::cout << opcode << ' ' << operando << '\n';
    if (isInmediato(opcode, operando))
      memoria -> escribir(0, memoria->get_acumulador() * std::stoi(operando));
    else
      memoria -> escribir(0, memoria->get_acumulador() * (*memoria)[std::stoi(operando)]);
    pc -> incrementar();
    return 1;
  }
  else if(opcode == "div" || opcode == "DIV")
  {
    if (debug) std::cout << "Voy a hace un MULT\n";
    if (isInmediato(opcode, operando))
      memoria -> escribir(0, memoria->get_acumulador() / std::stoi(operando));
    else
      memoria -> escribir(0, memoria->get_acumulador() / (*memoria)[std::stoi(operando)]);
    pc -> incrementar();
    return 1;
  }
  else if (opcode == "read" || opcode == "READ") // TODO *
  {
    if (debug) std::cout << "READ: \n";
    if (operando[0] != '*')
    {
      memoria -> escribir(std::stoi(operando), cinta_entrada->read());
    }
    else
    {
      operando.erase(operando.begin());
      memoria -> escribir((*memoria)[std::stoi(operando)], cinta_entrada->read());
    }
    pc -> incrementar();
    return 1;
  }
  else if (opcode == "write" || opcode == "WRITE")
  {
    if (debug) std::cout << opcode << ' ' << operando << '\n';
    if (isInmediato(opcode, operando))
      cinta_salida -> write(std::stoi(operando));
    else
      cinta_salida->write((*memoria)[std::stoi(operando)]);
    pc -> incrementar();
    return 1;
  }
  else if (opcode == "jump" || opcode == "JUMP")
  {
    if (debug) std::cout << "JUMP a " << operando << '\n';
    pc -> jump(set_etiquetas_.buscar(operando));
    return 1;
  }
  else if (opcode == "jgtz" || opcode == "JGTZ")
  {
    if (memoria->get_acumulador() > 0)
    {
      if (debug) std::cout << "JGTZ a " << operando << '\n';
      pc -> jump(set_etiquetas_.buscar(operando));
    }
    else
    {
      if (debug) std::cout << "Sorteo JGTZ";
      pc -> incrementar();
    }
    return 1;
  }
  else if (opcode == "jzero" || opcode == "JZERO")
  {
    if (memoria->get_acumulador() == 0)
    {
      if (debug) std::cout << "JZERO a " << operando << '\n';
      pc -> jump(set_etiquetas_.buscar(operando));
    }
    else
    {
      if (debug) std::cout << "Sorteo JZERO\n";
      pc -> incrementar();
    }
    return 1;
  }
  else if (opcode == "halt" || opcode == "HALT")
  {
    throw Halt("El programa terminó correctamente\n", true);
  }
  else
  {
    throw Halt("La operacion " + opcode + " no existe\n");
  }
  return 0;
}

bool isInmediato(const std::string& opcode, std::string& operando)
{
  bool literal = false;
  try
  {
    if (operando[0] == '=')
    {
      operando.erase(operando.begin());
      literal = true;
    }
    std::stoi(operando);
    return literal;
  }
  catch (std::invalid_argument &e)
  {
    throw Halt("La operación " + opcode + ' ' + operando + " no es valida\n");
  }
}
