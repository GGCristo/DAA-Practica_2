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
          std::cout << "Meto: " << palabra2 << " con " << palabra3 << '\n';
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
          std::cout << "Meto: " << palabra1 << " con " << palabra2 << '\n';
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
  // TODO Acepta tanto todo mayuscula como minuscula
  if (opcode == "load" || opcode == "LOAD")
  {
    std::cout << "LOAD: " << operando << '\n';
    if(operando[0] != '=')
    {
      memoria->escribir(0, (*memoria)[std::stoi(operando)]);
    }
    else
    {
      operando.erase(operando.begin());
      memoria->escribir(0, std::stoi(operando));
    }
    // std::cin.get();
    pc->incrementar();
    return 1;
  }
  else if (opcode == "store" || opcode == "STORE")
  {
    std::cout << "STORE " << operando << '\n';
    if (operando[0] != '*')
    {
      memoria->escribir(std::stoi(operando), memoria->get_acumulador());
    }
    else
    {
      operando.erase(operando.begin());
      memoria->escribir((*memoria)[std::stoi(operando)], memoria->get_acumulador());
    }
    // std::cin.get();
    pc->incrementar();
    return 1;
  }
  else if (opcode == "add" || opcode == "ADD")
  {
    std::cout << "Voy a hace un ADD\n";
    if (operando[0] != '=')
    {
      memoria->escribir(0, memoria->get_acumulador() + (*memoria)[std::stoi(operando)]);
    }
    else
    {
      operando.erase(operando.begin());
      memoria->escribir(0, memoria->get_acumulador() + std::stoi(operando));
    }
    // std::cin.get();
    pc->incrementar();
    return 1;
  }
  else if (opcode == "sub" || opcode == "SUB")
  {
    std::cout << "Voy a hace un SUB\n";
    if (operando[0] != '=')
    {
      memoria->escribir(0, memoria->get_acumulador() - (*memoria)[std::stoi(operando)]);
    }
    else
    {
      operando.erase(operando.begin());
      memoria->escribir(0, memoria->get_acumulador() - std::stoi(operando));
    }
    // std::cin.get();
    pc->incrementar();
    return 1;
  }
  else if (opcode == "mult" || opcode == "MULT")
  {
    std::cout << "Voy a hace un MULT\n";
    if (operando[0] != '=')
    {
      memoria->escribir(0, memoria->get_acumulador() * (*memoria)[std::stoi(operando)]);
    }
    else
    {
      operando.erase(operando.begin());
      memoria->escribir(0, memoria->get_acumulador() * std::stoi(operando));
    }
    // std::cin.get();
    pc->incrementar();
    return 1;
  }
  else if(opcode == "div" || opcode == "DIV")
  {
    std::cout << "Voy a hace un DIV\n";
    if (operando[0] != '=')
    {
      memoria->escribir(0, memoria->get_acumulador() / (*memoria)[std::stoi(operando)]);
    }
    else
    {
      operando.erase(operando.begin());
      memoria->escribir(0, memoria->get_acumulador() / std::stoi(operando));
    }
    // std::cin.get();
    pc->incrementar();
    return 1;
  }
  else if (opcode == "read" || opcode == "READ")
  {
    std::cout << "READ: \n";
    if (operando[0] != '*')
    {
      memoria->escribir(std::stoi(operando), cinta_entrada->read());
    }
    else
    {
      operando.erase(operando.begin());
      memoria->escribir((*memoria)[std::stoi(operando)], cinta_entrada->read());
    }
    // std::cin.get();
    pc->incrementar();
    return 1;
  }
  else if (opcode == "write" || opcode == "WRITE")
  {
    std::cout << "Voy a hace un WRITE con el valor: " << operando << '\n';
    if (operando[0] != '=')
    {
      cinta_salida->write((*memoria)[std::stoi(operando)]);
    }
    else
    {
      operando.erase(operando.begin());
      cinta_salida->write(std::stoi(operando));
    }
    // std::cin.get();
    pc->incrementar();
    return 1;
  }
  else if (opcode == "jump" || opcode == "JUMP")
  {
    std::cout << "Voy a hace un JUMP\n";
    pc -> jump(set_etiquetas_.buscar(operando));
    // std::cin.get();
    return 1;
  }
  else if (opcode == "jgtz" || opcode == "JGTZ")
  {
    if (memoria->get_acumulador() > 0)
    {
      std::cout << "Voy a hace un JGTZ\n";
      pc -> jump(set_etiquetas_.buscar(operando));
    }
    else
    {
      std::cout << "No hago el salto JGTZ";
      pc -> incrementar();
    }
    // std::cin.get();
    return 1;
  }
  else if (opcode == "jzero" || opcode == "JZERO")
  {
    if (memoria->get_acumulador() == 0)
    {
      std::cout << "Voy a hace un JZERO\n";
      pc -> jump(set_etiquetas_.buscar(operando));
    }
    else
    {
      std::cout << "No hago el salto JZERO\n";
      pc -> incrementar();
    }
    // std::cin.get();
    return 1;
  }
  else if (opcode == "halt" || opcode == "HALT")
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
