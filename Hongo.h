class Hongo : public Carta {
public:
    Hongo(int grado);
    int obtenerGrado() const;  // No es necesario que sea override si no est� en Carta
    void mostrar() const override;

private:
    int grado;
};
