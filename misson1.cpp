#include <iostream>
#include <string.h>
using namespace std;

class commercail_licenss //الكلاس الاساسي
{
    private:
    string id;
    string name;
    short int address;
    short int business_type;
    string date;
    string exoeration_date;

 public:
    void read_licenss(commercail_licenss l1[],int n){         //دالة القرأة
    for (int i=0; i<n; i++)
    {
        cin.ignore();
        
    cout << "enter the id\n";    
        getline(cin,l1[i].id);
    cout << "enter the name\n";
        getline(cin,l1[i].name);
    cout << "enter the address\n";    
        cin >> l1[i].address;
    cout << "enter the business type\n";    
        cin >> l1[i].business_type;
        
        cin.ignore();
        
    cout << "enter the date\n";    
        getline(cin,l1[i].date);
    cout << "enter the exoeration date\n";    
        getline(cin,l1[i].exoeration_date);


      }
    }

        void display_licenss(commercail_licenss l1[],int n){     //دالة الطباعة
    for (int i=0; i<n; i++)
    {

         cout << endl << l1[i].id <<endl;
         cout << l1[i].name << endl;
         cout << l1[i].address << endl;
         cout << l1[i].business_type<<endl;
         cout << l1[i].date << endl;
         cout << l1[i].exoeration_date << endl;
      }
    }

};
int main()
{
    int n;
    do{
    cout << "enter the number of commercial"<<endl;
    cin>>n;
    }while(n<0);

    commercail_licenss l1[n];              //مصفوفة من الكلاس
    commercail_licenss get_func;

    get_func.read_licenss(l1,n);        // استدعاء الدوال من الكلاس 
    get_func.display_licenss(l1,n);

    return 0;
}
