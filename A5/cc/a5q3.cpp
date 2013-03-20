#include "a5q3.h"
#include <stddef.h>


SLTower::SLTower()
    : height( 0 )
    , infinity( true )
{
}
 
    
SLTower::SLTower( int key )
    : height( 0 )
    , infinity( false )
    , key( key )
{
}


SLTower* SLTower::Neighbour( unsigned int layer ) const
{
    return layer < height ? neighbours[layer] : NULL;
}


void SLTower::Link( SLTower* t )
{
    height++;
    neighbours.push_back( t );
}


SkipList::SkipList()
    : head()
    , tail()
{
    head.Link( &tail );
}


SkipList::SkipList( const std::vector<int>& uniqueSortedValues )
{
}


bool SkipList::Search( int key ) const
{
    SLTower* t = (SLTower*)&head;
    for( unsigned int i = head.Height()-1; i >= 0; i-- )
    {
        SLTower* next = t->Neighbour( i );
        while( next->Key() < key && !next->Infinity() )   
        {
            t = next;
            next = next->Neighbour( i );
        }

        if( !t->Infinity() && t->Key() == key )
            return true; 
    }

    return false;
}
