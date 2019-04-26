#ifndef TABLEMANAGER_H
#define TABLEMANAGER_H

#include "Table.h"
#include <vector>
using namespace std;

vector<Table> tables;

//search for a table given a table no(key).
int search_if_table_exist(int key, table *head){
  table *current = head;
  while (current != NULL) {
    // Idk is this while loop legal lol
    if (current -> table_no == key){
      return 1;}
    current = current->next}
  return 0;}
  
  

//TODO Change table configuration
void change_table_config( string order, table *&head, int table_no, int no_of_cus){
  // this first read an order ("add"-add a table , "delete"-delete a table, "change" - change no of customers)
  //this function then reads a pointer pointing to the head of linked list, table no. of targeted table and new no. of customers.
if (order == "add"){
  if(search_if_table_exist(table_no, head)){
    cout << "Table already existed" << endl;}
  else{
  table *p = new table;
  p->table-no = table_no;
  p->no_of_cus = no_of_cus;
  p->status = NULL;
  p->amount = NULL;
  p->time = NULL;
  p->next = head;
  head = p;}
  }
  
}

//TODO Reserve a table
void reserve_table (table *head, int target_table){
  //this function then reads a pointer pointing to the head of linked list, table no. of targeted table
  
}
//TODO Occupy a table
void occupy_table (table *head, int target_table){
  //this function then reads a pointer pointing to the head of linked list, table no. of targeted table, 
}
  
  //TODO Release a table
void release_table (table *head, int target_table){
  //this function then reads a pointer pointing to the head of linked list, table no. of targeted table
}

void addTable(Table t) {
  tables.push_back(t);
}

int testFunction(Table t) {
  return t.table_num;
}

#endif
