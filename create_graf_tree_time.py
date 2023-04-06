import matplotlib.pyplot as plt


# функция для чтения файла
def read_file(filename):
    with open(filename, 'r') as f:
        data = f.read()
    return data


# функция рисования графика по точкам из файла
def draw_graph(data):
    lines = data.split('\n')
    xs = []
    ys = []
    for line in lines:
        if len(line) > 0:
            x, y = line.split(';')
            xs.append(float(x))
            ys.append(float(y))
    plt.plot(xs, ys)
    plt.show()


## выбор из разных файлов
loop = 0
choose = 0

while choose==0:
    print("Выберите файл для построения графика:")
    print("1. Заполнение дерева")
    print("2. Поиск")
    print("3. Вставка")
    print("4. Удаление")
    print("5. Выход")
    loop = int(input())
    if loop == 1:
        data = read_file('/Users/margogusarova/CLionProjects/LABA2_2_1.3var_AISD/cmake-build-debug/insert_time_full.txt')
        draw_graph(data)
    elif loop == 2:
        data = read_file('/Users/margogusarova/CLionProjects/LABA2_2_1.3var_AISD/cmake-build-debug/search_time.txt')
        draw_graph(data)
    elif loop == 3:
        data = read_file('/Users/margogusarova/CLionProjects/LABA2_2_1.3var_AISD/cmake-build-debug/insert_time.txt')
        draw_graph(data)
    elif loop == 4:
        data = read_file('/Users/margogusarova/CLionProjects/LABA2_2_1.3var_AISD/cmake-build-debug/delete_time.txt')
        draw_graph(data)
    elif loop == 5:
        break

