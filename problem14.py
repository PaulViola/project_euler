# The following iterative sequence is defined for the set of positive integers:
# n -> n/2 (n is even)
# n -> 3n + 1 (n is odd)

# Starting with 13, we generate the following sequence:
# 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1

# Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

# Which starting number, under one million, produces the longest chain?

upper_limit = 1000000

def collatz_sequence_count(num, count):
    if num == 1:
        return count
    if num % 2 == 0:
        return collatz_sequence_count(num/2, count + 1)
    else:
       return collatz_sequence_count((3*num + 1), count+1)


def get_num_with_longest_chain(upper_limit):
    longest_chain = (1,1)
    for i in range(2, upper_limit):
        chain_length = collatz_sequence_count(i, 1)

        if chain_length > longest_chain[1]:
            longest_chain = (i, chain_length)
    return longest_chain

longest_chain_under_one_million = get_num_with_longest_chain(upper_limit)

print(longest_chain_under_one_million[0])