#pragma once

#include "postgres.h"
#include "pg_config.h"

#ifndef PG_VERSION_NUM
#error "Unsupported too old PostgreSQL version"
#endif

#if (PG_VERSION_NUM / 10000) < 13
#error "Sorry! This extension only supports Postgres 13 and above"
#endif

#include "fmgr.h"
/* To ensure that a dynamically loaded object file is not loaded into an incompatible server, PostgreSQL checks that the file contains a “magic block” with the appropriate contents. */
PG_MODULE_MAGIC;

#include "utils/builtins.h"
#include <stdio.h>
#include <sting.h>

typedef struct
{
    char name[24];
    int age;
    float grade;
} student;

Datum student_in(PG_FUNCTION_ARGS);
Datum student_out(PG_FUNCTION_ARGS);
Datum text_to_student(PG_FUNCTION_ARGS);
Datum student_to_text(PG_FUNCTION_ARGS);

static inline student* str_to_student(const char*);
static inline const char* student_to_str(const student*);
