/*
 * string_manip.c
 *
 *  Created on: 11 apr. 2020
 *      Author: quad
 */

#include "string_manip.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>

int nb_char(char * str, char c, short size)
{
	int cpt = 0 ;

	if(size > LINE_MAX) {
		printf("Petit problème dans ma plantation\n");
		return -1;
	}
	else {
		for (int i = 0 ; i < size ; i++) {
			if(str[i] == c)
				cpt++;
		}
	}
	return cpt;
}

int isAlphaNum(char c)
{
	return (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')) || ((c >= '0') && (c <= '9')));
}

void LongestWord(char * sen)
{
    int cpt_word = 0;
    int i;
    int size = strlen(sen);
    char result[size];
    char tmp[size];

    for (i = 0 ; i <= size ; i++) {
    	if(isalnum(sen[i])) {
    		tmp[cpt_word++] = sen[i];
    	}
    	else {
    		cpt_word = 0;
    		if(strlen(tmp) > strlen(result)) {
    			strcpy(result, tmp);
    		}
    	}
    }
    printf("%s", result);
}

void FirstReverse(char * str)
{
	int size = strlen(str);
	char tmp[size];

	for(int i = 0 ; i <= size ; i++) {
		tmp[i] = str[(size-1)-i];
	}
	printf("%s", tmp);
}

void delete_char(char * str, char c )
{
	char * addr;
	addr = str;

	while(addr = strchr(addr, c)) {
		strcpy(addr, addr+1);
	}

	puts(str);

}

void create_file(char file_name[])
{
	FILE * file;
	int new_contact;
	struct contact myContact;
	char c;

	file = fopen(file_name, "w");

	do {
		printf("Donner nom:");
		scanf("%s",&myContact.nom); getchar();
		printf("Donner prenom:");
		scanf("%s", &myContact.prenom); getchar();
		printf("Donner age:");
		scanf("%d", &myContact.age ); getchar();
		printf("Donner téléphone:");
		scanf("%s", &myContact.tel); getchar();

		fwrite(&myContact.nom, sizeof(myContact), 1, file);
		fprintf(file, "\n");
		fwrite(&myContact.prenom, sizeof(myContact), 1, file);
		fprintf(file, "\n");
		fwrite(&myContact.age, sizeof(myContact), 1, file);
		fprintf(file, "\n");
		fwrite(&myContact.tel, sizeof(myContact), 1, file);
		fprintf(file, "\n");

		printf("Nouveau contact ?"); c = getchar();
		new_contact = (c == 'O' ? 1 : 0);

	}while(new_contact);

	fclose(file);
}

void display_file(char file_name[])
{
	FILE * file;
	int num = 1;
	char ligne[LINE_MAX_F];

	file = fopen(file_name, "r");
	while(fgets(ligne, LINE_MAX_F, file)) {
		printf("%5d", num++);
		printf("%s", ligne);
	}
	fclose(file);
}
