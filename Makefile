# Makefile para o projeto em C++ "projeto1_lp1"
# Criado por Caio Justino 30/04/2025

CC = g++
CPPFLAGS = -Wall -pedantic

TARGET = programa

OBJS = main.cpp cliente.cpp conta_bancaria.cpp

$(TARGET):
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp header.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) *.o