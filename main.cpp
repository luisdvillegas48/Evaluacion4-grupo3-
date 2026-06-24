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
    do {
        mostrarMenuOpciones();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();
        switch(opcion) {
case 1: registrarNuevoEstudiante(miClase); 
break;

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
void mostrarMenuOpciones() {
    cout << "\n=== GESTOR DE RESERVAS PARA CLASES ONLINE ===\n";
    cout << "1. Registrar estudiante\n";
    cout << "2. Dar de baja estudiante\n";
    cout << "3. Consultar disponibilidad de cupos\n";
    cout << "4. Listar alumnos inscritos\n";
    cout << "5. Salir\n";
}
void registrarNuevoEstudiante(ClaseOnline &clase) {
    if (!verificarCupoDisponible(clase)) {
        cout << "Error: No se puede registrar. Se ha alcanzado el maximo de cupos permitidos.\n";
        return;
    }
    
    Estudiante nuevoAlumno;
    cout << "Ingrese la cedula del estudiante: ";
    getline(cin, nuevoAlumno.cedula);
    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, nuevoAlumno.nombre);
    
    clase.inscritos.push_back(nuevoAlumno);
    cout << "Estudiante registrado exitosamente.\n";
}
case 2: darDeBajaEstudiante(miClase);
break;

void darDeBajaEstudiante(ClaseOnline &clase) {
    if (clase.inscritos.empty()) {
        cout << "El sistema no registra estudiantes inscritos actualmente.\n";
        return;
    }
    
    string cedulaBuscar;
    cout << "Ingrese la cedula del estudiante a dar de baja: ";
    getline(cin, cedulaBuscar);
    
    bool encontrado = false;
    for (size_t i = 0; i < clase.inscritos.size(); ++i) {
        if (clase.inscritos[i].cedula == cedulaBuscar) {
            clase.inscritos.erase(clase.inscritos.begin() + i);
            cout << "Reserva cancelada y cupo liberado correctamente.\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado) cout << "No se encontro la cedula especificada.\n";
}

