
import random

p = int(input('Enter a prime number : ')) 
g = int(input('Enter a number : '))


class A:
    def __init__ (self):
        self.n = random.randint(1, p)

    def publish(self):
        (g**self.n)%p

    def compute_secret(self, pub_B): 
        return (pub_B**self.n)%p


class B:
    def __init__ (self):
        self.a = random.randint(1, p)
        self.b = random.randint(1, p)
        self.arr = [self.a,self.b]

    def publish(self, i):
        return (g**self.arr[i])%p

    def compute_secret(self, pub_A, i): 
        return (pub_A**self.arr[i])%p


alice = A() 
bob = A()
eve = B()

print(f"Alice selected private key(a) : {alice.n}") 
print(f"Bob selected private key (b) : {bob.n}") 
print("\n")
print(f"Eve selected private key for Alice (c) : {eve.a}") 
print(f"Eve selected private key for Bob (d) : {eve.b}") 
print("\n")

pub_A = alice.publish() 
pub_B = bob.publish()
gea = eve.publish(0) 
geb = eve.publish(1)
print(f"Alice published public key (pub_A): {pub_A}") 
print(f"Bob published public key (pub_B): {pub_B}") 
print("\n")
print(f"Eve published key for Alice (gc): {gea}") 
print(f"Eve published key for Bob (gd): {geb}") 
print("\n")

# Computing the secret key
sec_A = alice.compute_secret(gea) 
sea = eve.compute_secret(pub_A,0) 
sb = bob.compute_secret(geb)
sec_B = eve.compute_secret(pub_B,1) 
print("Alice computed (S1) " + {sec_A})
print("Eve computed key for Alice (S1): " + {sea}) 
print("\n")
print("Bob computed (S2): "+{sb})
print("Eve computed key for Bob (S2): "+{sec_B})