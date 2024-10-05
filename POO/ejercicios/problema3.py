# Problema 3: Sistema de Gestión de Juegos (Clases Abstractas)
# Descripción del Problema:
# Se requiere un sistema para gestionar diferentes tipos de juegos, como juegos de mesa, juegos de cartas y juegos de video. 
# Cada tipo de juego tiene un precio de venta que varía según sus características. Por ejemplo, los juegos de mesa tienen un costo fijo, 
# mientras que los juegos de cartas tienen un costo basado en la cantidad de cartas que incluyen, y los juegos de video tienen un costo adicional
# por cada DLC (contenido descargable).
from abc import ABC
from abc import abstractmethod

class GameManager(ABC):
    def __init__(self, name, price:int):
        self._name = name
        self._price = price

    @abstractmethod
    def price_calculator(self):
        pass

    @abstractmethod
    def get_product_info(self):
        pass

class VideGames(GameManager):
    def __init__(self, name, price, dlcs:int, dlc_price:float):
        super().__init__(name, price)
        self._dlcs = dlcs
        self._dlc_price = dlc_price
        self._realprice = 0

    def price_calculator(self):
        self._realprice = self._price+(self._dlcs*self._dlc_price)
        return self._realprice

    @property
    def get_product_info(self):
        return {
            "name":self._name,
            "price":self._price,
            "DLCs":self._dlcs,
            "DLC price":self._dlc_price
        }

class BoardGames(GameManager):
    def __init__(self, name, price):
        super().__init__(name, price)

    def price_calculator(self):
        return self._price

    @property
    def get_product_info(self):
        return {
            "name":self._name,
            "price":self._price
        }

obj_1 = VideGames("God of war",200, 2, 150)
print(obj_1.get_product_info)
print(obj_1.price_calculator())
obj_2 = BoardGames("Turista Mundial",150)
print(obj_2.get_product_info)
print(obj_2.price_calculator())