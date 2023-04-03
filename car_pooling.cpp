// There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

// You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

// Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.


// Example 1:

// Input: trips = [[2,1,5],[3,3,7]], capacity = 4
// Output: false

class Solution {
public:

    static bool comp(vector<int> &a,vector<int> &b)
    {
        return a[2]<b[2];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        sort(trips.begin(),trips.end(),comp);

        int n=trips.size();

        int m= trips[n-1][2];
      

        vector<int> buff(m+1,0);

        for(int i=0;i<n;i++)
        {
            for(int j=trips[i][1];j<trips[i][2];j++)
            {
                buff[j]+=trips[i][0];
                if(buff[j]>capacity)
                {
                    return false;
                }
            }
            
        }

        return true;        
    }
};