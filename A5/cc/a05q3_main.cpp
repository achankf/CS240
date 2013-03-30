#include "a05q3.h"
#include "sl_tester.h"
#include <stdio.h>


int main()
{
    int num_elements;
    scanf( "%d", &num_elements );

    int array[num_elements];
    for( int i = 0; i < num_elements; i++ )
        array[i] = i;
    std::vector<int> input( array, array+num_elements );
 
    SkipList sl( input );

    if( SLTester::TestLevels( sl ) )
        printf( "Passed TestLevels\n" );
    else
        printf( "Failed TestLevels\n" );

    if( SLTester::TestTowers( sl ) )
        printf( "Passed TestTowers\n" );
    else
        printf( "Failed TestTowers\n" );

    if( SLTester::TestHeights( sl ) )
        printf( "Passed TestHeights\n" );
    else
        printf( "Failed TestHeights\n" );

    if( SLTester::TestSet( sl, input ) )
        printf( "Passed TestSet\n" );
    else
        printf( "Failed TestSet\n" );

    return 0;
}
