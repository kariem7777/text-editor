#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


string name ,line ,word,newtext;
vector <string> words;
vector<string> text;
int counter, choice;
fstream file ,nwfile;
char linec[300];

int menu();

void mergeFile();
void countLines();
void countCharacters();
void countWords();
void searchWord();

void AddText();
void DisplayContent();
void Empty();
void Encrypt();
void Decrypt();

void lowerCase(vector<string>&text);
void upperCase(vector<string>&text);

int main() {
    cout<<"enter the name of the file: ";
    cin>>name;
    name +=".txt";
    file.open(name,ios::in);
    if(file.fail()){
        file.open(name,ios::app);
        cout<<"\nthis is a new file, i created it for you"<<endl;
        file.close();
    }else{
        cout<<"\nthis file exists."<<endl;
        file.close();
    }
    menu();
    
    return 0;
}

int menu(){
    
    cout << "\n1=> Add Text\n2=> Display the content\n3=> Empty the content\n4=> Encrypt the content\n";
    cout << "5=> Decrypt the content\n6=> merge another file\n7=> Count the number of words\n";
    cout << "8=> Count the number of characters\n9=> Count the number of lines\n10=> Search for a word\n";
    cout << "11=> Count the number of times a word exists\n12=> Turn the file content to upper case\n";
    cout << "13=> Turn the file content to lower case\n14=> turn first char of each word to capital\n15=> save\n16=> Exit";
    cout << "\nplease choose one of these options: ";
    cin >> choice;
    
    if (choice == 1)
        AddText();
    else if (choice == 2)
        DisplayContent();
    else if (choice == 3)
        Empty();
    else if (choice == 4)
        Encrypt();
    else if (choice == 5)
        Decrypt();
    else if (choice == 6)
        mergeFile();
    else if (choice == 7)
        countWords();
    else if (choice == 8)
        countCharacters();
    else if (choice == 9)
        countLines();
    else if (choice == 10)
       searchWord();
    //else if (choice == 11)
        //countNOTW(text);
    else if (choice == 12)
        upperCase(text);
    else if (choice == 13)
        lowerCase(text);
    //else if (choice == 14)
        //lowerCased(text);
    //else if (choice == 15)

    return choice;
}

void mergeFile(){
    cout<<"enter the name of the another file: ";
    name="";
    cin>>name;
    name+=".txt";
    nwfile.open(name,ios::in);
    if(nwfile.fail()){
        cout<<"\ninvalid file name"<<endl;
    }else{
        while (getline(nwfile,line)){
            file<<" ";
            file<<line;
        }
        file.close();
        nwfile.close();
    }}

void countLines(){
    file.open(name,ios::in);
    while (!file.eof()){
        counter +=1;
    }
    file.close();
    cout<<counter;
}

void countCharacters(){
    file.open(name,ios::in);
    while (getline(file,line)){
        for (char i: line)++counter;
    }
    file.close();
    cout<<counter;
}
void countWords(){
    file.open(name,ios::in);
    while (getline(file,line)){
        counter +=1;
        for(int i=0; i<line.length();++i){
            if (i !=0 && int(line[i]) == 32 && int(line[i-1] !=32)) {
                counter +=1;
            }}}
    file.close();
    cout<<counter;
}

void searchWord(){
    string state="";
    file.open(name,ios::in);
    while (getline(file , line)){
        transform(line.begin(),line.end(),line.begin(),::tolower);
        for(int i=0; i<line.length();++i){
            if ( int(line[i]) != 32){
                word +=line[i];
            }else if (i!=0 && int(line[i]) == 32 && int(line[i-1] !=32)){
                words.push_back(word);
                word="";
            }}
        words.push_back(word);
        word="";
    }
    cout<<"enter the word: ";
    cin.clear();
    cin.sync();
    getline(cin,word);
    transform(word.begin(),word.end(),word.begin(), ::tolower);
    for(auto i:words){
        if(i==word)
            state="found";
    }
    if(state=="found")
        cout<<"word was found in the file";
    else
        cout<<"word was not found in the file";
}

void DisplayContent(){
    file.open(name,ios::in);
    while (!file.eof()){
        file.getline(linec, 300, '\n');
        text.push_back(string(linec));
    }
    for (string linec: text){
        cout << linec << endl;
    }
    file.close();
}

void Empty(){
    file.open(name,ios::out);
    file << "";
    file.close();
}

void AddText(){}

void Encrypt(){}

void Decrypt(){}

void lowerCase(vector<string>&text){}


void upperCase(vector<string>&text){}


