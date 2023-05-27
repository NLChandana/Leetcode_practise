/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

*/
//Method 1

class Solution {
    public int[] twoSum(int[] nums, int target) {
       Map<Integer,Integer> map=new HashMap<>();
       for(int i=0;i<nums.length;i++)
       {
           int current=nums[i];
           int sum=target-current;
           if(map.containsKey(sum))
           {
               return new int[] { map.get(sum),i};
           }
           map.put(current,i);
       } 
       return null;
    }
    
}


//Method 2
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int arr[]=new int[2];
        for(int i=0;i<(nums.length);i++)
        {
            int r=target-nums[i];
            arr[0]=i-1;
            for(int j=i+1;j<nums.length;j++)
            {
                if(r==nums[j])
                {
                    arr[1]=j;
                    break;
                }
            }
        } 
        //System.out.println(arr);
        return arr; 
    }
    
}
