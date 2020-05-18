#include <stdio.h>
#include <string.h>

struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};

/* function declaration */
void printBook( struct Books book );

int main( ) {

   struct Books Book1;        /* Declare Book1 of type Book */
   struct Books Book2;        /* Declare Book2 of type Book */

   /* book 1 specification */
   strcpy( Book1.title, "American Assassin");
   strcpy( Book1.author, "Vince Flynn");
   strcpy( Book1.subject, "Mitch Rapp Series");
   Book1.book_id = 6495407;

   /* book 2 specification */
   strcpy( Book2.title, "The Hunt for Red October");
   strcpy( Book2.author, "Tom Clancy");
   strcpy( Book2.subject, "Spy, suspense");
   Book2.book_id = 6495700;

   /* print Book1 info */
   printBook( Book1 );

   /* Print Book2 info */
   printBook( Book2 );

   return 0;
}

void printBook( struct Books book ) {

   printf( "Book title : %s\n", book.title);
   printf( "Book author : %s\n", book.author);
   printf( "Book subject : %s\n", book.subject);
   printf( "Book book_id : %d\n", book.book_id);
}
