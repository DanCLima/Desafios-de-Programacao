def encontrar_maior(vetor):
    maior = -1

    for valor in vetor:
        if maior < valor:
            maior = valor

    return maior

def main():
    lin, vol = map(int, input().split())
    vetor = []

    for _ in range(lin):
        l, w, h = map(int, input().split())
        vetor.append(l * w * h)

    maior = encontrar_maior(vetor)
    print(maior - vol)

if __name__ == "__main__":
    main()