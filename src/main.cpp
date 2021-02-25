#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "../include/instruccion.hpp"
#include "../include/programa.hpp"

void compilar(std::fstream&);

int main()
{
  std::fstream f_instrucciones;
  f_instrucciones.open("test/test1.ram", std::ios::in);
  if (!f_instrucciones)
  {
    std::cout << "Fichero no se ha creado/abierto correctamente\n";
    return -1;
  }
  std::cout << "Fichero abierto correctamente\n";
  compilar(f_instrucciones);

  f_instrucciones.close();
  return 0;
}

void compilar(std::fstream& f_instrucciones)
{
  // TODO ¿Debería ser Singleton la clase "Programa"?
  Programa programa;
  std::string linea;
  std::string palabra1;
  std::string palabra2;
  std::string palabra3;
  while(getline(f_instrucciones, linea))
  {
    std::stringstream linea_stream(linea);
    if (linea[0] != '#')
    {
      while(linea_stream >> palabra1)
      {
        if (palabra1[palabra1.size() - 1] == ':')
        {
          std::cout << "Es una etiqueta: " << palabra1 << "que apunta a: " << programa.get_sz() << '\n';
          linea_stream >> palabra2;
          linea_stream >> palabra3;
          std::cout << "Esta es la operacion: " << palabra2 << '\n';
          std::cout << "Y esta es el valor: " << palabra3 << '\n';
          programa.insertar_instruccion(Instruccion(palabra2, palabra3));
        }
        else
        {
          std::cout << "No es una etiqueta\n";
          linea_stream >> palabra2;
          std::cout << "Esta es la operacion: " << palabra1 << '\n';
          std::cout << "Y esta es el valor: " << palabra2 << '\n';
          programa.insertar_instruccion(Instruccion(palabra1, palabra2));
        }
      }
      std::cout << "\n\n";
    }
  }
}
