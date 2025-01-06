
def radix_sort(data):
    max_val = max(data)
    exp = 1
    while max_val // exp > 0:
        counting_sort(data, exp)
        exp *= 10

def counting_sort(data, exp):
    output = [0] * len(data)
    count = [0] * 10

    for num in data:
        index = num // exp
        count[index % 10] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    for num in reversed(data):
        index = num // exp
        output[count[index % 10] - 1] = num
        count[index % 10] -= 1

    for i in range(len(data)):
        data[i] = output[i]

# Example usage
if __name__ == "__main__":
    auction_data = [121, 432, 564, 23, 1, 450, 312]
    print("Before sorting:", auction_data)
    radix_sort(auction_data)
    print("After sorting:", auction_data)
