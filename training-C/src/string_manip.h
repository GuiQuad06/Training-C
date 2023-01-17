/*
 * string_manip.h
 *
 *  Created on: 11 apr. 2020
 *      Author: quad
 */

#ifndef STRING_MANIP_H_
#define STRING_MANIP_H_

#include <string.h>

#define LINE_MAX   133
#define LINE_MAX_F 81

struct contact {
	char nom[21];
	char prenom[16];
	int  age;
	char tel[12];
};

int nb_char(char * str, char c, short size);
void delete_char(char * str, char c );
int isAlphaNum(char c);
void FirstReverse(char * str);
void LongestWord(char * sen);
void create_file(char file_name[]);
void display_file(char file_name[]);

#endif /* STRING_MANIP_H_ */
