class Matrix:
    def __init__(self, row:int, columns:int):
        self._row = row
        self._columns = columns
        self.matrix = []
    def get_matrix(self):
        for i in range(self.row):
            for j in range(self.columns):
                mtemp = int(input(f"Ingresa la columna{i+1} de tu matriz"))
            mtemp = matrix.append(mtemp)
    def print_matrix(self):
        for i in range(self.row):
            for j in range(self.columns):
                print(self.matrix[0])


obj_mat = Matrix(3, 3)
obj_mat.get_matrix()