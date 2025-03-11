import streamlit as st
from classes.components.navigation import Navigation
from classes.db.database import Database_mysql
from classes.db.database import Database_postgresql

class App:
    
    def run(self):
        # db_post = Database_postgresql()
        # db_post.connect()

        # db_mysql = Database_mysql()
        # db_mysql.connect()

        obj_navigation = Navigation()
        obj_navigation.render_menu()

app = App()
app.run()
