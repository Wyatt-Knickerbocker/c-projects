#ifndef TVINFO_H
#define TVINFO_H

#include<string>

using namespace std;

struct TVDBINFO
{
    string title;   //START INFORMATION
    int start_date;
    int end_date;
    string genre;
    string imdb_link;
    string  actors[16];
	unsigned int actorcount;//END INFORMATION
};

typedef TVDBINFO tvDB;
#endif
