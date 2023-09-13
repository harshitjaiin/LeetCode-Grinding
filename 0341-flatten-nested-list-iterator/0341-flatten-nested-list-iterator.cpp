class NestedIterator {
public:
    
    vector<int> res; //store final result
    int idx=0; //store index
    
    void flattenList(vector<NestedInteger> &nestedList)
    {
        for(auto x:nestedList)
        {
            //if x is int then push it into the vector res
            if(x.isInteger())
            {
                res.push_back(x.getInteger());
            }
            
            //if x is list then call the flattenList function again
            else
            {
                flattenList(x.getList());
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) 
    {
        //call the flattenList function to make the 1d array of whole nestedList
        flattenList(nestedList);
        
    }
    
    int next() 
    {
        //return the value at index idx
        return res[idx++];   
    }
    
    bool hasNext() 
    {
        //check whether next elements is available or not by checking index value is less than res size
        return idx<res.size();   
    }
};