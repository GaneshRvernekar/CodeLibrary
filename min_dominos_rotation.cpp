// In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

// We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

// Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

// If it cannot be done, return -1.

 

// Example 1:


// Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
// Output: 2
// Explanation: 
// The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
// If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.


class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {

        int ans =INT_MAX;

        for(int i=1;i<7;i++)
        {
            int b =count(bottoms.begin(),bottoms.end(),i);
            int t =count(tops.begin(),tops.end(),i);
            cout<<b+t<<endl;
            if(b+t>=2)
            {
                int cnt=0;
                int j=0;
                if(b>t)
                {
                    for(;j<bottoms.size();j++)
                    {
                        
                        if(bottoms[j]!=i && tops[j] == i)
                        {
                            
                            cnt++;
                        }
                        else if(bottoms[j]!=i && tops[j] != i)
                        {
                            break;
                        }
                    }

                }
                else
                {
                    for(;j<tops.size();j++)
                    {
                        if( tops[j] != i && bottoms[j]==i )
                        {
                            cnt++;
                            cout<<j;
                        }
                        else if( tops[j] != i && bottoms[j]!=i )
                        {
                            break;
                        }
                    }
                }

                if(j==bottoms.size())
                {
                    // cout<<i<<" "<<cnt<<endl;
                    ans =min(cnt,ans);
                }
            }

        }

        if(ans>=INT_MAX)
        {
            return -1;
        }
        else
        {
            return ans;
        }
        
    }
};