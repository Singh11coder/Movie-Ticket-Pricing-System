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
