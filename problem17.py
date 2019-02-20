# If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

# If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

from math import floor

# when given a ones value, returns the number of letters in the val
# for example get_ones_val(5) returns 4 one for each letter in the word five
def get_ones_val(number):
    switcher = {
        9: 4,
        8: 5,
        7: 5,
        6: 3,
        5: 4,
        4: 4,
        3: 5,
        2: 3,
        1: 3,
        0: 0,
    }
    return switcher.get(number, "Not Found")

# when given a special tens value (10-19), returns the number of letters in the val
# for example get_special_ones_and_tens(15) returns 7 one for each letter in the word fifteen
def get_special_ones_and_tens(number):
    switcher = {
        10: 3,
        11: 6,
        12: 6,
        13: 8,
        14: 8,
        15: 7,
        16: 7,
        17: 9,
        18: 8,
        19: 8
    }
    return switcher.get(number, "Not Found")

# when given a tens value above 19, returns the number of letters in the val
# for example get_tens_above_nineteen(30) returns 6 one for each letter in the word thirteen
def get_tens_above_nineteen(number):
    switcher = {
        20: 6,
        30: 6,
        40: 5,
        50: 5,
        60: 5,
        70: 7,
        80: 6,
        90: 6
    }
    return switcher.get(number, "Not Found")

# when given a hundreds value, returns the number of letters in the val
# for example get_hundreds(200) returns 9 one for each letter in the words two hundred
def get_hundreds(number):
    hundred = 7
    number_of_hundreds = floor(number/100)
    return hundred + get_ones_val(number_of_hundreds)

def get_thousand(number):
    return 11# one thousand

def sum_for_hundreds(number):

    sum = 0
    sum += get_hundreds(number)
    remainder_from_100 = number % 100
    if number % 100 > 0:
        sum+=3

    if remainder_from_100 > 9 and remainder_from_100 < 20:
        return sum + get_special_ones_and_tens(remainder_from_100)
    tens = floor(remainder_from_100 / 10) * 10
    if(tens != 0):
        sum += get_tens_above_nineteen(tens)
    sum += get_ones_val(remainder_from_100 % 10)
    return sum

def sum_for_tens(number):
    sum = 0
    if number > 9 and number < 20:
        return sum + get_special_ones_and_tens(number)
    tens = floor(number / 10) * 10
    sum += get_tens_above_nineteen(tens)
    sum += get_ones_val(number % 10)
    return sum

def sum_for_num(number):
    if floor(number / 1000) > 0:
        return get_thousand(number)
    elif floor(number / 100) > 0:
        return sum_for_hundreds(number)
    elif number > 9:
        return sum_for_tens(number)
    elif number <= 9:
        return get_ones_val(number)
    return 0

def find_number_letter_counts(start, stop):
    sum = 0
    for i in range(start, stop+1):
        sum += sum_for_num(i)
    return sum
one_to_one_thousand_letter_count = find_number_letter_counts(1, 1000)
print(one_to_one_thousand_letter_count)
