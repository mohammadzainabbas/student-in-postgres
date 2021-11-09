-- complain if script is sourced in psql, rather than via CREATE EXTENSION
\echo Use "CREATE EXTENSION student" to load this file. \quit

CREATE OR REPLACE FUNCTION student_in(cstring)
RETURNS student
AS '$libdir/student'
LANGUAGE C IMMUTABLE STRICT;

CREATE OR REPLACE FUNCTION student_out(student)
RETURNS cstring
AS '$libdir/student'
LANGUAGE C IMMUTABLE STRICT;

CREATE TYPE student (
    INPUT = student_in,
    OUTPUT = student_out
);

COMMENT ON TYPE student IS 'Student is a composite type with a name, age and grade';

CREATE OR REPLACE FUNCTION student(text)
RETURNS student
AS '$libdir/student', 'text_to_student'
LANGUAGE C IMMUTABLE STRICT;

CREATE OR REPLACE FUNCTION text(student)
RETURNS text
AS '$libdir/student', 'student_to_text'
LANGUAGE C IMMUTABLE STRICT;

CREATE CAST (text as student) WITH FUNCTION student(text) AS IMPLICIT;
CREATE CAST (student as text) WITH FUNCTION text(student);
