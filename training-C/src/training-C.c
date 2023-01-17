/*
 ============================================================================
 Name        : training-C.c
 Author      : GCO
 Version     :
 Copyright   : Your copyright notice
 Description : Exercises and basic algorithms, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "basics.h"
#include "byte_manip.h"
#include "string_manip.h"

#define REG_SIZE   4  // 4 octets
#define NMEA_SIZE 25  // 25 octets
#define N		   7

int size_triangle;
int data[N] = {0, 5, 10, 8, 7, 9, 3};
int glmin = N_MAX_INT;
int glmax = 0;

struct point myPoints[NB_POINTS];

/* Bytes manip variables */
uint8_t byte_to_test = 0x95;
uint32_t reg_to_test = 0xAE010359;
char* nmea_frame = "GPZDA,133358,09,05,2007,,";

/* String manip variables */
char string[LINE_MAX] = "repertoire";
char file_name[20] = "repertoire.txt";

int main(void) {
	puts("---Exercises and basic algorithms---");

	/* Basics */
	som();
	sub(10);
	printf("%f\n", moyenne());

	/* Test du triangle */
	puts("Rentrer une taille de triangle :");
	scanf("%d", &size_triangle);
	triangle(size_triangle);

	/* Test du nb premier */
	printf("8 %s , 7 %s\n", premier(8) ? "est premier" : "n'est pas premier", \
							premier(7) ? "est premier" : "n'est pas premier");

	/* Test suite de Fibonacci, 2 méthodes */
	printf("%d\n", fibonacci(6)); // attendu : Un = 8
	printf("%d\n", _fibonacci(6)); // attendu : Un = 8

	/* Génération table mult. avec gestion d'erreur */
	if( print_table(10))
		return EXIT_FAILURE;

	/* Algo min/max */
	min_max(data, N);
	min_max_ptr(data, N);
	min_max_param(data, N, &glmin, &glmax);
	printf("Le min est %d\n, le max est %d\n", glmin, glmax);

	/* Algo de tri + utilisation macro */
	if( SORT(data, 7))
			return EXIT_FAILURE;
	for (int i = 0 ; i < 7 ; i++) {
		printf("%d, ", data[i]);
	}

	/* Test algo de recherche binaire */
	printf("Il %s le chiffre %d dans l'array\n", \
			binarySearch(data, 7, 0, 6) ? "y a" : "n'y a pas", \
					7);
	printf("Il %s le chiffre %d dans l'array\n", \
			binarySearch(data, 16, 0, 6) ? "y a" : "n'y a pas", \
					16);

	/* Bytes manipulation */
	printf("Il y a %d bits à '1' dans le byte de data : 0x%2x\r\n", check_parity(byte_to_test), byte_to_test);
	printf("Le XOR checksum est de 0x%2x sur la data 0x%8x à l'adresse 0x%8x\r\n", xor_checksum_32b(reg_to_test, REG_SIZE), reg_to_test, &reg_to_test);
	printf("Le xor de la trame ascii est 0x%2x\r\n", xor_checksum(nmea_frame, NMEA_SIZE));

	/* String manipulation */
	printf("Il y a %d 'e' dans la chaine donnée\n", nb_char(string, 'e', strlen(string)));
	printf("Rentrez une chaîne de caractères: \n");
	scanf("%s", string);
	delete_char(string, 'e');

	/* Utilisation structure */
	if(read_points(myPoints))
		return EXIT_FAILURE;
	if(display_points(myPoints))
		return EXIT_FAILURE;

	/* Utilisation liste chainée */
	struct element * start;
	creation(&start);
	display_list(start);

	/* Lecture/Ecriture sur fichiers */
	create_file(file_name);
	display_file(file_name);

	/* THE END */
	return EXIT_SUCCESS;
}
