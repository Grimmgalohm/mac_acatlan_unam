# Conexión a la base de datos
# No sé que se necesita para conectar mysql con python :c // menos postgresql
# Usaremos la libreria mysql
import os

import mysql.connector
from mysql.connector import Error

# Para PostgreSQL usaremos
import psycopg2
from psycopg2 import OperationalError

user=os.getenv("MYSQL_USER")
password=os.getenv("MYSQL_PASSWORD")
database=os.getenv("MYSQL_DB")
port=os.getenv("MYSQL_PORT")
host=os.getenv("MYSQL_HOST")

DB_CONFIG_POSTGRESQL = {
    'dbname': os.getenv("POSTGRES_DATABASE"),
    'user': os.getenv("POSTGRES_USER"),
    'password': os.getenv("POSTGRES_PASSWORD"),
    'port': os.getenv("POSTGRES_PORT"),
    'host': os.getenv("POSTGRES_HOST")
}

class Database_mysql:
    def __init__(self):
        self.connection = None

    def connect(self):
        try:
            self.connection = mysql.connector.connect(
                host=host,
                port=port,
                user=user,
                password=password,
                database=database
                )
            
            if self.connection.is_connected():
                print("Conexión exitosa a la base de datos")

        except Error as e:
            print(f"Error al conectar {e} ")

    def execute_query(self, query, values=None):
        # """ Ejecuta una consulta SQL """
        cursor = self.connection.cursor()
        try:
            cursor.execute("USE testdb") 
            if values:
                cursor.execute(query, values)
            else:
                cursor.execute(query)
            self.connection.commit()
            return True
        except Error as e:
            return e
        finally:
            cursor.close()

    def fetch_query(self, query, values=None):
        cursor = self.connection.cursor()
        try:
            cursor.execute("USE testdb")
            if values:
                cursor.execute(query, values)
            else:
                cursor.execute(query)
            return cursor.fetchall()  # Devuelve una lista de tuplas
        except mysql.connector.Error as e:
            return e

    def close(self):
        if self.connection:
            self.connection.close()
            print("Conexión cerrada")

class Database_postgresql:
    def __init__(self):
        self.connection = None

    def connect(self):
        try:
            self.connection = psycopg2.connect(**DB_CONFIG_POSTGRESQL)
            print("Conexión realizada")

        except OperationalError as e:
            print(f"Error al conectar: {e}")

    def execute_query(self, query, values=None):
        # Ejecuta una consulta SQL (INSERT, UPDATE, DELETE)
        try:
            if values:
                self.cursor.execute(query, values)
            else:
                self.cursor.execute(query)
            self.connection.commit()
            return True
        except psycopg2.Error as e:
            return e
        
    def fetch_query(self, query, values=None):
        # """ Ejecuta una consulta SELECT y devuelve los resultados """
        try:
            if values:
                self.cursor.execute(query, values)
            else:
                self.cursor.execute(query)
            return self.cursor.fetchall()  # Obtiene todos los resultados
        except psycopg2.Error as e:
            return e

    def close(self):
        if self.connection:
            self.connection.close()
            print("Conexión cerrada")