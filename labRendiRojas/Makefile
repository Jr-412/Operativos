GCC = gcc

MODULO = modulo

PROGRAMAS = labRendiRojas

$(PROGRAMAS):
		$(GCC) $(MODULO).c -c
		$(GCC) $@.c $(MODULO).o -o $@

clear:
		$(RM) $(PROGRAMAS) $(MODULO).o
