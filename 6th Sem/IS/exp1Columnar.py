def fillMatrix(keysize, plaintext):
    matrix = []
    row = []

    for i in range(len(plaintext)):
        row.append(plaintext[i])
        if (i + 1) % keysize == 0 or i == (len(plaintext) - 1):
            if(len(row)<keysize):
                for j in range(len(row),keysize):
                    row.append(" ")
                    i = i+1
            matrix.append(row)
            row = []

    remSpace = keysize - len(matrix)
    if(remSpace > 0):
        row = [" "] * keysize
        for i in range(0,remSpace):
            matrix.append(row)

    return matrix

def encrypt(keysize,matrix):
    sorted_key = ''.join(sorted(key))
    order_dict = {char: index for index, char in enumerate(key)}
    cipherText = ""

    for i in range(keysize):
        col = order_dict[sorted_key[i]]
        for j in range(0,keysize):
            cipherText += matrix[j][col]

    return cipherText

def decrypt(keysize, ciphertext):
    sorted_key = ''.join(sorted(key))
    order_dict = {char: index for index, char in enumerate(key)}
    num_rows = len(ciphertext) // keysize

    matrix = [[" " for _ in range(keysize)] for _ in range(num_rows)]

    index = 0
    for i in range(keysize):
        col = order_dict[sorted_key[i]]
        for j in range(num_rows):
            matrix[j][col] = ciphertext[index]
            index += 1
    plaintext = ""
    for i in range(num_rows):
        plaintext += ''.join(matrix[i])

    return plaintext.rstrip()



key = str(input("Enter Key: "))
plaintext = str(input("Enter Plaintext to be encrypted: "))
print("Your Plaintext was: " + "'"+plaintext+"'")

matrix = fillMatrix(len(key),plaintext)
print(matrix)

cipherText = encrypt(len(key),matrix)
print("Your Cipher text is: " + "'"+cipherText+"'")

decryptedText = decrypt(len(key), cipherText)
print("Your Decrypted text is: " + "'"+decryptedText+"'")