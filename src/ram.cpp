#include "../include/ram.hpp"

Ram::Ram(char *argv[]) : programa_(argv[1]) // Cargar Programa
{
  std::cout << "Entro en el constructor\n";
  halt_ = false;
  debug_ = std::stoi(argv[4]);
  cargarCinta(argv[2]);
  std::cout << "Salgo del constructor\n";
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
  CintaEntrada::get_instance().set_cinta_entrada(cinta_aux);
  f_cinta_input.close();
}

void Ram::volcarCinta(char* fichero)
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

bool Ram::isHalt()
{
  return halt_;
}

void Ram::ejecutar()
{
  if (debug_)
  {
    do
    {
      if (!menu()) break;
      halt_ = programa_.ejecutar(debug_);
    }
    while (!isHalt());
  }
  else
  {
    while (!isHalt())
    {
      halt_ = programa_.ejecutar(debug_);
    };
  }
  std::cout << "El programa se ejecutó correctamente\n";
}

bool Ram::menu()
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
