#include "student.h"

static inline student* str_to_student(const char* str)
{
    char * name;
    int age;
    float grade;

    if (sscanf(str, "( %s , %d , %f )", name, &age, &grade) != 3)
    {
        ereport(
            ERROR,
            (errcode(ERRCODE_INVALID_TEXT_REPRESENTATION),
            errmsg("Invalid input syntax for type 'student': \"%s\"", str))
        );
    }

    student * s = (student *) palloc( sizeof(student) );

    s->name = name;
    s->age = age;
    s->grade = grade;
    
    return s;
}

static inline const char* student_to_str(const student* s)
{
    char * result = psprintf("( %s , %d , %f )", s->name, s->age, s->grade);
    return result;
}

/*  */
PG_FUNCTION_INFO_V1(student_in);
Datum student_in(PG_FUNCTION_ARGS)
{
    const char * str = PG_GETARG_CSTRING(0);    
    PG_RETURN_POINTER( str_to_student( str ) );
}

PG_FUNCTION_INFO_V1(student_out);
Datum student_out(PG_FUNCTION_ARGS)
{
    const student *s = (student *) PG_GETARG_POINTER(0);
    PG_RETURN_CSTRING( student_to_str(s) );
}

PG_FUNCTION_INFO_V1(text_to_student);
Datum text_to_student(PG_FUNCTION_ARGS)
{
    text *txt = PG_GETARG_TEXT_P(0);
    char *str = DatumGetCString( DirectFunctionCall1(textout, PointerGetDatum(txt) ) );
    PG_RETURN_POINTER( str_to_student( str ) );
}

PG_FUNCTION_INFO_V1(student_to_text);
Datum student_to_text(PG_FUNCTION_ARGS)
{
    const student *s = (student *) PG_GETARG_POINTER(0);    
    text *out = (text *) DirectFunctionCall1(textin, PointerGetDatum( student_to_str(s) ) );
    PG_RETURN_TEXT_P(out);
}
