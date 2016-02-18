#include <my_global.h>
#include <stdio.h>
#include <string.h>
#include <mysql.h>
#include "config.h"
#include "connection.h"


int main() {
  MYSQL *conns;
  MYSQL_RES *result;      /* result set */
  MYSQL_ROW row;  /* an instance of a row from the result */
  
  int x;
  
  char query[1000];
  conn = mysql_init(NULL);
  conns = connection();
  
  printf("Query: ");
  fgets(query, 1000, stdin);
  printf("\n");
  
  /* run the SQL query */
  if (mysql_query(conns, query)) {
    perror(mysql_error(conns));
    return 0;
  }

  result = mysql_use_result(conns);

  printf("+----------------------+\n");
  printf("|        RESULT(S)     |\n");
  printf("+----------------------+\n");

  /* print out the results */
  while ((row = mysql_fetch_row(result)) != NULL) {
    printf("| %s", row[0]);
    /* layout */
    for(x = strlen(row[0]); x < 21; x++)
    printf(" ");

    printf("|\n");
  }

  printf("+----------------------+\n");

  /* clean up */  
  mysql_free_result(result);
  mysql_close(conns);

  return 0;
}

  
