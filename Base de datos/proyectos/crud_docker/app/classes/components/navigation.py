import time
from datetime import datetime

import streamlit as st
from streamlit_option_menu import option_menu
from ..logics.create_user import Form
from ..logics.list_users import ListElements

class Navigation:
    def __init__(self) -> None:
        self._init_title = "Base de datos (MAC)"
        self._init_secondtitle = "Proyecto 1 (CRUD)- MAC"

        self._menu_handlers = {
            "Inicio": self._handle_inicio,
            "Lista general": self._handle_lists
        }

        self._options = list(self._menu_handlers.keys())

    def render_menu(self):

        with st.sidebar:
            option = option_menu(
                "Main Menu",
                self._options,
                icons=[
                    "house",
                    "gear"
                ],
                menu_icon="cast",
                default_index=0,
            )

        handler = self._menu_handlers.get(option)
        if handler:
            handler()

    def _handle_inicio(self):
        st.title(self._init_title)
        st.write(self._init_secondtitle)
        Form().data_form()

    def _handle_lists(self):
        st.title("Lista de datos")
        with st.spinner("Wait for it..."):
            ListElements().list_and_show()


    # def _handle_gestion_de_contactos(self):
    #     st.title("Gestion De Contactos")
    #     with st.spinner("Wait for it..."):
    #         GestorContactos().logic()