#ifndef TABLEMANAGER_H
#define TABLEMANAGER_H

#include "Table.h"
#include <string>
#include <vector>
#include <iostream>
#include <chrono>
using namespace std;


//Search for a table given a table number.
//Inputs: key - The table number.
//        head - The address of the head of the list of tables.
//Ouput: The table number if found, 0 if not found.
int search_for_table(int key, table *head) {

  if (head == NULL) return 0;
  table *current = head;
  int n=1;

  while (current != NULL) {
    if (current -> table_no == key){
      return n;
    }
    current = current->next;
    n++;
  }
  return 0;

}

//Add a table to the linked list
//Inputs: head - The address of the head of the list of tables.
//        tail - The address of the tail of the list of tables.
//        table_no - The ID of the table.
//        no_of_cus - The capacity of the table.
void addTable(table * & head, table * & tail, int table_no, int no_of_cus) {

  //If a table with the same ID is present, give an error.
  if (search_for_table(table_no, head) != 0) {
    cout << "[!] The same table already exists!" << endl;
    return;
  } else {

    //Create the table, initialize it with default values.
    table *p = new table;
    p->table_no = table_no;
    p->no_of_cus = no_of_cus;
    p->status = 'A';
    p->amount = 0;
    p->total_amount = 0;
    p->next = NULL;

    //Add the table to the list
    if (head == NULL) head = p;
    else tail->next = p
    tail = p;

  }
}

//Changes the capacity of the table.
//Inputs: head - The address of the head of the list of tables.
//        table_no - The ID of the table.
//        no_of_cus - The capacity of the table.
void changeTable(table *head, int table_no, int no_of_cus) {

  //Search for the table, error if it does not exit.
  int i = search_for_table(table_no, head);
  table *current = head;
  if(i) {

    //Updates the capacity
    for (int k=1;k<i;k++){
      current = current->next;
    }
    current->no_of_cus = no_of_cus;

  } else {
    cout << "[!] Table does not exist!"<<endl;
  }
}

//Reserves a table.
//Inputs: head - The address of the head of the list of tables.
//        target_table - The ID of the table.
//Output: True if the table is successfully reserved, false otherwise.
bool reserve_table (table *head, int target_table){

  //Search for the table, gives warning if it does not exist.
  int i = search_for_table(target_table, head);
  table*current = head;
  if(i) {

    for (int k=1;k<i;k++) {
      current = current->next;
    }
    //Only avaliable tables can be reserved.
    if (current->status != 'A') {
      cout << "[!] The table is not avaliable!" << endl;
      return false;
    }
    current->status = 'R' ;
    return true;

  } else {
    cout << "[!] Table does not exist!"<<endl;
    return false;
  }

}

//Occupies a table.
//Inputs: head - The address of the head of the list of tables.
//        target_table - The ID of the table.
//Output: True if the table is successfully occupied, false otherwise.
bool occupy_table (table *head, int target_table) {

  //Search for the table, gives warning if not found.
  int i = search_for_table(target_table, head);
  table*current = head;
  if(i) {

    for (int k=1;k<i;k++) {
      current = current->next;
    }
    //Only reserved or avaliable tables can be occupied.
    if (current->status == 'O') {
      cout << "[!] The table is already occupied!" << endl;
      return false;
    }

    //Update the status and mark down the time
    current->status = 'O' ;
    current->time = chrono::system_clock::now();
    return true;

  } else {

    cout << "[!] Table does not exist!"<<endl;
    return false;

  }
}

//Releases a table.
//Inputs: head - The address of the head of the list of tables.
//        target_table - The ID of the table.
//Output: The order amount of the table, or -1 if failed to release the table.
int release_table (table *head, int target_table) {

  //Search for the table, gives a warning if not found.
  int i = search_for_table(target_table, head);
  table*current = head;
  if(i) {

    for (int k=1;k<i;k++) {
      current = current->next;
    }
    //Only occupied tables can be released.
    if (current->status != 'O') {
      cout << "[!] The table is not occupied!" << endl;
      return -1;
    }

    //Updates the status and resets the amount.
    //Adds to the total amount.
    current->status = 'A' ;
    int n = current->amount;
    current->total_amount += n;
    current->amount = 0;
    return n;

  } else {
    cout << "[!] Table does not exist!"<<endl;
    return -1;
  }
  
}

#endif
