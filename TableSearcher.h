#ifndef TABLESEARCHER_H
#define TABLESEARCHER_H

#include "Table.h"
#include "TableManager.h"
#include <vector>
#include <iomanip>
using namespace std;

//TODO Search for the avaliable table
int search_for_table(table *head,char status){
    // read a status, this function returns the first  tables with given status
    table *current = head;
    while (current != NULL) {
      // Idk is this while loop legal lol
      if (current ->status == status){
        return current -> table_no;
     
        }
      current = current->next;}
    return 0;}


//TODO Check the status of a table
void check_table_status(int table_no, table *head){
  table *current = head;
  while (current != NULL) {
    // Idk is this while loop legal lol
    if (current -> table_no == table_no){
   cout << setw(10) << "Table No." << setw(10) << "Capacity" << setw(10) << "Status" << setw(10) << "Amount" << endl;
   cout <<  setw(10) << current->table_no <<  setw(10) <<current->no_of_cus <<  setw(10) << current->status  <<  setw(10) <<current->amount<<endl;
      }
    current = current->next;}
  return ;}

#endif
