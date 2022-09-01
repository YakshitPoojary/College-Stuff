key=int(input("Enter key: "))
upperalpha="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
loweralpha="abcdefghijklmnopqrstuvwxyz"
num="0123456789"
p=str(input("Enter code to encrypt: "))

def encrypt(p):
    c=""
    for i in p:
        if i.isupper():
            b=upperalpha.index(i)
            if b+key<len(upperalpha):
                c+=upperalpha[b+key]
            else:
                c+=upperalpha[(b+key)-len(upperalpha)]
        elif i.islower():
            b=loweralpha.index(i)
            if b+key<len(loweralpha):
                c+=loweralpha[b+key]
            else:
                c+=loweralpha[(b+key)-len(loweralpha)]
        elif i.isnumeric():
            b=num.index(i)
            if b+key<len(num):
                c+=num[b+key]
            else:
                c+=num[(b+key)-len(num)]
        elif i==" ":
            c+=i
            
    return c

def decrypt(p):
    d=""
    for i in cipher:
        if i.isupper():
            a=upperalpha.index(i)
            if a-key<len(upperalpha) and a-key>=0:
                d+=upperalpha[a-key]
            else:
                d+=upperalpha[((a-key)+len(upperalpha))]
        elif i.islower():
            a=loweralpha.index(i)
            if a-key<len(loweralpha) and a-key>=0:
                d+=loweralpha[a-key]
            else:
                d+=loweralpha[((a-key)+len(loweralpha))]
        elif i.isnumeric():
            a=num.index(i)
            if a-key<len(num) and a-key>=0:
                d+=num[a-key]
            else:
                d+=num[((a-key)+len(num))]
        elif i==" ":
            d+=i
        
    return d
            
cipher=encrypt(p)
decipher = decrypt(cipher)
print(cipher)
print(decipher)