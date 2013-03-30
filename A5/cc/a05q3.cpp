#include "a05q3.h"
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
}


SkipList::SkipList( const std::vector<int>& uniqueSortedValues )
    : head()
    , tail()
{
}
