#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Author
{
protected:
    string name;
    string surname;
    int year;
public:
    Author() :name("no name"), surname("no surname"), year(0) { }
    Author(string name, string surname, int year)
    {
        this->name = name;
        this->surname = surname;
        this->year = year;
    }
    void SetName(string name)
    {
        this->name = name;
    }
    string GetName()const
    {
        return name;
    }
    void SetSurname(string surname)
    {
        this->surname = surname;
    }
    string GetSurname()const
    {
        return surname;
    }
    void SetYear(int year)
    {
        this->year = year;
    }
    int GetYear()const
    {
        return year;
    }
    void Print()const
    {
        cout << "- - - - - - - Автор - - - - - - -" << endl;
        cout << "Ім`я: " << name << endl;
        cout << "Прізвище: " << surname << endl;
        cout << "Рік народження: " << year;
    }
};
class Publisher
{
protected:
    string publishingHouse;
    int publishingYear;
public:
    Publisher() :publishingHouse("no publushing house"), publishingYear(0) { }
    Publisher(string publishingHouse, int publishingYear) :publishingHouse(publishingHouse), publishingYear(publishingYear) { }
    void SetPublishingHouse(string publishingHouse)
    {
        this->publishingHouse = publishingHouse;
    }
    string GetPublishingHouse()const
    {
        return publishingHouse;
    }
    void SetPublishingYear(int publishingYear)
    {
        this->publishingYear = publishingYear;
    }
    int GetPublishingYear()const
    {
        return publishingYear;
    }
    void Print()const
    {
        cout << "- - - - - - - Видавець - - - - - - -" << endl;
        cout << "Видавець книги: " << publishingHouse << endl;
        cout << "Рік видання книги: " << publishingYear << endl;
    }
};
class Book :public Publisher, public Author
{
private:
    string name;
    int numberBook;
    string type;
    string language;
    double rating;
    float pages;
public:
    Book() :numberBook(0), name("no name"), type("no type"), language("no language"), Publisher(),
    rating(0), pages(0) { }
    Book(int numberBook, string name, string type, string language, string publishingHouse, int publishingYear,
         string _name, string surname, int year, double rating, float pages)
    {
        this->numberBook = numberBook;
        this->name = name;
        this->type = type;
        this->language = language;
        Publisher(publishingHouse, publishingYear);
        Author(_name, surname, year);
        this->rating = rating;
        this->pages = pages;
    }
    void SetNumberBook(int numberBook)
    {
        this->numberBook = numberBook;
    }
    int GetNumberBook()const
    {
        return numberBook;
    }
    void SetName(string name)
    {
        this->name = name;
    }
    string GetName()const
    {
        return name;
    }
    void SetType(string type)
    {
        this->type = type;
    }
    string GetType()const
    {
        return type;
    }
    void SetLanguage(string language)
    {
        this->language = language;
    }
    string Getlanguage()const
    {
        return language;
    }
    void SetRating(double rating)
    {
        this->rating = rating;
    }
    double GetRating()const
    {
        return rating;
    }
    void SetPages(float pages)
    {
        this->pages = pages;
    }
    float GetPages()const
    {
        return pages;
    }
    void Print()const
    {
        cout << "- - - - - - - Книга - - - - - - -" << endl;
        cout << "Номер: " << numberBook << endl;
        cout << "Назва: " << name << endl;
        cout << "Тип: " << type << endl;
        cout << "Мова: " << language << endl;
        Publisher::Print();
        Author::Print();
        cout << "Рейтинг: " << rating << endl;
        cout << "Кількість сторінок: " << pages << endl;
    }
    friend ostream &operator<<( ostream &COUT, const Book &BOOK );
    friend bool CompareBooksByName(const Book &bk1, const Book &bk2);
    friend bool CompareBooksByNumber(const Book &bk1, const Book &bk2);
    friend bool operator==(const Book &b1, const Book &b2);
};
bool CompareBooksByName(const Book &bk1, const Book &bk2)
{
    return bk1.name < bk2.name;
}
bool CompareBooksByNumber(const Book &bk1, const Book &bk2)
{
    return bk1.numberBook < bk2.numberBook;
}
ostream &operator<<( ostream &COUT, const Book &BOOK )
{
    COUT << "Номер: " << BOOK.numberBook << endl;
    COUT << "Назва: " << BOOK.name << endl;
    COUT << "Тип: " << BOOK.type << endl;
    COUT << "Мова: " << BOOK.language << endl;
    COUT << "Рейтинг: " << BOOK.rating << endl;
    COUT << "Кількість сторінок: " << BOOK.pages << endl;
    return COUT;
}
bool operator==(const Book &b1, const Book &b2)
{
    if(b1.name == b2.name)
        return 1;
    else
        return 0;
}

class Magazine :public Publisher, public Author
{
private:
    int numberMagazine;
    string name;
    string type;
    string thematicDirection;
    string ageCategory;
    string basicDetails;
    string format;
public:
    Magazine() :numberMagazine(0), name("no name"), type("no type"), thematicDirection("no thematic direction"),
    ageCategory("0"), basicDetails("no basic details"), format("no format") { }
    Magazine(int numberMagazine, string name, string type, string publishingHouse, int publishingYear, string _name,
             string surname, int year, string thematicDirection, string ageCategory, string format)
    {
        this->numberMagazine = numberMagazine;
        this->name = name;
        this->type = type;
        Publisher(publishingHouse, publishingYear);
        Author(_name, surname, year);
        this->thematicDirection = thematicDirection;
        this->ageCategory = ageCategory;
        this->format = format;
    }
    void SetNumberMagazine(int numberMagazine)
    {
        this->numberMagazine = numberMagazine;
    }
    int GetNumberMagazine()const
    {
        return numberMagazine;
    }
    void SetName(string name)
    {
        this->name = name;
    }
    string GetName()const
    {
        return name;
    }
    void SetType(string type)
    {
        this->type = type;
    }
    string GetType()const
    {
        return type;
    }
    void SetThematicDirection(string thematicDirection)
    {
        this->thematicDirection = thematicDirection;
    }
    string GetThematicDirection()const
    {
        return thematicDirection;
    }
    void SetAgeCategory(string ageCategory)
    {
        this->ageCategory = ageCategory;
    }
    string GetAgeCategory()const
    {
        return ageCategory;
    }
    void SetBasicDetails(string basicDetails)
    {
        this->basicDetails = basicDetails;
    }
    string GetBasicDetails()const
    {
        return basicDetails;
    }
    void SetFormat(string format)
    {
        this->format = format;
    }
    string GetFormat()const
    {
        return format;
    }
    void Title(string title)
    {
        cout << "<<<<<<<НАЗВА ЖУРНАЛУ>>>>>>>" << endl;
        cout << title << endl;
    }
    void Print()
    {
        cout << "- - - - - - - ЖУРНАЛ - - - - - - -" << endl;
        cout << "Номер: " << numberMagazine << endl;
        cout << "Назва: " << name << endl;
        cout << "Тип: " << type << endl;
        Publisher::Print();
        Author::Print();
        cout << "Тематичний напрям: " << thematicDirection << endl;
        cout << "Вікова категорія: " << ageCategory << endl;
        cout << "Формат: " << format << endl;
    }
    friend ostream &operator<<( ostream &COUT, const Magazine &MAGAZINE );
    friend bool CompareMagazinesByName(const Magazine &mg1, const Magazine &mg2);
    friend bool CompareMagazinesByNumber(const Magazine &mg1, const Magazine &mg2);
};
ostream &operator<<(ostream &COUT, const Magazine &MAGAZINE)
{
    COUT << "Номер: " << MAGAZINE.numberMagazine << endl;
    COUT << "Назва: " << MAGAZINE.name << endl;
    COUT << "Тип: " << MAGAZINE.type << endl;
    COUT << "Тематичний напрям: " << MAGAZINE.thematicDirection << endl;
    COUT << "Вікова категорія: " << MAGAZINE.ageCategory << endl;
    COUT << "Формат: " << MAGAZINE.format << endl;
    return COUT;
}
bool CompareMagazinesByName(const Magazine &mg1, const Magazine &mg2)
{
    return mg1.name < mg2.name;
}
bool CompareMagazinesByNumber(const Magazine &mg1, const Magazine &mg2)
{
    return mg1.numberMagazine < mg2.numberMagazine;
}
class Newspaper :public Publisher
{
private:
    int numberNewspaper;
    string name;
    string thematic;
    string age;
    string periodicity;
    string format;
    string designStyle;
    Publisher publisher;
public:
    Newspaper() :numberNewspaper(0), name("no name"), thematic("no thematic"), age("no age"),
    periodicity("no periodicity"), format("no format"), designStyle("none"), Publisher() { }
    Newspaper(int numberNewspaper, string name, string thematic, string age, string periodicity, string format,
              string designStyle, string publishingHouse, int publishingYear)
    {
        this->numberNewspaper = numberNewspaper;
        this->name = name;
        this->thematic = thematic;
        this->age = age;
        this->periodicity = periodicity;
        this->format = format;
        this->designStyle = designStyle;
        Publisher(publishingHouse, publishingYear);
    }
    void SetNumberNewspaper(int numberNewspaper)
    {
        this->numberNewspaper = numberNewspaper;
    }
    int GetNumberNewspaper()const
    {
        return numberNewspaper;
    }
    void SetName(string name)
    {
        this->name = name;
    }
    string GetName()const
    {
        return name;
    }
    void SetThematic(string thematic)
    {
        this->thematic = thematic;
    }
    string GetThematic()const
    {
        return thematic;
    }
    void SetAge(string age)
    {
        this->age = age;
    }
    string GetAge()const
    {
        return age;
    }
    void SetPeriodicity(string periodicity)
    {
        this->periodicity = periodicity;
    }
    string GetPeriodicity()const
    {
        return periodicity;
    }
    void SetFormat(string format)
    {
        this->format = format;
    }
    string GetFormat()const
    {
        return format;
    }
    void Print()const
    {
        cout << "- - - - - - - Газета - - - - - - -" << endl;
        cout << "Номер: " << numberNewspaper << endl;
        cout << "Назва: " << name << endl;
        cout << "Тематика: " << thematic << endl;
        cout << "Вікова категорія: " << age << endl;
        cout << "Періодичні видання газети: " << periodicity << endl;
        cout << "Формат: " << format << endl;
        cout << "Стиль оформлення газети: " << designStyle << endl;
        Publisher::Print();
    }
    friend ostream &operator<<( ostream &COUT, const Newspaper &NEWSPAPER );
    friend bool CompareNewspapersByName(const Newspaper &np1, const Newspaper &np2);
    friend bool CompareNewspapersByNumber(const Newspaper &np1, const Newspaper &np2);
};
ostream &operator<<(ostream &COUT, const Newspaper &NEWSPAPER)
{
    COUT << "Номер: " << NEWSPAPER.numberNewspaper << endl;
    COUT << "Назва: " << NEWSPAPER.name << endl;
    COUT << "Тематика: " << NEWSPAPER.thematic << endl;
    COUT << "Вікова категорія: " << NEWSPAPER.age << endl;
    COUT << "Періодичні видання газети: " << NEWSPAPER.periodicity << endl;
    COUT << "Формат: " << NEWSPAPER.format << endl;
    COUT << "Стиль оформлення газети: " << NEWSPAPER.designStyle << endl;
    return COUT;
}
bool CompareNewspapersByName(const Newspaper &np1, const Newspaper &np2)
{
    return np1.name < np2.name;
}
bool CompareNewspapersByNumber(const Newspaper &np1, const Newspaper &np2)
{
    return np1.numberNewspaper < np2.numberNewspaper;
}

class Head
{
private:
    string lastName;
    string initials;
    int accessLvl;
    unsigned int experience;
    unsigned int salaryPerHour;
    unsigned int salaryForWorkTime;
    unsigned int workTime;
    double award;
    string login;
public:
    Head() :lastName("no name"), initials("none"), experience(0), salaryPerHour(0), salaryForWorkTime(0),
    workTime(0), award(0) { }
    Head(string lastName, string initials, unsigned int experience, unsigned int salaryPerHour,
         unsigned int workTime)
    {
        this->lastName = lastName;
        this->initials = initials;
        this->experience = experience;
        this->salaryPerHour = salaryPerHour;
        this->workTime = workTime;
        this->salaryForWorkTime = salaryPerHour * workTime;
    }
    void SetLastName(string lastName)
    {
        this->lastName = lastName;
    }
    string GetLastName()const
    {
        return lastName;
    }
    void SetInitials(string initials)
    {
        this->initials = initials;
    }
    string GetInitials()const
    {
        return initials;
    }
    void SetAccesLvl(int accessLvl)
    {
        this->accessLvl = accessLvl;
    }
    int GetAccessLvl()const
    {
        return accessLvl;
    }
    void SetExperience(unsigned int experience)
    {
        this->experience = experience;
    }
    unsigned int GetExperience()const
    {
        return experience;
    }
    void SetSalaryPerHour(unsigned int salaryPerHour)
    {
        this->salaryPerHour = salaryPerHour;
    }
    unsigned int GetSalaryPerHour()const
    {
        return salaryPerHour;
    }
    void SetSalaryForWorkTime(unsigned int salaryForWorkTime)
    {
        this->salaryForWorkTime = salaryForWorkTime;
    }
    unsigned int GetSalaryForWorkTime()const
    {
        return salaryForWorkTime;
    }
    void SetWorkTime(unsigned int workTime)
    {
        this->workTime = workTime;
    }
    unsigned int GetWorkTime()const
    {
        return workTime;
    }
    void SetAward(double award)
    {
        this->award = award;
    }
    double GetAward()const
    {
        return award;
    }
    void AccessLvl(string accessLvl)
    {
        cout << "Рівень продуктивності роботи директора бібліотеки: " << accessLvl << endl;
    }
    void Set(unsigned int experience)
    {
        if( experience < 1 )
            award = 0.0;
        else if( experience < 3)
        {
            award = (double)(salaryForWorkTime * 5)/100.0;
        }
        else if( experience < 5 )
        {
            award = (double)(salaryForWorkTime * 8)/100.0;
        }
        else
        {
            award = (double)(salaryForWorkTime * 15)/100.0;
        }
    }
    void Print()const
    {
        cout << "- - - - - - - Директор бібліотеки - - - - - - -" << endl;
        cout << "Прізвище: " << lastName << endl;
        cout << "Ініціали: " << initials << endl;
        cout << "Досвід директорської роботи: " << experience << " рокі" << endl;
        cout << "Заробітна плата за годину: " << salaryPerHour << " грн" << endl;
        cout << "Заробітна плата за робочий час: " << salaryForWorkTime << " грн" << endl;
        cout << "Робочі години: " << workTime << endl;
    }
};
class Visitor
{
private:
    string name;
    string surname;
    string patronymicName;
    int year;
public:
    Visitor() :name("no name"), surname("no surname"), patronymicName("no patronymic name"), year(0) { }
    Visitor(string name, string surname, string patronymicName, int year)
    {
        this->name = name;
        this->surname = surname;
        this->patronymicName = patronymicName;
        this->year = year;
    }
    void SetName(string name)
    {
        this->name = name;
    }
    string GetName()const
    {
        return name;
    }
    void SetSurname(string surname)
    {
        this->surname = surname;
    }
    string GetSurname()const
    {
        return surname;
    }
    void SetPatronymicName(string patronymicName)
    {
        this->patronymicName = patronymicName;
    }
    string GetPatronymicName()const
    {
        return patronymicName;
    }
    void SetYear(int year)
    {
        this->year = year;
    }
    int GetYear()const
    {
        return year;
    }
    void RegistrationField()
    {
        int c;
        cout << "\t\t\t______________________________________________________\n\n\n";
        cout << "\t\t\t            Ласкаво просимо на сторінку входу          \n\n\n";
        cout << "\t\t\t__________________     МЕНЮ              _______________\n\n";
        cout << "                                                               \n\n";
        cout << "\t| Натисніть 1, щоб УВІЙТИ                   |" << endl;
        cout << "\t| Натисніть 2, щоб ЗАРЕЄСТРУВАТИСЯ          |" << endl;
        cout << "\t| Натисніть 3, якщо ви ЗАБУЛИ свій пароль   |" << endl;
        cout << "\t| Натисніть 4, щоб ВИЙТИ                    |" << endl;
        cout << "\n\t\t\t Введіть свій вибір: ";
        cin >> c;
        cout << endl;

        switch (c)
        {
            case 1:
            {
                int count;
                string userId, password, id, pass;
                //system("cls");
                cout << "\t\t\t Введіть ваш логін та пароль: " << endl;
                cout << "\t\t\t ЛОГІН ";
                cin >> userId;
                cout << "\t\t\t ПАРОЛЬ ";
                cin >> password;

                while (cin >> id >> pass)
                {
                    if (id == userId && pass == password)
                    {
                        count = 1;
                        //system("cls");
                    }
                }

                if (count == 1)
                {
                    cout << userId << "\n YВаш ВХІД успішний \n Дякуємо за вхід! \n";
                    RegistrationField();
                }
                else
                {
                    cout << "\n ПОМИЛКА ВХОДУ \n Перевірте свій логін та пароль\n";
                    RegistrationField();
                }
                break;
            }
            case 2:
            {
                string ruserId, rpassword, rid, rpass;
                //system("cls");
                cout << "\t\t\t Введіть логін: ";
                cin >> ruserId;
                cout << "\t\t\t Введіть пароль: ";
                cin >> rpassword;

                cout << ruserId << ' ' << rpassword << endl;
                //system("cls");
                cout << "\n\t\t\t Реєстрація пройшла успіщно! \n";
                RegistrationField();
                break;
            }
            case 3:
            {
                int option;
                //system("cls");
                cout << "\t\t\t Ви забули пароль? Нічого страшного \n";
                cout << "Натисніть 1, щоб шукати свій ідентифікатор за іменем користувача " << endl;
                cout << "Натисніть 2, щоб повернутися до головного меню " << endl;
                cin >> option;
                switch (option)
                {
                    case 1:
                    {
                        int count = 0;
                        string suserId, sId, spass;
                        cout << "\n\t\t\tВведіть ім'я користувача, яке ви запам'ятали: ";
                        cin >> suserId;

                        while (cin >> sId >> spass)
                        {
                            if (sId == suserId)
                            {
                                count = 1;
                            }
                        }
                        if (count == 1)
                        {
                            cout << "\n\n Ваш обліковий запис знайдено! \n";
                            cout << "\n\n Ваш пароль: " << spass;
                            RegistrationField();
                        }
                        else
                        {
                            cout << "\n\t Вибачте! Ваш обліковий запис не знайдено! \n";
                            RegistrationField();
                        }
                        break;
                    }
                    case 2:
                    {
                        RegistrationField();
                    }
                    default:
                        cout << "\t\t\tНеправильний вибір! Будь ласка спробуйте ще раз " << endl;
                        //forgot();
                        break;
                }
                break;
            }
            case 4:
                cout << "\t\t\t Дякую! \n\n";
                break;
            default:
                //system("cls");
                cout << "\t\t\t Виберіть із наведених вище варіантів  \n" << endl;
                RegistrationField();
        }
    }
    void Print()const
    {
        cout << "Ім`я: " << name << endl;
        cout << "Прізвище: " << surname << endl;
        cout << "По-батькові: " << patronymicName << endl;
        cout << "Рік народження: " << year << endl;
    }
};
class Library
{
private:
    vector<Book> books;
    int countBooks;
    vector<Magazine> magazines;
    int countMagazines;
    vector<Newspaper> newspapers;
    int countNewspapers;
    int countReaders;
    Head head;
    Visitor *visitors;
public:
    Library() :countBooks(0), countMagazines(0), countNewspapers(0), countReaders(0) { }
    Library(int countBooks, int countMagazines, int countNewspapers, int countReaders)
    {
        this->countBooks = countBooks;
        this->countMagazines = countMagazines;
        this->countNewspapers = countNewspapers;
        this->countReaders = countReaders;
    }
    void AddBook(Book bk)
    {
        books.push_back(bk);
    }
    void AddMagazine(Magazine mg)
    {
        magazines.push_back(mg);
    }
    void AddNewspaper(Newspaper np)
    {
        newspapers.push_back(np);
    }
    void removeBook(size_t index)
    {
        auto it = books.begin();
        advance(it, index);
        books.erase(it);
    }
    void removeMagazine(size_t index)
    {
        auto it = magazines.begin();
        advance(it, index);
        magazines.erase(it);
    }
    void removeNewspaper(size_t index)
    {
        auto it = newspapers.begin();
        advance(it, index);
        newspapers.erase(it);
    }
    void SortBooksByName()
    {
        cout << "Сортування книг за назвою....." << endl;
        std::sort(books.begin(), books.end(), CompareBooksByName);
    }
    void SortBooksByNumber()
    {
        cout << "Сортування книг за номером....." << endl;
        std::sort(books.begin(), books.end(), CompareBooksByNumber);
    }
    void SortMagazinesByName()
    {
        cout << "Сортування журналів за назвою....." << endl;
        std::sort(magazines.begin(), magazines.end(), CompareMagazinesByName);
    }
    void SortMagazinesByNumber()
    {
        cout << "Сортування журналів за номером....." << endl;
        std::sort(magazines.begin(), magazines.end(), CompareMagazinesByNumber);
    }
    void SortNewspapersByName()
    {
        cout << "Сортування газет за назвою....." << endl;
        std::sort(newspapers.begin(), newspapers.end(), CompareNewspapersByName);
    }
    void SortNewspapersByNumber()
    {
        cout << "Сортування газет за номером....." << endl;
        std::sort(newspapers.begin(), newspapers.end(), CompareNewspapersByNumber);
    }
    void FindBookByName(string name)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].GetName() == name)
            {
                books[i].Print();
            }
        }
    }
    void FindMagazineByName(string name)
    {
        for (int i = 0; i < magazines.size(); i++)
        {
            if (magazines[i].GetName() == name)
            {
                magazines[i].Print();
            }
        }
    }
    void Print()const
    {
        cout << "- - - - - - - Бібліотека - - - - - - -" << endl;
        for (int i = 0; i < books.size(); i++)
        {
            cout << books[i] << endl;
        }
        for (int i = 0; i < magazines.size(); i++)
        {
            cout << magazines[i] << endl;
        }
        for (int i = 0; i < newspapers.size(); i++)
        {
            cout << newspapers[i] << endl;
        }
        cout << "Кількість книг у бібліотеці: " << countBooks << endl;
        cout << "Кількість журналів у бібліотеці: " << countMagazines << endl;
        cout << "Кількість газет у бібліотеці: " << countNewspapers << endl;
        cout << "Кількість читачів у бібліотеці: " << countReaders << endl;
    }
};

int main()
{
    setlocale(LC_CTYPE, "ukr");
    Library lib(20, 6, 5, 3);
    lib.AddBook(Book(1, "Чарлі і шоколадна фабрика", "для дітей", "укр", "А-ба-ба-га-ла-ма-га", 2009, "Роальд", "Дал", 1916, 6, 287));
    lib.AddBook(Book(2, "Гаррі Потер", "для дітей", "укр", "А-ба-ба-га-ла-ма-га", 1997, "Джоан", "Роулінг", 1935, 8, 350));
    lib.AddBook(Book(3, "Список запрошених", "художня проза", "укр", "Старого Лева", 2021, "Люсі", "Фолі", 1981, 4, 432));
    lib.AddBook(Book(4, "Карти на стіл", "художня література", "укр", "Клуб сімейного дозвілля", 2020, "Аґата", "Крісті", 1976, 5, 320));
    lib.AddBook(Book(5, "Відьмак. Останнє бажання", "художня література", "укр", "Клуб сімейного дозвілля", 2016, "Анджей", "Сапковський", 1991, 9, 288));
    lib.AddBook(Book(6, "Правила життя", "саморозвиток", "укр", "КМ-БУКС", 2022, "Річард", "Темплар", 1973, 10, 296));
    lib.AddBook(Book(7, "Хороші звички, погані звички", "психологія/саморозвиток", "укр", "Book Chef", 2020, "Венді", "Вуд", 1965, 7, 384));
    lib.AddBook(Book(8, "Ілюзія Ефективності", "про дослідження", "укр", "Фабула", 2020, "Віра", "Валле", 1974, 3, 208));
    lib.AddBook(Book(9, "Психологія грошей", "психологія", "укр", "Yakaboo", 2021, "Морган", "Гаусел", 1964, 10, 288));
    lib.AddBook(Book(10, "Психологія впливу", "психологія", "укр", "Клуб сімейного дозвілля", 2020, "Роберт", "Чалдіні", 1955, 6, 400));
    lib.AddBook(Book(11, "Отойти от дел молодым и богатым", "саморозвиток", "рос", "Поппури", 2016, "Роберт", "Кійосакі", 1947, 10, 458));
    lib.AddBook(Book(12, "Як подолати неспокій і почати жити", "психологія", "укр", "Клуб сімейного дозвілля", 2014, "Дейл", "Карнегі", 1923, 9, 334));
    lib.AddBook(Book(13, "Емоційний інтелект", "саморозвиток", "укр", "КМ-БУКС", 2018, "Даніель", "Гоулман", 1948, 7, 427));
    lib.AddBook(Book(14, "Засліплені блиском", "історія", "укр", "Фабула", 2015, "Аджа", "Рейден", 1943, 3, 288));
    lib.AddBook(Book(15, "Енергетика, клімат, конфлікти", "наукова література", "укр", "Лабораторія", 2022, "Даніель", "Єргін", 1959, 1, 520));
    lib.AddBook(Book(16, "Копірайтинг в алгоритмах", "маркетинг", "укр", "IPIO", 2021, "Ірина", "Костюченко", 1967, 8, 128));
    lib.AddBook(Book(17, "Створи story brand", "фінанси", "укр", "Vivat", 2022, "Дональд", "Міллер", 1994, 6, 240));
    lib.AddBook(Book(18, "С++ для чайників", "програмування", "укр", "Віват", 2022, "Стефан", "Девіс", 1943, 10, 549));
    lib.AddBook(Book(19, "Одного разу в Голлівуді", "мистецтво", "укр", "А-ба-ба-га-ла-ма-га", 2021, "Квентін", "Тарантіно", 1976, 3, 320));
    lib.AddBook(Book(20, "Коротка історія фотографії", "творчість", "укр", "Старого лева", 2021, "Йен", "Сміт", 1962, 6, 224));
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    lib.AddMagazine(Magazine(1, "Forbes", "про людей", "Віват", 2022, "Борис", "Давиденко", 1978, "про найуспішніших людей України", "16+", "205х265 мм"));
    lib.AddMagazine(Magazine(2, "Пульс серця: Зародження", "психологія", "Колесо жизни", 2020, "Анна", "Мельник", 1984, "про здоров`я людини", "18+", "213х290 мм"));
    lib.AddMagazine(Magazine(3, "Експеремент", "саморозвиток/дослідження", "Віват", 2017, "Роман", "Кушнір", 1990, "Правила ефективного самокоучингу", "16+", "165х230 мм"));
    lib.AddMagazine(Magazine(4, "Чарівний світ", "з мультика", "Егмонт", 2022, "-", "-", 1979, "дитячі комікси", "3+", "210х280 мм"));
    lib.AddMagazine(Magazine(5, "Локальна історія", "історія", "УГА", 2022, "Віталій", "Ляска", 1956, "про історичні події на території України", "16+", "210х270 мм"));
    lib.AddMagazine(Magazine(6, "Цінності поза часом", "мода", "Україна", 2021, "Лілія", "Нілова", 1983, "impossible is nothing", "18+", "205х275 мм"));
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    lib.AddNewspaper(Newspaper(1, "Світ кращих судоку", "головоломки", "10+", "щотижневі", "А2", "кольорові", "Кузя", 2021));
    lib.AddNewspaper(Newspaper(2, "Порадниця", "побут", "18+", "щомісячні", "А4", "кольорові", "Укрпошта", 2017));
    lib.AddNewspaper(Newspaper(3, "Новини України", "рекламно-інформаційні", "18+", "щоденні", "А3", "чорно-білі", "Українська правда", 2022));
    lib.AddNewspaper(Newspaper(4, "Молодь України", "змішані", "16+", "щотижневі", "А4", "чорно-білі", "IPIO", 2013));
    lib.AddNewspaper(Newspaper(5, "Бібліотечний вісник", "наукові", "16+", "щомісячні", "А2", "чорно-білі з  кольоровими вставками", "IPIO", 2015));
    lib.Print();
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Head head("Кузьменко", "В. І.", 23, 330, 12);
    head.AccessLvl("10/10");
    head.Set(23);
    head.Print();
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Visitor visitor1("Іванов", "Іван", "Іванович", 2002);
    visitor1.RegistrationField();
    visitor1.Print();
    Visitor visitor2("Шпак", "Андрій", "Вікторович", 2001);
    visitor2.Print();
    Visitor visitor3("Волкова", "Катерина", "Вадимівна", 2001);
    visitor3.Print();
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int num;
    do
    {
        cout << "\t\t\t______________________________________________________\n\n\n";
        cout << "\t\t\t            Ласкаво просимо до бібліотеки              \n\n\n";
        cout << "\t\t\t__________________     МЕНЮ              _______________\n\n";
        cout << "                                                               \n\n";
        cout << "\t| Натисніть 1, щоб переглянути дані про всі джерела            |" << endl;
        cout << "\t| Натисніть 2, щоб видалити книгу із бази даних за індексом    |" << endl;
        cout << "\t| Натисніть 3, щоб видалити журнал із бази даних за індексом   |" << endl;
        cout << "\t| Натисніть 4, щоб видалити газету із бази даних за індексом   |" << endl;
        cout << "\t| Натисніть 5, щоб упорядкувати книги за назвою                |" << endl;
        cout << "\t| Натисніть 6, щоб упорядкувати книги за номером               |" << endl;
        cout << "\t| Натисніть 7, щоб упорядкувати журнали за назвою              |" << endl;
        cout << "\t| Натисніть 8, щоб упорядкувати журнали за номером             |" << endl;
        cout << "\t| Натисніть 9, щоб упорядкувати газети за назвою               |" << endl;
        cout << "\t| Натисніть 10, щоб упорядкувати газети за номером             |" << endl;
        cout << "\t| Натисніть 11, щоб знайти книгу за назвою                     |" << endl;
        cout << "\t| Натисніть 12, щоб знайти журнал за назвою                    |" << endl;
        cout << "\t| Натисніть 0, щоб вийти                                       |" << endl;
        cout << "\n\t\t\t Введіть свій вибір: ";
        cin >> num;
        cout << endl;
        switch (num)
        {
            case 1: lib.Print(); break;
            case 2: { lib.removeBook(3); lib.removeBook(7); lib.removeBook(12); lib.removeBook(19); break; }
            case 3: lib.removeMagazine(2); lib.removeMagazine(4); break;
            case 4: lib.removeNewspaper(5); lib.removeNewspaper(2); break;
            case 5: lib.SortBooksByName(); break;
            case 6: lib.SortBooksByNumber(); break;
            case 7: lib.SortMagazinesByName(); break;
            case 8: lib.SortMagazinesByNumber(); break;
            case 9: lib.SortNewspapersByName(); break;
            case 10: lib.SortNewspapersByNumber(); break;
            case 11: lib.FindBookByName("Засліплені блиском"); lib.FindBookByName("Хороші звички, погані звички"); break;
            case 12: lib.FindMagazineByName("Чарівний світ"); lib.FindMagazineByName("Цінності поза часом"); break;
            case 0: exit(0); break;
        }
    }while(num != 0);
}