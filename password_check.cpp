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
