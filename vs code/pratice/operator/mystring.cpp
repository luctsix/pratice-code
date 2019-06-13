#include <iostream>
#include <string.h>

using namespace std;

class Mystring{
    friend ostream& operator<<(ostream &cout, Mystring &p);
    friend istream& operator>>(istream &cin, Mystring &p);
    public:
        Mystring();
        Mystring(const char *str);
        Mystring(const Mystring &p);
        ~Mystring();

        Mystring& operator+(const Mystring &p)const;
        Mystring& operator=(const Mystring &p);
        bool operator==(const Mystring &p);
        bool operator>(const Mystring &p);
        bool operator<(const Mystring &p);

        bool IsEmpty();

        void ToUpper();
        void ToDowner();

        char& operator[](int val);

        void operator()(){
            cout<<this->str<<endl;
        }
    private:
        char *str;
        int   size;
};
Mystring::Mystring(){
    str  = NULL;
    size = 0;
}
Mystring::Mystring(const char *str){
    this->str = new char[strlen(str)+1];
    this->size = strlen(str)+1;
    strcpy(this->str, str);
}
Mystring::Mystring(const Mystring &p){
    this->str = new char[p.size];
    this->size = p.size;
    strcpy(this->str, p.str);
}
Mystring& Mystring::operator+(const Mystring &p)const{
    Mystring *tmp= new Mystring;
    tmp->str = new char[this->size+p.size-1];
    memset(tmp->str, 0, tmp->size);
    strcpy(tmp->str, this->str);
    strcat(tmp->str, p.str);
    return *tmp;
}
Mystring& Mystring::operator=(const Mystring &p){
    if(this->str != NULL){
        delete []this->str;
        this->str = NULL;
        this->size = 0;
    }
    this->str = new char[p.size];
    this->size = p.size;
    strcpy(this->str, p.str);
    return *this;
}
bool Mystring::operator==(const Mystring &p){
    if(strcmp(this->str, p.str)==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool  Mystring::operator>(const Mystring &p){
    if(strcmp(this->str, p.str)>0)
    {
        return true;
    }
    else
    {
        return false;
    }  
}
bool  Mystring::operator<(const Mystring &p){
    if(strcmp(this->str, p.str)<0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool  Mystring::IsEmpty(){
    if(this->str==NULL && this->size==0)    {
        return true;
    }
    else{
        return false;
    }
}

void Mystring::ToUpper(){
    for(int i=0; i<this->size; i++){
        if(this->str[i]>='a' && this->str[i] <='z')
        {
            this->str[i] -= 32;
        }
    }
}
void Mystring::ToDowner(){
    for(int i=0; i<this->size; i++){
        if(this->str[i]>='A' && this->str[i] <='Z')
        {
            this->str[i] += 32;
        }
    }
}

char& Mystring::operator[](int val){
    return this->str[val];
}
Mystring::~Mystring(){
    if(this->str!=NULL)
    {
        delete []this->str;
        this->str = NULL;
        this->size = 0;
    }
}


ostream& operator<<(ostream &cout, Mystring &p){
    // for(int i=0; i<p.size; i++){
    //     cout<<p.str[i];
    // }
    cout<<p.str;
    return cout;
}
istream& operator>>(istream &cin, Mystring &p){
    
    //printf("\n = %s", tmp);
    if(p.str != NULL){
        delete []p.str;
        p.str = NULL;
        p.size = 0;
    }
    p.str = new char[256];
    cin>>p.str;
    return cin;
}

int main(){
    // Mystring str("hello");
    // Mystring str2 = "world";
    // str2 = str;
    // Mystring str3 = str + str2;
    //cout<<"input: ";
    //cin>>str;
    //cout<<str[2]<<endl;
    //cout<<str<<endl;
    // str();
    // str2();
    // str3();

    Mystring str4;
    cin>>str4;
    str4();
    str4.ToUpper();
    str4();
    str4.ToDowner();
    cout<<str4<<endl;
    return 0;
}