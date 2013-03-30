#ifndef A5Q3_H
#define A5Q3_H


#include <vector>


class SLTower
{
    public:
        SLTower();
        SLTower( int key );

        bool Infinity() const { return infinity; }
        int Key() const { return key; }
        unsigned int Height() const { return height; }

        SLTower* Neighbour( unsigned int layer ) const;
        void Link( SLTower* t );

    protected:
        std::vector<SLTower*> neighbours;
        unsigned int height;
        bool infinity;
        int key;
};


class SkipList
{
    public:
        SkipList();
        SkipList( const std::vector<int>& uniqueSortedValues );
 
        SLTower* Head() const { return (SLTower*)&head; }
        SLTower* Tail() const { return (SLTower*)&tail; }

    protected:
        SLTower head;
        SLTower tail;
};


#endif
