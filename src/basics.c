/*
 * basics.c
 *
 *  Created on: 7 janv. 2020
 *      Author: quad
 */

#include "basics.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Exo : Remplacer for par un while */
void som(void)
{
	int i = 0;
	int som, n;
	som = 0;

	while(i < 4) {
		printf("Rentrer un entier :\n");
		scanf("%d", &n);
		som += n;
		i++;
	}
	printf("La somme est : %d\n", som);
}

/* Exo : Remplacer for par un do..while */
void sub(int start_value)
{
	int i = 0;
	int sub, n;
	sub = start_value;

	do {
		printf("Rentrer un entier :\n");
		scanf("%d", &n);
		sub -= n;
		i++;
	} while(i < 4);

	printf("Il reste : %d\n", sub);
}

/* Exo valeur moyenne */
float moyenne(void)
{
	float sum, note;
	int n = 0;
	sum = 0;
	do{
		printf("Rentrer une note :\n");
		scanf("%f", &note);

		if(note < 0)
			break;

		sum += note;
		n++;
	}while (note >= 0) ;

	return (sum / n);
}

/* Exo boucle */
void triangle(int size)
{
	int i, j;

	for(i = 0 ; i < size ; i++) {
		for(j = 0 ; j <= i ; j++) {
			printf("*");
		}
		printf("\n");
	}
}

/* Exo boucle nb premier */
int premier(int n)
{
	for (int i = n-1 ; i > 1 ; i--) {
		if(n % i == 0) {
			return 0;
		}
	}
	return 1;
}

/* Fibo avec tableau */
int fibonacci(int n)
{
	int u[n];
	u[1] = 1;
	u[2] = 1;

	for (int i = 3 ; i <= n ; i++) {
		u[i] = u[i-1] + u[i-2];
	}
	return u[n];
}

/* Fibo sans tableau */
int _fibonacci(int n)
{
	int acc = 2;

	for(int i = 3 ; i < n ; i++) {
		acc += i-2;
	}
	return acc;
}

/* Exo : Affichage table multiplication */
int print_table(int n)
{
	if(n > NMAX) {
		printf("Mauvais paramètre\n");
		return 1;
	}

	/* HEADER */
	printf("\t\tI");
	for (int i = 1 ; i <= n ; i++) {
		printf("\t%d", i);
	}
	printf("\n");

	/* BODY */
	for(int i = 1 ; i <= n ; i++) {
		printf("\t%d\tI", i);

		for(int j = 1 ; j <= n ; j++) {
			printf("\t%d", i*j);
		}
		printf("\n");
	}
	return 0;
}

/* Min max tab style */
void min_max(int tab[], short size)
{
	int max = 0, min = N_MAX_INT;

	for (int i = 0 ; i < size ; i++) {
		if(tab[i] > max)
			max = tab[i];
		if(tab[i] < min)
			min = tab[i];
	}
	printf("Le min est %d\n, le max est %d\n", min, max);
}

/* Min Max ptr style */
void min_max_ptr(int * data, short size)
{
	int max = 0, min = N_MAX_INT;

	for (int i = 0 ; i < size ; i++) {
		if(*(data+i) > max ) {
			max = *(data+i);
		}
		if(*(data+i) < min ) {
			min = *(data+i);
		}
	}
	printf("Le min est %d\n, le max est %d\n", min, max);
}

/* Min max en passage par paramètres */
void min_max_param(int * data, short size, int * min, int * max)
{
	for (int i = 0 ; i < size ; i++) {
		if(*(data+i) > *max ) {
			*max = *(data+i);
		}
		if(*(data+i) < *min ) {
			*min = *(data+i);
		}
	}
}

/* Fonction d'échange */
void swap(int * ad1, int * ad2)
{
	int tmp;
	tmp = *ad2;
	*ad2 = *ad1;
	*ad1 = tmp;
}

/* Tri par sélection */
int sort_croissant(int data[], short size)
{
	for (int i = 0 ; i < size-1 ; i++) {
		for (int j = i+1 ; j < size ; j++) {
			if(data[i] > data[j])
				swap(data+i, data+j);
		}
	}
	return 0;
}

/* Tri à bulle */
int sort_bulle(int data[], short size)
{
	for (int i = 1 ; i <= size ; i++) {
		for (int j = 0 ; j < size-1 ; j++) {
			if(data[j] > data[j+1])
				swap(data+j, data+(j+1));
		}
	}
	return 0;
}

/* Tri par permutation */
int sort_permut(int data[], short size)
{
	int i, j, tmp, k;

	for (i = 1 ; i < size ; i++) {
		if(data[i] < data[i-1]) {
			j = 0;
			while(data[i] > data[j]) j++;

			tmp = data[i];
			for(k = i-1 ; k >= j ; k--) data[k+1] = data[k]; // "Shift Reg"
			data[j] = tmp;
		}
	}
	return 0;
}

void FirstFactorial(int num)
{
	int i;

	for(i = num-1 ; i > 0 ; i--) {
		num *= i;
	}
	printf("%d", num);
}

/*********** Utilisation Structure ************/
int read_points(struct point my_point[])
{
	for(int i = 0 ; i < NB_POINTS ; i++) {
		printf("Rentre le num, x et y\n");
		scanf("%d %f %f", &my_point[i].num, &my_point[i].x, &my_point[i].y);
	}
	return 0;
}

int display_points(struct point my_point[])
{
	for (int i = 0 ; i < NB_POINTS ; i++) {
		printf("%d : ", my_point[i].num);
		printf("%f : ", my_point[i].x);
		printf("%f : ", my_point[i].y);
	}

	return 0;
}
/**********************************************/

/*********** Utilisation liste chaînée ********/
void creation(struct element * * adeb)
{
	int num;
	float x, y;
	struct element * current;
	* adeb = NULL;

	while (printf("numero x y :"),
			scanf("%d %f %f", &num, &x, &y), num)
	{
		current = (struct element*) malloc (sizeof(struct element));
		current->num = num;
		current->x = x;
		current->y = y;
		current->next = * adeb;
		* adeb = current;
	}
}

void display_list(struct element * start)
{
	while(start) {
		printf("Num : %d", (start)->num);
		printf("X : %f", (start)->x);
		printf("Y : %f", (start)->y);
		printf("\n");
		start = (start)->next;
	}
}
/**********************************************/

/* Algo recherche binaire */
int binarySearch(int * array, int thing, int start, int end)
{
	if(start > end)
		return 0;

	int mid = floor((start+end)/2);
	if(array[mid] == thing)
		return 1;

	if(thing < array[mid])
		return binarySearch(array, thing, start, mid - 1);

	else
		return binarySearch(array, thing, mid + 1, end);

}
