#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <chrono>
#include "doctest.h"
#include "../include/ram.hpp"

std::string program = "./bin/main"; std::string input = "input_tape.in";
std::string output = "output_tape.out"; std::string debug = "0";

void escribir_fichero_in(const char*, std::vector<std::string>);
void comprobar(const char*, std::vector<std::string>);


TEST_CASE("TEST 1")
{
  char* argumentos[5];
  std::string test = "test/test1.ram";
  argumentos[0] = &program[0]; argumentos[1] = &test[0]; argumentos[2] = &input[0];
  argumentos[3] = &output[0]; argumentos[4] = &debug[0];

  std::vector<std::string> input_v = {"2", "4", "6", "8", "0"};
  std::vector<std::string> expected_v = {"2", "4", "6", "8"};
  escribir_fichero_in(argumentos[2], input_v);

  auto t1 = std::chrono::high_resolution_clock::now();
  Ram ram(argumentos);
  ram.ejecutar();
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "TEST1 time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";
  comprobar(argumentos[3], expected_v);
}

TEST_CASE("TEST 2")
{
  char* argumentos[5];
  std::string test = "test/test2.ram";
  argumentos[0] = &program[0]; argumentos[1] = &test[0]; argumentos[2] = &input[0];
  argumentos[3] = &output[0]; argumentos[4] = &debug[0];

  // Mismo número
  std::vector<std::string> input_v = {"1", "2", "2", "1", "0"};
  std::vector<std::string> expected_v = {"1"};
  escribir_fichero_in(argumentos[2], input_v);
  auto t1 = std::chrono::high_resolution_clock::now();
  Ram ram1(argumentos);
  ram1.ejecutar();
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "TEST2-1 time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";
  comprobar(argumentos[3], expected_v);

  // Numeros distintos TODO Fallo no me deja write =0
  input_v = {"1", "1", "2", "1", "0"};
  expected_v = {"0"};
  escribir_fichero_in(argumentos[2], input_v);
  auto t3 = std::chrono::high_resolution_clock::now();
  Ram ram2(argumentos);
  ram2.ejecutar();
  auto t4 = std::chrono::high_resolution_clock::now();
  std::cout << "TEST2-2 time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t4 - t3).count()/1000000.0 << " segundos\n";
  comprobar(argumentos[3], expected_v);
}

TEST_CASE("TEST 3")
{
  char* argumentos[5];
  std::string test = "test/test3.ram";
  argumentos[0] = &program[0]; argumentos[1] = &test[0]; argumentos[2] = &input[0];
  argumentos[3] = &output[0]; argumentos[4] = &debug[0];

  std::vector<std::string> input_v = {"1", "2", "3", "2", "0"};
  escribir_fichero_in(argumentos[2], input_v);
  CHECK_THROWS(Ram (argumentos));
}

TEST_CASE("TEST 4")
{
  char* argumentos[5];
  std::string test = "test/test4.ram";
  argumentos[0] = &program[0]; argumentos[1] = &test[0]; argumentos[2] = &input[0];
  argumentos[3] = &output[0]; argumentos[4] = &debug[0];

  // Mismo número
  std::vector<std::string> input_v = {"1", "2", "2", "1", "0"};
  std::vector<std::string> expected_v = {"2", "4", "4", "2"};
  escribir_fichero_in(argumentos[2], input_v);
  auto t1 = std::chrono::high_resolution_clock::now();
  Ram ram1(argumentos);
  ram1.ejecutar();
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "TEST4 time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";
  comprobar(argumentos[3], expected_v);
}

TEST_CASE("TEST 5")
{
  char* argumentos[5];
  std::string test = "test/test5.ram";
  argumentos[0] = &program[0]; argumentos[1] = &test[0]; argumentos[2] = &input[0];
  argumentos[3] = &output[0]; argumentos[4] = &debug[0];

  // Mismo número
  std::vector<std::string> input_v = {"1", "2", "2", "1", "0"};
  std::vector<std::string> expected_v = {"6"};
  escribir_fichero_in(argumentos[2], input_v);
  auto t1 = std::chrono::high_resolution_clock::now();
  Ram ram1(argumentos);
  ram1.ejecutar();
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "TEST5 time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";
  comprobar(argumentos[3], expected_v);
}

TEST_CASE("TEST 7")
{
  char* argumentos[5];
  std::string test = "test/test7.ram";
  argumentos[0] = &program[0]; argumentos[1] = &test[0]; argumentos[2] = &input[0];
  argumentos[3] = &output[0]; argumentos[4] = &debug[0];

  std::vector<std::string> input_v = {"2", "4", "6", "8", "0"};
  std::vector<std::string> expected_v = {"6", "12", "18", "24"};
  escribir_fichero_in(argumentos[2], input_v);
  auto t1 = std::chrono::high_resolution_clock::now();
  Ram ram(argumentos);
  ram.ejecutar();
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "TEST7 time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";
  comprobar(argumentos[3], expected_v);
}

TEST_CASE("Elevedo_lineal")
{
  char* argumentos[5];
  std::string test = "test/elevado_lineal.ram";
  argumentos[0] = &program[0]; argumentos[1] = &test[0]; argumentos[2] = &input[0];
  argumentos[3] = &output[0]; argumentos[4] = &debug[0];

  std::vector<std::string> input_v = {"4"};
  std::vector<std::string> expected_v = {"256"};
  escribir_fichero_in(argumentos[2], input_v);
  auto t1 = std::chrono::high_resolution_clock::now();
  Ram ram(argumentos);
  ram.ejecutar();
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "TEST elevado_lineal time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";
  comprobar(argumentos[3], expected_v);
}

TEST_CASE("Elevedo_algoritmico")
{
  char* argumentos[5];
  std::string test = "test/elevado.ram";
  argumentos[0] = &program[0]; argumentos[1] = &test[0]; argumentos[2] = &input[0];
  argumentos[3] = &output[0]; argumentos[4] = &debug[0];

  std::vector<std::string> input_v = {"4"};
  std::vector<std::string> expected_v = {"256"};
  escribir_fichero_in(argumentos[2], input_v);
  auto t1 = std::chrono::high_resolution_clock::now();
  Ram ram(argumentos);
  ram.ejecutar();
  auto t2 = std::chrono::high_resolution_clock::now();
  std::cout << "TEST elevado_logaritmico time: "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microsegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000.0 << " milisegundos | "
    << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count()/1000000.0 << " segundos\n";
  comprobar(argumentos[3], expected_v);
}

void escribir_fichero_in(const char* fichero, std::vector<std::string> input)
{
  std::fstream f_cinta_entrada;
  f_cinta_entrada.open(fichero, std::ios::out);
  if(!f_cinta_entrada)
  {
    throw "No se ha podido escribir en la cinta de salida\n";
  }

  for (size_t i = 0; i < input.size(); i++)
  {
    f_cinta_entrada << input[i] << ' ';
  }

  f_cinta_entrada.close();
}

void comprobar(const char* fichero, std::vector<std::string> comparables)
{
  std::fstream f_cinta_salida;
  f_cinta_salida.open(fichero, std::ios::in);
  if (!f_cinta_salida)
  {
    throw "No se ha podido leer la cinta\n";
  }
  std::string palabra;
  for (int i = 0; i < comparables.size(); i++)
  {
    f_cinta_salida >> palabra;
    CHECK(palabra == comparables[i]);
  }
  f_cinta_salida.close();
}
