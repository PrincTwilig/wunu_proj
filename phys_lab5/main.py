from prettytable import PrettyTable
import matplotlib.pyplot as plt
import numpy as np
from scipy import interpolate


class Solution:

    def __init__(self,spisk):
        self.spisk = spisk
        # Всі початкові значення таблиці, 6 елемент це середнє значення
        self.v = [275,197,111,55,49,0]
        self.F = [0.4,0.3,0.4,0.3,0.4,0]
        self.fF = [0,0,0,0,0,0]
        self.d1 = [610,300,195,140,145,0]
        self.d2 = [0,310,205,170,155,0]
        self.d3 = [0,0,200,145,165,0]
        self.d4 = [0,0,0,135,155,0]
        self.d = 0.61
        self.alfa = 0
        self.V = [0,0,0,0,0,0]

        self.X = np.array([self.fF[0], self.fF[1], self.fF[2], self.fF[3], self.fF[4]])
        self.Y = np.array([self.v[0], self.v[1], self.v[2], self.v[3], self.v[4]])

        self.m = 0 # масса одиниці струни

        # Значення похибок
        self.delta_V = [0,0,0,0,0,0]




    ## Функція для обчислення значень (приватні функції)
    # find alfa = 2*d
    def __find_alfa(self):
        self.alfa = 2*self.d

    # find V = alfa*v
    def __find_V(self):
        for i in range(5):
            self.V[i] = self.alfa*self.v[i]

    # корінь fF= sqrt(F)
    def __find_fF(self):
        for i in range(5):
            self.fF[i] = np.sqrt(self.F[i])

    # малюємо таблицю
    def __draw_table(self):
        smooth = 200  # значення плавності ліній
        smoth = False  # true - лінії будуть плавні між собою
        X = np.array([self.fF[0], self.fF[1]+0.000001, self.fF[2]+0.000002, self.fF[3]+0.000003, self.fF[4]+0.000004])
        Y = np.array([self.v[0], self.v[1], self.v[2], self.v[3], self.v[4]])
        # інтерполяція для плавності ліній
        f = interpolate.interp1d(X, Y, kind=2)
        x1 = np.linspace(X.min(), X.max(), smooth)

        plt.xlabel("√F")
        plt.ylabel("v")
        if smoth:
            plt.plot(X, Y, "o", x1, f(x1), "-")
        else:
            plt.plot(X, Y)

    # маса одиниці струни m = (F/V^2)*d
    def __find_m(self):
        self.m = (self.F[5]/self.V[5]**2)*self.d

    # find delta_V = V[5] - V[i] в модулі
    def __find_delta_V(self):
        for i in range(5):
            self.delta_V[i] = abs(self.V[5] - self.V[i])
        self.delta_V[5] = (self.delta_V[0] + self.delta_V[1] + self.delta_V[2] + self.delta_V[3] + self.delta_V[4]) / 5



    # find average value
    def __find_average(self):
        self.v[5] = (self.v[0] + self.v[1] + self.v[2] + self.v[3] + self.v[4])/5
        self.F[5] = (self.F[0] + self.F[1] + self.F[2] + self.F[3] + self.F[4])/5
        self.fF[5] = (self.fF[0] + self.fF[1] + self.fF[2] + self.fF[3] + self.fF[4])/5
        self.d1[5] = (self.d1[0] + self.d1[1] + self.d1[2] + self.d1[3] + self.d1[4])/5
        self.d2[5] = (self.d2[1] + self.d2[2] + self.d2[3] + self.d2[4])/4
        self.d3[5] = (self.d3[2] + self.d3[3] + self.d3[4])/3
        self.d4[5] = (self.d4[3] + self.d4[4])/2
        self.V[5] = (self.V[0] + self.V[1] + self.V[2] + self.V[3] + self.V[4])/5



    ## Публічні функції
    # Провести розрахунки всієї таблиці
    def calc(self):
        self.__find_alfa()
        self.__find_V()
        self.__find_fF()
        self.__find_average()
        self.__find_delta_V()
        self.__find_m()
        self.__draw_table()

    # Переводимо всі значення під номер в списку значення = значення * (spisk/100) + значення
    def normalize(self):
        for i in range(6):
            self.v[i] = self.v[i] * (self.spisk/100) + self.v[i]
            self.F[i] = self.F[i] * (self.spisk/100) + self.F[i]
            self.fF[i] = self.fF[i] * (self.spisk / 100) + self.fF[i]
            self.d1[i] = self.d1[i] * (self.spisk/100) + self.d1[i]
            self.d2[i] = self.d2[i] * (self.spisk/100) + self.d2[i]
            self.d3[i] = self.d3[i] * (self.spisk/100) + self.d3[i]
            self.d4[i] = self.d4[i] * (self.spisk/100) + self.d4[i]
            self.V[i] = self.V[i] * (self.spisk/100) + self.V[i]
        self.alfa = self.alfa * (self.spisk / 100) + self.alfa
        self.d = self.d * (self.spisk / 100) + self.d

    # заокруглити всі значення до 4 знаків після коми
    def round_values(self):
        for i in range(6):
            self.v[i] = round(self.v[i],5)
            self.F[i] = round(self.F[i],5)
            self.fF[i] = round(self.fF[i], 5)
            self.d1[i] = round(self.d1[i],5)
            self.d2[i] = round(self.d2[i],5)
            self.d3[i] = round(self.d3[i],5)
            self.d4[i] = round(self.d4[i],5)
            self.V[i] = round(self.V[i],5)
        self.d = round(self.d, 5)
        self.alfa = round(self.alfa, 5)
        self.m = round(self.m, 10)
        self.delta_V[5] = round(self.delta_V[5],5)


    # print table
    def print_table(self):
        f = open("result/table_variant" + str(self.spisk) + ".txt", 'w')
        table = PrettyTable()
        table.field_names = ["No","v","F","fF","d1","d2","d3","d4","d","alfa","V"]
        for i in range(6):
            table.add_row([i+1 if i != 5 else "ser",self.v[i],self.F[i],self.fF[i],self.d1[i] if self.d1[i] !=0 else '-',self.d2[i] if self.d2[i] !=0 else '-',self.d3[i] if self.d3[i] !=0 else '-',self.d4[i] if self.d4[i] !=0 else '-',self.d if i == 2 else ' ',self.alfa if i == 2 else ' ',self.V[i]])
        print(table)
        print("Маса одиниці довжини струни m = (F/V^2)*d: " + str(self.m))
        print("Абсолютна похибка V: " + str(self.V[5]) + " +- " + str(self.delta_V[5]))
        print("Відносна похибка E: " + str(round((self.delta_V[5]/self.V[5])*100,5)) + "%\n")
        text = table.get_string()
        text += "\nМаса одиниці довжини струни m = (F/V^2)*d: " + str(self.m) + "\nАбсолютна похибка V: " + str(self.V[5]) + " +- " + str(self.delta_V[5]) + "\nВідносна похибка E: " + str(round((self.delta_V[5]/self.V[5])*100,5)) + "%\n"
        f.write(text)


    # show graph
    def show_graph(self):
        plt.savefig("result/graph_variant"+str(self.spisk)+".png")
        plt.grid()
        plt.show()



# main
if __name__ == "__main__":
    print("Version: 1.0")
    print("Введіть додатній номер списку щоб додати відсоток, та відємний щоб відняти відсоток від данних(якщо ви перший в списку, то впишіть 0)")
    spisk = int(input("Введіть ваш номер в списку: "))
    table = Solution(spisk)  # Створюєм об'єкт класу Solution

    table.normalize() # Переводимо значення під варіант
    table.calc() # знаходимо невідомі
    table.round_values() # Заокруглюємо значення до 4 цифр після коми
    table.print_table() # Виводимо таблицю
    print("Нажміть ентр щоб побачити графік(ви можете зберегти графік, кнопка зберегти в меню графіка)")
    input()
    table.show_graph()
    input()




