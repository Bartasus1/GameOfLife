def blad(file):
    f = open(file, "r")
    dane = f.readlines()
    N = len(dane)
    f.close()
    
    srednia = 0
    for x in dane:
        srednia += float(x)
    srednia = srednia / N

    odchylenie = 0
    for x in dane:
        odchylenie += (float(x) - srednia)**2

    odchylenie = (odchylenie / (N-1))**(1/2)

    blad_standardowy = odchylenie / (N**(1/2))

    return blad_standardowy



name = "size"
number = [10, 100, 200, 500, 1000]

error = []
for i in number:
    filename = name + str(i) + ".txt"
    error.append(blad(filename))


f = open("output.txt", "w+")
for i in range(len(error)):
    f.write("Błąd standardowy średniej dla size" + str(number[i]) + ": " + str(error[i]) + "\n")
    
f.close()
