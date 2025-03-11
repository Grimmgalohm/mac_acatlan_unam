# CRUD con conexión a base de datos :d
# To-Do list
# Prev 0.1 - Crear un archivo de conexión a la base de datos [in progress]
# Prev 0.2 - Crear un archivo utils con la información de la conexión a la base de datos [in progress]
# 1.- Crear un metodo para crear un elemento en la tabla de la base de datos
#   1.1 - Probar si la conexión existe y es exitosa o no
#   1.3 - Probar si las tablas existe, si no, crearlas
#   1.4 - Metodos de crear, leer, modificar y borrar
# 2.- Crar un metodo para leer los elementos de la tabla en la base de datos
# 3.- Crar un metodo para modificar
# 4.- Crear un metodo para borrar

import psycopg2
import mysql.connector

# Configuración de la conexión para MySQL
config_mysql = {
    'user': 'dckr_usr',
    'password': 'dckrusr',
    'host': 'localhost',
    'database': 'testdb',
    'raise_on_warnings': True
}

# Configuración de la conexión para PostgreSQL
config_pg = {
    'dbname': 'testdb',
    'user': 'dckr_usr',
    'password': 'dckrusr',
    'host': 'localhost',
    'port': '5432'
}

def conectar_mysql():
    try:
        return mysql.connector.connect(**config_mysql)
    except mysql.connector.Error as err:
        print(f"Error al conectar a MySQL: {err}")
        return None

def conectar_postgres():
    try:
        return psycopg2.connect(**config_pg)
    except psycopg2.Error as err:
        print(f"Error al conectar a PostgreSQL: {err}")
        return None

def crear_producto(conexion, nombre, precio, cantidad):
    if conexion:
        try:
            cursor = conexion.cursor()
            query = "INSERT INTO productos (nombre, precio, cantidad) VALUES (%s, %s, %s)"
            valores = (nombre, float(precio), int(cantidad))
            cursor.execute(query, valores)
            conexion.commit()
            print("Producto creado correctamente.")
        except Exception as err:
            print(f"Error al crear el producto: {err}")
        finally:
            cursor.close()
            conexion.close()

def leer_producto(conexion):
    if conexion:
        try:
            cursor = conexion.cursor()
            query = "SELECT * FROM productos"
            cursor.execute(query)
            resultados = cursor.fetchall()
            if resultados:
                for fila in resultados:
                    print(f"ID: {fila[0]}, Nombre: {fila[1]}, Precio: {fila[2]}, Cantidad: {fila[3]}")
            else:
                print("No hay productos en la base de datos.")
        except Exception as err:
            print(f"Error al leer los productos: {err}")
        finally:
            cursor.close()
            conexion.close()

def actualizar_producto(conexion, id, nombre, precio, cantidad):
    if conexion:
        try:
            cursor = conexion.cursor()
            query = "UPDATE productos SET nombre = %s, precio = %s, cantidad = %s WHERE id = %s"
            valores = (nombre, float(precio), int(cantidad), int(id))
            cursor.execute(query, valores)
            conexion.commit()
            if cursor.rowcount > 0:
                print("Producto actualizado correctamente.")
            else:
                print("No se encontró un producto con ese ID.")
        except Exception as err:
            print(f"Error al actualizar el producto: {err}")
        finally:
            cursor.close()
            conexion.close()

def eliminar_producto(conexion, id):
    if conexion:
        try:
            cursor = conexion.cursor()
            query = "DELETE FROM productos WHERE id = %s"
            valores = (int(id),)
            cursor.execute(query, valores)
            conexion.commit()
            if cursor.rowcount > 0:
                print("Producto eliminado correctamente.")
            else:
                print("No se encontró un producto con ese ID.")
        except Exception as err:
            print(f"Error al eliminar el producto: {err}")
        finally:
            cursor.close()
            conexion.close()

def menu():
    while True:
        print("\n--- CRUD con MySQL y PostgreSQL ---")
        print("1. Crear producto")
        print("2. Leer productos")
        print("3. Actualizar producto")
        print("4. Eliminar producto")
        print("5. Salir")
        db_type = input("Selecciona la base de datos (mysql/postgres): ").strip().lower()
        
        if db_type == "mysql":
            conexion = conectar_mysql()
        elif db_type == "postgres":
            conexion = conectar_postgres()
        else:
            print("Base de datos no válida. Inténtalo de nuevo.")
            continue
        
        opcion = input("Selecciona una opción: ")
        
        if opcion == "1":
            nombre = input("Nombre: ")
            precio = input("Precio: ")
            cantidad = input("Cantidad: ")
            crear_producto(conexion, nombre, precio, cantidad)
        elif opcion == "2":
            leer_producto(conexion)
        elif opcion == "3":
            id = input("ID del producto a actualizar: ")
            nombre = input("Nuevo nombre: ")
            precio = input("Nuevo precio: ")
            cantidad = input("Nueva cantidad: ")
            actualizar_producto(conexion, id, nombre, precio, cantidad)
        elif opcion == "4":
            id = input("ID del producto a eliminar: ")
            eliminar_producto(conexion, id)
        elif opcion == "5":
            print("Saliendo...")
            break
        else:
            print("Opción no válida. Inténtalo de nuevo.")

if __name__ == "_main_":
    menu()