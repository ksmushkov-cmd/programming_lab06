/*************************
 * Автор: Смушков Кирилл *
 * Вариант: 12           *
 *                       *  
 *************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Apartment {
  int apartmentNumber; 
  string lastName;
  int totalArea;
  int numberOfRooms;
};

int main() {
  int apartmentCount;
  Apartment apartmentList[99];

  cout << "apartmentCount " << endl;
  cin >> apartmentCount;
  
  ifstream fin("Apartment.TXT");

  if (fin.is_open() == 0) {
    cout << "Error of Open" << endl;
  } else {
    for (int apartmentIndex = 0; apartmentIndex < apartmentCount; ++apartmentIndex) {
      fin >> apartmentList[apartmentIndex].apartmentNumber
          >> apartmentList[apartmentIndex].lastName
          >> apartmentList[apartmentIndex].totalArea
          >> apartmentList[apartmentIndex].numberOfRooms;
 
        cout << apartmentList[apartmentIndex].apartmentNumber << " "
             << apartmentList[apartmentIndex].lastName << " "
             << apartmentList[apartmentIndex].totalArea << " "
             << apartmentList[apartmentIndex].numberOfRooms << endl;

    }

  fin.close();
  double areaThreshold;
  cout << "areaThreshold: ";
  cin >> areaThreshold;

  // Поиск квартир с площадью выше порога
  cout << "Apartaments with an area of more than: " << areaThreshold << endl;
  int minRooms = 1000; 
  int minRoomsIndex = -1;
  bool foundAny = false;

  for (int apartmentIndex = 0; apartmentIndex < apartmentCount && apartmentIndex < 99; ++apartmentIndex) {
    if (apartmentList[apartmentIndex].totalArea > areaThreshold) {
      cout << " apartmentNumber: " << apartmentList[apartmentIndex].apartmentNumber
      << " lastName: " << apartmentList[apartmentIndex].lastName
      << " totalArea: " << apartmentList[apartmentIndex].totalArea
      << " numberOfRooms: " << apartmentList[apartmentIndex].numberOfRooms << endl;

      foundAny = true;
      if (apartmentList[apartmentIndex].numberOfRooms < minRooms) {
        minRooms = apartmentList[apartmentIndex].numberOfRooms;
        minRoomsIndex = apartmentIndex;
      }
    }
  }

  if (!foundAny) {
    cout << "There are no apartment" << endl;
    } else {
      cout << " An apartment with a minimum number of: " << endl;
      cout << " apartmentNumber: " << apartmentList[minRoomsIndex].apartmentNumber
      << " lastName: " << apartmentList[minRoomsIndex].lastName
      << " totalArea: " << apartmentList[minRoomsIndex].totalArea
      << " numberOfRooms: " << apartmentList[minRoomsIndex].numberOfRooms << endl;
    }

  // Ввод числа комнат для определения средней площади
  int targetRooms;
  cout << " targetRooms: ";
  cin >> targetRooms;

  double sumArea = 0.0;
  int countRooms = 0;

  for (int apartmentIndex = 0; apartmentIndex < apartmentCount && apartmentIndex < 99; apartmentIndex++) {
    if (apartmentList[apartmentIndex].numberOfRooms == targetRooms) {
      sumArea += apartmentList[apartmentIndex].totalArea;
      countRooms++;
    }
  }

  if (countRooms > 0) {
    cout << " The average area of apartments with " << targetRooms << " rooms: "
    << (sumArea / countRooms) << endl;
  } else {
    cout << " There are no apartments with " << targetRooms << " rooms." << endl;
  }

  return 0;
}
}