#include <iostream>
#include<fstream>
using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float discount;
    string name;
public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit ();
    void remov();
    void List ();
    void receipt ();

};
void shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;


    cout<<"\t\t\t___________________________\n";
    cout<<"\t\t\t                           \n";
    cout<<"\t\t\t   supermarket main menu   \n";
    cout<<"\t\t\t                           \n";
    cout<<"\t\t\t___________________________\n";
    cout<<"\t\t\t                           \n";
    cout<<"\t\t\t|  1) adminstrator        |\n";
    cout<<"\t\t\t|                         |\n";
    cout<<"\t\t\t|  2) buyer               |\n";
    cout<<"\t\t\t|                         |\n";
    cout<<"\t\t\t|  3) exit                |\n";
    cout<<"\t\t\t|                         |\n";
    cout<<"\n\t\t please select!";
    cin>>choice;
    switch (choice)
    {

    case 1 :
        cout <<"\t\t\t  please login   \n";
        cout <<"\t\t\t enter email     \n";
        cin>>email;
        cout<<"\t\t\t   enter password \n";
        cin>>password;
        if(email=="mohamed@gmail.com"&& password=="12345678")
        {
           administrator();
        }
        else
        {
            cout<<" invalid email/password";
        }
        break; // why!!
    case 2:
        {
            buyer();
        }
    case 3 :
        {
           break; // dont understand
        }
    default  :
        {
            cout<<"please enter availble number ";
        }

    }
    goto m;
}
void shopping::administrator()
{
    m :
    int choice;
    cout<<"\n\n\n\t\t administrator menu ";
    cout<<"\n\t\t\t|____ 1) add a product     |";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|____ 2) modify a product  |";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|____ 1) delete a product  |";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|____ 1) back to main menu |";
    cout<<"\n\n\t please enter your choice ";
    cin>>choice;
    switch (choice)
    {
    case 1 :
        add();
        break;
    case 2 :
        edit();
        break;
    case 3 :
        remov();
        break;
    case 4 :
        menu();
        break;
    default :
        cout<< " invalid";

    }
    goto m;
}
void shopping::buyer()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t buyer menu ";
    cout<<"\n\t\t\t|____ 1) buy a product     |";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|____ 2) go back           |";
    cout<<"\n\n\t please enter your choice ";
    cin>>choice;
    switch(choice)
     {
    case 1 :
        receipt();
        break;
    case 2 :
        menu();
        break;
    default :
        cout<<"invalid";
     }
     goto m;
}
void shopping::add()
{
    m:

    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n ;

    cout<<"\n\n\t\t  add new product";
    cout<<"\n\n\t pcode of the product";
    cin>>pcode;
    cout<<"\n\n\t name of the product";
    cin>>name;
    cout<<"\n\n\t price of the product ";
    cin>>price;
    cout<<"\n\n\t discount on product ";
    cin>>discount;

    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<name<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;
        while (!data.eof())
            {
        if(pcode==c)
        {
            token++;
        }
         data>>c>>n>>p>>d;
    }

    if (token==1)
    {
        cout <<"product already exist";
        goto m;
    }
    else
    {
         data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<name<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
}
cout<<"\n\n\t\t record inserted";

}
void shopping::edit()
{

    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;
    cout<<"\n\t\t\t modify the record";
    cout<<"\n\t\t\t product code :";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n file doesn't exist";

    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>name>>price>>discount;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t product new code:";
                cin>>c;
                cout<<"\n\t\t name of product :";
                cin>>n;
                cout<<"\n\t\t price:";
                cin>>p;
                cout<<"\n\t\t discount:";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t record edited";
                token++;
            }
            else
            {
                 data1<<" "<<pcode<<" "<<name<<" "<<price<<" "<<discount<<"\n";
            }
            data>>pcode>>name>>price>>discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename ("dtabase1,txt", "database.txt");
        if (token==0)
        {
            cout<<"not found";
        }
    }
}
    void shopping::remov()
    {
        fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\t\t\t delete product";
    cout<<"\n\t\t\t product code :";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n file doesn't exist";

    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>name>>price>>discount;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"product deleted succefully ";
                token++;
            }
            else
            {
                 data1<<" "<<pcode<<" "<<name<<" "<<price<<" "<<discount<<"\n";
            }
            data>>pcode>>name>>price>>discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename ("dtabase1,txt", "database.txt");
        if (token==0)
        {
            cout<<"not found";
        }
    }

}
void shopping::List()
{

    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|_______________________________\n";
    cout<<"pronp\t\tname\t\tprice\n";
    cout<<"\n\n|_______________________________\n";
    data>>pcode>>name>>price;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<name<<"\t\t"<<price<<"\n";
        data>>pcode>>name>>price;
    }
    data.close();
}
void shopping::receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice ;
    int c=0;
    float amount =0;
    float dis =0;
    float total =0;

    cout<<"\n\n\t\t\t\t Receipt ";
     data.open("database.txt",ios::in);
     if (!data)
     {
         cout<<"empty";
     }
     else
    {

        data.close();
        List();
        cout<<"\n_______________________________________\n";
        cout<<"\n                                       \n";
        cout<<"\n    please place your order            \n";
        cout<<"\n                                       \n";
        cout<<"\n_______________________________________\n";
        do
        {
            m:
            cout<<"\n\n enter product code:";
            cin>>arrc[c];
            cout<<"\n\nenter the quantity";
            cin>>arrq[c];
            for(int i =0;i<c;i++)
            {
                if(arrc[c]==arrc[i]){
                    cout<<"item dublicated ";
                goto m;
                }

            }
            c++;
            cout<<"\n\n if you want to buy another product please press y else if no press x";
            cin>>choice;


        }while(choice=='y');
        cout<<"\n\n\t\t\t_________________Receipt__________\n";
        cout<<"\nproduct no\tproduct name\tprodcut qty\tprice\amount\tamount with dis\n";

        for(int i=0;i<c;i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>name>>price>>discount;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount=price*arrq[i];
                    discount=amount-(amount*discount/100);
                    total=total+discount;
                    cout<<"\n"<<pcode<<"\t\t"<<name<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<discount;
                }
                 data>>pcode>>name>>price>>discount;
            }
            data.close();
        }
     cout<<"\n\n_______________________________";
     cout<<"\n Total amount :"<<total;

}
}
int main()
{


    shopping c;
    c.menu();
}
