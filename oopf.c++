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
            cout << "enter the business type name :" << i + 1 << endl;
            getline(cin, t[i].name);
            cout << "enter the number for represent this business type  :" << i + 1 << endl;
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
class Address
{
public:
    string street;
    short int type;

    void read_business_address(Address a1[], int k) // دالة قراءة نوع النشاط التجاري
    {

        for (int i = 0; i < k; i++)
        {
            cin.ignore();
            cout << "enter the business address name :" << i + 1 << endl;
            getline(cin, a1[i].street);
            cout << "enter the number for represent this business address  :" << i + 1 << endl;
            cin >> a1[i].type;
        }
    };
    string get_business_addres_name(short int type, Address a1[], int k) // دالة بحث عن نوع النشاط التجاري
    {
        for (int i = 0; i < k; i++)
        {
            if (a1[i].type == type)
            {
                return a1[i].street;
            }
        }
        return "Unknown";
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
            cout << "enter the address\n";
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

    void display_licenss(business_licenss l1[], int n, bussiness_type b1[], int m, Address a1[], int k)
    {
        bussiness_type bt1;
        Address bt2;
        // دالة الطباعة
        for (int i = 0; i < n; i++)
        {

            cout << "Business License Details:" << endl;
            cout << "ID: " << l1[i].id << endl;
            cout << "Name: " << l1[i].name << endl;
            cout << "Address: " << bt2.get_business_addres_name(l1->address, a1, k) << endl;
            cout << "Business Type: ";
            cout << bt1.get_business_type_name(l1->business_type, b1, m) << endl;
            cout << "Date: " << l1[i].date << endl;
            cout << "Expiration Date: " << l1[i].exoeration_date << endl;
        }
    };
};

int main()
{
    int n, m, k;
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

    do
    {
        cout << "Enter the number of business Address you need in this system" << endl;
        cin >> k;
    } while (k < 0);

    business_licenss l1[n]; // مصفوفة من الكلاس
    business_licenss get_func;

    Address a1[k];
    Address get_func2;
    get_func2.read_business_address(a1, k);
    bussiness_type b1[m]; // مصفوفة من كلاس نوع النشاط التجاري
    bussiness_type get_func1;
    get_func1.read_business_type(b1, m); // استدعاء دالة قراءة نوع النشاط التجاري

    int choice;
    do
    {

        cout << "enter number (1) for enter the data\t enter number (2) for display the data" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            get_func.read_licenss(l1, n); // استدعاء الدوال من الكلاس
            break;
        case 2:
            get_func.display_licenss(l1, n, b1, m, a1, k);
            break;
        };
        cin.ignore();
    } while (choice < 2);

    return 0;
}