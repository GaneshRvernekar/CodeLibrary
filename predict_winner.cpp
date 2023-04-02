// You are given an integer array nums. Two players are playing a game with this array: player 1 and player 2.

// Player 1 and player 2 take turns, with player 1 starting first. Both players start the game with a score of 0. At each turn, the player takes one of the numbers from either end of the array (i.e., nums[0] or nums[nums.length - 1]) which reduces the size of the array by 1. The player adds the chosen number to their score. The game ends when there are no more elements in the array.

// Return true if Player 1 can win the game. If the scores of both players are equal, then player 1 is still the winner, and you should also return true. You may assume that both players are playing optimally.


bool scores(vector<int>& nums, bool a_turn, int score_a,int score_b, int i,int j)
{
    if(i>j)
        return score_a>=score_b;
      
    if(a_turn)
        return scores(nums,false,score_a+nums[i],score_b,i+1,j)||scores(nums,false,score_a+nums[j],score_b,i,j-1);
        
    
         return scores(nums,true,score_a,score_b+nums[i],i+1,j)&&scores(nums,true,score_a,score_b+nums[j],i,j-1);
    
    
}
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return scores(nums,true,0,0,0,nums.size()-1);
    }
};