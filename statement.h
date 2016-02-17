#include <my_global.h>
#include <stdio.h>
#include <string.h>
#include <mysql.h>
#include "config.h"
#include "connection.h"

int statement(char query) {

  /*result set */ 
  MYSQL_RES *result;
  
  /* an instance of a row from the result */
  MYSQL_ROW row;  
  
  int x;
  
  conn = connection();
  
  /* run the SQL query */
  if (mysql_query(conn, query)) {
    perror(mysql_error(conn));
    return 0;
  }
  
  result = mysql_use_result(conn);
  
  printf("+----------------------+\n");
  printf("|        RESULT        |\n");
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
  mysql_close(conn);
  
  return 0;
}
