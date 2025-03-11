CREATE TABLE IF NOT EXISTS students (
    id SERIAL PRIMARY KEY,
    first_name VARCHAR(100) NOT NULL,
    middle_name VARCHAR(100),
    last_name VARCHAR(100) NOT NULL,
    second_last_name VARCHAR(100),
    age INT CHECK (age BETWEEN 0 AND 120),
    account_number VARCHAR(100) UNIQUE NOT NULL
);

CREATE TABLE IF NOT EXISTS materias (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL
);

CREATE TABLE IF NOT EXISTS student_materias (
    id SERIAL PRIMARY KEY,
    student_id INT NOT NULL,
    materia_id INT NOT NULL,
    FOREIGN KEY (student_id) REFERENCES students(id) ON DELETE CASCADE,
    FOREIGN KEY (materia_id) REFERENCES materias(id) ON DELETE CASCADE,
    UNIQUE (student_id, materia_id)
);