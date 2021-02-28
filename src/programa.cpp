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
    if (linea[0] != '#')
    {
      while(linea_stream >> palabra1)
      {
        if (palabra1[palabra1.size() - 1] == ':')
        {
          palabra1.erase(palabra1.end() - 1);
          linea_stream >> palabra2;
          linea_stream >> palabra3;
          set_etiquetas_.insertar(palabra1, programa_.size());
          insertar_instruccion(Instruccion(palabra2, palabra3));
        }
        else
        {
          linea_stream >> palabra2;
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

int Programa::ejecutar() const
{
  Memoria* memoria = &Memoria::get_instance();
  CintaSalida* cinta_salida = &CintaSalida::get_instance();
  CintaEntrada* cinta_entrada = &CintaEntrada::get_instance();
  Pc* pc = &Pc::get_instance();
  std::string opcode = programa_[pc->get_Pc()].opcode_;
  std::string operando = programa_[pc->get_Pc()].operando_;
  // TODO Acepta tanto todo mayuscula como minuscula
  if (opcode == "load")
  {
    std::cout << "LOAD: " << std::stoi(operando) << '\n';
    memoria->escribir(0, (*memoria)[std::stoi(operando)]);
    // std::cin.get();
    pc->incrementar();
    return 1;
  } // TODO hacer store *i
  else if (opcode == "store")
  {
    std::cout << "Voy a hace un STORE\n";
    memoria->escribir(std::stoi(operando), memoria->get_acumulador());
    // std::cin.get();
    pc->incrementar();
    return 1;
  }
  else if (opcode == "add")
  {
    std::cout << "Voy a hace un ADD\n";
    memoria->escribir(0, memoria->get_acumulador() + std::stoi(operando));
    // std::cin.get();
    pc->incrementar();
    return 1;
  }
  else if (opcode == "sub")
  {
    std::cout << "Voy a hace un SUB\n";
    memoria->escribir(0, memoria->get_acumulador() - std::stoi(operando));
    // std::cin.get();
    pc->incrementar();
    return 1;
  }
  else if (opcode == "mult")
  {
    std::cout << "Voy a hace un MULT\n";
    memoria->escribir(0, memoria->get_acumulador() * std::stoi(operando));
    // std::cin.get();
    pc->incrementar();
    return 1;
  }
  else if(opcode == "div")
  {
    std::cout << "Voy a hace un DIV\n";
    memoria->escribir(0, memoria->get_acumulador() / std::stoi(operando));
    // std::cin.get();
    pc->incrementar();
    return 1;
  } // TODO hacer read*
  else if (opcode == "read")
  {
    // std::cout << "READ: " << ;
    memoria->escribir(std::stoi(operando), cinta_entrada->read());
    // std::cin.get();
    pc->incrementar();
    return 1;
  }
  else if (opcode == "write")
  {
    std::cout << "Voy a hace un WRITE\n";
    cinta_salida->write((*memoria)[std::stoi(operando)]);
    // std::cin.get();
    pc->incrementar();
    return 1;
  }
  else if (opcode == "jump")
  {
    std::cout << "Voy a hace un JUMP\n";
    pc -> jump(set_etiquetas_.buscar(operando));
    // std::cin.get();
    return 1;
  }
  else if (opcode == "jgtz")
  {
    if (memoria->get_acumulador() > 0)
    {
      std::cout << "Voy a hace un JGTZ\n";
      pc -> jump(set_etiquetas_.buscar(operando));
    }
    else
    {
      pc -> incrementar();
    }
    // std::cin.get();
    return 1;
  }
  else if (opcode == "jzero")
  {
    if (memoria->get_acumulador() == 0)
    {
      std::cout << "Voy a hace un JZERO\n";
      pc -> jump(set_etiquetas_.buscar(operando));
    }
    else
    {
      pc -> incrementar();
    }
    // std::cin.get();
    return 1;
  }
  else if (opcode == "halt")
  {
    std::cout << "El programa termina\n";
  }
  else
  {
    std::cout << "Esa operacion no existe\n";
    std::cout << "Operacion: " << opcode << '\n';
  }
  // std::cin.get();
  return 0;
}
