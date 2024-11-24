import subprocess
from typing import final

subprocess.run("chcp 1257", shell=True)

LT_ABC_ARRAY = ['A', 'Ą', 'B', 'C', 'Č', 'D', 'E', 'Ę', 'Ė', 'F',
                'G', 'H', 'I', 'Į', 'Y', 'J', 'K', 'L', 'M',
                 'N', 'O', 'P', 'R', 'S', 'Š', 'T', 'U', 'Ų',
                 'Ū', 'V', 'Z', 'Ž' ]

def IsUsingAllowedSymbols(encoding, Array):
    Array_Length = len(Array)
    if encoding == 1:
        x = 0
        Encoding_Length = len(LT_ABC_ARRAY)
        for i in range(0, Array_Length):
            for j in range(0, Encoding_Length):
                if Array[i] == LT_ABC_ARRAY[j]:
                    x+=1
        return x == Array_Length

    elif encoding == 2:
        total = 0
        for xd in range(0, Array_Length):
            if 33 <= ord(Array[xd]) <= 126:
                total+=1
        return total == Array_Length

    else:
        print('[KLAIDA]: Function IsUsingAllowedSymbols, encoding is neither 1 nor 2\n')
        return False

def Encrypt(encoding, P, R, Final_Array, abc_letter_count):
    Array_Length = len(P)
    match encoding:
        case 1:
            M,K = 0, 0
            Final_Array = [0] * Array_Length
            for i in range(Array_Length):
                for j in range(abc_letter_count):
                    if LT_ABC_ARRAY[j] == P[i]: M = j
                    if LT_ABC_ARRAY[j] == R[i]: K = j
                final_number = (M+K) % abc_letter_count
                Final_Array[i] = LT_ABC_ARRAY[final_number]
        case 2:
            Final_Array.clear()
            for i in range(Array_Length):
                A_P = ord(P[i])
                A_R = ord(R[i])

                if 33 <= A_P <= 126 and 33 <= A_R <= 126:
                    result = (A_P + A_R) % abc_letter_count
                if result < 33:
                    result += abc_letter_count
                Final_Array.append(result)
        case _:
            print('[KLAIDA]: Encrypt encoding unequal 1 nor 2\n')
            return

    print('Užšifruotas žodis: ')
    for al in range (Array_Length):
        if encoding == 1:
            print(Final_Array[al], end='')
        elif encoding == 2:
            print(chr(Final_Array[al]), end='')
        else:
            print('[KLAIDA]: Encrypt encoding unequal 1 nor 2.\n')
            return
    print('\n')

def Decrypt(encoding, P, R, Final_Array, abc_letter_count):
    Array_Length = len(P)
    C, K = 0, 0
    match encoding:
        case 1:
            Final_Array = [''] * Array_Length
            for i in range(Array_Length):
                for j in range(abc_letter_count):
                    if LT_ABC_ARRAY[j] == P[i]: C = j
                    if LT_ABC_ARRAY[j] == R[i]: K = j

                final_number = (C-K) + (abc_letter_count % abc_letter_count)

                if final_number < 0: final_number = abc_letter_count+final_number
                Final_Array[i] = LT_ABC_ARRAY[final_number]
        case 2:
            Final_Array = []
            for i in range(Array_Length):
                A_P = ord(P[i])
                A_R = ord(R[i])

                if 33 <= A_P <= 126 and 33 <= A_R <= 126:
                    result = (A_P - A_R + abc_letter_count) % abc_letter_count
                    Final_Array.append(result)

                if Final_Array[i] < 33:
                    result += abc_letter_count
                    Final_Array[i] = result
        case _:
            print('[KLAIDA]: Decrypt encoding unequal 1 nor 2')
            return

    print('Dešifruotas žodis: ')
    for zx in range(Array_Length):
        if encoding == 1:
            print(Final_Array[zx], end='')

        elif encoding == 2:
            print(chr(Final_Array[zx]), end = '')

        else:
            print('[KLAIDA]: Decrypt encoding unequal 1 nor 2\n')
            return

    print('\n')

def main():

    while True:
        try:
            print('Šifravimo / dešifravimo sistema')
            menu_choice = int(input('Pasirinkite: \n1 - Užšifruoti tekstą \n2 - Dešifruoti tekstą\n3 - Išeiti iš programos\n ĮVEDIMAS:'))

            if menu_choice > 3 or menu_choice < 1:
                print('[KLAIDA]: Privalote pasirinkti tarp [1-3]\n')
                continue

            if menu_choice == 3:
                print('[INFO]: Pasirinkote išeiti iš programos')
                break
        except ValueError:
            print('Privalote pasirinkti tarp [1-3]:')
            continue

        while True:
            try:
                encoding = int(input('» Pasirinkite: \n1 - LT abėcėlė\n2 - ASCII koduotė\n» ĮVEDIMAS: '))

                if encoding > 2 or encoding < 1:
                    print('[KLAIDA]: Privalote pasirinkti tarp [1-2]\n')
                    continue

                abc_letter_count = 0  # Abėcėlės ilgis (kiek iš viso simbolių)

                match encoding:
                    case 1:
                        abc_letter_count = len(LT_ABC_ARRAY)
                    case 2:
                        abc_letter_count = 93
                    case _:
                        print('[KLAIDA]: switch(encoding) - default case fault\n')

                while True:
                    P = input(
                        '» Įveskite pradinį tekstą:\n\t• Pradinis tekstas negali būti ilgesnis nei 25 simboliai\n\t'
                        '• Negali būti trumpesnis nei 1 simbolis\n\t'
                        '• Gali būti sudarytas tik iš abėcėlėje esančių simbolių\n'
                        '» ĮVEDIMAS: ')

                    if not encoding == 2:
                        P = P.upper()

                    len_p = len(P)

                    if not IsUsingAllowedSymbols(encoding, P) or len_p > 25 or len_p < 1:
                        P = ""
                        print('[KLAIDA]: Pradinis tekstas neatitinka vieno iš reikalavimų')
                        continue

                    while True:
                        R = [0]
                        R = input('» Įveskite raktą:\n\t'
                                  '• Raktas negali būti ilgesnis nei pradinis tekstas\n\t'
                                  '• Negali būti trumpesnis nei 1 simbolis\n\t'
                                  '• Gali būti sudarytas tik iš abėcėlėje esančių simbolių\n'
                                  '» ĮVEDIMAS: ')

                        if encoding == 1:
                            R = R.upper()

                        len_r = len(R)

                        if not IsUsingAllowedSymbols(encoding, R) or len_r > len_p or len_r < 1:
                            R = ""
                            print('[KLAIDA]: Raktas neatitinka vieno iš reikalavimų\n')
                            continue

                        if (len_r < len_p):
                            R = list(R)
                            x = 0
                            for i in range(len_r, len_p):
                                R.append(R[x])
                                x = (x + 1) % len_r

                        G = [0]

                        match menu_choice:
                            case 1:
                                Encrypt(encoding, P, R, G, abc_letter_count)
                            case 2:
                                Decrypt(encoding, P, R, G, abc_letter_count)

                        break
                    break
                break
            except ValueError:
                print('[KLAIDA]: Privalote pasirinkti tarp [1-2]\n')
                continue



if __name__ == '__main__':
    main()