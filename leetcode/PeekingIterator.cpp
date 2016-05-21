// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
    private:
    int current;
    int Next;
    bool first;
    int nextCall;
    int size;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    assert (nums.size() >= 0);
	    size = nums.size();
	    current = Next = nums[0];
	    first = true;
	    nextCall = 0;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
	    return Next;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    
	    if (!hasNext()) {
	        return -1;
	    }
	    
	    nextCall++;
	    if (first) {
    	    if (Iterator::hasNext()) {
        	    current = Iterator::next();
        	    if (Iterator::hasNext()) {
        	        Next = Iterator::next();
        	    }
    	    }
    	    first = !first;
	    } else {
	        current = Next;
	        if (Iterator::hasNext()) {
        	    Next = Iterator::next();
        	}
	    }
	    
	    return current;
	}

	bool hasNext() const {
	    return (nextCall < size);
	}
};