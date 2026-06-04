# Compilatore e standard
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude

# Cartelle
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

# Trova in automatico tutti i file .c e genera i nomi per i file .o
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Nome dell'eseguibile finale
TARGET = yugioh_manager

# Regola principale: compila tutto
all: $(TARGET)

# Come costruire l'eseguibile unendo i file oggetto
$(TARGET): $(OBJS)
	@echo "Linkando l'eseguibile $@..."
	$(CC) $(CFLAGS) -o $@ $^
	@echo "Compilazione completata con successo!"

# Come compilare i singoli file .c nei file .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	@echo "Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Regola per pulire il workspace
clean:
	@echo "Pulizia in corso..."
	@if exist $(OBJ_DIR)\*.o del /Q $(OBJ_DIR)\*.o
	@if exist $(TARGET).exe del /Q $(TARGET).exe
	@echo "Workspace pulito."

# Dichiara che 'all' e 'clean' non sono file fisici
.PHONY: all clean

# Regola per eseguire il programma in automatico
run: $(TARGET)
	@echo "Avviando $(TARGET)..."
	@.\$(TARGET).exe

.PHONY: all clean run