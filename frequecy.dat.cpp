#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

/* 
Implementation of the usage of class with one public and one private section
*/
class NumberItems {
    private: 
    map<string, int> ItemCount;

    public: 
    void readTextFile(const string& filename){
        // reads each element in the text file
        ifstream inputTextFile(filename);
        // txt file composed of elements, 'item' as a string
        string item;
        // while statement: while there is another item in list, increment the count
        while (inputTextFile >> item){
            itemCount[item]++;
        }
        inputTextFile.close();
    }

/* Menu Option One: 
1. Prompt a user to input the item, or word, they wish to look for.
2. Return a numeric value for the frequency of the specific word.
*/ 
    // Defining function to count frequency of the item in the list
    int getItemCount(const string& item){
        return itemCount[item];
    }

/* Menu Option Two:
1. Print the list with numbers that represent the frequency of all items purchased.
The screen output should include every item paired with a the numer of times that item appears in the input file.
*/
    // Defining function to print the item list with corresponding numerical time that the item appears
    void printItemCount(){
        for (const auto& entry : itemCount){
            cout << entry.first << ": " << entry.next << endl;
        }
    }

/* Menu Option Three:
1. Print the same frequency information for all the items in the form of a histogram.
2. Print the name, followed by asterisks or another special character to represent the numeric amount. 
The number of asteriks should equal the frequency read from the input text file. 
*/
    // Defining function to print the corresponding nummber of astericks next to the item, representing the amount of times the item appears. 
    void printItemHistogram(){
        for (const auto& entry : itemCount){
            cout << entry.first << " ";
            // for each item in list, prints item with asterick to match count 
            for (int i = 0, i < entry.next; i++){
                cout << "*";
            }
            cout << endl;
        }
    }
}

// Main Function 
int main() {
    // class items created
    NumberItems items;
    // reads the text file 
    items.readTextFile("CS210_Project_Three_Input_File.txt")


    int Option;
    while (true){
        // Give user options, then prompeted for a response
        cout << "From the Menu, choose Option 1, 2, 3 , or 4 and hit Enter."
        cout << "Menu:" << endl;
        cout << "Option 1: Numerical Count of Specified Item" << endl;
        cout << "Option 2: Print Items with Numerical Count" << endl;
        cout << "Option 3: Print Items with Histogram" << endl;
        cout << "Option 4: Exit" << endl;
        cout << "Your Option is Option #: "
        cin >> Option;

        // If and else if statement depending on the option the use rinputs. 
        // For the first open, the defined function (getItemCount) is called.
        if (Option == 1) {
            string item;
            cout << "Enter the item are you looking for: ";
            cin >> item;
            cout << "Count: " << items.getItemCount(item) << endl;
        // if the second option is picked by the user, (printItemCount) is called. 
        } else if (Option == 2){
            item.printItemCount();
        } else if (Option == 3){
        // if the second option is picked by the user, (printItemHistoram) is called.            
            item.printItemHistogram();
        // If option for is chosen, the program is Exited.
        } else if (Option == 4){
            break;
        // When none of the options are chosen, an error message appears. 
        } else{ 
            cout << "Try Again: Valid Response '1', '2', '3', '4'. " << endl;
        }
    }

// end program
    return 0;
}


