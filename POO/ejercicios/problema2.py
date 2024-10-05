# Problema 2: Sistema de Reservas de Alojamiento (Polimorfismo)
# Descripción del Problema:
# Se necesita un sistema que permita realizar reservas en diferentes tipos de alojamiento, como hoteles, hostales y apartamentos. 
# Cada tipo de alojamiento tiene su propio método de cálculo de precio, que puede variar según la duración de la estancia y las comodidades incluidas.

'''
    Reservaciones usan:
    1.- Temporalidad (cuantos dias)
    2.- Precio base de la reserva (se definiria en cada clase hija)
    3.- Una funcion que calcule el costo de acuerdo a cómo funcionan en cada tipo de hospedaje
'''

class Reservations:
    def __init__(self, time:int):
        self._time = time

    def _pricing(self):
        pass

'''
    Tipos de habiltaciones en un hotel
    - Personales
    - Matrimoniales
    - Suites
    - King suites
    - Presidential Suites
    
    0)Personal, 1)Matrimonial, 2)Suite, 3)King suite, 4)Presidential Suite

'''
class Hotel(Reservations):
    def __init__(self, time, room_type:int):
        super().__init__(time)
        self._price = 0
        self._room_type = room_type
        self._room_selected = ""

    def _princing(opt):
        if opt == 0:
            self._price = 150
            self._room_selected = "Personal"
        elif opt == 1:
            self._price = 400
            self._room_selected = "Matrimonial"
        elif opt == 2:
            self._price = 600
            self._room_selected = "Suite"
        elif opt == 3:
            self._price = 1040
            self._room_selected = "King Suite"
        elif opt == 4:
            self._price = 3000
            self._room_selected = "Presidential Suite"
        else:
            self._price = 100
            self._room_selected = "Palenque"
    
    def reservation(self):
        opt = self._room_type
        self._pricing(opt)

        print( {
            "Room Type": self._room_selected,
            "Price per day": self._price,
            "Total": self._price*self._time,
            "Reservation period": self._time
        } )

obj_1 = Hotel(7, 1)
obj_1.reservation()