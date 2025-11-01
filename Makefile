SRC = compino.cpp

TARGET = compino

CXX = g++

CXXFLAGS = -O3 -Wall

INSTALL_DIR = /usr/local/bin

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $< -o $@

install: $(TARGET)
	mkdir -p $(INSTALL_DIR)
	cp $(TARGET) $(INSTALL_DIR)
	@echo "Instalação concluída. '$(TARGET)' agora está disponível como um comando do sistema."

uninstall:
	rm -f $(INSTALL_DIR)/$(TARGET)
	@echo "Desinstalação concluída. '$(TARGET)' foi removido do sistema."

clean:
	rm -f $(TARGET)
	@echo "Arquivos de compilação limpos."

.PHONY: all install uninstall clean

