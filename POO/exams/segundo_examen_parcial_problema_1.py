# Segundo Examen Parcial

class Employees:
    def __init__(self,name:str,id:int,base_salary:float):
        self._name = name
        self._id = id
        self._base_salary = base_salary
        
    def salary_calculator(self):
        pass
    
    @property 
    def getter_info(self):
        pass
        
class SalesMan(Employees):
    def __init__(self,name,id,base_salary,sales:int):
        super().__init__(name,id,base_salary)
        self._sales = sales
        
    def salary_calculator(self):
        return (self._base_salary*(self._sales/1000))
       
    @property 
    def getter_info(self):
        return{
            "Nombre":self._name,
            "ID":self._id,
            "Salario base":self._base_salary,
            "Comision":self._sales,
            "Salario Neto":self.salary_calculator()+self._base_salary
        }
        
class Administrative(Employees):
    def __init__(self,name,id,base_salary,bonus:int):
        super().__init__(name,id,base_salary)
        self._bonus = bonus
        
    def salary_calculator(self):
        return (self._base_salary+((self._bonus*self._base_salary)/100))
       
    @property 
    def getter_info(self):
        return{
            "Nombre":self._name,
            "ID":self._id,
            "Salario base":self._base_salary,
            "Bono":self._bonus,
            "Salario Neto":self.salary_calculator()
        }

obj_salesman = SalesMan('Cesar', 1, 4500.50, 150)
print(obj_salesman.getter_info)

obj_administrative = Administrative('Miguel', 2, 6000, 10)
print(obj_administrative.getter_info)

