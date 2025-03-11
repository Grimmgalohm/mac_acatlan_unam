import time
from datetime import datetime

import streamlit as st

from classes.db.database import Database_mysql
from classes.db.database import Database_postgresql

class Form:
    def __init__(self):
        pass

    def data_form(self):
        with st.form("my_form"):
            
            st.write("Ingresa los datos requeridos:")
            st.divider()
            
            first_name = st.text_input("Nombre(s)")
            last_name = st.text_input("Apellidos")
            age = st.text_input("Edad", key="age")
            account_number = st.text_input("Número de cuenta", key="account_number")
            options = ["TEORIA DE GRAFICAS", "BASE DE DATOS", "PROBABILIDAD", "CALCULO IV", "INGLES AVANZADO I"]
            selection = st.multiselect("Materias", options)  # Reemplazo de segmented_control
            
            age = int(age) if age else None

            st.divider()
            
            fname = first_name.split(" ") if first_name else [None, None]
            lname = last_name.split(" ") if last_name else [None, None]
            first = fname[0] if len(fname) > 0 else None
            middle = fname[1] if len(fname) > 1 else None
            last = lname[0] if len(lname) > 0 else None
            second_last = lname[1] if len(lname) > 1 else None
            
            submit = st.form_submit_button("Enviar")
            
            if submit:
                values = (first, middle, last, second_last, age, account_number)
                mysql = Database_mysql()
                mysql.connect()
                
                query = """INSERT INTO students (first_name, middle_name, last_name, second_last_name, age, account_number) VALUES (%s, %s, %s, %s, %s, %s)"""

                post = mysql.execute_query(query, tuple(values))

                if post == True:
                    st.success(f"Datos enviados: {first_name} {last_name}, {age} años, Número de cuenta: {account_number}")
                    st.write("Materias seleccionadas:", ", ".join(selection))
                else:
                    st.error(f"MySQL Error: {post}")

                mysql.close()


            