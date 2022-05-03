from prettytable import PrettyTable


class Solution:

    def __init__(self,spisk,U,I, n):
        self.spisk = spisk
        # Всі початкові значення таблиці, 6 елемент це середнє значення
        self.U = U
        self.I = I

        self.n = n

        self.R = [0,0,0,0,0,0]

        self.delta_R = [0,0,0,0,0,0]

        self.normalize()
        self.calc()
        self.round_values()
        self.print_table()





    ## Функція для обчислення значень (приватні функції)
    # find R = U/I
    def __findR(self):
        for i in range(5):
            self.R[i] = self.U[i]/self.I[i]
        self.R[5] = (self.R[0]+self.R[1]+self.R[2]+self.R[3]+self.R[4])/5

    # find delta R = R - R(n)
    def __findDeltaR(self):
        for i in range(5):
            self.delta_R[i] = abs(self.R[5] - self.R[i])
        self.delta_R[5] = (self.delta_R[0]+self.delta_R[1]+self.delta_R[2]+self.delta_R[3]+self.delta_R[4])/5


    ## Публічні функції
    # Провести розрахунки всієї таблиці
    def calc(self):
        self.__findR()
        self.__findDeltaR()

    # Переводимо всі значення під номер в списку значення = значення * (spisk/100) + значення
    def normalize(self):
        for i in range(5):
            self.U[i] = self.U[i] * (self.spisk/100) + self.U[i]
            self.I[i] = self.I[i] * (self.spisk/100) + self.I[i]

    # заокруглити всі значення до 4 знаків після коми
    def round_values(self):
        for i in range(5):
            self.U[i] = round(self.U[i],5)
            self.I[i] = round(self.I[i],5)
            self.R[i] = round(self.R[i],5)
            self.delta_R[i] = round(self.delta_R[i],5)
        self.R[5] = round(self.R[5],5)
        self.delta_R[5] = round(self.delta_R[5],5)


    # print table
    def print_table(self):
        f = open("table_variant" + str(self.spisk) + ".txt", 'a')
        table = PrettyTable()
        table.field_names = ["No", "U", "I", "R" + str(self.n), "delta R" + str(self.n)]
        for i in range(6):
            table.add_row([i+1 if i != 5 else "ser",self.U[i] if i != 5 else "---",self.I[i] if i != 5 else "---",self.R[i],self.delta_R[i]])
        print("\nTable "+ str(self.n) + ", variant " + str(self.spisk) + ":\n\n")
        print(table)
        print("\n\nRx"+str(self.n)+" = " + str(self.R[5]) + " +- " + str(self.delta_R[5]))
        print("E = " + str(round((self.delta_R[5]/self.R[5])*100,5)) + "%")
        text = "\nTable "+ str(self.n) + ", variant " + str(self.spisk) + ":\n\n"
        text += table.get_string()
        text += "\n\nRx"+str(self.n)+" = " + str(self.R[5]) + " +- " + str(self.delta_R[5])
        text += "\nE = " + str(round((self.delta_R[5]/self.R[5])*100,5)) + "%"
        f.write(text)


class Table2:
    def __init__(self,spisk,U,I, n, Rp):
        self.spisk = spisk
        self.Rp = Rp
        # Всі початкові значення таблиці, 6 елемент це середнє значення
        self.U = U
        self.I = I

        self.n = n

        self.Rpa = [0, 0, 0, 0, 0, 0]
        self.Rpo = [0, 0, 0, 0, 0, 0]

        self.delta_Rpa = [0, 0, 0, 0, 0, 0]
        self.delta_Rpo = [0, 0, 0, 0, 0, 0]

        self.normalize()
        if self.Rp == 1:
            self.__Rpo()
            self.__delt_Rpo()
            self.round_values()
            self.print_Rpo()
        else:
            self.__Rpa()
            self.__delt_Rpa()
            self.round_values()
            self.print_Rpa()

    # опір трьох резисторів в послідовному зєжнанні

    # Rpa = U/I
    def __Rpa(self):
        for i in range(5):
            self.Rpa[i] = self.U[i] / self.I[i]
        self.Rpa[5] = (self.Rpa[0] + self.Rpa[1] + self.Rpa[2] + self.Rpa[3] + self.Rpa[4]) / 5

    def __delt_Rpa(self):
        for i in range(5):
            self.delta_Rpa[i] = abs(self.Rpa[5] - self.Rpa[i])
        self.delta_Rpa[5] = (self.delta_Rpa[0] + self.delta_Rpa[1] + self.delta_Rpa[2] + self.delta_Rpa[3] + self.delta_Rpa[4]) / 5

    def __Rpo(self):
        for i in range(5):
            self.Rpo[i] = 1/(self.U[i] / self.I[i])
        self.Rpo[5] = (self.Rpo[0] + self.Rpo[1] + self.Rpo[2] + self.Rpo[3] + self.Rpo[4]) / 5

    def __delt_Rpo(self):
        for i in range(5):
            self.delta_Rpo[i] = abs(self.Rpo[5] - self.Rpo[i])
        self.delta_Rpo[5] = (self.delta_Rpo[0] + self.delta_Rpo[1] + self.delta_Rpo[2] + self.delta_Rpo[3] + self.delta_Rpo[4]) / 5


    def normalize(self):
        for i in range(5):
            self.U[i] = self.U[i] * (self.spisk/100) + self.U[i]
            self.I[i] = self.I[i] * (self.spisk/100) + self.I[i]

    def round_values(self):
        for i in range(5):
            self.U[i] = round(self.U[i],5)
            self.I[i] = round(self.I[i],5)
            self.Rpa[i] = round(self.Rpa[i],5)
            self.Rpo[i] = round(self.Rpo[i],5)
            self.delta_Rpa[i] = round(self.delta_Rpa[i],5)
            self.delta_Rpo[i] = round(self.delta_Rpo[i],5)
        self.Rpo[5] = round(self.Rpo[5],5)
        self.Rpa[5] = round(self.Rpa[5],5)
        self.delta_Rpo[5] = round(self.delta_Rpo[5],5)
        self.delta_Rpa[5] = round(self.delta_Rpa[5],5)

    def print_Rpa(self):
        f = open("table_variant" + str(self.spisk) + ".txt", 'a')
        table = PrettyTable()
        table.field_names = ["No", "U", "I", "Rpa" , "delta Rpa"]
        for i in range(6):
            table.add_row([i + 1 if i != 5 else "ser", self.U[i] if i != 5 else "---", self.I[i] if i != 5 else "---", self.Rpa[i],self.delta_Rpa[i]])
        print("\nTable " + str(self.n) + ", variant " + str(self.spisk) + ":\n\n")
        print(table)
        print("\n\nRpa" + " = " + str(self.Rpa[5]) + " +- " + str(self.delta_Rpa[5]))
        print("E = " + str(round((self.delta_Rpa[5] / self.Rpa[5]) * 100, 5)) + "%")
        text = "\nTable " + str(self.n) + ", variant " + str(self.spisk) + ":\n\n"
        text += table.get_string()
        text += "\n\nRx" + str(self.n) + " = " + str(self.Rpa[5]) + " +- " + str(self.delta_Rpa[5])
        text += "\nE = " + str(round((self.delta_Rpa[5] / self.Rpa[5]) * 100, 5)) + "%"
        f.write(text)

    def print_Rpo(self):
        f = open("table_variant" + str(self.spisk) + ".txt", 'a')
        table = PrettyTable()
        table.field_names = ["No", "U", "I", "Rpo" , "delta Rpo"]
        for i in range(6):
            table.add_row([i + 1 if i != 5 else "ser", self.U[i] if i != 5 else "---", self.I[i] if i != 5 else "---", self.Rpo[i],self.delta_Rpo[i]])
        print("\nTable " + str(self.n) + ", variant " + str(self.spisk) + ":\n\n")
        print(table)
        print("\n\nRpa" + " = " + str(self.Rpo[5]) + " +- " + str(self.delta_Rpo[5]))
        print("E = " + str(round((self.delta_Rpo[5] / self.Rpo[5]) * 100, 5)) + "%")
        text = "\nTable " + str(self.n) + ", variant " + str(self.spisk) + ":\n\n"
        text += table.get_string()
        text += "\n\nRx" + str(self.n) + " = " + str(self.Rpo[5]) + " +- " + str(self.delta_Rpo[5])
        text += "\nE = " + str(round((self.delta_Rpo[5] / self.Rpo[5]) * 100, 5)) + "%"
        f.write(text)



# main
if __name__ == "__main__":
    print("Version: 1.0")
    print("Введіть додатній номер списку щоб додати відсоток, та відємний щоб відняти відсоток від данних(якщо ви перший в списку, то впишіть 0)")
    spisk = int(input("Введіть ваш номер в списку: "))
    schem1 = Solution(spisk, [1.2,2,2.8,3.2,4], [0.32,0.56,0.7,0.81,1.1], 1)
    schem2 = Solution(spisk, [12,15,18,120,23], [0.12,0.16,0.179,0.199,0.23], 2)
    schem3 = Solution(spisk, [20,22.5,23.5,25.5,29], [20.1,18.75,20.09,21.07,24.19], 3)
    table1 = Table2(spisk, [20,25.5,30.5,35,40], [4,5.08,6.1,6.97,8], 1, 1)
    table2 = Table2(spisk, [20,25.5,30.5,35,40], [22.99,29.29,35.05,40.52,46], 2, 2)