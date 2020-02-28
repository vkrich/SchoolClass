#include "School.h"

using namespace std;

template <typename T, typename T1>
Sclist<T, T1>::Sclist(){
    size=0; 
    head=nullptr;
}

template <typename T, typename T1>
Sclist<T, T1>::~Sclist(){
    clear();
};

template <typename T, typename T1>
void Sclist<T, T1>::show(){
    Node<T, T1> *current = this->head;
    cout<<"Our list is:"<<endl;
    for(int i=0;i<size;i++){
        cout<<current->stcount<<" and "<<current->spec<<endl;
        current=current->pNext;
    }
}

template <typename T, typename T1>
void Sclist<T, T1>::clear(){
    while(size>0){
        pop_front();
    }
}
template <typename T, typename T1>
void Sclist<T, T1>::removeAt(int index){
    if(index==0){
      pop_front();
    }else{
         Node<T, T1> *previous = head;
         for(int i=0;i<index-1;i++){
             previous=previous->pNext;
         }
         Node<T, T1> *temp=previous->pNext;
         previous->pNext=temp->pNext;
         delete temp;
         size--;
    }
}
template <typename T, typename T1>
void Sclist<T, T1>::insert(T stcount,T1 spec, int index){
 if(index==0){
     push_front(stcount);
 }else{
     Node<T, T1> *previous = head;
     
     for(int i=0;i<index-1;i++){
         previous=previous->pNext;
     }
     
     Node<T, T1> *newst = new Node<T, T1>(stcount,spec,previous->pNext);
     previous->pNext = newst;
     
     size++;
 }
}

template <typename T, typename T1>
void Sclist<T, T1>::pop_back(){
    removeAt(size-1);
}

template <typename T, typename T1>
void Sclist<T, T1>::pop_front(){
    Node<T, T1> *temp=head;
    head=head->pNext;
    delete temp;
    size--;
}

template <typename T, typename T1>
void Sclist<T, T1>::push_front (T stcount, T1 spec){
    head = new Node<T, T1>(stcount, spec, head);
    size++;
}

template <typename T, typename T1>
void Sclist<T, T1>::push_back (T stcount, T1 spec){
    if(head == nullptr){
        head = new Node<T, T1>(stcount, spec);
    }else{
        Node<T, T1> *current = this->head;
        
        while(current->pNext != nullptr){
            current = current->pNext;
        }
        
        current->pNext = new Node<T, T1>(stcount, spec);
        
    }
    size++;
}
template <typename T, typename T1>
T1& Sclist<T, T1>::operator[](const int index){
    int counter=0;
    Node<T, T1> *current = this->head;
    while(current!=nullptr){
        
        if(counter==index){
         return current->spec;
        }
         
        current=current->pNext;
        counter++;
    }
    //если больше - то ошибкаТОДО
}
void School::setSchool(int sc_number, string sc_spec, string sc_dir, string sc_phone, int sc_studCount){
    number=sc_number;
    specialization=sc_spec;
    director=sc_dir;
    phone=sc_phone;
    studentCount=sc_studCount;
}
        
School::School(){
    number=0;
    specialization="";
    director="";
    phone="";
    studentCount=0;
}
        
School::School(int sc_number, string sc_spec, string sc_dir, string sc_phone, int sc_studCount){
    setSchool(sc_number, sc_spec, sc_dir, sc_phone, sc_studCount);
}
        
void School::getSchool(){
    cout<<this->number<<" "<<this->specialization<<" "<<this->director<<" "<<this->phone<<" "<<this->studentCount<<endl;
}
        
int School::getstudentsCount(){
    return studentCount;
}
string School::getspec(){
    
    return specialization;
}
        
School& operator++(School& i, int){
    i.number++;
    return i;
}
        
School& operator--(School& i, int){
    i.number--;
    return i;
}
        
School& operator+=(School& left, const School& right) {
    
    left.studentCount+=right.studentCount;
    return left;
}
        
School& operator-=(School& left, const School& right) {
        
    if(left.studentCount>=right.studentCount){
        left.studentCount-=right.studentCount;
        return left;
    }
    else{
        throw Myexception("Number of students cant be below zero");
    }
}
        
bool operator==(const School& left, const School& right){
    if(left.studentCount==right.studentCount){
        return true;
    }else
        return false;
}
        
bool operator<(const School& left, const School& right){
    if(left.studentCount<right.studentCount){
        return true;
    }else
        return false;
}
        
bool operator>(const School& left, const School& right){
    if(left.studentCount>right.studentCount){
        return true;
    }else
        return false;
}
        
std::ostream& operator<<(ostream& out, School& i){
        out<<"School number: "<<i.number<<" "<<i.director<<" "<<i.specialization<<" "<<i.phone<<" "<<"there are "<<i.studentCount<<" students";
    return out;
}
std::ifstream& operator>>(ifstream& in, School& temp){        
        int i=0;
        int n=0;
        string s;
        getline(in,s);
            
        while(s[i]!=char(32)){
            if(s[i]>='0' and s[i]<='9')      
                n = n*10 + s[i] - '0';
            else{
			       throw Myexception("Invalid data for School number in file");
            }
            i++;
        }
            i++;
           
        temp.number = n;
        while(s[i]!=char(32)){
            if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z')){
                temp.specialization+=s[i];
                i++;
            }
            else{
			       throw Myexception("Invalid data for School specialization in file");
            }
        }
            i++;
        while(s[i]!=char(32)){
            if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z')){
                temp.director+=s[i];
                i++;
            }
            else{
			      throw Myexception("Invalid data for School director in file");
            }
        }
            i++;
        while(s[i]!=char(32)){
            if((s[i]>='0' and s[i]<='9') or s[i]=='+'){
                temp.phone+=s[i];
                i++;
            }
            else{
			      throw Myexception("Invalid data for School phone in file");
            }
        }
        i++;
        n=0;
        while(i<=s.length()-1){
                
            if(s[i]>='0' and s[i]<='9'){      
                n = n*10 + s[i] - '0';
                i++;
            }
            else{
			    throw Myexception("Invalid data for number of students in file");
            }
        }
        temp.studentCount = n;
        
    return in;
}
        
void findMinMax(School *p, const int &n){
    School min=*(p);
    School max=*(p);
        for(int i=0;i<n;i++){
            if(min > *(p+i)){
                min=*(p+i);
            }
            if(max < *(p+i)){
                max = *(p+i);
            }
        }
        cout<<"Minimum element is: "<<endl;
        cout<<min;
        cout<<endl;
        cout<<"Maximum element is: "<<endl;
        cout<<max<<endl;
        cout<<"%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
}
        
template <typename T> 
void sortSchools(T *p, const int &n){
        T temp;
        for(int i=1;i<n;i++){     
	       for(int j=i;j>0 && *(p+j-1)>*(p+j);j--){ // пока j>0 и элемент j-1 > j, x-массив int
			 temp=*(p+j);
			 *(p+j)=*(p+j-1);
			 *(p+j-1)=temp;
		   }
        }
    }
        
void School::outinTable(fstream& file1){
    file1<<"\t"<<number<<"\t\t\t"<<specialization<<"\t \t \t\t"<<director<<"\t\t"<<phone<<"\t\t"<<studentCount<<"\n";
}
School* addelem(School *mass, School elem, int n){
    School *temp = new School[n+1];
    temp[n] = elem;
    for (int i = 0; i < n; i++)
        temp[i] = mass[i]; // копируем данные со старого массив
        
    delete [] mass; // удаляем старый массив
    return temp;
}

std::ostream& operator<<(ostream& out, Mystring& i){
      out<<i.getStr();
      return out;
}
//bool cmpSchools (const School & a, const School & b) { return a.getstudentsCount() > b.getstudentsCount(); }        
int main()
{
    School a;
    School b(239,"Math","RozovVA", "9119115020",150);
    a=b;
    School c(a);
    b++;
    c--;
    b+=a;
    a.getSchool();
    b.getSchool();
    c.getSchool();
    
    cout<<"Файловый ВВОД"<<endl;
    int n=0;
    //School mass[n];
    School *mass = new School[n];
    
    //ввод из файла    
    ifstream file;
    file.open("input.txt");
    
    if(file.is_open()){
        int j=0;//and j<n 4 static
        while(!file.eof()){
            
            School curSchool;
            file>>curSchool;
            
            mass=addelem(mass,curSchool,n);
            n++;
        }
        
        file.close();
        
        findMinMax(mass, n);
        sortSchools<School>(mass, n);
        
        for (int i=0;i<n;i++){
            cout<<mass[i];
            cout<<endl;
        }
        
    }else{
        cout<<"Не удалось открыть файл";
        return -1;
    }
    
    //Вывод в файл
    fstream file1;    
    file1.open("output.txt", fstream::out);
    
    if(file1.is_open()){
        
       file1<<"  number \t specialization \t director \t\t phone \t \t studentCount \n";
       
       for(int i=0;i<n;i++) 
        mass[i].outinTable(file1);
       
    }else{
        cout<<"Не удалось открыть файл";
        return -1;
    }
    
    cout<<"our vector"<<endl;
    vector <School> vecs;
    vecs.reserve(10); // increase capasity to 10
    ifstream file2;
    file2.open("input.txt");
    
    if(file2.is_open()){
        
        while(!file2.eof()){
            School curSchool;
            file2>>curSchool;
            vecs.push_back(curSchool);
        }
        file2.close();
    }
    
    for(int i=0;i<vecs.size();i++){
        cout<<vecs[i]<<endl;
    }
    
    cout<<"Sorted vector STL"<<endl;
    sort(vecs.begin(), vecs.end());
    
    for(int i=0;i<vecs.size();i++){
        cout<<vecs[i]<<endl;
    }
    
    Sclist<int, string> lst;
    
    for(int i =0;i<vecs.size();i++){
        lst.push_back(vecs[i].getstudentsCount(), vecs[i].getspec());
    }
    
    lst.show();
    /*lst.push_front(3);
    lst.insert(404,3);
    lst.show();
    lst.removeAt(3);
    lst.show();
    lst.removeAt(0);
    lst.show();
    lst.insert(404,3);
    lst.show();
    lst.pop_back();
    lst.show();*/
    
    cout<<"We have "<<lst.getSize()<<" elements in our List"<<endl;    
    
    list<School> schoolList;
    list<School>::iterator it = schoolList.begin();
    
    ifstream inpfile;
    inpfile.open("input.txt");
    
    if(inpfile.is_open()){
        while(!inpfile.eof()){
            School tempt;
            inpfile>>tempt;
            schoolList.push_back(tempt);
            cout<<tempt<<endl;
        }
        inpfile.close();
    }
    cout<<"Our LIST list<School>"<<endl;
    cout<<schoolList.size()<<endl;
    
    for(list<School>::iterator i = schoolList.begin();i!=schoolList.end();i++){
        cout<<*i<<endl;
    }
    schoolList.sort();
    cout<<"Sorted list"<<endl;
    for(list<School>::iterator i = schoolList.begin();        i!=schoolList.end();i++){
        cout<<*i<<endl;
    }    
    
    return 0;
}

