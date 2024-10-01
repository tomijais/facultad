def msd_radix_sort(strings, position=0):
    if len(strings) <= 1:
        return strings
    
    buckets = [[] for _ in range(257)]

    for word in strings:
        if position < len(word):
            char = ord(word[position])
            buckets[char + 1].append(word)
        else:
            buckets[0].append(word)

    sorted_strings = []

    for i in range(257):
        if buckets[i]:
            sorted_strings.extend(msd_radix_sort(buckets[i], position + 1))

    return sorted_strings

strings = ["apple", "banana", "apricot", "grape", "kiwi", "blueberry"]
sorted_strings = msd_radix_sort(strings)
print(sorted_strings)