from bs4 import BeautifulSoup  # Библиотека парсера "Прекрасное мыло"
import os  # Путь к current working directiry (cwd) - рабочая папка

# Распарсит страницу и вернет два массива женских\мужских имен
def parse_me(filename):
    file = open(os.getcwd() + filename)  # Открываем файл
    soup = BeautifulSoup(file, 'lxml')

    links = soup.find_all('a')                  # Поиск всех ссылок в которых будут имена
    headers = soup.find('h3')
    # print(headers.find_next('h3'))
    female_name_base_list = ['Любовь']                # Список женских имен <ИСКЛ>
    male_name_base_list = ['Никита', 'Лёва', 'Илья']  # Список мужских имен <ИСКЛ>

    male_list = {}  # Словарь с ключами - годами
    female_list = {}

    while soup.find_next('a'):
        name = soup.find('a')
        if soup.find_next() == 'h3':
            break


    # for link in links:
    #     length = len(headers)
    #     name = link.next.split()
    #
    #     if name[1][-1] == 'а' or name[1][-1] == 'я':
    #         if name[1] in male_name_base_list:
    #             male_list.append(' '.join(name))
    #         else:
    #             female_list.append(' '.join(name))
    #     else:
    #         if name[1] in female_name_base_list:
    #             female_list.append(' '.join(name))
    #         else:
    #             male_list.append(' '.join(name))

    # print(male_list)
    # return male_list, female_list


# Функция вычисляет статистику по именам за каждый год с учётом пола.
def make_stat(filename):
    # file = open(os.getcwd() + filename)  # Открываем файл
    # male_list, female_list = parse_me(file)  # Получили два массива
    pass



def extract_years(stat):
    """
    Функция принимает на вход вычисленную статистику и выдаёт список годов,
    упорядоченный по возрастанию.
    """
    pass


def extract_general(stat):
    """
    Функция принимает на вход вычисленную статистику и выдаёт список tuple'ов
    (имя, количество) общей статистики для всех имён.
    Список должен быть отсортирован по убыванию количества.
    """
    pass


def extract_general_male(stat):
    """
    Функция принимает на вход вычисленную статистику и выдаёт список tuple'ов
    (имя, количество) общей статистики для имён мальчиков.
    Список должен быть отсортирован по убыванию количества.
    """
    pass


def extract_general_female(stat):
    """
    Функция принимает на вход вычисленную статистику и выдаёт список tuple'ов
    (имя, количество) общей статистики для имён девочек.
    Список должен быть отсортирован по убыванию количества.
    """
    pass


def extract_year(stat, year):
    """
    Функция принимает на вход вычисленную статистику и год.
    Результат — список tuple'ов (имя, количество) общей статистики для всех
    имён в указанном году.
    Список должен быть отсортирован по убыванию количества.
    """
    pass


def extract_year_male(stat, year):
    """
    Функция принимает на вход вычисленную статистику и год.
    Результат — список tuple'ов (имя, количество) общей статистики для всех
    имён мальчиков в указанном году.
    Список должен быть отсортирован по убыванию количества.
    """
    pass


def extract_year_female(stat, year):
    """
    Функция принимает на вход вычисленную статистику и год.
    Результат — список tuple'ов (имя, количество) общей статистики для всех
    имён девочек в указанном году.
    Список должен быть отсортирован по убыванию количества.
    """
    pass


if __name__ == '__main__':
    parse_me('\\home.html')
    # make_stat('\\home.html')
