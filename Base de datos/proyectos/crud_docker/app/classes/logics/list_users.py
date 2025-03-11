import time
from datetime import datetime

import pandas as pd
import streamlit as st

from classes.db.database import Database_mysql
from classes.db.database import Database_postgresql

class ListElements:
    def __init__(self):
        self._data_set = []
        self._data_dict = []
        self._result_search = None

    def list_and_show(self):

        tab_listado_general, tab_buscar_registro = st.tabs(["Listar todos", "Buscar un registro"])

        with tab_listado_general:
            self._listar()
        with tab_buscar_registro:
            self._buscar_registro()

    def _listar(self):
            mysql = Database_mysql()
            mysql.connect()
            query = "SELECT * FROM students;"
            self._data_set = mysql.fetch_query(query)
            keys = ['id', 'first','middle', 'last', 'second_last', 'age', 'account_number']
            
            df = pd.DataFrame([dict(zip(keys, t)) for t in self._data_set])    

            st.dataframe(df)

            mysql.close()
    
    def _buscar_registro(self):
        with st.form("Buscar Resgistro"):
            busqueda = st.text_input("Buscar por número de cuenta")
            submit = st.form_submit_button("Enviar")

            if submit:
                mysql = Database_mysql()
                mysql.connect()

                post = mysql.fetch_query("SELECT * FROM students WHERE students.account_number = "+busqueda+";")

                keys = ['id', 'first','middle', 'last', 'second_last', 'age', 'account_number']
                self._result_search = [dict(zip(keys, t)) for t in post]

                mysql.close()

        if self._result_search != None:
            st.success(f"Numero de cuenta: {self._result_search[0]['account_number']}")

            fn = st.text_input("Nombre(s)",
                        value=self._result_search[0]['first'] + " " + self._result_search[0]['middle'],
                        key="nombres")
            ln = st.text_input("Apellidos",
                        value=self._result_search[0]['last'] + " " + self._result_search[0]['second_last'],
                        key="apellidos")
            age = st.text_input("Edad",
                        value=self._result_search[0]['age'],
                        key="edad")
            
            fname = fn.split(" ") if fn else [None, None]
            lname = ln.split(" ") if ln else [None, None]

            first = fname[0] if len(fname) > 0 else None
            middle = fname[1] if len(fname) > 1 else None
            last = lname[0] if len(lname) > 0 else None
            second_last = lname[1] if len(lname) > 1 else None
            
            save = st.button("Guardar cambios", key="save_changes")

            if save:
                mysql = Database_mysql()
                mysql.connect()

                query="UPDATE students SET first_name = '%s', middle_name = '%s', last_name = '%s', second_last_name = '%s', age = %s WHERE id = %s;"
                values=(first, middle, last, second_last, age)
                post = mysql.execute_query(query, tuple(values))

                if post == True:
                    st.success("Registro Actualizado")
                else:
                    st.error(f"Error: {post}")

                mysql.close()

    def eliminar_registro(self, id):
        pass

    def _actualizar_registro(self):
        pass