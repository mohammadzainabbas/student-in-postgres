EXTENSION   = student
MODULES     = student
DATA        = student--1.0.sql student.control

LDFLAGS=-lrt

PG_CONFIG ?= pg_config
PGXS = $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)