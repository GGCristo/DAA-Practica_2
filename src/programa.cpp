#include "../include/programa.hpp"
#include "../include/instrucciones/cabeceras.hpp"

Programa::Programa()
{}

Programa::Programa(char* fichero, CintaEntrada& cintaEntrada, CintaSalida& cintaSalida)
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
          insertar_instruccion(palabra2, palabra3, cintaEntrada, cintaSalida);
        }
        // La línea no tiene etiqueta
        else
        {
          linea_stream >> palabra2;
          if (palabra2[palabra2.size() - 1] == ':')
          {
            throw "La etiqueta tiene que ser el primer valor de la línea\n";
          }
          insertar_instruccion(palabra1, palabra2, cintaEntrada, cintaSalida);
        }
      }
    }
  }
  f_programaRAM.close();
}

void Programa::insertar_instruccion(std::string opcode, std::string operando,
                                    CintaEntrada& cintaEntrada, CintaSalida& cintaSalida)
{
  if (opcode == "load" || opcode == "LOAD")
  {
    programa_.push_back(std::make_shared<ILoad>(opcode, operando));
  }
  else if (opcode == "store" || opcode == "STORE")
  {
    programa_.push_back(std::make_shared<IStore>(opcode, operando));
  }
  else if (opcode == "add" || opcode == "ADD")
  {
    programa_.push_back(std::make_shared<IAdd>(opcode, operando));
  }
  else if (opcode == "sub" || opcode == "SUB")
  {
    programa_.push_back(std::make_shared<ISub>(opcode, operando));
  }
  else if (opcode == "mult" || opcode == "MULT")
  {
    programa_.push_back(std::make_shared<IMult>(opcode, operando));
  }
  else if(opcode == "div" || opcode == "DIV")
  {
    programa_.push_back(std::make_shared<IDiv>(opcode, operando));
  }
  else if (opcode == "read" || opcode == "READ")
  {
    programa_.push_back(std::make_shared<IRead>(opcode, operando, cintaEntrada));
  }
  else if (opcode == "write" || opcode == "WRITE")
  {
    programa_.push_back(std::make_shared<IWrite>(opcode, operando, cintaSalida));
  }
  else if (opcode == "jump" || opcode == "JUMP")
  {
    programa_.push_back(std::make_shared<IJump>(opcode, operando, pc_ , set_etiquetas_));
  }
  else if (opcode == "jgtz" || opcode == "JGTZ")
  {
    programa_.push_back(std::make_shared<IJgtz>(opcode, operando, pc_, set_etiquetas_));
  }
  else if (opcode == "jzero" || opcode == "JZERO")
  {
    programa_.push_back(std::make_shared<IJzero>(opcode, operando, pc_ , set_etiquetas_));
  }
  else if (opcode == "halt" || opcode == "HALT")
  {
    programa_.push_back(std::make_shared<IHalt>());
  }
  else
  {
    throw Halt("La operacion " + opcode + " no existe\n");
  }
}

const Instruccion_Interfaz& Programa::operator [](int index)
{
  return *programa_[index];
}

const Instruccion_Interfaz& Programa::operator [](int index) const
{
  return *programa_[index];
}

int Programa::ejecutar(Memoria& memoria, bool debug)
{
  try
  {
    return programa_[pc_.acceso()] -> ejecutar(memoria, debug);
  }
  catch(Halt &e)
  {
    // volcarCinta(argv[3]);
    e.acoplar("|| Linea " + pc_.peek() + '\n');
    throw e;
  }
}
