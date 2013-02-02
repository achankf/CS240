class MaxHeap
{
    public:
        // Create an empty max-heap with storage in array for array_sz elements.
        // Assume that array_sz > 0 and that array will not be externally modified.
        MaxHeap( int* array, int array_sz ) 
            : array( array )
            , array_sz( array_sz )
            , num_values( 0 ) { }
#ifdef NDEBUG
				~MaxHeap();
#endif
       
        // Insert data into array in max-heap order.
        // Assume that the caller never tries to insert too many values.
        void Insert( int data );

        // Delete the max value from the heap and return that value.
        // Assume that the caller 
        int DeleteMax();

        int NumValues() const { return num_values; }
				void Print();

    private:
        // Store the max-heap values with the max value at index 0.
        int * array;

        // The number of elements in array.
        const int array_sz;

        // The number of values stored in the array.
        // Update this variable whenever inserting or deleting values.
        int num_values;
};