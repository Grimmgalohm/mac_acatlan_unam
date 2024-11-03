import os
import hashlib
from datetime import datetime

class TransactionManager:
    def __init__(self):
        self._transaction_id
        self._country
        self._product
        self._import_export
        self._quantity
        self._value
        self._date
        self._category
        self._port
        self._customs
        self._weight
        self._shipping_method
        self._supplier
        self._customer
        self._invoice_number
        self._payment_terms
        self._transactions = []
    
    def __generate_transaction_id(self):
        now = datetime.now()
        one = hashlib.sha256(now.day).hexdigest()
        two = hashlib.sha256(now.month).hexdigest()
        three = hashlib.sha256(now.year).hexdigest()
        four = hashlib.sha256(now.hour).hexdigest()
        five = hashlib.sha256(now.minute).hexdigest()

        return one+"-"+two+"-"+three+"-"+four+"-"+five

    #For all users
    def create_transaction(self):
        print(self.__generate_transaction_id)

    def list_all_transactions():
        pass
    
    #Only for users
    def search_personal_transactions():
        pass

    #Only for admins
    def delete_transaction():
        pass
    def search_transaction():
        pass

class DataTreatment:
    def __init__(self):
        super().__init__()
        pass

class Navigation:
    def __init__(self):
        pass

    def _admin_panel(self):
        obj_transaction_manager = TransactionManager
        while True:
            print("======= Menu Administrador =======")
            print("¿Qué quieres hacer hoy?")
            print("1.- Levantar una orden")
            print("2.- Listar mis ordenes")
            print("3.- Buscar una orden")
            print("0.- Salir")
            opcion = int(input("Escribe la opción seleccionada:  "))
            if opcion == 1:
                self.create_transaction()
            elif opcion == 0:
                return

    def __user_panel(self):
        obj_transaction_manager = TransactionManager
        while True:
            print("======= Menu Usuario =======")
            print("¿Qué quieres hacer hoy?")
            print("1.- Levantar una orden")
            print("2.- Listar las ordenes")
            print("3.- Buscar una orden")
            print("4.- Borrar orden")
            print("0.- Salir")
            opcion = int(input("Escribe la opción seleccionada:  "))
            if opcion == 1:
                self.create_transaction()
            elif opcion == 0:
                return

    #Una condición toda choriza pero que funciona por ahora
    def panel(user_type):
        if user_type:
            self.__admin_panel
        else:
            self.__user_panel

class UserManager:
    def __init__(self, user_name, password):
        self._user_name = user_name
        self._password = password
        self._response = {}
        self._super_base = [
            {
                'email':'admin123',
                'password':'admin123',
                'is_admin':True
            },
            {
                'email':'user123',
                'password':'1234567',
                'is_admin':False
            }
        ]

    @property
    def is_authenticated(self):
        self.__authenticate()
        return self._response

    def __authenticate(self):
        for user in self._super_base:
            if user['email']==self._user_name and user['password']==self._password:
                self._response['exists'] = True
                self._response['is_admin'] = user['is_admin']
            return
        self._response['exists'] = False
        self._response['is_admin'] = False
    
class Login:
    def __init__(self):
        self._user_name = ""
        self._password = ""

    def _setter_username(self):
        self._user_name = input("Username/Email: ") 

    def _setter_password(self):
        self._password = input("Password: ")

    @property
    def get_username(self):
        return self._user_name
    @property
    def get_password(self):
        return self._password

    def login(self):
        while True:
            print("========= Login =======")
            self._setter_username()
            self._setter_password()

            password = self.get_password
            username = self.get_username

            obj_usermanager = UserManager(username, password)

            if obj_usermanager.is_authenticated['exists']:
                obj_navigation = Navigation
                obj_navigation.panel(bool(obj_usermanager.is_authenticated['is_admin']))
            else:
                print("el Usuario/contraseña es incorrecto")

class AppTransacciones:
    def __init__():
        pass
    def iniciar_app():
        obj_login = Login()
        obj_login.login()

obj_transacciones = AppTransacciones
obj_transacciones.iniciar_app()