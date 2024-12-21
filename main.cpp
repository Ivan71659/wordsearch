#include <iostream>
#include <vector>

using namespace std;

class node {
  public: 
    char letter;
    node* next;
    node* prev;

    node(char letter) {
      this->letter = letter;
      this->next = nullptr;
      this->prev = nullptr;
    }
};

class list {
  public: 
    node* head;
    node* tail;

    list () {
      head = nullptr;
      tail = nullptr;
    }

    void print () {
      node* current = head;
      while (current != nullptr){
        cout << current->letter << " ";
        current = current->next;
      }
      cout << "\n";
    }

    void add_back (char letter) {
      node* new_node = new node (letter);

      if(tail == nullptr) { 
         head = new_node;
         tail = new_node;
      }

      else {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
      } 
    }

    node* get_node (int position) {
      node* current = head;

      for(int i = 1; i < position; i++){
        current = current->next;
      }

      return current;
    }

    string check_row (int start_col, int end_col) {
      node* current = head;
      string word = "";
      
      for (int i = 1; i <= 12; i++) {
        if(i >= start_col && i <= end_col){
          word += current->letter;
        }
        current = current->next;
      }

      return word;
    }
};

string check_column (int start_row, int end_row, int column, vector <list> rows) {
  string word = "";
  
  for(int i = start_row - 1; i < end_row; i++){
    word += rows[i].get_node(column)->letter;
  }

  return word;
}

int main () {
  list l1;
  list l2;
  list l3;
  list l4;
  list l5;
  list l6;
  list l7;
  list l8;

  l1.add_back('J');
  l1.add_back('L');
  l1.add_back('I');
  l1.add_back('B');
  l1.add_back('P');
  l1.add_back('N');
  l1.add_back('Z');
  l1.add_back('Q');
  l1.add_back('O');
  l1.add_back('A');
  l1.add_back('J');
  l1.add_back('D');

  l2.add_back('K');
  l2.add_back('B');
  l2.add_back('F');
  l2.add_back('A');
  l2.add_back('M');
  l2.add_back('Z');
  l2.add_back('S');
  l2.add_back('B');
  l2.add_back('E');
  l2.add_back('A');
  l2.add_back('R');
  l2.add_back('O');

  l3.add_back('O');
  l3.add_back('A');
  l3.add_back('K');
  l3.add_back('T');
  l3.add_back('M');
  l3.add_back('I');
  l3.add_back('C');
  l3.add_back('E');
  l3.add_back('C');
  l3.add_back('T');
  l3.add_back('Q');
  l3.add_back('G');

  l4.add_back('Y');
  l4.add_back('L');
  l4.add_back('L');
  l4.add_back('S');
  l4.add_back('H');
  l4.add_back('O');
  l4.add_back('E');
  l4.add_back('D');
  l4.add_back('A');
  l4.add_back('O');
  l4.add_back('G');
  l4.add_back('U');

  l5.add_back('S');
  l5.add_back('L');
  l5.add_back('H');
  l5.add_back('C');
  l5.add_back('O');
  l5.add_back('W');
  l5.add_back('Z');
  l5.add_back('B');
  l5.add_back('T');
  l5.add_back('Y');
  l5.add_back('A');
  l5.add_back('H');

  l6.add_back('M');
  l6.add_back('H');
  l6.add_back('A');
  l6.add_back('N');
  l6.add_back('D');
  l6.add_back('S');
  l6.add_back('A');
  l6.add_back('O');
  l6.add_back('I');
  l6.add_back('S');
  l6.add_back('L');
  l6.add_back('A');

  l7.add_back('T');
  l7.add_back('O');
  l7.add_back('P');
  l7.add_back('I');
  l7.add_back('F');
  l7.add_back('Y');
  l7.add_back('P');
  l7.add_back('Y');
  l7.add_back('A');
  l7.add_back('G');
  l7.add_back('J');
  l7.add_back('T');

  l8.add_back('E');
  l8.add_back('Z');
  l8.add_back('T');
  l8.add_back('B');
  l8.add_back('E');
  l8.add_back('L');
  l8.add_back('T');
  l8.add_back('E');
  l8.add_back('A');
  l8.add_back('T');
  l8.add_back('A');
  l8.add_back('H');

  vector <list> rows = {l1,l2,l3,l4,l5,l6,l7,l8};
  vector <string> words = {"BELT","BEAR","SHOE","HAND","BALL","MICE","TOYS","BAT","DOG","TOP","HAT","COW","ZAP","GAL","BOY","CAT"};

  while (true) {
    cout << "\n";
    for (int i = 0; i < rows.size (); i++) {
      rows[i].print ();
    }
    cout << "\n";
    
    for (int i = 0; i < words.size (); i++) {
      cout << words[i] << " ";
      if ((i + 1) % 4 == 0) {
        cout << "\n";
      }
    }
    cout << "\n";
  
    string question1;
    cout << "where did you find your word, row or column? ";
    cin >> question1;
  
    if(question1 == "row"){
      int question2;
      cout << "which row? ";
      cin >> question2;
  
      int question3;
      cout << "which column does it start at? ";
      cin >> question3;
  
      int question4;
      cout << "which column does it end at? ";
      cin >> question4;

      string word = rows[question2 - 1].check_row(question3, question4);
      for (int i = 0; i < words.size(); i++) {
        if(word == words[i]){
          words[i] = "----";
        }
      }
    }
    
    if(question1 == "column"){
      int question2;
      cout << "which column? ";
      cin >> question2;
  
      int question3;
      cout << "which row does it start at? ";
      cin >> question3;
  
      int question4;
      cout << "which row does it end at? ";
      cin >> question4;
      string word = check_column(question3,question4,question2,rows);
      for (int i = 0; i < words.size(); i++) {
        if(word == words[i]){
          words[i] = "----";
        }
      }
    }

    int counter = 0;
    for(int i = 0; i < words.size(); i++){
      if(words[i] == "----"){
        counter += 1;
      }
    }
    
    if(counter == 16){
      break;
    }
  }

}
