// In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

// Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

// Given the integer array position and the integer m. Return the required force.

 

// Example 1:


// Input: position = [1,2,3,4,7], m = 3
// Output: 3
// Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.


class Solution {
public:

    int canPlace(vector<int> &positions,int dist )
    {
        int last = positions[0],ans=1;

        for(int i=1;i<positions.size();++i)
        {
            if(positions[i]>=last+dist)
            {
                ans++;
                last=positions[i];
            }
        }

        return ans;
    }
    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(),position.end());
        int low=0,high=position.back()-position.front(),res=-1;

        while(low<=high)
        {
            int mid = (high+low)/2;
            if(canPlace(position,mid)>=m)
            {
                low=mid+1;
                res=mid;
            }
            else
            {
                high=mid-1;
            }
        }

        return res;
        
    }
};