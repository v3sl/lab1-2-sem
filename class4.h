class point{
private:
    int x;
    int y;
    point() = default;
public:
    point(int cx, int cy) : x(cx), y(cy){};
    ~point() = default;
    friend std::ostream& operator << (std::ostream& out, const point& obj){
        out << obj.x << ", " << obj.y;
        return out;
    }
    friend bool operator < (const point& first, const point& second){
        return first.x * first.y < second.x* second.y;
    }
    friend bool operator >= (const point& first, const point& second){
        return first.x * first.y >= second.x * second.y;
    }
};