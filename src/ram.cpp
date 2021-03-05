#include "../include/ram.hpp"

Ram::Ram(char** argv) : programa_(argv[1], cintaEntrada_, cintaSalida_) // Cargar Programa
{
  halt_ = false;
  argumentos_ = argv;
  debug_ = std::stoi(argumentos_[4]);
  cargarCinta(argumentos_[2]);
}

void Ram::cargarCinta(char* fichero)
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
  cintaEntrada_.set_cinta_entrada(cinta_aux);
  f_cinta_input.close();
}

void Ram::volcarCinta(char* fichero)
{
  std::cout << "Escribiendo en la cinta de Salida...\n";
  std::fstream f_cinta_output;
  f_cinta_output.open(fichero, std::ios::out);
  if(!f_cinta_output)
  {
    throw "No se ha podido escribir en la cinta de salida\n";
  }
  for (size_t i = 0; i < cintaSalida_.get_sz(); i++)
  {
    // std::cout << "Escribo: " << cintaSalida_[i] << '\n';
    f_cinta_output << cintaSalida_[i] << ' ';
  }
  f_cinta_output.close();
}

bool Ram::isHalt()
{
  return halt_;
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
  }
  volcarCinta(argumentos_[3]);
}

void Ram::inner_ejecutar()
{
  bool ejecutar = !debug_;
  if (debug_)
  {
    while (!isHalt())
    {
      if (!menu(memoria_, cintaEntrada_, cintaSalida_, ejecutar)) break;
      halt_ = programa_.ejecutar(memoria_, debug_);
    }
  }
  if (ejecutar)
  {
    while (!isHalt())
    {
      halt_ = programa_.ejecutar(memoria_, debug_);
    };
  }
}

bool Ram::menu(Memoria& memoria, CintaEntrada& cintaEntrada, CintaSalida& cintaSalida, bool& ejecutar)
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
      case 'e':
        ejecutar = true;
        break;
      case 'r':
        memoria.mostrar();
        break;
      case 'i':
        cintaEntrada.mostrar();
        break;
      case 'o':
        cintaSalida.mostrar();
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
  if (opcion == 'x' || opcion == 'e') return false;
  return true;
}

void ayuda()
{
  std::cout << "Ejecute \"./bin/main <input_tape> <output_tape> <debug>[0|1]\"\n";
}
