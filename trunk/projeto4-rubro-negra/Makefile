CLASSES = main.cpp RubroNegra.cpp Folha.cpp

# regra principal
all: lab4

# gera o executável
lab4:
	g++ -o lab4 ${CLASSES} 
	@echo "\n***** Para executar o programa digite ./lab4 nome_do_arquivo.txt *****"
	@echo "\n***** Para gerar a documentação digite make doxygen *****\n"

# remove o executável
clean:
	rm -f *.o lab4

# gera documentação
doxygen:
	doxygen -g
	sed -i 's/EXTRACT_PRIVATE        = NO/EXTRACT_PRIVATE        = YES/g' Doxyfile
	doxygen
	@echo "\n***** Diretório html criado com sucesso. Contém toda documentação das classes *****\n"