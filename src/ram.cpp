#include "../include/ram.hpp"

Ram::Ram(char** argv) :
  cintaEntrada_(argv[2]), // Cargar Cinta
  programa_(argv[1], memoria_, cintaEntrada_, cintaSalida_) // Cargar Programa
{
  halt_ = false;
  argumentos_ = argv;
  debug_ = std::stoi(argumentos_[4]);
}

void Ram::volcarCinta(char* fichero)
{
  if (cintaSalida_.get_sz() > 0)
  {
    cintaSalida_.volcar(fichero);
  }
}

void Ram::ejecutar()
{
  try
  {
    inner_ejecutar();
  }
  catch(const Halt &e)
  {
    std::cerr << "Error en tiempo de ejecución: " << e.what();
    volcarCinta(argumentos_[3]);
  }
  if (!debug_)
  {
    std::cout << "Número de ejecuciones: " << programa_.numeroEjecuciones() << '\n';
  }
  volcarCinta(argumentos_[3]);
}

void Ram::inner_ejecutar()
{
  bool ejecutar = !debug_;
  if (debug_)
  {
    while (!halt_)
    {
      if (!menu(ejecutar))
      {
        break;
      }
      halt_ = programa_.ejecutar();
    }
  }
  if (ejecutar)
  {
    while (!halt_)
    {
      halt_ = programa_.ejecutar();
    };
  }
}

bool Ram::menu(bool& ejecutar)
{
  char opcion;
  do
  {
    std::cout << "r: ver los registros\nt: traza\ne: ejecutar\ns: desensamblador\ni: ver cinta entrada\no: ver cinta salida\nh: ayuda\nx: salir\n";
    std::cin >> opcion;
    switch(opcion)
    {
      case 't':
        programa_.peek();
        break;
      case 'e':
        ejecutar = true;
        break;
      case 'r':
        memoria_.mostrar();
        break;
      case 'i':
        cintaEntrada_.mostrar();
        break;
      case 'o':
        cintaSalida_.mostrar();
        break;
      case 'x':
        std::cout << "Cerrando programa\n";
        break;
      case 'h':
        ayuda();
        break;
      case 's':
        programa_.peek();
        break;
      default:
        std::cout << "Esa opción no esta contemplada\n";
    }
  } while (opcion != 't' && opcion != 'x' && opcion != 'e');
  if (opcion == 'x' || opcion == 'e') return false;
  return true;
}

void ayuda()
{
  std::cout << "Ejecute \"./bin/main <input_tape> <output_tape> <debug>[0|1]\"\n";
}
