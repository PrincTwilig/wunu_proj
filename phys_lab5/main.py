from prettytable import PrettyTable
import matplotlib.pyplot as plt

class Solution:

    def __init__(self,spisk):
        self.spisk = spisk
        # Всі початкові значення таблиці, 6 елемент це середнє значення
        self.v = [0,0,0,0,0,0]
        self.F = [0,0,0,0,0,0]
        self.fF = [0,0,0,0,0,0]
        self.d1 = [0,0,0,0,0,0]
        self.d2 = [0,0,0,0,0,0]
        self.d3 = [0,0,0,0,0,0]
        self.d4 = [0,0,0,0,0,0]
        self.d = [0,0,0,0,0,0]
        self.alfa = [0,0,0,0,0,0]
        self.V = [0,0,0,0,0,0]

        # Значення похибок





    ## Функція для обчислення значень (приватні функції)
    #find d = alfa/2
    def __find_d(self):
        for i in range(5):
            self.d[i] = self.alfa[i]/2

    #find V = alfa*v
    def __find_V(self):
        for i in range(5):
            self.V[i] = self.alfa[i]*self.v[i]

    # find average value
    def __find_average(self):
        self.v[5] = (self.v[0] + self.v[1] + self.v[2] + self.v[3] + self.v[4])/5
        self.F[5] = (self.F[0] + self.F[1] + self.F[2] + self.F[3] + self.F[4])/5
        self.fF[5] = (self.fF[0] + self.fF[1] + self.fF[2] + self.fF[3] + self.fF[4])/5
        self.d1[5] = (self.d1[0] + self.d1[1] + self.d1[2] + self.d1[3] + self.d1[4])/5
        self.d2[5] = (self.d2[0] + self.d2[1] + self.d2[2] + self.d2[3] + self.d2[4])/5
        self.d3[5] = (self.d3[0] + self.d3[1] + self.d3[2] + self.d3[3] + self.d3[4])/5
        self.d4[5] = (self.d4[0] + self.d4[1] + self.d4[2] + self.d4[3] + self.d4[4])/5
        self.d[5] = (self.d[0] + self.d[1] + self.d[2] + self.d[3] + self.d[4])/5
        self.alfa[5] = (self.alfa[0] + self.alfa[1] + self.alfa[2] + self.alfa[3] + self.alfa[4])/5
        self.V[5] = (self.V[0] + self.V[1] + self.V[2] + self.V[3] + self.V[4])/5



    ## Публічні функції
    # Провести розрахунки всієї таблиці
    def calc(self):
        self.__find_d()
        self.__find_V()
        self.__find_average()

    # Переводимо всі значення під номер в списку значення = значення * (spisk/100) + значення
    def normalize(self):
        for i in range(6):
            self.v[i] = self.v[i] * (self.spisk/100) + self.v[i]
            self.F[i] = self.F[i] * (self.spisk/100) + self.F[i]
            self.fF[i] = self.fF[i] * (self.spisk/100) + self.fF[i]
            self.d1[i] = self.d1[i] * (self.spisk/100) + self.d1[i]
            self.d2[i] = self.d2[i] * (self.spisk/100) + self.d2[i]
            self.d3[i] = self.d3[i] * (self.spisk/100) + self.d3[i]
            self.d4[i] = self.d4[i] * (self.spisk/100) + self.d4[i]
            self.d[i] = self.d[i] * (self.spisk/100) + self.d[i]
            self.alfa[i] = self.alfa[i] * (self.spisk/100) + self.alfa[i]
            self.V[i] = self.V[i] * (self.spisk/100) + self.V[i]

    # заокруглити всі значення до 4 знаків після коми
    def round_values(self):
        for i in range(6):
            self.v[i] = round(self.v[i],5)
            self.F[i] = round(self.F[i],5)
            self.fF[i] = round(self.fF[i],5)
            self.d1[i] = round(self.d1[i],5)
            self.d2[i] = round(self.d2[i],5)
            self.d3[i] = round(self.d3[i],5)
            self.d4[i] = round(self.d4[i],5)
            self.d[i] = round(self.d[i],5)
            self.alfa[i] = round(self.alfa[i],5)
            self.V[i] = round(self.V[i],5)


    # print table
    def print_table(self):
        table = PrettyTable()
        table.field_names = ["№","v","F","fF","d1","d2","d3","d4","d","alfa","V"]
        for i in range(6):
            table.add_row([i+1 if i != 5 else "сер",self.v[i],self.F[i],self.fF[i],self.d1[i],self.d2[i],self.d3[i],self.d4[i],self.d[i],self.alfa[i],self.V[i]])
        print(table)

    # show graph
    def show_graph(self):
        plt.plot([self.V[0], self.V[1], self.V[2], self.V[3], self.V[4]],
                 [self.fF[0], self.fF[1], self.fF[2], self.fF[3], self.fF[4]])
        plt.show()


# main
if __name__ == "__main__":
    print("Version: 1.0")
    print("Введіть додатній номер списку щоб додати відсоток, та відємний щоб відняти відсоток від данних(якщо ви перший в списку, то впишіть 0)")
    spisk = int(input("Введіть ваш номер в списку: "))
    table = Solution(spisk)  # Створюєм об'єкт класу Solution

    table.normalize() # Переводимо значення під варіант
    table.round_values() # Заокруглюємо значення до 4 цифр після коми
    table.print_table() # Виводимо таблицю
    print("Нажміть ентр щоб побачити графік(ви можете зберегти графік, кнопка зберегти в меню графіка)")
    input()
    table.show_graph()



