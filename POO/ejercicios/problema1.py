# Problema 1: Sistema de Gestión de Productos en un Almacén (Herencia)
# Descripción del Problema:
# Se requiere un sistema que gestione distintos tipos de productos en un almacén. 
# Cada producto tiene un nombre, un ID y un precio base, pero el precio final puede variar según el tipo de producto. 
# Por ejemplo, los productos electrónicos pueden tener un impuesto adicional, mientras que los alimentos pueden tener un descuento.

class Products:
    def __init__(self, id:int, name):
        self._id = id
        self._name = name
    
    @property
    def get_name(self):
        return self._name
    
    @property
    def get_id(self):
        return self._id

class Electronics(Products):
    def __init__(self,id, name, price:float, discount:int):
        super().__init__(id,name)
        self._price = price
        self._discount = discount
    
    @property
    def get_price(self):
        return self._price

    @property
    def get_discount(self):
        return self._discount

    def calc_discount(self):
        return self._price-(self._price*(self._discount/100))
    
class Foods(Products):
    def __init__(self,id, name, price:float, discount:int):
        super().__init__(id, name)
        self._price = price
        self._discount = discount

    @property
    def get_price(self):
        return self._price

    @property
    def get_discount(self):
        return self._discount

    def calc_discount(self):
        return self._price-(self._price*(self._discount/100))

obj_1 = Electronics(1, "Calculadora", 335.40, 20)
print(f"ID:{obj_1.get_name}, Nombre: {obj_1.get_id}, Precio regular: {obj_1.get_price}, Descuento:%{obj_1.get_discount}\n")
print(f"Precio con descuento: {obj_1.calc_discount()}")
print("\n")
obj_2 = Foods(1, "Jamon Serrano de cerdo Ibérico", 900, 10)
print(f"ID:{obj_2.get_name}, Nombre: {obj_2.get_id}, Precio regular: {obj_2.get_price}, Descuento:%{obj_2.get_discount}\n")
print(f"Precio con descuento: {obj_2.calc_discount()}")