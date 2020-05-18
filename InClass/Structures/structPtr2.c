#include <stdio.h>
#include <string.h>


typedef struct Books{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
}book_t;

/* function declaration */
void printBook(book_t *book );
int main( ) {

    book_t Book1;        /* Declare Book1 of type Book */
    book_t Book2;        /* Declare Book2 of type Book */

   /* book 1 specification */
   strcpy( Book1.title, "Cross Justice");
   strcpy( Book1.author, "James Patterson");
   strcpy( Book1.subject, "Mystery");
   Book1.book_id = 6495407;

   /* book 2 specification */
   strcpy( Book2.title, "A Painted House");
   strcpy( Book2.author, "John Grisham");
   strcpy( Book2.subject, "Mystery");
   Book2.book_id = 6495700;

   /* print Book1 info by passing address of Book1 */
   printBook( &Book1 );

   /* print Book2 info by passing address of Book2 */
   printBook( &Book2 );

   return 0;
}

void printBook(book_t *book ) {

   printf( "Book title : %s\n", book->title);
   printf( "Book author : %s\n", book->author);
   printf( "Book subject : %s\n", book->subject);
   printf( "Book book_id : %d\n", book->book_id);
}
