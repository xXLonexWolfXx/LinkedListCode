#include "LinkedList.cpp"
int main(){
    string input_files[]={"california.txt", "halloween calories.txt",
                    "harry potter..txt", "pokemon.txt", "programming.txt", 
                    "soft drinks.txt", "testFile.txt"};
    //UserInput to be used for input_file selection 1-x where x < input_files.size()
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

    LinkedList StackLL, QueueLL; // Declaration of two Linked Lists, one "stack" and one "queue"
    ifstream inFile(input_files[UserInput-1]);
    string textInput;

    while(!inFile.eof()){
        getline(inFile, textInput);
//        cout << textInput << " Added to Lists" << endl;
        StackLL.AddHead(textInput);
        QueueLL.AddTail(textInput);
    };

    cout << StackLL.ToList() << endl << QueueLL.ToList();
    cout << "Code Compiled \"Successfully\"" << endl << StackLL.About();

    return 0;
}