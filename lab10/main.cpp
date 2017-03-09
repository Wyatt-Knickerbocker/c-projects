#include <iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstring>

#include "tree.h"
#include "tvinfo.h"

using namespace std;

void ReadFile();
void PrintStruct(tvDB print);

int main()
{
	unsigned count, choice, decade;

    tree tvtree;

    tvDB *temptv;

    string tempstr, fullname, date, input;
	
	char yn;
	
    //!BEGIN FILE READ
	
    ifstream infile ("movies.txt");

    while(infile.good())
    {
		temptv = new tvDB;
		temptv->actorcount = 0;
		
        getline(infile, tempstr); //Title
        temptv->title = tempstr.substr(0, (tempstr.length()- 13));
        //cout << "TITLE: " << temptv->title << endl;
		
		date = tempstr.substr((tempstr.length()-11), 4); //Start date
		temptv->start_date = atof(date.c_str());
		//cout << "START DATE: " << temptv->start_date << endl;
		
		date = tempstr.substr((tempstr.length()-6), 4); //End date
		temptv->end_date = atof(date.c_str());
		//cout << "END DATE: " << temptv->end_date << endl;

        getline(infile, temptv->genre); //Genre
        //cout << temptv->genre << endl;

        getline(infile, temptv->imdb_link); //IMDB page
        //cout << temptv->imdb_link << endl;

		
		count = 0;
        while((infile.peek() >= 65) && (infile.peek() <= 90)) //Actors
        {
            getline(infile, fullname);
			fullname = fullname.substr(0, fullname.length() - 1);
            temptv->actors[count] = fullname;
			temptv->actorcount++;
			count++;
        }
		
		//cout << endl;
        infile.ignore();
		infile.ignore();
		//cout << "SUP" << endl;
        tvtree.AddNode(*temptv);
		//PrintStruct(*temptv);
		delete temptv;
		//cout <<"BRO" << endl;
        //cout << "\nhere?" << endl;

    }
	cout << "ALL FILES LOADED.\n" << endl;
  infile.close();

  //!END OF FILE CATCHING
  //!START OF STUFF

	cout << "Welcome to the move database." << endl;

    while(choice != 0 || choice != 0)
	{

		cout << "Please choose an option:" << endl;
		cout << "0) Exit Program;" << endl;
		cout << "1) Show All Movies;" << endl;
		cout << "2) Find Shows by Actor;" << endl;
		cout << "3) Find Actors By Show;" << endl;
		cout << "4) Find Shows By Decade;" << endl;
		cout << "Choice: ";
		cin >> choice;

		switch(choice)
		{
		
		case 1:
			cout << "\nALL MOVIES:\n" << endl;
			tvtree.PrintShows(); 
			cout <<"Press Enter to continue." << endl;
			cin.ignore();
			cin.ignore();
			break;
		case 2:
			cout << "Please enter a name.\nName: ";
			cin.ignore();
			getline(cin, input);
			cout << input << endl;
			cout << "\nShows with " << input << ':' << endl;
			tvtree.PrintByActor(input);
			cout <<"Press Enter to continue." << endl;
			cin.ignore();
			break;
			
		case 3:
			cout << "Please enter a title.\nTitle: ";
			cin.ignore();
			getline(cin, input);
			cout << "\nActors in " << input << ":" << endl;
			tvtree.ActorsInShow(input);
			cout <<"Press Enter to continue." << endl;
			cin.ignore();
			break;
			
		case 4:
			cout << "Please enter a year.\nYear: ";
			cin >> decade;
			cin.ignore();
			cout << "\nShows started in the decade of " << decade << ':' << endl;
			tvtree.ShowsFromDecade(decade);
			cout <<"Press Enter to continue." << endl;
			cin.ignore();
			break;
			
		default:
			if(choice != 0)
			{
				cout << "Invalid choice.\n" << endl;
			}
			else
			{
				cout << "Thank you, goodbye." << endl;
			}
		}
	}
    cout << "\n-------"<< endl;
    return 0;
}

void PrintStruct(tvDB print)
{
	cout << print.title <<endl;
	cout << print.start_date <<'-' << print.end_date <<endl;
	cout << print.genre <<endl;
	cout << print.imdb_link << endl;
	cout << "ACTORS:" << endl;
	for(unsigned int i = 0; i < print.actorcount; i++)
	{
		cout << print.actors[i] << endl;
	}
}
