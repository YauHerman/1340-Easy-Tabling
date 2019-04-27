#ifndef TABLEMANAGER_H
#define TABLEMANAGER_H

#include "Table.h"
#include <string>
#include <vector>
#include <iostream>
#include <chrono>
using namespace std;

//vector<Table> tables;

//search for a table given a table no(key).
int search_for_table(int key, table *head) {
  if (head == NULL) return 0;
  table *current = head;
  int n=1;
  while (current != NULL) {
    // Idk is this while loop legal lol
    if (current -> table_no == key){
      return n;
    }
    current = current->next;
    n++;
  }
  return 0;
}



//TODO Change table configuration
void addTable(table * & head, table * & tail, int table_no, int no_of_cus) {
  if (search_for_table(table_no, head) != 0) {
    cout << "Table exists" << endl;
    return;
  } else {
    table *p = new table;
    p->table_no = table_no;
    p->no_of_cus = no_of_cus;
    p->status = 'A';
    p->amount = 0;
    p->total_amount = 0;
    p->next = NULL;
    // set time to null at this line
    if (head == NULL) {
      head = p;
      tail = p;
    } else {
      tail->next = p;
      tail = p;
    }
  }
}

void deleteTable(table *head, int table_no, int no_of_cus) {
  if(search_for_table(table_no, head)){
    table *current = head;
    while(current->next){
      if (current ->next -> table_no == table_no){
        table *p = current ->next;
        current->next=current->next->next;
        // how the delete data stored in p?
        return;
      }
      current = current->next;
    }
    delete current;
    return;
    //in case targeted table is the last table
  } else {
    cout << "Table does no exist"<<endl;
    return;
  }
}

void changeTable(table *head, int table_no, int no_of_cus) {
  int i = search_for_table(table_no, head);
  table *current = head;
  if(i){
    for (int k=0;k<i;k++){
      current = current->next;
    }
    current->no_of_cus = no_of_cus;
    return;
  } else {
    cout << "Table does no exist"<<endl;
    return;
  }
}

void change_table_config(string order, table *head, int table_no, int no_of_cus) {
  // this first read an order ("add"-add a table , "delete"-delete a table, "change" - change no of customers)
  //this function then reads a pointer pointing to the head of linked list, table no. of targeted table and new no. of customers.

}


//TODO Reserve a table
void reserve_table (table *head, int target_table){
  int i = search_for_table(target_table, head);
  table*current = head;
  if(i) {
    for (int k=1;k<i;k++) {
      current = current->next;
    }
    current->status = 'R' ;
    return;
  } else {
    cout << "Table does no exist"<<endl;
    return;
  }
  //this function then reads a pointer pointing to the head of linked list, table no. of targeted table

}
//TODO Occupy a table
void occupy_table (table *head, int target_table) {
  //this function then reads a pointer pointing to the head of linked list, table no. of targeted table,
  int i = search_for_table(target_table, head);
  table*current = head;
  if(i) {
    for (int k=1;k<i;k++) {
      current = current->next;
    }
    current->status = 'O' ;
    current->time = chrono::system_clock::now();
    return;
  } else {
    cout << "Table does no exist"<<endl;
    return;
  }
}

//TODO Release a table
int release_table (table *head, int target_table) {
  //this function then reads a pointer pointing to the head of linked list, table no. of targeted table
  int i = search_for_table(target_table, head);
  table*current = head;
  if(i) {
    for (int k=1;k<i;k++) {
      current = current->next;
    }
    current->status = 'A' ;
    int n = current->amount;
    current->total_amount += n;
    current->amount = 0;
    //reset amount to 0
    return n;
  } else {
    cout << "Table does no exist"<<endl;
    return 0;
  }
}

#endif
