class TransactionManager:
    def __init__(self):
        self.transactions = []  # Almacena las transacciones

    def __generate_transaction_id(self):
        return len(self.transactions) + 1  # Hace ID

    # Para todos los usuarios
    def create_transaction(self, user_email, product, transaction_type, quantity, value):
        transaction_id = self.__generate_transaction_id()
        transaction = {
            'id': transaction_id,
            'user_email': user_email,
            'product': product,
            'type': transaction_type,
            'quantity': quantity,
            'value': value,
        }
        self.transactions.append(transaction)
        return transaction

    def list_all_transactions(self):
        return self.transactions

    # Solo para usuarios
    def search_personal_transactions(self, user_email):
        return [t for t in self.transactions if t['user_email'] == user_email]

    # Solo para administradores
    def delete_transaction(self, transaction_id):
        self.transactions = [t for t in self.transactions if t['id'] != transaction_id]

    def search_transaction(self, transaction_id):
        for transaction in self.transactions:
            if transaction['id'] == transaction_id:
                return transaction
        return None


class DataTreatment:
    def __init__(self):
        super().__init__()
        pass


class Navigation:
    def __init__(self, user_manager, transaction_manager):
        self.user_manager = user_manager
        self.transaction_manager = transaction_manager

    def panel(self, user_type):
        if user_type:
            print("Panel Admin")
            self.admin_panel()
        else:
            print("Panel User")
            self.user_panel()

    def admin_panel(self):
        while True:
            print("======= Menu Administrador =======")
            print("1. Listar todas las transacciones")
            print("2. Buscar transacción")
            print("3. Eliminar transacción")
            print("4. Salir")
            choice = input("Elige una opción: ")

            if choice == '1':
                transactions = self.transaction_manager.list_all_transactions()
                print("Transacciones:", transactions)
            elif choice == '2':
                transaction_id = int(input("Ingresa el ID de la transacción a buscar: "))
                transaction = self.transaction_manager.search_transaction(transaction_id)
                print("Transacción encontrada:", transaction)
            elif choice == '3':
                transaction_id = int(input("Ingresa el ID de la transacción a eliminar: "))
                self.transaction_manager.delete_transaction(transaction_id)
                print("Transacción eliminada")
            elif choice == '4':
                print("Saliendo del panel administrador.")
                break
            else:
                print("Opción no válida.")

    def user_panel(self):
        while True:
            print("======= Menu Usuario =======")
            print("1. Crear transacción")
            print("2. Listar mis transacciones")
            print("3. Actualizar perfil")
            print("4. Salir")
            choice = input("Elige una opción: ")

            if choice == '1':
                product = input("Producto: ")
                transaction_type = input("Tipo de transacción: ")
                quantity = int(input("Cantidad: "))
                value = float(input("Valor: "))
                transaction = self.transaction_manager.create_transaction(self.user_manager._user_name, product, transaction_type, quantity, value)
                print("Transacción creada:", transaction)
            elif choice == '2':
                transactions = self.transaction_manager.search_personal_transactions(self.user_manager._user_name)
                print("Mis transacciones:", transactions)
            elif choice == '3':
                self.update_profile()
            elif choice == '4':
                print("Saliendo del panel usuario.")
                break
            else:
                print("Opción no válida.")

    def update_profile(self):
        new_email = input("Ingresa tu nuevo email: ")
        new_password = input("Ingresa tu nueva contraseña: ")

        # Actualiza los datos en
        for user in self.user_manager._super_base:
            if user['email'] == self.user_manager._user_name:
                user['email'] = new_email
                user['password'] = new_password
                self.user_manager._user_name = new_email
                print("Perfil actualizado con éxito.")
                break
        else:
            print("Usuario no encontrado.")


class UserManager:
    def __init__(self, user_name, password):
        self._user_name = user_name
        self._password = password
        self._response = {}
        self._super_base = [
            {
                'email': 'soyeladmin@empresa.org',
                'password': 'admin123',
                'is_admin': True
            },
            {
                'email': 'user123',
                'password': '1234567',
                'is_admin': False
            }
        ]

    @property
    def is_authenticated(self):
        self.__authenticate()
        return self._response

    def __authenticate(self):
        for user in self._super_base:
            if user['email'] == self._user_name and user['password'] == self._password:
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
                obj_navigation = Navigation(obj_usermanager, TransactionManager())
                obj_navigation.panel(obj_usermanager.is_authenticated['is_admin'])
                break
            else:
                print("El Usuario/contraseña es incorrecto")


class AppTransacciones:
    def __init__(self):
        pass

    @staticmethod
    def iniciar_app():
        obj_login = Login()
        obj_login.login()


# Inicia la aplicación
obj_transacciones = AppTransacciones()
obj_transacciones.iniciar_app()