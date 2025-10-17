#include "StackandQueue.cpp"
using namespace std;
int main(){
    string input_files[]={"california.txt", "halloween calories.txt",
                    "harry potter..txt", "pokemon.txt", "programming.txt", 
                    "soft drinks.txt", "testFile.txt"};
    //UserInput to be used for input_file selection 1- the size of the array input_files
    //input_files_size is the size of the array (have to use division of sizeof's to compute
    //  as the data structure array, has no .size() attribute
    int UserInput, input_files_size = sizeof(input_files)/sizeof(input_files[0]);
    //Makes sure the User's input is valid in the range of items
    do{
        cout << "What number file would you like to use as your Linked List file?" << endl;
        for(int i = 0; i < input_files_size; ++i){
            cout << i + 1 << ". " << input_files[i] << endl;
        }
        cout << "> ";
        cin  >> UserInput;
    } while (UserInput < 1 || UserInput > input_files_size);

// Declaration of two Linked Lists, one front-added "stack" and one back-added "queue"
    Stack StackLL;
    Queue QueueLL; 
    ifstream inFile(input_files[UserInput-1]);
    string textInput;

    while(!inFile.eof()){
        getline(inFile, textInput);
//        cout << textInput << " Added to Lists" << endl;
        StackLL.Push(textInput);
        QueueLL.Enqueue(textInput);
    };

    cout << StackLL.ToList() << endl << QueueLL.ToList();
    cout << "Code Compiled \"Successfully\"" << endl;
    cout << "Type something and enter to close the application:";
    cin >> textInput;

    return 0;
}