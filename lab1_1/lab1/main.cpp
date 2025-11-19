#include <iosteram>
using namespace std;

class Shape {
    
protected:
    static constexpr double pi = 3.1415926535;
public:

    virtual std::string picture() const {
        return get_picture();
    }
    virtual ~Shape() = default;
    friend std::ostream& operator<<(std::ostream& os, const Shape& s){
        s.output(os);
    }
    friend std::istream& operator>>(const std::istream& is, Shape& s){
        s.input(is);
    }
private:
    virtual std::string get_picture() const = 0;
    virtual void input(std::istream& is) = 0;
    virtual void output(std::ostream& os) = 0;
};

class Shape2D : public Shape {
public:
  virtual double area() const = 0;
};

class Shape3D : public Shape2D {
public:
  virtual double volume() const = 0;
};

class Circle : public Shape2D {
    double r;
public: 
    Circle(double radius) : r(radius) {}
    
    double area() const override {
        return pi * r * r;
    }

    std::string get_picture() const override {
        int radius = static_cast<int>(r);
        if (radius <= 0) return "";
        
        int size = 2 * radius + 1;
        std::string result;
        
        for (int y = 0; y < size; y++) {
            std::string line;
            for (int x = 0; x < size; x++) {
                int dx = x - radius;
                int dy = (y - radius) * 2;

                int distance_sq = dx * dx + dy * dy;
                int radius_sq = radius * radius;

                if (distance_sq >= radius_sq - radius && 
                    distance_sq <= radius_sq + radius) {
                    line += '*';
                } else {
                    line += ' ';
                }
            }
            result += line + '\n';
        }
        
        return result;
    }
};

class Rectangle : public Shape2D {
    double a, b;
public: 
    Rectangle(double a, double b) : a(a), b(b) {}
    
    double area() const override {
        return a * b;
    }
    
    std::string get_picture() const override {
        std::stringstream s;
        for(int i = 0; i < a; ++i)
            s << '*';
        s << '\n';
        for(int i = 0; i < b - 2; ++i){
            s << '*';
            for(int j = 0; j < a - 2; ++j)
                s << ' ';
            s << '*' << '\n';
        }
        for(int i = 0; i < a; ++i)
            s << '*';
        s << '\n';
        return s.str();
    }
};

class Square : public Shape2D {
    double a;
public: 
    Square(double a) : a(a) {}
    
    double area() const override {
        return a * a;
    }
    
    std::string get_picture() const override {
        std::stringstream s;
        for(int i = 0; i < a; ++i)
            s << '*';
        s << '\n';
        for(int i = 0; i < a - 2; ++i){
            s << '*';
            for(int j = 0; j < a - 2; ++j)
                s << ' ';
            s << '*' << '\n';
        }
        for(int i = 0; i < a; ++i)
            s << '*';
        s << '\n';
        return s.str();
    }
};






int main() {
 Rectangle r(7, 4);
 std::cout<<r.picture() << std::endl;
 
 Square s(4);
 std::cout<<s.picture() << std::endl;

 Circle c(4);
 std::cout << c.picture() << std::endl;

}