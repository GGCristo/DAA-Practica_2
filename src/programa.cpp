#include "../include/programa.hpp"
#include "../include/instrucciones/cabeceras.hpp"

Programa::Programa(const char* fichero, Memoria& memoria, CintaEntrada& cintaEntrada, CintaSalida& cintaSalida)
{
  ejecuciones_ = 0;
  std::fstream f_programaRAM;
  f_programaRAM.open(fichero, std::ios::in);
  if (!f_programaRAM)
  {
    throw "No se ha podido cargar el programa";
  }
  std::string linea, palabra1, palabra2, palabra3, comentario;
  while(getline(f_programaRAM, linea))
  {
    std::stringstream linea_stream(linea);
    if (linea[0] != '#' && linea[0] != ';')
    {
      if (linea_stream >> palabra1)
      {
        // La línea tiene etiqueta
        if (palabra1[palabra1.size() - 1] == ':')
        {
          palabra1.erase(palabra1.end() - 1);
          if (!(linea_stream >> palabra2)) continue; // Si solo esta la etiqueta sigue
          linea_stream >> palabra3;
          if (palabra2[palabra2.size() - 1] == ':' || palabra3[palabra3.size() - 1] == ':')
          {
            throw "Solo puede haber una etiqueta por línea\n";
          }
          set_etiquetas_.insertar(palabra1, programa_.size());
          insertar_instruccion(palabra2, palabra3, memoria, cintaEntrada, cintaSalida);
        }
        // La línea no tiene etiqueta
        else
        {
          linea_stream >> palabra2;
          if (palabra2[palabra2.size() - 1] == ':')
          {
            throw "La etiqueta tiene que ser el primer valor de la línea\n";
          }
          insertar_instruccion(palabra1, palabra2, memoria, cintaEntrada, cintaSalida);
        }
        // Comentarios al final
        if (linea_stream >> comentario)
        {
          if (comentario[0] == '#' || comentario[0] == ';') continue;
          else throw Halt("Solo puede haber una instrucción por línea\n");
        }
      }
    }
  }
  f_programaRAM.close();
}

void Programa::insertar_instruccion(std::string& opcode, std::string& operando,
                                    Memoria& memoria, CintaEntrada& cintaEntrada,
                                    CintaSalida& cintaSalida)
{
  if (opcode == "load" || opcode == "LOAD")
  {
    programa_.push_back(std::make_unique<ILoad>(opcode, operando, memoria));
  }
  else if (opcode == "store" || opcode == "STORE")
  {
    programa_.push_back(std::make_unique<IStore>(opcode, operando, memoria));
  }
  else if (opcode == "add" || opcode == "ADD")
  {
    programa_.push_back(std::make_unique<IAdd>(opcode, operando, memoria));
  }
  else if (opcode == "sub" || opcode == "SUB")
  {
    programa_.push_back(std::make_unique<ISub>(opcode, operando, memoria));
  }
  else if (opcode == "mult" || opcode == "MULT")
  {
    programa_.push_back(std::make_unique<IMult>(opcode, operando, memoria));
  }
  else if(opcode == "div" || opcode == "DIV")
  {
    programa_.push_back(std::make_unique<IDiv>(opcode, operando, memoria));
  }
  else if (opcode == "read" || opcode == "READ")
  {
    programa_.push_back(std::make_unique<IRead>(opcode, operando, memoria, cintaEntrada));
  }
  else if (opcode == "write" || opcode == "WRITE")
  {
    programa_.push_back(std::make_unique<IWrite>(opcode, operando, memoria, cintaSalida));
  }
  else if (opcode == "jump" || opcode == "JUMP")
  {
    programa_.push_back(std::make_unique<IJump>(opcode, operando, pc_ , set_etiquetas_));
  }
  else if (opcode == "jgtz" || opcode == "JGTZ")
  {
    programa_.push_back(std::make_unique<IJgtz>(opcode, operando, memoria, pc_, set_etiquetas_));
  }
  else if (opcode == "jzero" || opcode == "JZERO")
  {
    programa_.push_back(std::make_unique<IJzero>(opcode, operando, memoria, pc_ , set_etiquetas_));
  }
  else if (opcode == "halt" || opcode == "HALT")
  {
    programa_.push_back(std::make_unique<IHalt>(opcode));
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

int Programa::numeroEjecuciones()
{
  return ejecuciones_;
}

int Programa::ejecutar()
{
  try
  {
    if (pc_.peek() >= programa_.size())
    {
      throw Halt("Se ha llegado al final del programa sin invocar al Halt\n");
    }
    ejecuciones_++;
    return programa_[pc_.acceso()] -> ejecutar();
  }
  catch(Halt &e)
  {
    e.acoplar("|| Linea " + std::to_string(pc_.peek()) + '\n');
    throw;
  }
}

void Programa::peek()
{
  programa_[pc_.peek()] -> mostrar();
}
