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
