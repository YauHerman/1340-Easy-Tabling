#ifndef TABLESEARCHER_H
#define TABLESEARCHER_H

#include "Table.h"
#include "TableManager.h"
#include <chrono>
#include <iomanip>
using namespace std;

//TODO Search for the avaliable table
int search_for_avaliable(table *head, int customers){
  // read a status, this function returns the first  tables with given status
  table *current = head;
  int minDiff = -1;
  int tableNum = -1;
  while (current != NULL) {
    if (current->status != 'A' || customers > current->no_of_cus) {
      current = current->next;
      continue;
    }
    if (minDiff == -1 || current->no_of_cus - customers < minDiff) {
      minDiff = current->no_of_cus - customers;
      tableNum = current->table_no;
    }
    current = current->next;
  }
  return tableNum;
}


//TODO Check the status of a table
void check_table_status(int table_no, table *head){
  table *current = head;
  while (current != NULL) {
    // Idk is this while loop legal lol
    if (current -> table_no == table_no){
      cout << setw(10) << "Table No." << setw(10) << "Capacity" << setw(10) << "Status" << setw(10) << "Amount" << endl;
      cout <<  setw(10) << current->table_no <<  setw(10) <<current->no_of_cus <<  setw(10) << current->status  <<  setw(10) <<current->amount<<endl;
    }
    current = current->next;
  }
  return ;
}

#endif
