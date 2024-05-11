'''
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
product = 24
i = 0: product / nums[0]
i = 1: product / nums[1]
...

Input: nums = [-1,1,0,-3,3]
Output:       [0,0,9,0,0]


nums = [0 3 0 4 -6]
       [0 0 0 0 0]
'''

def productExceptSelf(self, nums: List[int]) -> List[int]:
    ans = [0] * len(nums)
    nuls = 0

    for i in nums:
        if i == 0:
            nuls += 1
        else:
            product *= i

    if nuls == 0:
        for i in range(len(nums)):
            ans[i] = int(product / nums[i])
    elif nuls == 1:
        ans[nums.index(0)] = product

    return ans
            