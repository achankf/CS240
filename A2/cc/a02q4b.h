class MaxHeap
{
    public:
        // Create an empty max-heap with storage in array for array_sz elements.
        // Assume that array_sz > 0 and that array will not be externally modified.
        MaxHeap( int* array, int array_sz ) 
            : array( array )
            , array_sz( array_sz )
            , num_values( 0 ) { }
       
        // Insert data into array in max-heap order.
        // Assume that the caller never tries to insert too many values.
        void Insert( int data );
#ifdef NDEBUG
~MaxHeap();
void Print();
int DeleteMax();
void Tree(int i, int d = 0);
bool integ(int i = 0);
#endif

    private:
        // Store the max-heap values with the max value at index 0.
        int *const array;

        // The number of elements in array.
        const int array_sz;

        // The number of values stored in the array.
        // Update this variable whenever inserting or deleting values.
        int num_values;
};
