#include <iostream> // Подключение библиотеки ввода/вывода.
#include <string> // Подключение библиотеки строк.
#include <algorithm> // Подключение библиотеки алгоритмов.
#include <cmath> // Подключение библиотеки математических функций.
using namespace std; // Использование пространства имен std.
const double pi = 3.14; // Определение константы pi.

// Определение функций для математических операций.

int add(int a, int b) // Функция сложения двух целых чисел.
{
    return a + b;
}

int multiply(int a, int b) // Функция умножения двух целых чисел.
{
    return a * b;
}

double multiply1(double a, double b) // Функция умножения двух вещественных чисел.
{
    return a * b;
}

double divide(double a, double b) // Функция деления двух вещественных чисел.
{
    return  a / b;
}

double average(int a, int b) // Функция вычисления среднего арифметического двух целых чисел.
{
    return (a + b) / 2;
}

double circlelongevity(int a) // Функция вычисления длины окружности по радиусу.
{
    return 2 * a * pi;
}

double circleploshad(int a) // Функция вычисления площади круга по радиусу.
{
    return a * a * pi;
}



// Определили две структуры данных: CartesianCoordinates для хранения декартовых координат (x, y) и PolarCoordinates для хранения полярных координат (r, theta).

struct CartesianCoordinates {
    double x;
    double y;
};

struct PolarCoordinates {
    double r;
    double theta;
};






int main() {

    // Определение нескольких функций для выполнения различных задач.

   /*task 1*/
        std::cout << "Enter the first foundation "; // Выводится запрос на ввод значения первого основания.
        int foundation = 0; // Инициализация переменной a.
        std::cin >> foundation; // Пользователь вводит значение a.

        std::cout << "Enter the second foundation, which is less than the first one "; // Запрос на ввод значения второго основания, которое должно быть меньше первого.
        int secondfoundation = 0; // Инициализация переменной b.
        std::cin >> secondfoundation; // Пользователь вводит значение b.

        std::cout << "Enter the height "; // Запрос на ввод значения высоты.
        int height = 0; // Инициализация переменной h.
        std::cin >> height; // Пользователь вводит значение h.

        std::cout << "Ploshad " << multiply((divide(add(foundation, secondfoundation), 2)), height) << std::endl; // Вычисление и вывод площади прямоугольника по формуле (a + b) / 2 * h.
    

        /*task 2*/
        std::cout << "Enter the radius "; // Выводится запрос на ввод значения радиуса.
        int radius = 0; // Инициализация переменной a.
        std::cin >> radius; // Пользователь вводит значение радиуса.

        std::cout << "Dlina = " << circlelongevity(radius) << std::endl; // Выводится длина окружности для введенного радиуса.
        std::cout << "Ploshad = " << circleploshad(radius) << std::endl; // Выводится площадь круга для введенного радиуса.
    

        /*task 3*/
        std::cout << "Enter the first catet: "; // Выводится запрос на ввод значения первого катета.
        int firstcatet = 0; // Инициализация переменной a.
        std::cin >> firstcatet; // Пользователь вводит значение первого катета.

        std::cout << "Enter the second catet: "; // Выводится запрос на ввод значения второго катета.
        int secondcatet = 0; // Инициализация переменной b.
        std::cin >> secondcatet; // Пользователь вводит значение второго катета.

        std::cout << "Enter the height: "; // Выводится запрос на ввод значения высоты.
        int heighttwo = 0; // Инициализация переменной h.
        std::cin >> heighttwo; // Пользователь вводит значение высоты.

        double Ploshadtreygolnika = divide(multiply(firstcatet, secondcatet), 2); // Вычисление площади треугольника по формуле (a * b) / 2.
        std::cout << "Ploshad treygolnika: " << Ploshadtreygolnika << std::endl; // Выводится площадь треугольника.

        double hypotenuse_length = divide(multiply(Ploshadtreygolnika, 2), heighttwo); // Вычисление длины гипотенузы по формуле (2 * c) / h.
        std::cout << "Dlina gipotenuzy: " << hypotenuse_length << std::endl; // Выводится длина гипотенузы.
    

        /*task 4*/
        std::cout << "Enter the 4 symbol number: "; // Выводится запрос на ввод 4-х значного числа.
        int foursymbolnumber = 0; // Инициализация переменной a.
        std::cin >> foursymbolnumber; // Пользователь вводит 4-х значное число.

        int m = foursymbolnumber % 10; // Получение последней цифры числа.
        int n = (foursymbolnumber / 10) % 10; // Получение предпоследней цифры числа.
        int k = (foursymbolnumber / 100) % 10; // Получение третьей цифры числа.
        int z = (foursymbolnumber / 1000) % 10; // Получение первой цифры числа.

        int summafour = m + n + k + z; // Вычисление суммы цифр числа.
        std::cout << summafour << std::endl; // Выводится сумма цифр на экран.
    

        /*task 5*/
        PolarCoordinates polarfive; // Создание объекта для хранения полярных координат.

        // Ввод полярных координат
        std::cout << "Enter the r: ";
        std::cin >> polarfive.r; // Ввод радиуса r.

        std::cout << "Enter the theta: ";
        std::cin >> polarfive.theta; // Ввод угла theta.

        // Переход к декартовым координатам
        CartesianCoordinates cartesianfive; // Создание объекта для хранения декартовых координат.
        cartesianfive.x = polarfive.r * std::cos(polarfive.theta); // Вычисление координаты x по радиусу и углу.
        cartesianfive.y = polarfive.r * std::sin(polarfive.theta); // Вычисление координаты y по радиусу и углу.

        // Вывод декартовых координат
        std::cout << "Decart:\n";
        std::cout << "x = " << cartesianfive.x << "\n"; // Вывод координаты x.
        std::cout << "y = " << cartesianfive.y << "\n"; // Вывод координаты y.
    


        /*task 6*/
        CartesianCoordinates cartesian; // Создание объекта для хранения декартовых координат.

        // Ввод декартовых координат
        std::cout << "Enter the x: ";
        std::cin >> cartesian.x; // Ввод координаты x.

        std::cout << "Enter the y: ";
        std::cin >> cartesian.y; // Ввод координаты y.

        // Переход к полярным координатам
        PolarCoordinates polar; // Создание объекта для хранения полярных координат.
        polar.r = std::sqrt(cartesian.x * cartesian.x + cartesian.y * cartesian.y); // Вычисление радиуса r по координатам x и y.
        polar.theta = std::atan2(cartesian.y, cartesian.x); // Вычисление угла theta с использованием арктангенса.

        // Вывод полярных координат
        std::cout << "Polar:\n";
        std::cout << "r = " << polar.r << "\n"; // Вывод радиуса r.
        std::cout << "0 = " << polar.theta << "\n"; // Вывод угла theta.
    

    /*task 7*/
        double a = 0; // Инициализация коэффициента a.
        double b = 0; // Инициализация коэффициента b.
        double c = 0; // Инициализация коэффициента c.
        double x1 = 0; // Инициализация первого корня уравнения.
        double x2 = 0; // Инициализация второго корня уравнения.

        std::cout << "Enter the a,b,c for ax^2+bx+c: "; // Запрос на ввод коэффициентов уравнения.
        std::cin >> a; // Пользователь вводит коэффициент a.
        std::cin >> b; // Пользователь вводит коэффициент b.
        std::cin >> c; // Пользователь вводит коэффициент c.

        double disk = b * b - 4 * a * c; // Вычисление дискриминанта.

        if (disk > 0) // Если дискриминант больше 0, у уравнения два корня.
        {
            x1 = (-b + sqrt(disk)) / (2 * a); // Вычисление первого корня.
            x2 = (-b - sqrt(disk)) / (2 * a); // Вычисление второго корня.
            std::cout << "the x1 =" << x1 << " the x2 =" << x2 << std::endl; // Вывод корней уравнения.
        }
        else if (disk == 0) // Если дискриминант равен 0, у уравнения один корень.
        {
            x1 = -b / (2 * a); // Вычисление корня.
            x2 = x1; // x2 присваивается значение x1.
            std::cout << "the x = " << x1 << std::endl; // Вывод корня уравнения.
        }
        else if (disk < 0) // Если дискриминант меньше 0, у уравнения нет корней.
        {
            std::cout << "No roots!" << std::endl; // Вывод сообщения о отсутствии корней.
        }
    

        /*task 8*/
        std::cout << "Enter the sides a,b,c "; // Выводится запрос на ввод длин сторон треугольника.
        double dlinaa = 0; // Инициализация переменной a.
        double  dlinab = 0; // Инициализация переменной b.
        double  dlinac = 0; // Инициализация переменной c.
        std::cin >> dlinaa >> dlinab >> dlinac; // Пользователь вводит длины сторон треугольника.

        double ma = 0.5 * (sqrt(2 * dlinab * dlinab + 2 * dlinac * dlinac - dlinaa * dlinaa)); // Вычисление медианы относительно стороны a.
        std::cout << "mediana a= " << ma << std::endl; // Вывод медианы a.

        double mb = 0.5 * (sqrt(2 * dlinaa * dlinaa + 2 * dlinac * dlinac - dlinab * dlinab)); // Вычисление медианы относительно стороны b.
        std::cout << " mediana b= " << mb << std::endl; // Вывод медианы b.

        double mc = 0.5 * (sqrt(2 * dlinab * dlinab + 2 * dlinaa * dlinaa - dlinac * dlinac)); // Вычисление медианы относительно стороны c.
        std::cout << " mediana c= " << mc << std::endl; // Вывод медианы c.
    

        /*task 9*/
        std::cout << "Enter the second of the day "; // Выводится запрос на ввод количества секунд.
        int seconds = 0; // Инициализация переменной a.
        std::cin >> seconds; // Пользователь вводит количество секунд.

        int hour = seconds / 3600; // Вычисление количества часов.
        int min = (seconds % 3600) / 60; // Вычисление количества минут (остаток от деления на 3600 секунд, затем результат делится на 60).

        std::cout << "Lasted " << hour << " hours " << min << " minutes" << std::endl; // Выводится результат в формате "Прошло часов минут".
    

        /*task 10*/
        std::cout << "Enter the a,b,c sides "; // Выводится запрос на ввод длин сторон треугольника.
        int sideone, sidetwo, sidethree; // Инициализация переменных a, b, c.
        std::cin >> sideone >> sidetwo >> sidethree; // Пользователь вводит длины сторон треугольника.

        if (sideone == sidetwo || sidetwo == sidethree || sideone == sidethree) // Проверка условия равенства хотя бы двух сторон треугольника.
        {
            std::cout << "The treugol is ravnobed" << std::endl; // Вывод сообщения о том, что треугольник равнобедренный.
        }
        else {
            std::cout << "Bad news" << std::endl; // Вывод сообщения о том, что треугольник не равнобедренный.
        }
    

        /*task 11*/
        std::cout << "Enter the cost "; // Выводится запрос на ввод стоимости товара.
        double cost; // Инициализация переменной a для хранения стоимости товара.
        std::cin >> cost; // Пользователь вводит стоимость товара.

        if (cost > 1000) // Проверка условия: если стоимость товара больше 1000.
        {
            double sale = cost * 0.1; // Вычисление скидки (10% от стоимости).
            double totalcost = cost - sale; // Вычисление общей стоимости с учетом скидки.
            std::cout << "Total cost is " << totalcost << std::endl; // Вывод общей стоимости с учетом скидки.
        }
        else {
            std::cout << "Total cost is " << cost << std::endl; // Вывод общей стоимости без скидки.
        }
    

        /*task 12*/
        std::cout << "Enter the height "; // Выводится запрос на ввод роста.
        double rost; // Инициализация переменной a для хранения роста.
        std::cin >> rost; // Пользователь вводит рост.

        std::cout << "Enter the weight "; // Выводится запрос на ввод веса.
        double weight; // Инициализация переменной b для хранения веса.
        std::cin >> weight; // Пользователь вводит вес.

        double normalweight = rost - 100; // Вычисление "нормального" веса по формуле (рост - 100).

        if (weight > normalweight) // Проверка условия: если вес больше "нормального" веса.
        {
            std::cout << "Hydeem" << std::endl; // Вывод сообщения (худеем).
        }
        else if (weight < normalweight) // Проверка условия: если вес меньше "нормального" веса.
        {
            std::cout << "Tolsteem" << std::endl; // Вывод сообщения  (толстеем).
        }
        else // В противном случае (если вес равен "нормальному" весу).
        {
            std::cout << "Cool" << std::endl; // Вывод сообщения (вес в норме).
        }
    

        /*task 13*/

        int num1 = (rand() % 9) + 1; // Генерация случайного числа num1 от 1 до 9.
        int num2 = (rand() % 9) + 1; // Генерация случайного числа num2 от 1 до 9.

        std::cout << "Enter the answer for the task " << num1 << "*" << num2; // Выводится задание на умножение.

        int ans = 0; // Инициализация переменной ans для хранения ответа пользователя.
        std::cin >> ans; // Пользователь вводит ответ.

        if (ans == (num1 * num2)) // Проверка условия: если ответ пользователя равен произведению num1 и num2.
        {
            std::cout << "Excellent " << std::endl; // Выводится сообщение "Excellent".
        }
        else {
            std::cout << "Not excellent, the correct is " << num1 * num2 << std::endl; // Выводится сообщение о неверном ответе и показывается правильный ответ.
        }
    

        /*task 14*/
        std::cout << "Enter the minutes, the price of 1 minute costs 3 rub "; // Выводится запрос на ввод количества минут и стоимости 1 минуты.
        double minutes; // Инициализация переменной a для хранения количества минут.
        std::cin >> minutes; // Пользователь вводит количество минут.

        std::cout << "Enter the weekday if 1-Monday, 2-Tuesday,..., 7-Sunday "; // Выводится запрос на ввод номера дня недели.
        double weekday; // Инициализация переменной b для хранения номера дня недели.
        std::cin >> weekday; // Пользователь вводит номер дня недели.

        double callscost = minutes * 3; // Вычисление общей стоимости звонков.

        std::cout << "Your check is " << callscost << "!  Let's check the sale " << std::endl; // Выводится общая стоимость и предложение проверить наличие скидки.

        if (weekday == 7 || weekday == 6) // Проверка условия: если день недели - суббота или воскресенье.
        {
            double totally = callscost - (callscost * 0.2); // Вычисление стоимости со скидкой (20% от общей стоимости).
            std::cout << "Total cost is " << totally << std::endl; // Выводится общая стоимость со скидкой.
        }
        else {
            std::cout << "No sales" << std::endl; // Выводится сообщение, что скидок нет.
        }
    

        /*task 15*/
        std::cout << "Enter the index of month if 1 is January,.., 12 is December "; // Выводится запрос на ввод номера месяца.
        int indexofmonth; // Инициализация переменной a для хранения номера месяца.
        std::cin >> indexofmonth; // Пользователь вводит номер месяца.

        if (indexofmonth == 1 || indexofmonth == 2 || indexofmonth == 12) // Проверка условия: если номер месяца является зимним месяцем (1, 2 или 12).
        {
            std::cout << "Winter baby "; // Выводится сообщение о том, что идет зима.
        }
        else if (indexofmonth == 3 || indexofmonth == 4 || indexofmonth == 5) // Проверка условия: если номер месяца является весенним месяцем (3, 4 или 5).
        {
            std::cout << "Spring baby " << std::endl; // Выводится сообщение о том, что идет весна.
        }
        else if (indexofmonth == 6 || indexofmonth == 7 || indexofmonth == 8) // Проверка условия: если номер месяца является летним месяцем (6, 7 или 8).
        {
            std::cout << "Summer baby " << std::endl; // Выводится сообщение о том, что идет лето.
        }
        else if (indexofmonth == 9 || indexofmonth == 10 || indexofmonth == 11) // Проверка условия: если номер месяца является осенним месяцем (9, 10 или 11).
        {
            std::cout << "Autumn baby " << std::endl; // Выводится сообщение о том, что идет осень.
        }

        // Дополнительные условия для вывода названия месяца.
        if (indexofmonth == 1)
            std::cout << "January" << std::endl;
        else if (indexofmonth == 2)
            std::cout << "February" << std::endl;
        else if (indexofmonth == 3)
            std::cout << "March" << std::endl;
        else if (indexofmonth == 4)
            std::cout << "April" << std::endl;
        else if (indexofmonth == 5)
            std::cout << "May" << std::endl;
        else if (indexofmonth == 6)
            std::cout << "June" << std::endl;
        else if (indexofmonth == 7)
            std::cout << "July" << std::endl;
        else if (indexofmonth == 8)
            std::cout << "August" << std::endl;
        else if (indexofmonth == 9)
            std::cout << "September" << std::endl;
        else if (indexofmonth == 10)
            std::cout << "October" << std::endl;
        else if (indexofmonth == 11)
            std::cout << "November" << std::endl;
        else if (indexofmonth == 12)
            std::cout << "December" << std::endl;
    

        /*task 16*/
        std::cout << "Enter the 6 symbol number "; // Выводится запрос на ввод шестизначного числа.
        int sixsymbolnumber;
        std::cin >> sixsymbolnumber; // Пользователь вводит шестизначное число.

        int lastthree = sixsymbolnumber % 1000; // Получение последних трех цифр числа.
        int firstthree = sixsymbolnumber / 1000; // Получение первых трех цифр числа.

        int summa = 0; // Инициализация переменной sum для суммирования цифр последних трех цифр числа.
        int summa2 = 0; // Инициализация переменной sum2 для суммирования цифр первых трех цифр числа.

        while (lastthree > 0)
        {
            summa += lastthree % 10; // Суммирование цифр последних трех цифр числа.
            lastthree /= 10; // Удаление последней цифры числа.
        }

        while (firstthree > 0)
        {
            summa2 += firstthree % 10; // Суммирование цифр первых трех цифр числа.
            firstthree /= 10; // Удаление последней цифры числа.
        }

        if (summa == summa2)
        {
            std::cout << "The number is happy" << std::endl; // Вывод сообщения о том, что число является "счастливым".
        }
        else
        {
            std::cout << "The number is not happy" << std::endl; // Вывод сообщения о том, что число не является "счастливым".
        }
    

        /*task 17*/
        std::cout << "Enter the number from 1 to 99 "; // Выводится запрос на ввод числа от 1 до 99.
        int numfromonetoninenine;
        std::cin >> numfromonetoninenine; // Пользователь вводит число.

        if (numfromonetoninenine > 20) // Проверка, если число больше 20.
        {
            int lastnum = numfromonetoninenine % 10; // Получение последней цифры числа.

            if (lastnum == 1)
                std::cout << numfromonetoninenine << " kopeika"; // Вывод сообщения о копейке, если последняя цифра равна 1.
            else if (lastnum > 1 && lastnum < 5)
                std::cout << numfromonetoninenine << " kopeiki"; // Вывод сообщения о копейках, если последняя цифра от 2 до 4.
            else if (lastnum > 4 || lastnum == 0)
                std::cout << numfromonetoninenine << " kopeek"; // Вывод сообщения о копейках, если последняя цифра больше 4 или равна 0.
        }
        else if (numfromonetoninenine >= 1 && numfromonetoninenine <= 20) // Проверка, если число от 1 до 20.
        {
            if (numfromonetoninenine == 1)
                std::cout << numfromonetoninenine << " kopeika"; // Вывод сообщения о копейке, если число равно 1.
            else if (numfromonetoninenine > 1 && numfromonetoninenine < 5)
                std::cout << numfromonetoninenine << " kopeiki"; // Вывод сообщения о копейках, если число от 2 до 4.
            else if (numfromonetoninenine > 4 || numfromonetoninenine == 0)
                std::cout << numfromonetoninenine << " kopeek"; // Вывод сообщения о копейках, если число больше 4 или равно 0.
        }
        else
        {
            std::cout << "Number is not from 1 to 99" << std::endl; // Вывод сообщения о том, что число вне диапазона от 1 до 99.
        }
    

        /*task 18*/
        std::cout << "Enter the 4 symbol number "; // Выводится запрос на ввод четырехзначного числа.
        int numberoffour;
        std::cin >> numberoffour; // Пользователь вводит четырехзначное число.

        int lastn = numberoffour % 10; // Получение последней цифры числа.
        int prelastn = (numberoffour / 10) % 10; // Получение предпоследней цифры числа.
        int secn = (numberoffour / 100) % 10; // Получение второй цифры числа.
        int firn = (numberoffour / 1000) % 10; // Получение первой цифры числа.

        if (lastn == firn && prelastn == secn)
        {
            std::cout << "Palindrom " << std::endl; // Вывод сообщения о том, что число является палиндромом.
        }
        else
        {
            std::cout << "Ne Palindrom " << std::endl; // Вывод сообщения о том, что число не является палиндромом.
        }

        /*task 19*/
        std::cout << "Enter the 3 symbol number "; // Выводится запрос на ввод трехзначного числа.
        int numofthree;
        std::cin >> numofthree; // Пользователь вводит трехзначное число.

        std::cout << "Enter the number b "; // Выводится запрос на ввод числа b.
        int bnumber;
        std::cin >> bnumber; // Пользователь вводит число b.

        int pro = 1; // Инициализация переменной pro для произведения цифр числа.
        int  plus = 0; // Инициализация переменной sum для суммирования цифр числа.

        while (numofthree > 0)
        {
            plus += numofthree % 10; // Суммирование цифр числа.
            pro *= numofthree % 10; // Умножение цифр числа.
            numofthree /= 10; // Удаление последней цифры числа.
        }

        if (plus % 7 == 0)
        {
            std::cout << plus << " kratno 7" << std::endl; // Вывод сообщения о том, что сумма цифр кратна 7.
        }
        else
        {
            std::cout << plus << " ne kratno 7" << std::endl; // Вывод сообщения о том, что сумма цифр не кратна 7.
        }

        if (pro > bnumber)
        {
            std::cout << pro << ">" << bnumber << std::endl; // Вывод сообщения о том, что произведение цифр больше числа b.
        }
        else if (pro < bnumber)
        {
            std::cout << pro << "<" << bnumber << std::endl; // Вывод сообщения о том, что произведение цифр меньше числа b.
        }
        else if (pro == bnumber)
        {
            std::cout << pro << "=" << bnumber << std::endl; // Вывод сообщения о том, что произведение цифр равно числу b.
        }
    

        /*task 20*/
        std::cout << "Enter the a side "; // Выводится запрос на ввод стороны a.
        int aside;
        std::cin >> aside; // Пользователь вводит значение стороны a.

        std::cout << "Enter the b side "; // Выводится запрос на ввод стороны b.
        int bside;
        std::cin >> bside; // Пользователь вводит значение стороны b.

        std::cout << "Enter the c side "; // Выводится запрос на ввод стороны c.
        int cside;
        std::cin >> cside; // Пользователь вводит значение стороны c.

        std::cout << "Enter the d side "; // Выводится запрос на ввод стороны d.
        int dside;
        std::cin >> dside; // Пользователь вводит значение стороны d.

        if (aside <= cside && bside <= dside || aside <= dside && bside <= cside)
        {
            std::cout << "Moshno vpisat "<<std::endl; // Вывод сообщения о том, что можно вписать.
        }
        else {
            std::cout << "Nelzya " << std::endl; // Вывод сообщения о том, что нельзя вписать.
        }
    

    /*task 21*/
        std::cout << "Sizes in bytes\n"; // Вывод заголовка.

        std::cout << "char: " << sizeof(char) << " byte\n"; // Вывод размера типа данных char в байтах (использую другой метод переноса строки :)).
        std::cout << "int: " << sizeof(int) << " byte\n"; // Вывод размера типа данных int в байтах.
        std::cout << "float: " << sizeof(float) << " byte\n"; // Вывод размера типа данных float в байтах.
        std::cout << "double: " << sizeof(double) << " byte\n"; // Вывод размера типа данных double в байтах.
        std::cout << "long long: " << sizeof(long long) << " byte\n"; // Вывод размера типа данных long long в байтах.
    




    return 0;
}
