#ifndef TABLE_H
#define TABLE_H
#include <chrono>
using namespace std;

//Structure table
//table_no - The ID of the table
//no_of_cus - The capacity of the table
//status - The status of the table, will be either 'O' for occupied, 'A' for avaliable or 'R' for reserved.
//amount - The order amount of the table.
//total amount - The total order amount.
//time - The time the table is occupied.
//next - points to the address of the next table.
struct table {
  int table_no;
  int no_of_cus;
  char status;
  int amount;
  table *next;
  int total_amount;
  chrono::system_clock::time_point time;
};

#endif
