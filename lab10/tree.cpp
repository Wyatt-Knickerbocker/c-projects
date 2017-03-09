#include "tree.h"


#include<iostream>
#include<string>
#include<cstring>

using namespace std;

tree::tree()
{
    root = NULL;//ctor
}


void tree::DeleteTree(treeptr& treePtr)
{
   if( treePtr != NULL )
   {
      DeleteTree( treePtr->left );
      DeleteTree( treePtr->right );
      delete  treePtr;
      treePtr = NULL;
   }
}

tree::~tree()
{
   DeleteTree(root); //dtor
}

void tree::AddNode(tvDB inf)
{
    treeptr n;
    n = new TNode;

    n->info = inf;
    n->left = NULL;
    n->right = NULL;

    if (root == NULL)
    {
        root = n;
    }
    else
    {
        treeptr ptr = root;
        treeptr target;

        while( ptr != NULL)
        {
            target = ptr;
			
			if(inf.start_date <= ptr->info.start_date)
            {
                ptr = ptr->left;
            }
            else //Otherwise it's greater
            {
                ptr = ptr->right;
            }
        }
        if(inf.start_date <= target->info.start_date)
        {
            target->left = n;
        }
        else
        {
                target->right = n;
        }
    }
    return;
}

//!START INORDER TITLE PRINT
void tree::PrintShows()
{
    PrintShowsPrivate(root);
}

void tree::PrintShowsPrivate(treeptr travel)
{

    if(travel != NULL)
    {
        PrintShowsPrivate(travel->left);

        cout << travel->info.title << endl;

        PrintShowsPrivate(travel->right);
    }
}
//!END INORDER TITLE PRINT

//!FUNCTION FOR FINDACTOR
string CapString(string str)
{
    for(unsigned int i = 0; i < str.length(); i++)
    {
		//cout << actorname << endl;
        if( (str[i] >= 97) && (str[i] <= 122) )
        {
			//cout <<"BRUH STOP" << endl;
            str[i] = str[i] - 32;
        }
    }
	//cout << str << endl;
    return str;
}
//!END FUNCTION

void tree::PrintByActor(string actor)
{
	actor = CapString(actor);
    PrintActorPrivate(actor, root);
}

void tree::PrintActorPrivate(string actor, treeptr traversal)
{

	string check;
	
    if(traversal != NULL)
    {

        PrintActorPrivate(actor, traversal->left);

        for(unsigned int i = 0; i < traversal->info.actorcount; i++)
		{
			check = CapString(traversal->info.actors[i]);
			//cout << actor << "=?=" << traversal->info.actors[i] << endl;
			if(!strcmp(actor.c_str(), check.c_str()))
			{
				cout << traversal->info.title << endl;
			}
		}

        PrintActorPrivate(actor, traversal->right);
    }
}
//!END INORDER PRINT BY ACTOR

void tree::ActorsInShowPrivate(string show, treeptr p)
{
	
	if(p != NULL)
	{
		string check = CapString(p->info.title);
		
		if(!strcmp(show.c_str(), check.c_str()))
		{
			for(unsigned int i = 0; i < p->info.actorcount; i++)
			{
				cout << p->info.actors[i] << endl;
			}
			return;
		}
		else
		{
			ActorsInShowPrivate(show, p->left);
			ActorsInShowPrivate(show, p->right);
		}
	}
}

void tree::ActorsInShow(string show)
{
	show = CapString(show);
	ActorsInShowPrivate(show, root);
}

void tree::ShowsFromDecade(int decade)
{
    ShowsFromDecadePrivate(decade, root);
}
void tree::ShowsFromDecadePrivate(int decade, treeptr p)
{
	if(p != NULL)
	{
	
		int period = ((decade%100) - (decade%10));
		int check = ((p->info.start_date%100)-(p->info.start_date%10));
		
		ShowsFromDecadePrivate(decade, p->left);
		
		if(check == period)
		{
			cout << p->info.title << endl;
		}
		
		ShowsFromDecadePrivate(decade, p->right);
		
	}

}