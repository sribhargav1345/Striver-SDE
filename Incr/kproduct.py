def gett(k):
    place = min(6, k)  # maximum number of digits that will be greater than 1
    have = 9 ** place  # This is the max product

    summ = place * 9 + (k - place)  # Max sum which can be obtained

    # Adjust 'have' and 'summ' until 'have < summ'
    while have >= summ:
        have //= 9
        summ -= 9
        summ += 1

    have *= 9  # Because here, have < sum
    summ += (9 - 1)

    s = ['1'] * k  # Initialize the string as all '1's

    have2 = have
    i = 0

    # Set digits to '9' as long as possible
    while have2 >= 9:
        s[i] = '9'
        have2 //= 9
        i += 1

    i = 0
    sum2 = summ

    # Adjust digits from '9' downward to meet conditions
    while s[i] == '9':
        dig = 9
        for j in range(1, 10):
            have2 = (have // 9) * j
            sum2 = summ - 9 + j

            if have2 >= sum2:
                have = have2
                summ = sum2
                dig = j
                break
        s[i] = str(dig)
        i += 1

    s.sort()
    return ''.join(s)


if __name__ == "__main__":
    k = int(input("Enter the value of k: "))
    print(gett(k))
