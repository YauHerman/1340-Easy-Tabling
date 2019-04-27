#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <chrono>
#include "Table.h"
#include "TableManager.h"
#include "TableSearcher.h"
#include "TableService.h"
using namespace std;

//Main Program, has 3 parts.
//1. Read input from a text file.
//2. Handle commands from users while providing a text menu.
//3. Output a report to a text file.
int main() {

  //Initialize linked list and default idle value
  table * head = NULL;
  table * tail = NULL;
  int idleMins = 120;

  //Read input config file, terminate program if failed.
  ifstream fin;
  fin.open("config.txt");
  if (fin.fail()) {
    cout << "[!] Failed to read the configuration file!" << endl;
    cout << "[!] The program will end now..." << endl;
    exit(1);
  }

  //Create tables according to the config.
  string tmp;
  int n = 1, x;
  getline(fin,tmp);
  while (fin >> x) {
    addTable(head, tail, n, x);
    n++;
  }
  fin.close();

  //The main menu
  char in;
  while (true) {

    //Output all status of the tables and check idle time
    cout << endl;
    printAllTableStatus(head);
    checkIdleTable(head, idleMins);

    //Main menu layer 1
    cout << endl << "MAIN MENU" << endl;
    cout << "-----" << endl;
    cout << "1. Table Operation" << endl;
    cout << "2. Table Searching" << endl;
    cout << "3. Table Service" << endl;
    cout << "0. End Program" << endl << endl;
    cout << "[?] Please input number (0 - 3): > ";

    cin >> in;
    if (in == '0') {

      //Confirm program termination
      cout << endl << "[?] Program will end, are you sure? (Y/N): > ";
      cin >> in;
      if (in == 'Y') {
        cout << endl << "[i] Thank you for using Easy Tabling." << endl;
        cout << endl << "[i] Made by To Ming Lok and Yau Herman, all rights reserved." << endl;
        cout << endl << "A report.txt will be generated at the root folder." << endl;
        break;
      }
    } else if (in == '1') {

      //Main menu layer 2
      cout << endl << "TABLE OPERATION" << endl;
      cout << "-----" << endl;
      cout << "+. Occupy table" << endl;
      cout << "*. Reserve table" << endl;
      cout << "-. Release table" << endl;
      cout << "/. Change table configuration" << endl;
      cout << "0. Back" << endl << endl;
      cout << "[?] Please input symbol: > ";

      cin >> in;
      if (in == '+') {

        //Occupy a table
        cout << endl << "[?] What table number to occupy? > ";
        cin >> x;
        if (occupy_table(head, x)) {
          cout << "[i] Successfully occupied table " << x << "." << endl;
        }

      } else if (in == '*') {

        //Reserve a table
        cout << endl << "[?] What table number to reserve? > ";
        cin >> x;
        if (reserve_table(head, x)) {
          cout << "[!] Successfully reserved table " << x << "." << endl;
        }

      } else if (in == '-') {

        //Release a table
        cout << endl << "[?] What table number to release? > ";
        cin >> x;
        int amount = release_table(head, x);
        if (amount >= 0)
          cout << "[i] Table " << x << " has been released, the total amount is $" << amount << "." << endl;

      } else if (in == '/') {

        //Change capacity of a TableService
        cout << endl << "[?] What table number to change configuration? > ";
        cin >> x;
        cout << endl << "[?] Change to what capacity? > ";
        cin >> n;
        if (n <= 0) {
          cout << endl << "[!] The new capacity needs to be larger than 0!" << endl;
        } else changeTable(head, x, n);

      } else continue;

    } else if (in == '2') {

      //Main menu layer 2
      cout << endl << "TABLE SEARCHING" << endl;
      cout << "-----" << endl;
      cout << "!. Get next avaliable table" << endl;
      cout << "?. Check status of a table" << endl;
      cout << "0. Back" << endl << endl;
      cout << "[?] Please input symbol: > ";

      cin >> in;
      if (in == '!') {

        //Search for the next avaliable table
        cout << endl << "[?] How many customers? > ";
        cin >> x;

        if (x <= 0) {
          cout << endl << "[!] Number of customers must be larger than 0." << endl;
        }

        int tableNum = search_for_avaliable(head, x);
        if (tableNum <= 0) {
          cout << endl << "[i] No table avaliable for " << x << " customers right now." << endl;
        } else {
          cout << endl << "[i] Table " << tableNum << " is avaliable for " << x << " customers." << endl;
        }

      } else if (in == '?') {

        //Check status of a table
        cout << endl << "[?] Which table to search for? > ";
        cin >> x;
        check_table_status(x, head);

      } else continue;

    } else if (in == '3') {

      //Main menu layer 2
      cout << endl << "TABLE SERVICE" << endl;
      cout << "-----" << endl;
      cout << "+. Add an order" << endl;
      cout << "@. Change table idle notification time" << endl;
      cout << "0. Back" << endl << endl;
      cout << "[?] Please input symbol: > ";

      cin >> in;
      if (in == '+') {

        //Add a order for a table
        cout << endl << "[?] Which table is ordering? > ";
        cin >> x;
        cout << endl << "[?] How much is the amount of the order? ($) > ";
        cin >> n;
        if (ordering(head, x, n))
        cout << endl << "[i] $" << n << " has been added for table " << x << ".";

      } else if (in == '@') {

        //Change the idle value
        cout << endl << "[i] Current idle minutes is " << idleMins << "." << endl;
        cout << "[?] How many minutes should a occupied table considered idle? > ";
        cin >> x;

        if (x <= 0) {
          cout << endl << "[!] Idle minutes time has to be larger than 0!" << endl;
        }
        idleMins = x;
        cout << endl << "[i] The idle time has been set to " << x << " minutes." << endl;

      }

    }

  }

  //Output to a file, terminate if failed
  ofstream fout;
  fout.open("report.txt");
  if (fout.fail()) {
    cout << "[!] Failed to generate the report!" << endl;
    cout << "[!] The program will end now..." << endl;
    exit(1);
  }

  //Output with style... I mean format.
  fout << left;
  fout << setw(10) << "Table No." << setw(10) << "Capacity" << setw(10) << "Total ($)" << endl;
  table *current = head;
  int sum = 0;
  while (current != NULL) {
    fout << setw(10) << current->table_no << setw(10) << current->no_of_cus << setw(10) << current->total_amount << endl;
    sum += current->total_amount;
    table * tmp = current;
    current = current->next;
    //Save some memory
    delete tmp;
  }
  fout.close();

}
