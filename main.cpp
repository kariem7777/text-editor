#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


string name ,line ,word;
vector <string> words;
int counter;
fstream file ,nwfile;

void mergeFile();
void countLines();
void countCharacters();
void countWords();
void searchWord();
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
    file.open(name,ios::in);
    if(getline(file,line)){
        cout<<line;
    }else
        cout<<"empty";
    file.close();
    return 0;
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
    }
}

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
            }
        }
    }
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
            }
        }
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
