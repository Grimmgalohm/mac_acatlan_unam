# Solo una clase
# Para definir una clase se necesita usar la palabra reservada class
# Seguido del nombre de la clase y dos puntos
# Ej.

class MiPrimeraClase:
    # Para los nombres de las clases se usa el standard camel case
    def __init__(self, attrib:str):
        self._attrib = attrib
        # El método constructor nos sirve para inicializar los valores iniciales del objeto
        # Se llama al crear una instancia de un objeto
        # Usamos self como parametro para referirse a la instancia del objeto en la que se está invocando

    def mi_primer_metodo(self):
        print(f"Este es mi primer attributo en {self._attrib}")

obj_1 = MiPrimeraClase("Python")
obj_2 = MiPrimeraClase("Java :D")

obj_1.mi_primer_metodo()
obj_2.mi_primer_metodo()