#include "sl_tester.h"
#include <iostream>
#include <limits>
#include <algorithm>


unsigned int SLTester::Width( const SkipList& sl )
{
    SLTower* head = sl.Head();
    SLTower* tail = sl.Tail();

    int count = 0;
    while( head != tail )
    {
        head = head->Neighbour(0);
        count++;
    }

    return count-1;
}


bool SLTester::Search( const SkipList& sl, int key )
{
    SLTower* head = sl.Head();
    SLTower* t = head;
    for( int i = head->Height()-1; i >= 0; i-- )
    {
        SLTower* next = t->Neighbour( i );

        while( !next->Infinity() && next->Key() < key )
        {
            t = next;
            next = next->Neighbour( i );
        }
 
        if( !next->Infinity() && next->Key() == key )
            return true;
    }

    return false;
}


bool SLTester::TowerSearch( const SkipList& sl, SLTower* tower )
{
    SLTower* t = sl.Head()->Neighbour(0);
    while( t != sl.Tail() )
    {
        if( t == tower )
            return true;
        else
            t = t->Neighbour(0);
    }
     
    return false;
}


bool SLTester::TestSet( const SkipList& sl, const std::vector<int>& values )
{
    // Test whether all vector values are in SkipList.
    // There are much more elegant ways to do this.
    std::vector<int>::const_iterator i;
    for( i = values.begin(); i != values.end(); i++ )
        if( !Search( sl, *i ) ) 
            return false;

    // Test whether all SkipList values are in vector
    // There are much more elegant ways to do this.
    SLTower* t = sl.Head()->Neighbour(0);
    while( t != sl.Tail() )
    {
        if( std::find( values.begin(), values.end(), t->Key() ) == values.end() )
            return false;
        else
            t = t->Neighbour(0);
    }

    return true;
}


// Return true if every tower in sl has the expected number of nodes 
// (i.e., elements in the vector); return false otherwise.
// Note that SLTower::Height returns the number of nodes in the tower.
bool SLTester::TestHeights( const SkipList& sl )
{
    return true;
}


bool SLTester::TestTowers( const SkipList& sl )
{
    SLTower* t = sl.Head()->Neighbour(0);
    while( t != sl.Tail() )
    {
        if( !TestTowerNeighbours( sl, t ) )
            return false;
        else
            t = t->Neighbour(0);
    }
    
    return true;
}


bool SLTester::TestTowerNeighbours( const SkipList& sl, SLTower* t )
{
    for( int i = 1; i < t->Height(); i++ )
        if( !TowerSearch( sl, t ) )
            return false;

    return true;
}


bool SLTester::TestLevels( const SkipList& sl )
{
    for( int i = 0; i < sl.Head()->Height(); i++ )
    {    
        SLTower* t = sl.Head()->Neighbour(i);
        int max = std::numeric_limits<int>::min();

        while( t != sl.Tail() )
        {
            if( t->Key() < max )
                return false;
            else
            {
                max = t->Key();
                t = t->Neighbour(i);
            }
        }
    }

    return true;
}


void SLTester::Print( const SkipList& sl )
{
    SLTower* head = sl.Head();
    unsigned int height = head->Height();
    unsigned int width = Width( sl );

    unsigned int str_width = width + 4;
    char array[height][str_width];
    for( int i = 0; i < height; i++ )
    {
        array[i][0] = '-';
        array[i][width+1] = '+';
        array[i][width+2] = '\n';
        array[i][width+3] = '\0';

        for( int j = 1; j <= width; j++ )
            array[i][j] = '.';
    }

    SLTower* tail = sl.Tail();
    int j = 1;
    for( head = head->Neighbour(0); head != tail; head = head->Neighbour(0), j++ )
        for( int i = 0; i < head->Height(); i++ )
            array[height-i-1][j] = '0';

    for( int i = 0; i < height; i++ )
        std::cout << array[i];
}


void SLTester::Example( SkipList& empty )
{
    // -inf-------3-inf
    // -inf---1---3-inf
    // -inf-0-1-2-3-inf

    SLTower* t0 = new SLTower(0);
    SLTower* t1 = new SLTower(1);
    SLTower* t2 = new SLTower(2);
    SLTower* t3 = new SLTower(3);

    SLTower* head = empty.Head();
    SLTower* tail = empty.Tail();

    // build one tower at a time, from the bottom up
    head->Link( t0 );
    head->Link( t1 );
    head->Link( t3 );

    t0->Link( t1 );
    
    t1->Link( t2 );
    t1->Link( t3 );
  
    t2->Link( t3 );
    
    t3->Link( tail );
    t3->Link( tail );
    t3->Link( tail );
}
