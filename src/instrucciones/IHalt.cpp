#include "../../include/instrucciones/IHalt.hpp"

IHalt::IHalt()
{

}

int IHalt::ejecutar()
{
  std::cout << "Soy el Halt\n";
  return 1;
}
