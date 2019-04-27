#ifndef TABLESEARVICE_H
#define TABLESEARVICE_H

#include "Table.h"
#include "TableManager.h"
#include <chrono>
#include <iostream>
using namespace std;

//Make an order for a table.
//Inputs: head - The address of the head of the list of tables.
//        tasble_no - The table number.
//        amount - The amount of the order.
//Output: True if the order is successfully added, false otherwise.
bool ordering(table*head, int table_no, int amount) {

  table *current = head;
  //Get the table object with the table number
  while (current != NULL) {
    if (current -> table_no == table_no) {

      //Only occupied tables can make orders.
      if (current->status != 'O') {
        cout << "[!] The table is not occupied!" << endl;
        return false;
      }

      //The final amount cannot be smaller than 0.
      if (current->amount + amount < 0) {
        cout << "[!] The result amount cannot be smaller than 0!"
        return false;
      }

      current -> amount += amount;
      return true;

    }
    current = current->next;
  }

  cout<< "[!] Table does not exist!"<<endl;
  return false;

}

//Check through the list of tables whether it is occupied for more than x minutes.
//Inputs: head - The address of the head of the list of tables.
//        minutes - The number of minutes for a table to be considered idle.
void checkIdleTable(table *head, int minutes) {

  //Get the time now
  auto now = chrono::system_clock::now();

  //Loop through the list
  while (head != NULL) {

    //Only occupied tables will be considered
    if (head->status != 'O') {
      head = head->next;
      continue;
    }

    //Calculate the time difference
    chrono::duration<double> seconds = now - head->time;
    if (seconds.count() > minutes * 60) {
      cout << "[i] Table " << head->table_no << " has been occupied for more than " << minutes << " minutes!" << endl;
    }

    head = head->next;
    
  }
}

#endif
