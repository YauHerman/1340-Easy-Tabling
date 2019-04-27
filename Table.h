#ifndef TABLE_H
#define TABLE_H
#include <chrono>
using namespace std;

struct table {
  int table_no;
  int no_of_cus;
  char status;
  int amount;
  // add starting time here
  table *next;
  int total_amount;
  chrono::system_clock::time_point time;
};

#endif
