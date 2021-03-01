#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "../include/programa.hpp"

void cargarCinta(char*);
void ejecutar(Programa&, char*);
void volcarCinta(char*);
bool menu();
void ayuda();

int main(int argc, char *argv[])
{
  try
  {
    if (argc != 5)
    {
      ayuda();
      throw "Se necesita cuatro valores\n";
    }
    cargarCinta(argv[2]);
    Programa programa(argv[1]); // Cargar Programa
    ejecutar(programa, argv[4]);
  }
  catch(const std::exception& e)
  {
    volcarCinta(argv[3]);
    std::cout << e.what();
  }
  catch(const char* message)
  {
    volcarCinta(argv[3]);
    std::cout << message;
  }
  catch(const Halt &e)
  {
    volcarCinta(argv[3]);
    std::cerr << "Error: " << e.what() << "|| Línea " << Pc::get_instance().get_Pc() + 1<< '\n';
  }
  catch(...)
  {
    volcarCinta(argv[3]);
    std::cout << "Ha habido un error no especificado\n";
  }
  return 0;
}

void cargarCinta(char* fichero)
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
    cinta_aux.push_back(std::stoi(palabra));
  }
  CintaEntrada::get_instance().set_cinta_entrada(cinta_aux);
  f_cinta_input.close();
}

void volcarCinta(char* fichero)
{
  std::fstream f_cinta_output;
  f_cinta_output.open(fichero, std::ios::out);
  if(!f_cinta_output)
  {
    throw "No se ha podido escribir en la cinta de salida\n";
  }
  for (size_t i = 0; i < CintaSalida::get_instance().get_sz(); i++)
  {
    f_cinta_output << CintaSalida::get_instance()[i] << ' ';
  }
  f_cinta_output.close();
}

void ejecutar(Programa& programa, char* debug)
{
  bool b_debug = std::stoi(debug);

  if (b_debug)
  {
    do
    {
      if (!menu()) break;
      programa.ejecutar(b_debug);
    }
    while (!programa.isHalt());
  }
  else
  {
    while (!programa.isHalt())
    {
      programa.ejecutar(b_debug);
    };
  }
  std::cout << "El programa se ejecutó correctamente\n";
}

bool menu()
{
  char opcion;
  do
  {
    std::cout << "r: ver los registros\nt: traza\ne: ejecutar\ns: desensamblador\ni: ver cinta entrada\no: ver cinta salida\nh: ayuda\nx: salir\n";
    std::cin >> opcion;
    switch(opcion)
    {
      case 't':
        break;
      case 'r':
        Memoria::get_instance().mostrar();
        break;
      case 'i':
        for (size_t i = 0; i < CintaEntrada::get_instance().get_sz(); i++)
        {
          std::cout << CintaEntrada::get_instance()[i] << '\n';
        }
        break;
      case 'o':
        for (size_t i = 0; i < CintaSalida::get_instance().get_sz(); i++)
        {
          std::cout << CintaSalida::get_instance()[i] << '\n';
        }
        break;
      case 'x':
        std::cout << "Cerrando programa\n";
        break;
      case 'h':
        ayuda();
        break;
      default:
        std::cout << "Esa opción no esta contemplada\n";
    }
  } while (opcion != 't' && opcion != 'x' && opcion != 'e');
  if (opcion == 'x') return false;
  return true;
}

void ayuda()
{
  std::cout << "Ejecute \"./bin/main <input_tape> <output_tape> <debug>[0|1]\"\n";
}
