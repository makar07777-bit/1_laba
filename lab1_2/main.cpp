// split headers
#include <fstream>
#include <iostream>
#include <limits>


#include "Circle.h"
#include "Keeper.h"
#include "Rectangle.h"
#include "Shape2D.h"
#include "Square.h"


using namespace std;

int main() {
  Keeper k;

  auto print_menu = []() {
    cout << "\nMenu:\n";
    cout << " 1) Add circle\n";
    cout << " 2) Add rectangle\n";
    cout << " 3) Add square\n";
    cout << " 4) Remove shape by index\n";
    cout << " 5) List shapes\n";
    cout << " 6) Show shape picture\n";
    cout << " 7) Load from file\n";
    cout << " 8) Save to file\n";
    cout << " 9) Areas of all shapes\n";
    cout << " 0) Exit\n";
    cout << "Your choice: ";
  };

  auto read_double = [](const char *prompt) {
    double v{};
    while (true) {
      cout << prompt;
      if (cin >> v)
        return v;
      cout << "Invalid input. Try again.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  };

  auto read_size_t = [](const char *prompt) {
    long long v{};
    while (true) {
      cout << prompt;
      if (cin >> v && v >= 0)
        return static_cast<size_t>(v);
      cout << "Invalid input. Try again.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  };

  int choice = -1;
  do {
    print_menu();
    if (!(cin >> choice)) {
      cout << "Invalid input. Try again.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    switch (choice) {
    case 1: {
      double r = read_double("Radius: ");
      Shape *s = new Circle(r);
      if (!k.add(s)) {
        cout << "Storage is full.\n";
        delete s;
      }
      break;
    }
    case 2: {
      double a = read_double("Width (a): ");
      double b = read_double("Height (b): ");
      Shape *s = new Rectangle(a, b);
      if (!k.add(s)) {
        cout << "Storage is full.\n";
        delete s;
      }
      break;
    }
    case 3: {
      double a = read_double("Side (a): ");
      Shape *s = new Square(a);
      if (!k.add(s)) {
        cout << "Storage is full.\n";
        delete s;
      }
      break;
    }
    case 4: {
      if (k.get_size() == 0) {
        cout << "No shapes to remove.\n";
        break;
      }
      cout << "Current count: " << k.get_size() << "\n";
      size_t idx = read_size_t("Index [0..n-1]: ");
      if (idx >= k.get_size()) {
        cout << "Index out of range.\n";
      } else {
        k.remove(idx);
        cout << "Removed.\n";
      }
      break;
    }
    case 5: {
      if (k.get_size() == 0) {
        cout << "List is empty.\n";
      } else {
        for (size_t i = 0; i < k.get_size(); ++i) {
          cout << i << ": " << k[i]
               << "  | Area=" << static_cast<const Shape2D &>(k[i]).area()
               << '\n';
        }
      }
      break;
    }
    case 6: {
      if (k.get_size() == 0) {
        cout << "List is empty.\n";
        break;
      }
      size_t idx = read_size_t("Shape index: ");
      if (idx >= k.get_size()) {
        cout << "Index out of range.\n";
      } else {
        cout << k[idx].picture() << '\n';
      }
      break;
    }
    case 7: {
      cout << "Path to load file: ";
      string path;
      cin >> path;
      ifstream in(path);
      if (!in) {
        cout << "Failed to open file.\n";
      } else {
        k.clear();
        in >> k;
        cout << "Loaded. Current size: " << k.get_size() << "\n";
      }
      break;
    }
    case 8: {
      cout << "Path to save file: ";
      string path;
      cin >> path;
      ofstream out(path);
      if (!out) {
        cout << "Failed to open file for writing.\n";
      } else {
        out << k;
        cout << "Saved.\n";
      }
      break;
    }
    case 9: {
      if (k.get_size() == 0) {
        cout << "List is empty.\n";
      } else {
        for (size_t i = 0; i < k.get_size(); ++i) {
          cout << i << ": Area=" << static_cast<const Shape2D &>(k[i]).area()
               << '\n';
        }
      }
      break;
    }
    case 0:
      cout << "Exit.\n";
      break;
    default:
      cout << "Unknown command.\n";
      break;
    }
  } while (choice != 0);
}