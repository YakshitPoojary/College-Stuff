import string

def create_playfair_matrix():
    alphabet = list(string.ascii_uppercase)
    alphabet.remove('J')
    key_matrix = []

    for i in range(0, len(alphabet), 5):
        key_matrix.append(alphabet[i:i+5])
    return key_matrix

def print_matrix(matrix):
    for row in matrix:
        print(" ".join(row))

def encrypt(plaintext, matrix):
    def find_position(char):
        for i, row in enumerate(matrix):
            if char in row:
                return i, row.index(char)

    def encrypt_pair(pair):
        if pair[0] == pair[1]:
            return pair[0] + 'X'
        else:
            row1, col1 = find_position(pair[0])
            row2, col2 = find_position(pair[1])

            if row1 == row2:
                return matrix[row1][(col1 + 1) % 5] + matrix[row2][(col2 + 1) % 5]
            elif col1 == col2:
                return matrix[(row1 + 1) % 5][col1] + matrix[(row2 + 1) % 5][col2]
            else:
                return matrix[row1][col2] + matrix[row2][col1]

    if len(plaintext) % 2 != 0:
        plaintext += 'X'

    plaintext = plaintext.upper().replace('J', 'I')
    plaintext_pairs = [plaintext[i:i+2] for i in range(0, len(plaintext), 2)]

    ciphertext = ''
    for pair in plaintext_pairs:
        ciphertext += encrypt_pair(pair)

    return ciphertext

plaintext = str(input("Enter your Plaintext: "))
playfair_matrix = create_playfair_matrix()
print_matrix(playfair_matrix)

ciphertext = encrypt(plaintext, playfair_matrix)
print("Ciphertext:", ciphertext)
