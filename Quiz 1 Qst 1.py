def remove_duplicates(nums):
    if not nums:
        return 0

    count = 1  # Initialize count to 1 since the first element is always unique

    for i in range(1, len(nums)):
        if nums[i] != nums[i - 1]:
            nums[count] = nums[i]
            count += 1

    return count

# Example:
nums = [1, 1, 2, 2, 3, 4, 4, 5]
new_length = remove_duplicates(nums)
print("Original array:", nums)
print("Modified array:", nums[:new_length])
