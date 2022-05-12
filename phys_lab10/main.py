from prettytable import PrettyTable

# class solution for the phisics table
# constructor takes 5 of Ce Ne N1 N2 N3 and one U
# we need to calculte C1 C2 C3 and all middle values
# C1 = Ce*(N1/Ne)
# table make with prettytable module
# print U then prettytable No Ce Ne N1 C1 N2 C2 N3 C3
# and create a file and print it to the file too
class Solution:
    def __init__(self, Ce, Ne, N1, N2, N3, U, spisk, number):
        self.number = number
        self.spisk = spisk

        self.Ce = Ce
        self.Ne = Ne
        self.N1 = N1
        self.N2 = N2
        self.N3 = N3
        self.U = U

        self.C1 = [0, 0, 0, 0, 0, 0]
        self.C2 = [0, 0, 0, 0, 0, 0]
        self.C3 = [0, 0, 0, 0, 0, 0]

        self.delta_C1 = [0, 0, 0, 0, 0, 0]
        self.delta_C2 = [0, 0, 0, 0, 0, 0]
        self.delta_C3 = [0, 0, 0, 0, 0, 0]

        self.normalize()
        self.calc_C()
        self.middle_values()
        self.calc_delta_C()
        self.round_values()
        self.print_table()

    def calc_C(self):
        for i in range(5):
            self.C1[i] = self.Ce[i] * (self.N1[i] / self.Ne[i])
            self.C2[i] = self.Ce[i] * (self.N2[i] / self.Ne[i])
            self.C3[i] = self.Ce[i] * (self.N3[i] / self.Ne[i])

    def middle_values(self):
        # every element[5] = (element1 + element2 + element3 + element4 + element5) / 5
        self.Ce[5] = (self.Ce[0] + self.Ce[1] + self.Ce[2] + self.Ce[3] + self.Ce[4]) / 5
        self.Ne[5] = (self.Ne[0] + self.Ne[1] + self.Ne[2] + self.Ne[3] + self.Ne[4]) / 5
        self.N1[5] = (self.N1[0] + self.N1[1] + self.N1[2] + self.N1[3] + self.N1[4]) / 5
        self.C1[5] = (self.C1[0] + self.C1[1] + self.C1[2] + self.C1[3] + self.C1[4]) / 5
        self.N2[5] = (self.N2[0] + self.N2[1] + self.N2[2] + self.N2[3] + self.N2[4]) / 5
        self.C2[5] = (self.C2[0] + self.C2[1] + self.C2[2] + self.C2[3] + self.C2[4]) / 5
        self.N3[5] = (self.N3[0] + self.N3[1] + self.N3[2] + self.N3[3] + self.N3[4]) / 5
        self.C3[5] = (self.C3[0] + self.C3[1] + self.C3[2] + self.C3[3] + self.C3[4]) / 5

    def calc_delta_C(self):
        for i in range(5):
            self.delta_C1[i] = abs(self.C1[5] - self.C1[i])
            self.delta_C2[i] = abs(self.C2[5] - self.C2[i])
            self.delta_C3[i] = abs(self.C3[5] - self.C3[i])
        self.delta_C1[5] = (self.delta_C1[0] + self.delta_C1[1] + self.delta_C1[2] + self.delta_C1[3] + self.delta_C1[4]) / 5
        self.delta_C2[5] = (self.delta_C2[0] + self.delta_C2[1] + self.delta_C2[2] + self.delta_C2[3] + self.delta_C2[4]) / 5
        self.delta_C3[5] = (self.delta_C3[0] + self.delta_C3[1] + self.delta_C3[2] + self.delta_C3[3] + self.delta_C3[4]) / 5

    def normalize(self):
        for i in range(5):
            self.Ce[i] = self.Ce[i] * (self.spisk / 100) + self.Ce[i]
            self.Ne[i] = self.Ne[i] * (self.spisk / 100) + self.Ne[i]
            self.N1[i] = self.N1[i] * (self.spisk / 100) + self.N1[i]
            self.N2[i] = self.N2[i] * (self.spisk / 100) + self.N2[i]
            self.N3[i] = self.N3[i] * (self.spisk / 100) + self.N3[i]
        self.U = self.U * (self.spisk / 100) + self.U

        # заокруглити всі значення до 4 знаків після коми

    def round_values(self):
        for i in range(5):
            self.Ce[i] = round(self.Ce[i], 4)
            self.Ne[i] = round(self.Ne[i], 4)
            self.N1[i] = round(self.N1[i], 4)
            self.C1[i] = round(self.C1[i], 4)
            self.N2[i] = round(self.N2[i], 4)
            self.C2[i] = round(self.C2[i], 4)
            self.N3[i] = round(self.N3[i], 4)
            self.C3[i] = round(self.C3[i], 4)
        self.U = round(self.U, 4)
        self.Ce[5] = round(self.Ce[5], 4)
        self.Ne[5] = round(self.Ne[5], 4)
        self.N1[5] = round(self.N1[5], 4)
        self.C1[5] = round(self.C1[5], 4)
        self.N2[5] = round(self.N2[5], 4)
        self.C2[5] = round(self.C2[5], 4)
        self.N3[5] = round(self.N3[5], 4)
        self.C3[5] = round(self.C3[5], 4)

    def print_table(self):
        table = PrettyTable(['No', 'Ce', 'Ne', 'N1', 'C1', 'N2', 'C2', 'N3', 'C3'])
        for i in range(6):
            table.add_row(
                [i + 1 if i != 5 else "ser", self.Ce[i], self.Ne[i], self.N1[i], self.C1[i], self.N2[i], self.C2[i],
                 self.N3[i], self.C3[i]])
        text = "Table " + str(self.number) + " variant " + str(self.spisk) + "\n\n"
        text += "U= " + str(self.U) + "\n"
        text += table.get_string()
        text += "\n\n"
        text += "C1= " + str(self.C1[5]) + " +- " + str(round(self.delta_C1[5],4)) + "\n"
        text += "C1 E= " + str(round((self.delta_C1[5]/self.C1[5])*100,4)) + "%\n"
        text += "C2= " + str(self.C2[5]) + " +- " + str(round(self.delta_C2[5],4)) + "\n"
        text += "C2 E= " + str(round((self.delta_C2[5] / self.C2[5]) * 100, 4)) + "%\n"
        text += "C3= " + str(self.C3[5]) + " +- " + str(round(self.delta_C3[5],4)) + "\n"
        text += "C3 E= " + str(round((self.delta_C3[5] / self.C3[5]) * 100, 4)) + "%\n"
        print(text)

        f = open("Table" + str(self.number),"w")
        f.write(text)
        f.close()

class Table2:
    def __init__(self, Ce, Ne, N1, N2, U, spisk):
        self.spisk = spisk

        self.Ce = Ce
        self.Ne = Ne
        self.N1 = N1
        self.N2 = N2
        self.U = U

        self.C1 = [0, 0, 0, 0, 0, 0]
        self.C2 = [0, 0, 0, 0, 0, 0]

        self.delta_C1 = [0, 0, 0, 0, 0, 0]
        self.delta_C2 = [0, 0, 0, 0, 0, 0]

        self.normalize()
        self.calc_C()
        self.middle_values()
        self.calc_delta_C()
        self.round_values()
        self.print_table()

    def calc_C(self):
        for i in range(5):
            self.C1[i] = self.Ce[i] * (self.N1[i] / self.Ne[i])
            self.C2[i] = 1/(self.Ce[i] * (self.N2[i] / self.Ne[i]))

    def middle_values(self):
        # every element[5] = (element1 + element2 + element3 + element4 + element5) / 5
        self.Ce[5] = (self.Ce[0] + self.Ce[1] + self.Ce[2] + self.Ce[3] + self.Ce[4]) / 5
        self.Ne[5] = (self.Ne[0] + self.Ne[1] + self.Ne[2] + self.Ne[3] + self.Ne[4]) / 5
        self.N1[5] = (self.N1[0] + self.N1[1] + self.N1[2] + self.N1[3] + self.N1[4]) / 5
        self.C1[5] = (self.C1[0] + self.C1[1] + self.C1[2] + self.C1[3] + self.C1[4]) / 5
        self.N2[5] = (self.N2[0] + self.N2[1] + self.N2[2] + self.N2[3] + self.N2[4]) / 5
        self.C2[5] = (self.C2[0] + self.C2[1] + self.C2[2] + self.C2[3] + self.C2[4]) / 5

    def calc_delta_C(self):
        for i in range(5):
            self.delta_C1[i] = abs(self.C1[5] - self.C1[i])
            self.delta_C2[i] = abs(self.C2[5] - self.C2[i])
        self.delta_C1[5] = (self.delta_C1[0] + self.delta_C1[1] + self.delta_C1[2] + self.delta_C1[3] + self.delta_C1[4]) / 5
        self.delta_C2[5] = (self.delta_C2[0] + self.delta_C2[1] + self.delta_C2[2] + self.delta_C2[3] + self.delta_C2[4]) / 5

    def normalize(self):
        for i in range(5):
            self.Ce[i] = self.Ce[i] * (self.spisk / 100) + self.Ce[i]
            self.Ne[i] = self.Ne[i] * (self.spisk / 100) + self.Ne[i]
            self.N1[i] = self.N1[i] * (self.spisk / 100) + self.N1[i]
            self.N2[i] = self.N2[i] * (self.spisk / 100) + self.N2[i]
        self.U = self.U * (self.spisk / 100) + self.U

        # заокруглити всі значення до 4 знаків після коми

    def round_values(self):
        for i in range(5):
            self.Ce[i] = round(self.Ce[i], 4)
            self.Ne[i] = round(self.Ne[i], 4)
            self.N1[i] = round(self.N1[i], 4)
            self.C1[i] = round(self.C1[i], 4)
            self.N2[i] = round(self.N2[i], 4)
            self.C2[i] = round(self.C2[i], 4)
        self.U = round(self.U, 4)
        self.Ce[5] = round(self.Ce[5], 4)
        self.Ne[5] = round(self.Ne[5], 4)
        self.N1[5] = round(self.N1[5], 4)
        self.C1[5] = round(self.C1[5], 4)
        self.N2[5] = round(self.N2[5], 4)
        self.C2[5] = round(self.C2[5], 4)

    def print_table(self):
        table = PrettyTable(['No', 'Ce', 'Ne', 'N1', 'C1', 'N2', 'C2'])
        for i in range(6):
            table.add_row(
                [i + 1 if i != 5 else "ser", self.Ce[i], self.Ne[i], self.N1[i], self.C1[i], self.N2[i], self.C2[i]])
        text = "Table22" + " variant " + str(self.spisk) + "\n\n"
        text += "U= " + str(self.U) + "\n"
        text += table.get_string()
        text += "\n\n"
        text += "C1= " + str(self.C1[5]) + " +- " + str(round(self.delta_C1[5], 4)) + "\n"
        text += "C1 E= " + str(round((self.delta_C1[5] / self.C1[5]) * 100, 4)) + "%\n"
        text += "C2= " + str(self.C2[5]) + " +- " + str(round(self.delta_C2[5], 4)) + "\n"
        text += "C2 E= " + str(round((self.delta_C2[5] / self.C2[5]) * 100, 4)) + "%\n"
        print(text)

        f = open("Table22", "w")
        f.write(text)
        f.close()


print("Version: 1.0")
print("Введіть додатній номер списку щоб додати відсоток, та відємний щоб відняти відсоток від данних(якщо ви перший в списку, то впишіть 0)")
spisk = int(input("Введіть ваш номер в списку: "))

table1 = Solution([0.1,0.1,0.5,1,2,0],[5,6,15,40,65,0],[7,11,25,35,45,0],[10,15,20,42,55,0],[6,12,35,32,60,0],20, spisk, 1)
table2 = Solution([0.1,0.5,0.9,1.2,1.5,0],[5,15,38,40,45,0],[7,25,32,42,48,0],[10,20,40,45,45,0],[6,35,30,47,50,0],100, spisk, 2)
table3 = Solution([0.1,0.7,0.9,1,2,0],[5,17,38,40,65,0],[7,27,32,35,45,0],[10,25,40,42,55,0],[6,37,30,32,60,0],35, spisk, 3)
Table = Table2([0.1,0.3,0.6,1,1.2,0],[5,8,10,35,40,0],[7,10,14,40,42,0],[9,12,16,42,45,0],35, spisk)
