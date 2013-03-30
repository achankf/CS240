#include "a05q3.h"
#include <stddef.h>
#include <cmath>
#include <iostream>
using namespace std;


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
	const size_t size = uniqueSortedValues.size();

	// nothing in the array
	if (size == 0) return;

	// copy all items and push their reference into an array; using it as a map
	vector<SLTower * > towers(size);
	for (size_t i = 0; i < size; i++){
		towers[i] = new SLTower(uniqueSortedValues[i]);
	}

	size_t maxTowerHeight = log(size) / log(2);

	// loop for each level O(lg(n))
	for (size_t i = 0; i <= maxTowerHeight; i++){
		size_t prevIdx = 0; // counter
		size_t jumpSize = 1 << i; // 2^i, counting factor

		SLTower *cur = &head; // iterator

		// for each level, loop for n/2^i items
		while(true){
			prevIdx += jumpSize;
			if (prevIdx > size) break;
			// off-by-one since 2^i starts with 1, not 0
			SLTower *next = towers[prevIdx - 1];
			cur->Link(next);
			cur = next;
		}
		cur->Link(&tail);
	}

	// Algorithm run time: in O(n) + (n/2 + n/4 + n/8 + ...) = O(n) time :)
	//   space: O(n) for the vector map
}

// destructor -- just ignore it
SkipList::~SkipList(){
	SLTower *next;
	SLTower *cur = head.Neighbour(0);
	if (!cur) return;

	for (;;){
		next = cur->Neighbour(0);
		delete cur;
		if (next == &tail) break;
		cur = next;
	}
}
