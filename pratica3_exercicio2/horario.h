
struct Horario{
    //dados
    int hora;
    int minuto;
    int segundo;
    //contrutor
    Horario(int h,int m,int s);
    //metodos
    void exibeHorarioUniversal(); //24h
    void exibeHorarioPadrao(); // 12h
};

