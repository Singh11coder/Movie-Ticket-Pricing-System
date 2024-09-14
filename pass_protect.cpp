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
