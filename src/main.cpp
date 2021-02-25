#include <iostream>
#include <string>
#include <fstream>

int main()
{
  std::fstream f_instrucciones;
  f_instrucciones.open("test/test1.ram", std::ios::in);
  if(!f_instrucciones)
  {
    std::cout << "Fichero no se ha creado/abierto correctamente\n";
    return -1;
  }
  std::cout << "Fichero abierto correctamente\n";
  std::string mostrar;
  while(getline(f_instrucciones, mostrar))
  {
    if (mostrar[0] != '#')
    {
      std::cout << mostrar << '\n';
    }
  }

  f_instrucciones.close();
  return 0;
}
