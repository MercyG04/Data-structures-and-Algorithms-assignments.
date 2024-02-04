def rotate(nums, k):
    if not nums or k <= 0:
        return

    n = len(nums)
    k %= n  # Calculate the effective rotation index

    # Helper function to reverse a portion of the array
    def reverse(start, end):
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1

    # Reverse the entire array
    reverse(0, n - 1)

    # Reverse the first k elements
    reverse(0, k - 1)

    # Reverse the remaining elements after the first k elements
    reverse(k, n - 1)

# Example:
nums = [1, 2, 3, 4, 5, 6, 7]
k = 4
rotate(nums, k)
print("Rotated array:", nums)
