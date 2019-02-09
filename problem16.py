# 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
# What is the sum of the digits of the number 2^1000?

# completed
import math
def find_sum_of_digits(base, power):
    number = base**power
    length = len(str(number))
    digit_position = 10
    sum = 0
    for x in range(0,length):
        current_digit = math.floor((number % digit_position) / ( digit_position / 10))
        number -= current_digit
        digit_position *= 10
        sum += current_digit
    return sum

sum = find_sum_of_digits(2, 1000)
print(sum)