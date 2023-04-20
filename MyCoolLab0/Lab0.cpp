#include <iostream>
#include "singlyLinkedListReal.hpp"
#include "binaryTreeReal.hpp"
#include "DateReal.hpp"
#include "ParticipantOfTheCompetitionReal.hpp"
#include <string>
#include <fstream>


std::istream& operator>>(std::istream& in, Date& birthYear)
{
    unsigned short day;
    unsigned short month;
    unsigned short year;
    char delimeter;

    in >> month >> delimeter >> day >> delimeter >> year;

    birthYear = Date(day, month, year);

    return in;
}

std::ostream& operator<<(std::ostream& out, const Date& birthYear)
{
    out << birthYear.Month() << "/" << birthYear.Day() << "/" << birthYear.Year();

    return out;
}


std::istream& operator>>(std::istream& in, ParticipantsOfTheCompetition& Participant)
{
    std::string lastName;
    getline(in, lastName, ',');
    std::string firstName;
    getline(in, firstName, ',');
    std::string country;
    getline(in, country, ',');
    std::string category;
    getline(in, category, ',');
    Date birthYear;
    in >> birthYear;
    in.ignore();
    unsigned short idParticipants;
    in >> idParticipants;

    Participant = ParticipantsOfTheCompetition(lastName, firstName, category, country, birthYear, idParticipants);
    std::string end;
    getline(in, end);

    return in;
}


std::ostream& operator<<(std::ostream& out, const ParticipantsOfTheCompetition& Participant)
{
    out << Participant.LastName() << "\t" << Participant.FirstName() << "\t" << Participant.Country() << "\t" << Participant.Category() << "\t" << Participant.BirthYear() << "\t" << Participant.IDParticipant() << std::endl;

    return out;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    std::string path = "D:/MyCoolProject1/MyCoolLab2/MOCK_DATA.csv";

    std::ifstream file(path);

    singlyLinkedList<ParticipantsOfTheCompetition> List;

    //Проверка на открытие файла
    if (!file.is_open())
    {
        std::cout << "File opening error!" << std::endl;
    }
    else
    {
            //Пока файл не дошёл до конца
            while (!file.eof())
            {
                //Создаём временную переменную
                ParticipantsOfTheCompetition tmp;

                //Считываем из файла значения во временную переменную
                file >> tmp;

                //Если достигнут конец файла, завершаем работу цикла
                if (file.eof())
                {
                    break;
                }
                //Записываем участника в список
                List.push_back(tmp);
            }
    }
    file.close();
    
    List.printList();

    system("pause>nul");
    return 0;
}