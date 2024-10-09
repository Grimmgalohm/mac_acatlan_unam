from abc import ABC
from abc import abstractmethod

class Vehicle(ABC):
    @abstractmethod
    def _mantaince_costs(self):
        pass
    
class Motorcicle(Vehicle):
    def __init__(self, cc:int):
        self._cc = cc
    
    def _mantaince_costs(self):
        return (100+(10*self._cc))
        
class Car(Vehicle):
    def __init__(self, gas:str):
        self._gas = gas
    
    def _mantaince_costs(self):
        if self._gas == "diesel":
            return 400
        elif self._gas == "normal":
            return 300
        else:
            return "Tipo no reconocido"
        
class Camion(Vehicle):
    def __init__(self, capacity:float):
        self._capacity = capacity
    
    def _mantaince_costs(self):
        return (500+(20*self._capacity))

obj_moto = Motorcicle(50)
print(f"costo Moto: {obj_moto._mantaince_costs()}")

obj_car = Car("diesel")
print(f"costo Automovil: {obj_car._mantaince_costs()}")

obj_camion = Camion(50)
print(f"costo Camion: {obj_camion._mantaince_costs()}")
        