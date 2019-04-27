#ifndef TABLESEARCHER_H
#define TABLESEARCHER_H

#include "Table.h"
#include "TableManager.h"
#include <chrono>
#include <iomanip>
using namespace std;

//Search for the next avaliable table.
//The table's capacity must be higher than the number of customers.
//The table with the smallest difference between the number of customers and the capacity will be chosen.
//Inputs: head - The address of the head of the list of tables.
//        customers - The number of customers.
//Output: The table number.
int search_for_avaliable(table *head, int customers) {

  //Initialize varaibles
  table *current = head;
  int minDiff = -1;
  int tableNum = -1;

  //Read through the list of tables
  while (current != NULL) {

    //Only avaliable tables will be chosen
    //Only tables with capacity higher than the number of customers will be chosen
    if (current->status != 'A' || customers > current->no_of_cus) {
      current = current->next;
      continue;
    }

    //Choose the table with the minimum difference
    if (minDiff == -1 || current->no_of_cus - customers < minDiff) {
      minDiff = current->no_of_cus - customers;
      tableNum = current->table_no;
    }
    current = current->next;

  }

  return tableNum;

}


//Prints the header
void printHeader() {

  cout << left;
  cout << setw(10) << "Table No." << setw(10) << "Capacity" << setw(10) << "Status" << setw(10) << "Amount" << setw(15) << "Starting Time" << endl;

}

//Print the individual status of a table withOUT a header.
//Input: t - the table to be printed.
void printTableStatus(table *t) {

  cout << left;
  if (t->status == 'O') {
    time_t time = chrono::system_clock::to_time_t(t->time);
    cout << setw(10) << t->table_no << setw(10) << t->no_of_cus << setw(10) << t->status << setw(10) << t->amount << setw(15) << ctime(&time);
  } else {
    cout << setw(10) << t->table_no << setw(10) << t->no_of_cus << setw(10) << t->status << setw(10) << "N/A" << setw(15) << "N/A" << endl;
  }
}

//Print all status of all the tables WITH the header.
//Input: t - The address of the head of the list of tables.
void printAllTableStatus(table *t) {

  printHeader();
  cout << left;
  while (t != NULL) {
    printTableStatus(t);
    t = t->next;
  }

}

//Check the status of a table.
//Inputs: table_no - The table number.
//        head - The address of the head of the list of tables.
void check_table_status(int table_no, table *head){

  table *current = head;
  while (current != NULL) {
    if (current -> table_no == table_no){
      printHeader();
      printTableStatus(current);
    }
    current = current->next;
  }
  
}

#endif
