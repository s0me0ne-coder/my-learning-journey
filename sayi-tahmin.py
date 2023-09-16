import random

cevap = random.randrange(101)

hak = int(input("Kaç hak istersiniz").strip())
can = hak

while can >= 0:
    try:
        tahmin = int(input("0-100 arası sayıyı tahmin ediniz: ").strip())
        if tahmin > 100 or tahmin < 0:
            print("geçersiz sayı, birdaha deneyiniz")
            continue
    except ValueError:
        print("geçersiz sayı, birdaha deneyiniz")
        continue
    if tahmin == cevap:
        break
    elif tahmin > cevap:
        print("aşağıda")
    elif tahmin < cevap:
        print("yukarda")
    
    can -= 1

if can > 0:
    print(f"{hak - can} denemede bildiniz")
    print(f"Puanınız: {can * (100 / hak)}")
else:
    print(f"bilemediniz, sayı {cevap} olacaktı")
