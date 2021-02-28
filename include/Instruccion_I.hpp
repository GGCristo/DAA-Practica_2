#pragma once
class Instruccion_I
{
  public:
    Instruccion_I();
    virtual ~Instruccion_I(){};
    virtual void ejecutar() = 0;
};
