#ifndef TABLE_H
#define TABLE_H

struct table {
  int table_no;
  int no_of_cus;
  char status;
  int amount;
  // add starting time here
  table *next;
};

#endif
