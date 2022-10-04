#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define MAX_FIELD 25

struct record {
    struct record* next;
    struct record* previous;
    char name[MAX_FIELD];
    char address[MAX_FIELD];
    char phone[MAX_FIELD];
};
typedef struct record person;

typedef struct {
    person* first;
    person* last;
} people;

people *makeRolodex();
person *addPerson(people*, char *, char *, char *);
void sortRolodex(people *);
void swapFirstLast(people *, person *, person *);
void swapFirst(people *, person *, person *);
void swapLast(people *, person *, person *);
void swapRolodexPosition(people *, person *, person *);
void validateRolodex(people *);
person *makePerson(char *, char *, char *);
void destroyPerson(person *);
void printRolodex(people *);
int isEmpty(people *);
void removePerson(people *, char *);
int rolodexSize(people *P);
int main(int, char *[]);

people *makeRolodex() {
    people *P = (people *)malloc(sizeof(people));
    if (P == NULL) {
        fprintf(stderr, "error: unable to allocate memory.\n");
        fflush(stderr);
        return NULL;
    }
    P->first = NULL;
    P->last = NULL;
    return P;
}

person *addPerson(people *P, char *name, char *address, char *phone) {
    person *dude;
    person *a, *b;
    int len1, len2, len3;

    len1 = strlen(name);
    len2 = strlen(address);
    len3 = strlen(phone);
    if (len1>=MAX_FIELD || len2>=MAX_FIELD || len3>=MAX_FIELD) {
        fprintf(stderr, "error: name, address and phone must be less than %i characters.\n", MAX_FIELD);
        fflush(stderr);
        return NULL;
    }
    dude = makePerson(name, address, phone);
    if (dude == NULL) return NULL;

    if (P->first == NULL)  {
        P->first = dude;
        P->last = dude;
    } else {
        P->first->previous = dude;
        dude->next = P->first;
        P->first = dude;
    }
    printf("Added: %-20s : %-25s : %-20s\n",
        dude->name, dude->address, dude->phone);
    fflush(stdout);
    sortRolodex(P);
    return dude;
}

void sortRolodex(people *P) {
    person *a, *b;
    int sorted = TRUE;

    a = P->first;
    if (a == NULL) return ;
    b = a->next;
    if (b == NULL) return ;

    do {
        if (strcmp(a->name, b->name) < 0) {
            a = b;
            b = a->next;
        } else {
            swapRolodexPosition(P, a, b);
            b = a->next;
            sorted = FALSE;
        }

        if ((b == NULL || b->next == NULL) && !sorted) {
            a = P->first;
            b = a->next;
            sorted = TRUE;
        }
    // } while ((b != NULL && b->next != NULL) || !sorted);
    } while (b != NULL || !sorted);
    printf("Sorted rolodex.\n"); fflush(stdout);
    printRolodex(P);
    return ;
}

void swapFirstLast(people *P, person *a, person *b) {
    P->first = b;                   // set the first link
    P->last = a;                    // set the last link
    b->previous->next = a;          // set 1 next link
    a->previous = b->previous;      // set 3 previous links
    b->previous = NULL;
    a->next->previous = b;
    b->next = a->next;              // set 2 next links
    a->next = NULL;
    return ;
}

void swapFirst(people *P, person *a, person *b) {
    person *tmp;

    P->first = b;
    a->next = b->next;
    a->next->previous = a;
    a->previous = b;
    b->next = a;
    b->previous = NULL;
    return ;
}

void swapLast(people *P, person *a, person *b) {
    P->last = a;
    b->previous = a->previous;
    b->previous->next = b;
    b->next = a;
    a->previous = b;
    a->next = NULL;
    return ;
}

void swapRolodexPosition(people *P, person *a, person *b) {
    person tmp;

    if (P==NULL || a==NULL || b==NULL) {
        fprintf(stderr, "error: unable to swap positions in rolodex.\n");
        fflush(stderr);
        return ;
    }
    
    if (P->first == a)
        if (P->last == b) swapFirstLast(P, a, b);
        else swapFirst(P, a, b);
    else if (P->first == b)
        if (P->last == a) swapFirstLast(P, b, a);
        else swapFirst(P, b, a);
    else if (P->last == a)
        swapLast(P, b, a);
    else if (P->last == b)
        swapLast(P, a, b);
    else {
        b->previous = a->previous;
        b->previous->next = b;
        a->next = b->next;
        a->next->previous = a;
        b->next = a;
        a->previous = b;
    }
}

void validateRolodex(people *P) {
    person *a, *b;
    if ((P->first == NULL && (P->last != NULL || P->first->previous != NULL)) ||
        (P->last == NULL && (P->first != NULL || P->last->next != NULL))) {
        fprintf(stderr, "error: fake empty.\n");
        fflush(stderr);
        return ;
    }
    a = P->first;
    b = a->next;
    while (b!=NULL) {
        if (a->previous==a || a->next==a) {
            fprintf(stderr, "error: %s is self-referential.\n", a->name); fflush(stderr);
            return ;            
        }
        if (b->previous==b || b->next==b) {
            fprintf(stderr, "error: %s is self-referential.\n", b->name); fflush(stderr);
            return ;            
        }
        if (a->next!=b || b->previous!=a) {
            fprintf(stderr, "error: unmatched links %s and %s.\n", a->name, b->name); fflush(stderr);
            return ;
        }
        a = b;
        b = a->next;
    }
    printf("Validated rolodex.\n"); fflush(stdout);
    return ;
}

person *makePerson(char *name, char *address, char *phone) {
    person *dude;

    dude = (person *)malloc(sizeof(person));
    if (dude == NULL) {
        fprintf(stderr, "error: unable to allocate memory.\n"); fflush(stderr);
        return NULL;
    }

    dude->next = NULL;
    dude->previous = NULL;
    strcpy(dude->name, name);
    strcpy(dude->address, address);
    strcpy(dude->phone, phone);
    printf("Made: %-20s : %-25s : %-20s\n",
        dude->name, dude->address, dude->phone); fflush(stdout);
    return dude;
}

void destroyPerson(person *dude) {
    free(dude);
}

void printRolodex(people *P) {
    person* a = P->first;

    validateRolodex(P);
    printf("\n--- %d people in rolodex ---\n", rolodexSize(P));
    while(a != NULL) {
        printf("%-20s : %-25s : %-20s\n", a->name, a->address, a->phone);
        a = a->next;
    }
    fflush(stdout);
}

int isEmpty(people *P){
    return (P->first == NULL);
}

void removePerson(people *P, char *name) {
    person *a;

    a = P->first;
    if (a == NULL) {
        fprintf(stderr, "error: %s is not in the rolodex.\n", name); fflush(stderr);
        return;
    }

    while(TRUE) {
        if (strcmp(a->name, name) == 0) {
            if (P->first == a) P->first = P->first->next;
            if (P->last == a) P->last = P->last->previous;
            if (a->next != NULL) a->next->previous = a->previous;
            if (a->previous != NULL) a->previous->next = a->next;
            destroyPerson(a);
            printf("%s is removed from the rolodex.\n", name); fflush(stdout);
            return;
        }        
        if (a->next == NULL) {
            fprintf(stderr, "error: %s is not in the rolodex.\n", name); fflush(stderr);
            return;
        }
        a = a->next;
    }
}

int rolodexSize(people *P) {
    person* a = P->first;
    int cnt = 0;
    
    while(a != NULL) {
        a = a->next;
        cnt++;
    }
    return cnt;
}

int main(int argc, char *argv[]) {
    people *rolodex = makeRolodex();
    person *dude;

    if(isEmpty(rolodex)) printf("PASSED: Empty rolodex at start.\n");
    printf("%d people in rolodex.\n\n", rolodexSize(rolodex)); fflush(stdout);

    dude=addPerson(rolodex, "Chris Kringle", "1000 North Pole", "1-800-4SANTAC");
    if (dude==NULL) return-1;
    dude=addPerson(rolodex, "Herman Munster", "1313 Mockingbird Lane", "206-555-5555");
    if (dude==NULL) return -1;
    dude=addPerson(rolodex, "George Washington", "1600 Pennsylvania Ave NW", "(202) 456-1111");
    if (dude==NULL) return -1;
    dude=addPerson(rolodex, "Buffalo Bill", "Dodge City, KS", "(620) 555-5555");
    if (dude==NULL) return -1;
    dude=addPerson(rolodex, "Superman", "Metropolis, Illinois", "618-555-5555"); 
    if (dude==NULL) return -1;
    // printRolodex(rolodex);

    removePerson(rolodex, "Superman");
    removePerson(rolodex, "Buffalo Bill");
    removePerson(rolodex, "George Washington");
    printRolodex(rolodex);

    return 0;
}