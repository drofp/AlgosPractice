
def twoSum(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    
    # for i in range(len(nums)):
    #     for j in range(i+1, len(nums)):
    #         if(nums[i] + nums[j] == target):
    #             return [nums[i], nums[j]]

    dictionary = {}
    result = [None, None]

    for i in range(len(nums)):
        if dictionary.get(target - nums[i]) != None:
            result[1] = i
            result[0] = dictionary[target - nums[i]]
            return result
        dictionary[nums[i]] = i
    
    return result

if __name__ == '__main__':
    print(twoSum([3,3], 6))