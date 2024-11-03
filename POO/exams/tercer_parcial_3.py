class TransactionManager:
    def __init__(self):
        self.transactions = []  # transacciones

    def __generate_transaction_id(self):
        return len(self.transactions) + 1  # Genera ID

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

        # Mostrar
        print("\nTransacción creada exitosamente:")
        print("=" * 50)
        print(f"{'ID':<5} {'Usuario':<20} {'Producto':<15} {'Tipo':<10} {'Cantidad':<10} {'Valor':<10}")
        print("=" * 50)
        print(f"{transaction['id']:<5} {transaction['user_email']:<20} {transaction['product']:<15} "
              f"{transaction['type']:<10} {transaction['quantity']:<10} {transaction['value']:<10.2f}\n")
        return transaction

    def list_all_transactions(self):
        if not self.transactions:
            print("No hay transacciones registradas.")
            return
        print(f"{'ID':<5} {'Usuario':<20} {'Producto':<15} {'Tipo':<10} {'Cantidad':<10} {'Valor':<10}")
        print("=" * 70)
        for transaction in self.transactions:
            print(
                f"{transaction['id']:<5} {transaction['user_email']:<20} {transaction['product']:<15} "
                f"{transaction['type']:<10} {transaction['quantity']:<10} {transaction['value']:<10.2f}"
            )

    # Solo para usuarios
    def search_personal_transactions(self, user_email):
        transactions = [t for t in self.transactions if t['user_email'] == user_email]
        if not transactions:
            print("No tienes transacciones registradas.")
        else:
            print(f"{'ID':<5} {'Producto':<15} {'Tipo':<10} {'Cantidad':<10} {'Valor':<10}")
            print("=" * 55)
            for transaction in transactions:
                print(
                    f"{transaction['id']:<5} {transaction['product']:<15} "
                    f"{transaction['type']:<10} {transaction['quantity']:<10} {transaction['value']:<10.2f}"
                )
        return transactions

    def delete_transaction(self, transaction_id, user_email, is_admin):
        for transaction in self.transactions:
            if transaction['id'] == transaction_id and (is_admin or transaction['user_email'] == user_email):
                self.transactions.remove(transaction)
                print(f"Transacción con ID {transaction_id} eliminada exitosamente.")
                return True
        print("Transacción no encontrada o no tienes permiso para eliminarla.")
        return False

    def search_transaction(self, transaction_id):
        for transaction in self.transactions:
            if transaction['id'] == transaction_id:
                print("\nTransacción encontrada:")
                print("=" * 50)
                print(f"{'ID':<5} {'Usuario':<20} {'Producto':<15} {'Tipo':<10} {'Cantidad':<10} {'Valor':<10}")
                print("=" * 50)
                print(f"{transaction['id']:<5} {transaction['user_email']:<20} {transaction['product']:<15} "
                      f"{transaction['type']:<10} {transaction['quantity']:<10} {transaction['value']:<10.2f}\n")
                return transaction
        print("Transacción no encontrada.")
        return None

    def generate_report(self):
        if not self.transactions:
            print("No hay transacciones registradas.")
            return

        highest_transaction = max(self.transactions, key=lambda x: x['value'])
        lowest_transaction = min(self.transactions, key=lambda x: x['value'])
        average_value = sum(t['value'] for t in self.transactions) / len(self.transactions)

        print("\n======= Reporte de Transacciones =======")
        print("=" * 40)
        print(f"{'Transacción Más Alta':<30} {highest_transaction['value']:<10.2f}")
        print(f"{'Transacción Más Baja':<30} {lowest_transaction['value']:<10.2f}")
        print(f"{'Promedio de Transacciones':<30} {average_value:<10.2f}")
        print("=" * 40)

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
            print("\n======= Menu Administrador =======")
            print("1. Listar todas las transacciones")
            print("2. Buscar transacción")
            print("3. Eliminar transacción")
            print("4. Crear transacción")
            print("5. Generar reporte")
            print("6. Regresar al menú principal")
            choice = input("Elige una opción: ")

            if choice == '1':
                self.transaction_manager.list_all_transactions()
            elif choice == '2':
                transaction_id = int(input("Ingresa el ID de la transacción a buscar: "))
                self.transaction_manager.search_transaction(transaction_id)
            elif choice == '3':
                transaction_id = int(input("Ingresa el ID de la transacción a eliminar: "))
                self.transaction_manager.delete_transaction(transaction_id, self.user_manager._user_name, is_admin=True)
            elif choice == '4':
                user_email = input("Email del usuario: ")
                product = input("Producto: ")
                transaction_type = input("Tipo de transacción: ")
                quantity = int(input("Cantidad: "))
                value = float(input("Valor: "))
                self.transaction_manager.create_transaction(user_email, product, transaction_type, quantity, value)
            elif choice == '5':
                self.transaction_manager.generate_report()
            elif choice == '6':
                print("Regresando al menú principal...")
                break
            else:
                print("Opción no válida.")

    def user_panel(self):
        while True:
            print("\n======= Menu Usuario =======")
            print("1. Crear transacción")
            print("2. Listar mis transacciones")
            print("3. Eliminar transacción")
            print("4. Actualizar perfil")
            print("5. Regresar al menú principal")
            choice = input("Elige una opción: ")

            if choice == '1':
                product = input("Producto: ")
                transaction_type = input("Tipo de transacción: ")
                quantity = int(input("Cantidad: "))
                value = float(input("Valor: "))
                self.transaction_manager.create_transaction(self.user_manager._user_name, product, transaction_type, quantity, value)
            elif choice == '2':
                self.transaction_manager.search_personal_transactions(self.user_manager._user_name)
            elif choice == '3':
                transaction_id = int(input("Ingresa el ID de la transacción a eliminar: "))
                self.transaction_manager.delete_transaction(transaction_id, self.user_manager._user_name, is_admin=False)
            elif choice == '4':
                self.update_profile()
            elif choice == '5':
                print("Regresando al menú principal...")
                break
            else:
                print("Opción no válida.")

    def update_profile(self):
        new_email = input("Ingresa tu nuevo email: ")
        new_password = input("Ingresa tu nueva contraseña: ")

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
            {'email': 'admin', 'password': '123', 'is_admin': True},
            {'email': 'user', 'password': '123', 'is_admin': False}
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
    def __init__(self, transaction_manager):
        self._user_name = ""
        self._password = ""
        self.transaction_manager = transaction_manager

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
                obj_navigation = Navigation(obj_usermanager, self.transaction_manager)
                obj_navigation.panel(obj_usermanager.is_authenticated['is_admin'])
                break
            else:
                print("El Usuario/contraseña es incorrecto")


class AppTransacciones:
    def __init__(self):
        self.transaction_manager = TransactionManager()

    def iniciar_app(self):
        while True:
            print("\n===== Bienvenido al Sistema de Transacciones =====")
            print("1. Iniciar sesión")
            print("2. Salir")
            choice = input("Elige una opción: ")

            if choice == '1':
                obj_login = Login(self.transaction_manager)
                obj_login.login()
            elif choice == '2':
                print("Saliendo del sistema.")
                break
            else:
                print("Opción no válida.")


if __name__ == "__main__":
    app = AppTransacciones()
    app.iniciar_app()