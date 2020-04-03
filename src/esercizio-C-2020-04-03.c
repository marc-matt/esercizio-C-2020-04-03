// IN PROGRESS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 64
#define PHONE_LEN 20

int counter = 0;

typedef struct {
   int id; // id numerico del contatto (valore univoco)
   char name[NAME_LEN + 1]; // nome della persona
   char phone[PHONE_LEN + 1]; // numero di telefono
} contact_type;

contact_type * create_contact(char * name, char * phone){
  contact_type person = {counter, name, phone};
  contact_type * contact_pointer;
  contact_pointer = &person;
  person.id = counter;
  counter++;
  return contact_pointer;
}

void print_contact(contact_type * person){
  contact_type temp = *person;
  printf("%d %s %s\n", temp.id, temp.name, temp.phone);
}

int main(int argc, char *argv[]) {
	contact_type * pino = create_contact("pino rossi", "+393331234567");
	if(pino == NULL) {
		printf("errore in create_contact!\n");
		exit(EXIT_FAILURE);
	}
	contact_type * gino = create_contact("gino verdi", "+393487654321");
	if(gino == NULL) {
		printf("errore in create_contact!\n");
		exit(EXIT_FAILURE);
	}
	print_contact(pino);
  print_contact(gino);
	return 0;
}
