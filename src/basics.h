/*
 * basics.h
 *
 *  Created on: 7 janv. 2020
 *      Author: quad
 */

#ifndef BASICS_H_
#define BASICS_H_

/* CONSTANTS */
#define NMAX      10
#define N_MAX_INT sizeof(int)
#define NB_POINTS 5

/* Structure */
struct point { int num;
				float x;
				float y;
};

int display_points(struct point my_point[]);
int read_points(struct point my_point[]);
void som(void);
void sub(int start_value);
float moyenne(void);
void triangle(int size);
int premier(int n);
int fibonacci(int n);
int _fibonacci(int n);
int print_table(int n);
void min_max(int tab[], short size);
void min_max_param(int data[], short size, int * min, int * max);
void min_max_ptr(int * data, short size);
void FirstFactorial(int num);
int binarySearch(int * array, int thing, int start, int end);
void swap(int * ad1, int * ad2);

#endif /* BASICS_H_ */
