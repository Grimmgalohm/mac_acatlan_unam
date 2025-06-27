import csv
import os

class Storage:
    def __init__(self):
        self._archivo_csv = "datos.csv"
        self._encabezados = ["id", "nombre", "precio", "cantidad"]
        self._index

    def abrir_archivo(self):
        if not os.path.exists(self._archivo_csv):
            with open(self._archivo_csv, mode="w", newline="") as archivo:
                escritor = csv.writer(archivo)
                escritor.writerow(self._encabezados)  # Escribir encabezados
            print(f"Archivo '{self._archivo_csv}' inicializado con éxito.")

        else:
            datos = []
            try:
                with open(self._archivo_csv, mode="r", newline="") as archivo:
                    lector = csv.DictReader(archivo)
                    for fila in lector:
                        
                        datos.append(dict(fila))  # Convertir cada fila en un diccionario y agregar a la lista

            except FileNotFoundError:
                print(f"El archivo '{self._archivo_csv}' no existe.")
            
            return datos

    def set_productos(self, datos):

        with open(self._archivo_csv, mode="w", newline="") as archivo:
            escritor = csv.DictWriter(archivo, fieldnames=self._encabezados)
            escritor.writeheader()  # Escribe los encabezados
            escritor.writerows(datos)  # Escribe los datos

    def get_productos(self):
        pass


class Crud:
    def __init__(self, productos):
        self._productos = productos
        self.id_producto = ""
        self.nombre_produto = ""
        self.precio_producto = ""
        self.cantidad = ""

    def crear_producto(self):
        
        print("Ingresa los datos del producto")
        self.nombre_producto = input("Nombre del producto: ")
        self.precio_producto = input("Escribe el precio del producto (por unidad o caja): ")
        self.cantidad = input("Ingresa la cantidad del stock del producto: ")

        print(f"Producto: {self.nombre_producto}, Precio: {self.precio_producto}, Cantidad: {self.cantidad}")

        self._productos.append({"id":1,"nombre":self.nombre_producto, "precio":self.precio_producto, "cantidad":self.cantidad})

        create = Storage()
        create.set_productos(self._productos)

    def listar_productos(self):
        return self._productos

    def modificar_producto(self):
        pass

    def eliminar_producto(self):
        pass
    


class Main:
    def __init__(self):
        self._datos = []

    def inicializador(self):
        storage = Storage()
        self._datos = storage.abrir_archivo()

    def menu(self):
        self.inicializador()
        while True:
            print("===== Menu =====")
            print("1] Crear un producto")
            print("2] Listar productos")
            print("3] Listar productos")
            print("4] Actualizar un producto")
            print("5] Eliminar un producto")
            print("6] Salir del programa")

            selection = input("Elige una opción: ")
            
            if selection == '1':
                crear = Crud(self._datos)
                crear.crear_producto()
            elif selection == '2':
                crear = Crud(self._datos)
                print(crear.listar_productos())
            elif selection == '3':
                pass
            elif selection == '4':
                pass
            elif selection == '5':
                pass
            elif selection == '6':
                return

app = Main()
app.menu()