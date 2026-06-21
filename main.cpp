#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Estudiante {
    string cedula;
    string nombre;
};

struct ClaseOnline {
    string nombreAsignatura;
    int cupoMaximo;
    vector<Estudiante> inscritos;
};

void configurarCuposIniciales(ClaseOnline &clase);
void mostrarMenuOpciones();
void registrarNuevoEstudiante(ClaseOnline &clase);
void darDeBajaEstudiante(ClaseOnline &clase);
void consultarEstadoCupos(const ClaseOnline &clase);
void listarAlumnosInscritos(const ClaseOnline &clase);
bool verificarCupoDisponible(const ClaseOnline &clase);

int main() {
    ClaseOnline miClase;
    miClase.nombreAsignatura = "Lenguaje de Programacion II";
    
    
    configurarCuposIniciales(miClase);
    
    int opcion;
    
// ==========================================
// DESARROLLO DE LAS FUNCIONES
// ==========================================

void configurarCuposIniciales(ClaseOnline &clase) {
    int cantidad;
    do {
        cout << "Ingrese la cantidad maxima de cupos para la asignatura: ";
        cin >> cantidad;
        if (cantidad <= 0) {
            cout << "La cantidad debe ser mayor a cero.\n";
        }
    } while (cantidad <= 0);
    clase.cupoMaximo = cantidad;
    cout << "Sistema inicializado con un limite de " << clase.cupoMaximo << " cupos.\n";
}
