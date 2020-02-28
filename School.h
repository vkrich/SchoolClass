#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <utility>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>

using namespace std;
class School{
    private:
      int number;
      string specialization;
      string director;
      string phone;
      int studentCount;
      
      friend School& operator++(School& i, int);
      friend School& operator--(School& i, int);
      friend School& operator+=(School& left, const School& right);
      friend School& operator-=(School& left, const School& right);
      friend bool operator==(const School& left, const School& right);
      friend bool operator<(const School& left, const School& right);
      friend bool operator>(const School& left, const School& right);
      friend std::ostream& operator<<(ostream& out, School& i);
      friend std::ifstream& operator>>(ifstream& in, School& temp);
      
    public:
        void setSchool(int, string, string, string, int);
        void getSchool();
        int getstudentsCount();
        string getspec();
        void fillSchool(string s);
        void outinTable(fstream& file1);
        
        School& operator=(const School &objSchool2 ) //перегрузка оператора присваивания
        {
            number=objSchool2.number; 
            specialization=objSchool2.specialization;
            director=objSchool2.director;
            phone=objSchool2.phone;
            studentCount=objSchool2.studentCount;
            return *this;
        }
        
        School();
        School(int, string, string, string, int);
        ~School(){
            //delete [] mass;
        };
        
        School(const School &other){
            this->number=other.number; 
            this->specialization=other.specialization;
            this->director=other.director;
            this->phone=other.phone;
            this->studentCount=other.studentCount;
        }
};

template <typename T, typename T1>
class Node{
        public:
        
        Node *pNext;
        T stcount;
        T1 spec;
        
        Node(T stcount = T(), T1 spec = T1(), Node *pNext = nullptr){
            this->pNext=pNext;
            this->stcount=stcount;
            this->spec=spec;
        }
};

template <typename T, typename T1>
class Sclist{
    private:
        int size;
        Node<T, T1> *head;
    
    public:
        Sclist();
        ~Sclist();
        void push_back (T stcount, T1 spec);
        void push_front (T stcount, T1 spec);
        void insert(T stcount, T1 spec, int index);
        void removeAt(int index);
        void pop_front();
        void pop_back();
        void show();
        void clear();
        int getSize(){return size;};
        T1& operator[](const int index);
};
/*
class Myexception :public exception
{
    public:
    // исп также throw Myexception("bla");
    Myexception(char* msg) : exception(msg)
    {
    }
    
    // исп также throw Myexception("bla", int);
    Myexception(char* msg, int curState) : exception(msg)
    {
        this->curState=curState;
    }
    
    int getcurState (){
        return curState;
    }
    
    private:
    int curState;
};

try{
    
}catch(Myexception &ex){
    cout<<endl<<"Данные в переменной неверные"<<ex.getcurState();
}

*/

class Mystring{
  
  public:
  
  Mystring(){
      str=nullptr;
  }
  
  Mystring(char *str){
    int length = strlen(str); 
    this->str = new char[length+1];//т.к. в конце строки '\0'
    for(int i =0;i<length;i++){
        //*((this->str)+i) = *(str+i);
        this->str[i]=str[i];
    }
    this->str[length]='\0';//term 0 in the end
  }
  
  Mystring (const Mystring& other){
      
        int length = strlen(other.str); 
        this->str = new char[length+1];
        for(int i =0;i<length;i++){
            this->str[i]=other.str[i];
        }
            this->str[length]='\0';
  }
  
  Mystring& operator=(const Mystring& other){
      if(this->str!=nullptr){
          delete [] this->str;
      }else{
          int length = strlen(other.str); 
          this->str = new char[length+1];
          for(int i =0;i<length;i++){
            this->str[i]=other.str[i];
          }
        this->str[length]='\0';
      }
      return *this;
  }
  Mystring operator+(const Mystring& right){
      int rlength = strlen(right.str);
      int llength = strlen(this->str);
      
      Mystring res;
      res.str = new char[rlength + llength+1];
      
      for(int i =0;i<llength;i++){
            res.str[i]=this->str[i];
      }
      
      int j=0;
      for(int i = llength; i < rlength + llength;i++){
            res.str[i]=right.str[j];
            j++;
      }
      
      res.str[rlength + llength]='\0';
      return res;
  }
  
  char* getStr(){return this->str;}
  
  ~Mystring(){
      delete [] this->str;
  };
  
  private:
  char *str;
    
};

class Myexception  :public exception
{
  public:
    Myexception(string error): m_error(error)
    {
    }
    const char* what() const noexcept { return m_error.c_str(); }
  private:
   string m_error;
};
