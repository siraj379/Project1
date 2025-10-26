#include <iostream>
#include <string.h>
using namespace std;

class bussiness_type // كلاس نوع النشاط التجاري
{
public:
    string name;
    short int type;
    void read_business_type(bussiness_type t[], int m) // دالة قراءة نوع النشاط التجاري
    {

        for (int i = 0; i < m; i++)
        {
            cin.ignore();
            cout << "enter the business type name :"<<i+1<<endl;
            getline(cin, t[i].name);
            cout << "enter the number for represent this business type  :"<<i+1<<endl;
            cin >> t[i].type;
        }
    };

    string get_business_type_name(short int type, bussiness_type t[], int m) // دالة بحث عن نوع النشاط التجاري
    {
        for (int i = 0; i < m; i++)
        {
            if (t[i].type == type)
            {
                return t[i].name;
            }
        }
        return "Unknown";
    };
};

class Address // كلاس العنوان
{
public:
    string street;
    void read_address(int choice_adders)
    {

        switch (choice_adders)
        {
        case 1:
            street = "Tripoli Street";
            break;
        case 2:
            street = "Benghazi Street";
            break;
        case 3:
            street = "Aladhaeih Street";
            break;
        case 4:
            street = "Other";
            break;
        default:
            street = "Unknown";
            break;
        }
    };
};

class business_licenss // الكلاس الاساسي

{
public:
    string id;
    string name;
    short int address;
    short int business_type;
    string date;
    string exoeration_date;

    void read_licenss(business_licenss l1[], int n)
    { // دالة القرأة
        for (int i = 0; i < n; i++)
        {
            cin.ignore();

            cout << "enter the id\n";
            getline(cin, l1[i].id);
            cout << "enter the name\n";
            getline(cin, l1[i].name);
            cout << "Select Business Adders:" << endl;
            cout << "1. Tripoli Street" << endl;
            cout << "2. Benghazi Street" << endl;
            cout << "3. Aladhaeih Street" << endl;
            cout << "4. Other" << endl;
            cin >> l1[i].address;
            cout << "enter the business type\n";
            cin >> l1[i].business_type;

            cin.ignore();

            cout << "enter the date\n";
            getline(cin, l1[i].date);
            cout << "enter the exoeration date\n";
            getline(cin, l1[i].exoeration_date);
        }
    }

    void display_licenss(business_licenss l1[], int n, bussiness_type b1[], int m)
    { // دالة الطباعة
        for (int i = 0; i < n; i++)
        {
            Address address_obj;
            address_obj.read_address(l1[i].address);
            bussiness_type get_func1;

            cout << "Business License Details:" << endl;
            cout << "ID: " << l1[i].id << endl;
            cout << "Name: " << l1[i].name << endl;
            cout << "Address: " << address_obj.street << endl;
            cout << "Business Type: ";
            cout << get_func1.get_business_type_name(l1->business_type, b1, m) << endl;
            cout << "Date: " << l1[i].date << endl;
            cout << "Expiration Date: " << l1[i].exoeration_date << endl;
        }
    };
};

int main()
{
    int n, m;
    do
    {
        cout << "enter the number of commercial" << endl;
        cin >> n;
    } while (n < 0);

    do
    {
        cout << "Enter the number of business type you need in this system" << endl;
        cin >> m;
    } while (m < 0);

    business_licenss l1[n]; // مصفوفة من الكلاس
    business_licenss get_func;

    bussiness_type b1[m]; // مصفوفة من كلاس نوع النشاط التجاري
    bussiness_type get_func1;
    get_func1.read_business_type(b1, m); // استدعاء دالة قراءة نوع النشاط التجاري

    int choice;
    cout <<"enter number (1) for enter the data\t enter number (2) for display the data"<<endl;
    cin>>choice;
do{
        switch(choice){
            case 1 :
    get_func.read_licenss(l1, n); // استدعاء الدوال من الكلاس
    break;
            case 2 :
    get_func.display_licenss(l1, n, b1, m);
    break;
        };
}while (choice<2);

    return 0;
}
