#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


string name ,line ,word,newtext;
vector <string> words,content;
vector<string> text;
int choice;
fstream file ,nwfile;
char linec[300],pp;

bool menu();

void read_content();
void save();

//kariem gamal functios
void mergeFile();
void count_lines();
void countCharacters();
void countWords();
void searchWord();


void AddText();
void DisplayContent();
void Empty();
void Encrypt(vector<string>&content);
void Decrypt();
//Aya MOhamed functios
void lowercase(vector<string>&content);
void uppercase(vector<string>&content);
void countWord();
void repetedwords();
void firstchar (vector<string>&content);

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
    read_content();
    while(menu()){
        menu();
    }


}

bool menu(){
    cout<<"\n-------------------------------------------------------------"<<endl;
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
        Encrypt(content);
    else if (choice == 5)
        Decrypt();
    else if (choice == 6)
        mergeFile();
    else if (choice == 7)
        countWords();
    else if (choice == 8)
        countCharacters();
    else if (choice == 9)
        count_lines();
    else if (choice == 10)
       searchWord();
    else if (choice == 11)
        repetedwords();
    else if (choice == 12)
        uppercase(content);
    else if (choice == 13)
        lowercase(content);
    else if (choice == 14)
        firstchar(content);
    else if (choice == 15){
        save();
    }
    else if (choice ==16){
        return false;
    }

    return true;
}

void read_content(){
    //to read the content of the file and put it in a vector
    file.open(name,ios::in);
    while(getline(file,line)){
        content.push_back(line);
    }
    for(string i:content){
        cout<<i<<endl;
    }
    file.close();
};

void mergeFile(){
    string mergedfile;
    cout<<"enter the name of the another file: ";
    cin.clear();
    cin.sync();
    getline(cin,mergedfile);
    mergedfile+=".txt";
    //open the file to merge it with the original
    nwfile.open(mergedfile,ios::in);
    if(nwfile.fail()){
        cout<<"\ninvalid file name"<<endl;
    }else{
        while (getline(nwfile,line)){

            content.push_back(line);
        }
        nwfile.close();
    }
    for(string i:content){
        cout<<i<<endl;
    }
}

void count_lines(){
    int counter=0;
    file.open(name,ios::in);
    while (getline(file,line)){

        ++counter;

    }
    file.close();
    cout<<"number of lines is: "<<counter;
}

void countCharacters(){
    int counter=0;
    file.open(name,ios::in);
    while (getline(file,line)){
        for (char i: line){
            ++counter;

        }
    }
    file.close();
    cout<<"number of characters in the original file is: "<<counter;
}
void countWords(){
    int counter=0;
    file.open(name,ios::in);
    while (getline(file,line)){
        counter +=1;
        for(int i=0; i<line.length();++i){
                //to recognize a word if a space is found between letters
            if (i !=0 && int(line[i]) == 32 && int(line[i-1] !=32)) {
                counter +=1;
            }}}
    file.close();
    cout<<"number of words in the original file is: "<<counter;
}

void searchWord(){
    string state="";
    file.open(name,ios::in);
    //put the words in a vector called words
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
            //compare the word with the words in the vector
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
        cout<<linec<<endl;
    }
    file.close();
}

void Empty(){
    content.clear();
    for(string i:content){
        cout<<i<<endl;
    }

    //file.open(name,ios::out);
    //file << "";
    //file.close();
}

void AddText(){
    cout << "\nplease enter a text: ";
    cin.clear();
    cin.sync();
    getline(cin,newtext);
    content[content.size()-1] +=" ";
    content[content.size()-1] +=newtext;
    for(string i:content){
        cout<<i<<endl ;
    }
}

void Encrypt(vector<string>&content){
    string text;
    for(int i=0; i<content.size();++i){
        text="";
        for (int j=0 ; j <content[i].size();  j++){
           content[i][j]=char( (int)content[i][j] + 1);
        }
    }
    for(string i:content){
        cout<<i<<endl;
    }
}

void Decrypt(){
string text;
    for(int i=0; i<content.size();++i){
        text="";
        for (int j=0 ; j <content[i].size();  j++){
           content[i][j]=char( (int)content[i][j] - 1);
        }
    }
    for(string i:content){
        cout<<i<<endl;
    }
}

void uppercase(vector<string>&content){
    for(int i =0 ; i<content.size();++i){
        for(int j= 0 ;j<content[i].size();++j){
            //for each char in each line we will use to upper function to make it upper case
            content[i][j]=toupper(content[i][j]);
        }
    }
    for(string i:content){
        cout<<i<<endl;
    }
}


void lowercase(vector<string>&content){
    for(int i =0 ; i<content.size();++i){
        for(int j= 0 ;j<content[i].size();++j){
            //for each char in each line we will use to lower function to make it lower case
            content[i][j]=tolower(content[i][j]);
        }
    }
    for(string i:content){
        cout<<i<<endl;
    }
}

void repetedwords(){
    string userword;
    int word_counter=0;
    for(string line:content){
        // to make all content lower to get all probabilities
        transform(line.begin(),line.end(),line.begin(),::tolower);
        for(int i=0; i<line.length();++i){
            // check if it is space or not
            if ( int(line[i]) != 32){
                word +=line[i];
            }else if (i!=0 && int(line[i]) == 32 && int(line[i-1] !=32)){
                words.push_back(word);
                word="";
            }
        }
        words.push_back(word);
        word="";
    }
    cout<<"enter the word to count the repeations: ";
    cin.clear();
    cin.sync();
    getline(cin,userword);
    for(string i:words){
        if(i==userword){
            word_counter+=1;
        }
    }
    cout<<"the word repeted "<<word_counter<<" times";
    file.close();
}

void save(){
    char choice;
    string new_file;
    cout<<"do you want to save it in same file or another file ( (s)ame or (a)nother ): ";
    cin>>choice;
    choice=tolower(choice);
    if (choice=='s'){
        file.open(name,ios::out);
        for(string i:content){
        file<<i<<endl;
        }
        file.close();
    }else if(choice=='a'){
        cout<<"enter the name of the file: ";
        cin.clear();
        cin.sync();
        getline(cin,new_file);
        new_file+=".txt";
        file.open(new_file,ios::app);
        for(string i:content){
        file<<i<<endl;
        }
        file.close();
    }
}

void firstchar (vector<string>&content){
    string word ;
    char answer;
    int x=0;
    for(int i = 0 ;i<content.size() ; i++){
            x=0;
        for(int j = 0 ; j <content[i].size();j++){
                if(x==0){
                    content[i][j]=toupper(content[i][j]);
                    ++x;
                }if (content[i][j]==' '){
                    x=0;
                }
        }
        for(string i:content){
        cout<<i<<endl;
        }
    }
}
