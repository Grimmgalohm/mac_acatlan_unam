class MetodosNumericos: 
    def __init__(self, xn:float):
        self._xn = xn
        self._f_de_x
        self._f_prima_de_x
    
    def _ecuacion_defecto(self, x:float):
        print(self._f_de_x = x)
        print(self._f_prima_de_x = x+1)

    def newton_raphson(self):
        for iteracion in range(self._xn, 0):
            self._ecuacion_defecto(self._xn)

obj = MetodosNumericos(3)

obj.newton_raphson()