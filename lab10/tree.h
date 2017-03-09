#ifndef TREE_H
#define TREE_H



#include"tvinfo.h"
#include<string>

using namespace std;

class tree
{
        private:

        struct TNode
        {
            tvDB info;

            TNode * right; //POINTERS TO TRAVERSE
            TNode * left;
        };

        typedef TNode * treeptr;

        treeptr root;

        void DeleteTree(treeptr& treePtr);
		
		void ActorsInShowPrivate(string show, treeptr);
        void PrintShowsPrivate(treeptr travel);
        void PrintActorPrivate(string actor, treeptr travel);
        void ShowsFromDecadePrivate(int decade, treeptr root);

    public:

        tree();
       ~tree();

        void AddNode(tvDB info);

        void PrintShows();
		void ActorsInShow(string show);
        void PrintByActor(string actor);
        void ShowsFromDecade(int decade);
};

#endif // TREE_H
