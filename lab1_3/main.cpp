#include <fstream>
#include <iostream>
#include <limits>

#include "Circle.h"
#include "Cube.h"
#include "Keeper.h"
#include "Parallelepiped.h"
#include "Rectangle.h"
#include "Shape2D.h"
#include "Sphere.h"
#include "Square.h"
#include <iomanip>
#include <sstream>

using namespace std;

size_t read_size_t(const char *prompt) {
  long long v{};
  while (true) {
    cout << prompt;
    if (cin >> v && v >= 0)
      return static_cast<size_t>(v);
    cout << "Invalid input. Try again.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
}

double read_double(const char *prompt) {
  double v{};
  while (true) {
    cout << prompt;
    if (cin >> v)
      return v;
    cout << "Invalid input. Try again.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
}

int main() {
  Keeper k;

  auto print_menu = []() {
    cout << "\nMenu:\n";
    cout << " 1) Add figure\n";
    cout << " 2) Remove shape by index\n";
    cout << " 3) List shapes\n";
    cout << " 4) Show shape picture\n";
    cout << " 5) Load from file\n";
    cout << " 6) Save to file\n";
    cout << " 0) Exit\n";
    cout << "Your choice: ";
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
      int sc = -1;
      do {
        cout << "\nAdd figure:\n";
        cout << " 1) Circle\n";
        cout << " 2) Rectangle\n";
        cout << " 3) Square\n";
        cout << " 4) Sphere\n";
        cout << " 5) Cube\n";
        cout << " 6) Box (parallelepiped)\n";
        cout << " 0) Back\n";
        cout << "Your choice: ";
        if (!(cin >> sc)) {
          cout << "Invalid input. Try again.\n";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          continue;
        }

        Shape *s = nullptr;
        switch (sc) {
        case 1: {
          double r = read_double("Radius: ");
          s = new Circle(r);
          break;
        }
        case 2: {
          double a = read_double("Width (a): ");
          double b = read_double("Height (b): ");
          s = new Rectangle(a, b);
          break;
        }
        case 3: {
          double a = read_double("Side (a): ");
          s = new Square(a);
          break;
        }
        case 4: {
          double r = read_double("Radius: ");
          s = new Sphere(r);
          break;
        }
        case 5: {
          double a = read_double("Side (a): ");
          s = new Cube(a);
          break;
        }
        case 6: {
          double a = read_double("Width (a): ");
          double b = read_double("Height (b): ");
          double c = read_double("Depth (c): ");
          s = new Parallelepiped(a, b, c);
          break;
        }
        case 0:
          break;
        default:
          cout << "Unknown command.\n";
          break;
        }

        if (s) {
          if (!k.add(s)) {
            cout << "Storage is full.\n";
            delete s;
          } else {
            cout << "Added.\n";
          }
        }
      } while (sc != 0);
      break;
    }
    case 2: {
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
    case 3: {
      if (k.get_size() == 0) {
        cout << "List is empty.\n";
      } else {
        cout << left << setw(5) << "Idx" << setw(24) << "Shape" << right
             << setw(14) << "Area" << setw(14) << "Volume" << '\n';
        cout << string(5 + 24 + 14 + 14, '-') << '\n';
        for (size_t i = 0; i < k.get_size(); ++i) {
          const Shape &s = k[i];
          std::ostringstream oss;
          oss << s;
          double area = static_cast<const Shape2D &>(s).area();
          const Shape3D *s3d = dynamic_cast<const Shape3D *>(&s);
          cout << left << setw(5) << i << setw(24) << oss.str() << right
               << setw(14) << area;
          if (s3d) {
            cout << setw(14) << s3d->volume();
          } else {
            cout << setw(14) << "-";
          }
          cout << '\n';
        }
      }
      break;
    }
    case 4: {
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
    case 5: {
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
    case 6: {
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
    case 0:
      cout << "Exit.\n";
      break;
    default:
      cout << "Unknown command.\n";
      break;
    }
  } while (choice != 0);
}