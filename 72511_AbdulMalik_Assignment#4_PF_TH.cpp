#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main() {
	string sname="ABDUL MALIK";
	string name=sname.substr(0, 11);
	cout<<"NAME = "<<name<<endl; 
    // 1. substr() = EXTRACT SUBSTRING FROM STRING <..>  
    string s1="ABDUL MALIK";
    string sub=s1.substr(0, 5);
    cout<<"1. substr : "<<sub<<endl;
    // 2. strcat() = CONCATENATE TWO C-STYLE STRINGS <..>
    char str1[7] = "ABDUL ";
    char str2[] = "MALIK";
    strcat(str1, str2);
    cout<<"2. strcat : "<<str1<<endl;
    // 3. strcmp() COMPARE TWO C-STYLE STRINGS <..>           
    char word1[]="ABDUL";
    char word2[]="MALIK";
    int result=strcmp(word1, word2);
    cout<<"3. strcmp : "<<result;
    if(result < 0)
        cout<<") ABDUL COMES BEFORE MALIK"<<endl;
    else if(result > 0)
        cout<<"ABDUL COMES AFTER BANANA"<<endl;
    else
        cout<<"BOTH ARE EQUAL"<<endl;
    // 4. strcpy() = COPY ONE STRING TO ANOTHER <..>   
    char source[]="ABDUL MALIK";
    char destination[50];
    strcpy(destination, source);
    cout<<"4. strcpy: "<<destination<<endl;
    // 5. strlen() = GET LENGTH OF STRING <..>           
    char text[]="ABDUL MALIK";
    int length=strlen(text);
    cout<<"5. strlen: "<<length<<" characters"<<endl;
    // 6. strncat() = CONCATENATE FIRST N CHARACTERS <..>  
    char dest[50]="Hello ";
    char src[]="World!";
    strncat(dest, src, 5);
    cout<<"6. strncat : "<<dest<<endl;
    return 0;
}
