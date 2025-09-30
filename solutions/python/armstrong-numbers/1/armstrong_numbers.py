def is_armstrong_number(number):
    num_str = str(number)
    digits = list(map(int, num_str))
    num_of_digits = len(digits)
    total = 0

    for digit in digits:
        total += digit ** num_of_digits

    return total == number
