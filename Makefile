#
# CC - nazwa kompilatora jezyka C
# CFLAGS - flagi kompilacji jezyka C
# LFLAGS - opcje dla linkera
#
# CXX – nazwa kompilatora C++
# CXXFLAGS – flagi kompilacji C++
#
# -Wall  -- spowoduje wypisywanie przez kompilator najważniejszych ostrzeżeń.
# -c     -- spowoduje skompilowanie plików źródłowych C do plików obiektów
# -std=x -- gdzie x jest standardem i może przybierać miedzy innymi wartości: 
#           c99,  gnu99,  c89,  gnu89. 
# -o     -- określa nazwę jaką ma przyjąć plik wynikowy kompilacji
# -L     -- wskazuje niestandardowe położenie biblioteki.
#           Kompilator w celu znalezienia bibliotek będzie dodatkowo
#           przeszukiwał wskazane katalogi.
#           
# Zmienne dynamiczne:          
#           $@ - oznacza pełną nazwę etykiety bieżącej
#           $< - oznacza pierwszy plik z listy bieżących zależności
#           $? - oznacza listę plików z bieżących zależności,  
#                które są nieaktualne (ze spacjami pomiędzy nimi)
#           $^ - oznacza wszystkie bieżące zależności.
#           $* - oznacza odwołanie do dopasowanego wzorca.

CC=gcc
CXX=g++
#CFLAGS=-Wall -g -O2 -std=c99
CFLAGS=-Wall -O2 -std=c99
LFLAGS=

PRG=test
CSRC=$(PRG).c
COBJ=$(CSRC:.c=.o)

$(PRG).bin: $(COBJ)
	$(CC) $(CFLAGS) $? -o $@

$(COBJ): $(CSRC) 
	$(CC) $(CFLAGS) -c $*.c -o $@

clean:
	rm -f *.o
	rm -f *.exe
	rm -f *.bin

# zeby mogl istniec w katalogu plik o nazwie 'all' lub 'clean' 
# inaczej reguly te moglyby nie dzialac
#
.PHONY: all clean
