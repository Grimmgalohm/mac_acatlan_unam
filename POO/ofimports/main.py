# Debe existir un archivo __init__.py en las carpetas en las que hay archivos python
# El nombre del archivo debe ser:
# - en minusculas
# - con snake case
# - debe coincidir con el nombre de la clase general
#
# Se importa la clase con: from .nombredeclase import NombreDeClase
# 

# Hacer una carpeta de instalación de python
# Se tiene que definir un archivo setup.py
# El contenido del archivo utilica la siguiente estructura
# from setuptools import find_packages, setup
# setup(
#      * name='Nombre de libreria',
#      * version='1.0',
#      description='Python Distribution Utilities',
#      author='Greg Ward',
#      author_email='gward@python.net',
#      url='https://www.python.org/sigs/distutils-sig/',
#      * packages=find_packages()                         )<- recuerda cerrar el paréntesis
# Siendo lo marcado con un asterisco lo minimo indispensable :D
#
# pip install py (para mac?)
# 
# Para crear la libreria:
# python3 setup.py bdist_wheel
# la carpeta dist tenemos el archivo .whi que empaqueta la libreria