//20200596 nervana anwer
//20200414 makrina emad
//20200217 sara samouil
#include <iostream>
#include<vector>
#include<iterator>
using namespace std;

class PhoneDirectory
{
private:

        string first_name,last_name;
        int phone_number;

public:

    vector<string>firstname;
    vector<string>lastname;
    vector<int>phonenumber;

    PhoneDirectory()
    {
        first_name= "";
        last_name= "";
        phone_number=0;
    }

    void set_firstname(string name)
    {first_name=name;}
    void set_lastname (string name)
    {last_name=name;}
    void set_phonenumber(int number)
    {phone_number=number;}

    string get_firstname()
    {return first_name;}
    string get_lastname()
    {return last_name;}
    int get_phonenumber ()
    {return phone_number;}


    void Add_Entry()
    { PhoneDirectory *x;
      x= new PhoneDirectory;
      cout<< "Enter the first name \n";
      cin >>x->first_name ;
      cout<< "Enter the last name \n";
      cin>>x->last_name;
      cout<< "Enter the phone number \n";
      cin>>x->phone_number;
      set_firstname(x->first_name);
      firstname.push_back(get_firstname());
      set_lastname(x->last_name);
      lastname.push_back(get_lastname());
      set_phonenumber(x->phone_number);
      phonenumber.push_back(get_phonenumber());

    }

    void Delete_entry()
    {
        if(!firstname.empty())
        {   string name;
            cout<<"enter the first name \n";
            cin>>name;
            for(int i=0;i<firstname.size();i++)
            {
                if (name==firstname[i])
                    {
                       string ftemp=firstname[i];
                       firstname[i]=firstname[firstname.size()-1];
                       firstname[firstname.size()-1]=ftemp;
                       firstname.pop_back();
                       string ltemp=lastname[i];
                       lastname[i]=lastname[lastname.size()-1];
                       lastname[lastname.size()-1]=ltemp;
                       lastname.pop_back();
                       int ptemp=phonenumber[i];
                       phonenumber[i]=phonenumber[phonenumber.size()-1];
                       phonenumber[phonenumber.size()-1]=ptemp;
                       phonenumber.pop_back();
                       cout<< "the entry deleted \n"<<endl;
                    }
                    else
                        cout<< "not found!! \n"<<endl;
            }
        }
        else
            cout<<"The Phone Directory is empty! \n"<<endl;

    }

    void Search_By_FirstName()
    {
    string Name;
    bool found = false ;
    cout << "Enter the First Name which you searching for : " ;
    cin >> Name;
    for( int i = 0 ; i < firstname.size(); i++)
     {
        if(firstname[i] == Name)
        {
            found = true;
            cout << "The first name: "<<firstname[i]<<endl;
            cout << "The last name: "<<lastname[i]<<endl;
            cout << "The phone number: "<<phonenumber[i]<<endl;
        }
     }
    if(!found)
     {
        cout << "The first name Not Found !! \n";
     }
    }
    void Search_By_phonenumber()
    {
    int phone;
    bool found = false ;
    cout << "Enter the phone number which you searching for : " ;
    cin >> phone;
    for(int i = 0 ; i < phonenumber.size(); i++)
     {
        if(phonenumber[i] == phone)
        {
            found = true;
            cout << "The phone number: "<<phonenumber[i]<<endl;
            cout << "The first name: "<<firstname[i]<<endl;
            cout << "The last name: "<<lastname[i]<<endl;
        }
     }
    if(!found)
     {
        cout << "The phone number Not Found !! \n";
     }
    }



    void Insertion_Sort()
    {
    for ( int i = 1, j; i < firstname.size(); i++)
    {
        string tmp_Fname = firstname [i];
        string tmp_Lname = lastname [i];
        int tmp_Pnum = phonenumber[i];
        for (j = i; j > 0 && tmp_Fname < firstname [j-1]; j--)
        {
            firstname[j] = firstname[j-1];
            lastname[j] = lastname[j-1];
            phonenumber [j] = phonenumber [j -1];
        }
        firstname [j] = tmp_Fname;
        lastname [j] = tmp_Lname;
        phonenumber [j] = tmp_Pnum;
    }
    cout << endl<< "The phone directory After Sorting :"<<endl;
    for( int i = 0 ; i < firstname.size(); i++)
    {
            cout << "The first name: "<<firstname[i]<<endl;
            cout << "The last name: "<<lastname[i]<<endl;
            cout << "The phone number: "<<phonenumber[i]<<endl;
            cout << endl;
    }
    cout << endl;


    }
    void selection_Sort()
     {for (int i = 0, j, least; i < firstname.size()-1; i++)
        {
            for (j = i+1, least = i; j <firstname.size(); j++)
             if (firstname [j] < firstname [least])
              least = j;
           swap (firstname [least], firstname [i]);
           swap (lastname [least], lastname [i]);
           swap (phonenumber [least], phonenumber [i]);
        }
    cout << endl<< "The phone directory After Sorting :"<<endl;
    for( int i = 0 ; i < firstname.size(); i++)
    {
            cout << "The first name: "<<firstname[i]<<endl;
            cout << "The last name: "<<lastname[i]<<endl;
            cout << "The phone number: "<<phonenumber[i]<<endl;
    }
    cout << endl;
     }
     void bubbleSort()
      {
          for (int i = 0; i < firstname.size()-1; i++)
          {

              for (int j = firstname.size()-1; j > i; --j)

		        if (firstname [j] < firstname [j-1])
                {
                    swap (firstname [j], firstname [j - 1]);
                    swap (lastname [j], lastname [j - 1]);
                    swap (phonenumber [j], phonenumber [j - 1]);
                }

          }
    cout << endl<< "The phone directory After Sorting :"<<endl;
    for( int i = 0 ; i < firstname.size(); i++)
    {
            cout << "The first name: "<<firstname[i]<<endl;
            cout << "The last name: "<<lastname[i]<<endl;
            cout << "The phone number: "<<phonenumber[i]<<endl;
    }
    cout << endl;


      }

};
int main()
{   PhoneDirectory obj;
    while(true)
    {
    cout<<endl;
    cout<< "enter value correspond to needed option \n";
    cout<< "1. Add an entry to the directory \n";
    cout<< "2. Look up a phone number \n";
    cout<< "3. Look up by first name \n";
    cout<< "4. Delete an entry from the directory \n";
    cout<< "5. List All entries in phone directory  \n";
    cout<< "6. Exit form this program  \n";
    cout<<endl<<endl;
    int num_function;

       cin>>num_function;
       if(num_function==1)
          obj.Add_Entry();

       else if(num_function==2)
          obj.Search_By_phonenumber();

       else if(num_function==3)
        obj.Search_By_FirstName();

       else if(num_function==4)
        obj.Delete_entry();

       else if(num_function==5)
       {
           cout<< "select the sort way:\n";
           cout<< "insertion sort ENTER 1 \n";
           cout<< "selection sort ENTER 2 \n";
           cout<< "bubble sort ENTER 3 \n";
           int n;
           cin>>n;
           if(n==1)
            obj.Insertion_Sort();
           else if(n==2)
            obj.selection_Sort();
           else
            obj.bubbleSort();

       }
       else
         break;

    }

    return 0;
}
