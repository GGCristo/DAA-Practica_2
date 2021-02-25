#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "../include/instruccion.hpp"
#include "../include/programa.hpp"
#include "../include/cinta_salida.hpp"
#include "../include/cinta_entrada.hpp"
#include "../include/set_etiquetas.hpp"

void cargarPrograma(char*);
void leerCinta(char*);

int main(int argc, char *argv[])
{
  try
  {
    leerCinta(argv[2]);
    cargarPrograma(argv[1]);
  }
  catch(const std::exception& e)
  {
    std::cout << e.what();
  }
  catch(const char* message)
  {
    std::cout << message;
  }
  return 0;
}

void leerCinta(char* fichero)
{
  std::fstream f_cinta_input;
  f_cinta_input.open(fichero, std::ios::in);
  if (!f_cinta_input)
  {
    throw "No se ha podido leer la cinta\n";
  }
  std::string palabra;
  std::vector<int> cinta_aux;
  while(f_cinta_input >> palabra)
  {
    std::stringstream to_int(palabra);
    int entero = 0;
    to_int >> entero;
    cinta_aux.push_back(entero);
  }
  CintaEntrada::get_instance().set_cinta_entrada(cinta_aux);
  f_cinta_input.close();
}

void cargarPrograma(char* fichero)
{
  std::fstream f_programaRAM;
  f_programaRAM.open(fichero, std::ios::in);
  if (!f_programaRAM)
  {
    throw "No se ha podido cargar el programa";
  }
  // TODO ¿Debería ser Singleton la clase "Programa"?
  Programa programa;
  SetEtiquetas set_etiquetas;
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
          set_etiquetas.insertar(palabra1, programa.get_sz());
          programa.insertar_instruccion(Instruccion(palabra2, palabra3));
        }
        else
        {
          linea_stream >> palabra2;
          programa.insertar_instruccion(Instruccion(palabra1, palabra2));
        }
      }
    }
  }
  f_programaRAM.close();
}
