class Contacto:
    def __init__(self, nombre, telefono):
        self._nombre = nombre
        self._telefono = telefono

    def display(self):
        print(self._nombre, self._telefono)

class Agenda:
    def __init__(self):
        self._lista_contactos = []

    def agregar_contacto(self):
        print("====Ingresa los datos del usuario====")
        nombre = input("Ingresa el nombre del usuario")
        telefono = input("Ingresa el telefono del usuario")
        obj_contacto = Contacto(nombre, telefono)
        self._lista_contactos.append(obj_contacto)
        print("\nEl contacto se agrego de forma exitoa")

class Navegacion:
    def __init__(self):
        pass

    def muestra_opciones(self):
        obj_agenda = Agenda()
        while True:
            print("========Opciones======")
            print("1.- Listar contactos")
            print("2.- Agregar contacto")
            print("3.- Modificar contacto")
            print("4.- Eliminar contacto")
            print("5.- Salir")

            opcion = int(input("Ingresa una opción"))

            if(opcion== 5):
                print("Adios")
                break
            elif opcion == 1:
                if len(obj_agenda.__dict__.get("_lista_contactos")) == 0:
                    print("\nNo existen contactos para listar")
                    print("Agrega un contacto\n")
                else:
                    for contacto in obj_agenda.__dict__.get("_lista_contactos"):
                        contacto.display()
            elif opcion == 2:
                obj_agenda.agregar_contacto()

class AppAgenda:
    def __init__(self):
        pass
    def run_aplicacion(self):
        obj_navegacion = Navegacion()
        obj_navegacion.muestra_opciones()

obj_agenda = AppAgenda()
obj_agenda.run_aplicacion()