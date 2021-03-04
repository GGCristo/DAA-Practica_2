#pragma once
class Pc
{
  public:
    Pc();
    static Pc& get_instance();
    const int get_Pc();
    void jump(int);
    void incrementar();
  private:
    int pc_;
};
