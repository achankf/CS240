#ifndef SL_TESTER_H
#define SL_TESTER_H


#include "a05q3.h"
#include <vector>


class SLTester
{
    public:
        static unsigned int Width( const SkipList& sl );
        static bool Search( const SkipList& sl, int key );
        static bool TowerSearch( const SkipList& sl, SLTower* t );
  
        static bool TestSet( const SkipList& sl, const std::vector<int>& values );
        static bool TestHeights( const SkipList& sl );
        static bool TestTowerNeighbours( const SkipList& sl, SLTower* t );
        static bool TestLevels( const SkipList& sl );
        static bool TestTowers( const SkipList& sl );

        static void Print( const SkipList& sl );
        static void Example( SkipList& empty );
};


#endif
