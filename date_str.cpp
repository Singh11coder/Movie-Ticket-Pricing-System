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
