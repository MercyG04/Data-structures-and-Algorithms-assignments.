def contains_duplicate(nums):
    seen_set = set()

    for num in nums:
        if num in seen_set:
            return True
        seen_set.add(num)

    return False

# Example:
first_set = [1, 2, 3, 4, 5, 1]
second_set = [6, 7, 8, 9, 10]

result_with_duplicates = contains_duplicate(first_set)
result_without_duplicates = contains_duplicate(second_set)

print("Array with duplicates:", result_with_duplicates)
print("Array without duplicates:", result_without_duplicates)
