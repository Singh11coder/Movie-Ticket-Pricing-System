#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <fstream>
using namespace std;
int obn,ext,prnt_once=0,dir_customer=0;
int m=0,*p,sn,arg,arg2,tkt,tkt_pr,nt=0,sti,foundu=0,foundp=0,pas_chk=0,mv_str=0,data_store=0;
double cost=0;

int  pas_rak=0;
char cus_in;

string name[100],tkt_pnt,pass,cus_id,cus_pas,user,hall_name;
int ar[100][100][100][12][18],tkt_row[12],tkt_col[18],str_tim[100];
string tim[100][100];

string timing[100];
class movie_booking
{

public:
    void first();
    void show_seat_frm_file();
    void show();
    void seatdisp(int z,int wt);
    void book(int z,int wt ,int a);
    void seatin(int z,int wt);
    void manager();
    void ticket_print();
    void pass_proctect();
    void data_str();
    int password_check();
    void hal_name()
    {
        switch(obn)
        {
            case 1:
            hall_name="CHANDIGHAR CINEMA";
            break;
             case 2:
            hall_name="CINEPOLIS AMRITSAR";
            break;
             case 3:
            hall_name="BIHAR CINEMA MALL";
            break;
             case 4:
            hall_name="KHARAR CINEMA MALL";
            break;
        }

    }

};


void movie_booking::first()
{
    int i;
    char in='c',ind,cus;//cus is customer and ind is manager input
    cout<<"\n\n\t\t\t\t\tTO ENTER MANAGER LOGIN PRESS 'o' or 'O' ELSE ANY OTHER KEY FOR CUSTOMER BOOKING\n";
    cout<<"\t\t\t\t\t\t\t";
    cin>>ind;
    int pas_count=0;
    if((ind=='o')||(ind=='O'))
    {
        while(pas_count<3)
        {
            (*this).pass_proctect();
        if(pass=="KASAW")
        {
            (*this).manager();//the manager mode to set the number of seats available for booking
            pas_count=3;
        }

        else
        {
        cout<<"PASSWORD ENTERED IS WRONG!!"<<" ATTEMPTS REMAINING = "<<2-pas_count<<" \n";//pas_count is to count no. of attempts left
            pas_count++;
        }

    }
    }

    system("clear");
    cout<<"\n\n\t\t\t\t\t\t\tDEAR CUSTOMER TO BOOK SEATS PRESS 'y' or 'Y' \n";
    cout<<"\t\t\t\t\t\t\t";
    cin>>cus;
    //HERE I HAVE TO ADD THE CUSTOMER LOGIN FUNCTION
     if((cus=='y')||(cus=='Y'))//the customer part starts here
     {  cout<<"\n\t\t\t\t\t\t\tIF YOU ARE NEW CUSTOMER PRESS N/n TO SIGNUP\n";
        cout<<"\t\t\t\t\t\t\t";
        cin>>cus_in;
        if(cus_in=='N'||cus_in=='n')
        (*this).data_str();
        else
        {
            cout<<"\n\t\t\t\t\t\t\tWELCOME EXISTING CUSTOMER!!!\n";
           pas_rak=(*this).password_check();

        }

//cout<<"+++++++++++"<<pas_rak<<"--------"<<data_store<<endl;to check the values
        cout<<"\t\t\t\t\t\t\t";
        cout<<"PRESS ANYKEY TO CONTINUE\n";
// CLEAR();
 system("clear");
         if(pas_rak!=0||data_store!=0)
         {  cout<<"\n\n\t\t\t\t\t\tTHE SEATS AVAILABLE ARE:\n";
                 while((in=='c')||(in=='C'))
    {
        cost=0;
       (*this).show_seat_frm_file();
            cout<<"\n\n\t\t\t\t\t\t\tENTER THE MOVIE NUMBER TO BOOK TICKET\n";
            cout<<"\t\t\t\t\t\t\t";
            cin>>arg;
            ifstream fin;//this part is for retrieving moive name from file
fin.open("movie_test2.csv");
   for(i=0;i<arg-1;i++)
   {
    getline(fin,name[i],'\n');
   }
   getline(fin,name[i],',');
    fin.close();
             cout<<"\n\n\t\t\t\t\t\t\tCHOOSE THE NUMBER CORRENSPONDING TO TIMING TO BOOK TICKET FOR MOVIE :-"<<endl;

            cout<<"\t\t\t\t\t\t\t"<<name[i];
            cout<<"\t\t\t\t\t\t\t";
            cin>>sti;

            tkt_pnt=name[i];
               // cout<<"THE ARGUMENT IS ="<<arg<<endl;
            (*this).seatdisp(arg,sti);
            (*this).seatin(arg,sti);
            system("clear");
            (*this).seatdisp(arg,sti);
            /*HERE ANOTHER FUNCTION IS TO BE WRITTEN TO PRINT THE TICKETS*/
            system("clear");

            (*this).ticket_print();
    cout<<"\n\n\t\t\t\t\t\t\tPRESS 'C' or 'c' IF U WANT TO BOOK SEAT AGAIN?\n";
    cin>>in;



    }
         }

else{cout<<"\n\n\t\t\t\t\t\t\t YOU PRESSED WRONG USER PASSWORD\n";
    cout<<"\n\n\t\t\t\t\t\t\t PROGRAM TERMINATED!!!\n";
        cout<<"\n\n\t\t\t\t\t\t\t YOU ENTERED WRONG PASSWORD";}

     }
}

void movie_booking::show_seat_frm_file()
{int i=0,j;
    system("clear");//after the input is being over the screen is cleared and data is displayed
cout<<"\n\n\t\t\t\t\t\t\tTHE MOVIES RUNNING IN HALL ARE:\n\n\n";
ifstream fin;
fin.open("movie_test2.csv");
if(dir_customer==0)
    m=13;
while(i<m)
{
     cout<<"\n\t\t\t\t\t\t\t";

    getline(fin,name[i],',');
    cout<<"MOVIE :\t"<<i+1<<"\t"<<name[i]<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t";
    cout<<"THE TIMINGS OF THE MOVIE : "<<name[i]<<" :-  "<<endl;
    int j=0;

   getline(fin,tim[i][j],'\n');
        cout<<"\t\t\t\t\t\t\t";
        cout<<tim[i][j]<<endl<<endl;

i++;//to access the different movie names
}

}
void movie_booking::show()//this function is for entering the number of movie running in hall
{
    int i,j;
    p=(int*)(malloc(sizeof(int)));
    cout<<"\n\n\t\t\t\t\t\t\tENTER THE NUMBER MOVIES RUNNING IN THE HALL\n";
    cout<<"\t\t\t\t\t\t\t";
    cin>>m;
    (*p)=m;
     ofstream fout;
    fout.open("movie_test2.csv",ios::app);
for(i=0;i<m;i++)//m is the total no of movies running in that hall
{   fflush(stdin);
    cout<<"\n\n\t\t\t\t\t\t\tENTER THE NAME OF MOVIE "<<i+1<<endl;
    cout<<"\t\t\t\t\t\t\t";
    getline(cin,name[i]);
    fflush(stdin);
    fout<<name[i]<<",";//movie name writing in file
    cout<<"\n\n\t\t\t\t\t\t\tENTER THE NUMBER OF SHOWS OF MOVIE: "<<name[i]<<" IN A DAY : ";
    cin>>nt;
    str_tim[i]=nt;
    //here a function is to be added to save the show timings
    cout<<"\n\n\t\t\t\t\t\t\tENTER THE SHOW TIMINGS OF THE MOVIE : "<<name[i]<<endl;
    for(j=0;j<nt;j++)
    {   fflush(stdin);
         cout<<"\t\t\t\t\t\t\t";
        getline(cin,tim[i][j]);// this is the function for collecting the show timings
        fout<<tim[i][j]<<",";

    }
    fout<<endl;

}
 fout.close();
 //FILE HANDLING 100% CORRECT TILL HERE
 m=m+13;//as already is csv file there 13 movies
(*this).show_seat_frm_file();
}


void movie_booking::seatdisp(int z,int wt)
//1st argument to display the seats of that particular movie
//2nd arg is for the particular movie time
{
    arg=z;
    sti=wt;
    int i,j;
    char ch='A',st;
    system("clear");
    cout<<"\n\nCOST OF RECTILINEAR:Rs 500/-\n";
      cout<<"COST OF SUPER DELUXE :Rs 200/-\n";
    cout<<"COST OF  DELUXE :Rs 100/-\n";
ifstream fin;
fin.open("movie_test2.csv");
   cout<<"\n\n\t\t\t\t\t\t\tBOOKED SEATS ARE MARKED WITH [x]\n\n";
   for(i=0;i<arg-1;i++)
   {
    getline(fin,name[i],'\n');
   }
   getline(fin,name[i],',');
   cout<<"\n\n\t\t\t\t\t\t\tTHIS IS THE SEAT MATRIX FOR MOVIE: "<<name[i]<<"\n\n";
    fin.close();
    for(i=0;i<13;i++)
    {
        ch='A';
        ch=ch+i;
        cout<<"\t";
     for(j=0;j<18;j++)
        {
            if(ar[obn][arg][sti][i][j]==1)
            cout<<"["<<" X"<<"]";
            else
            {
                cout<<"["<<ch<<j+1<<"]";
            }

            cout<<" ";//1 white spaces given
                      //the seat would be displayed in format[A1]

            if(j==4||j==12)
                cout<<"\t";

        }
        cout<<"\n\n";
 if(i==12)
    {
        cout<<"\n\n\t\t\t\t\t\t SCREEN THIS WAY\n";
        cout<<"\t______________________________________________________________________________________________________________";
    }

    }

}




void movie_booking::book(int z,int wt ,int a)//first argument is for the movie number and 3rd argument for manager mode
//2nd arg is for show time
{int i,j,num,al,n,col,stor,arg;
arg=z;
sti=wt;
    arg2=a;
    if(arg2==100)
    {
      cout<<"\n\n\t\t\t\t\t\t\tADMIN ENTER THE SEATS WHICH WONT BE AVAILABLE FOR BOOKING\n";
    }

else
{
 cout<<"\n\n\t\t\t\t\t\t\tCUSTOMER BOOKING\n";
}

        (*this).seatdisp(arg,sti);
    char ch='A',chr;
    cout<<"\n\n\t\t\t\t\t\t\tENTER THE SEAT NUMBER\t";

        cin>>chr>>col;
        stor=chr-65;
        col=col-1;

        if(ar[obn][arg][sti][stor][col]==0)
        {
            ar[obn][arg][sti][stor][col]=1;

            tkt_col[tkt]=col;
            tkt_row[tkt]=stor;


        }
        else
        {

            while(ar[obn][arg][sti][stor][col]!=0)
            {
                if(arg2==100)
                {
                  cout<<"\n\n\t\t\t\t\t\t\tADMIN YOU HAVE ALREADY MARKED THIS SEAT AS BOOKED ENTER A NEW SEAT WHICH IS BOOKED\n";
               cout<<"\t\t\t\t\t\t\t ";
                }

           else
           {
            cout<<"\n\n\t\t\t\t\t\t\tTHE SEAT YOU SELECTED IS ALREADY OCCUPIED ENTER A NEW SEAT\n";
            cout<<"\t\t\t\t\t\t\t ";
           }
                cin>>chr>>col;
                stor=chr-65;
                col=col-1;
            }
            ar[obn][arg][sti][stor][col]=1;
           tkt_col[tkt]=col;
            tkt_row[tkt]=stor;
        }

}

void movie_booking::seatin(int z,int wt)//1st argument for the particular movie seat booking
//2nd arg is for particular show time of particular movie
{

     int n,i;
    arg=z;
    sti=wt;
    //cout<<"THE ARGUMENT IS nest="<<arg<<endl;
     cout<<"\n\n\t\t\t\t\t\t\tENTER THE NUMBER OF SEATS TO BE BOOKED"<<endl;
     ifstream fin;//this part is for retrieving moive name from file
fin.open("movie_test2.csv");
   cout<<"\n\n\t\t\t\t\t\t\tBOOKED SEATS ARE MARKED WITH [x]\n\n";

   for(i=0;i<arg-1;i++)
   {
    getline(fin,name[i],'\n');
   }
   getline(fin,name[i],',');

            cout<<"\t\t\t\t\t\t\t MOVIE NAME="<<name[i]<<endl;
           fin.close();
            cout<<"\t\t\t\t\t\t\t ";
    cin>>n;
    tkt_pr=n;
       for(tkt=0;tkt<n;tkt++)//loop for booking the desired no. of tickets as input by user
{
     (*this).book(arg,sti,20);
     cout<<"LOOP IS RUNNING\n";
       system("clear");
  (*this).seatdisp(arg,sti);

}
cout<<"\n\n\t\t\t\t\t\t\tPRESS ANY KEY TO CONTINUE\n";
// CLEAR();
 system("clear");

}




void movie_booking::manager()
{   char mov='c',in='c';
    (*this).show();
    while((mov=='c')||(mov=='C'))//this loop is for entering the seats that are booked for different movies
    {
        cout<<"\n\n\t\t\t\t\t\t\t ENTER THE SHOW NUMBER WHOSE SEATS U WANT TO ASSIGN FOR BOOKING\n";
        cout<<"\t\t\t\t\t\t\t";
    cin>>sn;
      cout<<"\n\n\t\t\t\t\t\t\t ENTER THE NUMBER CORRESPONDING TO THE TIME TO BOOK TICKET\n";
        cout<<"\t\t\t\t\t\t\t";
    cin>>sti;
    tkt_pnt=name[sn];

    while((in=='c')||(in=='C'))
    {
      (*this).book(sn,sti,100);
      system("clear");
      (*this).seatdisp(sn,sti);
    cout<<"\n\n\t\t\t\t\t\t\tPRESS 'C' or 'c' IF U WANT TO CONTINUE ENTERING THE BOOKED SEATS\n";
    cout<<"\t\t\t\t\t\t\t";
    cin>>in;
    }

    cout<<"\n\n\t\t\t\t\t\t\tPRESS 'C' or 'c' IF U WANT TO CONTINUE ENTERING FOR OTHER MOVIES\n";
    cout<<"\t\t\t\t\t\t\t";
    cin>>mov;
    in='c';
    }
    mv_str++;

}

void movie_booking::ticket_print()
{    int i,a=0,b=0,d=0;
    char c;
    string time;//time to store the movie timing

    for(i=0;i<tkt_pr;i++)//this loop is for printing the total cost of ticket
        {


             if(tkt_row[i]==0||tkt_row[i]==1)
            {
                cost=cost+500;
                a++;
            }
            else if(tkt_row[i]>1&&tkt_row[i]<7)
            {
                cost=cost+200;
                b++;
            }
            else{cost=cost+100;d++;}


        }
           cout<<"\n\n\n\t\t\tCOST : "<<endl;
           if(a!=0)
           cout<<"\t\t\t       "<<a<<" * 500"<<endl;
           if(b!=0)
           cout<<"\t\t\t      +"<<b<<" * 200"<<endl;
           if(c!=0)
           cout<<"\t\t\t      +"<<d<<" * 100"<<endl;
       cout<<"GST 18% = "<<cost*0.18<<endl;
       cost=cost+cost*(0.18);
        cout<<"\n\n\n\n\t\t\tTHE TOTAL TICKET COST = Rs "<<cost<<"/-"<<endl;
        cout<<"\n\nPRESS ANY KEY TO CONTINUE\n";
    //    CLEAR();
     system("clear");

         system("clear");
         ifstream fin;//this part is for retrieving moive name from file
fin.open("movie_test2.csv");

   for(i=0;i<arg-1;i++)
   {
    getline(fin,name[i],'\n');
   }
   getline(fin,name[i],',');

         for(int j=0;j<sti;j++)
   {
    getline(fin,time,',');
   }
   fin.close();
    (*this).hal_name();
    cout<<"\n\n\n\n\t\t\t________________________________________________________________________________\n";
cout<<"\t\t\t|                                                                              |\n";
cout<<"\t\t\t|   Dear Customer,                                                             |\n";
cout<<"\t\t\t|                      Congratulation!! Your tickets has been booked.          |\n";
cout<<"\t\t\t|                                                                              |\n";
cout<<"\t\t\t|                  THE DETAILS:                                                |\n";
cout<<"\t\t\t|                            MOVIE HALL: "<<hall_name<<"                 \n";
cout<<"\t\t\t|                            MOVIE NAME: "<<name[i]<<"                                 \n";
cout<<"\t\t\t|                            SHOW STARTS:"<<time<<"                        \n";
cout<<"\t\t\t|                            NUMBER OF TICKETS BOOKED: "<<tkt_pr<<"             |\n";
cout<<"\t\t\t|                 THE SEAT NUMBERS ARE: ";for(i=0;i<tkt_pr;i++)
                                            {   c=tkt_row[i]+65;
                                                cout<<c<<tkt_col[i]+1;//PLS CHECK WHY I HV WRITTEN HERE +
                                                if(i<tkt-1)
                                                {
                                                    cout<<",";
                                                }
                                            }
cout<<"                        \n";
cout<<"\t\t\t|                                                     QR CODE                  |\n";
cout<<"\t\t\t|                                                       ..++>>>                |\n";
cout<<"\t\t\t|                                                       ..__***                |\n";
cout<<"\t\t\t|                                                       &%^>>>>                |\n";
cout<<"\t\t\t|                                                       :::::::                |\n";
cout<<"\t\t\t|______________________________________________________________________________|\n";


}

void movie_booking::pass_proctect()//to protect the password
{

        int ps=0,star=0;// to count the characters in password

        //star is to print the password in * format
                    //pas[-1]=0;//intialised just like that "I GUESS ITS NIT REQUIRED"
         cout<<"\n\n\t\t\t\t\t\t\tENTER THE MANAGER PASSWORD\n";
         cout<<"\t\t\t\t\t\t\t";

                cin>>pass;
               ps=pass.length();
                system("clear");
                while(star<ps)
                {   if(star==0)
                {
                    cout<<"\n\n\t\t\t\t\t\t\tENTER THE MANAGER PASSWORD\n\n";

                    cout<<"\t\t\t\t\t\t\t\t";

                }

                    cout<<" * ";
                    star++;
                }

}

void movie_booking::data_str()
{
 ofstream fout;
    fout.open("database1.csv",ios::app);
    string name1,name2,usr_id,usr_psd;
    /*format to be save is 1st name,title,user id,age,password*/
    fflush(stdin);


 cout<<"\t\t\t\t\t\t\tENTER THE FIRST NAME\n";
        fflush(stdin);
        getline(cin,name1);
         cout<<"\t\t\t\t\t\t\tENTER THE LAST NAME\n";
         fflush(stdin);
        getline(cin,name2);
         cout<<"\t\t\t\t\t\t\tENTER THE USER ID\n";
         fflush(stdin);
        getline(cin,usr_id);
         cout<<"\t\t\t\t\t\t\tENTER THE USER PASSWORD\n";
         fflush(stdin);
        getline(cin,usr_psd);
         fout<<name1<<","<<name2<<","<<usr_id<<","<<usr_psd<<endl;

fout.close();
data_store=1;
}
int movie_booking::password_check()
{
     cout<<"\n\n\t\t\t\t\t\t\tENTER YOUR USER ID\n";
            fflush(stdin);
            cout<<"\t\t\t\t\t\t\t";

            cin>>cus_id;
 ifstream myfile;
            myfile.open("database1.csv");
                while(!myfile.eof())
            {
                getline(myfile,user,',');
                getline(myfile,user,',');
                getline(myfile,user,',');
                getline(myfile,pass,'\n');
                fflush(stdin);

                fflush(stdin);
                if(user==cus_id||pass==cus_id)
                {
                   foundu++;
                   prnt_once++;
                   if(prnt_once==1)
                   cout<<"\n\n\t\t\t\t\t\t\tUSER ID FOUND\n";
                }


            }

            if(foundu==0)
            {cout<<"\n\n\t\t\t\t\t\t\tUSER ID NOT FOUND\n";
             myfile.close();
            }
              else
              {
                 myfile.close();
                              cout<<"\n\n\t\t\t\t\t\t\tENTER YOUR USER PASSWORD\n";
            fflush(stdin);
             cout<<"\t\t\t\t\t\t\t";
            cin>>cus_pas;
 myfile.open("database1.csv");
                while(!myfile.eof())
            {
                getline(myfile,user,',');
                getline(myfile,user,',');
                getline(myfile,user,',');
                getline(myfile,pass,'\n');
                fflush(stdin);

                fflush(stdin);
                if(pass==cus_pas)
                {
                   foundp++;
                   cout<<"\n\n\t\t\t\t\t\t\tPASSWORD MATCHED\n";
                }


            }

              }

            if(foundp==0)
               cout<<"\n\n\t\t\t\t\t\t\tPASSWORD IS WRONG\n";


             myfile.close();
             return foundp;


}
int sale(long long g,long long f)
{
    // const double PRICE_PER_TICKET; // price per ticket
   //int numTicketsSold; // number of tickets sold
   long long totalSales; // total sales for all tickets sold

   // Get the number of tickets sold from the user
   //cout << "Enter the number of tickets sold: ";
   //cin >> numTicketsSold;

   // Calculate the total sales
   totalSales = g* f;

   // Display the total sales
   //cout << "Total sales: $" << totalSales << endl;

   return totalSales;
}
double t;
int monthly_sale(long long g,long long f)
{
    long long totalsales;
    totalsales=g*f;
    return totalsales;
}
int last_year(long long g,long long f)
{
    long long totalsales;
    totalsales=g*f;
    t=totalsales;
    return totalsales;

}

int main()
{
    prnt_once=0;
    movie_booking obj[4];
    cout<<"\n\n\t\t*********************WELCOME TO THE CINEMA WORLD *********************";
    //cout<<endl;
    cout<<"\n\n\t\t======================================================================";
    while(1)
    {

        cout<<"\n\n\t\t\t PRESS 1 TO BOOK TICKET IN CHANDIGHAR CINEMA           ";
        cout<<"\n\n\t\t\t PRESS 2 TO BOOK TICKET IN CINEPOLIS AMRITSAR          ";
        cout<<"\n\n\t\t\t PRESS 3 TO BOOK TICKET IN BIHAR CINEMA MALL           ";
        cout<<"\n\n\t\t\t PRESS 4 TO BOOK TICKET IN KHARAR CINEMA MALL          ";
        cout<<"\n\n\t\t\t PRESS 5 TO CHECK MAXIMUM SALE IN A DAY                ";
        cout<<"\n\n\t\t\t PRESS 6 TO CHECK MAXIMUN SALE IN A MONTH              ";
        cout<<"\n\n\t\t\t PRESS 7 TO CHECK MAXIMUM SALE IN LAST YEAR            ";
        cout<<"\n\n\t\t\t PRESS 8 TO CHECK THE INCREASE RATE OF REVENUE OR LAND ";
        cout<<"\n\n\t\t\t TO EXIT PROGRAM PRESS 9 ";
        cout<<"\n\n\t\t\t\t";
    cin>>obn;
    switch(obn)
    {
        case 1:
            cout<<"\t\t\t\t\t\t\t";
            cout<<"CHANDIGHAR CINEMA IS SELECTED\n";
        obj[0].first();
        break;
        case 2:
        cout<<"\t\t\t\t\t\t\t";
            cout<<"CINEPOLIS AMRITSAR IS SELECTED\n";
        obj[1].first();
        break;
        case 3:
        cout<<"\t\t\t\t\t\t\t";
             cout<<"BIHAR CINEMA MALL IS SELECTED\n";
        obj[2].first();
        break;
        case 4:
        cout<<"\t\t\t\t\t\t\t";
            cout<<" KHARAR CINEMA MALL IS SELECTED\n";
        obj[3].first();
        break;
        case 5:
            {
                long long h;
                long long p;
                cout<<"ENTER THE NUMBER OF TICKETS SOLD";
                cin>>h;
                cout<<"ENTER THE PRICE OF EACH TICKET";
                cin>>p;

                long long j=sale(h,p);
                cout<<endl<<"TOTAL SALE FOR A DAY IN RUPPES  "<<j<<endl;
                 cout<<endl;
                 break;
            }
        case 6:
            {
               long long h,p;
               cout<<"ENTER THE NUMBER OF TICKETS SOLD IN A MONTH";
               cin>>h;
               cout<<"ENTER THE PRICE OF EACH TICKET ";
               cin>>p;

               long long  f= monthly_sale(h,p);
               cout<<endl<<"  MONTHLY SALE "<<f<<endl;
               cout<<endl;
               break;
            }
        case 7:
            {
             long long h,p;
              cout<<"ENTER THE NUMBER OF TICKETS SOLD IN THE LAST YEAR";
              cin>>h;
              cout<<"ENTER THE PRICE OF EACH TICKET";
              cin>>p;

              long long f=last_year(h,p);
              cout<<endl<<"SALE OF LAST YEAR   "<<f<<endl;
              cout<<endl;
              break;

            }
        case 8:
            {
                long long s;
                cout<<"ENTER THE TOTAL SALE DONE IN THE LAST YEAR";
                cin>>s;
                cout<<endl;
                double k=987593839;
                 if(s<k){

                  cout<<"ACCORDING TO THE ESTIMATION FROM LAST 5 YEARS THIS SALE LEAD TO THE DECREASE \n"
                        "IN REVNUES OF LAND OR POPULARITY OF AREA"<<endl;
                        cout<<endl;
                  double q=(s/k)*100;
                  cout<<"APPROXIMATELY YOUR SALE SHOULD INCREASE BY   " <<100-(q)<<"% PERCENT TO MAKE \n"
                        "HIGH REVENUES OF LAND"<<endl;
                        cout<<endl;
                  int l=q*120;
                  cout<<"YOU NEED TO SELL "<<l<<" MORE TICKETS AS COMPARE TO THE LAST YEAR"<<endl;


                 }
                 else{
                    int z=20;
                    double o=(k/s)*100;
                    cout<<"YOUR SALE IS GOING ON AN EXCELENT STAGE "<<endl;
                    cout<<endl;
                    cout<<"IF ESTIMATING YOUR SALE IN THE COMING YEARS \n "
                          " THE LAND AND REVENUES OF THAT PARTICULAR AREA COMES IN DEMAND"<<endl;
                          cout<<endl;
                    cout<<"ACCORDING TO YOUR SALE THE PRICE OF LAND AND REVENUE INCRESASE BY "<< o+z <<" PERCENT IN THE COMING YEARS"<<endl;
                    cout<<endl;
                 }





            }
        case 9:
                goto bye;
                break;
        default:
        cout<<"enter a valid number\n";
        goto bye;
                break;
    }


    }



bye:

     cout<<"\n\n\n\n\t\t\t\t\t\t\t THANK YOU FOR USING OUR APPLICATION!!!!";
 return 0;

}

