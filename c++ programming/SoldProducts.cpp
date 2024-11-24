#include <iostream>
#include <string>
using namespace std;

class Product 
{
 private:
    //декларираме какжи свойства/параметри ще има класът Продукт
    string brand;
    int qtyInStorage;
    int soldProducts;
    int mostSoldPerDay[7];
    
 public:
    // Конструктор (За да сложим име на фирмата за продукти и капацитет от този продукт)
    Product(string brand = "", int qty = 0) : brand(brand), qtyInStorage(qty), soldProducts(0) 
    {
        //Слагаме стойност 0 на всякъде в масива, за да на се произволни числата
        for(int i = 0; i < 7; i++) mostSoldPerDay[i] = 0;
    }

    // Гетъри и сетъри (Прави се с цел енкапсулация)
    void setMostSoldPerDay(int sales, int index) 
    {
        mostSoldPerDay[index] = sales;
    }

    int* getMostSoldPerDay() 
    {
        return mostSoldPerDay;
    }

    void setBrand(string str) 
    {
        brand = str;
    }

    void setQtyInStorage(int num) 
    {
        qtyInStorage = num;
    }

    void setSoldProducts(int num) 
    {
        soldProducts = num;
    }

    int getSoldProducts() 
    {
        return soldProducts;
    }

    int getQtyInStorage() 
    {
        return qtyInStorage;
    }

    string getBrand() 
    {
        return brand;
    }
};
    // Мейн функция в която ще извършваме действията
int main() 
{
    // Използваме сетлокал за да можем да взимаме и принтираме информация от конзолата на Кирилица
    setlocale(LC_ALL, "Bulgarian");
    
    // Инициализация на продуктите
    Product products[2] = {Product("coca cola", 50), Product("pepsi", 50)};
    
    // Взимаме продажби за първият продукт като итерираме 7 пъти за седемте дни от седмицата
    for(int i = 0; i < 7; i++) 
    {
        // Изискваме информация от юзъра за да попълним нашият масив
        cout << "Въведете продажбите на продукта от производител1 за ден " << i + 1 << endl;
        // Нагаждаме взетата информация в променливата
        int currentSoldProducts = 0;
        cin >> currentSoldProducts;
        // Проверяваме дали юзъра не задава негативни стойности или нула
        if (currentSoldProducts <= 0) 
        {
            cout << "Невалидни данни!" << endl;
            i--; // При използване на невалидни данни повтаряме процедурата
        } 
        else 
        {
            // Взимаме старата стойност за продадени продукти 
            // от масива и прибавяме новата към нея
            products[0].setSoldProducts(products[0].getSoldProducts() + currentSoldProducts);
            products[0].setQtyInStorage(products[0].getQtyInStorage() - currentSoldProducts);
            products[0].setMostSoldPerDay(currentSoldProducts, i);
        }
    }

      // Взимаме продажби за вторият продукт като итерираме 7 пъти за седемте дни от седмицата
    for(int i = 0; i < 7; i++) 
    {
         // Изискваме информация от юзъра за да попълним нашият масив
        cout << "Въведете продажбите на продукта от производител2 за ден " << i + 1 << endl;
        // Нагаждаме взетата информация в променливата
        int currentSoldProducts = 0;
        cin >> currentSoldProducts;
        // Проверяваме дали юзъра не задава негативни стойности или нула
        if (currentSoldProducts <= 0) 
        {
            cout << "Невалидни данни!" << endl;
            i--; // При използване на невалидни данни повтаряме процедурата
        } 
        else 
        { 
            // Взимаме старата стойност за продадени продукти 
            // от масива и прибавяме новата към нея
            products[1].setSoldProducts(products[1].getSoldProducts() + currentSoldProducts);
            products[1].setQtyInStorage(products[1].getQtyInStorage() - currentSoldProducts);
            products[1].setMostSoldPerDay(currentSoldProducts, i);
        }
    }

    // Принтираме общият брой продадени продукти за седмицата като сбор от двете компании
    cout << "Общ брой на продадените продукти: " << products[0].getSoldProducts() + products[1].getSoldProducts() << endl;

    // Сравняваме покупките за всеки един ден от седмицата
    if (products[0].getSoldProducts() > products[1].getSoldProducts()) 
    {
        // В случай, че първата фирма има повече продажби
        cout << "По-често се продават продуктите на " << products[0].getBrand() 
             << " (" << products[0].getSoldProducts() << " броя)" << endl;
    } 
    else if (products[0].getSoldProducts() < products[1].getSoldProducts()) 
    {
        // В случай, че втората има повече продажби
        cout << "По-често се продават продуктите на " << products[1].getBrand() 
             << " (" << products[1].getSoldProducts() << " броя)" << endl;
    } 
    else 
    {
        // При равенство
        cout << "И двамата продавачи продават по равно" << endl;
    }

    // Намираме денят с най-много продажби
    int biggestSalesDay = 0;
    int biggestSale = 0;
    for(int i = 0; i < 7; i++)
    {
        // Проверяваме дали сборът на продажбите за този ден не е по-голям от последната
        // зададена стойност на променливата в която държим най-голямата стойност от 
        // предишната проверка или първоначалната нула
        if(products[0].getMostSoldPerDay()[i] + products[1].getMostSoldPerDay()[i] > biggestSale)
        {
            // задаваме най голямата стойност и денят в който е направена
            biggestSale = products[0].getMostSoldPerDay()[i] + products[1].getMostSoldPerDay()[i];
               biggestSalesDay = i + 1;
        }
    }
    // Принитраме денят в който има най-много продажби като низова репрезентация на ден от седмицата
switch(biggestSalesDay)
{
    case 1:
    cout << "Ден от седмицата, през който са реализирани най-много продажби: Понеделник" << endl;
    break;
    case 2:
    cout << "Ден от седмицата, през който са реализирани най-много продажби: Вторник" << endl;
    break;
    case 3:
    cout << "Ден от седмицата, през който са реализирани най-много продажби: Сряда" << endl;
    break;
    case 4:
    cout << "Ден от седмицата, през който са реализирани най-много продажби: Четвъртък" << endl;
    break;
    case 5:
    cout << "Ден от седмицата, през който са реализирани най-много продажби: Петък" << endl;
    break;
    case 6:
    cout << "Ден от седмицата, през който са реализирани най-много продажби: Събота" << endl;
    break;
    case 7:
    cout << "Ден от седмицата, през който са реализирани най-много продажби: Неделя" << endl;
    break;
}
 
    return 0;
}