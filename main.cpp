#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;

class Shopping
{
public:
    // variables to store details for store

    int productCode;
    string email;
    string product;
    string password;
    float price;
    float discount;

    //main menu function of the store

    void menu()
    {
        int choice;

       cout << "\t\t\t\t\t PETMART "<<endl<<endl;
       cout << "\t\t\t\t\t Welcome! "<<endl<<endl;

       cout << "\t\t\t\t\t select an option "<<endl<<endl;
       cout << "\t\t\t\t\t 1, Administrator "<<endl;
       cout << "\t\t\t\t\t 2, Buyer "<<endl;
       cout << "\t\t\t\t\t 3, Exit "<<endl;
       cin>>choice;


       // email and password validation
       if(choice == 1)
       {
           system("cls");
          cout << "\t\t\t\t\t Please Login "<<endl<<endl;
          cout << "\t\t\t\t\t Email: ";
          cin>>email;
          cout<<endl;
          cout << "\t\t\t\t\t Password: ";
          cin>>password;

          if( email == "swae123@gmail.com" && password == "swae1234")
          {
              // redirection to admin interface
              admin();
          }
          else
          {
              cout << "\t\t\t\t\t Invalid inputs "<<endl;
              Sleep(2000);
              system("cls");
              menu();
          }

       }
       else if(choice == 2)
       {
           Display();
           Reciept();
       }
       else
       {
           exit(0);
       }


    }

    void admin()
    {
        int option;

        cout << "\t\t\t\t\t Welcome Mr. Swae "<<endl<<endl;

        cout << "\t\t\t\t\t Please select an option"<<endl<<endl;

        cout << "\t\t\t\t\t 1, Add product "<<endl;
        cout << "\t\t\t\t\t 2, Update product"<<endl;
        cout << "\t\t\t\t\t 3, Delete a product"<<endl;
        cout << "\t\t\t\t\t 4, Exit "<<endl;
        cin>>option;

        if(option == 1)
        {
            Addfunc();
        }
        else if (option == 2)
        {
            Updatefunc();
        }
        else if(option == 3)
        {
            Deletefunc();
        }
        else if(option == 4)
        {
            menu();
        }


    }


    void Addfunc()
    {
        fstream data;

        int c;
        int token = 0;
        float p;
        float d;
        string n;

        cout << "\t\t\t\t\t Add a new product "<<endl<<endl;

        cout << "\t\t\t\t\t Enter product code "<<endl;
        cin>>productCode;

        cout << "\t\t\t\t\t Enter product name "<<endl;
        cin >>product;

        cout << "\t\t\t\t\t Enter price "<<endl;
        cin>>price;

        cout << "\t\t\t\t\t Enter discount "<<endl;
        cin>>discount;


        data.open("database.txt", ios::in);


        if(!data)
        {
            data.open("database.txt", ios::app|ios::out);
            data<< " "<<productCode<< " "<< product<< " "<< price << " "<<discount<<endl;
            data.close();
        }
        else{
            data>>c>>n>>p>>d;


            while(!data.eof())
            {
                if(c == productCode)
                {
                    token++;
                }
                data>>c>>n>>p>>d;
            }
            data.close();
        }

        if(token == 1)
        {
            cout << "\t\t\t\t\t Product code already exist"<<endl;
            admin();
        }
        else{

            data.open("database.txt", ios::app|ios::out);
            data<< " "<<productCode<< " "<< product<< " "<< price << " "<<discount<<endl;
            data.close();

        }
        cout << "\t\t\t\t\t Product added successfully"<<endl;

    }

    void Updatefunc()
    {
        fstream data, data1;

        int pcode;
        int token = 0;
        string n;
        int c;
        float p;
        float d;

        cout << "\t\t\t\t\t Update records"<<endl;

        cout << "\t\t\t\t\t Enter product code";
        cin>>pcode;

        cout << endl;

        data.open("database.txt", ios::in);

        if(!data)
        {
            cout<< "\t\t\t\t\t error fetching data"<<endl;
        }
        else
        {
            data1.open("database.txt", ios::app|ios::out);

            data>>productCode>>product>>price>>discount;
            while(!data.eof())
            {
                if(pcode == productCode)
                {
                    cout << "\t\t\t\t\t Product new code";
                    cin>>c;
                    cout << endl;

                    cout << "\t\t\t\t\t Product name";
                    cin>>n;
                    cout<<endl;

                    cout << "\t\t\t\t\t Product price";
                    cin>>p;
                    cout <<endl;

                    cout << "\t\t\t\t\t Discount";
                    cin>>d;
                    cout<<endl;
                    token++;


                }
                else{
                        data<< " "<<productCode<< " "<< product<< " "<< price << " "<<discount<<endl;

                }
                 data>>productCode>>product>>price>>discount;

            }
            data.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt", "database.txt");

            if(token == 0)
            {
                cout <<"\t\t\t\t\t Records not found sorry"<<endl;
            }
        }

    }

    void Deletefunc()
    {
        fstream data,data1;

        int pcode;
        int token = 0;
        cout << "\t\t\t\t\t Delete product"<<endl;
        cout << "\t\t\t\t\t Enter product code";
        cin>>pcode;

        data.open("database.txt", ios::in);
        if(!data)
        {
             cout << "\t\t\t\t\t Data not exist sorry "<<endl;
        }
        else
            {
                data1.open("database1.txt", ios::app|ios::out);
                data>>productCode>>product>>price>>discount;

                while(!data.eof())
                {
                    if(productCode == pcode)
                    {
                        cout << "\t\t\t\t\t Product deleted"<<endl;
                        token++;
                    }
                    else{
                        data<< " "<<productCode<< " "<< product<< " "<< price << " "<<discount<<endl;
                    }
                    data>>productCode>>product>>price>>discount;
                }
            }
            data.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt", "database.txt");
            if(token == 0)
            {
                cout << "\t\t\t\t Record not found"<<endl;
            }

    }

    void Exitfunc()
    {
        menu();
    }

    void Display()
    {
        fstream data;

        data.open("database.txt", ios::in);

        cout << "\t\t\t Product no  \t Product   \t price"<<endl;
        data>>productCode>>product>>price>>discount;

        while(!data.eof())
        {
            cout << productCode<<"\t\t"<<product<< "\t\t"<<price<< "\t\t"<<discount<<endl;
        }
    }


    void Reciept()
    {
        fstream data;
        int arrc[100];
        int arrq[100];
        string choice;
        int c = 0;
        float amount=0;
        float dis = 0;
        float total = 0;

        cout <<"\t\t\t\t\t Receipts "<<endl;
        data.open("database.txt", ios::in);
        if(!data)
        {
            cout << "empty database"<<endl;
        }
        else{
                m:
            data.close();
            Display();

            cout << "\t\t\t\t\t Please place your order"<<endl;

            do
            {
                cout << "\t\t\t\t\t Enter product code";
                cin>>arrc[c];
                cout << "\t\t\t\t\t Enter product quantity";
                cin>>arrq[c];
                for(int i =0; i<c; i++)
                {
                    if(arrc[c] == arrc[i])
                    {
                        cout << "\t\t\t\t\t Duplicate code please try again"<<endl;
                        goto m;
                    }
                }
                c++;
                cout << "Do you wanna buy another product y for yes n for no";
                cin>>choice;
            }while(choice == "y");

            cout << "\n\n\n\\t\t\t________________________RECIEPTS_________________"<<endl;
            cout << "\n\t Product code \t product name \t price \t quantity \t amount \t discount amount "<<endl;

            for(int i = 0; i<c; i++)
            {
                data.open("database.txt", ios::in);
                data>>productCode>>product>>price>>discount;
                while(!data.eof())
                {
                    amount = price*arrq[i];
                    discount = amount-(amount*discount/100);
                    total = total+discount;
                    cout << "\n "<<productCode<<"\t"<<product<< "\t"<<arrq[i]<< "\t"<<price<<"\t\t"<<amount<<"\t\t"<<discount;

                }
                data>>productCode>>product>>price>>discount;
            }
            data.close();
        }
        cout<<endl;
        cout << "\t\t\t Total Amount :"<<total<<endl;
    }



};



int main()
{
    Shopping obj;

    obj.menu();



    return 0;
}
