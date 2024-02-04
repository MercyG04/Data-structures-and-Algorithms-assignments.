#implementing XOR addition 

def single_number(nums):
    result = 0

    for num in nums:
        result ^= num

    return result

# Example:
nums = [4, 3, 2, 1, 2, 3, 1]
result = single_number(nums)

print("The single number is:", result)
