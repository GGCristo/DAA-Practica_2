#pragma once
class Pc
{
  public:
    static Pc& get_instance();
    const int get_Pc();
  private:
    Pc();
    void jump(int);
    void incrementar();
    int pc_;
    friend class Programa;
};
